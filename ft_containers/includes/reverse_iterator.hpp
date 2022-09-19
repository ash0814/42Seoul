#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "./iterator_traits.hpp"
#include <iterator>
namespace ft
{

  template <typename Iterator>
  class reverse_iterator
  {
  public:
    typedef Iterator                                                        iterator_type;
    typedef typename ft::iterator_traits<iterator_type>::difference_type    difference_type;
    typedef typename ft::iterator_traits<iterator_type>::value_type         value_type;
    typedef typename ft::iterator_traits<iterator_type>::pointer            pointer;
    typedef typename ft::iterator_traits<iterator_type>::reference          reference;
    typedef typename ft::iterator_traits<iterator_type>::iterator_category  iterator_category;

    reverse_iterator(void) : current(iterator_type()) {}
    explicit reverse_iterator(iterator_type i) : current(i) {}
    template <typename Other>
    reverse_iterator(const reverse_iterator<Other> &i) : current(i.base()) {}
    ~reverse_iterator(void) {}

    template <typename Other>
    reverse_iterator &operator=(const reverse_iterator<Other> &i)
    {
      current = i.base();
      return *this;
    }
    iterator_type base(void) const { return current; }
    reference operator*(void) const
    {
      iterator_type tmp = current;
      return *--tmp;
    }
    reference operator[](difference_type n) const
    {
      return *(*this + n);
    }
    pointer operator->(void) const { return &operator*(); }

    reverse_iterator &operator++(void) {
      --current;
      return *this;
    }

    reverse_iterator &operator--(void) {
      ++current;
      return *this;
    }
    reverse_iterator operator++(int) {
      reverse_iterator tmp(*this);
      --current;
      return tmp;
    }
    reverse_iterator operator--(int) {
      reverse_iterator tmp(*this);
      ++current;
      return tmp;
    }

    reverse_iterator operator+(difference_type n) const { return reverse_iterator(current - n); }
    reverse_iterator operator-(difference_type n) const { return reverse_iterator(current + n); }
    reverse_iterator &operator+=(difference_type n) {
      current -= n;
      return *this;
    }
    reverse_iterator &operator-=(difference_type n) {
      current += n;
      return *this;
    }

  private:
    Iterator current;
  };

  template <typename Iterator>
  reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &i)
  {
    return reverse_iterator<Iterator>(i.base() - n);
  }

  template <typename Iterator1, typename Iterator2>
  typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1> &x,const reverse_iterator<Iterator2> &y)
  {
    return y.base() - x.base();
  }


  template <typename Iterator1, typename Iterator2>
  bool operator==(const reverse_iterator<Iterator1> &x, const reverse_iterator<Iterator2> &y)
  {
    return x.base() == y.base();
  }

  template <typename Iterator1, typename Iterator2>
  bool operator!=(const reverse_iterator<Iterator1> &x, const reverse_iterator<Iterator2> &y)
  {
    return x.base() != y.base();
  }

  template <typename Iterator1, typename Iterator2>
  bool operator<(const reverse_iterator<Iterator1> &x, const reverse_iterator<Iterator2> &y)
  {
    return x.base() > y.base();
  }

  template <typename Iterator1, typename Iterator2>
  bool operator<=(const reverse_iterator<Iterator1> &x, const reverse_iterator<Iterator2> &y)
  {
    return x.base() >= y.base();
  }

  template <typename Iterator1, typename Iterator2>
  bool operator>(const reverse_iterator<Iterator1> &x, const reverse_iterator<Iterator2> &y)
  {
    return x.base() < y.base();
  }

  template <typename Iterator1, typename Iterator2>
  bool operator>=(const reverse_iterator<Iterator1> &x, const reverse_iterator<Iterator2> &y)
  {
    return x.base() <= y.base();
  }

}

#endif