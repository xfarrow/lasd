#include<iostream>
using namespace std;

/*
  ereditarietà a diamante:
  A <-- B
  A <-- C
  B <-- D
  C <-- D
*/

class A{
  public:
     int a;
     A(){
       cout<<"A created"<<endl;
     }
     ~A(){
       cout<<"A destroyed"<<endl;
     }
};

class B : A{
  public:
     int b;
     B(){
       cout<<"B created"<<endl;
     }
     ~B(){
       cout<<"B destroyed"<<endl;
     }
};

class C : A{
public:
  int c;
  C(){
    cout<<"C created"<<endl;
  }
  ~C(){
    cout<<"C destroyed"<<endl;
  }
};

class D : B,C{
public:
  int d;
  D(){
    cout<<"D created"<<endl;
  }
  ~D(){
    cout<<"D destroyed"<<endl;
  }
};

int main(){
  /*
  Ogni oggetto deve avere all'interno gli oggetti ereditati. Quindi stampa:
  A created (per creare D mi serve prima B. Per creare B mi serve prima A)
  B created (creato A, posso creare B)
  A created (per creare D mi serve prima C. Per creare C mi serve prima A)
  C created (creato A, posso creare C)
  D created (creato B che contiene A e creato C che contiene A, posso creare D)
  */
  D obj;
  cout<<endl;
  return 0;

  /*
  La distruzione viene effettuata al contrario
  D destroyed
  C destroyed
  A destroyed
  B destroyed
  A destroyed
  */
}
