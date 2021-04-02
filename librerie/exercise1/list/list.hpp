
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List :  virtual public LinearContainer<Data>,
              virtual public MappableContainer<Data>,
              virtual public FoldableContainer<Data>  { // Must extend LinearContainer<Data>, MappableContainer<Data>, and FoldableContainer<Data>

private:

protected:

  using LinearContainer<Data>::size;

  struct Node
  {
    Data value;
    Node* next = nullptr;

    /* ********************************************************************** */

    // Specific constructors
    Node(Data);

    /* ********************************************************************** */

    // Copy constructor
    Node(const Node&);
    Node(const Data&);

    // Move constructor
    Node(Node&&);
    Node(Data&&);

    /* ********************************************************************** */

    // Destructor
    ~Node() = default;

    /* ********************************************************************** */

    // Comparison operators
    bool operator==(const Node&) const noexcept;
    bool operator!=(const Node&) const noexcept;
  };

  struct Node* head = nullptr;
  struct Node* tail = nullptr;

public:

  // Default constructor
  List() = default;

  /* ************************************************************************ */

  // Specific constructor
  List(const LinearContainer&); // A list obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  List(const List&);

  //Move constructor
  List(List&&);

  /* ************************************************************************ */

  // Destructor
  ~List();

  /* ************************************************************************ */

  // Copy assignment
  List& operator=(const List&);

  // Move assignment
  List& operator=(List&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const List&) const noexcept;
  bool operator!=(const List&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  void InsertAtFront(const Data&); // Copy of the value
  void InsertAtFront(Data&&); // Move of the value
  void RemoveFromFront(); // (must throw std::length_error when empty)
  Data FrontNRemove(); // (must throw std::length_error when empty)

  void InsertAtBack(const Data&); // Copy of the value
  void InsertAtBack(Data&&); // Move of the value

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  Data& Front() override const; // Override LinearContainer member (must throw std::length_error when empty)
  Data& Back() override const; // Override LinearContainer member (must throw std::length_error when empty)

  Data& operator[](const ulong) const override; // Override LinearContainer member (must throw std::out_of_range when out of range)

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFunctor;

  void MapPreOrder(const MapFunctor, void*) override; // Override MappableContainer member
  void MapPostOrder(const MapFunctor, void*) override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  void FoldPreOrder(const FoldFunctor, const void*, void*) const override; // Override FoldableContainer member
  void FoldPostOrder(const FoldFunctor, const void*, void*) const override; // Override FoldableContainer member

protected:

  // Auxiliary member functions (for MappableContainer)

  void MapPreOrder(const MapFunctor, void*, struct Node*); // Accessory function executing from one point of the list onwards
  void MapPostOrder(const MapFunctor, void*, struct Node*); // Accessory function executing from one point of the list onwards

  /* ************************************************************************ */

  // Auxiliary member functions (for FoldableContainer)

  void FoldPreOrder(const FoldFunctor, const void*, void*, struct Node*) const; // Accessory function executing from one point of the list onwards
  void FoldPostOrder(const FoldFunctor, const void*, void*, struct Node*) const; // Accessory function executing from one point of the list onwards

};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
