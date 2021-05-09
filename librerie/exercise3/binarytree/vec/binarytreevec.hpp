
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

namespace lasd {

template <typename Data>
class BinaryTreeVec : virtual public BinaryTree<Data>{ // Must extend BinaryTree<Data>

protected:

  struct NodeVec : virtual public BinaryTree<Data>::Node { // Must extend Node

  protected:
    using BinaryTree<Data>::Node::data;
    ulong index;
    BinaryTreeVec<Data>* ReferenceToTree = nullptr;

  public:
    NodeVec(Data&, ulong, BinaryTreeVec<Data>*);
    struct NodeVec& operator=(const NodeVec&); // Copy assignment of abstract types should not be possible.
    struct NodeVec& operator=(NodeVec&&) noexcept; // Move assignment of abstract types should not be possible.
    bool IsLeaf() const noexcept override; // (concrete function should not throw exceptions)
    bool HasLeftChild() const noexcept override; // (concrete function should not throw exceptions)
    bool HasRightChild() const noexcept override; // (concrete function should not throw exceptions)
    struct NodeVec& LeftChild() const override; // (concrete function must throw std::out_of_range when not existent)
    struct NodeVec& RightChild() const override; // (concrete function must throw std::out_of_range when not existent)

    friend class BinaryTreeVec<Data>;
  };

protected:

  using BinaryTree<Data>::size;
  Vector<struct BinaryTreeVec<Data>::NodeVec*> tree;

public:

  BinaryTreeVec() = default;
  BinaryTreeVec(const LinearContainer<Data>&); // A binary tree obtained from a LinearContainer
  BinaryTreeVec(const BinaryTreeVec<Data>&);
  BinaryTreeVec(BinaryTreeVec<Data>&&) noexcept;

  virtual ~BinaryTreeVec();

  BinaryTreeVec& operator=(const BinaryTreeVec<Data>&);
  BinaryTreeVec& operator=(BinaryTreeVec<Data>&&) noexcept;

  bool operator==(const BinaryTreeVec&) const noexcept;
  bool operator!=(const BinaryTreeVec&) const noexcept;

  // Specific member functions (inherited from BinaryTree)

  NodeVec& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

  /* ----- override of map and fold in breadth ----- */

  using typename BinaryTree<Data>::MapFunctor;
  using typename BinaryTree<Data>::FoldFunctor;
  void MapBreadth(const MapFunctor, void*) override;
  void FoldBreadth(const FoldFunctor, const void*, void*) const override;

};

}

#include "binarytreevec.cpp"

#endif
