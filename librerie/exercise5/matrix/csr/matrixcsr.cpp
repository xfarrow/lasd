
namespace lasd {

/* ************************************************************************** */

template <typename Data>
MatrixCSR<Data>::MatrixCSR(){
  R[0] = &head;
}

template <typename Data>
MatrixCSR<Data>::MatrixCSR(const ulong& r, const ulong& c){
  rows = r;
  columns = c;
  R.Resize(rows+1);
  for(ulong i=0 ; i<R.Size() ; ++i){
    R[i] = &head;
  }
}

// copy constructor
template <typename Data>
MatrixCSR<Data>::MatrixCSR(const MatrixCSR& toCopy) : MatrixCSR(toCopy.rows, toCopy.columns) {
  /*
    For each element in the "R" vector, insert it in the matrix (represented as a list)
    in this way:
    The row index is represented by "i" (the variable that iterates over the R array),
    meanwhile the column index is represented by the second element in the pair of the node.
    The actual element is stored in the first element in the pair of the node.
    The update of the newely created R array is left to operator()().
  */
  for(ulong i=0 ; i < (toCopy.R.Size()-1) ; ++i){
    for(Node** ptr = toCopy.R[i] ; ptr!=toCopy.R[i+1] ; ptr = &( (*(*ptr)).next ) ){
      (*this)(i , ((*ptr)->value).second) = (*ptr)->value).first;
    }
  }
}

template <typename Data>
MatrixCSR<Data>::MatrixCSR(MatrixCSR&& toMove) : MatrixCSR() noexcept{ // controllare se chiamare MatrixCSR()
  std::swap(rows, toMove.rows);
  std::swap(columns, toMove.columns);
  std::swap(size, toMove.size);
  std::swap(head, toMove.head);
  std::swap(R, toMove.R);

  toMove.R[0] = &toMove.head;

  Node** oldHead = R[0];
  for(ulong i=0 ; i<R.Size() && R[i]==oldHead; ++i){
    R[i] = &head;
  }
}

template <typename Data>
MatrixCSR<Data>::~MatrixCSR(){
  Clear();
}

template <typename Data>
MatrixCSR<Data>& MatrixCSR::operator=(const MatrixCSR& toCopy){
  MatrixCSR<Data> tmp(toCopy);
  std::swap(*this, tmp);
  delete tmp;
  return *this;
}

template <typename Data>
MatrixCSR<Data>& MatrixCSR::operator=(MatrixCSR&& toMove) noexcept{
  MatrixCSR<Data> tmp(std::move(toMove));
  std::swap(*this, tmp);
  delete tmp;
  return *this;
}

template <typename Data>
bool MatrixCSR<Data>::operator==(const MatrixCSR& toCompare) const noexcept{

}

template <typename Data>
bool MatrixCSR<Data>::operator!=(const MatrixCSR& toCompare) const noexcept{
  return !(*this == toCompare);
}

template <typename Data>
void RowResize(const ulong& new_row_size){
  R.Resize(new_row_size+1);
  for(ulong i=rows ; i<new_row_size+1 ; ++i){
    R[i] = R[rows];
  }
  rows = new_row_size;
  size = new_row_size * columns;
}

/* ************************************************************************** */

}
