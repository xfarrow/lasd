#include <iostream>
using namespace std;

enum class Color1{green, white, red};
enum class Color2{black, blue, brown, green, red};

enum Color3{rosso, arancione};
//enum Color4{rosso, viola}; //errore, rosso già dichiarato

int main(){

  // Posso accedere ai valori di Color3 come fossero variabili globali
  cout<<rosso<<" "<<arancione<<endl; // 0 1

  // Non posso accedere direttamente ai valori di Color1 e Color2
  //cout<<green;

  //Ma devo richiamarli in questo modo:
  cout<<(int)Color1::green<<endl; // a differenza dell'enum normale, devo fare un cast

  //if(rosso == Color1::green) //errore
  if(rosso == (int)Color1::green) cout<<"Cast obbligatorio"<<endl;

  Color1 mioColore = Color1::green;
  if(mioColore == Color1::green) cout<<"Tipi uguali direttamente confrontabili"<<endl;

}
