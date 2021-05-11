
namespace lasd {

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

}
