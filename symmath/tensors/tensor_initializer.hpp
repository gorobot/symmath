#ifndef SYMMATH_TENSORS_TENSOR_INITIALIZER_HPP
#define SYMMATH_TENSORS_TENSOR_INITIALIZER_HPP

#include <array>
#include <vector>

#include <symmath/type_traits/boolean.hpp>
#include <symmath/type_traits/nested_initializer_list.hpp>

namespace sym {

// -----------------------------------------------------------------------------

namespace {

template< typename T >
struct IsNestedInitializer {
private:

  template< typename U >
  static TrueType test(std::initializer_list<U>);

  static FalseType test(...);

public:

  using type = decltype(test(std::declval<T&>()));

};

} // detail

// -----------------------------------------------------------------------------

template< typename T >
std::vector<T> flatten_initializer_list(NestedInitializerList_t<T, 1> list) {
  std::vector<T> v = list;
  return v;
}

template< typename T >
std::vector<T> flatten_initializer_list(NestedInitializerList_t<T, 2> list) {
  std::vector<T> v;
  for(auto l : list) {
    v.insert(v.end(), l);
  }
  return v;
}

template< typename T >
std::vector<T> flatten_initializer_list(NestedInitializerList_t<T, 3> list) {
  std::vector<T> v;
  for(auto l : list) {
    std::vector<T> lv = flatten_initializer_list<T>(l);
    v.insert(v.end(), lv.begin(), lv.end());
  }
  return v;
}

template< typename T >
std::vector<T> flatten_initializer_list(NestedInitializerList_t<T, 4> list) {
  std::vector<T> v;
  for(auto l : list) {
    std::vector<T> lv = flatten_initializer_list<T>(l);
    v.insert(v.end(), lv.begin(), lv.end());
  }
  return v;
}

// -----------------------------------------------------------------------------

template< typename T >
std::array<size_t, 1> dim_initializer_list(NestedInitializerList_t<T, 1> list) {
  std::array<size_t, 1> arr = {list.size()};
  return arr;
}

template< typename T >
std::array<size_t, 2> dim_initializer_list(NestedInitializerList_t<T, 2> list) {
  std::array<size_t, 2> arr;
  arr[0] = list.size();

  // TODO: Fix this.
  for(auto l : list) {
    arr[1] = l.size();
    break;
  }
  return arr;
}

template< typename T >
std::array<size_t, 3> dim_initializer_list(NestedInitializerList_t<T, 3> list) {
  std::array<size_t, 3> arr;
  arr[0] = list.size();

  // TODO: Fix this.
  for(auto l1 : list) {
    arr[1] = l1.size();
    for(auto l2 : l1) {
      arr[2] = l2.size();
      break;
    }
    break;
  }
  return arr;
}

template< typename T >
std::array<size_t, 4> dim_initializer_list(NestedInitializerList_t<T, 4> list) {
  std::array<size_t, 4> arr;
  arr[0] = list.size();

  // TODO: Fix this.
  for(auto l1 : list) {
    arr[1] = l1.size();
    for(auto l2 : l1) {
      arr[2] = l2.size();
      for(auto l3 : l2) {
        arr[3] = l3.size();
        break;
      }
      break;
    }
    break;
  }
  return arr;
}

} // sym

#endif // SYMMATH_TENSORS_TENSOR_INITIALIZER_HPP
