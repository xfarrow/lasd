
#ifndef MATRIXCSR_HPP
#define MATRIXCSR_HPP

/* ************************************************************************** */

#include "../matrix.hpp"

#include "../../list/list.hpp"
#include "../../vector/vector.hpp"

#include <iostream>

namespace lasd {

template <typename Data>
class MatrixCSR : virtual public List<std::pair<Data,ulong>>,
                  virtual public Matrix<Data>{ // Must extend Matrix<Data>

protected:

  using Matrix<Data>::rows;
  using Matrix<Data>::columns;
  using List<std::pair<Data,ulong>>::size;
  Vector<struct List<std::pair<Data,ulong>>::Node**> R;

  using List<std::pair<Data,ulong>>::head;
  using typename List<std::pair<Data,ulong>>::Node;

/*
  Node
  | pair
  | | Data (actual element - first)
  | | ulong (column index - second)
  | next
*/

public:

  MatrixCSR();
  MatrixCSR(const ulong, const ulong); // A matrix of some specified dimension

  MatrixCSR(const MatrixCSR&);
  MatrixCSR(MatrixCSR&&) noexcept;

  virtual ~MatrixCSR();


  MatrixCSR& operator=(const MatrixCSR<Data>&);
  MatrixCSR& operator=(MatrixCSR<Data>&&) noexcept;

  bool operator==(const MatrixCSR&) const noexcept;
  bool operator!=(const MatrixCSR&) const noexcept;

  void RowResize(const ulong&) override; // Override Matrix member
  void ColumnResize(const ulong&) override; // Override Matrix member

  bool ExistsCell(const ulong&, const ulong&) const noexcept override; // Override Matrix member (should not throw exceptions)

  Data& operator()(const ulong, const ulong) override; // Override Matrix member (mutable access to the element; throw out_of_range when out of range)
  const Data& operator()(const ulong, const ulong) const override; // Override Matrix member (immutable access to the element; throw out_of_range when out of range and length_error when not present)

  void Clear() override; // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  virtual void MapPreOrder(const typename MappableContainer<Data>::MapFunctor, void*) override; // Override MappableContainer member
  virtual void MapPostOrder(const typename MappableContainer<Data>::MapFunctor, void*) override; // Override MappableContainer member
  virtual void FoldPreOrder(const typename FoldableContainer<Data>::FoldFunctor, const void*, void*) const override; // Override FoldableContainer member
  virtual void FoldPostOrder(const typename FoldableContainer<Data>::FoldFunctor, const void*, void*) const override; // Override FoldableContainer member

  void debug();
};

/* ************************************************************************** */

}

#include "matrixcsr.cpp"

#endif
