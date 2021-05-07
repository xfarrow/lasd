
#include"test.hpp"
#include<iostream>
#include<random>
#include<cmath>
#include "../zlasdtest/test.hpp"

using namespace lasd;

void menu(){

  unsigned short int choice;

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
      chosenImplementation = ChooseImplementation();
      chosenDataType = ChooseDataType();
      UseChosenType(chosenImplementation, chosenDataType);
      break;
  }
}

DataType ChooseDataType(){
  unsigned short int choice;
  do{
    std::cout<<"\nChoose a data type:"<<std::endl;
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
    std::cout<<"\nChoose an implementation for the binary tree:"<<std::endl;
    std::cout<<"1. Vector"<<std::endl;
    std::cout<<"2. Pointers"<<std::endl;
    std::cin>>std::ws;
    std::cin>>choice;
  }while(!(choice>0 && choice<3));
  if(choice==1)
    return Implementation::vector;
  else if(choice==2)
    return Implementation::pointers;
}

void UseChosenType(Implementation chosenImplementation, DataType chosenDataType){

  if(chosenImplementation == Implementation::vector){
    if(chosenDataType == DataType::integer){
      BinaryTreeVec<int> bt;
      bt = GenerateIntegerBT(bt);
      IntegerFunctions(bt);

    }else if(chosenDataType == DataType::ffloat){
      BinaryTreeVec<float> bt;
      bt = GenerateFloatBT(bt);
      FloatFunctions(bt);

    }else if(chosenDataType == DataType::sstring){
      BinaryTreeVec<string> bt;
      bt = GenerateStringsBT(bt);
      StringFunctions(bt);
    }
  }else if(chosenImplementation == Implementation::pointers){
    if(chosenDataType == DataType::integer){
      BinaryTreeLnk<int> bt;
      bt = GenerateIntegerBT(bt);
      IntegerFunctions(bt);

    }else if(chosenDataType == DataType::ffloat){
      BinaryTreeLnk<float> bt;
      bt = GenerateFloatBT(bt);
      FloatFunctions(bt);

    }else if(chosenDataType == DataType::sstring){
      BinaryTreeLnk<string> bt;
      bt = GenerateStringsBT(bt);
      StringFunctions(bt);
    }
  }
}

template <typename T>
void IntegerFunctions(T& bt){
  unsigned short int choice;
  do{
    std::cout<<std::endl<<std::endl;
    std::cout<<"Choose one of the following options:"<<std::endl;
    std::cout<<"1. Print tree"<<std::endl;
    std::cout<<"2. Check exsistence of an element"<<std::endl;
    std::cout<<"3. Product of integers less than 'n' "<<std::endl;
    std::cout<<"4. Multiply each element by 3"<<std::endl;
    std::cout<<"5. Go back"<<std::endl;
    std::cout<<"6. Quit"<<std::endl;
    std::cin>>std::ws;
    std::cin>>choice;
    std::cout<<std::endl;
    switch(choice){
      case 1:
        PrintTree(bt);
        break;
      case 2:
        CheckExistence(bt);
        break;
      case 3:
        ProductsElementsLessThan(bt);
        break;
      case 4:
        MultiplyByThree(bt);
        break;
      case 5:
        menu();
        break;
    }
  }while(choice!=5 && choice!=6);
}

template <typename T>
void FloatFunctions(T& bt){
  unsigned short int choice;
  do{
    std::cout<<std::endl<<std::endl;
    std::cout<<"Choose one of the following options:"<<std::endl;
    std::cout<<"1. Print tree"<<std::endl;
    std::cout<<"2. Check exsistence of an element"<<std::endl;
    std::cout<<"3. Sum of floats greater than 'n' "<<std::endl;
    std::cout<<"4. Cube elements"<<std::endl;
    std::cout<<"5. Go back"<<std::endl;
    std::cout<<"6. Quit"<<std::endl;
    std::cin>>std::ws;
    std::cin>>choice;
    std::cout<<std::endl;
    switch(choice){
      case 1:
        PrintTree(bt);
        break;
      case 2:
        CheckExistence(bt);
        break;
      case 3:
        SumElementsGreaterThan(bt);
        break;
      case 4:
        CubeElements(bt);
        break;
      case 5:
        menu();
        break;
    }
  }while(choice!=5 && choice!=6);
}

template <typename T>
void StringFunctions(T& bt){
  unsigned short int choice;
  do{
    std::cout<<std::endl<<std::endl;
    std::cout<<"Choose one of the following options:"<<std::endl;
    std::cout<<"1. Print tree"<<std::endl;
    std::cout<<"2. Check exsistence of an element"<<std::endl;
    std::cout<<"3. Concatenate strings whose dimension is less or equal than 'n' "<<std::endl;
    std::cout<<"4. Head concatenation of a string"<<std::endl;
    std::cout<<"5. Go back"<<std::endl;
    std::cout<<"6. Quit"<<std::endl;
    std::cin>>std::ws;
    std::cin>>choice;
    std::cout<<std::endl;
    switch(choice){
      case 1:
        PrintTree(bt);
        break;
      case 2:
        CheckExistence(bt);
        break;
      case 3:
        ConcatLessThan(bt);
        break;
      case 4:
        HeadConcat(bt);
        break;
      case 5:
        menu();
        break;
    }
  }while(choice!=5 && choice!=6);
}

/* ----- integer functions ----- */
template <typename T>
void ProductsElementsLessThan(T& tree){
  int n, acc=1;
  void (*func)(const int&, const void*, void*) = AccumulateProduct;

  cout<<"Multipy all elements of the tree whose value is less than ";
  cin>>ws>>n;

  tree.FoldBreadth(func, (void*)&n, (void*)&acc);
  cout<<"\nThe result is "<<acc<<endl<<endl;

}
void AccumulateProduct(const int& data, const void* par, void* acc){
  if(data < (*(int*)par)){
      *(int*)acc *= data;
  }
}

template <typename T>
void MultiplyByThree(T& tree){
  void (*fun)(int&, void*) = MultiplyAnElement;
  int par = 3;
  tree.MapBreadth(fun,(void*)&par);
  cout<<"The tree is:\n\n";
  PrintTree(tree);
}
void MultiplyAnElement(int& data, void* par){
  data *= *(int*)par;
}

/* ----- float functions ----- */
template <typename T>
void SumElementsGreaterThan(T& tree){
  float n, acc = 0;
  void (*func)(const float&, const void*, void*) = AccumulateSum;

  cout<<"Sum all elements of the tree whose value is greater than ";
  cin>>ws>>n;

  tree.FoldBreadth(func, (void*)&n, (void*)&acc);
  cout<<"\nThe result is "<<acc<<endl<<endl;
}
void AccumulateSum(const float& data, const void* par, void* acc){
  if(data > (*(float*)par)){
      *(float*)acc += data;
  }
}

template <typename T>
void CubeElements(T& tree){
  void (*fun)(float&, void*) = Exponentiation;
  float par = 3;
  tree.MapBreadth(fun,(void*)&par);
  cout<<"The tree is:\n\n";
  PrintTree(tree);
}
void Exponentiation(float& data, void* par){
  data = pow(data , *(float*)par );
}

/* ----- string functions ----- */
template <typename T>
void ConcatLessThan(T& tree){
  int n;
  string concatenated = "";
  void (*func)(const string&, const void*, void*) = ConcatAString;

  cout<<"Concatenate all elements of the tree whose length is less or equal than ";
  cin>>ws>>n;

  tree.FoldBreadth(func, (void*)&n, (void*)&concatenated);
  cout<<"\nThe result is "<< concatenated << endl << endl;
}
void ConcatAString(const string& data, const void* par, void* acc){
  if( ((int)data.length()) <= ((*(int*)par)) ){
    *(string*)acc = *(string*)acc + "-" + data;
  }
}

template <typename T>
void HeadConcat(T& tree){
  void (*fun)(string&, void*) = HeadConcatMapAux;
  string par;

  cout<<"Concatenate in front the following string: ";
  cin>>ws;
  cin>>par;

  tree.MapBreadth(fun,(void*)&par);
  cout<<"The tree is:\n\n";
  PrintTree(tree);
}
void HeadConcatMapAux(string& data, void* par){
  data = *(string*)par + data;
}

/* ----- shared functions ----- */
template <template <typename...> class Tree, typename DTType>
void PrintTree(Tree<DTType>& tree){
  void (*PrinterFunction) (DTType&, void*) = PrintSingleElement;

  cout<<"Pre order:\n";
  tree.MapPreOrder(PrinterFunction, nullptr);
  cout<<endl<<endl;

  cout<<"In oder:\n";
  tree.MapInOrder(PrinterFunction, nullptr);
  cout<<endl<<endl;

  cout<<"Post order\n";
  tree.MapPostOrder(PrinterFunction, nullptr);
  cout<<endl<<endl;

  cout<<"Breadth order\n";
  tree.MapBreadth(PrinterFunction, nullptr);
  cout<<endl<<endl;
}

template <typename Data>
void PrintSingleElement(Data& data, void* _){
  std::cout << data << " ";
}

template <template <typename...> class Tree, typename DTType>
void CheckExistence(Tree<DTType>& tree){
  DTType elementToLookFor;
  cout<<"\n\nCheck existence in the tree of: ";
  cin>>ws;
  cin>>elementToLookFor;
  cout<<"The element " << ( (!tree.Exists(elementToLookFor))? "does not " : "") << "exists\n\n";
}


/* ----- generator functions ----- */

template <typename T>
T GenerateIntegerBT(T& bt){
  ulong dim = getDimension();
  Vector<int> tmp(dim);

  default_random_engine gen(random_device{}());
  uniform_int_distribution<int> dist(0,1000);

  cout<<"\n\nElements in the tree (in breadth order):\n";
  for(ulong i=0 ; i<dim ; ++i){
    tmp[i] = dist(gen);
    cout<<tmp[i]<<" ";
  }
  cout<<endl<<endl;

  T tree(tmp);
  return tree;
}

template <typename T>
T GenerateFloatBT(T& bt){
  ulong dim = getDimension();
  Vector<float> tmp(dim);

  default_random_engine gen(random_device{}());
  uniform_real_distribution<double> distr(0,5);

  cout<<"\n\nElements in the tree (in breadth order):\n";
  for(unsigned long i = 0; i < dim; ++i){
    tmp[i] = (round(distr(gen)*10000))/100;
    cout<<tmp[i]<<" ";
  }
  cout<<endl<<endl;

  T tree(tmp);
  return tree;
}

template <typename T>
T GenerateStringsBT(T& bt){
  ulong dim = getDimension();
  Vector<string> tmp(dim);

  default_random_engine gen(random_device{}());
  uniform_int_distribution<int> dist(1,5);

  cout<<"\n\nElements in the tree (in breadth order):\n";
  for(ulong i = 0; i < dim; ++i){
    tmp[i] = generateRandomString(dist(gen));
    cout<<tmp[i]<<" ";
  }
  cout<<endl<<endl;

  T tree(tmp);
  return tree;

}

string generateRandomString(ulong dim){
  default_random_engine gen(random_device{}());
  uniform_int_distribution<char> character('a','z');
  char newString[dim+1];
  for(int i=0;i<dim;i++){
    newString[i]=character(gen);
  }
  newString[dim]='\0';
  return newString;
}

ulong getDimension(){
  ulong dimension;
  std::cout<<"Insert the dimension: ";
  std::cin>>dimension;
  return dimension;
}
