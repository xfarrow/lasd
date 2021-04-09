
#ifndef MYTEST_HPP
#define MYTEST_HPP
#include<iostream>
#include"../vector/vector.hpp"
#include"../list/list.hpp"
enum class DataStructure{vector,list};
enum class DataType{integer,ffloat,sstring};
void menu();
DataType ChooseDataType(); //choose data type
DataStructure ChooseDataStructure();
void UseChosenType(DataStructure, DataType);
lasd::Vector<int> generateVectorOfIntegers();
lasd::Vector<float> generateVectorOfFloat();
lasd::Vector<std::string> generateVectorOfStrings();
lasd::List<std::string> generateListOfStrings();
lasd::List<float> generateListOfFloat();
lasd::List<int> generateListOfIntegers();
std::string generateRandomString(ulong dim);

void VectorIntegerFunctions(lasd::Vector<int>);
void VectorFloatFunctions(lasd::Vector<float>);
void VectorStringFunctions(lasd::Vector<std::string>);
template <typename Data>
void ShowFirstElement(lasd::Vector<Data>&);
template <typename Data>
void ShowLastElement(lasd::Vector<Data>&);
template <typename Data>
void ShowElementWithASpecificIndex(lasd::Vector<Data>&);
template <typename Data>
void ShowAllElements(lasd::Vector<Data>&);
template <typename Data>
void PrintSingleElement(Data&, void*);
template <typename Data>
void CheckElementExists(lasd::Vector<Data>&);
void SumLessThan(lasd::Vector<int>&);
void AccumulateSum(const int&, const void*, void*);
void DoubleIntegers(lasd::Vector<int>&);
void DoubleAnInteger(int&, void*);
void AccumulateProduct(const float&, const void*, void*);
void ProductMoreThan(lasd::Vector<float>&);
void SquareAFloat(float&, void*);
void SquareFloats(lasd::Vector<float>&);
void ConcatLessThan(lasd::Vector<std::string>&);
void ConcatAux(const std::string&, const void*, void*);
void Uppercase(lasd::Vector<std::string>&);
void UppercaseAString(std::string&, void*);
void ListIntegerFunctions(lasd::List<int>);
void ListFloatFunctions(lasd::List<float>);
void ListStringFunctions(lasd::List<std::string>);
template <typename Data>
void ShowFirstElement(lasd::List<Data>&);
template <typename Data>
void ShowLastElement(lasd::List<Data>&);
template <typename Data>
void ShowElementWithASpecificIndex(lasd::List<Data>&);
ulong getDimension();
/*
void ChooseDimension(ulong&);
LinearContainer<Data> GenerateRandomStructure(const ulong&);
void ViewElement(const LinearContainer<Data>&);
void PrintAllElements(const LinearContainer<Data>&);
void PrintElement(Data&, void*); // funzione richiamata dalla map
void CheckExists(const LinearContainer<Data>&);
void ChooseFoldFunction(const LinearContainer<Data>&);
void SumLessThan(const LinearContainer<int>&, const ulong&);
void SumLessThanFold(int&, const void*, void*);
void ProductMoreThan(const LinearContainer<float>&, const ulong&);
void ProductMoreThanFold(float&, const void*, void*);
void ConcatStringLessThan(const LinearContainer<string>&, const ulong&);
void ConcatStringLessThanFold(string&, const void*, void*);

//7
void ChooseMapFunction(const LinearContainer<Data>);
void DoubleN(const LinearContainer<int>&, const ulong&);
void DoubleNMap(int&, void*);

void SquareN(const LinearContainer<float>&, const ulong&);
void SquareNMap(float&, void*);

void Uppercase(const LinearContainer<string>&, const ulong&);
void UppercaseMap(string&, void*);
*/

#endif
