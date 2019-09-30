#ifndef SYMMATH_OPERATIONS_BASIC_ADD_HPP
#define SYMMATH_OPERATIONS_BASIC_ADD_HPP

#include <iostream>

#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/conditional.hpp>
#include <symmath/type_traits/covariant.hpp>
#include <symmath/type_traits/is_temporary.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class Add
  : private Operation {
public:

  using R1              = ResultType_t<T1>;
  using R2              = ResultType_t<T2>;
  using ResultType      = Covariant_t<R1, R2>;

  using LhsOperandType  = If_t<IsTemporary<T1>, const T1, const T1&>;
  using RhsOperandType  = If_t<IsTemporary<T2>, const T2, const T2&>;

private:

  LhsOperandType lhs_;
  RhsOperandType rhs_;

public:

  explicit inline Add(const T1 &lhs, const T2 &rhs);
  explicit inline Add(const T1 &lhs, T2 &&rhs);
  explicit inline Add(T1 &&lhs, const T2 &rhs);
  explicit inline Add(T1 &&lhs, T2 &&rhs);

private:

  template< typename U >
  friend inline void
  assign_(U &lhs, const Add<T1, T2> &rhs) {
    assign_(lhs, rhs.lhs_);
    assign_add_(lhs, rhs.rhs_);
  }

  template< typename U >
  friend inline void
  assign_add_(U &lhs, const Add<T1, T2> &rhs) {
    assign_add_(lhs, rhs.lhs_);
    assign_add_(lhs, rhs.rhs_);
  }

  template< typename U >
  friend inline void
  assign_sub_(U &lhs, const Add<T1, T2> &rhs) {
    assign_sub_(lhs, rhs.lhs_);
    assign_sub_(lhs, rhs.rhs_);
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T1,
          typename T2 >
inline Add<T1, T2>::Add(const T1 &lhs, const T2 &rhs)
  : lhs_(lhs),
    rhs_(rhs) {
      std::cout << "first one" << '\n';
      std::cout << IsTemporary<T1> << '\n';
      std::cout << IsTemporary<T2> << '\n';
    }

template< typename T1,
          typename T2 >
inline Add<T1, T2>::Add(const T1 &lhs, T2 &&rhs)
  : lhs_(lhs),
    rhs_(std::move(rhs)) {
      std::cout << "second one" << '\n';
      std::cout << IsTemporary<T1> << '\n';
      std::cout << IsTemporary<T2> << '\n';
    }

template< typename T1,
          typename T2 >
inline Add<T1, T2>::Add(T1 &&lhs, const T2 &rhs)
  : lhs_(std::move(lhs)),
    rhs_(rhs) {
      std::cout << "third one" << '\n';
      std::cout << IsTemporary<T1> << '\n';
      std::cout << IsTemporary<T2> << '\n';
    }

template< typename T1,
          typename T2 >
inline Add<T1, T2>::Add(T1 &&lhs, T2 &&rhs)
  : lhs_(std::move(lhs)),
    rhs_(std::move(rhs)) {
      std::cout << "fourth one" << '\n';
      std::cout << IsTemporary<T1> << '\n';
      std::cout << IsTemporary<T2> << '\n';
    }

} // sym

#endif // SYMMATH_OPERATIONS_BASIC_ADD_HPP
