#ifndef SYMMATH_PROPERTIES_PROPERTY_LIST_HPP
#define SYMMATH_PROPERTIES_PROPERTY_LIST_HPP

#include <iostream>
#include <memory>
#include <type_traits>

#include "property.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class PropertyList {
private:

  struct BaseVisitor {
    virtual ~BaseVisitor() = default;
    // virtual void visit(List &) = 0;
  };

  // template< typename T >
  // struct HasVisitor
  //   : public BaseVisitor {
  //
  //   bool result;
  //
  //   void visit(List &l) override {
  //
  //   }
  //
  //   template< typename U >
  //   void visit_impl(U &obj) {
  //     std::cout << "here" << '\n';
  //   }
  //
  // };

  struct List {
  public:
    virtual ~List() = default;
    virtual void accept(BaseVisitor &v) = 0;

    template< typename ...T >
    bool has() {
      TypeList<T...> tl;
      return false;
    }
  };

  template< typename ...T >
  struct TypeList final
    : public List {

    void accept(BaseVisitor &v) override {
      // v.visit(*this);
    }

  };

  std::unique_ptr<const List> ptr_;

public:

  explicit inline PropertyList();

  template< typename ...T >
  inline bool has();

private:

  template< typename ...T >
  inline PropertyList(TypeList<T...> tl);

  template< typename ...T >
  friend inline decltype(auto) make_property_list();

};

template< typename ...T >
inline decltype(auto) make_property_list() {
  PropertyList::TypeList<T...> tl;
  return PropertyList(tl);
}

// -----------------------------------------------------------------------------
// Constructor
inline PropertyList::PropertyList() {}

template< typename ...T >
inline PropertyList::PropertyList(TypeList<T...> tl)
  : ptr_(std::make_unique<TypeList<T...>>(std::move(tl))) {}

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename ...T >
inline bool PropertyList::has() {
  return ptr_->has<T...>();
}

} // sym

#endif // SYMMATH_PROPERTIES_PROPERTY_LIST_HPP
