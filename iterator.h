#include "nodes.h"

template<typename T>
class iterator {
    private:
        Node<T>* current;

    public:
        iterator(): current(nullptr){};
        iterator(Node<T>* node): current (node){};

        iterator<T> operator++(){
          //stack
        };
};
