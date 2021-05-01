
namespace lasd {

/* ************************************************************************** */
template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk& node){
  data = node.data;
  left = node.left;
  right = node.right;
  return *this;
}

template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk&& node) noexcept{
  std::swap(data, node.data);
  std::swap(left, node.left);
  std::swap(right, node.right);
  return *this;
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept{
  return (left==nullptr && right==nullptr);
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept{
  return (left!=nullptr);
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept{
  return (right!=nullptr);
}

template <typename Data>
Node& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const{
  return *left;
}

template <typename Data>
Node& BinaryTreeLnk<Data>::NodeLnk::RightChild() const{
  return *right;
}

// creates a tree from a linear container in breadth
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const LinearContainer<Data>& lc){
  root = CreateTreeFromLinearContainerInBreadth(lc,0);
  size = lc.Size();
}

struct BinaryTreeLnk<Data>::NodeLnk* CreateTreeFromLinearContainerInBreadth(const LinearContainer<Data>& lc, ulong position){
  if(position >= lc.Size()) return nullptr;

  struct BinaryTreeLnk<Data>::NodeLnk* tmp = CreateNode(lc[position]);
  // if(position == 0) root = tmp;

  tmp->left = CreateTreeFromLinearContainerInBreadth(lc, (2*position)+1);
  tmp->right = CreateTreeFromLinearContainerInBreadth(lc, (2*position)+2);

  return tmp;

}

template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk* CreateNode(const Data& data){
    struct BinaryTreeLnk<Data>::NodeLnk* newNode = new struct BinaryTreeLnk<Data>::NodeLnk();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk<Data>& tree){
  if(tree.root == nullptr) return;
  size = tree.size;
  root = CopyTree(&tree.Root());
}

BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::CopyTree(struct BinaryTreeLnk<Data>::NodeLnk* nodeToCopy){
  if(nodeToCopy==nullptr) return nullptr;

  struct BinaryTreeLnk<Data>::NodeLnk* tmp = CreateNode(nodeToCopy.Element());

  if(nodeToCopy.HasLeftChild())
    tmp->left = copyTree(&(nodeToCopy.LeftChild()));
  else
    tmp->left = nullptr;

  if(nodeToCopy.HasRightChild())
    tmp->right = copyTree(&(nodeToCopy.RightChild()));
  else
    tmp->right = nullptr;

  return tmp;
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk<Data>&& tree) noexcept{
  std::swap(size, tree.size);
  std::swap(root, tree.root);
}

template <typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk(){
  Clear();
}

template <typename Data>
void BinaryTreeLnk<Data>::DeleteTree(BinaryTreeLnk<Data>::NodeLnk* node){
  if(node == nullptr) return;
  DeleteTree(node->left);
  DeleteTree(node->right);
  delete node;
}

template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data>& tree){
  Clear();
  size = tree.size;
  if(tree.root != nullptr)
    root = CopyTree(&tree.Root());
  return *this;

}

template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data>&& tree) noexcept{
  std::swap(size, tree.size);
  std::swap(root, tree.root);
  return *this;
}

template <typename Data>
bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk<Data>& tree) const noexcept{
  return (Root() == tree.Root());
}

template <typename Data>
bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk<Data>& tree) const noexcept{
  return !(*this == tree);
}

template <typename Data>
struct NodeLnk& Root() override{
  return *root;
}

template <typename Data>
void Clear() override{
  DeleteTree(root);
}

}
