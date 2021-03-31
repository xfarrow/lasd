
#ifndef MYTEST_HPP
#define MYTEST_HPP

enum class DataStructure{vector,list};
enum class DataType{integer,double,string};
void menu();
DataType ChooseDataType();
void UseChosenType(DataStructure, DataType);
DataStructure ChooseDataStructure();

#endif
