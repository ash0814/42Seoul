#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include <memory>
#include "utility.hpp"
#include "rbtree.hpp"
#include "reverse_iterator.hpp"
#include "algorithm.hpp"

namespace ft
{
  template <typename U, typename V, typename Compare = std::less<U>, typename Allocator = std::allocator<ft::pair<const U, V> > >
  class map
  {
  public:
    typedef U                                                             key_type;
    typedef V                                                             mapped_type;
    typedef ft::pair<const U, V>                                          value_type;
    typedef Compare key_compare;

    typedef Allocator                                                     allocator_type;
    typedef typename allocator_type::template rebind<value_type>::other   type_allocator;
    typedef std::allocator_traits<type_allocator>                         type_traits;
    typedef typename type_traits::pointer                                 pointer;
    typedef typename type_traits::const_pointer                           const_pointer;
    typedef value_type                                                    &reference;
    typedef const value_type                                              &const_reference;

    typedef std::size_t                                                   size_type;
    typedef std::ptrdiff_t                                                difference_type;

    class value_compare
    {
    protected:
      key_compare comp;
    public:
      value_compare(key_compare c) : comp(c) {}
      ~value_compare(void) {}
      bool operator()(const value_type &x, const value_type &y) const { return comp(x.first, y.first); }
      bool operator()(const value_type &x, const key_type &y) const { return comp(x.first, y); }
      bool operator()(const key_type &x, const value_type &y) const { return comp(x, y.first); }
    };

    typedef typename ft::rb_tree<value_type, key_type, value_compare, allocator_type>::iterator       iterator;
    typedef typename ft::rb_tree<value_type, key_type, value_compare, allocator_type>::const_iterator const_iterator;
    typedef ft::reverse_iterator<iterator>                                                            reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>                                                      const_reverse_iterator;

    explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
        : key_cmp(comp), value_cmp(comp), tree(value_cmp, alloc) {}

    template <class InputIterator>
    map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type(),
        typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = ft::nil)
        : key_cmp(comp), value_cmp(comp), tree(value_cmp, alloc)
    {
      insert(first, last);
    }
    map(const map &m) : key_cmp(m.key_cmp), value_cmp(m.value_cmp), tree(m.tree) {}
    ~map(void) {}

    map &operator=(const map &m)
    {
      if (this != &m)
      {
        key_cmp = m.key_cmp;
        value_cmp = m.value_cmp;
        tree = m.tree;
      }
      return *this;
    }

    iterator begin(void) { return tree.begin(); }
    const_iterator begin(void) const { return tree.begin(); }
    iterator end(void) { return tree.end(); }
    const_iterator end(void) const { return tree.end(); }
    reverse_iterator rbegin(void) { return reverse_iterator(end()); }
    const_reverse_iterator rbegin(void) const { return reverse_iterator(end()); }
    reverse_iterator rend(void) { return reverse_iterator(begin()); }
    const_reverse_iterator rend(void) const { return reverse_iterator(begin()); }

    bool empty(void) const { return tree.empty(); }
    size_type size(void) const { return tree.size(); }
    size_type max_size(void) const { return tree.max_size(); }

    mapped_type &operator[](const key_type &key)
    {
      ft::pair<iterator, bool> p = insert(ft::make_pair(key, mapped_type()));
      return p.first->second;
    }

    mapped_type &at(const key_type &key)
    {
      iterator i = find(key);
      if (i == end())
        throw std::out_of_range("index out of range");
      return i->second;
    }

    const mapped_type &at(const key_type &key) const
    {
      const_iterator i = find(key);
      if (i == end())
        throw std::out_of_range("index out of range");
      return i->second;
    }

    ft::pair<iterator, bool> insert(const value_type &value) { return tree.insert(value); }
    iterator insert(iterator position, const value_type &value) { return tree.insert(position, value); }
    template <class InputIterator>
    void insert(InputIterator first, InputIterator last) { tree.insert(first, last); }

    void erase(iterator position) { tree.erase(position); }
    size_type erase(const key_type &key) { return tree.erase(key); }
    void erase(iterator first, iterator last) { tree.erase(first, last); }
    void swap(map &m) { tree.swap(m.tree); }
    void clear(void) { tree.clear(); }

    key_compare key_comp(void) const { return key_cmp; }
    value_compare value_comp(void) const { return value_cmp; }

    iterator find(const key_type &key) { return tree.find(key); }
    const_iterator find(const key_type &key) const { return tree.find(key); }
    size_type count(const key_type &key) const { return find(key) != end(); }

    iterator lower_bound(const key_type &key) { return tree.lower_bound(key); }
    const_iterator lower_bound(const key_type &key) const { return tree.lower_bound(key); }
    iterator upper_bound(const key_type &key) { return tree.upper_bound(key); }
    const_iterator upper_bound(const key_type &key) const { return tree.upper_bound(key); }
    ft::pair<iterator, iterator> equal_range(const key_type &key) { return tree.equal_range(key); }
    ft::pair<const_iterator, const_iterator> equal_range(const key_type &key) const { return tree.equal_range(key); }

    allocator_type get_allocator(void) const { return tree.get_allocator(); }

  private:
    key_compare key_cmp;
    value_compare value_cmp;
    ft::rb_tree<value_type, key_type, value_compare, allocator_type> tree;
  };

  template <typename U, typename V, typename Compare, typename Allocator>
  bool operator==(const ft::map<U, V, Compare, Allocator> &x, const ft::map<U, V, Compare, Allocator> &y)
  {
    return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
  }

  template <typename U, typename V, typename Compare, typename Allocator>
  bool operator!=(const ft::map<U, V, Compare, Allocator> &x, const ft::map<U, V, Compare, Allocator> &y)
  {
    return !(x == y);
  }

  template <typename U, typename V, typename Compare, typename Allocator>
  bool operator<(const ft::map<U, V, Compare, Allocator> &x, const ft::map<U, V, Compare, Allocator> &y)
  {
    return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
  }

  template <typename U, typename V, typename Compare, typename Allocator>
  bool operator<=(const ft::map<U, V, Compare, Allocator> &x, const ft::map<U, V, Compare, Allocator> &y)
  {
    return !(y < x);
  }

  template <typename U, typename V, typename Compare, typename Allocator>
  bool operator>(const ft::map<U, V, Compare, Allocator> &x, const ft::map<U, V, Compare, Allocator> &y)
  {
    return y < x;
  }

  template <typename U, typename V, typename Compare, typename Allocator>
  bool operator>=(const ft::map<U, V, Compare, Allocator> &x, const ft::map<U, V, Compare, Allocator> &y)
  {
    return !(x < y);
  }

  template <typename U, typename V, typename Compare, typename Allocator>
  void swap(ft::map<U, V, Compare, Allocator> &x, ft::map<U, V, Compare, Allocator> &y)
  {
    x.swap(y);
  }

}

#endif
