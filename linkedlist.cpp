/*********************
Name: Hope Watson
final project
Purpose: A bidirectional graph that uses a vector of linkedlists.
**********************/

#include "linkedlist.h"

using std::cout; using std::endl;


LinkedList::LinkedList(int vertexId, string* data) {

    head = NULL;
    int count = 0;
    this->vertexId = vertexId;
    this->data = data;
}

LinkedList::~LinkedList() {
    clearList();
}

bool LinkedList::addNode(int id, int weight) {

    bool added;

    if (id > 0) {
        if (head == NULL) {
            Node *newNode = addNodeHelper(id, weight);
            head = newNode;
            added = true;
        } else {
            Node *current = head;
            while (current->next && current->next->data.id != id) {
                current = current->next;
            }
            if (current->data.id == id) {
                added = false;
            } else {
                Node *newNode = addNodeHelper(id, weight);
                current->next = newNode;
                added = true;
            }
        }
    }
    return added;
}

bool LinkedList::deleteNode(int id) {

    bool deleted = false;
    if (id > 0) {
        if (head == NULL) {
            deleted = false;
        } else {
            Node* current = head;
            if (current->data.id == id) {
                head = current->next;
                delete current;
                current = NULL;
                deleted = true;
            } else {
                while (current->next != NULL && current->next->data.id != id) {
                    current = current->next;
                }
                if (current->data.id != id && current->next == NULL) {
                    deleted = false;
                } else if (current->next != NULL) {
                    Node* temp = current->next;
                    current->next = NULL;
                    delete current->next;
                    current->next = temp->next;
                    deleted = true;
                } else if (!current->next) {
                    delete current->next;
                    current->next = NULL;
                    deleted = true;
                }
            }

        }
    }
    return deleted;
}

void LinkedList::printList() {

    Node *current = head;
    head ? cout << " --> " : cout << "";
    while (current) {
        cout << current->data.id;
        current = current->next;
        current ? cout << " --> " : cout << "";
    }
    cout << endl;
}


bool LinkedList::clearList() {

    Node* current = head;
    Node* temp;
    while (current != NULL) {
        temp = current->next;
        delete current;
        current = temp;
    }
    head = NULL;
    return true;
}

Node* LinkedList::addNodeHelper(int id, int weight) {

    Node* newNode = new Node;

    newNode->data.id = id;
    newNode->data.weight = weight;
    newNode->next = NULL;
    count++;
    return newNode;
}

vector<Node*> LinkedList::getListIds() {

    Node* current = head;
    vector<Node*> listIds;

    while (current) {
        listIds.push_back(current);
        current = current->next;
    }
    return listIds;
}