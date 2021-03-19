#include <iostream>
using namespace std;
void differentStructSize();
void studentStruct();

int main(){
  studentStruct();
  return 0;
}

void studentStructWithConstructor(){

  struct StudentNoDefaultConstructor{
    string nome, cognome, matricola;
    int annoCorso;

    StudentNoDefaultConstructor(string n, string c, string m, int a){
      nome = m;
      cognome = c;
      matricola = m;
      annoCorso = a;
    }
  };
  struct StudentNoDefaultConstructor st1{"Alan","Turing","N86000000",1}; //OK
  //struct StudentNoDefaultConstructor st2; //errore. no default constructor

  /* Qui lascia compilare la dichiarazione di st3 ma non permette di lavorarci
    su, causa costruttore di default mancante. */
  struct StudentNoDefaultConstructor st3();
  //st3.nome = "Planck";
  //cout<<st3.nome;

  struct StudentOnlyDefaultConstructor{
    string nome, cognome, matricola;
    int annoCorso;
    StudentOnlyDefaultConstructor() = default;
  };

  struct StudentOnlyDefaultConstructor st4;
  struct StudentOnlyDefaultConstructor st5();
  //struct StudentOnlyDefaultConstructor st6{"Alan","Turing","N86000000",1}; errore
}

void studentStruct(){
  struct Student{
    string nome, cognome, matricola;
    int annoCorso;
  };
  struct Student st1{"Alan","Turing","N86000000",1};
  struct Student st2 = {"Kurt","Godel","N86000001",1}; // non preferibile
  //Student st3("Kurt","Godel","N86000001",1); // errore, richiede esplicitamente un costruttore
  struct Student st4;
  struct Student st5();
  cout<<st1.cognome<<" e "<<st2.cognome<<" studiano alla Federico II"<<endl;
}

void differentStructSize(){
  /*
    A causa della struttura di un elaboratore, due struct con gli stessi elementi
    potrebbero avere una dimensione diversa.
    Con g++ 7.5.0 senza opzioni di ottimizzazione S1 pesa 96 byte, mentre S2
    pesa 64 byte.
  */
  struct S1{
    char c1;
    int i;
    char c2;
  };
  struct S2{
    char c1,c2;
    int i;
  };
  cout<<sizeof(S1)<<" "<<sizeof(S2)<<endl; //12 8
}
