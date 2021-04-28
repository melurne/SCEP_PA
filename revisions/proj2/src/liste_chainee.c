#include<stdio.h>
#include"liste_chainee.h"

void ajout_tete(Liste* L, int x) {
	Cell* first = malloc(sizeof(Cell));
	first->val = x;
	first->next = *L;
	L = &first;
}

void affiche(Liste L) {
	if (L == NULL)
		printf("\n");
		return;
	printf("%d, ", L->val);
	affiche(L->next);
}
