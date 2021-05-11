
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST { // Must extend BinaryTreeLnk<Data>

private:

  // ...

protected:

  // using BinaryTreeLnk<Data>::???;

  // ...

public:

  // Default constructor
  // BST() specifiers;

  /* ************************************************************************ */

  // Specific constructors
  // BST(argument) specifiers; // A bst obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  // BST(argument) specifiers;

  // Move constructor
  // BST(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BST() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions

  // type Insert(argument) specifiers; // Copy of the value
  // type Insert(argument) specifiers; // Move of the value
  // type Remove(argument) specifiers;

  // type Min(argument) specifiers; // (concrete function must throw std::length_error when empty)
  // type MinNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
  // type RemoveMin(argument) specifiers; // (concrete function must throw std::length_error when empty)

  // type Max(argument) specifiers; // (concrete function must throw std::length_error when empty)
  // type MaxNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
  // type RemoveMax(argument) specifiers; // (concrete function must throw std::length_error when empty)

  // type Predecessor(argument) specifiers; // (concrete function must throw std::length_error when empty)
  // type PredecessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
  // type RemovePredecessor(argument) specifiers; // (concrete function must throw std::length_error when empty)

  // type Successor(argument) specifiers; // (concrete function must throw std::length_error when empty)
  // type SuccessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
  // type RemoveSuccessor(argument) specifiers; // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member

protected:

  // Auxiliary member functions

  // type DataNDelete(argument) specifiers;

  // type Detach(argument) specifiers;

  // type DetachMin(argument) specifiers;
  // type DetachMax(argument) specifiers;

  // type SkipOnLeft(argument) specifiers;
  // type SkipOnRight(argument) specifiers;

  // type FindPointerToMin(argument) specifiers;
  // type FindPointerToMax(argument) specifiers;

  // type FindPointerTo(argument) specifiers;

  // type FindPointerToPredecessor(argument) specifiers;
  // type FindPointerToSuccessor(argument) specifiers;

};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
