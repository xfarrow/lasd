
namespace lasd {

template <typename Data>
QueueLst<Data>::QueueLst(const LinearContainer<Data>& linear)
  : List<Data>(linear) {}

template <typename Data>
QueueLst<Data>::QueueLst(const QueueLst& copyFrom)
  : List<Data>(copyFrom) {}

template <typename Data>
QueueLst<Data>::QueueLst(QueueLst&& moveFrom) noexcept
  : List<Data>(std::move(moveFrom)) {}

template <typename Data>
QueueLst<Data>::~QueueLst(){
  Clear();
}

template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst& toCopy){
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
    List<Data>::InsertAtBack(std::move(data));
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

}
