#include "nodes.h"
#include <sstream>

using namespace std;

class tree{
  private:
      Node* root;
      Node* head;

  public:
  tree():root(nullptr),head(nullptr){};

  #define COUNT 10
  void print2DUtil(Node *root, int space){
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    cout<< "\n";
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data <<endl;

    // Process left child
    print2DUtil(root->left, space);
  }

// Wrapper over print2DUtil()
void print2D(Node* root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}

  void constructTree(int num){
    if (!root){
      head=root=new Node(num);
    }
    else{
      Node* to = new Node(num);
      if (head -> data==num){
        throw "Ya existe";
      }
      if (head -> data > num){
        if (head -> left){
          head=head->left;
          constructTree(num);
        }
        else{
          head -> left=to;
          head=root;
        }
      }
      else{
        if (head -> right){
          head=head -> right;
          constructTree(num);
        }
        else{
          head -> right=to;
          head=root;
        }
      }
    }
  };

  void printTree(){
    print2D(root);
  }
};
