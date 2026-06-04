#ifndef HEADER_H_
#define HEADER_H_

typedef int Atom;

struct Node {
    Atom data;
    int priority;
    Node* next;
};

struct PriorityQueue {
    Node* head;
};

void Init(PriorityQueue& q);
bool IsEmpty(PriorityQueue q);
void Put(PriorityQueue& q, Atom val, int prio); 
Atom Get(PriorityQueue& q);
Atom Front(PriorityQueue q);


#endif