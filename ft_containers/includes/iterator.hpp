#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>

namespace ft
{
  template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T *, class Reference = T &>
  struct iterator {
    typedef T value_type;
    typedef Distance difference_type;
    typedef Pointer pointer;
    typedef Reference reference;
    typedef Category iterator_category;
  };

  struct input_iterator_tag {};
  struct forward_iterator_tag {};
  struct forward_iterator_tag {};
  struct bidirectional_iterator_tag {};
  struct random_access_iterator_tag {};

}

#endif