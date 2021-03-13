#include<stdio.h>


typedef struct Cellule {
	int valeur;
	struct Cellule *suivant;
} Cellule;

typedef Cellule* Liste, ptCellule;

void concatenate(Liste *L1, Liste L2) {
	if (*L1 == NULL)
	{
		*L1 = L2;
		return;
	}
	ptCellule p1 = *L1;
	while (p1->suivant != NULL)
	{
		p1 = p1->suivant;
	}
	p1->suivant = L2;
}

void ajout_tete(Liste *ptListe, int a) {
	Cellule *c = malloc(sizeof(Cellule));
	c->valeur = a;
	c->suivant = *ptListe;
	*ptListe = &c;
}

void insertion(Liste *ptListe, int a) {
	Cellule c;
	c->valeur = a;
	c->suivant = NULL;
	if (*ptListe == NULL)
	{
		ajout_tete(ptListe, a); 
	}
	if (*ptListe->valeur > a) 
	{
		ajout_tete(ptListe, a);	
	}
	ptCellule p = *ptListe;
	while (a >= p->valeur && p->suivant != NULL)
	{
		p = p->suivant;
	}
	c->suivant = p->suivant;
	p->suivant = &c;
}

void supprimer_tete(Liste *ptListe) {
	*ptListe = (*ptListe)->suivant;
}

void supprimer(Liste *ptListe, int a) {
	if (*ptListe == NULL) return;
	if ((*ptListe)->valeur == a)
	{
		supprimer_tete(ptListe);
		return;
	}
	ptCellule precedent = *ptListe;
	ptCellule p = precedent->suivant;
	while (a != p->valeur && p != NULL)
	{
		precedent = p;
		p = p->suivant;
	}
	if (p != NULL)
	{
		precedent->suivant = p->suivant;
	}
}

int main() {
	Liste liste1;
	Liste liste2;
	insertion(&liste1, 2);
	insertion(&liste1, 4);
	insertion(&liste2, 1);
	insertion(&liste2, 5);


}
