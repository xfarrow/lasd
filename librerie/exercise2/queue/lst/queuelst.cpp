
namespace lasd {

/* ************************************************************************** */
template <typename Data>
QueueLst<Data>::QueueLst(const LinearContainer<Data>& linear){
  for(ulong i=0; i<linear.Size() ; ++i){
    Enqueue(linear[i]);
  }
}

template <typename Data>
QueueLst<Data>::QueueLst(const QueueLst& copyFrom){
  for(ulong i=0; i<copyFrom.Size() ; ++i){
    Enqueue(copyFrom[i]);
  }
}

template <typename Data>
QueueLst<Data>::QueueLst(QueueLst&& moveFrom) noexcept{
    std::swap(head,moveFrom.head);
    std::swap(tail,moveFrom.tail);
    std::swap(size,moveFrom.size);
}

template <typename Data>
QueueLst<Data>::~QueueLst(){
  Clear();
}

template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst& toCopy){
  // QueueLst<Data>* tmp = new QueueLst<Data>(toCopy);
  // std::swap(*this, *tmp);
  // delete tmp;
  // return *this;

  List<Data>::operator=(toCopy);
  return *this;
}

template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst&& toMove) noexcept{
  List<Data>::operator=(std::move(toMove));
  return *this;
}

template <typename Data>
bool QueueLst<Data>::operator==(const QueueLst& queuelist) const noexcept{
    return List<Data>::operator==(queuelist);
  }

template <typename Data>
bool QueueLst<Data>::operator!=(const QueueLst& queuelist) const noexcept{
    return List<Data>::operator!=(queuelist);
  }

template <typename Data>
  void QueueLst<Data>::Enqueue(const Data& data){
    List<Data>::InsertAtBack(data);
  }

template <typename Data>
void QueueLst<Data>::Enqueue(Data&& data){
    List<Data>::InsertAtBack(data);
  }

template <typename Data>
Data& QueueLst<Data>::Head() const{
    return List<Data>::Front();
}

template <typename Data>
void QueueLst<Data>::Dequeue(){
    List<Data>::RemoveFromFront();
}

template <typename Data>
Data QueueLst<Data>::HeadNDequeue(){
  return List<Data>::FrontNRemove();
}

template <typename Data>
void QueueLst<Data>::Clear(){
  List<Data>::Clear();
}
/* ************************************************************************** */

}
