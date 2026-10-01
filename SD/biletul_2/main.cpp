#include "header.h"

int main(){
    AVL* r=NULL;
    creare_avl(r);
    AVL* copie=r;
    cheie_maxim(r);
    cheie_minim(r);

    lista* cap=NULL;
    inserare_frunze(cap,copie);
    cout<<"Lista este: ";
    afisare(cap);

}