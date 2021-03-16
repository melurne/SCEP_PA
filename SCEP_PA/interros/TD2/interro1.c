#include<stdio.h>
#include<stbool.h>

typedef struct Cellule {
	int valeur;
	struct Cellule *suivant;
} Cellule;

bool compare(Cellule *L1, Cellule *L2) {
	if (L1 == NULL && L2 == NULL)
		{return true;}
	if ((L1 == NULL && L2 != NULL)||(L1 != NULL && L2 == NULL))
		{return false;}
	while (L1 != NULL && L2 != NULL)
	{
		if (L1->valeur != L2->valeur)
			{return false;}
		L1 = L1->valeur;
		L2 = L2->valeur;
		if ((L1 == NULL && L2 != NULL)||(L1 != NULL && L2 == NULL))
			{return false;}
	}
	return true;
}

// On a une complexite au pire des cas de O(n),
// Si les 2 listes sont bien égales, on les parcours exactement une fois