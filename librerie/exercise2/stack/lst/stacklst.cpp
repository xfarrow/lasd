
namespace lasd {

/* ************************************************************************** */

// Constructors
template <typename Data>
StackLst(const LinearContainer<Data>& linear){
  for(ulong i=linear.Size()-1 ; i>=0 ; --i){ // è possibile usare il costruttore di List?
    Push(linear[i]);
  }
}

StackLst(const StackLst& stcklist){
  for(ulong i=stcklist.Size()-1 ; i>=0 ; --i){
    Push(stcklist[i]);
  }
}

template <typename Data>
StackLst<Data>::StackLst(StackLst&& stcklist) noexcept{
    std::swap(size, stcklist.size);
    std::swap(head, stcklist.head);
}

// Destructor
virtual ~StackLst(){
  Clear();
}

StackLst& operator=(const StackLst& copyFrom){
  if(*this != copyFrom){
    Clear();
    for(ulong i=copyFrom.Size()-1 ; i>=0 ; --i){
      Push(copyFrom[i]);
    }
  }
  return *this;
}

StackLst& operator=(StackLst&& moveFrom){
  std::swap(size, moveFrom.size);
  std::swap(head, moveFrom.head);
  return *this;
}

bool operator==(const StackLst& stcklist) const noexcept{
  return List<Data>::operator==(stcklist);
}

bool operator!=(const StackLst& stcklist) const noexcept{
  return List<Data>::operator!=(stcklist);
}

// Specific member functions (inherited from Stack)
template <typename Data>
void Push(const Data& element){
  List<Data>::InsertAtFront(element);
}

template <typename Data>
void Push(Data&& element){
  List<Data>::InsertAtFront(element);
}

template <typename Data>
Data& Top() const{
  return List<Data>::Front();
}

template <typename Data>
void Pop(){
  List<Data>::RemoveFromFront();
}

template <typename Data>
Data TopNPop(){
  return List<Data>::FrontNRemove();
}

template <typename Data>
void Clear(){
  List<Data>::Clear();
}

/* ************************************************************************** */

}
