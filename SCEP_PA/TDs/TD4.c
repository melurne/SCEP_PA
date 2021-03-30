#include<stdio.h>
#include<stdbool.h>

typedef struct Cellule {
	int valeur;
	struct Cellule *suivant;
} Cellule;

typedef Cellule *Liste;

void affiche_liste(Liste l) {
	if (l == NULL) 
	{
		printf("\n");
		return;
	}
	printf("%d, ", l->valeur);
	affiche_liste(l->suivant);
}

float pow(float x, unsigned int n) {
	if (n == 0) return 1;
	if (n == 1) return x;
	return x*pow(x, n-1);
}

int occurences(int n, Liste l) {
	if (l == NULL) return 0;
	if (l->valeur == n) return 1 + occurences(l->suivant);
	return occurences(l->suivant);
}

// on suppose que la liste l est triée

bool is_set(Liste l) {
	if (l == NULL) return true;
	if (l->suivant == NULL) return true;
	if (l->valeur == l->suivant->valeur) return false;
	return is_set(l->suivant);
}

void remove(Liste *l, int x) {
	if (*l == NULL) return;
	if ((*l)->valeur == x)
	{
		*l = *l->suivant;
		return;
	}
	remove(&(*l->suivant), x);
}
