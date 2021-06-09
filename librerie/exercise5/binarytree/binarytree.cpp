
#include "../queue/queue.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../stack/stack.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../stack/vec/stackvec.hpp"
#include<iostream>

namespace lasd {

/* ----- begin of class BinaryTree ----- */

/* ----- begin of struct Node ----- */

template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& toEvaluate) const noexcept{
  return EqualNodes(*this, toEvaluate);
}

template <typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& toEvaluate) const noexcept{
  return !(*this == toEvaluate);
}

/* given two nodes, checks if the subtree is the same */
template <typename Data>
bool BinaryTree<Data>::Node::EqualNodes(const Node& n1, const Node& n2) const{
  if(n1.data == n2.data){

    if( (n1.HasLeftChild() && !n2.HasLeftChild()) || (n1.HasRightChild() && !n2.HasRightChild()) ) return false;

    if(n1.HasLeftChild() && n1.HasRightChild()){
      return( EqualNodes(n1.LeftChild(),n2.LeftChild()) && EqualNodes(n1.RightChild(),n2.RightChild()));
    }
    else if(n1.HasLeftChild() && !n1.HasRightChild()){
      return( EqualNodes(n1.LeftChild(),n2.LeftChild()));
    }
    else if(!n1.HasLeftChild() && n1.HasRightChild()){
      return( EqualNodes(n1.RightChild(),n2.RightChild()));
    }
    else{ //if leaf
      return true;
    }

  }else{
    return false;
  }
}

template <typename Data>
Data& BinaryTree<Data>::Node::Element(){
  return this->data;
}

template <typename Data>
const Data& BinaryTree<Data>::Node::Element() const{
  return this->data;
}

/* ----- end of struct Node ----- */

template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree& tree) const noexcept{
  if(size == tree.size){
    if(size == 0) return true;
    else return (Root() == tree.Root());
  }else{
    return false;
  }
}

template <typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree& toCompare) const noexcept{
  return !(*this == toCompare);
}

/* ----- Map and fold functions ----- */

template <typename Data>
void BinaryTree<Data>::MapPreOrder(const typename MappableContainer<Data>::MapFunctor function, void* par){
  if(size == 0) return;
  MapPreOrder(function, par, &Root());
}

template <typename Data>
void BinaryTree<Data>::MapPostOrder(const typename MappableContainer<Data>::MapFunctor function, void* par){
  if(size == 0) return;
  MapPostOrder(function, par, &Root());
}

template <typename Data>
void BinaryTree<Data>::MapInOrder(const typename MappableContainer<Data>::MapFunctor function, void* par){
  if(size == 0) return;
  MapInOrder(function, par, &Root());
}

template <typename Data>
void BinaryTree<Data>::MapBreadth(const typename MappableContainer<Data>::MapFunctor function, void* par){
  if(size == 0) return;
  MapBreadth(function, par, &Root());
}

template <typename Data>
void BinaryTree<Data>::FoldPreOrder(const typename FoldableContainer<Data>::FoldFunctor function, const void* par, void* acc) const{
  if(size == 0) return;
  FoldPreOrder(function, par, acc, &Root());
}

template <typename Data>
void BinaryTree<Data>::FoldPostOrder(const typename FoldableContainer<Data>::FoldFunctor function, const void* par, void* acc) const{
  if(size == 0) return;
  FoldPostOrder(function, par, acc, &Root());
}

template <typename Data>
void BinaryTree<Data>::FoldInOrder(const typename FoldableContainer<Data>::FoldFunctor function, const void* par, void* acc) const{
  if(size == 0) return;
  FoldInOrder(function, par, acc, &Root());
}

template <typename Data>
void BinaryTree<Data>::FoldBreadth(const typename FoldableContainer<Data>::FoldFunctor function, const void* par, void* acc) const{
  if(size == 0) return;
  FoldBreadth(function, par, acc, &Root());
}

/* ----- Auxiliary map and fold functions ----- */

template <typename Data>
void BinaryTree<Data>::MapPreOrder(const typename MappableContainer<Data>::MapFunctor function, void* par, Node* node){
  if(node != nullptr){
      function(node->Element(), par);
      if(node->HasLeftChild()){
          MapPreOrder(function, par, &(node->LeftChild()));
      }
      if(node->HasRightChild()){
          MapPreOrder(function, par, &(node->RightChild()));
      }
  }
}

template <typename Data>
void BinaryTree<Data>::MapPostOrder(const typename MappableContainer<Data>::MapFunctor function, void* par, Node* node){
  if(node != nullptr){
    if(node->HasLeftChild()){
        MapPostOrder(function, par, &(node->LeftChild()));
    }
    if(node->HasRightChild()){
        MapPostOrder(function, par, &(node->RightChild()));
    }
    function(node->Element(), par);
  }
}

template <typename Data>
void BinaryTree<Data>::MapInOrder(const typename MappableContainer<Data>::MapFunctor function, void* par, Node* node){
  if(node != nullptr){
    if(node->HasLeftChild()){
      MapInOrder(function, par, &(node->LeftChild()));
    }
    function(node->Element(), par);
    if(node->HasRightChild()){
      MapInOrder(function, par, &(node->RightChild()));
    }
  }
}

template <typename Data>
void BinaryTree<Data>::MapBreadth(const typename MappableContainer<Data>::MapFunctor function, void* par, Node* node){
  QueueLst<struct Node*> toVisit;
  if(node != nullptr){
    toVisit.Enqueue(node);
    while(!toVisit.Empty()){
      function(toVisit.Head()->Element(), par);

      if(toVisit.Head()->HasLeftChild()){
        toVisit.Enqueue(&(toVisit.Head()->LeftChild()));
      }
      if(toVisit.Head()->HasRightChild()){
        toVisit.Enqueue(&(toVisit.Head()->RightChild()));
      }
      toVisit.Dequeue();
    }
  }
}

template <typename Data>
void BinaryTree<Data>::FoldPreOrder(const typename FoldableContainer<Data>::FoldFunctor function, const void* par, void* acc, const Node* node) const{
  if(node != nullptr){
        function(node->Element(), par, acc);
        if(node->HasLeftChild()){
            FoldPreOrder(function, par, acc, &(node->LeftChild()));
        }
        if(node->HasRightChild()){
            FoldPreOrder(function, par, acc, &(node->RightChild()));
        }
  }
}

template <typename Data>
void BinaryTree<Data>::FoldPostOrder(const typename FoldableContainer<Data>::FoldFunctor function, const void* par, void* acc, const Node* node) const{
  if(node != nullptr){
    if(node->HasLeftChild()){
      FoldPostOrder(function, par, acc, &(node->LeftChild()));
    }
    if(node->HasRightChild()){
      FoldPostOrder(function, par, acc, &(node->RightChild()));
    }
    function(node->Element(), par, acc);
  }
}

template <typename Data>
void BinaryTree<Data>::FoldInOrder(const typename FoldableContainer<Data>::FoldFunctor function, const void* par, void* acc, const Node* node) const{
  if(node != nullptr){
    if(node->HasLeftChild()){
      FoldInOrder(function, par, acc, &(node->LeftChild()));
    }
    function(node->Element(), par, acc);
    if(node->HasRightChild()){
        FoldInOrder(function, par, acc, &(node->RightChild()));
    }
  }
}

template <typename Data>
void BinaryTree<Data>::FoldBreadth(const typename FoldableContainer<Data>::FoldFunctor function, const void* par, void* acc, Node* node) const{
  QueueLst<BinaryTree<Data>::Node*> toVisit;
  if(node != nullptr){
    toVisit.Enqueue(node);
    while(!toVisit.Empty()){
      function(toVisit.Head()->Element(), par, acc);

      if(toVisit.Head()->HasLeftChild()){
        toVisit.Enqueue(&(toVisit.Head()->LeftChild()));
      }
      if(toVisit.Head()->HasRightChild()){
        toVisit.Enqueue(&(toVisit.Head()->RightChild()));
      }
      toVisit.Dequeue();
    }
  }
}

/* ----- end of class BinaryTree ----- */

/* ----- begin of class BTPreOrderIterator ----- */

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& tree){
  if(tree.Size() > 0)
    curr = &tree.Root();
  else
    curr = nullptr;
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator& itr){
  curr = itr.curr;
  stack = itr.stack;
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator&& itr) noexcept{
  std::swap(curr, itr.curr);
  std::swap(stack, itr.stack);
}

template <typename Data>
BTPreOrderIterator<Data>::~BTPreOrderIterator(){
  stack.Clear();
  curr = nullptr;
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator& itr){
  curr = itr.curr;
  stack = itr.stack;
  return *this;
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator&& itr) noexcept{
  std::swap(curr, itr.curr);
  std::swap(stack, itr.stack);
  return *this;
}

template <typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator& itr) const noexcept{
  return ( curr==itr.curr && stack==itr.stack );
}

template <typename Data>
bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator& itr) const noexcept{
  return !(*this == itr);
}

template <typename Data>
Data& BTPreOrderIterator<Data>::operator*() const{
  if(Terminated()) throw std::out_of_range("Iterator is terminated!");
  return curr->Element();
}

template <typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept{
  return (curr==nullptr);
}

template <typename Data>
void BTPreOrderIterator<Data>::operator++(){
  if(Terminated()) throw std::out_of_range("Iterator is terminated!");

  if(curr->HasLeftChild()){

    if( curr->HasRightChild() ){
      stack.Push(&(curr->RightChild()));
    }

    curr = &(curr->LeftChild());

  }else if(curr->HasRightChild()){
    curr = &curr->RightChild();
  }
  else{ // is leaf
    if(stack.Empty()){
      curr = nullptr;
    }else{
      curr = stack.TopNPop();
    }
  }
}

/* ----- end of class BTPreOrderIterator ----- */

/* ----- begin of class BTPostOrderIterator ----- */

template <typename Data>
struct BinaryTree<Data>::Node* BTPostOrderIterator<Data>::DeepestLeftLeaf(struct BinaryTree<Data>::Node* node){
  if(node->HasLeftChild()){
    stack.Push(node);
    return DeepestLeftLeaf(&(node->LeftChild()));
  }
  else if(node->HasRightChild()){
    stack.Push(node);
    return DeepestLeftLeaf(&(node->RightChild()));
  }
  else
    return node;
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& tree){
  if(tree.Size() > 0)
    curr = DeepestLeftLeaf(&tree.Root());
  else
    curr = nullptr;
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator& itr){
  curr = itr.curr;
  stack = itr.stack;
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator&& itr) noexcept{
  std::swap(curr, itr.curr);
  std::swap(stack, itr.stack);
}

template <typename Data>
BTPostOrderIterator<Data>::~BTPostOrderIterator(){
  curr = nullptr;
  stack.Clear();
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator& itr){
  curr = itr.curr;
  stack = itr.stack;
  return *this;
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator&& itr) noexcept{
  std::swap(curr, itr.curr);
  std::swap(stack, itr.stack);
  return *this;
}

template <typename Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator& itr) const noexcept{
  return (curr == itr.curr && stack == itr.stack );
}

template <typename Data>
bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator& itr) const noexcept{
  return !(*this == itr);
}

template <typename Data>
Data& BTPostOrderIterator<Data>::operator*() const{
  if(Terminated()) throw std::out_of_range("Iterator is terminated!");
  return curr->Element();
}

template <typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept{
  return (curr == nullptr);
}

template <typename Data>
void BTPostOrderIterator<Data>::operator++(){
  /*
  * If we're coming from the left then we have to analyze the tree on the right
  * (if existent). Otherwise we just top 'n' pop.
  */

  if(Terminated()) throw std::out_of_range("Iterator is terminated!");

  if(stack.Empty()){
    curr = nullptr;
  }else{
    if((stack.Top())->HasLeftChild() && curr == &((stack.Top())->LeftChild()) ){
      if( (stack.Top())->HasRightChild()   ){
        curr = DeepestLeftLeaf(&((stack.Top())->RightChild()));
      }else{
        curr = stack.TopNPop();
      }
    }else{
      curr = stack.TopNPop();
    }
  }
}

/* ----- end of class BTPostOrderIterator ----- */

/* ----- begin of class BTInOrderIterator ----- */

template <typename Data>
struct BinaryTree<Data>::Node* BTInOrderIterator<Data>::MostLeftNode(struct BinaryTree<Data>::Node& root){
  if(root.HasLeftChild()){
    stack.Push(&root);
    return MostLeftNode(root.LeftChild());
  }else{
    return &root;
  }
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& tree){
  if(tree.Size() > 0)
    curr = MostLeftNode(tree.Root());
  else
    curr = nullptr;
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator& itr){
  curr = itr.curr;
  stack = itr.stack;
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator&& toMove) noexcept{
  std::swap(curr, toMove.curr);
  std::swap(stack, toMove.stack);
}

template <typename Data>
BTInOrderIterator<Data>::~BTInOrderIterator(){
   stack.Clear();
   curr = nullptr;
 }

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator& itr){
  curr = itr.curr;
  stack = itr.stack;
  return *this;
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator&& toMove) noexcept{
  std::swap(curr, toMove.curr);
  std::swap(stack, toMove.stack);
  return *this;
}

template <typename Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator& itr) const noexcept{
  return (curr == itr.curr && stack == itr.stack );
}

template <typename Data>
bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator& itr) const noexcept{
  return !(*this == itr);
}

template <typename Data>
Data& BTInOrderIterator<Data>::operator*() const{
  if(Terminated()) throw std::out_of_range("Iterator is terminated!");
  return curr->Element();
}

template <typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept{
  return (curr == nullptr);
}

template <typename Data>
void BTInOrderIterator<Data>::operator++(){
  if(Terminated()) throw std::out_of_range("Iterator is terminated!");

  if(curr->HasRightChild()){
    curr = MostLeftNode(curr->RightChild());
  }else{
    if(stack.Empty()){
      curr = nullptr;
    }else{
      curr = stack.TopNPop();
    }
  }
}

/* ----- end of class BTInOrderIterator ----- */

/* ----- begin of class BTBreadthIteratorOrderIterator ----- */

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& tree){
  if(tree.Size() > 0)
    curr = &(tree.Root());
  else
    curr = nullptr;
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator& itr){
  curr = itr.curr;
  queue = itr.queue;
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator&& itr) noexcept{
  std::swap(curr, itr.curr);
  std::swap(queue, itr.queue);
}

template <typename Data>
BTBreadthIterator<Data>::~BTBreadthIterator(){
  curr = nullptr;
  queue.Clear();
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator& itr){
  curr = itr.curr;
  queue = itr.queue;
  return *this;
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator&& itr) noexcept{
  std::swap(curr, itr.curr);
  std::swap(queue, itr.queue);
  return *this;
}

template <typename Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator& itr) const noexcept{
  return ( curr==itr.curr && queue==itr.queue );
}

template <typename Data>
bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator& itr) const noexcept{
  return !(*this == itr);
}

template <typename Data>
Data& BTBreadthIterator<Data>::operator*() const{
  if(Terminated()) throw std::out_of_range("Iterator is terminated!");
  return curr->Element();
}

template <typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept{
  return curr == nullptr;
}

template <typename Data>
void BTBreadthIterator<Data>::operator++(){
  if(Terminated()) throw std::out_of_range("Iterator is terminated!");

  if(curr->HasLeftChild()){
    queue.Enqueue(&(curr->LeftChild()));
  }
  if(curr->HasRightChild()){
    queue.Enqueue(&(curr->RightChild()));
  }
  if(!queue.Empty()){
    curr = queue.HeadNDequeue();
  }else{
    curr = nullptr;
  }
}

/* ************************************************************************** */

}
