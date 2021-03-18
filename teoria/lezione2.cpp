#include<iostream>
#include "header.hpp"
using namespace std;
int main(){

  /* Puntatori */

  const int x = 5;
  const int y = 3;

  const int* p = &x;
  //*p = 3; // errore
  p = &y; //OK

  const int* const p2 = &x;
  //*p2 = 3; //errore
  //p2 = &y; //errore

  /* Casting */

  char c = 'a';
  void* p3 = &c;
  //cout<<*p3; //errore (non conosce il tipo)
  //cout<<*((char*)p3)<<endl; //OK
  //cout<<*(static_cast<char*>(p3))<<endl; //miglior modo

  /* Riferimenti */

  int d = 7;
  int& e = d;
  e++;
  //cout<<d<<endl;

//  int a = function(); //OK
  //int& b = function(); //errore cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
  const int& b = function(); // perché funziona?
  //cout<<b<<endl;
  string s1 = "hello";
  string s2 = "world";

  cout<<"Address of s2 is"<<&s2<<endl;
  s1 = std::move(s2);
  cout<<"Address of s1 is"<<&s1<<endl;

  int r = move(function()); //ok
  cout<<r<<endl;

  int&& r2 = move(function()); //ok

  return 0;
}
