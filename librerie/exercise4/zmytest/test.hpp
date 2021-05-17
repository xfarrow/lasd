#ifndef MYTEST_HPP
#define MYTEST_HPP
#include"../binarytree/lnk/binarytreelnk.hpp"
#include"../bst/bst.hpp"

/* ************************************************************************** */

enum class DataType{integer,ffloat,sstring};

/* ---- integer functions ---- */

template <typename Data>
void IntegerFunctions(lasd::BST<Data>&);

template <typename Data>
void ProductsElementsLessThan(lasd::BST<Data>&);

void AccumulateProduct(const int&, const void*, void*);

/* ----- float functions ----- */

template <typename Data>
void FloatFunctions(lasd::BST<Data>&);

template <typename Data>
void SumElementsGreaterThan(lasd::BST<Data>&);

void AccumulateSum(const float&, const void*, void*);

/* ----- string functions ----- */

template <typename Data>
void StringFunctions(lasd::BST<Data>&);

template <typename Data>
void ConcatLessThan(lasd::BST<Data>&);

void ConcatAString(const std::string&, const void*, void*);

/* ---- shared functions ---- */
void menu();

template <typename Data>
void PrintTree(lasd::BST<Data>&);

template <typename Data>
void PrintSingleElement(Data& data, void* _);

template <typename Data>
void CheckExistence(lasd::BST<Data>& tree);

template <typename Data>
void InsertElement(lasd::BST<Data>&);

template <typename Data>
void RemoveElement(lasd::BST<Data>&);

template <typename Data>
void PrintMinimum(lasd::BST<Data>&);

template <typename Data>
void PrintMinimumNDelete(lasd::BST<Data>&);

template <typename Data>
void RemoveMin(lasd::BST<Data>&);

template <typename Data>
void PrintMaximum(lasd::BST<Data>&);

template <typename Data>
void PrintMaximumNDelete(lasd::BST<Data>&);

template <typename Data>
void RemoveMax(lasd::BST<Data>&);

template <typename Data>
void PrintPredecessor(lasd::BST<Data>&);

template <typename Data>
void PredecessorNRemove(lasd::BST<Data>&);

template <typename Data>
void RemovePredecessor(lasd::BST<Data>&);

template <typename Data>
void PrintSuccessor(lasd::BST<Data>&);

template <typename Data>
void SuccessorNRemove(lasd::BST<Data>&);

template <typename Data>
void RemoveSuccessor(lasd::BST<Data>&);

template <typename T>
void NodeOperations(T&);


/* ----- generator functions ----- */

DataType ChooseDataType();

void UseChosenType(DataType);

lasd::BST<int> GenerateIntegerBST(lasd::BST<int>&);

lasd::BST<float> GenerateFloatBST(lasd::BST<float>&);

lasd::BST<std::string> GenerateStringsBST(lasd::BST<std::string>&);

std::string generateRandomString(ulong);

ulong getDimension();

#endif
