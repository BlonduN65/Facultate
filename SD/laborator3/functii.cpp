#include "header.h"
#include <iostream>
using namespace std;

void CreareLista(Element *&cap){

    int n;
    cin>>n;
    while(n!=0)
    {

        Inserare(cap,n);
        cin>>n;
    }


}

void Inserare(Element *&cap,int val){

    Element *p;
    p=new Element;
    p->data=val;
    p->succ=cap;
    cap=p;

}

void Afisare_lista(Element *cap){

        Element *p=0;
        p=cap;
        cout<<"Elemenetele listei sunt :"<<endl;
        while(p!=0){
            
            
            cout<<p->data<<" ";
            p=p->succ;

        }


}

int Cautare_element(Element *&cap,int n){

    int gasit=0;
    Element *p=cap;

    while(p->succ!=0 && gasit==0 ){

        if( p->data == n )
        {
                gasit=1;
        }
                
        p=p->succ;
    }

    return gasit;

}
void Inserare_Element_poz(Element *&cap,int poz,int val){

        Element *p=cap;
        int ctr=0;
        while ( ctr<poz-1 && p!=0){
            ctr++;
            p=p->succ;
        }

        Element *nou=new Element;
        nou->data=val;
        nou->succ=p->succ;
        p->succ=nou;
        
        if(cap==0 && poz==1){
            cap=new Element;
            cap->data=val;
            cap->succ=0;
        }

}
void Stergere_Element(Element *&cap,int poz){

    Element *p;
    p=cap;
    int ctr=0;
    while( ctr<poz-2 && p!=0){
        p=p->succ;
        ctr++;
    }
    
    Element *nou=new Element;
    nou=p->succ;
    p->succ=nou->succ;
    delete nou;

}