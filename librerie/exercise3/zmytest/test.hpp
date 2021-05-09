
#ifndef MYTEST_HPP
#define MYTEST_HPP

#include"../vector/vector.hpp"
#include"../list/list.hpp"
#include"../queue/queue.hpp"
#include"../queue/lst/queuelst.hpp"
#include"../queue/vec/queuevec.hpp"
#include"../stack/stack.hpp"
#include"../stack/lst/stacklst.hpp"
#include"../stack/vec/stackvec.hpp"
#include"../iterator/iterator.hpp"
#include"../binarytree/binarytree.hpp"
#include"../binarytree/lnk/binarytreelnk.hpp"
#include"../binarytree/vec/binarytreevec.hpp"
#include<iostream>
using namespace std;
using namespace lasd;
/* ************************************************************************** */

enum class DataType{integer,ffloat,sstring};
enum class Implementation{vector,pointers};

void menu();

template <typename T>
void IntegerFunctions(T&);
template <typename T>
void FloatFunctions(T& bt);
template <typename T>
void StringFunctions(T&);

/* ----- integer functions ----- */
template <typename T>
void ProductsElementsLessThan(T&);
void AccumulateProduct(const int&, const void*, void*);
template <typename T>
void MultiplyByThree(T&);
void MultiplyAnElement(int&, void*);

/* ----- float functions ----- */
template <typename T>
void SumElementsGreaterThan(T&);
void AccumulateSum(const float&, const void*, void*);

/* ----- string functions ----- */
template <typename T>
void ConcatLessThan(T&);
void ConcatAString(const string&, const void*, void*);

template <typename T>
void HeadConcat(T&);
void HeadConcatMapAux(string&, void*);

template <typename T>
void CubeElements(T&);
void Exponentiation(float&, void*);

/* ----- shared functions ----- */
template <template <typename...> class Tree, typename DTType>
void PrintTree(Tree<DTType>&);
template <typename Data>
void PrintSingleElement(Data&, void*);
template <template <typename...> class Tree, typename DTType>
void CheckExistence(Tree<DTType>&);

template <template <typename...> class Tree, typename DTType>
void Iterators(Tree<DTType>&);

template <typename Iter>
void NavigateWithIterator(Iter&);

template <typename T>
void NodeOperations(T&);

/* ----- Generator functions ----- */
DataType ChooseDataType(); //choose data type
Implementation ChooseImplementation();
void UseChosenType(Implementation, DataType);
template <typename T>
T GenerateIntegerBT(T&);
template <typename T>
T GenerateFloatBT(T&);
template <typename T>
T GenerateStringsBT(T&);
std::string generateRandomString(ulong);
ulong getDimension();


#endif
