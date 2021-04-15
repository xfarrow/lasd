
namespace lasd {

/* ************************************************************************** */
template <typename Data>
QueueVec<Data>::QueueVec(){
  size = 4;
  rear = 0;
  front = 0;
  Elements = new Data[size];
}

template <typename Data>
QueueVec(const LinearContainer<Data>& linear){
  size = linear.Size();
  Elements = new Data[size+1]; //forse da espandere
  for(ulong i=0 ; i<linear.Size() ; ++i){
    Elements[i] = linear[i];
  }
  front = 0;
  rear = size;
}

template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec& toCopy){
  size = toCopy.Size();
  ulong index_of_the_element = toCopy.front , i=0;
  Elements = new Data[size];

  while(index_of_the_element != toCopy.rear){
    Elements[i] = toCopy[index_of_the_element];
    ++i;
    index_of_the_element = (index_of_the_element+1)%size;
  }
  front = 0;
  rear = toCopy.rear;
}

template <typename Data>
QueueVec<Data>::QueueVec(QueueVec&& toMove) noexcept{
    std::swap(Elements, toMove.Elements);
    std::swap(rear, toMove.rear);
    std::swap(front, toMove.front);
    std::swap(size, toMove.size);
}

template <typename Data>
virtual QueueVec<Data>::~QueueVec(){
  //vector destructor will be called
  // TEST IT!
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec& toCopy){
  QueueVec<Data>* tmpQueue = new QueueVec<Data>(toCopy);
  std::swap(*tmpQueue, *this);
  delete tmpQueue;
  return *this;
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec&& toMove) noexcept{
  std::swap(Elements, toMove.Elements);
  std::swap(size, toMove.size);
  std::swap(rear, toMove.rear);
  std::swap(front, toMove.front);
  return *this;
}

template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec& toCompare) const noexcept{
  if(Size() == toCompare.Size()){
    ulong indexToCompare = toCompare.front;
    ulong index = front;
    while(indexToCompare != toCompare.rear){
      if(Elements[index]!=toCompare[indexToCompare]){
        return false;
      }
      index = (index+1)%size;
      indexToCompare = (indexToCompare+1)%size;
    }
    return true;
  }else{
    return false;
  }
}

template <typename Data>
bool QueueVec<Data>::operator!=(const QueueVec& toCompare) const noexcept{
  return !(*this == toCompare);
}

template <typename Data>
void QueueVec<Data>::Enqueue(const Data& data){
  if((rear+1)%size == front){
    Expand();
  }
  Elements[rear] = data;
  rear = (rear + 1) % size;
}

template <typename Data>
void QueueVec<Data>::Enqueue(Data&& data){
  if((rear+1)%size == front){
    Expand();
  }
  std::swap(Elements[rear],data);
  rear = (rear + 1) % size;
}

template <typename Data>
Data& QueueVec<Data>::Head() const{
  if(Size()<=0){
    throw std::length_error("Queuevec is empty!");
  }
  return Elements[front];
}

template <typename Data>
void QueueVec<Data>::Dequeue(){
  if(Size() == 0){
    throw std::length_error("Queuevec is empty!");
  }
  front = (front + 1) % size;
  if(Size() < size/4){
    Reduce();
  }
}

template <typename Data>
Data QueueVec<Data>::HeadNDequeue(){
  Data tmp = Head();
  Dequeue();
  return tmp;
}

template <typename Data>
bool QueueVec<Data>::Empty() const noexcept{
  return (front == rear);
}

template <typename Data>
ulong Size() const noexcept{
  return ((rear + size) - front) % size;
}

template <typename Data>
void Clear(){

}
/* ************************************************************************** */

}
