#include "test.hpp"
#include"../matrix/matrix.hpp"
#include"../matrix/csr/matrixcsr.hpp"
#include"../matrix/vec/matrixvec.hpp"
#include "../zlasdtest/test.hpp"
#include<iostream>
using namespace std;
using namespace lasd;


void ciao (MatrixCSR<long>& a, MatrixCSR<long>& b)
{
  std::cout << "A" << '\n';
  MatrixCSR<long> c(std::move(a));

  std::cout << "B" << '\n';
  a=std::move(b);
  a.debug();

  std::cout << "C" << '\n';
  b=std::move(c);
}

void menu(){

  unsigned short int choice;

  do{
    std::cout<<std::endl;
    std::cout<<" 1. Use your tests (to be used by the professor)"<<std::endl;
    std::cout<<" 2. Use the library demo"<<std::endl;
    cout<<endl<<" -> ";
    std::cin>>std::ws;
    std::cin>>choice;
  }while(choice!=1 && choice!=2);
  if(choice==1){
    lasdtest();
  }else{
    
  }
}
