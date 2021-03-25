#include<iostream>
using namespace std;
class ClassName{
public:
  int x;
  int* v = new int[10];
  ~ClassName(){ // ~ si fa con ALT GR + ì
    delete[] v;
    cout<<"BYE!";
  }
};
int main(){
ClassName obj;
ClassName* ptr = new ClassName();
delete ptr; // viene chiamato il distruttore di ClassName per cancellare ptr;
return 0; // viene chiamato il distruttore di ClassName per cancellare obj
}
