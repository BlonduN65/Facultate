#include "header.h"
#include <iostream>
using namespace std;

Nod* make_nod(int a){

    Nod *p=new Nod;
    p->data=a;
    p->stg=0;
    p->drt=0;
    return p;
}

Nod* insert_Arbore(Nod *r,int a){
    
        if(r==NULL){

            return make_nod(a);

        }
        if(a<r->data){
            r->stg=insert_Arbore(r->stg,a);
        }
        else
        if(a>r->data){

            r->drt=insert_Arbore(r->drt,a);
        }

        return r;

}
void POSTORDINE(Nod *p) {
    if ( p!= NULL) {
    POSTORDINE(p->stg);
    POSTORDINE(p->drt);
    cout << p->data << " ";
}
}
void INORDINE(Nod *p) {
    if ( p!= NULL) {
         INORDINE(p->stg);
	    cout << p->data << " ";
	    INORDINE(p->drt);
	}
}

void PREORDINE(Nod* p){
    if (p!=NULL){
	    cout<<p->data<<" ";
    PREORDINE(p->stg);
    PREORDINE(p->drt);
    }
}
int  cautare_val(Nod *r,int val){
    if (r==NULL)
        return 0;
    if(val==r->data)
        return 1;
    if(val<r->data)
        return cautare_val(r->stg,val);
    
    return cautare_val(r->drt,val);
}
Nod* removeGreatest(Nod*& r) {
    if (r->drt == NULL) { 
        Nod* p = r;
        r = r->stg; 
        return p;
    } else {
        return removeGreatest(r->drt); 
    }
}
void deleteRoot(Nod*& rad) {
    Nod* p = rad;
    if (rad->stg == NULL) { 
        rad = rad->drt;
        delete p;
    } else if (rad->drt == NULL) { 
        rad = rad->stg;
        delete p;
    } else { 
        p = removeGreatest(rad->stg); 
        rad->data = p->data; 
        delete p; 
    }
}

void stergere_val(Nod *&p,int val){

    if(p==NULL)
        cout<<"Arborele este NULL";
    else
    if(val<p->data)
         stergere_val(p->stg,val);
    else
    if(val>p->data)
        stergere_val(p->drt,val);
    else
    deleteRoot(p);
    
}