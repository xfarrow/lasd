
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

  struct NodeLnk : virtual protected BinaryTree<Data>::Node { // Must extend Node

  private:

  protected:

    using BinaryTree<Data>::Node::data;
    struct NodeLnk* left;
    struct* NodeLnk* right;

  public:

    NodeLnk& operator=(const Node&); // Copy assignment of abstract types should not be possible.

    // Move assignment
    NodeLnk& operator=(Node&&) noexcept override; // Move assignment of abstract types should not be possible.
    bool IsLeaf() const noexcept override; // (concrete function should not throw exceptions)
    bool HasLeftChild() const noexcept override; // (concrete function should not throw exceptions)
    bool HasRightChild() const noexcept override; // (concrete function should not throw exceptions)

    Node& LeftChild() const override; // (concrete function must throw std::out_of_range when not existent)
    Node& RightChild() const override; // (concrete function must throw std::out_of_range when not existent)

  };

public:

  // Default constructor
  BinaryTreeLnk();

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeLnk(argument) specifiers; // A binary tree obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeLnk(argument) specifiers;

  // Move constructor
  // BinaryTreeLnk(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeLnk() specifiers;

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

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Clear() specifiers; // Override Container member

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
