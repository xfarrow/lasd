/* Il riferimento è un concetto non presente in C */
#include <iostream>
using namespace std;
void lvalue();
void rvalue();
void move();
int f();

int main(){
  lvalue();
  //rvalue();
  move();
  return 0;
}
void lvalue(){
  /*  Il riferimento è come se fosse un puntatore, ma non devo usare la deferenziazione
      per accedere al contenuto. è utile quando vogliamo passare dei parametri a puntatore
      funzione per riferimento (risparmiando sulla copia) ma senza usare la sintassi
      dei puntatori */

      int var = 7;
      int& riferimento = var;
      riferimento++;
      cout<<var<<endl; // stampa 8

      /* il riferimento ha lo stesso indirizzo della variabile */
      if(&var == &riferimento)
        cout<<"Stesso indirizzo";

      // il che è esattamente equivalente a fare questo
      int var2 = 7;
      int* riferimento2 = &var2;
      (*riferimento2)++;
      cout<<*riferimento2;
}
void rvalue(){

  /*
    fare una cosa del genere
    int k = f();
    richiede una copia dal valore di ritorno di f() che sta sullo stack in k
  */

  // Per ottenere valori da una funione seza dover fare copie posso usare due metodi:
  int&& x = f(); // questo è un riferimento, come se fosse un lvalue
  int y = std::move(f());
  cout<<x<<" "<<y<<endl;

  /*
    è consigliabile utilizzare std::move() al posto di && in quanto
    x è un riferimento a un indirizzo sullo stack, e proprio per natura dello
    stack, quella stessa porzione di memoria può essere riutilizzata e dunque
    contenere risultati inattesi
  */
}
void move(){
  //La move può essere utilizzata per altri scopi

  string s1 = "hello";
  string s2 = "world";
  cout<<s1<<" "<<s2<<endl; //hello world
  s1 = move(s2);
  cout<<s1<<" "<<s2<<endl; //world

  /*
    Quello che succede è che s1 ha LO STESSO oggetto di s2 senza fare copie.
    Praticamente a s1 viene puntato il vecchio indirizzo di s2.
    Lo standard non dice cosa avviene per s2. In questo caso il valore
    di s2 viene impostato a "" (stringa vuota).

    In realtà, se si analizzano i puntatori, si vede che non avviene nulla di
    particolare. Il prof Mogavero ha detto che questo è normale perché
    quello che faccio è stampare i puntatori della classe (string) e non
    delle stringhe in sè.
  */

  int i1 = 100;
  int i2 = 50;
  i1 = move(i2);
  cout<<i1<<" "<<i2<<endl; // Qui a differenza delle stinghe, il valore di i2 viene mantenuto

  /*
    N.B. move() viene creato dai programmatori e non è un qualcosa fatto dal compilatore.
    Il move di interi e stringhe è fatto dalla libreria standard.
  */

}
int f(){return 3;}
