
namespace lasd {

/* ************************************************************************** */

// Constructors
template <typename Data>
StackLst<Data>::StackLst(const LinearContainer<Data>& linear){
  for(long int i=(long int)linear.Size()-1 ; i>=0 ; --i){ // è possibile usare il costruttore di List?
    Push(linear[i]);
  }
}
/*
PROVARE
template <typename Data>
StackLst(const LinearContainer<Data>& linear) : List<Data>(linear){
return;
}
*/
template <typename Data>
StackLst<Data>::StackLst(const StackLst& stcklist){
for(long int i=(long int)stcklist.Size()-1 ; i>=0 ; i--){
    Push(stcklist[i]);
  }
}
/*
PROVARE
StackLst(const StackLst& stcklist) : List<Data>(stcklist){}
*/

template <typename Data>
StackLst<Data>::StackLst(StackLst&& stcklist) noexcept{
    std::swap(size, stcklist.size);
    std::swap(head, stcklist.head);
}

// Destructor
template <typename Data>
StackLst<Data>::~StackLst(){
  Clear();
}

template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst& copyFrom){
  if(*this != copyFrom){
    Clear();
    for(long int i=(long int)copyFrom.Size()-1 ; i>=0 ; --i){
      Push(copyFrom[i]);
    }
  }
  return *this;
}

template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst&& moveFrom) noexcept{
  std::swap(size, moveFrom.size);
  std::swap(head, moveFrom.head);
  return *this;
}

template <typename Data>
bool StackLst<Data>::operator==(const StackLst& stcklist) const noexcept{
  return List<Data>::operator==(stcklist);
}

template <typename Data>
bool StackLst<Data>::operator!=(const StackLst& stcklist) const noexcept{
  return List<Data>::operator!=(stcklist);
}

// Specific member functions (inherited from Stack)
template <typename Data>
void StackLst<Data>::Push(const Data& element){
  List<Data>::InsertAtFront(element);
}

template <typename Data>
void StackLst<Data>::Push(Data&& element) noexcept{
  List<Data>::InsertAtFront(element);
}

template <typename Data>
Data& StackLst<Data>::Top() const{
  return List<Data>::Front();
}

template <typename Data>
void StackLst<Data>::Pop(){
  List<Data>::RemoveFromFront();
}

template <typename Data>
Data StackLst<Data>::TopNPop(){
  return List<Data>::FrontNRemove();
}

template <typename Data>
void StackLst<Data>::Clear(){
  List<Data>::Clear();
}

/* ************************************************************************** */

}
