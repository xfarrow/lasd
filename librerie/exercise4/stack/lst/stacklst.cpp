
namespace lasd {

/* ************************************************************************** */

// Constructors
template <typename Data>
StackLst<Data>::StackLst(const LinearContainer<Data>& linear)
  : List<Data>(linear){}

template <typename Data>
StackLst<Data>::StackLst(const StackLst& stcklist)
  : List<Data>(stcklist){}

template <typename Data>
StackLst<Data>::StackLst(StackLst&& stcklist) noexcept
  : List<Data>(std::move(stcklist)){}

// Destructor
template <typename Data>
StackLst<Data>::~StackLst(){
  Clear();
}

template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst& copyFrom){
  List<Data>::operator=(copyFrom);
  return *this;
}

template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst&& moveFrom) noexcept{
  List<Data>::operator=(std::move(moveFrom));
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
