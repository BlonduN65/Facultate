#ifndef HEADER_H_
#define HEADER_H_


struct Element{
int data;
Element *succ;
};

void Inserare(Element *&cap,int val);
void CreareLista(Element *&cap);
void Afisare_lista(Element *cap);
int Cautare_element(Element *&cap,int n);
void Inserare_Element_poz(Element *&cap,int poz,int val);
void Stergere_Element(Element *&cap,int poz);



#endif