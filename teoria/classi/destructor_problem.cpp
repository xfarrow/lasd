#include<iostream>
using namespace std;

void problema();
void soluzione();

int main(){
  //problema();
  soluzione();
  return 0;
}

void problema(){
  class A{
  public:
  int* v = new int[10];
    ~A(){
      cout<<"Richiamato distuttore di A"<<endl;
      delete[] v;
    }
  };
  class B: public A{
  public:
  char* s = new char[20];
    ~B(){
      cout<<"Richiamato distruttore di B"<<endl;
      delete[] s;
    }
  };

  A* ptr = new B(); //dato che B è anche un tipo A, questo può essere fatto.
  delete ptr; // "Richiamato distruttore di A"
  /*
    Creo un oggetto B (quindi che contiene anche A) e lo assegno a un puntatore
    a oggetto A.
    Se poi faccio "delete ptr" il compilatore va a richiamare il distruttore di A
    e non anche quello di B. Quindi l'array di char "s" rimarrà in memoria almeno
    fino al termine del programma.
  */
}

void soluzione(){
  class A{
  public:
  int* v = new int[10];
  /*
  Virtual functions ensure that the correct function is called for an object,
  regardless of the type of reference (or pointer) used for function call.
  https://www.geeksforgeeks.org/virtual-function-cpp/
  */
    virtual ~A(){ // metodo virtuale. Deve essere sempre fatto così sui distruttori.
      cout<<"Richiamato distuttore di A"<<endl;
      delete[] v;
    }
  };
  class B: public A{
  public:
  char* s = new char[20];
    ~B(){
      cout<<"Richiamato distruttore di B"<<endl;
      delete[] s;
    }
  };
  A* ptr = new B(); //dato che B è anche un tipo A, questo può essere fatto.
  delete ptr; // "Richiamato distruttore di B Richiamato distuttore di A"
}
