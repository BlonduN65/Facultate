#ifndef HEADER_H_
#define HEADER_H_

struct Nod{

        int data;
        Nod* stg, *drt;
    };
Nod* insert_Arbore(Nod *r,int a);
Nod* make_nod(int a);
void POSTORDINE(Nod *p);
void INORDINE(Nod *p);
void PREORDINE(Nod* p);
int  cautare_val(Nod *r,int val);
void stergere_val(Nod*&r,int val);
void deleteRoot(Nod*& rad);
Nod* removeGreatest(Nod*& r);



#endif