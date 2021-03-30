template <typename Pippo>
Vector<Pippo>::Vector(uint size1){
  ptr = new Pippo[size1]();
  size = size1;
  cout << "A new object is created" << endl;
}

template <typename Pippo>
Vector<Pippo>::~Vector(){
  delete[] ptr;
}

// template <typename Pippo>
// Vector<Pippo>::Pippo& operator[](const uint idx) {
//   return ptr[idx];
// }

template <typename Pippo>
ostream& operator<< (ostream& outstr, const Vector<Pippo>& a) {
  for(int i=0;i<a.size;i++) outstr<<a.ptr[i];
  return outstr;
}
