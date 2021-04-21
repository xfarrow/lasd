#include"test.hpp"
#include<iostream>
#include<random>
#include "../zlasdtest/test.hpp"

using namespace lasd;


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
      chosenImplementation = ChooseImplementation();
      chosenDataType = ChooseDataType();
      UseChosenType(chosenDataStructure, chosenDataType, chosenImplementation);
      break;
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
  }while(!(choice>0 && choice<3));
  if(choice==1)
    return Implementation::vector;
  else if(choice==2)
    return Implementation::list;
}

void UseChosenType(DataStructure chosenDataStructure, DataType chosenDataType, Implementation chosenImplementation){
  if(chosenDataStructure == DataStructure::stack){
    if(chosenImplementation == Implementation::vector){
      if(chosenDataType == DataType::integer){
        StackVec<int> stckvec;
        stckvec = generateRandomStackVecInt();
        StackIntFunctions(stckvec);
      }
      else if(chosenDataType == DataType::ffloat){
        StackVec<float> stckvec;
        stckvec = generateRandomStackVecFloat();
      }
      else if(chosenDataType == DataType::sstring){
        StackVec<std::string> stckvec;
        stckvec = generateRandomStackVecString();
      }
    }
    else if(chosenImplementation == Implementation::list){
      if(chosenDataType == DataType::integer){
        StackLst<int> stcklst;
        stcklst = generateRandomStackLstInt();
      }
      else if(chosenDataType == DataType::ffloat){
        StackLst<float> stcklst;
        stcklst = generateRandomStackLstFloat();
      }
      else if(chosenDataType == DataType::sstring){
        StackLst<std::string> stcklst;
        stcklst = generateRandomStackLstString();
      }
    }
  }
  else if(chosenDataStructure == DataStructure::queue){
    if(chosenImplementation == Implementation::vector){
      if(chosenDataType == DataType::integer){
        QueueVec<int> queuevec;
        queuevec = generateRandomQueueVecInt();
      }
      else if(chosenDataType == DataType::ffloat){
        QueueVec<float> queuevec;
        queuevec = generateRandomQueueVecFloat();
      }
      else if(chosenDataType == DataType::sstring){
        QueueVec<std::string> queuevec;
        queuevec = generateRandomQueueVecString();
      }
    }
    else if(chosenImplementation == Implementation::list){
      if(chosenDataType == DataType::integer){
        QueueLst<int> queuelist;
        queuelist = generateRandomQueueListInt();
      }
      else if(chosenDataType == DataType::ffloat){
        QueueLst<float> queuelist;
        queuelist = generateRandomQueueListFloat();
      }
      else if(chosenDataType == DataType::sstring){
        QueueLst<std::string> queuelist;
        queuelist = generateRandomQueueListString();
      }
    }
  }
}

template <typename T>
void StackIntFunctions(T& stk){
  unsigned short int choice;
  do{
    std::cout<<std::endl<<std::endl;
    std::cout<<"Choose one of the following options:"<<std::endl;
    std::cout<<"1. Inserimento di un elemento (Push)"<<std::endl;
    std::cout<<"2. Rimozione di un elemento (Pop)"<<std::endl;
    std::cout<<"3. Rimozione con lettura (TopNPop)"<<std::endl;
    std::cout<<"4. Lettura non distruttiva (Top)"<<std::endl;
    std::cout<<"5. Test di vuotezza"<<std::endl;
    std::cout<<"6. Dimensione"<<std::endl;
    std::cout<<"7. Clear Stack"<<std::endl;
    std::cout<<"8. Vai indietro"<<std::endl;
    std::cout<<"9. Esci"<<std::endl;
    std::cin>>std::ws;
    std::cin>>choice;
    std::cout<<std::endl;
    switch(choice){
      case 1:
        PushInt(stk);
        break;
      case 2:
        Pop(stk);
        break;
      case 3:
        TopNPop(stk);
        break;
      case 4:
        Top(stk);
        break;
      case 5:
        Empty(stk);
        break;
      case 6:
        Size(stk);
        break;
      case 7:
        Clear(stk);
        break;
    }
  }while(choice!=9 && choice!=8);
}

template <typename T>
void PushInt(T& stk){
  int element;
  std::cout<<"Element to push: ";
  std::cin>>std::ws;
  std::cin>>element;
  stk.Push(element);
}

template <typename T>
void Pop(T& stk){
  stk.Pop();
}

template <typename T>
void TopNPop(T& stk){
  std::cout<<"Element top & popped is: "<<stk.TopNPop();
}

template <typename T>
void Top(T& stk){
  std::cout<<"Element on top is: "<<stk.Top();
}

template <typename T>
void Empty(T& stk){
  std::cout<<"Stack is ";
  stk.Empty()? std::cout<<"" : std::cout<<"not ";
  std::cout<<"empty";
}

template <typename T>
void Size(T& stk){
  std::cout<<"Size is "<<stk.Size();
}

template <typename T>
void Clear(T& stk){
  stk.Clear();
  std::cout<<"Stack has been cleared.";
}


lasd::QueueLst<int> generateRandomQueueListInt(){
  ulong dim = getDimension();
  int tmp;
  QueueLst<int> myqueue;
  std::default_random_engine gen(std::random_device{}());
  std::uniform_int_distribution<int> dist(0,1000);
  std::cout<<std::endl<<std::endl<<"Elements of the Queue list:"<<std::endl;
  for(ulong i = 0 ; i<dim ; ++i){
    tmp = dist(gen);
    myqueue.Enqueue(tmp);
    std::cout<<tmp<<" ";
  }
  return myqueue;
}
lasd::QueueLst<float> generateRandomQueueListFloat(){
  ulong dim = getDimension();
  float tmp;
  QueueLst<float> myqueue;
  std::default_random_engine gen(std::random_device{}());
  std::uniform_real_distribution<float> distr(0,5);
  std::cout<<std::endl<<std::endl<<"Elements of the Queue list:"<<std::endl;
  for(unsigned long i = 0; i < dim; ++i){
    tmp = (round(distr(gen)*10000))/100;
    myqueue.Enqueue(tmp);
    std::cout<<tmp<<" ";
  }
  return myqueue;
}
lasd::QueueLst<std::string> generateRandomQueueListString(){
  ulong dim = getDimension();
  std::string tmp;
  QueueLst<std::string> myqueue;
  std::default_random_engine gen(std::random_device{}());
  std::uniform_int_distribution<int> dist(1,5);
  std::cout<<std::endl<<std::endl<<"Elements of the Queue list:"<<std::endl;
  for(unsigned long i = 0; i < dim; ++i){
    tmp = generateRandomString(dist(gen));
    myqueue.Enqueue(tmp);
    std::cout<<tmp<<" ";
  }
  return myqueue;
}

lasd::QueueVec<int> generateRandomQueueVecInt(){
  ulong dim = getDimension();
  int tmp;
  QueueVec<int> myqueue;
  std::default_random_engine gen(std::random_device{}());
  std::uniform_int_distribution<int> dist(0,1000);
  std::cout<<std::endl<<std::endl<<"Elements of the Queue vector:"<<std::endl;
  for(ulong i = 0 ; i<dim ; ++i){
    tmp = dist(gen);
    myqueue.Enqueue(tmp);
    std::cout<<tmp<<" ";
  }
  return myqueue;
  }
lasd::QueueVec<float> generateRandomQueueVecFloat(){
  ulong dim = getDimension();
  float tmp;
  QueueVec<float> myqueue;
  std::default_random_engine gen(std::random_device{}());
  std::uniform_real_distribution<float> distr(0,5);
  std::cout<<std::endl<<std::endl<<"Elements of the Queue vector:"<<std::endl;
  for(unsigned long i = 0; i < dim; ++i){
    tmp = (round(distr(gen)*10000))/100;
    myqueue.Enqueue(tmp);
    std::cout<<tmp<<" ";
  }
  return myqueue;
}
lasd::QueueVec<std::string> generateRandomQueueVecString(){
  ulong dim = getDimension();
  std::string tmp;
  QueueVec<std::string> myqueue;
  std::default_random_engine gen(std::random_device{}());
  std::uniform_int_distribution<int> dist(1,5);
  std::cout<<std::endl<<std::endl<<"Elements of the Queue vector:"<<std::endl;
  for(unsigned long i = 0; i < dim; ++i){
    tmp = generateRandomString(dist(gen));
    myqueue.Enqueue(tmp);
    std::cout<<tmp<<" ";
  }
  return myqueue;
  }

lasd::StackLst<int> generateRandomStackLstInt(){
  ulong dim = getDimension();
  StackLst<int> myvec;
  std::default_random_engine gen(std::random_device{}());
  std::uniform_int_distribution<int> dist(0,1000);
  std::cout<<std::endl<<std::endl<<"Elements of the vector:"<<std::endl;
  for(ulong i = 0 ; i<dim ; ++i){
    myvec.Push(dist(gen));
    std::cout<<myvec.Top()<<" ";
  }
  return myvec;
}
lasd::StackLst<float> generateRandomStackLstFloat(){
  ulong dim = getDimension();
  StackLst<float> myvec;
  std::default_random_engine gen(std::random_device{}());
  std::uniform_real_distribution<float> distr(0,5);
  std::cout<<std::endl<<std::endl<<"Elements of the vector:"<<std::endl;
  for(unsigned long i = 0; i < dim; ++i){
    myvec.Push( float((round(distr(gen)*10000))/100) );
    std::cout<<myvec.Top()<<" ";
  }
  return myvec;
}
lasd::StackLst<std::string> generateRandomStackLstString(){
  ulong dim = getDimension();
  StackLst<std::string> myvec;
  std::default_random_engine gen(std::random_device{}());
  std::uniform_int_distribution<int> dist(1,5);
  std::cout<<std::endl<<std::endl<<"Elements of the vector:"<<std::endl;
  for(unsigned long i = 0; i < dim; ++i){
    myvec.Push( generateRandomString(dist(gen)) );
    std::cout<<myvec.Top()<<" ";
  }
  return myvec;
}

lasd::StackVec<int> generateRandomStackVecInt(){
  ulong dim = getDimension();
  StackVec<int> myvec;

  std::default_random_engine gen(std::random_device{}());
  std::uniform_int_distribution<int> dist(0,1000);
  std::cout<<std::endl<<std::endl<<"Elements of the vector:"<<std::endl;
  for(ulong i = 0 ; i<dim ; ++i){
    myvec.Push(dist(gen));
    std::cout<<myvec.Top()<<" ";
  }
  return myvec;
}
lasd::StackVec<float> generateRandomStackVecFloat(){
  ulong dim = getDimension();
  StackVec<float> myvec;
  std::default_random_engine gen(std::random_device{}());
  std::uniform_real_distribution<float> distr(0,5);
  std::cout<<std::endl<<std::endl<<"Elements of the vector:"<<std::endl;
  for(unsigned long i = 0; i < dim; ++i){
    myvec.Push( (round(distr(gen)*10000))/100 );
    std::cout<<myvec.Top()<<" ";
  }
  return myvec;
}
lasd::StackVec<std::string> generateRandomStackVecString(){
  ulong dim = getDimension();
  StackVec<std::string> myvec;
  std::default_random_engine gen(std::random_device{}());
  std::uniform_int_distribution<int> dist(1,5);
  std::cout<<std::endl<<std::endl<<"Elements of the vector:"<<std::endl;
  for(unsigned long i = 0; i < dim; ++i){
    myvec.Push(generateRandomString(dist(gen)));
    std::cout<<myvec.Top()<<" ";
  }
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
