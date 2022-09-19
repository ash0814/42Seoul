#ifndef algorithm_HPP
#define algorithm_HPP

#include <cstdint>
#include <stdexcept>

namespace ft {
  template <typename InputIterator1, typename InputIterator2>
  bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
    for (; first1 != last1; ++first1, ++first2) {
        if (!(*first1 == *first2)) {
            return false;
        }
    }
    return true;
  }

  template<typename InputIt1, typename InputIt2, typename BinaryPredicate>
  bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p) {
    for (; first1 != last1; ++first1, ++first2)
      if (!p(*first1, *first2))
          return false;
    return true;
  }

  template <typename InputIterator1, typename InputIterator2>
  bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
    while (first1!=last1) {
      if (first2==last2 || *first2<*first1) return false;
      else if (*first1<*first2) return true;
      ++first1; ++first2;
    }
    return (first2!=last2);
  }

}

#endif