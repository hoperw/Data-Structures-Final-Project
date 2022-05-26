/*********************
Name: Hope Watson
final project
Purpose: A bidirectional graph that uses a vector of linkedlists.
**********************/

#ifndef GRAPH_H
#define GRAPH_H

#include "linkedlist.h"

class Graph {

public:

    Graph();
    ~Graph();

    int getNumVertices();
    int getNumEdges();
    bool addVertex(int, string*);
    bool addEdge(int, int, int);
    void breadthFirstTraversal(int);
    void printGraph();
    bool removeEdge(int, int);
    bool removeVertex(int);
    int getEdgeWeight(int, int);
    void depthFirstTraversal(int);

private:

    vector<LinkedList*> graph;
    bool isEmpty();
    Node* findSmallest(vector<Node*>, vector<int>);
    bool hasVisited(vector<int>, Node*);
    int numOfEdges;
    bool verticesExist(int, int);
    bool edgeExists(int, int);

};


#endif