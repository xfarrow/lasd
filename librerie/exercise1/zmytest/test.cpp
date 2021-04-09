#include"test.hpp"
#include<iostream>
#include<random>
#include "../zlasdtest/test.hpp"

void menu(){
  unsigned short int choice;
  DataStructure chosenDataStructure;
  DataType chosenDataType;
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
      UseChosenType(chosenDataStructure,chosenDataType);
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
    std::cout<<"1. Vector"<<std::endl;
    std::cout<<"2. List"<<std::endl;
    std::cin>>std::ws;
    std::cin>>choice;
  }while(choice!=1 && choice!=2);
  if(choice == 1)
    return DataStructure::vector;
  else if(choice == 2)
    return DataStructure::list;
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
void UseChosenType(DataStructure chosenDataStructure, DataType chosenDataType){

  if(chosenDataStructure == DataStructure::vector){
    if(chosenDataType == DataType::integer){
      lasd::Vector<int> myvec;
      myvec = generateVectorOfIntegers();
      VectorIntegerFunctions(myvec);
    }else if(chosenDataType == DataType::ffloat){
      lasd::Vector<float> myvec;
      myvec = generateVectorOfFloat();
      VectorFloatFunctions(myvec);
    }else if(chosenDataType == DataType::sstring){
      lasd::Vector<std::string> myvec;
      myvec = generateVectorOfStrings();
      VectorStringFunctions(myvec);
    }
  }else if(chosenDataStructure == DataStructure::list){
    if(chosenDataType == DataType::integer){
      lasd::List<int> mylist;
      mylist = generateListOfIntegers();
      ListIntegerFunctions(mylist);
    }else if(chosenDataType == DataType::ffloat){
      lasd::List<float> mylist;
      mylist = generateListOfFloat();
      ListFloatFunctions(mylist);
    }else if(chosenDataType == DataType::sstring){
      lasd::List<std::string> mylist;
      mylist = generateListOfStrings();
      ListStringFunctions(mylist);
    }
  }
}

/*
********** VECTOR FUNCTIONS **********
*/
void VectorIntegerFunctions(lasd::Vector<int> myvec){
  unsigned short int choice;
  do{
    std::cout<<"Choose one of the following options:"<<std::endl;
    std::cout<<"1. Visualizza elemento iniziale"<<std::endl;
    std::cout<<"2. Visualizza elemento finale"<<std::endl;
    std::cout<<"3. Visualizza elemento con uno specifico indice"<<std::endl;
    std::cout<<"4. Visualizza tutti gli elementi"<<std::endl;
    std::cout<<"5. Controlla esistenza di uno specifico valore"<<std::endl;
    std::cout<<"6. Somma per gli interi minori di uno specifico valore"<<std::endl;
    std::cout<<"7. Raddoppia gli elementi."<<std::endl;
    std::cout<<"8. Torna indietro"<<std::endl;
    std::cout<<"9. Esci"<<std::endl;
    std::cin>>std::ws;
    std::cin>>choice;

    switch(choice){
      case 1:
        ShowFirstElement(myvec);
        break;
      case 2:
        ShowLastElement(myvec);
        break;
      case 3:
        ShowElementWithASpecificIndex(myvec);
        break;
      case 4:
        ShowAllElements(myvec);
        break;
      case 5:
        CheckElementExists(myvec);
        break;
      case 6:
        SumLessThan(myvec);
        break;
      case 7:
        DoubleIntegers(myvec);
        break;
      case 8:
        std::cout<<std::endl<<std::endl;
        menu();
        break;
      }
  }while(choice!=9 && choice!=8);
}
void VectorFloatFunctions(lasd::Vector<float> myvec){
  unsigned short int choice;
  do{
    std::cout<<"Choose one of the following options:"<<std::endl;
    std::cout<<"1. Visualizza elemento iniziale"<<std::endl;
    std::cout<<"2. Visualizza elemento finale"<<std::endl;
    std::cout<<"3. Visualizza elemento con uno specifico indice"<<std::endl;
    std::cout<<"4. Visualizza tutti gli elementi"<<std::endl;
    std::cout<<"5. Controlla esistenza di uno specifico valore"<<std::endl;
    std::cout<<"6. Prodotto per i float maggiori di uno specifico valore"<<std::endl;
    std::cout<<"7. Eleva al quadrato gli elementi."<<std::endl;
    std::cout<<"8. Torna indietro"<<std::endl;
    std::cout<<"9. Esci"<<std::endl;
    std::cin>>std::ws;
    std::cin>>choice;
    switch(choice){
      case 1:
        ShowFirstElement(myvec);
        break;
      case 2:
        ShowLastElement(myvec);
        break;
      case 3:
        ShowElementWithASpecificIndex(myvec);
        break;
      case 4:
        ShowAllElements(myvec);
        break;
      case 5:
        CheckElementExists(myvec);
        break;
      case 6:
        ProductMoreThan(myvec);
        break;
      case 7:
        SquareFloats(myvec);
        break;
      case 8:
          std::cout<<std::endl<<std::endl;
          menu();
          break;
      }
    }while(choice!=9 && choice!=8);
}
void VectorStringFunctions(lasd::Vector<std::string> myvec){
  unsigned short int choice;
  do{
    std::cout<<"Choose one of the following options:"<<std::endl;
    std::cout<<"1. Visualizza elemento iniziale"<<std::endl;
    std::cout<<"2. Visualizza elemento finale"<<std::endl;
    std::cout<<"3. Visualizza elemento con uno specifico indice"<<std::endl;
    std::cout<<"4. Visualizza tutti gli elementi"<<std::endl;
    std::cout<<"5. Controlla esistenza di uno specifico valore"<<std::endl;
    std::cout<<"6. Concatenazione delle stringhe lunghe meno di uno specifico n"<<std::endl;
    std::cout<<"7. Uppercase."<<std::endl;
    std::cout<<"8. Torna indietro"<<std::endl;
    std::cout<<"9. Esci"<<std::endl;
    std::cin>>std::ws;
    std::cin>>choice;
    switch(choice){
      case 1:
        ShowFirstElement(myvec);
        break;
      case 2:
        ShowLastElement(myvec);
        break;
      case 3:
        ShowElementWithASpecificIndex(myvec);
        break;
      case 4:
        ShowAllElements(myvec);
        break;
      case 5:
        CheckElementExists(myvec);
        break;
      case 6:
        ConcatLessThan(myvec);
        break;
      case 7:
        Uppercase(myvec);
        break;
      case 8:
        std::cout<<std::endl<<std::endl;
        menu();
        break;
      }
    }while(choice!=9 && choice!=8);
}
template <typename Data>
void ShowFirstElement(lasd::Vector<Data>& vec){
  std::cout<<std::endl<<"The first element is: "<<vec.Front()<<std::endl<<std::endl;
}
template <typename Data>
void ShowLastElement(lasd::Vector<Data>& vec){
  std::cout<<std::endl<<"The last element is: "<<vec.Back()<<std::endl<<std::endl;
}
template <typename Data>
void ShowElementWithASpecificIndex(lasd::Vector<Data>& vec){
  ulong index;
  std::cout<<"Insert the index: ";
  std::cin>>std::ws;
  std::cin>>index;
  try{
    std::cout<<std::endl<<"The element with the index: "<<index<<" is "<<vec[index]<<std::endl<<std::endl;
  }catch(std::out_of_range exc){
    std::cout<<exc.what()<<std::endl;
  }
}
template <typename Data>
void ShowAllElements(lasd::Vector<Data>& vec){
  void (*AuxMapPreOrder) (Data&, void*) = PrintSingleElement;
  std::cout<<"The vector contains:"<<std::endl;
  vec.MapPreOrder(AuxMapPreOrder, nullptr);
  std::cout<<std::endl;
}
template <typename Data>
void PrintSingleElement(Data& data, void* _){
  std::cout << data << " ";
}
template <typename Data>
void CheckElementExists(lasd::Vector<Data>& vec){
  Data element;
  std::cout<<"What element do you wanna check its exsistence on? ";
  std::cin>>std::ws;
  std::cin>>element;
  if(vec.Exists(element))
    std::cout<<"The element exists"<<std::endl<<std::endl;
  else
    std::cout<<"The element does not exist"<<std::endl<<std::endl;
}
void SumLessThan(lasd::Vector<int>& vec){
  int pivot;
  ulong acc=0;
  void (*func)(const int&, const void*, void*) = AccumulateSum;
  std::cout<<"Which element do you choose to performa a sum under it? ";
  std::cin>>std::ws;
  std::cin>>pivot;
  vec.FoldPreOrder(func, (void*)&pivot, (void*)&acc);
  std::cout<<"The result of the sum is "<<acc<<std::endl<<std::endl;
}
void AccumulateSum(const int& data, const void* par, void* acc){
if(data < (*(int*)par)){
    *(ulong*)acc += data;
  }
}
void DoubleIntegers(lasd::Vector<int>& vec){
  void (*fun)(int&, void*) = DoubleAnInteger;
  vec.MapPreOrder(fun, nullptr);
  std::cout<<std::endl<<"The doubled elements of the vector are: ";
  for (ulong i=0 ; i < vec.Size(); ++i){
    std::cout<<vec[i]<<" ";
  }
  std::cout<<std::endl<<std::endl;
}
void DoubleAnInteger(int& data, void* _){
  data *= 2;
}
void ProductMoreThan(lasd::Vector<float>& vec){
  float pivot, acc=1;
  void (*func)(const float&, const void*, void*) = AccumulateProduct;
  std::cout<<"Which element do you choose to perform a product above it? ";
  std::cin>>std::ws;
  std::cin>>pivot;
  vec.FoldPreOrder(func, (void*)&pivot, (void*)&acc);
  std::cout<<"The result of the product is "<<acc<<std::endl<<std::endl;
}
void AccumulateProduct(const float& data, const void* par, void* acc){
if(data > (*(float*)par)){
    *(float*)acc *= data;
  }
}
void SquareFloats(lasd::Vector<float>& vec){
  void (*fun)(float&, void*) = SquareAFloat;
  vec.MapPreOrder(fun, nullptr);
  std::cout<<std::endl<<"The squared elements of the vector are: ";
  for (ulong i=0 ; i < vec.Size(); ++i){
    std::cout<<vec[i]<<" ";
  }
  std::cout<<std::endl<<std::endl;
}
void SquareAFloat(float& data, void* _){
  data *= data;
}
void ConcatLessThan(lasd::Vector<std::string>& vec){
  ulong pivot;
  std::string acc = "";
  void (*func)(const std::string&, const void*, void*) = ConcatAux;
  std::cout<<"Concat elements whose length is less than: ";
  std::cin>>std::ws;
  std::cin>>pivot;
  vec.FoldPreOrder(func, (void*)&pivot, (void*)&acc);
  std::cout<<"The concatenated string is "<<acc<<std::endl<<std::endl;
}
void ConcatAux(const std::string& data, const void* par, void* acc){
  if( ((ulong)data.length()) < ((*(ulong*)par)) ){
    *(std::string*)acc = *(std::string*)acc + data;
  }
}
void Uppercase(lasd::Vector<std::string>& vec){
  void (*fun)(std::string&, void*) = UppercaseAString;
  vec.MapPreOrder(fun, nullptr);
  std::cout<<"The uppercased strings are: "<<std::endl;
  for (ulong i=0 ; i < vec.Size() ; ++i){
    std::cout<<vec[i]<<" ";
  }
  std::cout<<std::endl<<std::endl;
}
void UppercaseAString(std::string& data, void* par){
  for(ulong i=0 ; i<data.length() ; ++i){
    data[i] = toupper(data[i]);
  }
}
/*
********** END VECTOR FUNCTIONS **********
*/

/*
********** LIST FUNCTIONS **********
*/
void ListIntegerFunctions(lasd::List<int> mylist){
  unsigned short int choice;
  do{
    std::cout<<"Choose one of the following options:"<<std::endl;
    std::cout<<"1. Visualizza elemento iniziale"<<std::endl;
    std::cout<<"2. Visualizza elemento finale"<<std::endl;
    std::cout<<"3. Visualizza elemento con uno specifico indice"<<std::endl;
    std::cout<<"4. Visualizza tutti gli elementi"<<std::endl;
    std::cout<<"5. Controlla esistenza di uno specifico valore"<<std::endl;
    std::cout<<"6. Somma per gli interi minori di uno specifico valore"<<std::endl;
    std::cout<<"7. Raddoppia gli elementi."<<std::endl;
    std::cout<<"8. Torna indietro"<<std::endl;
    std::cout<<"9. Esci"<<std::endl;
    std::cin>>std::ws;
    std::cin>>choice;

    switch(choice){
      case 1:
        ShowFirstElement(mylist);
        break;
      case 2:
        ShowLastElement(mylist);
        break;
      case 3:
        ShowElementWithASpecificIndex(mylist);
        break;
      case 4:
        ShowAllElements(mylist);
        break;
      case 5:
        CheckElementExists(mylist);
        break;
      case 6:
        SumLessThan(mylist);
        break;
      case 7:
        DoubleIntegers(mylist);
        break;
      case 8:
        std::cout<<std::endl<<std::endl;
        menu();
        break;
      }
    }while(choice!=9 && choice!=8);
}
void ListFloatFunctions(lasd::List<float> mylist){
  unsigned short int choice;
  do{
    std::cout<<"Choose one of the following options:"<<std::endl;
    std::cout<<"1. Visualizza elemento iniziale"<<std::endl;
    std::cout<<"2. Visualizza elemento finale"<<std::endl;
    std::cout<<"3. Visualizza elemento con uno specifico indice"<<std::endl;
    std::cout<<"4. Visualizza tutti gli elementi"<<std::endl;
    std::cout<<"5. Controlla esistenza di uno specifico valore"<<std::endl;
    std::cout<<"6. Prodotto per i float maggiori di uno specifico valore"<<std::endl;
    std::cout<<"7. Eleva al quadrato gli elementi."<<std::endl;
    std::cout<<"8. Torna indietro"<<std::endl;
    std::cout<<"9. Esci"<<std::endl;
    std::cin>>std::ws;
    std::cin>>choice;
    switch(choice){
      case 1:
        ShowFirstElement(mylist);
        break;
      case 2:
        ShowLastElement(mylist);
        break;
      case 3:
        ShowElementWithASpecificIndex(mylist);
        break;
      case 4:
        ShowAllElements(mylist);
        break;
      case 5:
        CheckElementExists(mylist);
        break;
      case 6:
        ProductMoreThan(mylist);
        break;
      case 7:
        SquareFloats(mylist);
        break;
      case 8:
        std::cout<<std::endl<<std::endl;
        menu();
        break;
        }
    }while(choice!=9 && choice!=8);
}
void ListStringFunctions(lasd::List<std::string> mylist){
  unsigned short int choice;
  do{
    std::cout<<"Choose one of the following options:"<<std::endl;
    std::cout<<"1. Visualizza elemento iniziale"<<std::endl;
    std::cout<<"2. Visualizza elemento finale"<<std::endl;
    std::cout<<"3. Visualizza elemento con uno specifico indice"<<std::endl;
    std::cout<<"4. Visualizza tutti gli elementi"<<std::endl;
    std::cout<<"5. Controlla esistenza di uno specifico valore"<<std::endl;
    std::cout<<"6. Concatenazione delle stringhe lunghe meno di uno specifico n"<<std::endl;
    std::cout<<"7. Uppercase."<<std::endl;
    std::cout<<"8. Vai indietro"<<std::endl;
    std::cout<<"9. Esci"<<std::endl;
    std::cin>>std::ws;
    std::cin>>choice;
    switch(choice){
      case 1:
        ShowFirstElement(mylist);
        break;
      case 2:
        ShowLastElement(mylist);
        break;
      case 3:
        ShowElementWithASpecificIndex(mylist);
        break;
      case 4:
        ShowAllElements(mylist);
        break;
      case 5:
        CheckElementExists(mylist);
        break;
      case 6:
        ConcatLessThan(mylist);
        break;
      case 7:
        Uppercase(mylist);
        break;
      case 8:
        std::cout<<std::endl<<std::endl;
        menu();
        break;
      }
    }while(choice!=9 && choice!=8);
}

template <typename Data>
void ShowFirstElement(lasd::List<Data>& list){
  std::cout<<std::endl<<"The first element is: "<<list.Front()<<std::endl<<std::endl;
}
template <typename Data>
void ShowLastElement(lasd::List<Data>& list){
  std::cout<<std::endl<<"The last element is: "<<list.Back()<<std::endl<<std::endl;
}
template <typename Data>
void ShowElementWithASpecificIndex(lasd::List<Data>& list){
  ulong index;
  std::cout<<"Insert the index: ";
  std::cin>>std::ws;
  std::cin>>index;
  try{
    std::cout<<std::endl<<"The element with the index: "<<index<<" is "<<list[index]<<std::endl<<std::endl;
  }catch(std::out_of_range exc){
    std::cout<<exc.what()<<std::endl;
  }
}

template <typename Data>
void ShowAllElements(lasd::List<Data>& list){
  void (*AuxMapPreOrder) (Data&, void*) = PrintSingleElement;
  std::cout<<"The list contains:"<<std::endl;
  list.MapPreOrder(AuxMapPreOrder, nullptr);
  std::cout<<std::endl<<std::endl;
}

template <typename Data>
void CheckElementExists(lasd::List<Data>& list){
  Data element;
  std::cout<<"What element do you wanna check its exsistence on? ";
  std::cin>>std::ws;
  std::cin>>element;
  if(list.Exists(element))
    std::cout<<"The element exists"<<std::endl<<std::endl;
  else
    std::cout<<"The element does not exist"<<std::endl<<std::endl;
}

void SumLessThan(lasd::List<int>& list){
  int pivot;
  ulong acc=0;
  void (*func)(const int&, const void*, void*) = AccumulateSum;
  std::cout<<"Which element do you choose to performa a sum under it? ";
  std::cin>>std::ws;
  std::cin>>pivot;
  list.FoldPreOrder(func, (void*)&pivot, (void*)&acc);
  std::cout<<"The result of the sum is "<<acc<<std::endl<<std::endl;
}

void DoubleIntegers(lasd::List<int>& list){
  void (*fun)(int&, void*) = DoubleAnInteger;
  list.MapPreOrder(fun, nullptr);
  std::cout<<std::endl<<"The doubled elements of the vector are: ";
  for (ulong i=0 ; i < list.Size(); ++i){
    std::cout<<list[i]<<" ";
  }
  std::cout<<std::endl<<std::endl;
}
void ProductMoreThan(lasd::List<float>& list){
  float pivot, acc=1;
  void (*func)(const float&, const void*, void*) = AccumulateProduct;
  std::cout<<"Which element do you choose to perform a product above it? ";
  std::cin>>std::ws;
  std::cin>>pivot;
  list.FoldPreOrder(func, (void*)&pivot, (void*)&acc);
  std::cout<<"The result of the product is "<<acc<<std::endl<<std::endl;
}
void SquareFloats(lasd::List<float>& list){
  void (*fun)(float&, void*) = SquareAFloat;
  list.MapPreOrder(fun, nullptr);
  std::cout<<std::endl<<"The squared elements of the vector are: ";
  for (ulong i=0 ; i < list.Size(); ++i){
    std::cout<<list[i]<<" ";
  }
  std::cout<<std::endl<<std::endl;
}
void ConcatLessThan(lasd::List<std::string>& list){
  ulong pivot;
  std::string acc = "";
  void (*func)(const std::string&, const void*, void*) = ConcatAux;
  std::cout<<"Concat elements whose length is less than: ";
  std::cin>>std::ws;
  std::cin>>pivot;
  list.FoldPreOrder(func, (void*)&pivot, (void*)&acc);
  std::cout<<"The concatenated string is "<<acc<<std::endl<<std::endl;
}
void Uppercase(lasd::List<std::string>& list){
  void (*fun)(std::string&, void*) = UppercaseAString;
  list.MapPreOrder(fun, nullptr);
  std::cout<<"The uppercased strings are: "<<std::endl;
  for (ulong i=0 ; i < list.Size() ; ++i){
    std::cout<<list[i]<<" ";
  }
  std::cout<<std::endl<<std::endl;
}

/*
********** END LIST FUNCTIONS **********
*/

/*
********** GENERATORS **********
*/
lasd::List<std::string> generateListOfStrings(){
  ulong dim = getDimension();
  lasd::List<std::string> mylist = lasd::List<std::string>();

  std::default_random_engine gen(std::random_device{}());
  std::uniform_int_distribution<int> dist(1,5);

  for(unsigned long i = 0; i < dim; ++i){
     mylist.InsertAtFront(generateRandomString(dist(gen)));
  }
  std::cout<<"Elements of the list:"<<std::endl;
  for(unsigned long i = 0 ; i<dim ; ++i){
    std::cout<<mylist[i]<<" ";
  }
  std::cout<<std::endl;
  return mylist;
}
lasd::List<float> generateListOfFloat(){
  ulong dim = getDimension();
  lasd::List<float> mylist = lasd::List<float>();

  std::default_random_engine gen(std::random_device{}());
  std::uniform_real_distribution<double> distr(0,5);
  for(unsigned long i = 0; i < dim; ++i){
    mylist.InsertAtFront((round(distr(gen)*10000))/100);
  }
  std::cout<<"Elements of the list:"<<std::endl;
  for(unsigned long i = 0 ; i<dim ; ++i){
    std::cout<<mylist[i]<<" ";
  }
  std::cout<<std::endl;
  return mylist;
}
lasd::List<int> generateListOfIntegers(){
  ulong dim = getDimension();
  lasd::List<int> mylist = lasd::List<int>();
  std::default_random_engine gen(std::random_device{}());
  std::uniform_int_distribution<int> dist(0,1000);
  for(ulong i=0 ; i<dim ; ++i){
    mylist.InsertAtFront(dist(gen));
  }
  std::cout<<"Elements of the list:"<<std::endl;
  for(unsigned long i = 0 ; i<dim ; ++i){
    std::cout<<mylist[i]<<" ";
  }
  std::cout<<std::endl;
  return mylist;
}
lasd::Vector<int> generateVectorOfIntegers(){
  ulong dim = getDimension();
  lasd::Vector<int> myvec = lasd::Vector<int>(dim);

  std::default_random_engine gen(std::random_device{}());
  std::uniform_int_distribution<int> dist(0,1000);

  for(ulong i = 0 ; i<dim ; ++i){
    myvec[i] = dist(gen);
  }
  std::cout<<std::endl<<"Elements of the vector:"<<std::endl;
  for(unsigned long i = 0 ; i<dim ; ++i){
    std::cout<<myvec[i]<<" ";
  }
  std::cout<<std::endl;
  return myvec;
}
lasd::Vector<float> generateVectorOfFloat(){
  ulong dim = getDimension();
  lasd::Vector<float> myvec = lasd::Vector<float>(dim);

  std::default_random_engine gen(std::random_device{}());
  std::uniform_real_distribution<double> distr(0,5);
  for(unsigned long i = 0; i < dim; ++i){
    myvec[i] = (round(distr(gen)*10000))/100;
  }
  std::cout<<std::endl<<"Elements of the vector:"<<std::endl;
  for(unsigned long i = 0 ; i<dim ; ++i){
    std::cout<<myvec[i]<<" ";
  }
  std::cout<<std::endl;
  return myvec;
}
lasd::Vector<std::string> generateVectorOfStrings(){
  ulong dim = getDimension();
  lasd::Vector<std::string> myvec = lasd::Vector<std::string>(dim);

  std::default_random_engine gen(std::random_device{}());
  std::uniform_int_distribution<int> dist(1,5);

  for(unsigned long i = 0; i < dim; ++i){
    myvec[i] = generateRandomString(dist(gen));
  }
  std::cout<<std::endl<<"Elements of the vector:"<<std::endl;
  for(unsigned long i = 0 ; i<dim ; ++i){
    std::cout<<myvec[i]<<" ";
  }
  std::cout<<std::endl<<std::endl;
  return myvec;
}
std::string generateRandomString(ulong dim){
  std::default_random_engine gen(std::random_device{}());
  std::uniform_int_distribution<char> character('a','z');
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
