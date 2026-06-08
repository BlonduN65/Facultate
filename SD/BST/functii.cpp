#include "header.h"


nod *creare_nod(int x){

    nod* p=new nod ;
    p->valoare=x;
    p->stg=NULL;
    p->dr=NULL;
}

void insert(nod* &r, int val){

    if(r==NULL)
        r=creare_nod(val);
    else 
    if(val>r->valoare)
        insert(r->dr,val);
    else
        insert(r->stg,val)    ;
}

nod *cautare(nod* r, int k){
    if (r==NULL)
        return NULL;
    if(r->valoare==k)
        return r;
    else
    if(k>r->valoare)
        cautare(r->dr,k);
    else
        return cautare(r->stg,k);
}

nod *remove_greteast(nod* &r){

    if(r->dr==NULL)
    {
        nod *p=r;
        r=r->stg;
        return p;
    }
    else
        return remove_greteast(r->dr);

}

void delete_radacina(nod* &r){

    nod* p;
    if(r->stg==NULL){
        p=r;
        r=r->dr;
        delete p;
    }
    else
    if(r->dr==NULL)
    {
        p=r;
        r=r->stg;
        delete p;

    }
    else{
        p=remove_greteast(r);
        p->stg=r->stg;
        p->dr=r->dr;
        delete r;
        r=p;
    }
}
void stergere(nod* r,int k){

    if(r!=NULL)
        if(k<r->valoare)
            stergere(r->stg,k);
        else
        if(k>r->valoare)
            stergere(r->dr,k);
        else
            delete_radacina(r);

}

void inorder(nod* r){
    if(r!=NULL){
        inorder(r->stg);
        cout<<r->valoare<<" ";
        inorder(r->dr);
    }
}
void postorder(nod *r){
    if(r!=NULL){
        postorder(r->stg);
        postorder(r->dr);
        cout<<r->valoare<<" ";

    }
}
void preorder(nod *r){
    if(r!=NULL){
        cout<<r->valoare<<" ";
        preorder(r->stg);
        preorder(r->dr);
        
    }
}