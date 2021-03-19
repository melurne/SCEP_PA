#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#define MAX_STR 20

typedef struct Cellule {
	int valeur;
	struct Cellule *suivant;
} Cellule;

typedef Cellule *Liste, *ptCellule;

void ajout_tete(Liste *ptListe, int a) {
	Cellule *c = malloc(sizeof(Cellule));
	c->valeur = a;
	c->suivant = *ptListe;
	*ptListe = c;
}

void print_list(Liste L) {
	printf("[");
	while (L != NULL)
	{
		printf("%d, ", L->valeur);
		L = L->suivant;
	}
	printf("]\n");
}

bool is_sorted(Liste L) {
	if (L == NULL)
		{return true;}

	while (L->suivant != NULL)
	{
		if (L->suivant->valeur < L->valeur)
			{return false;}
		L = L->suivant;
	}
	return true;
}

void suprimer_tete(Liste *L) {
	if (*L == NULL)
		{return;}
	ptCellule pt_tete = *L;
	*L = (*L)->suivant;
	free(pt_tete);
}

void free_list(Liste *L) {
	while (*L != NULL)
	{
		ptCellule pt_tete = *L;
		*L = (*L)->suivant;
		free(pt_tete);
	}
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
	if (a == (*ptListe)->valeur)
		{return;}
	Cellule *c = malloc(sizeof(Cellule));
	c->valeur = a;
	c->suivant = NULL;

	ptCellule precedent = *ptListe;
	ptCellule p = (*ptListe)->suivant;
	while (p != NULL && a >= p->valeur)
	{
		if (a == p->valeur || a == precedent->valeur)
			{return;}
		precedent = p;
		p = p->suivant;
	}
	c->suivant = p;
	precedent->suivant = c;
}

Liste lecture_fichier(char path[MAX_STR]) {
	Liste L = NULL;
	int val = 0;
	FILE *f = fopen(path, "r");
	if (f == NULL)
	{
		printf("oups\n");
		return L;
	}
	while (fscanf(f, "%d", &val) == 1)
	{
		insertion_triee(&L, val);
	}
	fclose(f);
	return L;
}

int main(int argc, char* args[]) {
	printf("%s\n", args[1]);
	Liste L = lecture_fichier(args[1]);
	print_list(L);
	free_list(&L);
}