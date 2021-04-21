
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
Implementation ChooseImplementation();
void UseChosenType(DataStructure, DataType, Implementation);

lasd::QueueLst<int> generateRandomQueueListInt();
lasd::QueueLst<float> generateRandomQueueListFloat();
lasd::QueueLst<std::string> generateRandomQueueListString();
lasd::QueueVec<int> generateRandomQueueVecInt();
lasd::QueueVec<float> generateRandomQueueVecFloat();
lasd::QueueVec<std::string> generateRandomQueueVecString();
lasd::StackLst<int> generateRandomStackLstInt();
lasd::StackLst<float> generateRandomStackLstFloat();
lasd::StackLst<std::string> generateRandomStackLstString();
lasd::StackVec<int> generateRandomStackVecInt();
lasd::StackVec<float> generateRandomStackVecFloat();
lasd::StackVec<std::string> generateRandomStackVecString();

template <typename T>
void StackIntFunctions(T&);

template <typename T>
void PushInt(T&);
template <typename T>
void Pop(T&);
template <typename T>
void TopNPop(T&);
template <typename T>
void Top(T&);
template <typename T>
void Empty(T&);
template <typename T>
void Size(T&);
template <typename T>
void Clear(T&);
std::string generateRandomString(ulong);
ulong getDimension();

/* ************************************************************************** */
#include"test.cpp"
#endif
