#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "iterator_traits.hpp"

namespace ft
{
  template <class T1, class T2>
  struct pair
  {
    typedef T1 first_type;
    typedef T2 second_type;
    first_type first;
    second_type second;

    pair(void) : first(first_type()), second(second_type()) {}
    pair(const first_type &x, const second_type &y) : first(x), second(y) {}

    template <typename U1, typename U2>
    pair(const pair<U1, U2> &p) : first(p.first), second(p.second) {}

    pair &operator=(const pair &p)
    {
      if (this != &p)
      {
        first = p.first;
        second = p.second;
      }
      return *this;
    }
  };

  template <class T1, class T2>
  pair<T1, T2> make_pair(T1 x, T2 y)
  {
    return (pair<T1, T2>(x, y));
  }

  template <typename T1, typename T2>
  bool operator==(const ft::pair<T1, T2> &x, const ft::pair<T1, T2> &y)
  {
    return x.first == y.first && x.second == y.second;
  }

  template <typename T1, typename T2>
  bool operator!=(const ft::pair<T1, T2> &x, const ft::pair<T1, T2> &y)
  {
    return !(x == y);
  }

  template <typename T1, typename T2>
  bool operator<(const ft::pair<T1, T2> &x, const ft::pair<T1, T2> &y)
  {
    return x.first < y.first || (!(x.first > y.first) && x.second < y.second);
  }

  template <typename T1, typename T2>
  bool operator<=(const ft::pair<T1, T2> &x, const ft::pair<T1, T2> &y)
  {
    return !(y < x);
  }

  template < typename InputIt >
	typename ft::iterator_traits<InputIt>::difference_type	distance(InputIt first, InputIt last)
	{
		typename ft::iterator_traits<InputIt>::difference_type	dist = 0;
		while (first != last){
			++first;
			++dist;
		}
		return dist;
	}
}

#endif