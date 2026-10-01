#include "header.h"

bool Eq_required=false;
void creare_avl(AVL* &r){
    r=NULL;
    int x;
    cout<<"Dati valori pana la citirea lui 0 ";
    while(cin>>x && x!=0){
        insert(r,x);

    }
}
void RSS(AVL* &r ){
    AVL* aux=r->drt;
    r->drt=aux->stg;
    aux->stg=r;
    aux->bf=r->bf=0;
    r=aux;

}
void RSD(AVL* &r){
    AVL* aux=r->stg;
    r->stg=aux->drt;
    aux->drt=r;
    aux->bf=r->bf=0;
    r=aux;
}
void RDD(AVL* &r){
    AVL* aux1=r->stg;
    AVL* aux2=r->drt;

    r->stg=aux2->drt;
    aux1->drt=aux2->stg;
    aux2->stg=aux1;
    aux2->drt=r;

    if(aux2->bf==1)
        r->bf=-1;
    else
        r->bf=0;
    if(aux2->bf==-1)
        aux1->bf=1;
    else
        aux1=0;
    r=aux2;

}
void RSDD(AVL* &r){
    AVL* aux1=r->drt;
    AVL* aux2=aux1->stg;

    r->drt=aux2->stg;
    aux1->stg=aux2->drt;
    aux2->drt=aux1;
    aux2->stg=r;
  
    if(aux2->bf==1)
        r->bf=-1;
    else
        r->bf=0;
    if(aux2->bf==-1)
        aux1->bf=1;
    else
        aux1=0;
    r=aux2;

}

void echilibrare(AVL* &r){

    if(r->bf==-2){
        if(r->stg->bf==-1)
            RSD(r);
        else
            RDD(r);
    }
    else
        if(r->bf==2){
            if(r->drt->bf==1)
                RSS(r);
            else
                RSDD(r);
        }
}


void insert(AVL* &r,int a){

    if(r==NULL){
        r=new AVL;
        r->data=a;
        r->drt=r->stg=NULL;
        r->bf=0;
        Eq_required=true;
    }

    else{
        if(a<r->data){
            insert(r->stg,a);
            echilibrare(r);
        }
        else if(a>r->data){
            insert(r->drt,a);
            echilibrare(r);
        }
    }
}

void cheie_minim(AVL* r){
    AVL* copie=r;
    while(copie->stg!=NULL){
        copie=copie->stg;
    }
    cout<<"Cea mai mica cheie este: ";
    cout<<copie->data<<endl;
}
void cheie_maxim(AVL* r){
    AVL* copie=r;
    while(copie->drt!=NULL){
        copie=copie->drt;
    }
    cout<<"Cea mai mare cheie este: ";
    cout<<copie->data<<endl;
}

void insert_lista(lista* &cap,int x){
    lista* nou=new lista;
    nou->data=x;
    nou->next=NULL;
    if(cap==NULL){
        
        cap=nou;
        nou->next=cap;
        return;
    }
    lista* curent=cap;
    while(curent->next!=cap){
        curent=curent->next;
    }

    curent->next=nou;
    nou->next=cap;

}
void afisare(lista* cap){
    if(cap==nullptr){
        cout<<"Lista este goala ";

    }
    lista* curent=cap;
    do{
        cout<<curent->data<<" ";
        curent=curent->next;
    }while(curent!=cap);
}

void inserare_frunze(lista* &cap, AVL* r){
    if (r == nullptr) return; // <- OPRIREA RECURSIEI

    if(r->drt == nullptr && r->stg == nullptr) {
        insert_lista(cap, r->data);
        return; // Dacă e frunză, nu mai are sens să coborâm sub ea
    }
        
    inserare_frunze(cap, r->stg);
    inserare_frunze(cap, r->drt);
}