
#ifndef MYTEST_HPP
#define MYTEST_HPP

#include"../matrix/matrix.hpp"
#include"../matrix/csr/matrixcsr.hpp"
#include"../matrix/vec/matrixvec.hpp"
#include "../zlasdtest/test.hpp"
using namespace std;
using namespace lasd;

enum class DataType{integer,ffloat,sstring};
enum class Implementation{vector,yale};

void menu();

DataType ChooseDataType(); //choose data type

Implementation ChooseImplementation();

/* ----- integer functions ----- */

template <typename T>
void IntegerFunctions(T&);

template <typename T>
void ProductsElementsLessThan(T&);

void AccumulateProduct(const int&, const void*, void*);

template <typename T>
void Double(T&);

void MultiplyAnElement(int&, void*);

/* ----- float functions ----- */

template <typename T>
void FloatFunctions(T&);

template <typename T>
void SumElementsGreaterThan(T&);

void AccumulateSum(const float&, const void*, void*);

template <typename T>
void CubeElements(T&);

void Exponentiation(float&, void*);

/* ----- string functions ----- */

template <typename T>
void StringFunctions(T&);

template <typename T>
void ConcatLessThan(T&);

void ConcatAString(const string&, const void*, void*);

template <typename T>
void HeadConcat(T&);

void HeadConcatMapAux(string&, void*);

/* ----- shared functions ----- */

template <typename T>
void Print(T&);

template <template <typename...> class Matrix, typename Data>
void PrintElements(Matrix<Data>& mtx);

template <typename Data>
void PrintSingleElement(Data&, void*);

template <typename T>
void CheckExistenceOfCell(T&);

template <template <typename...> class Matrix, typename Data>
void CheckExistenceOfElement(Matrix<Data>&);

template <typename T>
void Insert(T&);

template <typename T>
void Read(const T&);

template <typename T>
void Resize(T& mtx);

/* ----- generator functions ----- */

void UseChosenType(Implementation, DataType);

template <typename T>
T GenerateIntegerMat(T&);

template <typename T>
T GenerateFloatMat(T&);

template <typename T>
T GenerateStringsMat(T&);

std::string generateRandomString(ulong);

#endif
