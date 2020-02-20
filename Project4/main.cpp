#include <fstream>
#include <iostream>

#include "MyAVLTree.hpp"

int main()
{
    MyAVLTree<int, std::string> tree;
    tree.insert(5, "foo");
    tree.insert(3, "sna");
    tree.insert(10, "bar");
    tree.insert(12, "twelve");
    tree.insert(15, "fifteen");

    int test = tree.size();

    return 0;
}

