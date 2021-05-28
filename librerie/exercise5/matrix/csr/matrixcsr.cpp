
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
MatrixCSR<Data>::MatrixCSR(MatrixCSR&& toMove) noexcept{
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
  if(columns == toCompare.columns && rows == toCompare.rows && size==toCompare.size){
    for(ulong i=0 ; i<(R.Size()-1) ; ++i){
      for(Node** ptr1 = R[i], ptr2 = toCopy.R[i] ; ptr1!=R[i+1] && ptr2!=toCopy.R[i+1] ; ptr1 = &( (*(*ptr1)).next ) , ptr2 = &( (*(*ptr2)).next ) ){

        if( ( ((*ptr1)->value).first != ((*ptr2)->value).first ) || ( ((*ptr1)->value).second != ((*ptr2)->value).second )) return false;

        if( (&((*(*ptr1)).next)==R[i+1] && &((*(*ptr2)).next) != toCopy.R.[i+1]) || (&((*(*ptr1)).next)!=R[i+1] && &((*(*ptr2)).next) == toCopy.R.[i+1])){
          return false;
        }

      }
    }
    return true;
  }else{
    return false;
  }
}

template <typename Data>
bool MatrixCSR<Data>::operator!=(const MatrixCSR& toCompare) const noexcept{
  return !(*this == toCompare);
}

template <typename Data>
void MatrixCSR<Data>::RowResize(const ulong& new_row_size){
  if(new_row_size == 0){
    Clear();
  }
  else if(new_row_size > row){
    R.Resize(new_row_size+1);
    for(ulong i=rows ; i<new_row_size+1 ; ++i){
      R[i] = R[rows];
    }
    rows = new_row_size;
  }else if(new_row_size < row){
    Node* toDelete,tmp;
    toDelete = *R[new_row_size];
    while(toDelete!=nullptr){
      tmp = toDelete->next;
      delete toDelete;
      toDelete = tmp;
      --size;
    }
    *(R[new_row_size]) = nullptr;
    R.Resize(new_row_size+1);
    rows = new_row_size;
  }
}

template <typename Data>
void MatrixCSR<Data>::ColumnResize(const ulong& new_column_size){
  if(new_column_size == 0){
    Clear();
  }
  else if(new_column_size > columns){
    columns = new_column_size;
  }
  else if(new_column_size < columns){
    Node** add;
    for(ulong i=0 ; i<R.Size()-1 ; ++i){
      for(Node** ptr = R[i] ; ptr!=R[i+1] ; ptr = &( (*(*ptr)).next ) ){
        if(((*ptr)->value).second) >= new_row_size) break;
      }
      if(ptr!=R[i+1]){
        //?
      }
    }
  }
}

template <typename Data>
bool MatrixCSR<Data>::ExistsCell(const ulong& r, const ulong& c) noexcept{
  if(r>=row || c>=column) return false;
  Node** ptr = R[r];
  while(ptr != R[r+1]){
    if( (**ptr).value.second == c ) return true;
    ptr = &((**ptr).next);
  }
  return false;
}

template <typename Data>
const Data& MatrixCSR<Data>::operator()(const ulong& r, const ulong& c) const{
  if(r>=row || c>=column) throw std::out_of_range("Tried to access position ["<<r<<"]["<<c<<"] in a ["<<rows<<"]["<<columns<<"] matrix!");
  else{
    Node** ptr = R[r];
    while(ptr != R[r+1]){
      if( (**ptr).value.second == c ) return (**ptr).value.first;
      ptr = &((**ptr).next);
    }
    throw std::length_error("The element does not exist!");
  }
}

template <typename Data>
Data& MatrixCSR<Data>::operator()(const ulong& r, const ulong& c){
  if(r>=row || c>=column) throw std::out_of_range("Tried to access position ["<<r<<"]["<<c<<"] in a ["<<rows<<"]["<<columns<<"] matrix!");
  else{
    Node** ptr = R[r];
    while(ptr != R[r+1]){
      if((**ptr).value.second == c){
        return (**ptr).value.first;
      }
      else if( (**ptr).value.second < c ){
        ptr = &((**ptr).next);
      }
      else if((**ptr).value.second > c){
        Node** tmp = *ptr;
        //?
      }
    }
  }
}

/* ************************************************************************** */

}
