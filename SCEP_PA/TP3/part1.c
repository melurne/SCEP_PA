#include<stdio.h>
#include<stdbool.h>

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
		printf("%p ", L);
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
		//printf("%p\n", L->suivant);
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

int main() {
	Liste L1;
	L1 = NULL;
	ajout_tete(&L1, 9);
	ajout_tete(&L1, 7);
	ajout_tete(&L1, 2);
	ajout_tete(&L1, 1);
	print_list(L1);
	//printf("%p\n", L1);
	printf("is_sorted = %d\n", (int)is_sorted(L1));

	suprimer_tete(&L1);
	print_list(L1);

	free_list(&L1);
	print_list(L1);
	printf("is_sorted = %d\n", (int)is_sorted(L1));

	suprimer_tete(&L1);
	print_list(L1);

	ajout_tete(&L1, 9);
	ajout_tete(&L1, 10);
	ajout_tete(&L1, 2);
	ajout_tete(&L1, 1);
	print_list(L1);
	//printf("%p\n", L1);
	printf("is_sorted = %d\n", (int)is_sorted(L1));
	free_list(&L1);
}