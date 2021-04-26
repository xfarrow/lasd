
// #include "..."

namespace lasd {

/* ************************************************************************** */

// checks if two trees which have the same root node are identical
template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& toEvaluate){
  return EqualNodes(this, &toEvaluate);
}

bool BinaryTree<Data>::Node::EqualNodes(Node* n1, Node* n2){
  if(n1->IsLeaf() && n2->IsLeaf() && n1->data == n2->data) return true;
  if( (n1->HasLeftChild() && !n2->HasLeftChild()) || (n1->HasRightChild() && !n2->HasRightChild()) ) return false;
  return( n1->data == n2->data &&
          EqualNodes(n1->LeftChild(),n2->LeftChild()) &&
          EqualNodes(n1->RightChild(),n2->RightChild())
        )
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

template <typename Data>
void BinaryTree<Data>::MapPreOrder(const MapFunctor function, void* par){
  MapPreOrder(function, par, &Root());
}

template <typename Data>
void BinaryTree<Data>::MapPostOrder(const MapFunctor function, void* par){
  MapPostOrder(function, par, &Root());
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
void BinaryTree<Data>::MapInOrder(const MapFunctor function, void* par){
  MapInOrder(function, par, &Root());
}

template <typename Data>
void BinaryTree<Data>::FoldInOrder(const MapFunctor function, const void* par, void* acc) const{
  FoldInOrder(function, par, acc, &Root());
}

template <typename Data>
void BinaryTree<Data>::MapBreadth(const MapFunctor function, void* par){
  MapBreadth(function, par, &Root());
}

template <typename Data>
void BinaryTree<Data>::FoldBreadth(const FoldFunctor function, const void* par, void* acc) const{
  FoldBreadth(function, par, acc, &Root());
}

/* ----- AUX ----- */

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
void MapBreadth(const MapFunctor function, void* par, Node* node){
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
      ql.Dequeue();
    }
  }
}



/* ************************************************************************** */

}
