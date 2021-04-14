
namespace lasd {

/* ************************************************************************** */
template <typename Data>
QueueVec<Data>::QueueVec(){
  size = 4;
  Elements = new Data[size];
}

template <typename Data>
QueueVec(const LinearContainer<Data>& linear){
  size = linear.Size();
  Elements = new Data[size];
  for(ulong i=0 ; i<linear.Size() ; ++i){
    Elements[i] = linear[i];
  }
}

/* ************************************************************************** */

}
