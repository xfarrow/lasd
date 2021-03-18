#include<iostream>
using namespace std;
int main(){
  string s1 = "hello";
  string s2 = "world";
  cout<<"Stringa 1: "<<s1<<endl<<"Stringa 2: "<<s2<<endl;
  cout<<"PTR Stringa 1: "<<&s1<<endl<<"PTR Stringa 2: "<<&s2<<endl<<endl;
  s1 = move(s2);

  cout<<"Stringa 1: "<<s1<<endl<<"Stringa 2: "<<s2<<endl;
  cout<<"PTR Stringa 1: "<<&s1<<endl<<"PTR Stringa 2: "<<&s2<<endl<<endl;

  s2 = "cacca";
  cout<<"Stringa 1: "<<s1<<endl<<"Stringa 2: "<<s2<<endl;

  return 0;
}
