#include "nodes.h"
#include <stack>

using namespace std;

template<typename T>
class Iterator {
    private:
        Node<T>* current;
        Node<T>* previous;

    public:
        Iterator(): current(nullptr), previous(nullptr){};
        Iterator(Node<T>* node): current (node){};

        Iterator<T> operator++(){
          stack<Node<T>*> thestack;
          // if (!current){
          //   cout << "Vacio";
          //   return;
          // }
          // else if (!current -> left && !current -> right){
          //   stack.push(current);
          // }
          // if (current -> left){
          //   current=current -> left;
          //
          // }
          if (current->left && current->left!=previous) {
            previous = current;
            current=current->left;
            thestack.push(current);
            return *this;
          }

        //go right
          if (current->right && current->right!=previous) {
            previous = current;
            current=current->right;
            thestack.push(current);
            return *this;
          }

        //go up
        previous = current;
        thestack.pop();
        current = thestack.top();
        return *this;
        }

};
