typedef struct Cell {
	int val;
	struct Cell* next;
} Cell;

typedef Cell* Liste;

void ajout_tete(Liste*, int);
void affiche(Liste);
