
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
Data BST<Data>::DataNDelete(struct BST<Data>::NodeLnk* ptr){
  Data data = ptr->Element();
  delete ptr;
  return data;
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Detach(struct BST<Data>::NodeLnk*& ptrref) noexcept{
  if(ptrref == nullptr) return nullptr;

  if(ptrref->left == nullptr){
    return SkipOnRight(ptrref);
  }
  else if(ptrref->right == nullptr){
    return SkipOnLeft(ptrref);
  }
  else{
    NodeLnk* maxNode = DetachMax(ptrref->left);
    std::swap(ptrref->Element() , maxNode->Element());
    return maxNode;
  }
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMin(struct BST<Data>::NodeLnk*& ptrref) noexcept{
  return SkipOnRight(FindPointerToMin(ptrref));
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMax(struct BST<Data>::NodeLnk*& ptrref) noexcept{
  return SkipOnLeft(FindPointerToMax(ptrref));
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::SkipOnLeft(struct BST<Data>::NodeLnk*& ptrref) noexcept{
  NodeLnk* left = nullptr;
  if(ptrref != nullptr){
    std::swap(left, ptrref->left);
    std::swap(left, ptrref);
    --size;
  }
  return left;
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::SkipOnRight(struct BST<Data>::NodeLnk*& ptrref) noexcept{
  NodeLnk* right = nullptr;
  if(ptrref != nullptr){
    std::swap(right, ptrref->right);
    std::swap(right, ptrref);
    --size;
  }
  return right;
}

template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMin(struct BST<Data>::NodeLnk* const& node) const noexcept{
  /*
    In order to return a [reference to a] const pointer, we need to
    declare a variable (ptr) which points to a const pointer which points to
    a NodeLnk.
    This const pointer that points to a NodeLnk is the parameter of the function.

    Hence, *ptr will be a const pointer.
  */
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
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin(struct BST<Data>::NodeLnk*& node) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToMin(node));
}

template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMax(struct BST<Data>::NodeLnk* const& node) const noexcept{
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
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax(struct BST<Data>::NodeLnk*& node) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToMax(node));
}

template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerTo(struct BST<Data>::NodeLnk* const& ref, Data data) const noexcept{
  /*
    In order to return a [reference to a] const pointer, we need to
    declare a variable (pointer) which points to a const pointer which points to
    a NodeLnk.
    This const pointer that points to a NodeLnk is the parameter of the function.
    Hence, (*pointer) will be a const pointer.

    Note: this function (and others too) could've been written using one single pointer, in this way:
    while(*pointer != nullptr && (*(*pointer)).Element() != data){
      if( (*(*pointer)).Element() < data ) pointer = &((*pointer)->right);
      else if((*(*pointer)).Element() > data ) pointer = &((*pointer)->left);
    }
    but I preferred to use a clearer version.
  */

  NodeLnk* const* pointer = &ref; //a pointer to a const pointer to a NodeLnk
  NodeLnk* current = ref;

  while(current != nullptr && current->Element() != data){
    if(current->Element() < data){
      pointer = &(current->right);
      current = current->right;
    }else if(current->Element() > data){
      pointer = &(current->left);
      current = current->left;
    }
  }
  return *pointer;
}

template <typename Data>
typename BST<Data>::NodeLnk* const* BST<Data>::FindPointerToPredecessor(struct BST<Data>::NodeLnk* const& ref, Data data) const noexcept{

  /*
    If the element we are looking the predecessor for is the current element,
    then its predecessor resides in the max node of its left subtree (if it has
    a left subtree. Return the candidate otherwise).

    If the element we are looking the predecessor for is greater than the current element,
    then we have to go down right the tree, saving the current "candidate".

    If the element we are looking the predecessor for is less than the current element,
    then we have to go down left the tree.
  */

  NodeLnk* const* pointer = &ref;
  NodeLnk* current = ref;
  NodeLnk* const* candidate = nullptr;

  while(current != nullptr){
    if(data == current->Element()){
      if(current->HasLeftChild()){
        return &(FindPointerToMax(current->left));
      }else{
        return candidate;
      }
    }else if(current->Element() < data){
      candidate = pointer;
      pointer = &(current->right);
      current = current->right;
    }else if(current->Element() > data){
      pointer = &(current->left);
      current = current->left;
    }
  }
  return candidate;
}

template <typename Data>
typename BST<Data>::NodeLnk* const* BST<Data>::FindPointerToSuccessor(struct BST<Data>::NodeLnk* const& ref, Data data) const noexcept{
  NodeLnk* const* pointer = &ref;
  NodeLnk* current = ref;
  NodeLnk* const* candidate = nullptr;

    while( current != nullptr){
      if(data == current->Element()){
        if(current->HasRightChild()){
          return &(FindPointerToMin(current->right));
        }
        else{
          return candidate;
        }
      }else if(current->Element() > data){
        candidate = pointer;
        pointer = &current->left;
        current = current->left;
      }else if(current->Element() < data){
        pointer = &current->right;
        current = current->right;
      }
    }
    return candidate;
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(struct BST<Data>::NodeLnk*& node, Data data) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerTo(node, data));
}

template <typename Data>
typename BST<Data>::NodeLnk** BST<Data>::FindPointerToPredecessor(struct BST<Data>::NodeLnk*& node, Data data) noexcept{
  return const_cast<NodeLnk**>(static_cast<const BST<Data> *>(this)->FindPointerToPredecessor(node, data));
}

template <typename Data>
typename BST<Data>::NodeLnk** BST<Data>::FindPointerToSuccessor(struct BST<Data>::NodeLnk*& node, Data data) noexcept{
  return const_cast<NodeLnk**>(static_cast<const BST<Data> *>(this)->FindPointerToSuccessor(node, data));
}

}
