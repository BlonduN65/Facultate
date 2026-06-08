#ifndef HEADER_H_
#define HEADER_H_
#define M 124
#include <fstream>
#include <iostream>
using namespace std;

#include <cstring>



struct NOD{
    
    char cheie[50];
    struct NOD *urm;

};


void initializare(NOD *HT[]);
int f(char *key);
void inserare(NOD *HT[],char *key);
void afisareHT(NOD *HT[]);


#endif