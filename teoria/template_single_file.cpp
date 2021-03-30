#include <iostream>
using namespace std;

 template <typename Pippo>
 class A;

 template <typename Pippo>
 ostream& operator<< (ostream& outstr, const A<Pippo>& a);

template <typename Pippo> // Lo chiamo Pippo per far capire che il nome è irrilevante
class A{
public:
  Pippo* ptr = nullptr;
  uint size;
  A(uint size1){
    ptr = new Pippo[size1]();
    size = size1;
    cout << "A new object is created" << endl;
  }
  ~A(){
    delete[] ptr;
  }
  Pippo& operator[](const uint idx) {
    return ptr[idx];
  }

  friend ostream& operator<< <>(ostream& outstr, const A<Pippo>&);

/*
  template <typename DataX>
  friend ostream& operator<<(ostream&, const A<DataX>&);
*/
};

template <typename Pippo>
ostream& operator<< (ostream& outstr, const A<Pippo>& a) {
  for(int i=0;i<a.size;i++) outstr<<a.ptr[i];
  return outstr;
}

/*
template <typename DataX>
ostream& operator<< (ostream& outstr, const A<DataX>& a) {
  for(int i=0;i<a.size;i++) outstr<<a.ptr[i];
  return outstr;
}
*/

int main(){
  A<char> str(50);
  A<int> v(10);

  str[1] = 'k';
  v[2] = 3;

  cout<<str[1]<<endl;
  cout<<v[2]<<endl;
  cout<<v;
  return 0;
}

/*
  NB: per fare l'override della funzione operator<< (e equiv. di operator>>)
      ci sono due metodi:

      1.  Usare quello che non è commentato, ovvero questo programma. (consigliato)

      2.
        a.  Cancellare/commentare righe 4-8

            4 template <typename Pippo>
            5 class A;

            7 template <typename Pippo>
            8 ostream& operator<< (ostream& outstr, const A<Pippo>& a);

        b.  Cancallare/commentare 35-39

            35 template <typename Pippo>
            36 ostream& operator<< (ostream& outstr, const A<Pippo>& a) {
            37 for(int i=0;i<a.size;i++) outstr<<a.ptr[i];
            38 return outstr;
            39 }

       c.   e decommentare ciò che è commentato.

       Perché? Non lo so.
*/
