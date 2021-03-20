#include<iostream>
using namespace std;

void exceptions();
void noExceptFun() noexcept;
void nestedTryCatch();

int main(){
  exceptions();
  nestedTryCatch();
  try{
    noExceptFun();
  }catch(bad_alloc ex){
    cout<<"Questo punto non verrà mai raggiunto";
  }
}

void nestedTryCatch(){
  try{
    try{
      throw exception();
    }catch(exception ex){
      throw ex;
    }
  }catch(exception ex){
    cout<<"Eccezione catturata"<<endl;
  }
}

void noExceptFun() noexcept{
  /*
    Le funzioni noexcept possono lanciare eccezioni. Se sono catturate da
    un try-catch non cambia niente da una normale funzione, mentre se l'eccezione
    è fuori un try-catch allora il programma termina improvvisamente
    (anche se la funzione richiamante ha un try-catch). Ovvero le eccezioni
    non vengono mai propagate.
  */
  try{
    throw bad_alloc();
  }catch(bad_alloc){
    cout<<"OK"<<endl;
  }

  throw bad_alloc(); // il programma termina qui.
}

void exceptions(){

  /*
    Viene preso il primo catch che corrisponde all'eccezione generata
    o il primo che ne è superclasse:
  */

  try{
    throw logic_error("Errore logico");
  }catch(exception& ex){
    /*
    Se non avessi messo &, funzionava lo stesso ma non stampava "errore logico"
    (questo discorso sembra valere solo per eccezioni "exception")
    */
    cout<<"Verrà preso questo catch qui. "<<ex.what()<<endl;
  }catch(logic_error ex){
    cout<<"Questo catch non verrà preso.";
  }

  try{
    throw logic_error("Errore logico");
  }catch(logic_error ex){ // Se non avessi messo &, funzionava lo stesso ma non stampava "errore logico"
    cout<<"Verrà preso questo catch qui. "<<ex.what()<<endl;
  }catch(exception ex){
    cout<<"Questo catch non verrà preso.";
  }

  try{
    throw runtime_error("Errore a runtime");
  }catch(logic_error ex){ // Se non avessi messo &, funzionava lo stesso ma non stampava "errore logico"
    cout<<"Questo catch non verrà preso.";
  }catch(exception ex){
    cout<<"Verrà preso questo catch qui. "<<ex.what()<<endl;
  }

/*
  Eccezioni non standard
*/
  try{
    throw 1.3;
  }catch(exception ex){
    cout<<"Non verrà preso";
  }catch(...){
    cout<<"Tutte le eccezioni non-standard verranno prese qui"<<endl;
  }

}
