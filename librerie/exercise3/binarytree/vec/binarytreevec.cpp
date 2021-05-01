
namespace lasd {

/* ************************************************************************** */

template <typename Data>
struct BinaryTree<Data>:Node& BinaryTreeVec<Data>::NodeVec::operator=(const BinaryTreeVec<Data>::NodeVec& node){
  ReferenceToTree = node.ReferenceToTree;
  data = node.data;
  index = node.index;
  return *this;
}

template <typename Data>
struct BinaryTree<Data>:Node& BinaryTreeVec<Data>::NodeVec::operator=(BinaryTreeVec<Data>::NodeVec&& node) noexcept{
  std::swap(data, node.data);
  std::swap(index, node.index);
  std::swap(ReferenceToTree, node.ReferenceToTree);
  return *this;
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept{
  return (!HasLeftChild() && !HasRightChild());
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept{
  if(index*2+1 < ReferenceToTree->size){
    return true;
  }else{
    return false;
  }
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept{
  if(index*2+2 < ReferenceToTree->size){
    return true;
  }else{
    return false;
  }
}

template <typename Data>
struct BinaryTree<Data>::Node& BinaryTreeVec<Data>::NodeVec::LeftChild() const{
  if(index*2+1 < ReferenceToTree->size)
    return *((ReferenceToTree->tree)[index*2+1]);
  else
    throw std::out_of_range("Left child does not exist!");
}

template <typename Data>
struct BinaryTree<Data>::Node& BinaryTreeVec<Data>::NodeVec::RightChild() const{
  if(index*2+2 < ReferenceToTree->size)
    return *((ReferenceToTree->tree)[index*2+2]);
  else
    throw std::out_of_range("Right child does not exist!");
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const LinearContainer<Data>& lc){
  tree.Resize(lc.Size());
  size = lc.Size();
  for(ulong i=0 ; i<size ; ++i){
    struct NodeVec* tmp = new BinaryTreeVec<Data>::NodeVec;
    tmp->data = lc[i];
    tmp->index = i;
    tmp->ReferenceToTree = this;
    tree[i] = tmp;
  }
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& bt){
  size = bt.size;
  tree.Resize(size);
  for(ulong i=0 ; i<size ; ++i){
    struct NodeVec* tmp = new BinaryTreeVec<Data>::NodeVec;
    tmp->data = bt[i];
    tmp->index = i;
    tmp->ReferenceToTree = this;
    tree[i] = tmp;
  }
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& bt) noexcept{
  std::swap(size,bt.size);
  std::swap(tree,bt.tree);
}

template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec(){
  Clear();
}

template <typename Data>
bool BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data>& bt){
  size = bt.size;
  tree.Resize(size);
  for(ulong i=0 ; i<size ; ++i){
    struct NodeVec* tmp = new BinaryTreeVec<Data>::NodeVec;
    tmp->data = bt[i];
    tmp->index = i;
    tmp->ReferenceToTree = this;
    tree[i] = tmp;
  }
  return *this;
}

template <typename Data>
bool BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data>&& bt) noexcept{
  std::swap(size, bt.size);
  std::swap(tree, bt.tree);
  return *this;
}

template <typename Data>
bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec& bt) const noexcept{
  if(size==bt.size){
    for(ulong i=0 ; i<size ; ++i){
      if((tree[i])->data != ((bt.tree)[i])->data ) return false;
    }
    return true;
  }
  return false;
}

template <typename Data>
bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec& bt) const noexcept{
  return !(*this == bt);
}

template <typename Data>
struct BinaryTreeVec<Data>::Node& BinaryTreeVec<Data>::Root(){
  return *(tree.Front());
}

template <typename Data>
void BinaryTreeVec<Data>::Clear(){
  for(ulong i=0 ; i<size ; ++i){
    delete tree[i];
    tree[i] = nullptr
  }
  size = 0;
}

template <typename Data>
void BinaryTreeVec<Data>::MapBreadth(const MapFunctor func, void* par) override{
  for(ulong i=0 ; i<size ; ++i){
    func( *(tree[i]), par);
  }
}

template <typename Data>
void BinaryTreeVec<Data>::FoldBreadth(const MapFunctor func, const void* par, void* acc) override{
  for(ulong i=0 ; i<size ; ++i){
    func( *(tree[i]), par, acc);
  }
}

/* ************************************************************************** */

}
