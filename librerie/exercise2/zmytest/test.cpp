#include"test.hpp"
#include<iostream>
#include<random>
#include "../zlasdtest/test.hpp"

using namespace lasd;

void menu(){
  /*
      !!! BUG !!!
  */
  /*
  Vector<int> v(5);
  v[0] = 0;
  v[1] = 1;
  v[2] = 2;
  v[3] = 3;

  StackVec<int> sv;
  sv.Push(0);
  sv.Push(1);
  sv.Push(2);
  sv.Push(3);

  StackVec<int> sv2(sv);

  if(sv2 == v) std::cout<<"OK";
  else std::cout<<"NO";
*/

 QueueLst<int> q;
 int a =3;
 q.Enqueue(std::move(a));

}

/*
void menu(){


  unsigned short int choice;
  DataStructure chosenDataStructure;
  DataType chosenDataType;
  Implementation chosenImplementation;
  do{
    std::cout<<"1. Use your tests (to be used by the professor)"<<std::endl;
    std::cout<<"2. Use the library demo"<<std::endl;
    std::cin>>std::ws;
    std::cin>>choice;
  }while(choice!=1 && choice!=2);
  switch(choice){
    case 1:
      lasdtest();
      break;
    case 2:
      chosenDataStructure = ChooseDataStructure();
      chosenDataType = ChooseDataType();
      chosenImplementation = ChooseImplementation();
      UseChosenType(chosenDataStructure,chosenDataType, chosenImplementation);
      break;
    default:
      std::cout<<"An error has occurred"<<std::endl;
      return;
  }
}
DataStructure ChooseDataStructure(){
  unsigned short int choice;
  do{
    std::cout<<"Choose a data structure:"<<std::endl;
    std::cout<<"1. Stack"<<std::endl;
    std::cout<<"2. Queue"<<std::endl;
    std::cin>>std::ws;
    std::cin>>choice;
  }while(choice!=1 && choice!=2);
  if(choice == 1)
    return DataStructure::stack;
  else if(choice == 2)
    return DataStructure::queue;
}
DataType ChooseDataType(){
  unsigned short int choice;
  do{
    std::cout<<"Choose a data type:"<<std::endl;
    std::cout<<"1. Integer"<<std::endl;
    std::cout<<"2. Float"<<std::endl;
    std::cout<<"3. String"<<std::endl;
    std::cin>>std::ws;
    std::cin>>choice;
  }while(!(choice>0 && choice<4));
  if(choice==1)
    return DataType::integer;
  else if(choice==2)
    return DataType::ffloat;
  else if(choice==3)
    return DataType::sstring;
}
Implementation ChooseImplementation(){
  unsigned short int choice;
  do{
    std::cout<<"Choose an implementation:"<<std::endl;
    std::cout<<"1. Vector"<<std::endl;
    std::cout<<"2. List"<<std::endl;
    std::cin>>std::ws;
    std::cin>>choice;
  }while(!(choice>0 && choice<4));
  if(choice==1)
    return Implementation::vector;
  else if(choice==2)
    return Implementation::list;
}

void UseChosenType(DataStructure chosenDataStructure, DataType chosenDataType, Implementation chosenImplementation){
  if(chosenDataStructure == DataStructure::stack){
    if(chosenImplementation == Implementation::vector){
      if(chosenDataType == DataType::integer){
        lasd::StackVec<int> myvec;
        myvec = generateVectorOfIntegers();
        VectorIntegerFunctions(myvec);
      }else if(chosenDataType == DataType::ffloat){
        lasd::StackVec<float> myvec;
        myvec = generateVectorOfFloat();
        VectorFloatFunctions(myvec);
      }else if(chosenDataType == DataType::sstring){
        lasd::StackVec<std::string> myvec;
        myvec = generateVectorOfStrings();
        VectorStringFunctions(myvec);
      }
    }
  }

}
*/
