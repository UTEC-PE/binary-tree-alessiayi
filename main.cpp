#include <iostream>
#include "tree.h"

using namespace std;

int main(int argc, char const *argv[]) {
  tree<int> Tree;

  Tree.insert(9);
  Tree.insert(20);
  Tree.insert(19);
  Tree.insert(7);
  Tree.insert(2);
  Tree.insert(28);
  Tree.insert(8);
  Tree.insert(1);
  Tree.insert(13);

  Tree.printTree();

  cout << "Peso: " << Tree.weight() << endl;

  cout << "Inorder: ";
  Tree.printInorderReal();
  cout << "Posorder: ";
  Tree.printPosorderReal();
  cout << "Preorder: ";
  Tree.printPreorderReal();
  cout << endl;

  Tree.remove(20);
  Tree.remove(7);

  Tree.printTree();

  cout << "Peso: " << Tree.weight() << endl;

  cout << "Inorder: ";
  Tree.printInorderReal();
  cout << "Posorder: ";
  Tree.printPosorderReal();
  cout << "Preorder: ";
  Tree.printPreorderReal();
  cout << endl;

  Iterator<int> It=Tree.begin();

  cout << *It << " ";
  for (int i=0; i<Tree.weight()-1; i++){
    cout << *++It << " ";
  }

  return 0;
}
