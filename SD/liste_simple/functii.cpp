#include "header.h"

void inserare_inceput(Nod* &cap , int valoare){

    Nod* nou=new Nod;
    nou->info=valoare;
    nou->next=cap;
    cap=nou;

}

void afisare_Lista(Nod* cap){
    cout<<"afisam lista"<<endl;
    Nod* nou=new Nod;
    nou=cap;
    while(nou!=NULL){
        cout<<nou->info<<" ";
        nou=nou->next;

    }
    cout<<"Am ajuns la finalul listei"<<endl;

}

void inserare_final(Nod* &cap , int valoare){

    Nod* nou=new Nod;
    nou->info=valoare;
    nou->next=nullptr;
    if (cap==nullptr){
        cap=nou;
        return;
    }

    Nod* curent=cap;
    while(curent->next!=nullptr){
        curent=curent->next;
    }
    curent->next=nou;

}

void cautare_element(Nod* cap , int element){
    Nod* nou=cap;
    int ctr=0;
    while(nou->next!=0 && ctr==0){
        if(nou->info==element)
         {
            ctr=1;
            nou=nou->next;

         }   


    }
    if (ctr==1)
        cout<<"Elementul a fost gasit";
        else
        cout<<"Elementukl nu a fost gasit ";
}

void inserare_dupapoz(Nod* cap, int valorare,int poz){
    Nod *nou=cap;
    int ctr=0;
    while(ctr<poz-1 && nou!=nullptr){
        ctr++;
        nou=nou->next;

    }


    Nod *nou2=new Nod;
    nou2->info=valorare;
    nou2->next=nou->next;
    nou->next=nou2;

}

void inserare_poz(Nod* cap, int element , int poz){
    


}