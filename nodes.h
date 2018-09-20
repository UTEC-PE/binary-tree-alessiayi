#include <string>

using namespace std;

struct Node{
  string data;
  Node* left;
  Node* right;

  Node(string value) : data(value), left(nullptr), right(nullptr){};
};
