#include <iostream>
#include "header.h"
using namespace std;
static char car = 0;

static void eroare()
{
	printf("Sirul de intrare este eronat!\n");
	printf("Apasati tasta o tasta...");
	getchar();
	exit(1);
}

static char readchar()
{
	char c;
	do  c = getchar();  while (c == ' ');
	return c;
}

static char citesteNume()
{
	char c;
	if (!isalpha(car)) eroare();
	c = car;
	car = readchar();
	return c;
}

static Nod* citesteArbore()
{
	Nod* rad;
	if (car == '-')
	{
		rad = 0;
		car = readchar();
	}
	else
	{
		rad = new Nod;
		rad->data = citesteNume();
		if (car != '(')
		{
			rad->stg = 0;
			rad->drt = 0;
		}
		else
		{
			car = readchar();
			rad->stg = citesteArbore();
			if (car != ',')
			{
				rad->drt = 0;
			}
			else
			{
				car = readchar();
				rad->drt = citesteArbore();
			}
			if (car != ')')  eroare();
			car = readchar();
		}
	}
	return rad;
}

Nod* creareArbore()
{
	printf("Exemplu: A(B(-,C),D(E(F,-),G(H,-)))\n");
	printf("Introduceti arborele:");
	car = readchar();
	return citesteArbore();
}

void PREORDINE(Nod* p){
    if (p!=NULL){
	    cout<<p->data<<" ";
    PREORDINE(p->stg);
    PREORDINE(p->drt);
}
}
void POSTORDINE(Nod *p) {
    if ( p!= NULL) {
    POSTORDINE(p->stg);
    POSTORDINE(p->drt);
    cout << p->data << " ";
}
}
void INORDINE(Nod *p) {
    if ( p!= NULL) {
         INORDINE(p->stg);
	    cout << p->data << " ";
	    INORDINE(p->drt);
	}
}
int Adancime(Nod *p)
{
            if(p!=0)
                 {
                    return 1+max(Adancime(p->stg),Adancime(p->drt));	
                }
                return 0;
}

int NrNoduri(Nod *p)
{
            if(p!=0)
    {
	    return 1+NrNoduri(p->stg)+NrNoduri(p->drt);	
    }
    return 0;

}

int NrFrunze(Nod *p) {
    if (p == 0) 
        return 0;
    if (p->stg == 0 && p->drt == 0) {
         return 1; 
    }
    return NrFrunze(p->stg) + NrFrunze(p->drt); 
}
char maxsubarb(Nod *p){

    if(p==NULL)
        return 0;
    char max_stg=maxsubarb(p->stg);
    char max_drt=maxsubarb(p->drt);

    char v_max=p->data;
    if(max_stg>v_max)
        v_max=max_stg;
    if(max_drt>v_max)
        v_max=max_drt;

        return v_max;

}

void AfiseazaNoduriMax(Nod *p){

    if(p==NULL)
        return;
      char max_stg=maxsubarb(p->stg);
      char max_drt=maxsubarb(p->drt);
    if ((p->stg != NULL || p->drt != NULL) && p->data > max_stg && p->data > max_drt) {
      cout << " " << p->data;
    }

    AfiseazaNoduriMax(p->stg);
    AfiseazaNoduriMax(p->drt);

}

char minsubarb(Nod *p){
    if(p==NULL)
        return 0;
    char min_stg=minsubarb(p->stg);
    char min_drt=minsubarb(p->drt);

    char v_min=p->data;
    if(min_stg<v_min)
        v_min=min_stg;
    if(min_drt<v_min)
        v_min=min_drt;
    
    return v_min;
}
void Verificare_stg_mic_drt(Nod *p){

    if(p==NULL)
        return;
    if((p->stg!=NULL) && (p->drt !=NULL)){
        char min_stg=minsubarb(p->stg);
        char max_drt=maxsubarb(p->drt);

        if(min_stg<max_drt)
            cout<<" "<<p->data;
    }
    Verificare_stg_mic_drt(p->stg);
    Verificare_stg_mic_drt(p->drt);
}

