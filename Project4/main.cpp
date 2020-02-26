#include <fstream>
#include <iostream>

#include "MyAVLTree.hpp"

int main()
{
    MyAVLTree<int, int> tree;
    tree.insert(5, 5);
    tree.insert(3, 3);
    tree.insert(10, 10);
    tree.insert(12, 12);
    tree.insert(15, 15);
    tree.insert(1, 1);

    tree.preOrder(tree.head);


    return 0;
}

