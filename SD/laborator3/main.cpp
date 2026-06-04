#include <iostream>
#include "header.h"
using namespace std;
int main(){

    Element *p=0;
    int k,l=0;
    int poz,elem;
    int pozel;
    cout<<"Elementul pe care il cautam este: "<<endl;
    cin>>k;
    cout<<"Pozitia pe care vrem sa inseram este "<<endl;
    cin>>poz;
    cout<<"Elementul pe care dorim sa l inseram este"<<endl;
    cin>>elem;
    cout<<"Vrem sa eliminam elementul de pe pozitia :"<<endl;
    cin>>pozel;

    CreareLista(p);

    Afisare_lista(p);
    cout<<endl;

    l=Cautare_element(p,k);
    if(l==0)
    cout<<"Elementul nu a fost gasit ";
    else
    cout<<"Elementul a fost gasit";
    cout<<endl;
   
    Inserare_Element_poz(p,poz,elem);
    Afisare_lista(p);

    cout<<endl;


    
    Stergere_Element(p,pozel);
    Afisare_lista(p);


    




    return 0;
}