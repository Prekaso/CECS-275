/*
 * Singly Linked List class header & implementation
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo Shin  
 * @version 1.2.1 
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

// define template class and structure for Node for linked list
template <class T> 
struct Node {
    T data;
    Node *next;
};

// define linked list class with template
template <class T> 
class LinkedList {
public:
    int length_;
    Node<T> *head_; // list head pointer
    Node<T> *tail_; // list tail pointer

    LinkedList();

    bool isEmpty() { // check if list is empty or not
        return this->head_ == nullptr;
    }
    int length() {
        return this->length_;
    }

    void add(T data);
    void drop(T value);
    void sort(T number);
    void printSequence();
};

// constructor for Linked list
template <class T> 
LinkedList<T>::LinkedList() {
    this->length_ = 0;
    this->head_ = nullptr;
    this->tail_ = nullptr;
}

// function to add data at the end of list
template <class T> 
void LinkedList<T>::add(T data) {
    Node<T> *node = nullptr;
    if (isEmpty()) { // checking condition
        node = new Node<T>;
        this->head_ = node;
    } else {
        node = this->tail_;
        node->next = new Node<T>;
        node = node->next;
    }
    node->data = data;
    node->next = nullptr;
    this->tail_ = node;
    this->length_++;
}

// function to delete particular value from linked list
template <class T>
void LinkedList<T>::drop(T value) { 
    int num_deleted = 0;
    Node<T> *curr = this->head_;
    Node<T> *tmp;
    while (!isEmpty() && ((T)curr->data).toString() == value.toString()) {
        tmp = curr;
        this->head_ = curr->next;
        curr = curr->next;
        delete tmp;
        num_deleted++;
    }
    while(!isEmpty() && curr->next != nullptr) { // while list isn't empty & the next node isn't null
        if (((T)curr->next->data).toString() == value.toString()) {
            tmp = curr->next;
            curr->next = curr->next->next;
            delete tmp;
            if (curr->next == nullptr) {  // update tail
                this->tail_ = curr;
            }
            num_deleted++;
        }
        curr = curr->next;
    }
    if (isEmpty()) {  // if list is empty, tail is null
        this->tail_ = nullptr;
    }
    if (num_deleted) {  // print out number of deleted courses
        cout << "Deleted " << num_deleted
             << " course(s): " << value.toString() << '.' << endl;
    } else {
        if (!isEmpty()) { // attempting to drop invalid course, print error message
            cout << "Course " << value.toString() << " not found in list."
                 << endl;
        } else {
            cout << "List is empty." << endl;
        }
    }
}

// function to sort courses by their course number
template <class T>
void LinkedList<T>::sort(T number) {
    Node<T> *node = nullptr;
}

//function to print linked list
template <class T> 
void LinkedList<T>::printSequence() {
    if (isEmpty()) { // make sure list is not empty, else print error message
        cout << "List is empty." << endl;
    } else {
        Node<T> *node = this->head_;
        while (node != nullptr) { // while node isn't null
            cout << ((T)node->data).toString() << endl; // printing nodes
            node = node->next;
        }
        cout << endl;
    }
}

#endif
