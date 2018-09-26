#include <iostream>
#include "tree.h"

using namespace std;

int main(int argc, char const *argv[]) {
  tree<int> Tree;

  Tree.constructTree(10);
  Tree.constructTree(7);
  Tree.constructTree(2);
  Tree.constructTree(0);
  Tree.constructTree(12);
  Tree.constructTree(6);
  Tree.constructTree(14);
  Tree.constructTree(11);

  Tree.printTree();
  cout << "Inorder: ";
  Tree.printInorderReal();
  cout << endl;
  cout << "Posorder: ";
  Tree.printPosorderReal();
  cout << endl;
  cout << "Preorder: ";
  Tree.printPreorderReal();
  cout << endl;


  return 0;
}
