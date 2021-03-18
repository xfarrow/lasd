/**** puntatori ****/

#include <iostream>
using namespace std;

// prototipi di funzione
void assegnazione();
void dimensione_puntatore();
void puntatori_const();
void casting();

int main(){
  casting();
  return 0;
}

void casting(){
  int i = -1;
  int* ptr_int = &i;
  /*  trasformo il puntatore da puntatore a intero a puntatore a unsigned intero
      quindi stamperà 4294967295 perchè interpreta il valore puntato come unsigned  */
  cout<<*((unsigned int*)ptr_int)<<endl;

  void* ptr_void = &i;
  // cout<<*ptr_void<<endl; //errore. non sa come interpretare il valore puntato da ptr_void
  cout<<*((int*)ptr_void)<<endl; //ok

  /* Il C++ offre lo static_cast ed è più restrittivo rispetto al cast normale */
  cout<<*(static_cast<int*>(ptr_void)); // Il tipo void* può sempre essere castato
  //cout<<*(static_cast<unsigned int*>(ptr_int)); // errore. Non avrebbe dato errore con il cast normale
}

void puntatori_const(){
  const char carattere_const = 'a';
  char carattere = 'b';

  /* ----- CONST TYPE* PTR ----- */
  // Se una variabile è const anche il suo puntatore deve esserlo

  // char* ptr = carattere_const;       // errore
  const char* ptr = &carattere_const; // OK
  /*  Se un puntatore è const char*, non  posso modificare il valore della
      variabile, ma posso modificare il valore del puntatore in sè */
  // *ptr = 'z'; //errore
  ptr = &carattere; //ok

  /* ----- CONST TYPE* CONST PTR ----- */
  /* const char* const vuol dire che è un puntatore const che non
  può neanche modificare il valore del puntatore in sè */

  const char* const ptr2 = &carattere_const;
  // *ptr2 = 'z'; //errore
  // ptr2 = &carattere; //errore

  /* ----- TYPE* CONST PTR ----- */
  /*  Punta a tipi non-const ma il suo valore non può essere cambiato,
      ovvero non può puntare a locazioni diverse rispetto alla dimensione_puntatore
      inizializzazione */

  char* const ptr3 = &carattere;
  *ptr3 = 'k'; // OK
  char carattere2 = 's';
  //ptr3 = &carattere2; // errore
}

void dimensione_puntatore(){
  /*  la dimensione di un puntatore non dipende dal tipo a cui punta
      dato che deve semplicemente essere abbastanza grande per individuare
      una cella di memoria  */

    long double* ptr1 = nullptr;
    char* ptr2 = nullptr;

    cout<<sizeof(ptr1)<<endl<<sizeof(ptr2)<<endl;
}

void assegnazione(){
  char carattere = 'a';
  char* ptr = nullptr;  // equivalente al NULL di C

  ptr = &carattere;     // assegno a ptr l'indirizzo di carattere

  cout<<"carattere: "<<carattere<<endl;
  cout<<"deferenziazione di ptr: "<<*ptr<<endl;
}
