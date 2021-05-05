#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

#include "../binarytree.hpp"

namespace lasd {

template <typename Data>
class BinaryTreeLnk : virtual public BinaryTree<Data>{ // Must extend BinaryTree<Data>

protected:

  struct NodeLnk : virtual protected BinaryTree<Data>::Node { // Must extend Node

  protected:

    using BinaryTree<Data>::Node::data;
    struct NodeLnk* left;
    struct NodeLnk* right;

  public:
    struct NodeLnk& operator=(const NodeLnk&); // Copy assignment of abstract types should not be possible.
    struct NodeLnk& operator=(NodeLnk&&) noexcept; // Move assignment of abstract types should not be possible.
    bool IsLeaf() const noexcept override; // (concrete function should not throw exceptions)
    bool HasLeftChild() const noexcept override; // (concrete function should not throw exceptions)
    bool HasRightChild() const noexcept override; // (concrete function should not throw exceptions)

    struct BinaryTree<Data>::Node& LeftChild() const override; // (concrete function must throw std::out_of_range when not existent)
    struct BinaryTree<Data>::Node& RightChild() const override; // (concrete function must throw std::out_of_range when not existent)

    friend class BinaryTreeLnk<Data>;

  };

protected:
    using BinaryTree<Data>::size;

    struct BinaryTreeLnk<Data>::NodeLnk* root = nullptr;
    struct BinaryTreeLnk<Data>::NodeLnk* CreateNode(const Data& data);

public:

  // Default constructor
  BinaryTreeLnk() = default;
  BinaryTreeLnk(const LinearContainer<Data>&); // A binary tree obtained from a LinearContainer
  BinaryTreeLnk(const BinaryTreeLnk<Data>&);
  BinaryTreeLnk(BinaryTreeLnk<Data>&&) noexcept;

  virtual ~BinaryTreeLnk();

  BinaryTreeLnk& operator=(const BinaryTreeLnk<Data>&);
  BinaryTreeLnk& operator=(BinaryTreeLnk<Data>&&) noexcept;

  bool operator==(const BinaryTreeLnk<Data>&) const noexcept;
  bool operator!=(const BinaryTreeLnk<Data>&) const noexcept;

  // Specific member functions (inherited from BinaryTree)

  struct BinaryTree<Data>::Node& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

  // Specific functions
  
  struct BinaryTreeLnk<Data>::NodeLnk* CreateTreeFromLinearContainerInBreadth(const LinearContainer<Data>&,ulong);
  struct BinaryTreeLnk<Data>::NodeLnk* CopyTree(struct BinaryTreeLnk<Data>::Node*);
  void DeleteTree(BinaryTreeLnk<Data>::NodeLnk* node);
};

}

#include "binarytreelnk.cpp"

#endif
