#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 30

//Declaration de liste chainee de chaines de caracteres
struct cell {
  char val[MAXSIZE];
  struct cell * suiv;
};

//OPTIONNEL: vous pouvez utiliser ces typedefs si vous voulez !
typedef struct cell   Cellule;
typedef struct cell * Liste;
typedef struct cell * ptCellule;

//Affichage de la liste en ligne
void afficher_liste(Liste L) {
	printf("[");
	while (L != NULL) {
		printf("%s, ", L->val);
		L = L->suiv;
	}
	printf("]\n");
}

//Ajout d'un mot en tete de la liste
void ajout_tete(Liste* pL, char * string) {
	ptCellule c = malloc(sizeof(Cellule));
	strcpy(string, c->val);
	if (*pL != NULL)
		c->suiv = (*pL)->suiv;
	else
		c->suiv = NULL;
	*(pL) = c;
}

//Suppression du mot en tete de la liste
void supp_tete(Liste* pL) {
	ptCellule tofree = *pL;
	(*pL) = (*pL)->suiv;
	free(tofree);
}

//Ajout un mot dans une liste supposee
// triee dans l'ordre alphabetique
void ajout_alphab(struct cell ** pl, char * mot)
{
	// liste vide ou mot < mot prochain => ajout en tête
    if ( (*pl == NULL) || (strcmp(mot, (*pl)->val) < 0) )
    {
        ajout_tete(pl,mot);
    }
    else
    {
    	// mot > mot prochain => ajouter après dans la liste
        if (strcmp(mot, (*pl)->val) > 0)
        {
            ajout_alphab(&(*pl)->suiv,mot);
        }
        //else => mot déjà dans la liste, ne rien faire?
    }
}

//Dit si un mot donne est dans la liste
//pas forcement triee
bool appartient(Liste L, char * string) {
	if (L == NULL)
		return false;
	if (strcmp(L->val, string) == 0)
		return true;
	return appartient(L, string);
}

//Donne la taille de la liste.
int taille(Liste L) {
	if (L == NULL)
		return 0;
	return 1 + taille(L->suiv);
}

//construit une liste triee a partir d'un fichier
void charge_fichier(FILE * fp, struct cell ** pl)
{
    char mot[MAXSIZE];

	//Nb d'elements à lire dans chaque fscanf
    const int NB_A_LIRE = 1;

	//`man fscanf` pour comprendre les valeurs de retour!!!
    while (fscanf(fp, "%s", mot) == NB_A_LIRE)
    {
        ajout_alphab(pl, mot);
    }

    //On peut tester la bonne ou mauvaise terminaison de la lecture
    if(feof(fp))    printf("Fin normal de lecture\n");
    if(ferror(fp))  printf("ERREUR de lecture\n");

}

//Destruction de Liste.
void detruire_liste(Liste* pL) {
	if ((*pL) == NULL)
		return;
	detruire_liste(&((*pL)->suiv));
	free(*pL);
}

