#include<iostream>
using namespace std;
class A{
private:
  int a = 1;
protected:
  int b = 2;
public:
  int c = 3;
  int sameVariable = 4;
};

class B : A{
public:
  int sameVariable = 9;
  void test(){
    //cout<<a<<endl; // errore, "a" è privata
    cout<<b<<endl; // 2
    cout<<c<<endl; // 3
    cout<<sameVariable<<endl; // 9
  }
};

int main(){
  B b;
  b.test();
  //cout<<b.a<<endl; //NO
  //cout<<b.b<<endl; //NO

  /*
  Benché A::c sia pubblica, non posso accedergli da qua perché di default
  l'ereditarietà viene fatta in modo privato.
  Se avessi scritto class B:public A allora avrei potuto stampare.
  */
  //cout<<b.c<<endl; //NO
  cout<<b.sameVariable<<endl; // 9

  /*
    Se l'ereditarietà fosse stata pubblica (B: public A) avrei potuto scrivere
    cout<<b.A::sameVariable<<endl;
    per eccedere a "sameVariable" di A
  */
}
