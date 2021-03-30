namespace lasd {
  // Specific constructor
  template typename<Data>
  Vector<Data>::Vector(const ulong dimension){
    Elements = new Data[dimenion] {};
    size = dimenion;
  }

  // Specific constructor
  template typename<Data>
  Vector<Data>::Vector(const LinearContainer<Data>& con){
    size = con.Size();
    Elements = new Data[size] {};
    for(ulong i ; i<size; ++i){
      Elements[i] = con[i];
    }
  }

  // Copy constructor
  template typename<Data>
  Vector<Data>::Vector(const Vector<Data>& vec){
    size = vec.size;
    Elements = new Data[size] {};
    for(ulong i=0 ; i<size; ++i){
      Elements[i] = vec[i];
    }
  }

  //Move constructor
  template typename<Data>
  Vector<Data>::Vector(Vector<Data>&& vec) noexcept{
    std::swap(Elements, vec.Elements);
    std::swap(size, vec.size);
  }

  // Destructor
  template typename<Data>
  Vector<Data>::~Vector(){
    delete[] Elements;
  }

  // Copy assignment
  template typename<Data>
  Vector<Data>& Vector<Data>::operator=(const Vector<Data>& vec){
    Vector<Data>* tmpvec = new Vector<Data>(vec);
    std::swap(*tmpvec,*this);
    delete tmpvec;
    return *this;
  }

  // Move assignment
  template typename<Data>
  Vector<Data>& Vector<Data>::operator=(Vector<Data>&& vec) noexcept{
    std::swap(Elements, vec.Elements);
    std::swap(size, vec.size);
    return *this;
  }

  // Comparison operators
  template typename<Data>
  bool Vector<Data>::operator==(const Vector<Data>& vec) const noexcept{
    if(size!=vec.size) return false;
    for(ulong i=0 ; i<size ; ++i){
      if(Elements[i] != vec.Elements[i]){
        return false;
      }
    }
    return true;
  }

  template typename<Data>
  bool Vector<Data>::operator!=(const Vector<Data>& vec) const noexcept{
    return !(*this == vec);
  }

  // Specific member function
  // template typename<Data>
  // void Vector<Data>::Resize(const ulong newsize){
  //   if(newsize == 0){
  //     Clear();
  //   }
  //   else{
  //      size = newsize;
  //     if(newsize < size){
  //       Data* tmpvec = new Data[newsize] {};
  //       for(ulong i=0;i<newsize;++i){
  //         tmpvec[i] = Elements[i];
  //       }
  //       delete[] Elements;
  //       Elements = tmpvec;
  //     }else if(newsize > size){
  //       Data* tmpvec = new Data[newsize] {};
  //       for(ulong i=0;i<size;++i){
  //         tmpvec[i] = Elements[i];
  //       }
  //       delete[] Elements;
  //       Elements = tmpvec;
  //     }
  //   }
  // }

  template typename<Data>
  void Vector<Data>::Resize(const ulong newsize){
    if(newsize == 0){
      Clear();
    }else if(size != newsize){
      ulong limit = (size < newsize) ? size : newsize;
      Data* TmpElements = new Data[newsize] {};
      for(ulong i = 0 ; i<limit ; ++i){
        std::swap(Elements[i], TmpElements[i]);
      }
      std::swap(Elements, TmpElements);
      size = newsize;
      delete[] TmpElements;
    }
}

template typename<Data>
void Vector<Data>::Clear(){
  delete[] Elements;
  Elements = nullptr;
  size = 0;
}
