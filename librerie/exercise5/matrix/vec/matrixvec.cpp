
namespace lasd {

template <typename Data>
MatrixVec<Data>::MatrixVec(ulong r, ulong c){
  rows = r;
  columns = c;
  size = r*c;
  Elements = new Data[size]{};
}

template <typename Data>
MatrixVec<Data>::MatrixVec(const MatrixVec& toCopy){
  rows = toCopy.rows;
  columns = toCopy.columns;
  size = toCopy.rows * toCopy.columns;
  Elements = new Data[size]{};
  for(ulong i=0 ; i<size ; ++i){
    Elements[i] = toCopy.Elements[i];
  }
}

template <typename Data>
MatrixVec<Data>::MatrixVec(MatrixVec&& toMove) noexcept{
  std::swap(rows, toMove.rows);
  std::swap(columns, toMove.columns);
  std::swap(size, toMove.size);
  std::swap(Elements, toMove.Elements);
}

template <typename Data>
MatrixVec<Data>::~MatrixVec(){
  Clear();
}

template <typename Data>
MatrixVec& MatrixVec<Data>::operator=(const MatrixVec& toCopy){
  Clear();
  rows = toCopy.rows;
  columns = toCopy.columns;
  size = toCopy.rows * toCopy.columns;
  Elements = new Data[size]{};
  for(ulong i=0 ; i<size ; ++i){
    Elements[i] = toCopy.Elements[i];
  }
  return *this;
}

template <typename Data>
MatrixVec& MatrixVec<Data>::operator=(MatrixVec&& toMove) noexcept{
  Clear();
  std::swap(rows, toMove.rows);
  std::swap(columns, toMove.columns);
  std::swap(size, toMove.size);
  std::swap(Elements, toMove.Elements);
  return *this;
}

template <typename Data>
bool MatrixVec<Data>::operator==(const MatrixVec& toCompare) const noexcept{
  if(rows == toCompare.rows && columns == toCompare.columns){
    return Vector<Data>::operator==(toCompare);
  }else{
    return false;
  }
}

template <typename Data>
bool MatrixVec<Data>::operator!=(const MatrixVec& toCompare) const noexcept{
  return !(*this == toCompare);
}

template <typename Data>
void MatrixVec<Data>::RowResize(const ulong newdim){
  Vector<Data>::Resize(newdim);
}

template <typename Data>
void MatrixVec<Data>::ColumnResize(const ulong& new_column_dim){

  if(new_column_dim == 0){
    Clear();
  }
  else if(new_column_dim != columns){

    Data* tmp = new Data[rows * new_column_dim]{};

    if(new_column_dim > columns){
      for(ulong i=0 ; i<r ; ++i){
        for(ulong j=0 ; j<new_column_dim ; ++j){
          if(ExistsCell(i,j)) tmp[(i*new_column_dim)+j] = (*this)(i,j);
        }
      }
    }else if(new_column_dim < columns){
      for(ulong i=0 ; i<r ; ++i){
        for(ulong j=0 ; j<new_column_dim ; ++j){
          tmp[(i*new_column_dim)+j] = (*this)(i,j);
        }
      }
    }

    size = rows * new_column_dim;
    columns = new_column_dim;
    std::swap(Elements, tmp);
    delete[] tmp;
  }
}

template <typename Data>
bool MatrixVec<Data>::ExistsCell(const ulong& r, const ulong& c) noexcept override{
  return (r<rows && c<columns);
}

template <typename Data>
const Data& MatrixVec<Data>::operator()(const ulong& r, const ulong& c) const{
  if(ExistsCell(r,c)) return Elements[(r*columns)+c];
  else throw std::out_of_range("Tried to access position ["<<r<<"]["<<c<<"] in a ["<<rows<<"]["<<columns<<"] matrix!");
}

template <typename Data>
Data& MatrixVec<Data>::operator()(const ulong& r, const ulong& c){
  if(ExistsCell(r,c)) return Elements[(r*columns)+c];
  else throw std::out_of_range("Tried to access position ["<<r<<"]["<<c<<"] in a ["<<rows<<"]["<<columns<<"] matrix!");
}

template <typename Data>
void MatrixVec<Data>::Clear(){
  Vector<Data>::Clear();
  rows = 0;
  columns = 0;
}

}
