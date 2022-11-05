/*
 * Tree class header & implementation
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo Shin  
 * @version 1.1.0 
 */

#ifndef TREE_H
#define TREE_H

#include <iostream>

using namespace std;

class Tree{
    // members of Tree class
    int size, capacity;
    int *data;
    
    public:
    /**
     * Constructs a Tree with a length
     * @param length the length
     */
    Tree(int length) { 
        size = 0;
        data = (int*)malloc(length*sizeof(int));
        capacity = length;
    }
    /**
     * inserts a node
     * @param value 
     */
    void insert(int value) { 
        data[size] = value;
        size++; // increment size so there won't be overwriting
    }
     /**
     * Removes a node
     */   
    void remove() { 
        size--;
    }
    /**
     * Finds the node with corresponding value
     * @param value
     * @return true/false
     */    
    bool search(int value){ 
        for (int i = 0; i < size; ++i) {
            if (value == data[i]) // checks if value matches with node(s)
                return true;
        }
        return false;
    }
    /**
     * Counts the number of leaves of tree
     * @return count the number of leaves
     */
    int countLeaves() { 
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (2 * i + 1 < size && 2 * i + 2 < size) { // checks each node pairs for children
                continue; // check next node pairs
            }
            count++;    // increment when node pairs don't have children
        }
        return count;
    }
     /**
     * Prints the node(s)
     */
    void print() { 
        cout << "Inserted nodes: ";
        for (int i = 0; i < size; ++i) {
            if (size - i == 1) cout << data[i] << " "; // get rid of comma after last node
            else cout << data[i] << ", ";
        }
        cout << endl;
    }
    /**
     * Returns the number of nodes
     * @return size the number of nodes
     */
    int getSize() { 
        return size;
    }
};
#endif
