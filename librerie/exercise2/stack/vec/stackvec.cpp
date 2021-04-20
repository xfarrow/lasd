
namespace lasd {

/* ************************************************************************** */
// constructors
template <typename Data>
StackVec<Data>::StackVec(){
  size = 4; // default vector is instantiated with 4 cells
  stackSize = 0;
  Elements = new Data[size];
}

template <typename Data>
StackVec<Data>::StackVec(const LinearContainer<Data>& linear)
  : Vector<Data>(linear){
  stackSize = linear.Size(); // the array is full
}

template <typename Data>
StackVec<Data>::StackVec(const StackVec& stckvec)
  : Vector<Data>(stckvec){
  stackSize = stckvec.Size(); // the array is full
}


template <typename Data>
StackVec<Data>::StackVec(StackVec&& toMove) noexcept
  : Vector<Data>(std::move(toMove)){
  std::swap(stackSize, toMove.stackSize);
}

template <typename Data>
StackVec<Data>::~StackVec(){
  // Vector destructor will be called automatically
}

template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data>& copyFrom){
  Vector<Data>::operator=(copyFrom); // espandere di un po' forse
  stackSize = copyFrom.Size();
  return *this;
}

template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec<Data>&& moveFrom) noexcept{
  Vector<Data>::operator=(std::move(moveFrom));
  stackSize = moveFrom.Size();
  return *this;
}

template <typename Data>
bool StackVec<Data>::operator==(const StackVec<Data>& toCompare) const noexcept{
  if(stackSize == toCompare.Size()){
    for(ulong i=0 ; i<stackSize ; ++i){
      if(Elements[i] != toCompare[i]){
        return false;
      }
    }
    return true;
  }else{
    return false;
  }
}

template <typename Data>
bool StackVec<Data>::operator!=(const StackVec<Data>& toCompare) const noexcept{
  return !(*this == toCompare);
}

// Specific member functions (inherited from Stack)
template <typename Data>
void StackVec<Data>::Push(const Data& data){
  if(size == stackSize){
    Expand();
  }
  Elements[stackSize] = data;
  ++stackSize;
}

template <typename Data>
void StackVec<Data>::Push(Data&& data){
  if(size == stackSize){
    Expand();
  }
  std::swap(Elements[stackSize], data);
  ++stackSize;
}

template <typename Data>
Data& StackVec<Data>::Top() const{
  if(stackSize == 0){
    throw std::length_error("Empty Stack!");
  }
  return Elements[stackSize-1];
}

template <typename Data>
void StackVec<Data>::Pop(){
  if(stackSize==0){
    throw std::length_error("Empty Stack!");
  }
  --stackSize;
  if(stackSize < (int)(size/4)){
    Reduce();
  }
}
template <typename Data>
Data StackVec<Data>::TopNPop(){
  Data data = Top();
  Pop();
  return data;
}

template <typename Data>
bool StackVec<Data>::Empty() const noexcept{
  return (stackSize == 0);
}

template <typename Data>
ulong StackVec<Data>::Size() const noexcept{
  return stackSize;
}

template <typename Data>
void StackVec<Data>::Expand(){
  Vector<Data>::Resize(size * 2);
}

template <typename Data>
void StackVec<Data>::Reduce(){
  if(size <= 4) return; // we're not going to have vectors with less than 4 cells
  Vector<Data>::Resize((ulong)size/2);
}

template <typename Data>
void StackVec<Data>::Clear(){
  delete [] Elements;
  size = 4;
  stackSize = 0;
  Elements = new Data[size];
}
}
