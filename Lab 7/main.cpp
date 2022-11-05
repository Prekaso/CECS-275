/*
 * This C++ program's purpose is to: 
 * - Implement a Tree class
 * - Provide additional member functions such as:
 * - return the number of nodes and leaves in that tree
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo Shin  
 * @version 1.0.0 
 */

#include <iostream>
#include "Tree.h"

using namespace std;


int main() {

    // create tree with length of 10
    Tree tree(10);

    // inserting nodes
    tree.insert(3);
    tree.insert(1);
    tree.insert(9);

    // removing node
    tree.remove();

    // inserting more nodes
    tree.insert(7);
    tree.insert(4);
    tree.insert(2);
    tree.insert(8);
    tree.insert(5);
    tree.insert(6);
 
    // outputting nodes inserted in tree
    tree.print();

    // outputting number of nodes in tree
    cout << "Number of nodes in tree: " << tree.getSize() << endl;

    // outputting number of leaves in tree
    cout << "Number of leaves in tree: " << tree.countLeaves() << endl;

    return 0;
}
