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

bool is_sorted(Liste L) {
	if (L == NULL || L->suivant == NULL)
		return true;
	if (L->valeur[0] >= L->suivant->valeur[0])
		return false;
	return is_sorted(L->suivant);
}

void delete_all(Liste *L) {
	if (*L == NULL)
		{return;}
	suprimer_tete(L);
	delete_all(L);
}

int multiplicite(Liste L, int a) {
	if (L == NULL)
		return 0;
	if (L->valeur[0] == a)
		return L->valeur[1];
	return multiplicite(L->suivant, a);
}

int cardinal(Liste L) {
	if (L == NULL)
		return 0;
	return L->valeur[1] + cardinal(L->suivant);
}

int main(int argc, char *argv[]) {
	Liste l = NULL;
	// insert(&l, 1);
	// insert(&l, 1);
	// insert(&l, 4);
	// insert(&l, 18);
	lire_fichier(&l, argv[1]);
	print_list(l);
	printf("is_sorted = %d\n", (int)is_sorted(l));
	//delete_all(&l);
	//print_list(l);
	
	printf("multiplicite(1) = %d\n", multiplicite(l, 1));
	printf("multiplicite(9) = %d\n", multiplicite(l, 9));
	printf("multiplicite(42) = %d\n", multiplicite(l, 42));
	printf("cardinal = %d\n", cardinal(l));
}