#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <cstddef>
#include <iterator>

namespace ft
{
  template <class Iterator> class iterator_traits {
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
    typedef typename Iterator::iterator_category iterator_category;
  };

  template <class T> class iterator_traits<T *>;
  
  template <class T> class iterator_traits<const T *>;
}

#endif