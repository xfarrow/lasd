#include<iostream>
using namespace std;

void testOperators();
void testConstructors();

class Punto{
public:
  float x,y;

  /**** COSTRUTTORI ****/
  Punto() = default; // costruttore di default;
  Punto(float x1, float y1){ // costruttore
    x = x1;
    y = y1;
  }
  Punto(const Punto& puntoDaCopaire){ // costruttore di copia
    x = puntoDaCopaire.x;
    y = puntoDaCopaire.y;
  }
  Punto(Punto&& puntoDaMuovere) noexcept{ // move constructor

  }

  /**** DISTRUTTORE ****/
  ~Punto(){
    cout<<"BYE!"<<endl;
  }

  /**** OPERATORI ****/
  bool operator==(const Punto& obj) const noexcept{
    return ((x==obj.x) && (y==obj.y));
  }
  int operator[](const uint position){
    switch (position) {
      case 0:
        return x;
        break;
      case 1:
        return y;
        break;
      default:
        return -1;
    }
  }
  Punto& operator=(const Punto& p){ // operatore di assegnamento COPY
    // ?
  }
  Punto& operator=(Punto&& p) noexcept{ // operatore di assegnamento MOVE
    // ?
  }
};

ostream& operator<<(ostream& outstr, const Punto& p) {
  return outstr<<p.x<<";"<<p.y;
}
istream& operator>>(istream& inputStream, Punto& p){
  return inputStream>>p.x>>p.y;
}

int main(){
  testConstructors();
  testOperators();
  return 0;
}

void testConstructors(){
  Punto p1; // OK, costruttore di default
  //Punto px(); // NO! Il compilatore si inceppa (fa eseguire ma non accedere ai dati)
  Punto p2{}; // OK, costruttore di default
  Punto p3(1,2); // OK
  Punto p4(3,4); // OK

  Punto p5(p3); //OK, costruttore di copia
  Punto p6{p4}; // OK; costruttore di copia
  cout<<p5<<endl<<p6<<endl;
}

void testOperators(){
  Punto p1,p2;
  cin>>p1;
  cout<<"Coordinata X: "<<p1[0]<<" Coordinata Y: "<<p1[1]<<endl;
  cin>>p2;
  cout<<"Coordinata X: "<<p2[0]<<" Coordinata Y: "<<p2[1]<<endl;
  if(p1==p2){
    cout<<"I due punti sono uguali"<<endl;
  }else{
    cout<<"I due punti non sono uguali"<<endl;
  }
}
