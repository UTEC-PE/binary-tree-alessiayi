#include <iostream>
#include "tree.h"

using namespace std;

int main(int argc, char const *argv[]) {
  tree Tree;

  Tree.constructTree(3);
  Tree.constructTree(10);
  Tree.constructTree(7);
  Tree.constructTree(2);
  Tree.constructTree(0);
  Tree.constructTree(6);
  Tree.constructTree(14);

  Tree.printTree();
  return 0;
}
