#include <iostream>
#include "tree.h"

using namespace std;

int main(int argc, char const *argv[]) {
  tree Tree;
  int count=0;
  int num;
  while (count < 10){
    cin >> num;
    Tree.constructTree(num);
    count+=1;
  }

  return 0;
}
