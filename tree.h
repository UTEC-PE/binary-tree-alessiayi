#include "nodes.h"
#include <sstream>

using namespace std;

class tree{
  private:
      Node* head;

  public:
  tree():head(nullptr){};

  void constructTree(int num){
    if (!head){
      Node* tohead = new Node(num);
      head=tohead;
    }
    if (head -> data > num){
      Node* toleft = new Node(num);
      if (head -> left){
        head=head->left;
        constructTree(num);
      }
      else{
        head -> left=toleft;
      }
    }
    else{
      Node* toright = new Node(num);
      if (head -> right){
        head=head -> right;
        constructTree(num);
      }
      else{
        head -> right=toright;
      }
    }
  }
};
