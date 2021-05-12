
namespace lasd {

template <typename Data>
BST<Data>::BST(const LinearContainer<Data>& lc){
  for(ulong i=0 ; i<lc.Size() ; ++i){
    Insert(lc[i]);
  }
}

template <typename Data>
BST<Data>::BST(const BST<Data>& bst)
  : BinaryTreeLnk<Data>(bst){}

template <typename Data>
BST<Data>::BST(BST<Data>&& bst) noexcept
  : BinaryTreeLnk<Data>(std::move(bst)){}

template <typename Data>
BST<Data>::~BST(){
  BinaryTreeLnk<Data>::Clear();
}

template <typename Data>
BST<Data>& BST<Data>::operator=(const BST<Data>& bst){
  BinaryTreeLnk<Data>::operator=(bst);
  return *this;
}

template <typename Data>
BST<Data>& BST<Data>::operator=(BST<Data>&& bst) noexcept{
  BinaryTreeLnk<Data>::operator=(std::move(bst));
  return *this;
}

template <typename Data>
bool BST<Data>::operator==(const BST<Data>& bst) const noexcept{
  if(size != bst.Size()) return false;

  BTInOrderIterator<Data> itr1(*this);
  BTInOrderIterator<Data> itr2(bst);

  for(; !itr1.Terminated() ; ++itr1, ++itr2){
    if(*itr1 != *itr2) return false;
  }
  return true;
}

template <typename Data>
bool BST<Data>::operator!=(const BST<Data>& bst) const noexcept{
  return !(*this = bst)
}

template <typename Data>
void BST<Data>::Insert(const Data& data) noexcept{
    NodeLnk*& pointer = FindPointerTo(root, data);
    if(pointer == nullptr){
      pointer = CreateNode(data);
      size++;
    }
}

template <typename Data>
void BST<Data>::Insert(Data&& data) noexcept{
    NodeLnk*& pointer = FindPointerTo(root, data);
    if(pointer == nullptr){
      pointer = new NodeLnk();
      std::swap(pointer->value, data);

      size++;
    }
}

template <typename Data>
void BST<Data>::Remove(const Data& data) noexcept{
  delete Detach(FindPointerTo(root,data));
}

template <typename Data>
const Data& BST<Data>::Min() const{
  if(root == nullptr) throw std::length_error("Empty tree!");

  return FindPointerToMin(root)->Element();
}

template <typename Data>
Data BST<Data>::MinNRemove(){
  if(root == nullptr) throw std::length_error("Empty tree!");

  return DataNDelete(DetachMin(root));
}

template <typename Data>
void BST<Data>::RemoveMin(){
  if(root == nullptr) throw std::length_error("Empty tree!");

  return DetachMin(root);
}


template <typename Data>
const Data& BST<Data>::Max() const{
  if(root == nullptr) throw std::length_error("Empty tree!");

  return FindPointerToMax(root)->Element();
}

template <typename Data>
Data BST<Data>::MaxNRemove(){
  if(root == nullptr) throw std::length_error("Empty tree!");

  return DataNDelete(DetachMax(root));
}

template <typename Data>
void BST<Data>::RemoveMax(){
  if(root == nullptr) throw std::length_error("Empty tree!");

  return DetachMax(root);
}

template <typename Data>
const Data& BST<Data>::Predecessor(const Data& data) const{
  NodeLnk* const* ptr = FindPointerToPredecessor(root, data)
  if(ptr!=nullptr){
    return (*(*ptr)).Element();
  }else{
    throw std::length_error("Predecessor not found!");
  }
}

template <typename Data>
Data BST<Data>::PredecessorNRemove(const Data& data){
  NodeLnk** ptr = FindPointerToPredecessor(root,data);
  if(ptr!=nullptr){
    return DataNDelete(Detach(*ptr));
  }else{
    throw std::length_error("Predecessor not found!");
  }
}

template <typename Data>
void BST<Data>::RemovePredecessor(const Data& data){
  NodeLnk** ptr = FindPointerToPredecessor(root,data);
  if(ptr!=nullptr){
    delete Detach(*ptr);
  }else{
    throw std::length_error("Predecessor not found!");
  }
}

template <typename Data>
const Data& BST<Data>::Successor(const Data& data) const{
  NodeLnk* const* ptr = FindPointerToSuccessor(root, data)
  if(ptr!=nullptr){
    return (*(*ptr)).Element();
  }else{
    throw std::length_error("Successor not found!");
  }
}

template <typename Data>
Data BST<Data>::SuccessorNRemove(const Data& data){
  NodeLnk** ptr = FindPointerToSuccessor(root,data);
  if(ptr!=nullptr){
    return DataNDelete(Detach(*ptr));
  }else{
    throw std::length_error("Successor not found!");
  }
}

template <typename Data>
void BST<Data>::RemoveSuccessor(const Data& data){
  NodeLnk** ptr = FindPointerToSuccessor(root,data);
  if(ptr!=nullptr){
    delete Detach(*ptr);
  }else{
    throw std::length_error("Successor not found!");
  }
}

}
