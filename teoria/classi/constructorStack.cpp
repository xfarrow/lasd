#include<iostream>
using namespace std;
class A{
public:
  int x;
  A(){
    cout<<"Sono nel costruttore di A"<<endl;
    x = x+1;
  }
  A(const A& a){
    cout<<"Sono nel costruttore di copia di A"<<endl;
  }
};
class B:public A{
public:
  B(){
    cout<<"Sono nel costruttore di B"<<endl;
    x+=100;
  }
  B(const B& b){
    cout<<"Sono nel costruttore di copia di B"<<endl;
  }
};
class C:public B{
public:
  C(){
    cout<<"Sono nel costruttore di C"<<endl;
    x+=1000;
  }
  C(const C& c){
    cout<<"Sono nel costruttore di copia di C"<<endl;
  }
};
int main(){
  /*
  Sono nel costruttore di A
  Sono nel costruttore di B
  Sono nel costruttore di C
  */
  C obj;
  
  cout<<endl;

  /*
  Sono nel costruttore di A
  Sono nel costruttore di B
  Sono nel costruttore DI COPIA di C
  */
  C obj2(obj);
  return 0;
}
