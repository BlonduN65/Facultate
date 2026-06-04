#ifndef HEADER_H_
#define HEADER_H_
struct Nod {
	char data;
	Nod* stg, *drt;
};

Nod* creareArbore();
void PREORDINE(Nod* p);
void POSTORDINE(Nod *p);
int Adancime(Nod *p);
int NrNoduri(Nod *p);
void INORDINE(Nod *p);
int NrFrunze(Nod *p);
char maxsubarb(Nod *p);
void AfiseazaNoduriMax(Nod *p);
char minsubarb(Nod *p);
void Verificare_stg_mic_drt(Nod *p);


#endif
