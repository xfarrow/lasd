
namespace lasd {

template <typename Data>
Vector<Data>::Vector(const ulong newsize){
  Elements = new Data[newsize]{};
  size = newsize;
}

template <typename Data>
Vector<Data>::Vector(const LinearContainer<Data>& con){
  size = con.Size();
  Elements = new Data[size]{};
  for(ulong i=0; i<size; ++i){
    Elements[i] = con[i];
  }
}

// Copy constructor
template <typename Data>
Vector<Data>::Vector(const Vector<Data>& vec){
  size = vec.size;
  Elements = new Data[size]{};
  for(ulong i=0; i<size; ++i){
    Elements[i] = vec[i];
  }
}

// Move constructor
template <typename Data>
 Vector<Data>::Vector(Vector<Data>&& vec)noexcept{
   std::swap(Elements, vec.Elements);
   std::swap(size, vec.size);
 }

 // Destructor
 template <typename Data>
  Vector<Data>::~Vector(){
    Clear();
  }

  // Copy assignment
  template <typename Data>
   Vector<Data>& Vector<Data>::operator=(const Vector<Data>& vec){
     Vector<Data>* tmpvec = new Vector<Data>(vec);
     std::swap(*tmpvec, *this);
     delete tmpvec;
     return *this;
   }

   // Move assignment
   template <typename Data>
   Vector<Data>& Vector<Data>::operator=(Vector<Data>&& vec)noexcept{
     std::swap(Elements,vec.Elements);
     std::swap(size, vec.size);
     return *this;
   }

   // Comparison operators
   template <typename Data>
   bool Vector<Data>::operator==(const Vector<Data>& vec) const noexcept{
     if(size == vec.size){
       for(ulong i=0; i<size; ++i){
         if(Elements[i] != vec.Elements[i])
            return false;
       }
       return true;
     }else{
     return false;
   }
   }


   template <typename Data>
   bool Vector<Data>::operator!=(const Vector<Data>& vec)const noexcept{
     return !(*this == vec);
   }

   template <typename Data>
   void Vector<Data>::Resize(const ulong newsize){
     if(newsize == 0){
       Clear();
     }else if(size != newsize)
     {
       ulong limit = (size < newsize) ? size : newsize;
       Data* TmpElements = new Data[newsize]{};
       for(ulong i=0; i<limit; ++i){
         std::swap(Elements[i], TmpElements[i]);
       }
       std::swap(Elements, TmpElements);
       size = newsize;
       delete[] TmpElements;
     }
   }


   template <typename Data>
   void Vector<Data>::Clear(){
      delete[] Elements;
      Elements = nullptr;
      size = 0;
   }

   template <typename Data>
     Data& Vector<Data>::Front() const {
       if(size != 0)
       {
         return Elements[0];
       }else{
         throw std::length_error("Access to an empty vector!");
       }
     }

    template <typename Data>
     Data& Vector<Data>::Back() const {
       if(size != 0)
        {
          return Elements[size - 1];
        }else{
          throw std::length_error("Access to an empty vector!");
        }
      }


    template <typename Data>
    Data& Vector<Data>::operator[](const ulong idx) const{
      if(idx < size)
      {
        return Elements[idx];
      }
      else
      {
        throw std::out_of_range("Tried to access index " + std::to_string(idx) + " but the dimension of the vector is " + std::to_string(size));
      }
    }


    template <typename Data>
    void Vector<Data>::MapPreOrder(const MapFunctor fun, void* par){
      for(ulong i=0; i<size; ++i){
        fun(Elements[i], par);
      }
    }

    template <typename Data>
    void Vector<Data>::MapPostOrder(const MapFunctor fun, void* par){
      ulong idx = size;
      while(idx > 0)
      {
        fun(Elements[--idx], par);
      }
    }


    template <typename Data>
    void Vector<Data>::FoldPreOrder(const FoldFunctor fun, const void* par, void* acc) const{
      for(ulong i=0; i<size; ++i){
        fun(Elements[i], par, acc);
      }
    }

    template <typename Data>
    void Vector<Data>::FoldPostOrder(const FoldFunctor fun, const void* par, void* acc) const{
        ulong idx = size;
        while(idx > 0){
          fun(Elements[--idx], par, acc);
        }
    }
}
