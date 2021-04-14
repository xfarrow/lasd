
namespace lasd {

/* ************************************************************************** */
// constructors
template <typename Data>
StackVec<Data>::StackVec(){
  size = 4; // default vector is instantiated with 4 cells
  Elements = new Data[size];
}

template <typename Data>
StackVec<Data>::StackVec(const LinearContainer<Data>& linear){ // si può richiamare il costruttore della classe Vector
  Elements = new Data[linear.Size()]; // espandere di un po' forse
  for(ulong i=0 ; i<linear.Size() ; ++i){
    Elements[i] = linear[i];
  }
  size = linear.Size();
  stackSize = linear.Size();
}

template <typename Data>
StackVec<Data>::StackVec(const StackVec& stckvec){// si può richiamare il costruttore della classe Vector
  Elements = new Data[stckvec.Size()]; // espandere di un po' forse
  for(ulong i=0 ; i<stckvec.Size() ; ++i){
    Elements[i] = stckvec[i];
  }
  size = stckvec.Size();
  stackSize = stckvec.stackSize;
}
/*
StackVec(const StackVec& stckvec) : Vector<Data>(copyFrom)
*/

template <typename Data>
StackVec<Data>::StackVec(StackVec&& toMove) noexcept{
  std::swap(Elements, toMove.Elements);
  std::swap(size, toMove.size);
  std::swap(stackSize, toMove.stackSize);
}

StackVec<Data>::~StackVec(){
  // Vector destructor will be called automatically
  // (TEST IT)
}

template <typename Data>
StackVec& StackVec<Data>::operator=(const StackVec& copyFrom){
  Vector<Data>::operator=(copyFrom); // espandere di un po' forse
  stackSize = copyFrom.Size();
  return *this;
}

template <typename Data>
StackVec& StackVec<Data>::operator=(StackVec&& moveFrom) noexcept{
  Vector<Data>::operator=(std::move(moveFrom)); // espandere di un po' forse
  stackSize = copyFrom.Size();
}

template <typename Data>
bool StackVec<Data>::operator==(const StackVec& toCompare) const noexcept{
  Vector<Data>::operator==(toCompare);
}

template <typename Data>
bool StackVec<Data>::operator!=(const StackVec& toCompare) const noexcept{
  Vector<Data>::operator!=(toCompare);
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
}

template <typename Data>
Data& StackVec<Data>::Top() const{
  if(stackSize == 0){
    throw std::length_error("Empty Stack!");
  }
  return Elements[stackSize-1]
}

template <typename Data>
void StackVec<Data>::Pop(){
  if(stackSize<=0){
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

/* ************************************************************************** */

}
