
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public BinaryTree<Data>{ // Must extend BinaryTree<Data>

private:

protected:

  using BinaryTree<Data>::size;
  // using BinaryTree<Data>::Node;
  Vector<struct NodeVec*> tree;

  struct NodeVec : virtual protected BinaryTree<Data>::Node { // Must extend Node

  private:

  protected:
    using BinaryTree<Data>::Node::data;
    ulong index;
    BinaryTreeVec<Data>* ReferenceToTree = nullptr;

  public:
    struct BinaryTree<Data>::Node& operator=(const NodeVec&) override; // Copy assignment of abstract types should not be possible.
    struct BinaryTree<Data>::Node& operator=(NodeVec&&) noexcept override; // Move assignment of abstract types should not be possible.
    bool IsLeaf() const noexcept override; // (concrete function should not throw exceptions)
    bool HasLeftChild() const noexcept override; // (concrete function should not throw exceptions)
    bool HasRightChild() const noexcept override; // (concrete function should not throw exceptions)
    struct BinaryTree<Data>::Node& LeftChild() const override; // (concrete function must throw std::out_of_range when not existent)
    struct BinaryTree<Data>::Node& RightChild() const override; // (concrete function must throw std::out_of_range when not existent)
  };

public:

  // Default constructor
  BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeVec(const LinearContainer<Data>&); // A binary tree obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeVec(const BinaryTreeVec<Data>&);

  // Move constructor
  BinaryTreeVec(BinaryTreeVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTreeVec();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeVec& operator=(const BinaryTreeVec<Data>&);

  // Move assignment
  BinaryTreeVec& operator=(BinaryTreeVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTreeVec&) const noexcept;
  bool operator!=(const BinaryTreeVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  struct BinaryTreeVec<Data>::NodeVec& Root() override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

  /* ----- override of map and fold in breadth ----- */
  using typename BinaryTree<Data>::MapFunctor;
  using typename BinaryTree<Data>::FoldFunctor;
  void MapBreadth(const MapFunctor, void*) override;
  void FoldBreadth(const FoldFunctor, const void*, void*) const override;

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
