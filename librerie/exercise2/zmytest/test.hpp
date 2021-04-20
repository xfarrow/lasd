
#ifndef MYTEST_HPP
#define MYTEST_HPP
#include<iostream>
#include"../vector/vector.hpp"
#include"../list/list.hpp"
#include"../queue/queue.hpp"
#include"../queue/lst/queuelst.hpp"
#include"../queue/vec/queuevec.hpp"
#include"../stack/stack.hpp"
#include"../stack/lst/stacklst.hpp"
#include"../stack/vec/stackvec.hpp"
/* ************************************************************************** */
enum class DataStructure{stack,queue};
enum class DataType{integer,ffloat,sstring};
enum class Implementation{vector,list};
void menu();
DataType ChooseDataType(); //choose data type
DataStructure ChooseDataStructure();
void UseChosenType(DataStructure, DataType);

/* ************************************************************************** */
#include"test.cpp"
#endif
