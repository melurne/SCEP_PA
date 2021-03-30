#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#define MAX_STR 20

typedef struct Cellule {
	int valeur[2];
	struct Cellule *suivant;
} Cellule;

typedef Cellule *Liste, *ptCellule;

void ajout_tete(Liste *ptListe, int a) {
	Cellule *c = malloc(sizeof(Cellule));
	c->valeur[0] = a;
	c->valeur[1] = 1;
	c->suivant = *ptListe;
	*ptListe = c;
}

void print_list(Liste L) {
	printf("[");
	while (L != NULL)
	{
		printf("(%d, %d), ", L->valeur[0], L->valeur[1]);
		L = L->suivant;
	}
	printf("]\n");
}

void suprimer_tete(Liste *L) {
	if (*L == NULL)
		{return;}
	ptCellule pt_tete = *L;
	*L = (*L)->suivant;
	free(pt_tete);
}

void insertion_triee(Liste *ptListe, int a) {
	if (*ptListe == NULL)
	{
		ajout_tete(ptListe, a);
		return; 
	}
	if ((*ptListe)->valeur > a) 
	{
		ajout_tete(ptListe, a);
		return;	
	}
	if (a == (*ptListe)->valeur[0])
		{return;}
	Cellule *c = malloc(sizeof(Cellule));
	c->valeur[0] = a;
	c->valeur[1] = 1;
	c->suivant = NULL;

	ptCellule precedent = *ptListe;
	ptCellule p = (*ptListe)->suivant;
	while (p != NULL && a >= p->valeur[0])
	{
		if (a == p->valeur[0] || a == precedent->valeur[0])
			{return;}
		precedent = p;
		p = p->suivant;
	}
	c->suivant = p;
	precedent->suivant = c;
}

void insert(Liste *L, int a) {
	if (*L == NULL || (*L)->valeur[0] > a)
	{
		insertion_triee(L, a);
		return;
	}
	if ((*L)->valeur[0] == a)
	{
		(*L)->valeur[1]++;
		return;
	}
	insert(&((*L)->suivant), a);
}

void lire_fichier(Liste *L, char *path) {
	FILE *f = fopen(path, "r");
	int a;
	while (fscanf(f, "%d", &a) == 1)
	{
		insert(L, a);
	}
}

Liste union_listes(Liste L1, Liste L2) {
	if (L1 == NULL && L2 == NULL)
		return NULL;
	if (L1 == NULL)
		return L2;
	if (L2 == NULL)
		return L1;
	ptCellule c = malloc(sizeof(Cellule));
	if (L1->valeur[0] == L2->valeur[0])
	{
		c->valeur[0] = L1->valeur[0];
		c->valeur[1] = L1->valeur[1] + L2->valeur[1];
		c->suivant = union_listes(L1->suivant, L2->suivant);
		return c;
	} 
	if (L1->valeur[0] > L2->valeur[0])
	{
		c->valeur[0] = L2->valeur[0];
		c->valeur[1] = L2->valeur[1];
		c->suivant = union_listes(L1, L2->suivant);
		return c;
	}
	c->valeur[0] = L1->valeur[0];
	c->valeur[1] = L1->valeur[1];
	c->suivant = union_listes(L1->suivant, L2);
	return c;
}

Liste intersect_listes(Liste L1, Liste L2) {
	if (L1 == NULL || L2 == NULL)
		return NULL;
	if (L1->valeur[0] == L2->valeur[0])
	{
		ptCellule c = malloc(sizeof(Cellule));
		c->valeur[0] = L1->valeur[0];
		c->valeur[1] = L1->valeur[1]<=L2->valeur[1] ? L1->valeur[1] : L2->valeur[1];//min(L1->valeur[1], L2->valeur[1]);
		c->suivant = intersect_listes(L1->suivant, L2->suivant);
		return c;
	} 
	if (L1->valeur[0] > L2->valeur[0])
	{	
		return intersect_listes(L1, L2->suivant);
	}
	return intersect_listes(L1->suivant, L2);
}

Liste diff_listes(Liste L1, Liste L2) {
	if (L1 == NULL && L2 == NULL)
		return NULL;
	if (L1 == NULL)
		return L2;
	if (L2 == NULL)
		return L1;
	ptCellule c = malloc(sizeof(Cellule));
	if (L1->valeur[0] == L2->valeur[0] && L1->valeur[1] != L2->valeur[1])
	{
		c->valeur[0] = L1->valeur[0];
		c->valeur[1] = L1->valeur[1] - L2->valeur[1] > 0 ? L1->valeur[1] - L2->valeur[1] : -L1->valeur[1] + L2->valeur[1];
		c->suivant = diff_listes(L1->suivant, L2->suivant);
		return c;
	} 
	if (L1->valeur[0] == L2->valeur[0] && L1->valeur[1] == L2->valeur[1])
	{
		return diff_listes(L1->suivant, L2->suivant);
	} 

	if (L1->valeur[0] > L2->valeur[0])
	{
		c->valeur[0] = L2->valeur[0];
		c->valeur[1] = L2->valeur[1];
		c->suivant = diff_listes(L1, L2->suivant);
		return c;
	}
	c->valeur[0] = L1->valeur[0];
	c->valeur[1] = L1->valeur[1];
	c->suivant = diff_listes(L1->suivant, L2);
	return c;
}

int main(int argc, char* argv[]) {
	Liste l1 = NULL;
	Liste l2 = NULL;
	lire_fichier(&l1, argv[1]);
	lire_fichier(&l2, argv[2]);
	Liste l12 = diff_listes(l1, l2);
	print_list(l1);
	print_list(l2);
	print_list(l12);
}