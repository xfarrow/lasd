#include<iostream>
using namespace std;

enum class Color{red, white, green, black};

ostream& operator<<(ostream& outputStream, const Color& color){ //la keyword const non è obbligatoria, ma meglio metterla
  switch(color){
    case Color::red:
      outputStream<<"Rosso";
      break;
    case Color::white:
      outputStream<<"Bianco";
      break;
    case Color::green:
      outputStream<<"Verde";
      break;
    case Color::black:
      outputStream<<"Nero";
  }
  return outputStream;
}
int main(){
  Color myColor = Color::red;
  cout<<myColor<<endl;
  return 0;
}
