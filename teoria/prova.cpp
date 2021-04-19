#include<iostream>
using namespace std;
ulong Size(){
  ulong a = 6;
  return a;
}
int main(){
  ulong j = Size();
  cout<<j<<endl;
  for(long int x=(long int)Size() ; x>=0 ; --x){
    cout<<x<<endl;
  }
}
