#include <iostream>
using namespace std;
struct Studente{
  string nome, cognome, matricola;
  int annoCorso;
};
ostream& operator<<(ostream& outputStream, const Studente& st){ //la keyword const non è obbligatoria, ma meglio metterla
  return outputStream<<st.nome<<" "<<st.cognome<<" "<<st.matricola<<" "<<st.annoCorso<<endl;
}
istream& operator>>(istream& inputStream, Studente& st){
  return inputStream>>st.nome>>st.cognome>>st.matricola>>st.annoCorso;
}
int main(){
  Studente s;
  cin>>s;
  cout<<s;
}
