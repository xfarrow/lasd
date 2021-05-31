
namespace lasd {

/*

      CONTROLLARE COLUMN RESIZE
      MOVE CONSTRUCTOR

*/
/* ************************************************************************** */

template <typename Data>
MatrixCSR<Data>::MatrixCSR(){
  R.Resize(1);
  R[0] = &head;
}

template <typename Data>
MatrixCSR<Data>::MatrixCSR(const ulong r, const ulong c){
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
      (*this)(i , ((*ptr)->value).second) = ((*ptr)->value).first;
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

  toMove.R.Resize(1);
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
MatrixCSR<Data>& MatrixCSR<Data>::operator=(const MatrixCSR& toCopy){
  MatrixCSR<Data>* tmp = new MatrixCSR<Data>(toCopy);
  std::swap(*this, *tmp);
  delete tmp;
  return *this;
}

template <typename Data>
MatrixCSR<Data>& MatrixCSR<Data>::operator=(MatrixCSR&& toMove) noexcept{
  MatrixCSR<Data>* tmp = new MatrixCSR<Data>(std::move(toMove));
  std::swap(*this, *tmp);
  delete tmp;
  return *this;
}

template <typename Data>
bool MatrixCSR<Data>::operator==(const MatrixCSR& toCompare) const noexcept{
  /*
  * Check the # of rows, of columns and of elements.
  * For each row, check if the nodes in that row have the same value (data and column).
  * If one row ends before the other one, return false.
  */

  if(columns == toCompare.columns && rows == toCompare.rows && size==toCompare.size){
    for(ulong i=0 ; i<(R.Size()-1) ; ++i){
      for(Node** ptr1 = R[i] , **ptr2 = (toCompare.R)[i] ; ptr1!=R[i+1] && ptr2!=toCompare.R[i+1] ; ptr1 = &( (*(*ptr1)).next ) , ptr2 = &( (*(*ptr2)).next ) ){

        if( ( ((*ptr1)->value).first != ((*ptr2)->value).first ) || ( ((*ptr1)->value).second != ((*ptr2)->value).second )) return false;

        if( (&((*(*ptr1)).next)==R[i+1] && &((*(*ptr2)).next) != toCompare.R[i+1]) || (&((*(*ptr1)).next)!=R[i+1] && &((*(*ptr2)).next) == toCompare.R[i+1])){
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
  else if(new_row_size > rows){
    R.Resize(new_row_size+1);
    for(ulong i=rows ; i<new_row_size+1 ; ++i){
      R[i] = R[rows];
    }
    rows = new_row_size;
  }else if(new_row_size < rows){
    Node* toDelete;
    Node* tmp;
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
    Node** last;
    Node** last_not_deleted;
    Node* toDelete;
    for(ulong i=0 ; i<R.Size()-1 ; ++i){
      last = R[i+1];
      last_not_deleted = R[i];
      for(Node** ptr = R[i] ; ptr!=R[i+1] ; ptr = &( (*(*ptr)).next ) ){
        if(((*ptr)->value).second < new_column_size){
          last_not_deleted = &( (*(*ptr)).next );
        }else{
          toDelete = *ptr;
          *ptr = (*(*ptr)).next;
          delete toDelete;
          --size;
        }
      }
      for(ulong j=i+1 ; j<R.Size() ; ++j){
        if(R[j] == last){
          R[j] = last_not_deleted;
        }
      }
    }
  }
}

template <typename Data>
bool MatrixCSR<Data>::ExistsCell(const ulong& r, const ulong& c) const noexcept{
  if(r>=rows || c>=columns) return false;
  Node** ptr = R[r];
  while(ptr != R[r+1]){
    if( (**ptr).value.second == c ) return true;
    ptr = &((**ptr).next);
  }
  return false;
}

template <typename Data>
const Data& MatrixCSR<Data>::operator()(const ulong& r, const ulong& c) const{
  if(r>=rows || c>=columns) throw std::out_of_range("Tried to access an invalid position!");
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
  if(r>=rows || c>=columns) throw std::out_of_range("Tried to access an invalid position!");
  else{
    Node** ptr = R[r];
    Node** last = R[r+1]; // pointer to the pointer inside the last element of the r-th cell

    while(ptr != R[r+1] && ((**ptr).value.second <= c)){
      if((**ptr).value.second == c){
        return (**ptr).value.first;
      }
      else if( (**ptr).value.second < c ){
        ptr = &((**ptr).next);
      }
    }

    struct List<std::pair<Data,ulong>>::Node* newNode = new Node;
    struct List<std::pair<Data,ulong>>::Node* nextNode = *ptr;
    *ptr = newNode;
    newNode->next = nextNode;

    if(last == ptr){ // the newely inserted element is the last one in its row
      for(ulong i=r+1 ; i<R.Size() ; ++i){ // then for each next row
        if(R[r+1] == last){ // check if it pointed to last (it was empty)
          R[r+1] = &(newNode->next); // assign the address of the pointer of the next node
        }
        else break;
      }
    }
    return (newNode->value).first;
  }
}

template <typename Data>
void MatrixCSR<Data>::Clear(){
  List<std::pair<Data,ulong>>::Clear();
  columns = 0;
  rows = 0;
  size = 0;
  R.Resize(1);
}

template <typename Data>
void MatrixCSR<Data>::MapPreOrder(const typename MappableContainer<Data>::MapFunctor fun, void* par){
  List<std::pair<Data,ulong>>::MapPreOrder(
    [&fun](std::pair<Data,ulong>& datx, void* parx){fun(datx.first, parx); }
    , par);
}

template <typename Data>
void MatrixCSR<Data>::MapPostOrder(const typename MappableContainer<Data>::MapFunctor fun, void* par){
  List<std::pair<Data,ulong>>::MapPostOrder(
    [&fun](std::pair<Data,ulong>& datx, void* parx){fun(datx.first, parx); }
    , par);
}

template <typename Data>
void MatrixCSR<Data>::FoldPreOrder(const typename FoldableContainer<Data>::FoldFunctor fun, const void* par, void* acc) const{
  List<std::pair<Data,ulong>>::FoldPreOrder(
    [&fun](const std::pair<Data,ulong>& datx, const void* parx, void* accx) {fun(datx.first, parx, accx); }
    , par , acc);
}

template <typename Data>
void MatrixCSR<Data>::FoldPostOrder(const typename FoldableContainer<Data>::FoldFunctor fun, const void* par, void* acc) const{
  List<std::pair<Data,ulong>>::FoldPostOrder(
    [&fun](const std::pair<Data,ulong>& datx, const void* parx, void* accx) {fun(datx.first, parx, accx); }
    , par , acc);
}



/* ************************************************************************** */

}
