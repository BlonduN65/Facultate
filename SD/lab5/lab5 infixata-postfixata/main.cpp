#include <iostream>
#include <cstring>
#include "header.h"
using namespace std;

int main() {
    Element *stiva_operatori = nullptr;
    char s[256], postfix[256];
    int k = 0;

    cout << "Introdu expresia : ";
    cin.getline(s, 256);

    int n = strlen(s);

    for (int i = 0; i < n / 2; i++) 
            swap(s[i], s[n - i - 1]);

  
    for (int i = 0; i < n; i++) {
        if (s[i] == '(')
             s[i] = ')';
        else 
        if (s[i] == ')') 
            s[i] = '(';
    }

   
    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            postfix[k++] = s[i];
        } 
        else if (s[i] == '(') {
            push(stiva_operatori, s[i]);
        } 
        else if (s[i] == ')') {
            while (!isEmpty(stiva_operatori) && top(stiva_operatori) != '(') {
                postfix[k++] = top(stiva_operatori);
                pop(stiva_operatori);
            }
            pop(stiva_operatori); 
        } 
        else {
            while (!isEmpty(stiva_operatori) && prioritate(s[i]) < prioritate(top(stiva_operatori))) {
                postfix[k++] = top(stiva_operatori);
                pop(stiva_operatori);
            }
            push(stiva_operatori, s[i]);
        }
    }

    while (!isEmpty(stiva_operatori)) {
        postfix[k++] = top(stiva_operatori);
        pop(stiva_operatori);
    }
    postfix[k] = '\0';

    for (int i = 0; i < k / 2; i++) 
        swap(postfix[i], postfix[k - i - 1]);

    cout << "Forma prefixata: " << postfix << endl;

    return 0;
}