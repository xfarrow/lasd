#include<iostream>
using namespace std;
void array();
void arrayInizializzato();
void noArray();

int main(){
  return 0;
}

void array(){
  int* ptr = nullptr;
  try{
    ptr = new int[5];
  }catch(bad_alloc ex){ // Se non riesce a creare abbastanza memoria viene sollevata un'eccezione
    cout<<"Errore allocazione memoria";
  }

  for(int i=0;i<5;i++){
    cout<<"Valore "<<i<<": ";
    cin>>ptr[i];
  }
  for(int i=0;i<5;i++){
    cout<<ptr[i];
  }
  cout<<endl;
  delete[] ptr;
}
void arrayInizializzato(){
  try{
    int* ptr = new int[3]{1,2,3};
    for(int i=0;i<3;i++){
      cout<<ptr[i];
    }
    delete[] ptr;
  }catch(bad_alloc ex){
    cout<<"Errore allocazione memoria";
  }
}
void noArray(){
  int* ptr = new int(5);
  cout<<*ptr<<endl;
  delete ptr;
}
