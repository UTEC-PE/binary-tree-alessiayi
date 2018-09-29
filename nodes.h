
template<typename T>
struct Node{
  int data;
  Node<T>* left;
  Node<T>* right;

  Node(int value) : data(value), left(nullptr), right(nullptr){};
};
