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
      break;
    default:
      std::cout<<"An error has occurred"<<std::endl;
      return;
  }
  UseChosenType(chosenDataStructure,chosenDataType);
}

DataStructure ChooseDataStructure(){
  unsigned short int choice;
  do{
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
    std::cout<<"1. Integer"<<std::endl;
    std::cout<<"2. Double"<<std::endl;
    std::cout<<"3. String"<<std::endl;
    std::cin>>std::ws;
    std::cin>>choice;
  }while(!(choice>0 && choice<4));
  if(choice==1)
    return DataType::integer;
  else if(choice==2)
    return DataType::ddouble;
  else if(choice==3)
    return DataType::sstring;
}
void UseChosenType(DataStructure chosenDataStructure, DataType chosenDataType){
  std::cout<<"\tTest on ";
  if(chosenDataStructure == DataStructure::vector)
    std::cout<<"vector of ";
  else if(chosenDataStructure == DataStructure::list)
    std::cout<<"list of ";

  if(chosenDataType == DataType::integer)
    std::cout<<" integers"<<std::endl;
  else if(chosenDataType == DataType::ddouble)
    std::cout<<" doubles"<<std::endl;
  else if(chosenDataType == DataType::sstring)
    std::cout<<" strings"<<std::endl;
}
