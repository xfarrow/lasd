
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

void menu(){
  cout<<"MY TESTS\n";
  Vector<string> vec(10);
  vec[0] = "A";
  vec[1] = "B";
  vec[2] = "C";
  vec[3] = "D";
  vec[4] = "E";
  vec[5] = "F";
  vec[6] = "G";
  vec[7] = "H";
  vec[8] = "I";
  vec[9] = "L";

  BinaryTreeLnk<string> bt1(vec);
  BinaryTreeLnk<string> bt2(vec);
//  if(bt1 == bt2) cout<<"uguali";

}



#endif
