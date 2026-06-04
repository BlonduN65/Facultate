#ifndef HEADER_H_
#define HEADER_H_

struct Element {
    char data;         
    Element *succ;
};


void push(Element *&cap, char val);
void pop(Element *&cap);
char top(Element *cap);
bool isEmpty(Element *cap);
int prioritate(char op);

#endif
