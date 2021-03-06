#include<stdio.h>
#include<string.h>
#define MAX_PERSONNES 100

struct Date {
	int day;
	int month;
	int year;
};

struct Personne {
	char nom[50];
	char prenom[50];
	char numero[10];
	struct Date naissance;
};

struct Annuaire {
	int dernier;
	struct Personne contenu[MAX_PERSONNES];
};

struct Date lire_date() {
	struct Date date;
	printf("entrez une date dd/mm/yyyy\n");
	scanf("%d/%d/%d", &(date.day), &(date.month), &(date.year));
	return date;
}

void affich_date(struct Date *date) {
	printf("%d/%d/%d\n", date->day, date->month, date->year);
}

int lire_personne(struct Personne* ptr_pers) {
	if (scanf("%s", &(ptr_pers->nom)) == EOF)
		return 1;
	scanf("%s", &ptr_pers->prenom);
	scanf("%d", &ptr_pers->naissance.day);
	scanf("%d", &ptr_pers->naissance.month);
	scanf("%d", &ptr_pers->naissance.year);
	scanf("%s", &ptr_pers->numero);
	return 0;
}

struct Annuaire construire_annuaire() {
	struct Annuaire annuaire;
	annuaire.dernier = -1;
	while (lire_personne(&(annuaire.contenu[annuaire.dernier+1])) == 0)
	{
		annuaire.dernier++;
	}
	return annuaire;
}

void affich_personne(struct Personne* p) {
	printf("%s, %s, %s, ", p->nom, p->prenom, p->numero);
	affich_date(&p->naissance);
	printf("\n");
}

void affich_annuaire(struct Annuaire* a) {
	for (int i = 0; i <= a->dernier; i++)
	{
		printf("%d ", i);
		affich_personne(&(a->contenu[i]));
	}
}


int main() {
	struct Annuaire annuaire;
	annuaire = construire_annuaire();	
	affich_annuaire(&annuaire);
}
