#include<iostream>
using namespace std;
class ClassName{
  int defaultVariable; // di default è privata
public:
  int publicVariable;
protected:
  int protectedVariable;
private:
  int privateVariable;
};
int main(){
  // Dichiarazione 1
  ClassName obj;
  obj.publicVariable = 3;
  std::cout << obj.publicVariable << '\n';  
  // obj.defaultVariable = 3; // errore, di default è privata
  // obj.protectedVariable = 3; // errore
  // obj.privateVariable = 3; // errore

  // Dichiarazione 2
  ClassName obj2{};
  obj2.publicVariable = 5;
  std::cout << obj2.publicVariable << '\n';
  return 0;
}
