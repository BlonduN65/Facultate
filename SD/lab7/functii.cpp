
#include "header.h"


int f(char *key)
{
    int i,suma;
    suma=0;
    for(i=0;i<strlen(key);i++)
        suma=suma+key[i];

    return suma%M;
    
}
void initializare(NOD *HT[]){

    for (int i=0;i<M;i++)
         HT[i]=NULL;

}
void inserare(NOD *HT[],char *key){

    int h=f(key);
    NOD *nou=new NOD;
    strcpy(nou->cheie,key);
    nou->urm=HT[h];
    HT[h]=nou;

}
void afisareHT(NOD *HT[]){

    for(int i=0;i<M;i++){
        cout<<"Pozitia este "<<i<<" ";
        NOD *p=HT[i];

        while(p!=NULL){

            cout<<p->cheie;
            p=p->urm;
        }
       // cout<<"NULL";
    cout<<endl;
    }
}