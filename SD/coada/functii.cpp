#include "header.h"

int nexpoz(int index){
    if(index<DIMax-1)
        return index+1;
    else
        return 0;

}
void initCoada(coada &c){
    c.prim=0;
    c.ultim=0;

}
int isEmpty(coada c){
    if(c.prim==c.ultim)
        return 1;
    else
        return 0;
}
int isFull(coada c){
    if(nexpoz(c.ultim)==c.prim)
        return 1;
    else
        return 0;

}
void put(coada &c, int x){
    if(!isFull(c)){
        
        c.v[c.ultim]=x;
        c.ultim=nexpoz(c.ultim);

    }
    else
    cout<<"Coada este plina! ";

}

Atom get(coada &c){
    if(!isEmpty(c)){
        Atom x=c.v[c.prim];
        c.prim=nexpoz(c.prim);
        return x;
    }
    else
        cout<<"Coada este goala ";
}
Atom front(coada c){
    if(!isEmpty(c)){
        return c.v[c.prim];
    }
    else
         cout<<"Coada este goala ";
}

