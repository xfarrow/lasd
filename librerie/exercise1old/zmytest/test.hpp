
#ifndef MYTEST_HPP
#define MYTEST_HPP

enum class DataStructure{vector,list};
enum class DataType{integer,ffloat,sstring};
void menu();
DataType ChooseDataType(); //choose data type
DataStructure ChooseDataStructure();
void UseChosenType(DataStructure, DataType);
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


#endif
