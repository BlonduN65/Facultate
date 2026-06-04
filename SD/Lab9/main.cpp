


#include <iostream>
using namespace std;
#include "header.h"
int main(){

    Nod *rad=NULL;
    int x,y,z;

    cout<<"Dati valoarea la variabila cautata:";
    cin>>y;
    cout<<endl;

    cout<<"Dati valori lui x"<<endl;
    while(cin>>x && x!=0){
        rad=insert_Arbore(rad,x);
    }

    cout<<endl<<"Afisare postordine:"<<endl;
    POSTORDINE(rad);
    
    cout<<endl<<"Afisare preordine:"<<endl;
    PREORDINE(rad);

    cout<<endl<<"Afisare inordine:"<<endl;
    INORDINE(rad);

    cout<<endl<<"Dati valoarea care sa fie stearsa:"<<endl;
    cin>>z;
    stergere_val(rad,z);

    INORDINE(rad);
    


    return 0;
}