#ifndef TREE_UTILS_HPP
#define TREE_UTILS_HPP

#include <algorithm>
#include <limits>
#include <memory>
#include "iterator_traits.hpp"
#include "utility.hpp"
#include "type_traits.hpp"

#define RED 0
#define BLACK 1

namespace ft
{
  template <typename T> struct tree_node {
    typedef T       value_type;
    typedef bool    binary_type;

    tree_node *parent;
    tree_node *left;
    tree_node *right;
    value_type val;
    binary_type color;

    tree_node(void) : parent(ft::nil), left(ft::nil), right(ft::nil), val(value_type()), color(binary_type()) {}

    tree_node(const value_type &value): parent(ft::nil), left(ft::nil), right(ft::nil), val(value), color(binary_type()) {}

    tree_node(const tree_node &n): parent(n.parent), left(n.left), right(n.right), val(n.val), color(n.color) {}
  
    ~tree_node(void) {}

    tree_node &operator=(const tree_node &n) {
      if (this != &n) {
        parent = n.parent;
        left = n.left;
        right = n.right;
        val = n.val;
        color = n.color;
      }
      return *this;
    }
  };

  template <class Ptr>
  bool is_left_child(const Ptr &ptr)
  {
    return ptr == ptr->parent->left;
  }

  template <class Ptr>
  bool is_right_child(const Ptr &ptr)
  {
    return ptr == ptr->parent->right;
  }

  template <class Ptr>
  bool is_black_node(const Ptr &ptr)
  {
    return ptr->color;
  }

  template <class Ptr>
  bool is_red_node(const Ptr &ptr)
  {
    return !ptr->color;
  }

  template <class Ptr>
  Ptr get_min(Ptr ptr, Ptr nil)
  {
    while (ptr->left != nil)
      ptr = ptr->left;
    return ptr;
  }

  template <class Ptr>
  Ptr get_max(Ptr ptr, Ptr nil)
  {
    while (ptr->right != nil)
      ptr = ptr->right;
    return ptr;
  }

  template <class Ptr>
  Ptr get_next_node(Ptr ptr, Ptr nil)
  {
    if (ptr->right != nil)
      return get_min(ptr->right, nil);
    while (!is_left_child(ptr))
      ptr = ptr->parent;
    return ptr->parent;
  }

  template <class Ptr>
  Ptr get_prev_node(Ptr ptr, Ptr nil)
  {
    if (ptr->left != nil)
      return get_max(ptr->left, nil);
    while (!is_right_child(ptr))
      ptr = ptr->parent;
    return ptr->parent;
  }

  //대소가 아니라 기준이 comp에 있는거임.
  template <typename U, typename V, class Comp>
  bool is_equal(const U &u, const V &v, Comp comp)
  {
    return !comp(u, v) && !comp(v, u);
  }

  template <typename U, typename V>
  class tree_iterator
  {
  public:
    typedef U                                                               value_type;
    typedef value_type                                                      *pointer;
    typedef value_type                                                      &reference;
    typedef V                                                               *iterator_type;
    typedef typename ft::iterator_traits<iterator_type>::difference_type    difference_type;
    typedef typename ft::iterator_traits<iterator_type>::value_type         node_type;
    typedef typename ft::iterator_traits<iterator_type>::pointer            node_pointer;
    typedef typename ft::iterator_traits<iterator_type>::reference          node_reference;
    typedef typename ft::iterator_traits<iterator_type>::iterator_category  iterator_category;

    tree_iterator(void) : __cur(ft::nil), __nil(ft::nil) {}
    tree_iterator(node_pointer cur, node_pointer nil)
        : __cur(cur), __nil(nil) {}
    tree_iterator(const tree_iterator &i)
        : __cur(i.__cur), __nil(i.__nil) {}
    ~tree_iterator(void) {}

    tree_iterator &operator=(const tree_iterator &i)
    {
      if (this != &i)
      {
        __cur = i.__cur;
        __nil = i.__nil;
      }
      return *this;
    }

    node_pointer base(void) const { return __cur; }
    pointer operator->(void) const { return &__cur->val; }
    reference operator*(void) const { return __cur->val; }

    tree_iterator &operator++(void)
    {
      __cur = ft::get_next_node(__cur, __nil);
      return *this;
    }
    tree_iterator &operator--(void)
    {
      __cur = ft::get_prev_node(__cur, __nil);
      return *this;
    }
    tree_iterator operator++(int)
    {
      tree_iterator tmp(*this);
      ++(*this);
      return tmp;
    }
    tree_iterator operator--(int)
    {
      tree_iterator tmp(*this);
      --(*this);
      return tmp;
    }

    template <typename T>
    bool operator==(const tree_iterator<T, node_type> &i) const
    {
      return __cur == i.base();
    }
    template <typename T>
    bool operator!=(const tree_iterator<T, node_type> &i) const
    {
      return !(*this == i);
    }

    operator tree_iterator<const value_type, node_type>(void) const
    {
      return tree_iterator<const value_type, node_type>(__cur, __nil);
    }

  private:
    node_pointer __cur;
    node_pointer __nil;
  };
}

#endif
