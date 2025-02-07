
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include "../container/container.hpp"

#include "../iterator/iterator.hpp"

#include "../queue/queue.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"

#include "../stack/stack.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../stack/vec/stackvec.hpp"

namespace lasd {

template <typename Data>
class BinaryTree :  virtual public InOrderMappableContainer<Data>,
                    virtual public BreadthMappableContainer<Data>,
                    virtual public InOrderFoldableContainer<Data>,
                    virtual public BreadthFoldableContainer<Data>{ // Must extend InOrder/BreadthMappableContainer<Data> and InOrder/BreadthFoldableContainer<Data>

public:

  struct Node {

  private:

  protected:
    Data data;
    // Comparison operators
    bool operator==(const Node&) const noexcept; // Comparison of abstract types is possible, but should not be visible.
    bool operator!=(const Node&) const noexcept; // Comparison of abstract types is possible, but should not be visible.

    bool EqualNodes(const Node&, const Node&) const;

  public:

    friend class BinaryTree<Data>;

    // Destructor
    virtual ~Node() = default;

    // Copy assignment
    Node& operator=(const Node&) = delete; // Copy assignment of abstract types should not be possible.

    // Move assignment
    Node& operator=(Node&&) noexcept = delete; // Move assignment of abstract types should not be possible.

    // Specific member functions
    Data& Element(); // Mutable access to the element (concrete function should not throw exceptions)
    const Data& Element() const; // Immutable access to the element (concrete function should not throw exceptions)

    virtual bool IsLeaf() const noexcept = 0; // (concrete function should not throw exceptions)
    virtual bool HasLeftChild() const noexcept = 0; // (concrete function should not throw exceptions)
    virtual bool HasRightChild() const noexcept = 0; // (concrete function should not throw exceptions)

    virtual Node& LeftChild() const = 0; // (concrete function must throw std::out_of_range when not existent)
    virtual Node& RightChild() const = 0; // (concrete function must throw std::out_of_range when not existent)

  };

  virtual ~BinaryTree() = default;

  BinaryTree& operator=(const BinaryTree&) = delete; // Copy assignment of abstract types should not be possible.
  BinaryTree& operator=(BinaryTree&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  bool operator==(const BinaryTree&) const noexcept; // Comparison of abstract binary tree is possible.
  bool operator!=(const BinaryTree&) const noexcept; // Comparison of abstract binary tree is possible.

  virtual Node& Root() const = 0; // (concrete function must throw std::length_error when empty)

  /* ----- Map and fold functions ----- */

  virtual void MapPreOrder(const typename MappableContainer<Data>::MapFunctor, void*) override; // Override MappableContainer member
  virtual void MapPostOrder(const typename MappableContainer<Data>::MapFunctor, void*) override; // Override MappableContainer member
  virtual void MapInOrder(const typename MappableContainer<Data>::MapFunctor, void*) override; // Override InOrderMappableContainer member
  virtual void MapBreadth(const typename MappableContainer<Data>::MapFunctor, void*) override; // Override BreadthMappableContainer member

  virtual void FoldPreOrder(const typename FoldableContainer<Data>::FoldFunctor, const void*, void*) const override; // Override FoldableContainer member
  virtual void FoldPostOrder(const typename FoldableContainer<Data>::FoldFunctor, const void*, void*) const override; // Override FoldableContainer member
  virtual void FoldInOrder(const typename FoldableContainer<Data>::FoldFunctor, const void*, void*) const override; // Override InOrderFoldableContainer member
  virtual void FoldBreadth(const typename FoldableContainer<Data>::FoldFunctor, const void*, void*) const override; // Override BreadthFoldableContainer member

protected:

  using BreadthMappableContainer<Data>::size;

  /* ----- Auxiliary map and fold functions ----- */

  void MapPreOrder(const typename MappableContainer<Data>::MapFunctor, void*, Node*); // Accessory function executing from one node of the tree
  void MapPostOrder(const typename MappableContainer<Data>::MapFunctor, void*, Node*); // Accessory function executing from one node of the tree
  void MapInOrder(const typename MappableContainer<Data>::MapFunctor, void*, Node*); // Accessory function executing from one node of the tree
  void MapBreadth(const typename MappableContainer<Data>::MapFunctor, void*, Node*); // Accessory function executing from one node of the tree

  void FoldPreOrder(const typename FoldableContainer<Data>::FoldFunctor, const void*, void*, const Node*) const; // Accessory function executing from one node of the tree
  void FoldPostOrder(const typename FoldableContainer<Data>::FoldFunctor, const void*, void*, const Node*) const; // Accessory function executing from one node of the tree
  void FoldInOrder(const typename FoldableContainer<Data>::FoldFunctor, const void*, void*, const Node*) const; // Accessory function executing from one node of the tree
  void FoldBreadth(const typename FoldableContainer<Data>::FoldFunctor, const void*, void*, Node*) const; // Accessory function executing from one node of the tree
};


template <typename Data>
class BTPreOrderIterator : virtual public ForwardIterator<Data> { // Must extend ForwardIterator<Data>

protected:

  struct BinaryTree<Data>::Node* curr = nullptr;
  StackLst<struct BinaryTree<Data>::Node*> stack;

public:

  virtual ~BTPreOrderIterator();

  BTPreOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree
  BTPreOrderIterator(const BTPreOrderIterator&);
  BTPreOrderIterator(BTPreOrderIterator&&) noexcept;

  BTPreOrderIterator& operator=(const BTPreOrderIterator&);
  BTPreOrderIterator& operator=(BTPreOrderIterator&&) noexcept;

  bool operator==(const BTPreOrderIterator&) const noexcept;
  bool operator!=(const BTPreOrderIterator&) const noexcept;

  // Specific member functions (inherited from Iterator)

  Data& operator*() const; // (throw std::out_of_range when terminated)
  bool Terminated() const noexcept; // (should not throw exceptions)

  // Specific member functions (inherited from ForwardIterator)

  void operator++(); // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator : virtual public ForwardIterator<Data>  { // Must extend ForwardIterator<Data>

protected:

  struct BinaryTree<Data>::Node* curr = nullptr;
  StackLst<struct BinaryTree<Data>::Node*> stack;

  struct BinaryTree<Data>::Node* DeepestLeftLeaf(struct BinaryTree<Data>::Node*);

public:

  BTPostOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree
  BTPostOrderIterator(const BTPostOrderIterator&);
  BTPostOrderIterator(BTPostOrderIterator&&) noexcept;

  virtual ~BTPostOrderIterator();


  BTPostOrderIterator& operator=(const BTPostOrderIterator&);
  BTPostOrderIterator& operator=(BTPostOrderIterator&&) noexcept;

  bool operator==(const BTPostOrderIterator&) const noexcept;
  bool operator!=(const BTPostOrderIterator&) const noexcept;

  // Specific member functions (inherited from Iterator)

  Data& operator*() const; // (throw std::out_of_range when terminated)
  bool Terminated() const noexcept; // (should not throw exceptions)

  // Specific member functions (inherited from ForwardIterator)

  void operator++(); // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator : virtual public ForwardIterator<Data> { // Must extend ForwardIterator<Data>

protected:

  struct BinaryTree<Data>::Node* curr = nullptr;
  StackLst<struct BinaryTree<Data>::Node*> stack;

  struct BinaryTree<Data>::Node* MostLeftNode(struct BinaryTree<Data>::Node&);

public:

  BTInOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree
  BTInOrderIterator(const BTInOrderIterator&);
  BTInOrderIterator(BTInOrderIterator&&) noexcept;

  virtual ~BTInOrderIterator();

  BTInOrderIterator& operator=(const BTInOrderIterator&);
  BTInOrderIterator& operator=(BTInOrderIterator&&) noexcept;

  bool operator==(const BTInOrderIterator&) const noexcept;
  bool operator!=(const BTInOrderIterator&) const noexcept;

  // Specific member functions (inherited from Iterator)

  Data& operator*() const; // (throw std::out_of_range when terminated)
  bool Terminated() const noexcept; // (should not throw exceptions)

  // Specific member functions (inherited from ForwardIterator)

  void operator++(); // (throw std::out_of_range when terminated)

};

template <typename Data>
class BTBreadthIterator : virtual public ForwardIterator<Data>{ // Must extend ForwardIterator<Data>

protected:

  struct BinaryTree<Data>::Node* curr = nullptr;
  QueueVec<struct BinaryTree<Data>::Node*> queue;

public:

  BTBreadthIterator(const BinaryTree<Data>&); // An iterator over a given binary tree
  BTBreadthIterator(const BTBreadthIterator&);
  BTBreadthIterator(BTBreadthIterator&&) noexcept;

  virtual ~BTBreadthIterator();

  BTBreadthIterator& operator=(const BTBreadthIterator&);
  BTBreadthIterator& operator=(BTBreadthIterator&&) noexcept;

  bool operator==(const BTBreadthIterator&) const noexcept;
  bool operator!=(const BTBreadthIterator&) const noexcept;

  // Specific member functions (inherited from Iterator)

  Data& operator*() const; // (throw std::out_of_range when terminated)
  bool Terminated() const noexcept; // (should not throw exceptions)

  // Specific member functions (inherited from ForwardIterator)

  void operator++(); // (throw std::out_of_range when terminated)

};

}

#include "binarytree.cpp"

#endif
