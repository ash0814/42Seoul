#ifndef STACK_HPP
#define STACK_HPP
#include "./vector.hpp"

namespace ft {

template <typename T, typename Container = ft::vector<T> >
class stack {
 public:
  typedef Container container_type;
  typedef typename container_type::value_type value_type;
  typedef typename container_type::size_type size_type;
  typedef typename container_type::reference reference;
  typedef typename container_type::const_reference const_reference;

  explicit stack(const container_type& container = container_type()) : c(container) {}
  stack(const stack& s) : c(s.c) {}
  ~stack(void) {}

  stack& operator=(const stack& s) {
    if (this != &s) {
      c = s.c;
    }
    return *this;
  }

  reference top(void) { return c.back(); }
  const_reference top(void) const { return c.back(); }

  bool empty(void) const { return c.empty(); }

  size_type size(void) const { return c.size(); }

  void push(const value_type& value) { c.push_back(value); }
  void pop(void) { c.pop_back(); }

  template <typename U, typename C>
  friend bool operator==(const stack<U, C>& x, const stack<U, C>& y);
  template <typename U, typename C>
  friend bool operator!=(const stack<U, C>& x, const stack<U, C>& y);
  template <typename U, typename C>
  friend bool operator<(const stack<U, C>& x, const stack<U, C>& y);
  template <typename U, typename C>
  friend bool operator<=(const stack<U, C>& x, const stack<U, C>& y);
  template <typename U, typename C>
  friend bool operator>(const stack<U, C>& x, const stack<U, C>& y);
  template <typename U, typename C>
  friend bool operator>=(const stack<U, C>& x, const stack<U, C>& y);

 protected:
  container_type c;
};
  template <typename T, typename C>
  bool operator==(const stack<T, C>& x, const stack<T, C>& y) {
    return x.c == y.c;
  }
  template <typename T, typename C>
  bool operator!=(const stack<T, C>& x, const stack<T, C>& y) {
    return x.c != y.c;
  }
  template <typename T, typename C>
  bool operator<(const stack<T, C>& x, const stack<T, C>& y) {
    return x.c < y.c;
  }
  template <typename T, typename C>
  bool operator<=(const stack<T, C>& x, const stack<T, C>& y) {
    return x.c <= y.c;
  }
  template <typename T, typename C>
  bool operator>(const stack<T, C>& x, const stack<T, C>& y) {
    return x.c > y.c;
  }
  template <typename T, typename C>
  bool operator>=(const stack<T, C>& x, const stack<T, C>& y) {
    return x.c >= y.c;
  }
}
#endif
