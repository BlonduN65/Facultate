#include "header.h"

bool Eq_Required=false;

void creare(AVL* &a){
    a=NULL;
    int x;
    cout<<"Dati valori pana la citirea lui 0";
    while(cin>>x && x!=0 ){
        insert(a,x);
    }
}
void RSS(AVL* &a){
    AVL* aux=a;
    a->drt=aux->stg;
    aux->stg=a;
    aux->bf=a->bf=0;
    a=aux;
}
void RSD(AVL* &a){
    AVL* aux=a;
    a->stg=aux->drt;
    aux->drt=a;
    a->bf=aux->bf=0;
    a=aux;
}
void RDD(AVL* &a){
    AVL* aux=a->stg;
    AVL* aux2=aux->drt;

    a->stg=aux2->drt;
    aux->drt=aux2->stg;

    aux2->stg=aux;
    aux2->drt=a;
    
    if(aux2->bf==1)
        a->bf=-1;
    else
    if(aux2->bf==-1)
        aux->bf=1;
    else
        aux->bf=0;

    a=aux2;


}
void RSDD(AVL* &a){
    AVL* aux=a->drt;
    AVL* aux2=aux->stg;

    a->drt=aux2->stg;
    aux->stg=aux2->drt;
    
    aux2->drt=aux;
    aux2->stg=a;

    if(aux2->bf==1)
        aux->bf=-1;
    else
    if(aux2->bf==-1)
        aux->bf=1;
    else
        aux->bf=0;
    a=aux2;

}
void echilibrare(AVL* &a){
    if(a->bf==-2)
        if(a->stg->bf==-1)
            RSD(a);
        else
            RDD(a);
    else   if(a->bf==2)
        if(a->drt->bf==1)
            RSS(a);
        else
            RSDD(a);

}
void insert(AVL* &a,int x){
    if(a==NULL){
        a=new AVL;
        a->data=x;
        a->stg=NULL;
        a->drt=NULL;
        a->bf=0;
        Eq_Required=true;
    }
    else   if(x<a->data){
            insert(a->stg,x);
            echilibrare(a);
    }
    else {
            insert(a->drt,x);
            echilibrare(a);
    }
}
void inorder(AVL* &a){
    if(a!=NULL){
        inorder(a->stg);
        cout<<a->data<<" ";
        inorder(a->drt);
    }
}
void deleteAVL(AVL* &a){
    if(a!=NULL){
        delete(a->stg);
        delete(a->drt);
        delete a;
        a=NULL;
    }

}







