
#include "../queue/queue.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"

#include "../stack/stack.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../stack/vec/stackvec.hpp"

namespace lasd {

/* ************************************************************************** */

// checks if two trees which have the same root node are identical
template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& toEvaluate){
  return EqualNodes(this, &toEvaluate);
}

/* given two nodes, checks if the subtree is the same */
bool BinaryTree<Data>::Node::EqualNodes(Node* n1, Node* n2){
  if(n1->data == n2->data){
    if(n1->IsLeaf() && n2->IsLeaf()) return true;
    if( (n1->HasLeftChild() && !n2->HasLeftChild()) || (n1->HasRightChild() && !n2->HasRightChild()) ) return false;
    return( EqualNodes(n1->LeftChild(),n2->LeftChild()) &&
            EqualNodes(n1->RightChild(),n2->RightChild())
          )
  }else{
    return false;
  }
}

template <typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& toEvaluate){
  return !(*this == toEvaluate)
}

template <typename Data>
Data& BinaryTree<Data>::Node::Element(){
  return this->data;
}

template <typename Data>
const Data& BinaryTree<Data>::Node::Element(){
  return this->data;
}

template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree& toCompare) const noexcept{
  return(Root() == toCompare.Root());
}

template <typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree& toCompare) const noexcept{
  return(Root() != toCompare.Root());
}

/* ----- Map and fold functions ----- */

template <typename Data>
void BinaryTree<Data>::MapPreOrder(const MapFunctor function, void* par){
  MapPreOrder(function, par, &Root());
}

template <typename Data>
void BinaryTree<Data>::MapPostOrder(const MapFunctor function, void* par){
  MapPostOrder(function, par, &Root());
}

template <typename Data>
void BinaryTree<Data>::MapInOrder(const MapFunctor function, void* par){
  MapInOrder(function, par, &Root());
}

template <typename Data>
void BinaryTree<Data>::MapBreadth(const MapFunctor function, void* par){
  MapBreadth(function, par, &Root());
}

template <typename Data>
void BinaryTree<Data>::FoldPreOrder(const FoldFunctor function, const void* par, void* acc){
  FoldPreOrder(function, par, acc, &Root());
}

template <typename Data>
void BinaryTree<Data>::FoldPostOrder(const FoldFunctor function, const void* par, void* acc) const{
  FoldPostOrder(function, par, acc, &Root());
}

template <typename Data>
void BinaryTree<Data>::FoldInOrder(const MapFunctor function, const void* par, void* acc) const{
  FoldInOrder(function, par, acc, &Root());
}

template <typename Data>
void BinaryTree<Data>::FoldBreadth(const FoldFunctor function, const void* par, void* acc) const{
  FoldBreadth(function, par, acc, &Root());
}

/* ----- Auxiliary map and fold functions ----- */

template <typename Data>
void BinaryTree<Data>::MapPreOrder(const MapFunctor function, void* par, Node* node){
  if(node != nullptr){
      function(node->Element(), par);
      if(node->HasLeftChild()){
          MapPreOrder(function, par, node->LeftChild());
      }
      if(node->HasRightChild()){
          MapPreOrder(function, par, node->RightChild());
      }
  }
}

template <typename Data>
void BinaryTree<Data>::MapPostOrder(const MapFunctor function, void* par, Node* node){
  if(node != nullptr){
    if(node->HasLeftChild()){
        MapPreOrder(function, par, node->LeftChild());
    }
    if(node->HasRightChild()){
        MapPreOrder(function, par, node->RightChild());
    }
    function(node->Element(), par);
  }
}

template <typename Data>
void BinaryTree<Data>::FoldPreOrder(const FoldFunctor function, const void* par, void* acc, const Node* node){
  if(node != nullptr){
        function(node->Element(), par, acc);
        if(node->HasLeftChild()){
            FoldPreOrder(function, par, acc, node->LeftChild());
        }
        if(node->HasRightChild()){
            FoldPreOrder(function, par, acc, node->RightChild());
        }
  }
}

template <typename Data>
void BinaryTree<Data>::FoldPostOrder(const FoldFunctor function, const void* par, void* acc, const Node* node){
  if(node != nullptr){
    if(node->HasLeftChild()){
      FoldPreOrder(function, par, acc, node->LeftChild());
    }
    if(node->HasRightChild()){
      MapPreOrder(function, par, acc, node->RightChild());
    }
    function(node->Element(), par, acc);
  }
}

template <typename Data>
void BinaryTree<Data>::MapInOrder(const MapFunctor function, void* par, Node* node){
  if(node != nullptr){
    if(node->HasLeftChild()){
      MapInOrder(function, par, node->LeftChild());
    }
    function(node->Element(), par);
    if(node->HasRightChild()){
      MapInOrder(function, par, node->RightChild());
    }
  }
}

template <typename Data>
void FoldInOrder(const FoldFunctor function, const void* par, void* acc, const Node* node) const{
  if(node != nullptr){
    if(node->HasLeftChild()){
      FoldInOrder(function, par, acc, node->LeftChild());
    }
    function(node->Element(), par, acc);
    if(node->HasRightChild()){
        FoldPreOrder(function, par, acc, node->RightChild());
    }
  }
}

template <typename Data>
void BinaryTree<Data>::MapBreadth(const MapFunctor function, void* par, Node* node){
  QueueLst<struct Node*> toVisit;
  if(node != nullptr){
    toVisit.Enqueue(node);
    while(!toVisit.Empty()){
      func(toVisit.Head()->Element(), par);

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
void BinaryTree<Data>::FoldBreadth(const MapFunctor function, const void* par, void* acc,  const Node* node){
  QueueLst<struct Node*> toVisit;
  if(node != nullptr){
    toVisit.Enqueue(node);
    while(!toVisit.Empty()){
      func(toVisit.Head()->Element(), par, acc);

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
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& tree){
  curr = &tree.Root();
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator& itr){
  //curr = &(*itr);
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
BTPreOrderIterator& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator& itr){
  //curr = &(*itr);
  curr = itr.curr;
  stack = itr.stack;
  return *this;
}

template <typename Data>
BTPreOrderIterator& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator&& itr) noexcept{
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
struct BinaryTree<Data>::Node BTPreOrderIterator<Data>::operator*() const{
  return *curr;
}

template <typename Data>
bool BTPreOrderIterator<Data>::Terminated() noexcept{
  return curr==nullptr;
}

template <typename Data>
void BTPreOrderIterator<Data>::operator++(){
  if(Terminated()) throw std::out_of_range("Iterator is terminated!");

  if( (curr->HasLeftChild() ){
    curr = &(curr->LeftChild());

    if( (curr->HasRightChild() )
      stack.Push(&curr->RightChild());

  }else if( (curr->HasRightChild() ){
    curr = &curr->RightChild();
  }
  else{
    try{
      curr = &stack.TopNPop();
    }catch(std:: length_error exc){
      curr = nullptr;
    }
  }
}

template <typename Data>
struct BinaryTree<Data>::Node* BTPostOrderIterator<Data>::DeepestLeftLeaf(struct BinaryTree<Data>::Node* node){
  if(node->HasLeftChild()){
    stack.Push(node);
    MostLeftLeaf(node->LeftChild());
  }
  else if(node->HasRightChild()){
    stack.Push(node);
    MostLeftLeaf(node->RightChild());
  }
  else
    return node;
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& tree){
  curr = DeepestLeftLeaf(&tree.Root())
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
BTPostOrderIterator& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator& itr){
  curr = itr.curr;
  stack = itr.stack;
  return *this;
}

template <typename Data>
BTPostOrderIterator& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator&& itr){
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
struct BinaryTree<Data>::Node BTPostOrderIterator<Data>::operator*() const{
  return *curr;
}

template <typename Data>
bool BTPostOrderIterator<Data>::Terminated() noexcept{
  return (curr == nullptr)
}

template <typename Data>
void BTPostOrderIterator<Data>::operator++(){
  if(Terminated()) throw std::out_of_range("Iterator is terminated!");
  try{
    if(curr == &stack.Top().LeftChild()){
      if(stack.Top().HasRightChild()){
        curr = DeepestLeftLeaf(&stack.Top().RightChild());
      }else{
        curr = &stack.TopNPop();
      }
    }else{
      curr = &stack.TopNPop();
    }
  }catch(std::length_error exc){
    curr = nullptr;
  }
}

template <typename Data>
struct BinaryTree<Data>::Node* BTInOrdertOrderIterator<Data>::MostLeftNode(struct BinaryTree<Data>::Node* root){
  if(root->HasLeftChild()){
    stack.Push(root);
    MostLeftNode(root->LeftChild());
  }else{
    return root;
  }
}

template <typename Data>
BTInOrdertOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& tree){
  curr = MostLeftNode(tree.Root());
}

template <typename Data>
BTInOrdertOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator& itr){
  curr = itr.curr;
  stack = itr.stack;
}

template <typename Data>
BTInOrdertOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator&& toMove) noexcept{
  std::move(curr, toMove.curr);
  std::move(stack, toMove.stack);
}

template <typename Data>
 BTInOrdertOrderIterator<Data>::~BTInOrderIterator(){
   stack.Clear();
   curr = nullptr;
 }

template <typename Data>
BTInOrdertOrderIterator<Data>::BTInOrderIterator& operator=(const BTInOrderIterator& itr){
  curr = itr.curr;
  stack = itr.stack;
  return *this;
}

template <typename Data>
BTInOrdertOrderIterator<Data>::BTInOrderIterator& operator=(BTInOrderIterator&& itr){
  std::move(curr, toMove.curr);
  std::move(stack, toMove.stack);
  return *this;
}

template <typename Data>
bool BTInOrdertOrderIterator<Data>::operator==(const BTInOrderIterator& itr) const noexcept{
  return (curr == itr.curr && stack == itr.stack );
}

template <typename Data>
bool BTInOrdertOrderIterator<Data>::operator!=(const BTInOrderIterator& itr) const noexcept{
  return !(*this == itr);
}

template <typename Data>
struct BinaryTree<Data>::Node BTInOrdertOrderIterator<Data>::operator*() const{
  return *curr;
}

template <typename Data>
bool BTInOrdertOrderIterator<Data>::Terminated() noexcept{
  return (curr == nullptr);
}

template <typename Data>
void BTInOrdertOrderIterator<Data>::operator++(){
  if(Terminated()) throw std::out_of_range("Iterator is terminated!");

  if(curr->HasRightChild()){
    curr = MostLeftNode(curr->RightChild());
  }else{
    try{
      curr = &(stack.TopNPop());
    }catch(std::length_error exc){
      curr = nullptr;
    }
  }
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& tree){
  curr = &(tree.Root());
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
BTBreadthIterator& BTBreadthIterator<Data>::operator=(const BTBreadthIterator& itr){
  curr = itr.curr;
  queue = itr.queue;
  return *this;
}

template <typename Data>
BTBreadthIterator& BTBreadthIterator<Data>::operator=(BTBreadthIterator&& itr) noexcept{
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
struct BinaryTree<Data>::Node BTBreadthIterator<Data>::operator*() const{
  return *curr;
}

template <typename Data>
bool BTBreadthIterator<Data>::Terminated() noexcept{
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
