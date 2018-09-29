#include <iostream>
#include "tree.h"

using namespace std;

int main(int argc, char const *argv[]) {
  tree<int> Tree;

  Tree.insert(10);
  Tree.insert(7);
  Tree.insert(2);
  Tree.insert(12);
  Tree.insert(1);
  Tree.insert(14);
  Tree.insert(11);
  Tree.insert(13);

  Tree.printTree();

  cout << "Peso: " << Tree.weight() << endl;

  Tree.remove(7);

  cout << "Inorder: ";
  Tree.printInorderReal();
  cout << "Posorder: ";
  Tree.printPosorderReal();
  cout << "Preorder: ";
  Tree.printPreorderReal();

  Tree.printTree();

  cout << "Peso: " << Tree.weight() << endl;

  Iterator<int> It=new Iterator<int>(Tree.begin());
  for (int i=0; i<Tree.weight(); i++){
    ++It;
  }

  return 0;
}
