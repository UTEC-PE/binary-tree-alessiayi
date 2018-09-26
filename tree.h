
#include "iterator.h"
#include <sstream>

using namespace std;

template<typename T>
class tree{
  private:
      Node<T>* root;
      Node<T>* current;

  public:
  tree():root(nullptr),current(nullptr){};

  #define COUNT 10
  void print2DUtil(Node<T> *root, int space){
    if (root == NULL)
        return;

    space += COUNT;

    print2DUtil(root->right, space);

    cout<< "\n";
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data <<endl;

    print2DUtil(root->left, space);
  }

  void print2D(Node<T>* root){
     print2DUtil(root, 0);
  }

  void printTree(){
    print2D(root);
  }

  void constructTree(T num){
    if (!root){
      current=root=new Node<T>(num);
    }
    else{
      Node<T>* to = new Node<T>(num);
      if (current -> data==num){
        throw "Ya existe";
      }
      if (current -> data > num){
        if (current -> left){
          current=current->left;
          constructTree(num);
        }
        else{
          current -> left=to;
          current=root;
        }
      }
      else{
        if (current -> right){
          current=current -> right;
          constructTree(num);
        }
        else{
          current -> right=to;
          current=root;
        }
      }
    }
  }

  void removeTree(T num){
    //0 hijos
    //1 hijos
    //2 hijos
  }

  void printInorder(Node<T>* start){
    //inorder, left root right
    if (start -> left){
      printInorder(start -> left);
    }

    cout << start -> data << " ";

    if (start -> right){
      printInorder(start -> right);
    }
  }

  void printInorderReal(){
    printInorder(current);
  }

  void printPosorder(Node<T>* start){
    //posorder, left right root
    if (start -> left){
      printPosorder(start -> left);
    }

    if (start -> right){
      printPosorder(start -> right);
    }

    cout << start -> data << " ";
  }

  void printPosorderReal(){
    printPosorder(current);
  }

  void printPreorder(Node<T>* start){
    //preorder, root left right
    cout << start -> data << " ";

    if (start -> left){
      printPreorder(start -> left);
    }

    if (start -> right){
      printPreorder(start -> right);
    }
  }

  void printPreorderReal(){
    printPreorder(current);
  }

};
