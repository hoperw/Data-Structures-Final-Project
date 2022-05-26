/*********************
Name: Hope Watson
final project
Purpose: A bidirectional graph that uses a vector of linkedlists.
**********************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "data.h"

class LinkedList {

public:

    LinkedList(int, string* data);
    ~LinkedList();
    
    int vertexId;
    bool addNode(int, int);
    bool deleteNode(int);
    void printList();
    bool clearList();
    vector<Node*> getListIds();

private: 

    string* data;
    int count;
    Node* head;
    Node* addNodeHelper(int id, int);

};

#endif
