#ifndef MYTEST_HPP
#define MYTEST_HPP
#include"../binarytree/lnk/binarytreelnk.hpp"
#include"../bst/bst.hpp"

/* ************************************************************************** */

enum class DataType{integer,ffloat,sstring};

/* ---- integer functions ---- */

template <typename T>
void IntegerFunctions(T&);

template <typename T>
void ProductsElementsLessThan(T&);

void AccumulateProduct(const int&, const void*, void*);

/* ----- float functions ----- */

template <typename T>
void FloatFunctions(T&);

template <typename T>
void SumElementsGreaterThan(T&);

void AccumulateSum(const float&, const void*, void*);

/* ----- string functions ----- */

template <typename T>
void StringFunctions(T&);

template <typename T>
void ConcatLessThan(T&);

void ConcatAString(const std::string&, const void*, void*);

/* ---- shared functions ---- */
void menu();

template <template <typename...> class Tree, typename DTType>
void PrintTree(Tree<DTType>&);

template <typename Data>
void PrintSingleElement(Data& data, void* _);

template <template <typename...> class Tree, typename DTType>
void CheckExistence(Tree<DTType>& tree);

template <template <typename...> class Tree, typename DTType>
void InsertElement(Tree<DTType>&);

template <template <typename...> class Tree, typename DTType>
void RemoveElement(Tree<DTType>&);

template <typename T>
void PrintMinimum(T&);

template <typename T>
void PrintMinimumNDelete(T&);

template <typename T>
void RemoveMin(T&);

template <typename T>
void PrintMaximum(T&);

template <typename T>
void PrintMaximumNDelete(T&);

template <typename T>
void RemoveMax(T&);

template <template <typename...> class Tree, typename DTType>
void PrintPredecessor(Tree<DTType>&);

template <template <typename...> class Tree, typename DTType>
void PredecessorNRemove(Tree<DTType>&);

template <template <typename...> class Tree, typename DTType>
void RemovePredecessor(Tree<DTType>&);

template <template <typename...> class Tree, typename DTType>
void PrintSuccessor(Tree<DTType>&);

template <template <typename...> class Tree, typename DTType>
void SuccessorNRemove(Tree<DTType>&);

template <template <typename...> class Tree, typename DTType>
void RemoveSuccessor(Tree<DTType>&);

template <typename T>
void NodeOperations(T&);


/* ----- generator functions ----- */

DataType ChooseDataType(); //choose data type
void UseChosenType(DataType);
template <typename T>
T GenerateIntegerBST(T&);
template <typename T>
T GenerateFloatBST(T&);
template <typename T>
T GenerateStringsBST(T&);
std::string generateRandomString(ulong);
ulong getDimension();

#endif
