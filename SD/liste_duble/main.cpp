#include "header.h"

int main(){

    nod *cap=new nod;
    inserare_nod(cap,5);
    inserare_nod(cap,2);
    inserare_nod(cap,3);

    afisare_dreapta(cap);

    return 0;
}