#include"test.hpp"
#include<iostream>
#include<random>
#include<cmath>
#include "../zlasdtest/test.hpp"

using namespace lasd;
using namespace std;

void menu(){

  unsigned short int choice;
  DataType chosenDataType;

  do{
    std::cout<<std::endl;
    std::cout<<" 1. Use your tests (to be used by the professor)"<<std::endl;
    std::cout<<" 2. Use the library demo"<<std::endl;
    cout<<endl<<" -> ";
    std::cin>>std::ws;
    std::cin>>choice;
  }while(choice!=1 && choice!=2);
  switch(choice){
    case 1:
      lasdtest();
      break;
    case 2:
      chosenDataType = ChooseDataType();
      UseChosenType(chosenDataType);
      break;
  }
}

DataType ChooseDataType(){
  unsigned short int choice;
  do{
    std::cout<<"\nChoose a data type:"<<std::endl;
    std::cout<<" 1. Integer"<<std::endl;
    std::cout<<" 2. Float"<<std::endl;
    std::cout<<" 3. String"<<std::endl;
    cout<<endl<<" -> ";
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

void UseChosenType(DataType chosenDataType){
  if(chosenDataType == DataType::integer){
    BST<int> bst;
    bst = GenerateIntegerBST(bst);
    IntegerFunctions(bst);

  }else if(chosenDataType == DataType::ffloat){
    BST<float> bst;
    bst = GenerateFloatBST(bst);
    FloatFunctions(bst);

  }else if(chosenDataType == DataType::sstring){
    BST<string> bst;
    bst = GenerateStringsBST(bst);
    StringFunctions(bst);
  }
}

/* ----- integer functions ----- */

template <typename Data>
void IntegerFunctions(BST<Data>& bst){
  unsigned short int choice;
  do{
    std::cout<<std::endl<<std::endl;
    std::cout<<"Choose one of the following options:"<<std::endl;
    std::cout<<" 1.  Print tree"<<std::endl;
    std::cout<<" 2.  Check exsistence of an element"<<std::endl;
    std::cout<<" 3.  Product of integers less than 'n' "<<std::endl;
    std::cout<<" 4.  Insert an element [Insert]"<<std::endl;
    std::cout<<" 5.  Remove an element [Remove]"<<std::endl;
    std::cout<<" 6.  Print the minimum element [Min]"<<std::endl;
    std::cout<<" 7.  Print the minimum element and remove it [Min and Remove]"<<std::endl;
    std::cout<<" 8.  Remove the minimum element [Remove Min]"<<std::endl;
    std::cout<<" 9.  Print the maximum element [Max]"<<std::endl;
    std::cout<<" 10. Print the maximum element and remove it [Max and Remove]"<<std::endl;
    std::cout<<" 11. Remove the maximum element [Remove Max]"<<std::endl;
    std::cout<<" 12. Print the predecessor of a given element [Predecessor]"<<std::endl;
    std::cout<<" 13. Remove and print the predecessor of a given element [Predecessor and Remove]"<<std::endl;
    std::cout<<" 14. Remove the predecessor of a given element [Remove Predecessor]"<<std::endl;
    std::cout<<" 15. Print the predecessor of a given element [Successor]"<<std::endl;
    std::cout<<" 16. Remove and print the successor of a given element [Successor and Remove]"<<std::endl;
    std::cout<<" 17. Remove the successor of a given element [Remove Successor]"<<std::endl;
    std::cout<<" 18. Node-level operations (debug)"<<std::endl;
    std::cout<<" 19. Go back"<<std::endl;
    std::cout<<" 20. Quit"<<std::endl;
    cout<<endl<<" -> ";

    std::cin>>std::ws;
    std::cin>>choice;
    std::cout<<std::endl;
    switch(choice){
      case 1:
        PrintTree(bst);
        break;
      case 2:
        CheckExistence(bst);
        break;
      case 3:
        ProductsElementsLessThan(bst);
        break;
      case 4:
        InsertElement(bst);
        break;
      case 5:
        RemoveElement(bst);
        break;
      case 6:
        PrintMinimum(bst);
      break;
      case 7:
        PrintMinimumNDelete(bst);
      break;
      case 8:
        RemoveMin(bst);
      break;
      case 9:
        PrintMaximum(bst);
      break;
      case 10:
        PrintMaximumNDelete(bst);
      break;
      case 11:
        RemoveMax(bst);
      break;
      case 12:
        PrintPredecessor(bst);
      break;
      case 13:
        PredecessorNRemove(bst);
      break;
      case 14:
        RemovePredecessor(bst);
      break;
      case 15:
        PrintSuccessor(bst);
        break;
      case 16:
        SuccessorNRemove(bst);
        break;
      case 17:
        RemoveSuccessor(bst);
        break;
      case 18:
      try{
        NodeOperations(bst.Root());
      }catch(length_error exc){
        cout<<exc.what();
      }
      break;
      case 19:
        menu();
    }
  }while(choice!=19 && choice!=20);
}

template <typename Data>
void ProductsElementsLessThan(BST<Data>& tree){
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

/* ----- float functions ----- */
template <typename Data>
void FloatFunctions(BST<Data>& bst){
  unsigned short int choice;
  do{
    std::cout<<std::endl<<std::endl;
    std::cout<<"Choose one of the following options:"<<std::endl;
    std::cout<<" 1.  Print tree"<<std::endl;
    std::cout<<" 2.  Check exsistence of an element"<<std::endl;
    std::cout<<" 3.  Sum of floats greater than 'n' "<<std::endl;
    std::cout<<" 4.  Insert an element [Insert]"<<std::endl;
    std::cout<<" 5.  Remove an element [Remove]"<<std::endl;
    std::cout<<" 6.  Print the minimum element [Min]"<<std::endl;
    std::cout<<" 7.  Print the minimum element and remove it [Min and Remove]"<<std::endl;
    std::cout<<" 8.  Remove the minimum element [Remove Min]"<<std::endl;
    std::cout<<" 9.  Print the maximum element [Max]"<<std::endl;
    std::cout<<" 10. Print the maximum element and remove it [Max and Remove]"<<std::endl;
    std::cout<<" 11. Remove the maximum element [Remove Max]"<<std::endl;
    std::cout<<" 12. Print the predecessor of a given element [Predecessor]"<<std::endl;
    std::cout<<" 13. Remove and print the predecessor of a given element [Predecessor and Remove]"<<std::endl;
    std::cout<<" 14. Remove the predecessor of a given element [Remove Predecessor]"<<std::endl;
    std::cout<<" 15. Print the predecessor of a given element [Successor]"<<std::endl;
    std::cout<<" 16. Remove and print the successor of a given element [Successor and Remove]"<<std::endl;
    std::cout<<" 17. Remove the successor of a given element [Remove Successor]"<<std::endl;
    std::cout<<" 18. Node-level operations (debug)"<<std::endl;
    std::cout<<" 19. Go back"<<std::endl;
    std::cout<<" 20. Quit"<<std::endl;
    cout<<endl<<" -> ";

    std::cin>>std::ws;
    std::cin>>choice;
    std::cout<<std::endl;
    switch(choice){
      case 1:
        PrintTree(bst);
        break;
      case 2:
        CheckExistence(bst);
        break;
      case 3:
        SumElementsGreaterThan(bst);
        break;
      case 4:
        InsertElement(bst);
        break;
      case 5:
        RemoveElement(bst);
        break;
      case 6:
        PrintMinimum(bst);
      break;
      case 7:
        PrintMinimumNDelete(bst);
      break;
      case 8:
        RemoveMin(bst);
      break;
      case 9:
        PrintMaximum(bst);
      break;
      case 10:
        PrintMaximumNDelete(bst);
      break;
      case 11:
        RemoveMax(bst);
      break;
      case 12:
        PrintPredecessor(bst);
      break;
      case 13:
        PredecessorNRemove(bst);
      break;
      case 14:
        RemovePredecessor(bst);
      break;
      case 15:
        PrintSuccessor(bst);
        break;
      case 16:
        SuccessorNRemove(bst);
        break;
      case 17:
        RemoveSuccessor(bst);
        break;
      case 18:
      try{
        NodeOperations(bst.Root());
      }catch(length_error exc){
        cout<<exc.what();
      }
      break;
      case 19:
        menu();
    }
  }while(choice!=19 && choice!=20);
}

template <typename Data>
void SumElementsGreaterThan(BST<Data>& tree){
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

/* ----- string functions ----- */

template <typename Data>
void StringFunctions(BST<Data>& bst){
  unsigned short int choice;
  do{
    std::cout<<std::endl<<std::endl;
    std::cout<<"Choose one of the following options:"<<std::endl;
    std::cout<<" 1.  Print tree"<<std::endl;
    std::cout<<" 2.  Check exsistence of an element"<<std::endl;
    std::cout<<" 3.  Concatenate strings whose dimension is less or equal than 'n' "<<std::endl;
    std::cout<<" 4.  Insert an element [Insert]"<<std::endl;
    std::cout<<" 5.  Remove an element [Remove]"<<std::endl;
    std::cout<<" 6.  Print the minimum element [Min]"<<std::endl;
    std::cout<<" 7.  Print the minimum element and remove it [Min and Remove]"<<std::endl;
    std::cout<<" 8.  Remove the minimum element [Remove Min]"<<std::endl;
    std::cout<<" 9.  Print the maximum element [Max]"<<std::endl;
    std::cout<<" 10. Print the maximum element and remove it [Max and Remove]"<<std::endl;
    std::cout<<" 11. Remove the maximum element [Remove Max]"<<std::endl;
    std::cout<<" 12. Print the predecessor of a given element [Predecessor]"<<std::endl;
    std::cout<<" 13. Remove and print the predecessor of a given element [Predecessor and Remove]"<<std::endl;
    std::cout<<" 14. Remove the predecessor of a given element [Remove Predecessor]"<<std::endl;
    std::cout<<" 15. Print the predecessor of a given element [Successor]"<<std::endl;
    std::cout<<" 16. Remove and print the successor of a given element [Successor and Remove]"<<std::endl;
    std::cout<<" 17. Remove the successor of a given element [Remove Successor]"<<std::endl;
    std::cout<<" 18. Node-level operations (debug)"<<std::endl;
    std::cout<<" 19. Go back"<<std::endl;
    std::cout<<" 20. Quit"<<std::endl;

    cout<<endl<<" -> ";
    std::cin>>std::ws;
    std::cin>>choice;
    std::cout<<std::endl;
    switch(choice){
      case 1:
        PrintTree(bst);
        break;
      case 2:
        CheckExistence(bst);
        break;
      case 3:
        ConcatLessThan(bst);
        break;
      case 4:
        InsertElement(bst);
        break;
      case 5:
        RemoveElement(bst);
        break;
      case 6:
        PrintMinimum(bst);
      break;
      case 7:
        PrintMinimumNDelete(bst);
      break;
      case 8:
        RemoveMin(bst);
      break;
      case 9:
        PrintMaximum(bst);
      break;
      case 10:
        PrintMaximumNDelete(bst);
      break;
      case 11:
        RemoveMax(bst);
      break;
      case 12:
        PrintPredecessor(bst);
      break;
      case 13:
        PredecessorNRemove(bst);
      break;
      case 14:
        RemovePredecessor(bst);
      break;
      case 15:
        PrintSuccessor(bst);
        break;
      case 16:
        SuccessorNRemove(bst);
        break;
      case 17:
        RemoveSuccessor(bst);
        break;
      case 18:
      try{
        NodeOperations(bst.Root());
      }catch(length_error exc){
        cout<<exc.what();
      }
      break;
      case 19:
        menu();
    }
  }while(choice!=19 && choice!=20);
}

template <typename Data>
void ConcatLessThan(BST<Data>& tree){
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

/* ----- shared functions ----- */
template <typename Data>
void PrintTree(BST<Data>& tree){
  void (*PrinterFunction) (Data&, void*) = PrintSingleElement;

  cout<<"Pre order:\n";
  tree.MapPreOrder(PrinterFunction, nullptr);
  cout<<endl<<endl;

  cout<<"In oder:\n";
  tree.MapInOrder(PrinterFunction, nullptr);
  cout<<endl<<endl;

  cout<<"Post order:\n";
  tree.MapPostOrder(PrinterFunction, nullptr);
  cout<<endl<<endl;

  cout<<"Breadth order:\n";
  tree.MapBreadth(PrinterFunction, nullptr);
  cout<<endl<<endl;
}

template <typename Data>
void PrintSingleElement(Data& data, void* _){
  std::cout << data << " ";
}

template <typename Data>
void CheckExistence(BST<Data>& tree){
  Data elementToLookFor;
  cout<<"\n\nCheck existence in the tree of: ";
  cin>>ws;
  cin>>elementToLookFor;
  cout<<"The element " << ( (!tree.Exists(elementToLookFor))? "does not " : "") << "exists\n\n";
}

template <typename Data>
void InsertElement(BST<Data>& bst){
  Data elementToInsert;
  cout<<"\n\nInsert in the BST the following element: ";
  cin>>ws;
  cin>>elementToInsert;
  bst.Insert(elementToInsert);
}

template <typename Data>
void RemoveElement(BST<Data>& bst){
  Data elementToRemove;
  cout<<"\n\nRemove from the BST the following element: ";
  cin>>ws;
  cin>>elementToRemove;
  bst.Remove(elementToRemove);
}

template <typename Data>
void PrintMinimum(BST<Data>& bst){
  if(bst.Size()>0)
    cout<<"\n\nThe minimum element in the BST is "<<bst.Min();
  else
    cout<<"\n\nTree is empty.";
}

template <typename Data>
void PrintMinimumNDelete(BST<Data>& bst){
  if(bst.Size()>0)
    cout<<"The minimum element in the BST ( "<<bst.MinNRemove()<<" ) has been removed";
  else
    cout<<"\n\nTree is empty.";
}

template <typename Data>
void RemoveMin(BST<Data>& bst){
  if(bst.Size()>0){
    bst.RemoveMin();
    cout<<"\n\nThe minimum element has been deleted";
  }
  else
    cout<<"\n\nTree is empty.";
}

template <typename Data>
void PrintMaximum(BST<Data>& bst){
  if(bst.Size()>0)
    cout<<"\n\nThe maximum element in the BST is "<<bst.Max();
  else
    cout<<"\n\nTree is empty.";
}

template <typename Data>
void PrintMaximumNDelete(BST<Data>& bst){
  if(bst.Size()>0)
    cout<<"The maximum element in the BST ( "<<bst.MaxNRemove()<<" ) has been removed";
  else
    cout<<"\n\nTree is empty.";
}

template <typename Data>
void RemoveMax(BST<Data>& bst){
  if(bst.Size()>0){
    bst.RemoveMax();
    cout<<"\n\nThe maximum element has been deleted";
  }
  else
    cout<<"\n\nTree is empty.";
}

template <typename Data>
void PrintPredecessor(BST<Data>& bst){
  Data lookForPredecessor;
  cout<<"Print the predecessor of ";
  cin>>ws;
  cin>>lookForPredecessor;
  try{
    cout<<"The predecessor of "<<lookForPredecessor<<" is "<<bst.Predecessor(lookForPredecessor);
  }catch(length_error exc){
    cout<<exc.what();
  }
}

template <typename Data>
void PredecessorNRemove(BST<Data>& bst){
  Data lookForPredecessor;
  cout<<"Print and delete the predecessor of ";
  cin>>ws;
  cin>>lookForPredecessor;
  try{
    cout<<"The predecessor of "<<lookForPredecessor<<" was "<<bst.PredecessorNRemove(lookForPredecessor)<<" and has been removed";
  }catch(length_error exc){
    cout<<exc.what();
  }
}

template <typename Data>
void RemovePredecessor(BST<Data>& bst){
  Data lookForPredecessor;
  cout<<"Delete the predecessor of ";
  cin>>ws;
  cin>>lookForPredecessor;
  try{
    bst.RemovePredecessor(lookForPredecessor);
    cout<<"The predecessor of "<<lookForPredecessor<<" has been removed";
  }catch(length_error exc){
    cout<<exc.what();
  }
}

template <typename Data>
void PrintSuccessor(BST<Data>& bst){
  Data lookForSuccessor;
  cout<<"Print the successor of ";
  cin>>ws;
  cin>>lookForSuccessor;
  try{
    cout<<"The successor of "<< lookForSuccessor<<" is "<<bst.Successor(lookForSuccessor);
  }catch(length_error exc){
    cout<<exc.what();
  }
}

template <typename Data>
void SuccessorNRemove(BST<Data>& bst){
  Data lookForSuccessor;
  cout<<"Print and delete the successor of ";
  cin>>ws;
  cin>>lookForSuccessor;
  try{
    cout<<"The successor of "<<lookForSuccessor<<" was "<<bst.SuccessorNRemove(lookForSuccessor)<<" and has been removed";
  }catch(length_error exc){
    cout<<exc.what();
  }
}

template <typename Data>
void RemoveSuccessor(BST<Data>& bst){
  Data lookForSuccessor;
  cout<<"Delete the successor of ";
  cin>>ws;
  cin>>lookForSuccessor;
  try{
    bst.RemoveSuccessor(lookForSuccessor);
    cout<<"The successor of "<<lookForSuccessor<<" has been removed";
  }catch(length_error exc){
    cout<<exc.what();
  }
}

template <typename T>
void NodeOperations(T& currentNode){
  uint choice;
  cout<<endl<<endl;
  cout<<" *** Element in the current node: "<<currentNode.Element()<<" ***"<<endl;
  cout<<" 1. Go left"<<endl;
  cout<<" 2. Go Right"<<endl;
  cout<<" 3. Is this a leaf?"<<endl;
  cout<<" 4. Go back"<<endl;
  cout<<endl<<" -> ";
  cin>>ws;
  cin>>choice;
  switch(choice){
    case 1:
      if(currentNode.HasLeftChild()) NodeOperations(currentNode.LeftChild());
      else{
        cout<<"\nThe node does not have a left child, operation aborted.";
        NodeOperations(currentNode);
      }
      break;

    case 2:
      if(currentNode.HasRightChild()) NodeOperations(currentNode.RightChild());
      else {
        cout<<"\nThe node does not have a right child, operation aborted.";
        NodeOperations(currentNode);
      }
      break;

    case 3:
      if(currentNode.IsLeaf()) cout<<"\n Yes, the current node is a leaf";
      else cout<<"\n No, the current node is not a leaf";
      NodeOperations(currentNode);
      break;
    }
}


/* ----- generator functions ----- */

BST<int> GenerateIntegerBST(BST<int>& bst){
  ulong dim = getDimension();
  Vector<int> tmp(dim);

  default_random_engine gen(random_device{}());
  uniform_int_distribution<int> dist(0,1000);

  cout<<"\n\nElements in the binary tree (in breadth order):\n";
  for(ulong i=0 ; i<dim ; ++i){
    tmp[i] = dist(gen);
    cout<<tmp[i]<<" ";
  }
  cout<<endl<<endl;

  BST<int> tree(tmp);
  return tree;
}

BST<float> GenerateFloatBST(BST<float>& bst){
  ulong dim = getDimension();
  Vector<float> tmp(dim);

  default_random_engine gen(random_device{}());
  uniform_real_distribution<double> distr(0,5);

  cout<<"\n\nElements in the binary tree (in breadth order):\n";
  for(unsigned long i = 0; i < dim; ++i){
    tmp[i] = (round(distr(gen)*10000))/100;
    cout<<tmp[i]<<" ";
  }
  cout<<endl<<endl;

  BST<float> tree(tmp);
  return tree;
}

BST<string> GenerateStringsBST(BST<string>& bst){
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

  BST<string> tree(tmp);
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
