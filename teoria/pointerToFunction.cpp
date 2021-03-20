#include<iostream>
#include <functional> // Solo per puntatori alla C++

using namespace std;

int func(int a);
void C_like_functionPointer();
void C_like_typedef_functionPointer();
void CPP_like_functionPointer();
void CPP_like_typedef_functionPointer();

int main(){
  C_like_functionPointer();
  C_like_typedef_functionPointer();
  CPP_like_functionPointer();
  CPP_like_typedef_functionPointer();
  return 0;
}

int func(int a){
  return 2*a;
}

void CPP_like_typedef_functionPointer(){
  // funptrType è un nuovo tipo che definisce puntatori a funzione di tipo int f(int)
  typedef function<int(int)> funptrType;
  funptrType ptr = func;
  cout<<ptr(3)<<endl;
  // cout<<(*funptr)(3); //illegale alla C++
}

void CPP_like_functionPointer(){
  // funptr è un PUNTATORE a funzione
  function<int(int)> funptr = nullptr;
  funptr = &func;
  funptr = func;
  cout<<funptr(3);
  // cout<<(*funptr)(3); //illegale alla C++
}

void C_like_functionPointer(){
  // sto creando un puntatore a funzione
  int (*funptr)(int);
  funptr = &func;
  funptr = func; //equivalente
  cout<<(*funptr)(3)<<" "<<funptr(3)<<endl;
}
void C_like_typedef_functionPointer(){
  // sto creando un nuovo tipo: puntatore a funzione int che prende in int in ingresso
  typedef int (*funptrType)(int);
  funptrType pointer;
  pointer = &func;
  pointer = func; // equivalente
  cout<<(*pointer)(3)<<" "<<pointer(3)<<endl;
}
