#include<iostream> // include anche <string>
using namespace std;

int main(){
  string s1 = "Alan";
  string s2 = {"Turing"};
  string s3{"Kurt"};
  string s4("Godel");

  string stringa_concatenata = s1 + s3; // l'operatore + è stato overloaded per le stringhe
  cout<<stringa_concatenata<<endl;

  string input_string;
  cin>>input_string; // se si inserisce "Alan Turing" verrà preso solo "Alan"
  cout<<input_string<<endl;
  getline(cin,input_string); // se si inserisce "Alan Turing" verrà preso "Alan Turing"
  cout<<input_string<<endl;

  /*
      - - - ATTENZIONE - - -
      Nell'esempio  precedente se si inserisce "Alan Turing" stamperà solo "Alan",
      però non richiede un nuovo inserimento su getline() perché " Turing" rimane
      nel buffer e infatti stampa " Turing".
  */

  string s6 = "stringamoltolunga";
  cout<<s6.size()<<endl;
  s6.clear();
  cout<<s6<<endl;
  cout<<s6.size()<<endl;
  return 0;

}
