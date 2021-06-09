
namespace lasd {

template <typename Data>
QueueVec<Data>::QueueVec(){
  size = 4;
  rear = 0;
  front = 0;
  Elements = new Data[size];
}

template <typename Data>
QueueVec<Data>::QueueVec(const LinearContainer<Data>& linear){
  size = linear.Size()+1; // 1 free cell
  Elements = new Data[size]; //forse da espandere
  for(ulong i=0 ; i<linear.Size() ; ++i){
    Elements[i] = linear[i];
  }
  front = 0;
  rear = size-1; // the vector will be full
}

template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec& toCopy){
  size = toCopy.size;
  ulong index_of_the_element = toCopy.front , i=0;
  Elements = new Data[size];

  while(index_of_the_element != toCopy.rear){
    Elements[i] = toCopy[index_of_the_element];
    ++i;
    index_of_the_element = (index_of_the_element+1)%size;
  }
  front = 0;
  rear = i;
}

template <typename Data>
QueueVec<Data>::QueueVec(QueueVec&& toMove) noexcept{
    Clear(); // the moved Queue will be in a consistent state
    std::swap(Elements, toMove.Elements);
    std::swap(rear, toMove.rear);
    std::swap(front, toMove.front);
    std::swap(size, toMove.size);
}

template <typename Data>
QueueVec<Data>::~QueueVec(){
  //vector destructor will be automatically called I hope
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
    throw std::length_error("Queue is empty!");
  }
  return Elements[front];
}

template <typename Data>
void QueueVec<Data>::Dequeue(){
  if(Size() <= 0){
    throw std::length_error("Queue is empty!");
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
ulong QueueVec<Data>::Size() const noexcept{
  //if(size == 0) return 0; // this won't ever get executed, it's here just in case
  return ((rear + size) - front) % size;
}

template <typename Data>
void QueueVec<Data>::Clear(){
  if(size!=4){
    delete[] Elements;
    Elements = new Data[4];
    size = 4;
  }
  front = 0;
  rear = 0;
}

template <typename Data>
void QueueVec<Data>::Expand(){
  Data* tmp = new Data[size * 2];
  ulong current_index = front , i=0;
  while(current_index != rear){
    tmp[i] = Elements[current_index];
    current_index = (current_index+1)%size;
    ++i;
  }
  delete[] Elements;
  Elements = tmp;
  front = 0;
  rear = i;
  size *= 2;
}

template <typename Data>
void QueueVec<Data>::Reduce(){
  if(size<=4) return; // we are not going to have vectors with less than 4 Elements
  ulong newsize = (ulong)size/2;
  Data* tmp = new Data[newsize];
  ulong current_index = front , i=0;
  while(current_index != rear){
    tmp[i] = Elements[current_index];
    current_index = (current_index+1)%size;
    ++i;
  }
  delete[] Elements;
  Elements = tmp;
  front = 0;
  rear = i;
  size = newsize;
}

}
