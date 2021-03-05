#include<stdio.h>
#define MAX_LEN 20

typedef struct Liste {
	int dernier;
	int contenu[MAX_LEN];
} Liste;

void ajout_elem_queue(Liste *l, int elem) {
	if ((*l)->dernier == MAX_LEN-1)
	{
		printf("La liste est déja pleine\n");
		return;
	}
	(*l)->dernier++;
	(*l)->contenu[(*l)->dernier] = elem;
}

void affiche_liste(Liste l) {
	printf("[");
	for (int i = 0; i <= dernier; i++)
	{
		printf("%d, ", l->contenu[i]);
	}
	printf("] dernier = %d\n", l->dernier)
}

int main() {
	Liste l;
	l->dernier = -1;
	ajout_elem_queue(&l, 1);
	ajout_elem_queue(&l, 2);
	ajout_elem_queue(&l, 4);
	ajout_elem_queue(&l, 9);
	affiche_liste(l);
	ajout_elem(&l, 7);
	ajout_elem(&l, 42);
	affiche_liste(l);
}
