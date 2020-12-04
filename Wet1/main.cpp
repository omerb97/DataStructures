#include <iostream>
#include "AVLtree.h"

int main()
{
    AVLtree<int> *t = new AVLtree<int>();

    t->insert(9);
    t->insert(5);
    t->insert(10);
    t->insert(0);
    t->insert(6);
    t->insert(11);
    t->insert(-1);
    t->insert(1);
    t->insert(2);

    t->preOrder(); //needs to be: 9 1 0 -1 5 2 6 10 11

    std::cout << std::endl;

    t->deleteNode(10);

    t->preOrder();//needs to be: 1 0 -1 9 5 2 6 11

    return 0;
}
