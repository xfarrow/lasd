
#ifndef MATRIXVEC_HPP
#define MATRIXVEC_HPP

#include "../matrix.hpp"
#include "../../vector/vector.hpp"

namespace lasd {

template <typename Data>
class MatrixVec : virtual public Matrix<Data>,
                  virtual public Vector<Data>{ // Must extend Matrix<Data>

protected:

  using Matrix<Data>::rows;
  using Matrix<Data>::columns;
  using Vector<Data>::size;
  using Vector<Data>::Elements;

public:


  MatrixVec() = default;
  MatrixVec(ulong, ulong); // A matrix of some specified dimension
  MatrixVec(const MatrixVec&);
  MatrixVec(MatrixVec&&) noexcept;

  virtual ~MatrixVec();


  MatrixVec& operator=(const MatrixVec&);
  MatrixVec& operator=(MatrixVec&&) noexcept;

  bool operator==(const MatrixVec&) const noexcept;
  bool operator!=(const MatrixVec&) const noexcept;

  // Specific member functions (inherited from Matrix)
  void RowResize(const ulong&) override; // Override Matrix member
  void ColumnResize(const ulong&) override; // Override Matrix member
  bool ExistsCell(const ulong&, const ulong&) const noexcept override; // Override Matrix member (should not throw exceptions)
  Data& operator()(const ulong&, const ulong&) override; // Override Matrix member (mutable access to the element; throw out_of_range when out of range)
  const Data& operator()(const ulong&, const ulong&) const override; // Override Matrix member (immutable access to the element; throw out_of_range when out of range and length_error when not present)


  // Specific member functions (inherited from Container)
  void Clear() override; // Override Container member

  using Vector<Data>::MapPreOrder;
  using Vector<Data>::MapPostOrder;
  using Vector<Data>::FoldPreOrder;
  using Vector<Data>::FoldPostOrder;

  // type MapPreOrder(arguments) specifiers; // Override MappableContainer member
  // type MapPostOrder(arguments) specifiers; // Override MappableContainer member
  // type FoldPreOrder(arguments) specifiers; // Override FoldableContainer member
  // type FoldPostOrder(arguments) specifiers; // Override FoldableContainer member

};

}

#include "matrixvec.cpp"

#endif
