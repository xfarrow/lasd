#include "test.hpp"
#include <random>
#include <iostream>

void menu(){

  DataType chosenDataType;
  Implementation chosenImplementation;

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
  }else if(choice==2){
    chosenImplementation = ChooseImplementation();
    chosenDataType = ChooseDataType();
    UseChosenType(chosenImplementation, chosenDataType);
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

Implementation ChooseImplementation(){
  unsigned short int choice;
  do{
    std::cout<<"\nChoose an implementation for the binary tree:"<<std::endl;
    std::cout<<" 1. Vector"<<std::endl;
    std::cout<<" 2. YALE (Compressed Sparse Row) "<<std::endl;
    cout<<endl<<" -> ";
    std::cin>>std::ws;
    std::cin>>choice;
  }while(!(choice>0 && choice<3));
  if(choice==1)
    return Implementation::vector;
  else if(choice==2)
    return Implementation::yale;
}

void UseChosenType(Implementation chosenImplementation, DataType chosenDataType){
  if(chosenImplementation == Implementation::vector){
    if(chosenDataType == DataType::integer){
      MatrixVec<int> mtx;
      mtx = GenerateIntegerMat<MatrixVec<int>>();
      IntegerFunctions(mtx);

    }else if(chosenDataType == DataType::ffloat){
      MatrixVec<float> mtx;
      mtx = GenerateFloatMat<MatrixVec<float>>();
      FloatFunctions(mtx);

    }else if(chosenDataType == DataType::sstring){
      MatrixVec<string> mtx;
      mtx = GenerateStringsMat<MatrixVec<string>>();
      StringFunctions(mtx);
    }
  }else if(chosenImplementation == Implementation::yale){
    if(chosenDataType == DataType::integer){
      MatrixCSR<int> mtx;
      mtx = GenerateIntegerMat<MatrixCSR<int>>();
      IntegerFunctions(mtx);

    }else if(chosenDataType == DataType::ffloat){
      MatrixCSR<float> mtx;
      mtx = GenerateFloatMat<MatrixCSR<float>>();
      FloatFunctions(mtx);

    }else if(chosenDataType == DataType::sstring){
      MatrixCSR<string> mtx;
      mtx = GenerateStringsMat<MatrixCSR<string>>();
      StringFunctions(mtx);
    }
  }
}

/* ----- integer functions ----- */

template <typename T>
void IntegerFunctions(T& mtx){
  unsigned short int choice;
  do{
    std::cout<<std::endl<<std::endl;
    std::cout<<"Choose one of the following options:"<<std::endl;
    std::cout<<" 1. Print elements"<<std::endl;
    std::cout<<" 2. Check existence of an element "<<std::endl;
    std::cout<<" 3. Check existence of a cell"<<std::endl;
    std::cout<<" 4. Product of integers less than 'n'"<<std::endl;
    std::cout<<" 5. Double all elements"<<std::endl;
    std::cout<<" 6. Insert in a position"<<std::endl;
    std::cout<<" 7. Read from a position"<<std::endl;
    std::cout<<" 8. Resize"<<std::endl;
    std::cout<<" 9. Go back"<<std::endl;
    std::cout<<" 10. Quit"<<std::endl;
    cout<<endl<<" -> ";
    std::cin>>std::ws;
    std::cin>>choice;
    std::cout<<std::endl;
    switch(choice){
      case 1:
        PrintElements(mtx);
        break;
      case 2:
        CheckExistenceOfElement(mtx);
        break;
      case 3:
        CheckExistenceOfCell(mtx);
        break;
      case 4:
        ProductsElementsLessThan(mtx);
        break;
      case 5:
        Double(mtx);
        break;
      case 6:
        Insert(mtx);
        break;
      case 7:
        Read(mtx);
        break;
      case 8:
        Resize(mtx);
        break;
      case 9:
        menu();
        break;
    }
  }while(choice!=9 && choice!=10);
}

template <typename T>
void ProductsElementsLessThan(T& mtx){
  int n, acc=1;
  void (*func)(const int&, const void*, void*) = AccumulateProduct;

  cout<<" Multipy all elements of the matrix whose value is less than ";
  cin>>ws>>n;

  mtx.FoldPreOrder(func, (void*)&n, (void*)&acc);
  cout<<"\n The result is "<<acc<<endl<<endl;
}

void AccumulateProduct(const int& data, const void* par, void* acc){
  if(data < (*(int*)par)){
      *(int*)acc *= data;
  }
}

template <typename T>
void Double(T& mtx){
  void (*fun)(int&, void*) = MultiplyAnElement;
  int par = 2;
  mtx.MapPreOrder(fun,(void*)&par);
  cout<<" Done.\n";
}

void MultiplyAnElement(int& data, void* par){
  data *= *(int*)par;
}

/* ----- float functions ----- */

template <typename T>
void FloatFunctions(T& mtx){
  unsigned short int choice;
  do{
    std::cout<<std::endl<<std::endl;
    std::cout<<"Choose one of the following options:"<<std::endl;
    std::cout<<" 1. Print elements"<<std::endl;
    std::cout<<" 2. Check existence of an element "<<std::endl;
    std::cout<<" 3. Check existence of a cell"<<std::endl;
    std::cout<<" 4. Sum of floats greater than 'n'"<<std::endl;
    std::cout<<" 5. Cube (-n)"<<std::endl;
    std::cout<<" 6. Insert in a position"<<std::endl;
    std::cout<<" 7. Read from a position"<<std::endl;
    std::cout<<" 8. Resize"<<std::endl;
    std::cout<<" 9. Go back"<<std::endl;
    std::cout<<" 10. Quit"<<std::endl;
    cout<<endl<<" -> ";
    std::cin>>std::ws;
    std::cin>>choice;
    std::cout<<std::endl;
    switch(choice){
      case 1:
        PrintElements(mtx);
        break;
      case 2:
        CheckExistenceOfElement(mtx);
        break;
      case 3:
        CheckExistenceOfCell(mtx);
        break;
      case 4:
        SumElementsGreaterThan(mtx);
        break;
      case 5:
        CubeElements(mtx);
        break;
      case 6:
        Insert(mtx);
        break;
      case 7:
        Read(mtx);
        break;
      case 8:
        Resize(mtx);
        break;
      case 9:
        menu();
        break;
    }
  }while(choice!=9 && choice!=10);
}

template <typename T>
void SumElementsGreaterThan(T& mtx){
  float n, acc = 0;
  void (*func)(const float&, const void*, void*) = AccumulateSum;

  cout<<" Sum all elements of the matrix whose value is greater than ";
  cin>>ws>>n;

  mtx.FoldPreOrder(func, (void*)&n, (void*)&acc);
  cout<<"\n The result is "<<acc<<endl<<endl;
}

void AccumulateSum(const float& data, const void* par, void* acc){
  if(data > (*(float*)par)){
      *(float*)acc += data;
  }
}

template <typename T>
void CubeElements(T& mtx){
  void (*fun)(float&, void*) = Exponentiation;
  float par = 3;
  mtx.MapPreOrder(fun,(void*)&par);
  cout<<" Done.\n";
}

void Exponentiation(float& data, void* par){
  data = (-1.0F) * pow(data , *(float*)par );
}

/* ----- string functions ----- */

template <typename T>
void StringFunctions(T& mtx){
  unsigned short int choice;
  do{
    std::cout<<std::endl<<std::endl;
    std::cout<<"Choose one of the following options:"<<std::endl;
    std::cout<<" 1. Print elements"<<std::endl;
    std::cout<<" 2. Check existence of an element "<<std::endl;
    std::cout<<" 3. Check existence of a cell"<<std::endl;
    std::cout<<" 4. Concatenate strings whose dimension is less or equal than 'n'"<<std::endl;
    std::cout<<" 5. Head concatenation of a string"<<std::endl;
    std::cout<<" 6. Insert in a position"<<std::endl;
    std::cout<<" 7. Read from a position"<<std::endl;
    std::cout<<" 8. Resize"<<std::endl;
    std::cout<<" 9. Go back"<<std::endl;
    std::cout<<" 10. Quit"<<std::endl;
    cout<<endl<<" -> ";
    std::cin>>std::ws;
    std::cin>>choice;
    std::cout<<std::endl;
    switch(choice){
      case 1:
        PrintElements(mtx);
        break;
      case 2:
        CheckExistenceOfElement(mtx);
        break;
      case 3:
        CheckExistenceOfCell(mtx);
        break;
      case 4:
        ConcatLessThan(mtx);
        break;
      case 5:
        HeadConcat(mtx);
        break;
      case 6:
        Insert(mtx);
        break;
      case 7:
        Read(mtx);
        break;
      case 8:
        Resize(mtx);
        break;
      case 9:
        menu();
        break;
    }
  }while(choice!=9 && choice!=10);
}

template <typename T>
void ConcatLessThan(T& mtx){
  int n;
  string concatenated = "";
  void (*func)(const string&, const void*, void*) = ConcatAString;

  cout<<" Concatenate all elements of the tree whose length is less or equal than ";
  cin>>ws>>n;

  mtx.FoldPreOrder(func, (void*)&n, (void*)&concatenated);
  cout<<"\n The result is "<< concatenated << endl << endl;
}

void ConcatAString(const string& data, const void* par, void* acc){
  if( ((int)data.length()) <= ((*(int*)par)) ){
    *(string*)acc = *(string*)acc + "-" + data;
  }
}

template <typename T>
void HeadConcat(T& mtx){
  void (*fun)(string&, void*) = HeadConcatMapAux;
  string par;

  cout<<" Concatenate in front the following string: ";
  cin>>ws;
  cin>>par;

  mtx.MapPreOrder(fun,(void*)&par);
  cout<<" Done.\n";
}

void HeadConcatMapAux(string& data, void* par){
  data = *(string*)par + data;
}

/* ----- shared functions ----- */

template <typename T>
void CheckExistenceOfCell(T& mtx){
  ulong row,column;
  cout<<"\n\n Check existence in the matrix of the cell with coordinates: \n";
  cout<<" Row: ";
  cin>>row;
  cout<<" Column: ";
  cin>>column;

  cout<<" The cell " << ( (mtx.ExistsCell(row,column))? "does" : "does not") << " exist\n\n";
}

template <typename T>
void Resize(T& mtx){
  ulong rows, columns;
  cout<<" The current dimension of the matrix is " << mtx.RowNumber() << " x " << mtx.ColumnNumber() << endl;
  cout<<" New dimension: \n";
  cout<<" Rows: ";
  cin>>rows;
  cout<<" Columns: ";
  cin>>columns;

  mtx.RowResize(rows);
  mtx.ColumnResize(columns);
  cout<<" Done.";

}

template <typename T>
void Read(const T& mtx){
  ulong row,column;
  cout<<" Insert the position of the element to read: \n";
  cout<<" Row: ";
  cin>>row;
  cout<<" Column: ";
  cin>>column;
  try{
    cout<<" The element in this position is: "<<mtx(row,column);
  }catch(out_of_range exc){
    cout<<" "<<exc.what();
  }catch(length_error exc2){
    cout<<" "<<exc2.what();
  }
}

template <typename T>
void Insert(T& mtx){
  ulong row,column;
  cout<<" Insert the position of the element to insert: \n";
  cout<<" Row: ";
  cin>>row;
  cout<<" Column: ";
  cin>>column;
  cout<<" Insert the element: ";
  try{
    cin>>mtx(row,column);
  }catch(out_of_range exc){
    cout<<exc.what();
  }
}

template <template <typename...> class Matrix, typename Data>
void CheckExistenceOfElement(Matrix<Data>& mtx){
  Data elementToLookFor;
  cout<<"\n\n Check existence in the matrix of: ";
  cin>>ws;
  cin>>elementToLookFor;
  cout<<" The element " << ( (mtx.FoldableContainer<Data>::Exists(elementToLookFor))? "does" : "does not") << " exist\n\n";
}

template <template <typename...> class Matrix, typename Data>
void PrintElements(Matrix<Data>& mtx){
  void (*PrinterFunction) (Data&, void*) = PrintSingleElement;

  cout<<"Pre order:\n";
  mtx.MapPreOrder(PrinterFunction, nullptr);
  cout<<endl<<endl;

  cout<<"Post order:\n";
  mtx.MapPostOrder(PrinterFunction, nullptr);
  cout<<endl<<endl;

  cout<<"Standard matrix-fashion (" << mtx.RowNumber() << " x " << mtx.ColumnNumber() << "):\n";
  for(ulong i=0 ; i<mtx.RowNumber() ; ++i){
    for(ulong j=0 ; j<mtx.ColumnNumber() ; ++j){
      cout<<"\t";
      if(mtx.ExistsCell(i,j))
        cout<<mtx(i,j);
      else
        cout<<"-";
    }
    cout<<endl;
  }

}

template <typename Data>
void PrintSingleElement(Data& data, void* _){
  std::cout << data << " ";
}

template <typename T>
void Print(T& mat){
  cout<<endl<<endl;
  cout<<"Rows: "<<mat.RowNumber()<<endl<<"Columns: "<<mat.ColumnNumber()<<endl<<"Size: "<<mat.Size()<<endl<<endl;
  for(ulong i=0; i<mat.RowNumber() ; ++i){
    for(ulong j=0 ; j<mat.ColumnNumber() ; ++j){
      cout<<"\t"<<mat(i,j);
    }
    cout<<endl;
  }
}

/* ----- generator functions ----- */

template <typename T>
T GenerateIntegerMat(){
  default_random_engine gen(random_device{}());
  uniform_int_distribution<int> random_dimension(1,20); // generates the dimensions of the matrix
  uniform_int_distribution<int> dist(0,100); // generates values inside the matrix

  ulong n_columns = random_dimension(gen);
  ulong n_rows = random_dimension(gen);
  ulong row, column, elements_to_insert;

  T matrix(n_rows, n_columns);
  MatrixCSR<bool> aux_matrix(n_rows, n_columns); //avoids to insert twice (or more) an element in a position

  cout<<" A "<<n_rows<<" x "<<n_columns<<" matrix has been generated.\n";
  do{
    elements_to_insert = getDimension();
  }while(elements_to_insert > n_rows*n_columns);

  for(ulong i=1 ; i<=elements_to_insert ; ++i){
    do{
      do{
        row = random_dimension(gen)-1;
      }while(row >= n_rows);

      do{
        column = random_dimension(gen)-1;
      }while(column >= n_columns);
    }while(aux_matrix.ExistsCell(row,column));

    aux_matrix(row,column) = true;
    matrix(row,column) = dist(gen);
  }
  return matrix;
}

template <typename T>
T GenerateFloatMat(){
  default_random_engine gen(random_device{}());
  uniform_int_distribution<int> random_dimension(1,20);
  uniform_real_distribution<double> dist(0,9);

  ulong n_columns = random_dimension(gen);
  ulong n_rows = random_dimension(gen);
  ulong row, column, elements_to_insert;

  T matrix(n_rows, n_columns);
  MatrixCSR<bool> aux_matrix(n_rows, n_columns); //avoids to insert twice (or more) an element in a position

  cout<<" A "<<n_rows<<" x "<<n_columns<<" matrix has been generated.\n";
  do{
    elements_to_insert = getDimension();
  }while(elements_to_insert > n_rows*n_columns);

  for(ulong i=1 ; i<=elements_to_insert ; ++i){
    do{
      do{
        row = random_dimension(gen)-1;
      }while(row >= n_rows);

      do{
        column = random_dimension(gen)-1;
      }while(column >= n_columns);

    }while(aux_matrix.ExistsCell(row,column));

    aux_matrix(row,column) = true;
    matrix(row,column) = dist(gen);
  }
  return matrix;
}

template <typename T>
T GenerateStringsMat(){
  default_random_engine gen(random_device{}());
  uniform_int_distribution<int> random_dimension(1,20);
  uniform_int_distribution<int> dist(1,5);

  ulong n_columns = random_dimension(gen);
  ulong n_rows = random_dimension(gen);
  ulong row, column, elements_to_insert;

  T matrix(n_rows, n_columns);
  MatrixCSR<bool> aux_matrix(n_rows, n_columns); //avoids to insert twice (or more) an element in a position

  cout<<" A "<<n_rows<<" x "<<n_columns<<" matrix has been generated.\n";

  do{
    elements_to_insert = getDimension();
  }while(elements_to_insert > n_rows*n_columns);

  for(ulong i=1 ; i<=elements_to_insert ; ++i){
    do{
      do{
        row = random_dimension(gen)-1;
      }while(row >= n_rows);

      do{
        column = random_dimension(gen)-1;
      }while(column >= n_columns);

    }while(aux_matrix.ExistsCell(row,column));

    aux_matrix(row,column) = true;
    matrix(row,column) = generateRandomString(dist(gen));
  }
  return matrix;

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
  std::cout<<" How many elements would you like to insert? ";
  std::cin>>dimension;
  return dimension;
}
