
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk : virtual protected BinaryTree<Data>{ // Must extend BinaryTree<Data>

private:

protected:

  using BinaryTree<Data>::size;
  struct NodeLnk* root = nullptr;

  // Node
  struct NodeLnk : virtual protected BinaryTree<Data>::Node { // Must extend Node

  private:

  protected:

    using BinaryTree<Data>::Node::data;
    struct NodeLnk* left;
    struct* NodeLnk* right;

  public:
    NodeLnk& operator=(const NodeLnk&); // Copy assignment of abstract types should not be possible.

    // Move assignment
    Node& operator=(Node&&) noexcept override; // Move assignment of abstract types should not be possible.
    bool IsLeaf() const noexcept override; // (concrete function should not throw exceptions)
    bool HasLeftChild() const noexcept override; // (concrete function should not throw exceptions)
    bool HasRightChild() const noexcept override; // (concrete function should not throw exceptions)

    Node& LeftChild() const override; // (concrete function must throw std::out_of_range when not existent)
    Node& RightChild() const override; // (concrete function must throw std::out_of_range when not existent)

    struct BinaryTreeLnk<Data>::NodeLnk* CreateNode(const Data& data);

  };

public:

  // Default constructor
  BinaryTreeLnk();

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeLnk(const LinearContainer<Data>&); // A binary tree obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeLnk(const BinaryTreeLnk<Data>&);

  // Move constructor
  BinaryTreeLnk(BinaryTreeLnk<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTreeLnk();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeLnk<Data>& operator=(const BinaryTreeLnk<Data>&);

  // Move assignment
  BinaryTreeLnk<Data> operator=(BinaryTreeLnk<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTreeLnk<Data>&) const noexcept;
  bool operator!=(const BinaryTreeLnk<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  struct NodeLnk& Root() override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

  struct BinaryTreeLnk<Data>::NodeLnk* CreateTreeFromLinearContainerInBreadth(const LinearContainer<Data>&,ulong);
  struct BinaryTreeLnk<Data>::NodeLnk* CopyTree(struct BinaryTreeLnk<Data>::NodeLnk*);
  void DeleteTree(BinaryTreeLnk<Data>::NodeLnk* node)
};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
