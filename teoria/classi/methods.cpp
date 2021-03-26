/*
  I metodi in C++ sono siffatti:
  [virtual] type nomeMetodo(parametri) [const] [noexcept] [override] [=assignment]

  virtual:
  const: il metodo non può modificare le variabili della ClassName
  noexcept: già visto. Non può sollevare eccezioni pena l'aborto del programma
  override: il metodo sovrascrive un metodo nella gerarchia
  assignment: può essere:
              = 0: pure virtual. A questo livello l'implementazione di questo metodo non esiste
              = default: ammesso solo per cost. e dist. che dice di creare quelli di default
              =delete: elimina un metodo precedentemente scritto nella gerarchia
*/
/*
  Il corpo di una funzione può essere messo anche fuori dalla classe:
*/
#include<iostream>
class ClassName{
private:
  int y = 5;
public:
  int x = 3;

  int aggiungiX(int); // dichiarazione funzione

  int aggiungiY(int); // dichiarazione funzione
  friend int aggiungiY(int); // dichiarazione friendship
};
/*
  NB: in questo caso x deve essere dichiarata pubblica. Se fosse stato un metodo
      all'interno della classe allora avrebbe potuto avere accesso anche se x
      fosse stata privata
*/
int ClassName::aggiungiX(int parametro){
  x+=parametro;
}
/*
  Oppure si può dichiarare la friendship per accedere a variabili private/protette
*/
int ClassName::aggiungiY(int parametro){
  y+=parametro;
  std::cout<<y<<std::endl;
}
int main(){
  ClassName obj;
  obj.aggiungiX(7);
  obj.aggiungiY(9);
  std::cout<<obj.x<<std::endl;
  return 0;
}
