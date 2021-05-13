
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST : virtual public BinaryTreeLnk<Data> { // Must extend BinaryTreeLnk<Data>

protected:

  using BinaryTreeLnk<Data>::size;
  using BinaryTreeLnk<Data>::root;
  using typename BinaryTreeLnk<Data>::NodeLnk;


public:

  BST() = default;

  /* ************************************************************************ */

  // Specific constructors
  BST(const LinearContainer<Data>&); // A bst obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  BST(const BST<Data>&);

  // Move constructor
  BST(BST<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BST();

  /* ************************************************************************ */

  // Copy assignment
  BST<Data>& operator=(const BST<Data>&);

  // Move assignment
  BST<Data>& operator=(BST<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BST<Data>&) const noexcept;
  bool operator!=(const BST<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  void Insert(const Data&) noexcept; // Copy of the value
  void Insert(Data&&) noexcept; // Move of the value
  void Remove(const Data&) noexcept;

  const Data& Min() const; // (concrete function must throw std::length_error when empty)
  Data MinNRemove(); // (concrete function must throw std::length_error when empty)
  void RemoveMin(); // (concrete function must throw std::length_error when empty)

  const Data& Max() const; // (concrete function must throw std::length_error when empty)
  Data MaxNRemove(); // (concrete function must throw std::length_error when empty)
  void RemoveMax(); // (concrete function must throw std::length_error when empty)

  const Data& Predecessor(const Data&) const; // (concrete function must throw std::length_error when empty)
  Data PredecessorNRemove(const Data&); // (concrete function must throw std::length_error when empty)
  void RemovePredecessor(const Data&); // (concrete function must throw std::length_error when empty)

  const Data& Successor(const Data&) const; // (concrete function must throw std::length_error when empty)
  Data SuccessorNRemove(const Data&); // (concrete function must throw std::length_error when empty)
  void RemoveSuccessor(const Data&); // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  bool Exists(const Data&) const noexcept override; // Override TestableContainer member

protected:

  // Auxiliary member functions

  Data DataNDelete(NodeLnk*);

  NodeLnk* Detach(NodeLnk*&) noexcept;

  NodeLnk* DetachMin(NodeLnk*&) noexcept;
  NodeLnk* DetachMax(NodeLnk*&) noexcept;

  NodeLnk* SkipOnLeft(NodeLnk*&) noexcept;
  NodeLnk* SkipOnRight(NodeLnk*&) noexcept;

  NodeLnk* const& FindPointerToMin(NodeLnk* const&) const noexcept;
  NodeLnk*& FindPointerToMin(NodeLnk*&) noexcept;
  NodeLnk* const& FindPointerToMax(NodeLnk* const&) const noexcept;
  NodeLnk*& FindPointerToMax(NodeLnk*&) noexcept;

  NodeLnk* const& FindPointerTo(NodeLnk* const&, Data) const noexcept;
  NodeLnk*& FindPointerTo(NodeLnk*&, Data) noexcept;

  NodeLnk* const* FindPointerToPredecessor(NodeLnk* const&, Data) const noexcept;
  NodeLnk** FindPointerToPredecessor(NodeLnk*&, Data) noexcept;
  NodeLnk* const* FindPointerToSuccessor(NodeLnk* const&, Data) const noexcept;
  NodeLnk** FindPointerToSuccessor(NodeLnk*&, Data) noexcept;


};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
