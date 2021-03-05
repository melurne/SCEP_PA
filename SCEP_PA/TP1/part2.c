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
	printf("nom :");
	if (scanf("%s", &(ptr_pers->nom)) == EOF)
		return 1;
	printf("prenom: ");
	scanf("%s", &ptr_pers->prenom);
	printf("numero: ");
	scanf("%d", &ptr_pers->naissance.day);
	scanf("%d", &ptr_pers->naissance.month);
	scanf("%d", &ptr_pers->naissance.year);
	scanf("%s", &ptr_pers->numero);
	return 0;
}

void affich_personne(struct Personne* p) {
	char c;
	
	printf("%s, %s, %s, ", p->nom, p->prenom, p->numero);
	affich_date(&p->naissance);
	printf("\n");
}

int main() {
	struct Personne bob;
	lire_personne(&bob);
	affich_personne(&bob);
}