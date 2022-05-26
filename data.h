/*********************
Name: Hope Watson
final project
Purpose: A bidirectional graph that uses a vector of linkedlists.
**********************/

#ifndef DATA_H
#define DATA_H

#include "string"
#include <iostream>
#include <vector>

using std::string; using std::cout; using std::endl; using std::vector;

struct Data {
    int id;
    int weight;
};

struct Node {
    Data data;
    Node *next;
};

#endif 