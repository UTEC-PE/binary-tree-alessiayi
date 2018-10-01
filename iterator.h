#include "nodes.h"
#include <stack>

using namespace std;

template<typename T>
class Iterator {
  private:
  Node<T>* current;
  Node<T>* previous;
  stack<Node<T>*> Stack;

  public:
  Iterator(): current(nullptr), previous(nullptr){}
  Iterator(Node<T>* root): current(root), previous(nullptr){
    Stack.push(current);
    while (current->left) {
      current=current->left;
      Stack.push(current);
    }
  };

  Iterator<T> operator++(){
    if (!current){
      throw "No";
    }
    if (!(current -> left || current -> right) ||
        (current -> left && current -> right && previous==current -> right) ||
        (!current -> right && current -> left && previous==current -> left) ||
        previous==current -> right){
      do{
        previous = Stack.top();
        Stack.pop();
        if (Stack.empty()) {
          cout<<"Vacio\n"; current=nullptr; return *this;
        }
        current=Stack.top();
      }
      while (previous==current -> right);
      return *this;
    }

    if (current -> left && previous!=current -> left){
      current=current -> left;
      Stack.push(current);
      return *this;
    }

    if (current -> right && previous!=current -> right){
      current = current->right;
      Stack.push(current);
      while (current -> left) {
        current=current -> left;
        Stack.push(current);
      }
      return *this;
    }
    current=nullptr;
    return *this;
  };

  T operator*(){
    if (!current) {
      throw "No";
    }
    return current -> data;
  }

  bool operator!=(Iterator<T> cmp){
    return current!=cmp.current;
  }
};
