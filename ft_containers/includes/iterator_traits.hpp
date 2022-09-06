#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <cstddef>
#include "iterator.hpp"

namespace ft
{
  template <class Iterator> class iterator_traits {
    typedef typename ft::Iterator::difference_type difference_type;
    typedef typename ft::Iterator::value_type value_type;
    typedef typename ft::Iterator::pointer pointer;
    typedef typename ft::Iterator::reference reference;
    typedef typename ft::Iterator::iterator_category iterator_category;
  };

  template <class T> class iterator_traits<T *> {
    typedef std::ptrdiff_t difference_type;
    typedef T value_type;
    typedef T *pointer;
    typedef T &reference;
    typedef ft::random_access_iterator_tag iterator_category;
  };

  template <class T> class iterator_traits<const T *> {
    typedef std::ptrdiff_t difference_type;
    typedef T value_type;
    typedef const T *pointer;
    typedef const T &reference;
    typedef ft::random_access_iterator_tag iterator_category;
  };
}

#endif