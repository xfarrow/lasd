
namespace lasd {

/* ************************************************************************** */
template <typename Data>
QueueLst(const LinearContainer<Data>& linear){
  for(ulong i=0; i<linear.Size() ; ++i){
    Enqueue(linear[i]);
  }
}

template <typename Data>
QueueLst(const QueueLst& copyFrom){
  for(ulong i=0; i<copyFrom.Size() ; ++i){
    Enqueue(copyFrom[i]);
  }
}

template <typename Data>
QueueLst(QueueLst&& moveFrom) noexcept{
    std::swap(head,moveFrom.head);
    std::swap(tail,moveFrom.tail);
    std::swap(size,moveFrom.size);
}

~QueueLst(){
  Clear();
}

template <typename Data>
QueueLst<Data>& operator=(const QueueLst& toCopy){
  QueueLst<Data>* tmp = new QueueLst<Data>(toCopy);
  std::swap(*this, *tmp);
  delete tmp;
  return *this;
  /*
    List<Data>::operator=(copyFrom);
  */
}

QueueLst& operator=(QueueLst&& toMove) noexcept{
  if(*this != toMove){
    std::swap(head, toMove.head);
    std::swap(head, toMove.tail);
    std::swap(size, toMove.size);
    return *this;
  }

  bool operator==(const QueueLst& queuelist) const noexcept{
    return List<Data>::operator==(queuelist);
  }

  bool operator==(const QueueLst& queuelist) const noexcept{
    return List<Data>::operator!=(queuelist);
  }

template <typename Data>
  void Enqueue(const Data& data){
    List<Data>::InsertAtBack(data);
  }

template <typename Data>
  void Enqueue(Data&& data){
    List<Data>::InsertAtBack(data);
  }

template <typename Data>
  Data& Head() const{
    return List<Data>::Front();
  }

template <typename Data>
  void Dequeue(){
    List<Data>::RemoveFromFront();
  }
}
template <typename Data>
Data HeadNDequeue(){
  return List<Data>::FrontNRemove();
}

/* ************************************************************************** */

}
