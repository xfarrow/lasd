#include<iostream>
#include<random>

#include<stdlib.h> // Per implementazione alla C [sconsigliato]
#include<time.h> // Per implementazione alla C [sconsigliato]

using namespace std;

void C_like_randomNumbers();
void Cpp_like_randomNumbers();
int main(){
  Cpp_like_randomNumbers();
  return 0;
}

void Cpp_like_randomNumbers(){
  default_random_engine gen(random_device{}());
  uniform_int_distribution<int> dist(0,100);
  for(int i=1;i<=15;i++){
    cout<<dist(gen)<<endl;
  }
}

void C_like_randomNumbers(){ // sconsigliato
  srand(time(NULL)); // seme (seed)
  printf("%d\n",rand());
}
