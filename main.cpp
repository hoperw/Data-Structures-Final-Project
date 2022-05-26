/*********************
Name: Hope Watson
final project
Purpose: A bidirectional graph that uses a vector of linkedlists.
**********************/

#include "main.h"

int main(int argc, char** argv) {

    srand(time(NULL));

    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-3] = ids[testdatasize-3];
    strs[testdatasize-3] = "known duplicate";
    ids[testdatasize-2] = - 1;
    strs[testdatasize-2] = "known bad";
    
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;


    string str = "string";

    Graph* graph = new Graph;

    /**
     
        * Empty Tests

    **/

    cout << "Beginning Empty Tests..." << endl << endl;

    // test getNumVertices
    cout << "Number of Vertices in Empty Graph: "
        << graph->getNumVertices() << endl << endl;

    // test getNumEdges
    cout << "Number of Edges in Empty Graph: "
        << graph->getNumEdges() << endl << endl;

    // test breadthFirstTraversal
    cout << "Trying Breadth First Traversal in Empty Graph: " << endl;
    for (int i : ids) {
        graph->breadthFirstTraversal(i);
    }
    cout << endl;

    // test removeEdge
    cout << "Trying Remove Edge in Empty Graph: " << endl << endl;
    for (int i = 0; i < testdatasize - 1; i++) {
        cout << "Trying to remove edge between ids: " << ids[i] << ", " << ids[i+1] << " ";
        graph->removeEdge(i, i+1) ? cout << "Success" : cout << "Failed";
        cout << endl;
    }
    cout << endl;

    // test removeVertex
    cout << "Trying Remove Vertex in Empty Graph: " << endl << endl;
    for (int i = 0; i < testdatasize - 1; i++) {
        cout << "Trying to remove id: " << ids[i] << " ";
        graph->removeEdge(i, i+1) ? cout << "Success" : cout << "Failed";
        cout << endl;
    }
    cout << endl;

    // test getEdgeWeight
    cout << "Using getEdgeWeight on Empty Graph: " << endl << endl;
    for (int i = 0; i < testdatasize - 1; i++) {
        cout << "Trying to get the edge weight between " << ids[i] << " and " << ids[i+1];
        graph->getEdgeWeight(i, i+1) == -1 ? cout << " No Weight " : cout << graph->getEdgeWeight(i, i+1);
        cout << endl;
    }
    cout << endl;


    // test depthFirstTraversal
    cout << "Trying Depth First Traversal in Empty Graph: " << endl;
    for (int i : ids) {
        graph->depthFirstTraversal(i);
    }
    cout << endl;

    // test addEdge
    // make random weights
    int weights[testdatasize];
    for (int i = 0; i < testdatasize; i++) {
        weights[i] = rand() % MAXID + 1;
    }
    cout << endl << "Trying addEdge on Empty Graph..." << endl << endl;
    for (int i = 0; i < testdatasize - 1; i++) {
        cout << "Addng weight between " << ids[i] << " and " << ids[i+1]
            << " is a ";
        graph->addEdge(ids[i], ids[i+1], weights[i]) ? cout << "success" : cout <<  "failure on empty";
        cout << endl;
    }
    cout << endl;

    // test addVertex
    cout << endl << "Trying addVertex on Empty Graph..." << endl << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << "Adding vertex " << ids[i];
        graph->addVertex(ids[i], &strs[i]) ? cout << " successfully " : cout << " not added ";
        cout << endl;
    }
    cout << endl;
    cout << "Graph after adding vertices... " << endl;
    graph->printGraph(); 
    cout << endl;


    /**
     
        * Non-Empty Tests

    **/

    // testing getNumVertices
    cout << "Testing getNumVertices on Non-Empty Graph..." << endl;
    cout << "The graph has " << graph->getNumVertices() << " vertices" << endl << endl;

    // testing getNumEdges
    cout << "Testing getNumEdges on Non-Empty Graph..." << endl << endl;
    cout << "The graph has " << graph->getNumEdges() << " edges" << endl << endl;

    // testing addEdge
    cout << "Adding Edges..." << endl << endl;
    for (int i = 0; i < testdatasize - 1; i++) {
        cout << "Attempting to add edge between " << ids[i] << " and " << ids[i+1]
            << " of weight: " << weights[i];
        graph->addEdge(ids[i], ids[i+1], weights[i]) ? cout << " success " : cout << " failed ";
        cout << endl;
    }
    cout << endl << "Printing graph after adding edges... " << endl << endl;
    graph->printGraph();
    cout << endl;

    // testing depthFirstTraversal
    cout << "Testing Depth First Traversal on Non-Tempty Graph" << endl << endl;
    for (int i = 0; i < testdatasize - 1; i++) {
        cout << "Testing Depth First Traversal with " << ids[i] << endl;
        graph->depthFirstTraversal(ids[i]);
        cout << endl;
    }

    // testing BreadthFirstTraversal
    cout << "Testing Breadth First Traversal on Non-Empty Graph" << endl << endl;
    for (int i = 0; i < testdatasize - 1; i++) {
        cout << "Testing Breadth First Traversal With " << ids[i] << endl;
        graph->breadthFirstTraversal(ids[i]);
        cout << endl;
    }

    // testing removeEdge
    int randomId = rand() % testdatasize;
    int randomId2 = rand() % testdatasize;
    cout << "Testing a single removal with removeEdge on Non-Empty Graph" << endl;
    cout << "Removing id: " << ids[randomId] << " and " << ids[randomId2] << endl;
    graph->removeEdge(ids[randomId], ids[randomId2]);
    cout << "Graph after removal: " << endl << endl;
    graph->printGraph();

    cout << "Testing repeatedly calling removeEdge on Non-Empty Graph" << endl << endl;
    for (int i = 0; i < BASE; i++) {
        randomId = rand() % testdatasize;
        cout << "Removing edges repeatedly from graph" << endl;
        cout << "Removing connection between: " << ids[randomId] << " and " << ids[i+1] << endl;
        graph->removeEdge(ids[randomId], ids[i+1]);
    }
    cout << endl << "Graph After Removals" << endl << endl;
    graph->printGraph();
    cout << endl;

    // testing removeVertex
    randomId = rand() % testdatasize;
    cout << "Testing a single removal with removeVertex on Non-Empty Graph" << endl;
    cout << "Removing id: " << ids[randomId] << endl;
    graph->removeVertex(ids[randomId]);
    cout << "Graph after removal: " << endl << endl;
    graph->printGraph();

    cout << "Testing repeatedly calling removeVertex on Non-Empty Graph" << endl << endl;
    for (int i = 0; i < BASE; i++) {
        randomId = rand() % testdatasize;
        cout << "Removing vertices repeatedly from graph" << endl;
        cout << "Removing vertex: " << ids[randomId] << endl;
        graph->removeVertex(ids[randomId]);
    }
    cout << endl << "Graph After Removals" << endl << endl;
    graph->printGraph();
    cout << endl;

    // refill graph

    cout << "Adding Vertices and Edges Again..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << "Adding vertex " << ids[i];
        graph->addVertex(ids[i], &strs[i]) ? cout << " successfully " : cout << " not added ";
        cout << endl;
    }
    cout << endl;
    weights[testdatasize];
    for (int i = 0; i < testdatasize; i++) {
        weights[i] = rand() % MAXID + 1;
    }
    for (int i = 0; i < testdatasize - 1; i++) {
        cout << "Addng weight between " << ids[i] << " and " << ids[i+1]
            << " is a ";
        graph->addEdge(ids[i], ids[i+1], weights[i]) ? cout << "success" : cout <<  "failure";
        cout << endl;
    }
    cout << endl;
    cout << "Graph after Refill..." << endl;
    graph->printGraph();
    cout << endl;

    // testing getEdge Weight 

    cout << "Testing repeatedly calling getEdgeWeight on Non-Empty Graph" << endl << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Calling getEdge Weight with: " << ids[i] << " and " << ids[i+1] << endl;
        if (graph->getEdgeWeight(ids[i], ids[i+1]) != -1) {
            cout << "Edge Weight: " << graph->getEdgeWeight(ids[i], ids[i+1]) << endl;
        } else {
            cout << "Edge doesn't exist..." << endl;
        }
    }

    return 0;
}
