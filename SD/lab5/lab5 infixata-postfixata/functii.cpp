#include <iostream>
#include "header.h"

void push(Element *&cap, char val) {
    Element *nou = new Element;
    nou->data = val;
    nou->succ = cap;
    cap = nou;
}


void pop(Element *&cap) {
    if (cap != nullptr) {
        Element *temp = cap;
        cap = cap->succ;
        delete temp;
    }
}


char top(Element *cap) {
    if (cap != nullptr) {
        return cap->data;
    }
    return '\0'; 
}


bool isEmpty(Element *cap) {
    return cap == nullptr; 
}

int prioritate(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0; 
}