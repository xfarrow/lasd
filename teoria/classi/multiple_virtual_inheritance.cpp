#include<iostream>
using namespace std;
/*
  ereditarietà a diamante:
  A <-- B
  A <-- C
  B <-- D
  C <-- D
*/

void nonVirtualInheritance();
void virtualInheritance();
int main(){
  //nonVirtualInheritance();
  virtualInheritance();
  return 0;
}

void nonVirtualInheritance(){
  class A{
    public:
       int size = 7;
  };

  class B : public A{
    public:
       int b;
  };

  class C : public A{
  public:
    int c;
  };

  class D : public B, public C{
  public:
    int d;
  };

  /*
    Adesso B ha una copia di A, C ha una copia di A, D ha una copia di B e una
    copia di C. Implica che D ha due copie di A.
    Se provo a stampare size, cosa succede?
  */
  D obj;
  //cout<<obj.size<<endl; //request for member ‘size’ is ambiguous

  cout<<obj.B::size<<endl;
  cout<<obj.C::size<<endl;
}

void virtualInheritance(){
  class A{
    public:
       int size = 7;
  };

  class B : virtual public A{
    public:
       int b;
  };

  class C :virtual public A{
  public:
    int c;
  };

  class D : public B, public C{
  public:
    int d;
  };

  D obj;
  cout<<obj.size; // adesso posso stampare tranquillamente size

  /*
    Questo è possibile grazie al fatto che B e C ereditano A in modo virtuale,
    ovverosia, c'è solo un'istanza A condivisa tra B e C.
    https://www.cprogramming.com/tutorial/virtual_inheritance.html
  */
}
