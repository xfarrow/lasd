#include <iostream>
using namespace std;

 template <typename Pippo>
 class Vector;

 template <typename Pippo>
 ostream& operator<< (ostream& outstr, const Vector<Pippo>& a);

template <typename Pippo> // Lo chiamo Pippo per far capire che il nome è irrilevante
class Vector{
public:
  Pippo* ptr = nullptr;
  uint size;

  Vector(uint);
  ~Vector();

  friend ostream& operator<< <>(ostream& outstr, const Vector<Pippo>&);
};
#include"vector.cpp"
