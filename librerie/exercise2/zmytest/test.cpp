#include"test.hpp"
#include<iostream>
#include<random>
#include "../zlasdtest/test.hpp"
using namespace lasd;

void menu(){
/*
  QueueVec<int> q1;
  q1.Enqueue(4);
  q1.Enqueue(0);
  q1.Enqueue(3);
  q1.Enqueue(1);
  q1.Enqueue(2);
  q1.HeadNDequeue();
  q1.Enqueue(5);

  QueueVec<int> q2;
  q2 = std::move(q1);

  QueueVec<int> q3(std::move(q1));
  std::cout<<q1.Head();
  */
  QueueLst<int> q1;
  q1.Enqueue(4);
  q1.Enqueue(0);
  q1.Enqueue(3);
  q1.Enqueue(1);
  q1.Enqueue(2);

  // QueueLst<int>* tmp = new QueueLst<int>(q1);
  // (*tmp).HeadNDequeue();
  // (*tmp).HeadNDequeue();
  // (*tmp).HeadNDequeue();
  // (*tmp).HeadNDequeue();
  // (*tmp).HeadNDequeue();



  // QueueLst<int> q2;
  // q2 = std::move(q1);
  //
  // q2.HeadNDequeue();
  // q2.HeadNDequeue();
  // q2.HeadNDequeue();
  // q2.HeadNDequeue();
  // q2.HeadNDequeue();


  QueueVec<int> quevec;
  quevec.Enqueue(0);
  quevec.Enqueue(1);
  QueueVec<int> newquevec = quevec;

  if(quevec == newquevec) std::cout<<"uguali";

}
