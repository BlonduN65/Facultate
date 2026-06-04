#include "header.h"
#include <iostream>

using namespace std;


void Init(PriorityQueue& q) {
    q.head = nullptr;
}


bool IsEmpty(PriorityQueue q) {
    return q.head == nullptr;
}


void Put(PriorityQueue& q, Atom val, int prio) {
    Node* newNode = new Node{val, prio, nullptr};

    
    if (q.head == nullptr || prio > q.head->priority) {
        newNode->next = q.head;
        q.head = newNode;
    } else {
       
        Node* temp = q.head;
        while (temp->next != nullptr && temp->next->priority >= prio) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}


Atom Get(PriorityQueue& q) {
    if (IsEmpty(q)) {
        cout << "Eroare: Coada este vida!\n";
        return -1;
    }
    Node* temp = q.head;
    Atom val = temp->data;
    q.head = q.head->next;
    delete temp;
    return val;
}


Atom Front(PriorityQueue q) {
    if (IsEmpty(q)) return -1;
    return q.head->data;
}