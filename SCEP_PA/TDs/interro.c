// Question 1

typedef struct Cellule {
	int valeur;
	struct Cellule *suivant;
} Cellule;

typedef Cellule *Liste, *ptCellule;

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

// Complexité O(n); où n = len(L1) 

// Question 2

typedef struct Cellule {
	int valeur;
	struct Cellule *suivant;
} Cellule;

void supprimer(Liste *l) {
	ptCellule ptr;
	while (*l != NULL) {
		ptr = (*l)->suivant;
		free(*l);
		*l = ptr;
	}
}

// Complexité O(n); où n = len(l)
