#include "header.h"
ifstream fin("text.txt");
int main(){
    NOD *HT[M];

    initializare(HT);
    char s[40];
    while(fin>>s){

        inserare(HT,s);

    }

    afisareHT(HT);
    return 0;
}