#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

namespace ft
{
  template <class T, class Alloc = std::allocator<T> >
  class vector
  {
    typedef T value_type;

    // default to allocator<value_type>
    typedef Allocator allocator_type;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;

    // same to std::size_t when Allocator is std::allocator
    typedef typename allocator_type::size_type size_type;

    // same to std::ptrdiff_t when Allocator is std::allocator
    typedef typename allocator_type::difference_type difference_type;

  };
}

#endif