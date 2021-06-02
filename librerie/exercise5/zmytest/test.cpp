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
    MatrixCSR<long> mat;
    mat.RowResize(5);
    mat.ColumnResize(5);

    mat(0,1) = 1;
    mat(0,3) = 4;
    mat(1,0) = 2;
    mat(1,4) = 8;
    mat(2,1) = 3;
    mat(2,2) = 5;
    mat(3,4) = 9;
    mat(4,1) = 6;
    mat(4,3) = 7;
    mat(4,0) = 13;

    mat.ColumnResize(2);

    MatrixCSR<long> copmat;
    copmat = std::move(mat);
  }
}
