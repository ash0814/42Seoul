#ifndef SET_HPP
#define SET_HPP

#include <functional>
#include <memory>
#include "utility.hpp"
#include "rbtree.hpp"
#include "reverse_iterator.hpp"
#include "algorithm.hpp"

namespace ft
{
  template <typename T, typename Compare = std::less<T>, typename Allocator = std::allocator<T> >
  class set
  {
  public:
    typedef T key_type;
    typedef T value_type;
    typedef Compare compare_type;
    typedef Compare key_compare;
    typedef Compare value_compare;

    typedef Allocator allocator_type;
    typedef typename allocator_type::template rebind<value_type>::other type_allocator;
    typedef std::allocator_traits<type_allocator> type_traits;
    typedef typename type_traits::pointer pointer;
    typedef typename type_traits::const_pointer const_pointer;
    typedef value_type &reference;
    typedef const value_type &const_reference;

    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;

    typedef typename ft::rb_tree<const value_type, key_type, value_compare, allocator_type>::iterator iterator;
    typedef typename ft::rb_tree<const value_type, key_type, value_compare, allocator_type>::const_iterator const_iterator;
    typedef ft::reverse_iterator<iterator> reverse_iterator;
    typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

    explicit set(const compare_type &comp = compare_type(), const allocator_type &alloc = allocator_type())
        : key_value_comp(comp), tree(comp, alloc) {}

    template <typename InputIterator>
    set(InputIterator first, InputIterator last, const compare_type &comp = compare_type(), const allocator_type &alloc = allocator_type(),
        typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = ft::nil)
        : key_value_comp(comp), tree(comp, alloc)
    {
      insert(first, last);
    }
    set(const set &s) : key_value_comp(s.key_value_comp), tree(s.tree) {}
    ~set(void) {}

    set &operator=(const set &s)
    {
      if (this != &s)
      {
        key_value_comp = s.key_value_comp;
        tree = s.tree;
      }
      return *this;
    }

    iterator begin(void) { return tree.begin(); }
    const_iterator begin(void) const { return tree.begin(); }
    iterator end(void) { return tree.end(); }
    const_iterator end(void) const { return tree.end(); }
    reverse_iterator rbegin(void) { return reverse_iterator(end()); }
    const_reverse_iterator rbegin(void) const { return reverse_iterator(end()); }
    reverse_iterator rend(void) { return reverse_iterator(begin()); }
    const_reverse_iterator rend(void) const { return reverse_iterator(begin()); }

    bool empty(void) const { return tree.empty(); }
    size_type size(void) const { return tree.size(); }
    size_type max_size(void) const { return tree.max_size(); }

    ft::pair<iterator, bool> insert(const value_type &value) { return tree.insert(value); }
    iterator insert(iterator position, const value_type &value) { return tree.insert(position, value); }
    template <typename InputIterator>
    void insert(InputIterator first, InputIterator last) { tree.insert(first, last); }

    void erase(iterator position) { tree.erase(position); }
    size_type erase(const value_type &value) { return tree.erase(value); }
    void erase(iterator first, iterator last) { tree.erase(first, last); }
    void swap(set &s) { tree.swap(s.tree); }
    void clear(void) { tree.clear(); }

    key_compare key_comp(void) const { return key_value_comp; }
    value_compare value_comp(void) const { return key_value_comp; }

    iterator find(const value_type &value) const { return tree.find(value); }
    size_type count(const value_type &value) const { return find(value) != end(); }
    iterator lower_bound(const value_type &value) const { return tree.lower_bound(value); }
    iterator upper_bound(const value_type &value) const { return tree.upper_bound(value); }
    pair<iterator, iterator> equal_range(const value_type &value) const { return tree.equal_range(value); }

    allocator_type get_allocator(void) const { return tree.get_allocator(); }

  private:
    compare_type key_value_comp;
    ft::rb_tree<const value_type, key_type, value_compare, allocator_type> tree;
  };

  template <typename T, typename Compare, typename Allocator>
  bool operator==(const ft::set<T, Compare, Allocator> &x, const ft::set<T, Compare, Allocator> &y)
  {
    return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
  }

  template <typename T, typename Compare, typename Allocator>
  bool operator!=(const ft::set<T, Compare, Allocator> &x, const ft::set<T, Compare, Allocator> &y)
  {
    return !(x == y);
  }

  template <typename T, typename Compare, typename Allocator>
  bool operator<(const ft::set<T, Compare, Allocator> &x, const ft::set<T, Compare, Allocator> &y)
  {
    return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
  }

  template <typename T, typename Compare, typename Allocator>
  bool operator<=(const ft::set<T, Compare, Allocator> &x, const ft::set<T, Compare, Allocator> &y)
  {
    return !(y < x);
  }

  template <typename T, typename Compare, typename Allocator>
  bool operator>(const ft::set<T, Compare, Allocator> &x, const ft::set<T, Compare, Allocator> &y)
  {
    return y < x;
  }

  template <typename T, typename Compare, typename Allocator>
  bool operator>=(const ft::set<T, Compare, Allocator> &x, const ft::set<T, Compare, Allocator> &y)
  {
    return !(x < y);
  }

  template <typename T, typename Compare, typename Allocator>
  void swap(ft::set<T, Compare, Allocator> &x, ft::set<T, Compare, Allocator> &y)
  {
    x.swap(y);
  }

}

#endif