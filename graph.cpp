/*********************
Name: Hope Watson
final project
Purpose: A bidirectional graph that uses a vector of linkedlists.
**********************/

#include "graph.h"

Graph::Graph() {
    int numOfEdges = 0;
}

Graph::~Graph() {
    for (int i = 0; i < graph.size(); i++) {
        graph[i]->clearList();
    }
    delete &graph;
}

bool Graph::addVertex(int id, string* str) {

    LinkedList* vertex = new LinkedList(id, str);
    bool added = false;
    if (id > 0 && *str != "/0") {
        int i = 0;
        bool exists = false;
        while (i < graph.size() && !exists) {
            exists = graph[i]->vertexId == id;
            i++;
        }
        if (!exists) {
            graph.push_back(vertex);
            added = true;
        }
    }
    return added;
}

bool Graph::verticesExist(int id1, int id2) {
    bool test1 = false;
    bool test2 = false;
    for (int i = 0; i < graph.size(); i++) {
        if (graph[i]->vertexId == id1) {
            test1 = graph[i]->vertexId == id1;
        }
        if (graph[i]->vertexId == id2) {
            test2 = graph[i]->vertexId == id2;
        }
    }
    return test1 && test2;
}

bool Graph::addEdge(int id1, int id2, int weight) {

    bool test1 = false;
    bool test2 = false;
    if (id1 > 0 && id2 > 0 && weight > 0 && !isEmpty() && verticesExist(id1, id2)) {
        for (int i = 0; i < graph.size(); i++) {
            if (graph[i]->vertexId == id1) {
                graph[i]->addNode(id2, weight);
                test1 = graph[i]->vertexId == id1;
            }
            if (graph[i]->vertexId == id2) {
                graph[i]->addNode(id1, weight);
                test2 = graph[i]->vertexId == id2;
            }
        }
        test1 && test2 ? numOfEdges++ : numOfEdges;
    }
    return test1 && test2;
}

bool Graph::removeEdge(int id1, int id2) {

    bool test1 = false;
    bool test2 = false;
    if (id1 > 0 && id2 > 0 && !isEmpty()) {
        for (int i = 0; i < graph.size(); i++) {
            if (graph[i]->vertexId == id1) {
                graph[i]->deleteNode(id2);
                test1 = graph[i]->vertexId == id1;
            }
            if (graph[i]->vertexId == id2) {
                graph[i]->deleteNode(id1);
                test2 = graph[i]->vertexId == id2;
            }
        }
        test1 && test2 ? numOfEdges-- : numOfEdges;
    } 
    return test1 && test2;
}

bool Graph::removeVertex(int id) {
    bool removed = false;
    if (id > 0 && !isEmpty()) {
        vector<Node*> connections;
        int index = 0;
        while (index < graph.size() && graph[index]->vertexId != id) {
            index++;
        } 
        if (graph[index]->vertexId != id) {
            removed = false;
        }
        else {
            connections = graph[index]->getListIds();
            for (int i = 0; i < connections.size(); i++) {
                removeEdge(id, connections[i]->data.id);
            }
            graph.erase(graph.begin() + index);
            removed = true;
        }
    }
    return removed;
}

int Graph::getEdgeWeight(int id1, int id2) {
    vector<Node*> connections;
    int weight = -1;
    int index = 0;
    if (id1 > 0 && id2 > 0 && !isEmpty() && edgeExists(id1, id2)) {
        while (index < graph.size() && graph[index]->vertexId != id1) {
            index++;
        }
        connections = graph[index]->getListIds();
        int j = 0;
        while (j < connections.size() && connections[j]->data.id != id2) {
            j++;
        }
        weight = connections[j]->data.weight;
    } 
    return weight; 
}

bool Graph::isEmpty() {
    return graph.size() == 0;
}

void Graph::printGraph() {

    if (!isEmpty()) {
        for (int i = 0; i < graph.size(); i++) {
            cout << "V: " << graph[i]->vertexId << " ";
            graph[i]->printList();
        }
    }
}

int Graph::getNumVertices() {
    return graph.size();
}

bool Graph::edgeExists(int id1, int id2) {
    bool exists = false;
    vector<Node*> connections;
    if (id1 > 0 && id2 > 0 && !isEmpty() && verticesExist(id1, id2)) {
        int i = 0;
        while (i < graph.size() && graph[i]->vertexId != id1) {
            i++;
        }
        if (graph[i]->vertexId == id1) {
            connections = graph[i]->getListIds();
            int j = 0;
            while (j < connections.size() && connections[j]->data.id != id2) {
                j++;
            }
            exists = connections[j]->data.id == id2;
        }
    }
    return exists;
}

int Graph::getNumEdges() {
    return numOfEdges;
}

void Graph::breadthFirstTraversal(int id1) {

    vector<int> queue;
    vector<int> visited;
    vector<Node*> connections;
    int id = id1;
    queue.push_back(id);

    if (id1 > 0 && !isEmpty()) {
        while (queue.size() > 0 && id1 > 0) {
            int index1 = 0;
            while (index1 < graph.size() && graph[index1]->vertexId != id) {
                index1++;
            }
            if (graph[index1]->vertexId == id) {
                visited.push_back(id);
                connections = graph[index1]->getListIds();
                for (int i = 0; i < connections.size(); i++) {
                    bool inVisited = hasVisited(visited, connections[i]);
                    if (!inVisited) {
                        bool inQueue = false;
                        int k = 0;
                        while (k < queue.size() && !inQueue) {
                            inQueue = connections[i]->data.id == queue[k];
                            k++;
                        }
                        if (!inQueue) {
                            queue.push_back(connections[i]->data.id);
                        }
                    }
                }
            }
            queue.erase(queue.begin());
            cout <<  "Queue: ";
            for (int l : queue) {
                cout << l << " ";
            }
            cout << endl;
            id = queue[0];
        }
        int id = id1;
        queue.push_back(id);
    }
}

void Graph::depthFirstTraversal(int id) {

    vector<int> stack;
    vector<int> visited;
    vector<Node*> connections;
    Node* smallest;

    if (id > 0 && !isEmpty()) {
        stack.push_back(id);
        visited.push_back(id);
        while (stack.size() > 0) {
            int i = 0;
            while (i < graph.size() && graph[i]->vertexId != id ) {
                i++;
            }
            if (graph[i]->vertexId == id) {
                connections = graph[i]->getListIds();
                smallest = findSmallest(connections, visited);
                bool inVisited = hasVisited(visited, smallest);
                if (!inVisited) {
                    stack.push_back(smallest->data.id);
                    visited.push_back(smallest->data.id);
                } else {
                    stack.pop_back();
                }
                id = stack.back();
                cout << "Stack: ";
                for (int n : stack) {
                    cout << n << " "; 
                }
                cout << endl;
            }

        }
    }
}

bool Graph::hasVisited(vector<int> visited, Node* node) {
    bool inVisited = false;
    int l = 0;         
    while (l < visited.size() && !inVisited) {
        inVisited = node->data.id == visited[l];
        l++;
    }
    return inVisited;
}

Node* Graph::findSmallest(vector<Node*> connections, vector<int> visited) {

    int j = 0;
    Node* smallest = connections[j];
    for (int k = 1; k < connections.size(); k++) {
        if(connections[k]->data.weight < smallest->data.weight && !hasVisited(visited, connections[k])) {
            smallest = connections[k];
        };
    }

    return smallest;
}