#include <sstream>
#include "iterator.h"

using namespace std;

template<typename T>
class tree{
  private:
      Node<T>* root;
      Node<T>* current;
      Node<T>* move;
      int count;

  public:
  tree():root(nullptr),current(nullptr), move(nullptr){};

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

  void insert(T num){
    //izquierda, menor
    //derecha, mayor
    if (!root){
      current=root=move=new Node<T>(num);
      count+=1;
      return;
    }
    Node<T>* to = new Node<T>(num);
    if (current -> data==num){
      throw "Ya existe";
    }
    else if (current -> data > num){
      if (current -> left){
        current=current->left;
        insert(num);
      }
      else{
        current -> left=to;
        count++;
        current=root;
      }
    }
    else{
      if (current -> right){
        current=current -> right;
        insert(num);
      }
      else{
        current -> right=to;
        count++;
        current=root;
      }
    }
  }

  void swapValues(Node<T>* num, Node<T>* del){
    T aux = del->data;
    del->data = num->data;
    num->data = aux;
  }

  bool isLeaf(Node<T>* tmp){
    if (tmp -> left || tmp -> right){
      return false;
    }
    else{
      return true;
    }
  }

  void find(T num){
    if (move -> data==num){
      return;
    }
    else if (move -> data > num){
      move=move->left;
      find(num);
    }
    else{
      move=move -> right;
      find(num);
    }
  }

  void remove(T num){
    if (!root){
      cout << "Vacio";
      return;
    }
    find(num);
    if (current -> right==move || current -> left==move){
      if (move -> left && !move -> right){
        current -> left=move -> left;
        count-=1;
      }
      else if (!move -> left && move -> right){
        current -> right=move -> right;
        count--;
      }
      else if (isLeaf(move)){
          if (current -> right){
            current -> right=nullptr;
          }
          else{
            current -> left=nullptr;
          }
          count--;
      }
      else{
        cout << "NU";
        count--;
      }
      current=root;
    }
    else{
      if (current -> data > num){
        current=current -> left;
        remove(num);
      }
      else{
        current=current -> right;
        remove(num);
      }
    }
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

  int weight(){
    return count;
  }

  Node<T>* begin(){
    return current;
  }

};
