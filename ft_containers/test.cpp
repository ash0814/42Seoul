#include <iostream>
#include <type_traits>
#include "type_traits.hpp"
// int negate(int i) { 
//   std::cout << "int " << std::endl;
//   return -i; }

// template <typename T>
// typename T::value_type negate(const T& t) {
//   std::cout << "SFINAE" << std::endl;
//   return -T(t);
// }

// template <typename T>
// void negate(const T& t) {
//   typename T::value_type n = -t();
// }

template <class T>
typename std::enable_if<std::is_integral<T>::value, bool>::type
  is_odd (T i) {return bool(i%2);}

template <class T>
typename ft::enable_if<ft::is_integral<T>::value, bool>::type
  is_even (T i) {return bool(!(i%2));}



int main()
{
  std::cout << is_odd(10) << std::endl;
  std::cout << is_even(10) << std::endl;
}