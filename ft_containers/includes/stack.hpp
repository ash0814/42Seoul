#ifndef STACK_HPP
#define STACK_HPP
#include "./vector.hpp"

namespace ft {

template <typename T, class Container = ft::vector<T> >
class stack {
 public:
  typedef Container container_type;
  typedef typename container_type::value_type value_type;
  typedef typename container_type::size_type size_type;
  typedef typename container_type::reference reference;
  typedef typename container_type::const_reference const_reference;

  explicit stack(const container_type& container = container_type())
    : c(container) {}
  stack(const stack& s) : c(s.c) {}
  ~stack(void) {}

  stack& operator=(const stack& s) {
    if (this != &s) {
      c = s.c;
    }
    return *this;
  }

  reference top(void) {
    return c.back();
  }
  const_reference top(void) const {
    return c.back();
  }

  bool empty(void) const {
    return c.empty();
  }

  size_type size(void) const {
    return c.size();
  }

  void push(const value_type& value) {
    c.push_back(value);
  }
  void pop(void) {
    c.pop_back();
  }

  friend bool operator==(const stack& x, const stack& y);
  friend bool operator!=(const stack& x, const stack& y);
  friend bool operator<(const stack& x, const stack& y);
  friend bool operator<=(const stack& x, const stack& y);
  friend bool operator>(const stack& x, const stack& y);
  friend bool operator>=(const stack& x, const stack& y);

 protected:
  container_type c;
};
  template <typename T>
  bool operator==(const stack<T>& x, const stack<T>& y) {
    return x.c == y.c;
  }
  template <typename T>
  bool operator!=(const stack<T>& x, const stack<T>& y) {
    return x.c != y.c;
  }
  template <typename T>
  bool operator<(const stack<T>& x, const stack<T>& y) {
    return x.c < y.c;
  }
  template <typename T>
  bool operator<=(const stack<T>& x, const stack<T>& y) {
    return x.c <= y.c;
  }
  template <typename T>
  bool operator>(const stack<T>& x, const stack<T>& y) {
    return x.c > y.c;
  }
  template <typename T>
  bool operator>=(const stack<T>& x, const stack<T>& y) {
    return x.c >= y.c;
  }
}  // namespace ft
#endif
