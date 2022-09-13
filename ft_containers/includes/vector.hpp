#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "./algorithm.hpp"
#include "./iterator_traits.hpp"
#include "./random_access_iterator.hpp"
#include "./reverse_iterator.hpp"
#include "./type_traits.hpp"
#include "./iterator.hpp"
#include "./utility.hpp"
#include <limits>
#include <memory>
#include <stdexcept>
#include <algorithm>

#include <vector>

namespace ft
{
  template <class T, class Allocator = std::allocator<T> >
  class vector
  {
  public:
    typedef T                                                 value_type;
    typedef Allocator                                         allocator_type;
    typedef std::allocator_traits<allocator_type>             type_traits;
    typedef typename allocator_type::pointer                  pointer;
    typedef typename allocator_type::const_pointer            const_pointer;
    typedef typename allocator_type::reference                reference;
    typedef typename allocator_type::const_reference          const_reference;

    typedef std::size_t                              size_type;
    typedef std::ptrdiff_t                           difference_type;

    typedef ft::random_access_iterator<value_type>            iterator;
    typedef ft::random_access_iterator<const value_type>      const_iterator;
    typedef ft::reverse_iterator<iterator>                    reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>              const_reverse_iterator;

    explicit vector(const allocator_type &alloc = allocator_type())
        : _begin(ft::nil), _end(ft::nil), _end_cap(ft::nil), _alloc(alloc) {}

    explicit vector(size_type n, const value_type &value = value_type(), const allocator_type &alloc = allocator_type()) : _alloc(alloc)  {
      _begin = _alloc.allocate(n);
      _end = _begin;
      _end_cap = _begin + n;
      for (size_type i = 0; i < n; i++) {
        _alloc.construct(_end);
        *_end++ = value;
      }
    }

    template <class InputIterator>
    vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
           typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = ft::nil) : _alloc(alloc) {
      size_type n = ft::distance(first, last);
      _begin = _alloc.allocate(n);
      _end = _begin;
      _end_cap = _begin + n;
      for (; n > 0; _end++, n--)
        _alloc.construct(_end);
      std::copy(first, last, _begin);
    }

    vector(const vector &v)
        : _alloc(v._alloc)
    {
      size_type n = v.size();
      _begin = _alloc.allocate(v.capacity());
      _end = _begin;
      _end_cap = _begin + v.capacity();
      for (; n > 0; _end++, n--)
        _alloc.construct(_end);
      std::copy(v._begin, v._end, _begin);
    }
    ~vector()
    {
      if (_begin == ft::nil) { return; }
      size_type cap = capacity();
      for (; _end != _begin; _end--)
        _alloc.destroy(_end);
      // for (; _end != _begin && _end--;)
      //   _alloc.destroy(_end);
      _alloc.deallocate(_begin, cap);
    }

    vector &operator=(const vector &v)
    {
      if (this != &v) {
        assign(v._begin, v._end);
      }
      return *this;
    }

    iterator begin(void)
    {
      return iterator(_begin);
    }
    const_iterator begin(void) const
    {
      return const_iterator(_begin);
    }
    iterator end(void)
    {
      return iterator(_end);
    }
    const_iterator end(void) const
    {
      return const_iterator(_end);
    }
    reverse_iterator rbegin(void)
    {
      return reverse_iterator(end());
    }
    const_reverse_iterator rbegin(void) const
    {
      return const_reverse_iterator(end());
    }
    reverse_iterator rend(void)
    {
      return reverse_iterator(begin());
    }
    const_reverse_iterator rend(void) const
    {
      return const_reverse_iterator(begin());
    }

    reference operator[](size_type n)
    {
      return _begin[n];
    }
    const_reference operator[](size_type n) const
    {
      return _begin[n];
    }
    reference at(size_type n)
    {
      if (n >= size())
      {
        throw std::out_of_range("index out of range");
      }
      return _begin[n];
    }
    const_reference at(size_type n) const
    {
      if (n >= size())
      {
        throw std::out_of_range("index out of range");
      }
      return _begin[n];
    }
    reference front(void)
    {
      return *_begin;
    }
    const_reference front(void) const
    {
      return *_begin;
    }
    reference back(void)
    {
      return *(_end - 1);
    }
    const_reference back(void) const
    {
      return *(_end - 1);
    }
    T *data(void) throw()
    {
      return reinterpret_cast<T *>(_begin);
    }
    const T *data(void) const throw()
    {
      return reinterpret_cast<const T *>(_begin);
    }

    size_type size(void) const
    {
      return static_cast<size_type>(_end - _begin);
    }

    size_type max_size(void) const
    {
      return _alloc.max_size();
    }

    void resize(size_type n, value_type value = value_type())
    {
      if (size() > n) {
        size_type rm_size = size() - n;
        for (size_type i = 0; i < rm_size; i++)
          _alloc.destroy(_end--);
      } else if (size() < n) {
        size_type new_size = n - size();
        if (capacity() < n)
          reserve(n);
        for (size_type i = 0; i < new_size; _end++, i++) {
          _alloc.construct(_end);
          *_end = value;
        }
      }
    }

    size_type capacity(void) const
    {
      return static_cast<size_type>(_end_cap - _begin);
    }

    bool empty(void) const { return _begin == _end; }

    void reserve(size_type n)
    {
      if (n > capacity()) {
        if (n > max_size())
          throw std::length_error("ERROR: allocate size too large");
        if (n < capacity() * 2) {
          if (capacity() * 2 < max_size())
            n = capacity() * 2;
          else
            n = max_size();
        }
        size_type pre_size = size();
        size_type pre_cap = capacity();
        pointer new_begin = _alloc.allocate(n);
        
        std::uninitialized_copy(_begin, _end, new_begin);
        for (; _end != _begin && _end-- ; )
          _alloc.destroy(_end);
        _alloc.deallocate(_begin, pre_cap);
        _begin = new_begin;
        _end = _begin + pre_size;
        _end_cap = _begin + n;
      }
    }

    template <class InputIterator> // TODO enable_if 는 왜 있는걸까?
    void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = ft::nil)
    {
      size_type n = ft::distance(first, last);
      if (capacity() < n)
        reserve(n);
      std::copy(first, last, _begin);
      _end = _begin + n;
    }

    void assign(size_type n, const value_type &value)
    {
      if (capacity() < n)
        reserve(n);
      std::fill_n(_begin, n, value);
      _end = _begin + n;
    }

    void push_back(const value_type &value)
    {
      size_type n = size() + 1;
      if (capacity() < n)
        reserve(n);
      _alloc.construct(_end++);
      *(_end - 1) = value;
    }

    void pop_back(void)
    {
      _alloc.destroy(_end--);
    }

    iterator insert(iterator position, const value_type &value)
    {
      difference_type insert_pos = ft::distance(begin(), position);
      if (capacity() < size() + 1)
        reserve(size() + 1);
      _alloc.construct(_end++);

      pointer insert_ptr = _begin + insert_pos;
      std::copy_backward(insert_ptr, _end - 1, _end);
      *insert_ptr = value;
      return iterator(insert_ptr);
    }

    void insert(iterator position, size_type n, const value_type &value)
    {
      difference_type insert_pos = ft::distance(begin(), position);
      if (capacity() < size() + n)
        reserve(size() + n);
      pointer insert_ptr = _begin + insert_pos;
      for (size_type i = 0; i < n;i++)
        _alloc.construct(_end++);
      std::copy_backward(insert_ptr, _end - n, _end);
      for (size_type i = 0; i < n; i++)
        insert_ptr[i] = value;
    }

    template <class InputIterator>
    void insert(iterator position, InputIterator first, InputIterator last,
                typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = ft::nil)
    {
      difference_type n = ft::distance(first, last);
      difference_type insert_pos = ft::distance(begin(), position);
      if (capacity() < size() + n)
        reserve(size() + n);
      pointer ptr = _begin + insert_pos;
      for (difference_type i = 0; i < n;i++)
        _alloc.construct(_end++);
      std::copy_backward(ptr, _end - n, _end);
      for (InputIterator i = first; i != last; i++, ptr++)
        *ptr = *i;
    }

    iterator erase(iterator position)
    {
      difference_type erase_pos = ft::distance(begin(), position);
      pointer erase_ptr = _begin + erase_pos;
      std::copy(erase_ptr + 1, _end, erase_ptr);
      _alloc.destroy(_end--);
      return iterator(erase_ptr);
    }

    iterator erase(iterator first, iterator last)
    {
      difference_type n = ft::distance(first, last);
      std::copy(last, end(), first);
      for (difference_type i = 0; i < n ; i++)
        _alloc.destroy(_end--);
      return first;
    }
    
    void swap(vector &v)
    {
      std::swap(_begin, v._begin);
      std::swap(_end, v._end);
      std::swap(_end_cap, v._end_cap);
      std::swap(_alloc, v._alloc);
    }

    void clear(void)
    {
      for (; _end != _begin && _end-- ; )
        _alloc.destroy(_end);
    }

    allocator_type get_allocator(void) const { return _alloc; }

  private:
    pointer _begin;
    pointer _end;
    pointer _end_cap;
    allocator_type _alloc;
  };

  template <typename T, class Allocator>
  bool operator==(const ft::vector<T, Allocator> &x,
                  const ft::vector<T, Allocator> &y)
  {
    return x.size() == y.size() &&
           ft::equal(x.begin(), x.end(), y.begin());
  }

  template <typename T, class Allocator>
  bool operator!=(const ft::vector<T, Allocator> &x,
                  const ft::vector<T, Allocator> &y)
  {
    return !(x == y);
  }

  template <typename T, class Allocator>
  bool operator<(const ft::vector<T, Allocator> &x,
                 const ft::vector<T, Allocator> &y)
  {
    return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
  }

  template <typename T, class Allocator>
  bool operator<=(const ft::vector<T, Allocator> &x,
                  const ft::vector<T, Allocator> &y)
  {
    return x == y || x < y;
  }

  template <typename T, class Allocator>
  bool operator>(const ft::vector<T, Allocator> &x,
                 const ft::vector<T, Allocator> &y)
  {
    return !(x <= y);
  }

  template <typename T, class Allocator>
  bool operator>=(const ft::vector<T, Allocator> &x,
                  const ft::vector<T, Allocator> &y)
  {
    return x == y || x > y;
  }

  template <typename T, class Allocator>
  void swap(ft::vector<T, Allocator> &x,
            ft::vector<T, Allocator> &y)
  {
    x.swap(y);
  }
}

#endif