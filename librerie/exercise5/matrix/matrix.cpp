
namespace lasd {

template <typename Data>
ulong Matrix<Data>::RowNumber() noexcept{
  return rows;
}

template <typename Data>
ulong Matrix<Data>::ColumnNumber() noexcept{
  return columns;
}

}
