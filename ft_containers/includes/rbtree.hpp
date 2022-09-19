#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "iterator_traits.hpp"
#include "utility.hpp"
#include "type_traits.hpp"
#include "tree_utils.hpp"
#include <limits>
#include <memory>
#include <algorithm>

namespace ft
{
  template <typename T, class Key, class Comp, class Allocator>
  class rb_tree
  {


  public:
    typedef T value_type;
    typedef Key key_type;
    typedef Comp compare_type;

    typedef tree_node<value_type> node_type;
    typedef tree_node<value_type> *node_pointer;

    typedef tree_iterator<value_type, node_type> iterator;
    typedef tree_iterator<const value_type, node_type> const_iterator;

    typedef Allocator allocator_type;
    typedef typename allocator_type::template rebind<node_type>::other node_allocator;

    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;

    rb_tree(const compare_type &comp, const allocator_type &alloc) : _comp(comp), _alloc(alloc), _size(size_type())
    {
      _nil = _alloc.allocate(1);
      _alloc.construct(_nil, value_type());
      _nil->color = BLACK;
      _nil->parent = _nil;
      _nil->left = _nil;
      _nil->right = _nil;
      _end = construct_node(value_type());
      _end->color = BLACK;
      _begin = _end;
    }

    rb_tree(const rb_tree &t) : _comp(t._comp), _alloc(t._alloc), _size(size_type())
    {
      _nil = _alloc.allocate(1);
      _alloc.construct(_nil, value_type());
      _nil->color = BLACK;
      _nil->parent = _nil;
      _nil->left = _nil;
      _nil->right = _nil;
      _end = construct_node(value_type());
      _end->color = BLACK;
      _begin = _end;
      insert(t.begin(), t.end());
    }

    ~rb_tree(void)
    {
      destruct_node(_end);
      _alloc.destroy(_nil);
      _alloc.deallocate(_nil, 1);
    }

    rb_tree &operator=(const rb_tree &t)
    {
      if (this != &t)
      {
        rb_tree tmp(t);
        swap(tmp);
      }
      return *this;
    }

    iterator begin(void) { return iterator(_begin, _nil); }
    const_iterator begin(void) const { return const_iterator(_begin, _nil); }
    iterator end(void) { return iterator(_end, _nil); }
    const_iterator end(void) const { return const_iterator(_end, _nil); }

    // utils

  void clear()
  {
    rb_tree tmp(_comp, _alloc);
    swap(tmp);
  }

    void swap(rb_tree &t)
    {
      std::swap(_nil, t._nil);
      std::swap(_begin, t._begin);
      std::swap(_end, t._end);
      std::swap(_comp, t._comp);
      std::swap(_alloc, t._alloc);
      std::swap(_size, t._size);
    }

    iterator find(const key_type &key)
    {
      node_pointer ptr = get_root();
      while (ptr != _nil)
      {
        if (_comp(key, ptr->val))
          ptr = ptr->left;
        else if (_comp(ptr->val, key))
          ptr = ptr->right;
        else
          return iterator(ptr, _nil);
      }
      return iterator(_end, _nil);
    }
    const_iterator find(const key_type &key) const
    {
      node_pointer ptr = get_root();
      while (ptr != _nil)
      {
        if (_comp(key, ptr->val))
          ptr = ptr->left;
        else if (_comp(ptr->val, key))
          ptr = ptr->right;
        else
          return const_iterator(ptr, _nil);
      }
      return const_iterator(_end, _nil);
    }

    iterator lower_bound(const key_type &key)
    {
      node_pointer ptr = get_root();
      node_pointer tmp = _end;
      while (ptr != _nil) {
        if (!_comp(ptr->val, key)) {
          tmp = ptr;
          ptr = ptr->left;
        } else {
          ptr = ptr->right;
        }
      }
      return iterator(tmp, _nil);
    }
    const_iterator lower_bound(const key_type &key) const
    {
      node_pointer ptr = get_root();
      node_pointer tmp = _end;
      while (ptr != _nil) {
        if (!_comp(ptr->val, key)) {
          tmp = ptr;
          ptr = ptr->left;
        } else {
          ptr = ptr->right;
        }
      }
      return iterator(tmp, _nil);
    }
    iterator upper_bound(const key_type &key)
    {
      node_pointer ptr = get_root();
      node_pointer tmp = _end;
      while (ptr != _nil) {
        if (_comp(key, ptr->val)) {
          tmp = ptr;
          ptr = ptr->left;
        } else {
          ptr = ptr->right;
        }
      }
      return iterator(tmp, _nil);
    }
    const_iterator upper_bound(const key_type &key) const
    {
      node_pointer ptr = get_root();
      node_pointer tmp = _end;
      while (ptr != _nil) {
        if (_comp(key, ptr->val)) {
          tmp = ptr;
          ptr = ptr->left;
        } else {
          ptr = ptr->right;
        }
      }
      return const_iterator(tmp, _nil);
    }

    ft::pair<iterator, iterator> equal_range(const key_type &key)
    {
      return ft::make_pair(lower_bound(key), upper_bound(key));
    }
    ft::pair<const_iterator, const_iterator> equal_range(const key_type &key) const
    {
      return ft::make_pair(lower_bound(key), upper_bound(key));
    }

    //get_allocator
    allocator_type get_allocator(void) const
    {
      return _alloc;
    }

    // capacity
    size_type size(void) const { return _size; }
    size_type max_size(void) const { return (_alloc.max_size()); }
    bool empty(void) const { return _size == 0; }

    // insert
    pair<iterator, bool> insert(const value_type &v)
    {
      node_pointer parent_ptr = search_parent(v);
      if (parent_ptr != _end && is_equal(parent_ptr->val, v, _comp))
        return ft::make_pair(iterator(parent_ptr, _nil), false);
      return ft::make_pair(iterator(insert_value(v, parent_ptr), _nil), BLACK);
    }

    iterator insert(iterator position, const value_type &v)
    {
      node_pointer parent_ptr = search_parent(v, position.base());
      if (parent_ptr != _end && is_equal(parent_ptr->val, v, _comp))
        return iterator(parent_ptr, _nil);
      return iterator(insert_value(v, parent_ptr), _nil);
    }

    template <class InputIterator>
    void insert(InputIterator first, InputIterator last)
    {
      for (; first != last; first++)
        insert(*first);
    }

  // erase
    iterator erase(iterator position)
    {
      if (_size == 0)
        return iterator(_nil, _nil);
      iterator tmp(position);
      ++tmp;
      if (position == begin())
        _begin = tmp.base();
      --_size;
      erase_pos(position.base());
      _alloc.destroy(position.base());
      _alloc.deallocate(position.base(), 1);
      return tmp;
    }

    template <typename U>
    size_type erase(const U &k)
    {
      iterator i(find_node(k), _nil);
      if (i == end())
        return 0;
      erase(i);
      return 1;
    }

    void erase(iterator first, iterator last)
    {
      for (; first != last;)
        first = erase(first);
    }

  private:
    node_pointer _nil;
    node_pointer _begin;
    node_pointer _end;
    compare_type _comp;
    node_allocator _alloc;
    size_type _size;


    //insert utils
    node_pointer search_parent(const value_type &val, node_pointer pos = ft::nil)
    {
      if (pos && pos != _end)
      {
        if (_comp(val, pos->val) && pos->left == _nil)
        {
          iterator prev = iterator(pos, _nil);
          if (prev == begin() || _comp(*--prev, val))
            return pos;
        }
        else if (pos->right == _nil)
        {
          iterator next = iterator(pos, _nil);
          if (next == end() || _comp(val, *++next))
            return pos;
        }
      }
      node_pointer cur = get_root();
      node_pointer tmp = _end;
      while (cur != _nil)
      {
        tmp = cur;
        if (_comp(val, cur->val))
          cur = cur->left;
        else if (_comp(cur->val, val))
          cur = cur->right;
        else
          return cur;
      }
      return tmp;
    }

    node_pointer insert_value(const value_type &value, node_pointer parent)
    {
      node_pointer ptr = construct_node(value);
      if (parent == _end)
        set_root(ptr);
      else if (_comp(value, parent->val))
        parent->left = ptr;
      else
        parent->right = ptr;
      ptr->parent = parent;
      fix_after_insert(ptr);
      if (_begin == _end || _comp(ptr->val, _begin->val))
        _begin = ptr;
      _size++;
      return ptr;
    }

    void fix_after_insert(node_pointer ptr)
    {
      while (is_red_node(ptr->parent)) {
        if (is_left_child(ptr->parent))
          fix_insert_left(ptr);
        else
          fix_insert_right(ptr);
      }
      get_root()->color = BLACK;
    }

    void fix_insert_left(node_pointer &ptr)
    {
      node_pointer uncle = ptr->parent->parent->right;
      if (is_red_node(uncle)) {
        ptr->parent->color = BLACK;
        uncle->color = BLACK;
        uncle->parent->color = RED;
        ptr = uncle->parent;
      } else {
        if (is_right_child(ptr)) {
          ptr = ptr->parent;
          rotation_left(ptr);
        }
        ptr->parent->color = BLACK;
        ptr->parent->parent->color = RED;
        rotation_right(ptr->parent->parent);
      }
    }

    void fix_insert_right(node_pointer &ptr)
    {
      node_pointer uncle = ptr->parent->parent->left;
      if (is_red_node(uncle)) {
        ptr->parent->color = BLACK;
        uncle->color = BLACK;
        uncle->parent->color = RED;
        ptr = uncle->parent;
      } else {
        if (is_left_child(ptr)) {
          ptr = ptr->parent;
          rotation_right(ptr);
        }
        ptr->parent->color = BLACK;
        ptr->parent->parent->color = RED;
        rotation_left(ptr->parent->parent);
      }
    }
    // erase_utils
    void erase_pos(node_pointer ptr)
    {
      node_pointer up_node;
      node_pointer replace_node;
      bool original_node = is_black_node(ptr);
      if (ptr->left == _nil) {
        up_node = ptr->right;
        transport(ptr, ptr->right);
      } else if (ptr->right == _nil) {
        up_node = ptr->left;
        transport(ptr, ptr->left);
      } else {
        replace_node = get_min(ptr->right, _nil);
        original_node = is_black_node(replace_node);
        up_node = replace_node->right;
        if (replace_node->parent == ptr) {
          up_node->parent = replace_node;
        } else {
          transport(replace_node, replace_node->right);
          replace_node->right = ptr->right;
          replace_node->right->parent = replace_node;
        }
        transport(ptr, replace_node);
        replace_node->left = ptr->left;
        replace_node->left->parent = replace_node;
        replace_node->color = is_black_node(ptr);
      }
      if (original_node == BLACK)
        fix_after_erase(up_node);
    }

    void fix_after_erase(node_pointer ptr)
    {
      while (ptr != get_root() && is_black_node(ptr)) {
        if (is_left_child(ptr))
          fix_erase_left(ptr);
        else
          fix_erase_right(ptr);
      }
      ptr->color = BLACK;
    }

    void fix_erase_left(node_pointer &ptr)
    {
      node_pointer sibling = ptr->parent->right;
      if (is_red_node(sibling))
      {
        sibling->color = BLACK;
        ptr->parent->color = RED;
        rotation_left(ptr->parent);
        sibling = ptr->parent->right;
      }
      if (is_black_node(sibling->left) && is_black_node(sibling->right))
      {
        sibling->color = RED;
        ptr = ptr->parent;
      } else if (is_black_node(sibling->right)) {
        sibling->left->color = BLACK;
        sibling->color = RED;
        rotation_right(sibling);
        sibling = ptr->parent->right;
      }
      if (is_red_node(sibling->right))
      {
        sibling->color = is_black_node(ptr->parent);
        ptr->parent->color = BLACK;
        sibling->right->color = BLACK;
        rotation_left(ptr->parent);
        ptr = get_root();
      }
    }

    void fix_erase_right(node_pointer &ptr)
    {
      node_pointer sibling = ptr->parent->left;
      if (is_red_node(sibling))
      {
        sibling->color = BLACK;
        ptr->parent->color = RED;
        rotation_right(ptr->parent);
        sibling = ptr->parent->left;
      }
      if (is_black_node(sibling->right) && is_black_node(sibling->left))
      {
        sibling->color = RED;
        ptr = ptr->parent;
      } else if (is_black_node(sibling->left)) {
        sibling->right->color = BLACK;
        sibling->color = RED;
        rotation_left(sibling);
        sibling = ptr->parent->left;
      }
      if (is_red_node(sibling->left))
      {
        sibling->color = is_black_node(ptr->parent);
        ptr->parent->color = BLACK;
        sibling->left->color = BLACK;
        rotation_right(ptr->parent);
        ptr = get_root();
      }
    }

    void transport(node_pointer former, node_pointer latter)
    {
      if (former->parent == _end)
        set_root(latter);
      else if (is_left_child(former))
        former->parent->left = latter;
      else
        former->parent->right = latter;
      latter->parent = former->parent;
    }

    // node_utils
    void destruct_node(node_pointer ptr)
    {
      if (ptr == _nil)
        return;
      destruct_node(ptr->left);
      destruct_node(ptr->right);
      _alloc.destroy(ptr);
      _alloc.deallocate(ptr, 1);
    }

    node_pointer construct_node(const value_type &value)
    {
      node_pointer ptr = _alloc.allocate(1);
      _alloc.construct(ptr, value);
      ptr->parent = _nil;
      ptr->left = _nil;
      ptr->right = _nil;
      ptr->color = RED;
      return ptr;
    }

    node_pointer get_root(void) const
    {
      return _end->left;
    }
    void set_root(const node_pointer ptr)
    {
      ptr->parent = _end;
      _end->left = ptr;
    }

    void rotation_left(node_pointer ptr)
    {
      node_pointer child = ptr->right;
      ptr->right = child->left;
      if (ptr->right != _nil)
        ptr->right->parent = ptr;
      node_pointer parent = ptr->parent;
      child->parent = parent;
      if (parent == _end)
        set_root(child);
      else if (is_left_child(ptr))
        parent->left = child;
      else
        parent->right = child;
      child->left = ptr;
      ptr->parent = child;
    }

    void rotation_right(node_pointer ptr)
    {
      node_pointer child = ptr->left;
      ptr->left = child->right;
      if (ptr->left != _nil)
        ptr->left->parent = ptr;
      node_pointer parent = ptr->parent;
      child->parent = parent;
      if (parent == _end)
        set_root(child);
      else if (is_left_child(ptr))
        parent->left = child;
      else
        parent->right = child;
      child->right = ptr;
      ptr->parent = child;
    }

    template <typename U>
    node_pointer find_node(const U &value) const
    {
      node_pointer ptr = get_root();
      while (ptr != _nil) {
        if (_comp(value, ptr->val))
          ptr = ptr->left;
        else if (_comp(ptr->val, value))
          ptr = ptr->right;
        else
          return ptr;
      }
      return _end;
    }
  };
}

#endif