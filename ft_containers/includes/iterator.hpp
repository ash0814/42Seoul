#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>

namespace ft
{
  template <typename Category, typename T, typename Distance = std::ptrdiff_t, typename Pointer = T *, typename Reference = T &>
  struct iterator {
    typedef T value_type;
    typedef Distance difference_type;
    typedef Pointer pointer;
    typedef Reference reference;
    typedef Category iterator_category;
  };

  struct	input_iterator_tag {};
  struct	output_iterator_tag {};
  struct	forward_iterator_tag : public input_iterator_tag, output_iterator_tag {};
  struct	bidirectional_iterator_tag : public forward_iterator_tag {};
  struct	random_access_iterator_tag : public bidirectional_iterator_tag {};
}

#endif