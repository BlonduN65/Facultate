#include <iostream>
#include "header.h"

using namespace std;

int main()
{
	Nod *root = creareArbore();
	
    cout<<"PREORDINE: "<<endl;
	PREORDINE(root);
	cout<<endl;
	
    cout<<"POSTORDINE: "<<endl;
	POSTORDINE(root);
	cout<<endl;
	
    cout<<"INORDINE: "<<endl;
	INORDINE(root);
	cout<<endl;
	
    int a=Adancime(root);
	cout<<"Adancime: "<<a<<endl;
	cout<<endl;
	
    int b=NrNoduri(root);
	cout<<"NrNoduri: "<<b<<endl;
	
    int c=NrFrunze(root);
	cout<<"NrFrunze: "<<c<<endl;
	cout<<endl;

    cout<<"Nodurile maxime sunt :";
    AfiseazaNoduriMax(root);
    cout<<endl;
    
    cout<<"Verificare stanga mai mic decat dreapta : ";
    Verificare_stg_mic_drt(root);
    cout<<endl;

    
    return 0;
}