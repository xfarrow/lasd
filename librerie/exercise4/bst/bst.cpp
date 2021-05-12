
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
  return !(*this == bst);
}

template <typename Data>
void BST<Data>::Insert(const Data& data) noexcept{
    NodeLnk*& pointer = FindPointerTo(root, data);
    if(pointer == nullptr){
      pointer = BinaryTreeLnk<Data>::CreateNode(data);
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

  delete DetachMin(root);
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

  delete DetachMax(root);
}

template <typename Data>
const Data& BST<Data>::Predecessor(const Data& data) const{
  NodeLnk* const* ptr = FindPointerToPredecessor(root, data);
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
  NodeLnk* const* ptr = FindPointerToSuccessor(root, data);
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

template <typename Data>
bool BST<Data>::Exists(const Data& data) const noexcept{
  return (FindPointerTo(root, data) != nullptr);
}

template <typename Data>
Data BST<Data>::DataNDelete(NodeLnk* ptr){
  Data data = ptr->Element();
  delete ptr;
  return data;
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Detach(NodeLnk*& ptrref) noexcept{
  if(ptrref == nullptr) return nullptr;

  if(ptrref->left == nullptr){
    return SkipOnRight(ptrref);
  }
  else if(ptrref->right == nullptr){
    return SkipOnLeft(ptrref);
  }
  else{
    NodeLnk* maxNode = DetachMax(ptrref->left);
    std::swap(ptrref->data , maxNode->data);
    return maxNode;
  }
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMin(NodeLnk*& ptrref) noexcept{
  return SkipOnRight(FindPointerToMin(ptrref));
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMax(NodeLnk*& ptrref) noexcept{
  return SkipOnLeft(FindPointerToMax(ptrref));
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::SkipOnLeft(NodeLnk*& ptrref) noexcept{
  NodeLnk* left = nullptr;
  if(ptrref != nullptr){
    std::swap(left, ptrref->left);
    std::swap(left, ptrref);
    --size;
  }
  return left;
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::SkipOnRight(NodeLnk*& ptrref) noexcept{
  NodeLnk* right = nullptr;
  if(ptrref != nullptr){
    std::swap(right, ptrref->right);
    std::swap(right, ptrref);
    --size;
  }
  return right;
}

template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMin(NodeLnk* const& node) const noexcept{
  NodeLnk* const* ptr = &node;
  NodeLnk* curr = node;
  if(curr!=nullptr){
    while(curr->left != nullptr){
      ptr = &curr->left;
      curr = curr->left;
    }
  }
  return *ptr;
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin(NodeLnk*& node) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToMin(node));
}

template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMax(NodeLnk* const& node) const noexcept{
  NodeLnk* const* ptr = &node;
  NodeLnk* curr = node;
  if(curr!=nullptr){
    while(curr->right != nullptr){
      ptr = &curr->right;
      curr = curr->right;
    }
  }
  return *ptr;
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax(NodeLnk*& node) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToMax(node));
}

/* ---- END ----- */

template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerTo(NodeLnk* const& node) const noexcept{
  NodeLnk* const* ptr = &node;
  NodeLnk* curr = node;
  if(curr!=nullptr){
    while(curr!=nullptr || curr->Element() != node->Element()){
      if(curr->Element() < node->Element()){
        ptr = &curr->right;
        curr = curr->right;
      }else if(curr->Element() > node->Element()){
        ptr = &curr->left;
        curr = curr->left;
      }
    }
  }
  if(curr->Element() == node->Element()) return *ptr;
  else return nullptr;
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(NodeLnk*& node) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerTo(node));
}

template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToPredecessor(NodeLnk* const& node) const noexcept{
  if(node == nullptr) return nullptr;
  NodeLnk* const* ptr = &node;
  NodeLnk* curr = node;
  NodeLnk* lastRight;
  while(curr!=nullptr || node->Element() != curr->Element()){
    if(node->Element() == curr->Element()){
      ptr = FindPointerToMax(curr->left);
    }else if(node->Element() < curr->Element()){
      ptr = &curr->left;
      curr = curr->left;
    }else{
      ptr = &curr->right;
      curr = curr->right;
      lastRight = ptr;
    }
  }
  if(node->Element() == curr->Element()) return *ptr;
  else return lastRight;
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToPredecessor(NodeLnk*& node) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToPredecessor(node));
}

template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToSuccessor(NodeLnk* const& node) const noexcept{
  if(node == nullptr) return nullptr;
  NodeLnk* const* ptr = &node;
  NodeLnk* curr = node;
  NodeLnk* lastLeft;
  while(curr!=nullptr || node->Element() != curr->Element()){
    if(node->Element() == curr->Element()){
      ptr = FindPointerToMin(curr->left);
    }else if(node->Element() < curr->Element()){
      ptr = &curr->left;
      curr = curr->left;
      lastLeft = ptr;
    }else{
      ptr = &curr->right;
      curr = curr->right;
    }
  }
  if(node->Element() == curr->Element()) return *ptr;
  else return lastLeft;
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToSuccessor(NodeLnk*& node) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToSuccessor(node));
}

}
