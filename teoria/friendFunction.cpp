#include<iostream>
using namespace std;

struct Studente{
  friend void printSecureNumber(Studente); // posso mettere questa linea ovunque all'interno della struct

  string nome;
  string cognome;
  private:
        int secureNumber = 999;
};
void printSecureNumber(Studente s){
  cout<<s.secureNumber<<endl;
}
int main(){
  Studente st;
  printSecureNumber(st);
  return 0;
}
