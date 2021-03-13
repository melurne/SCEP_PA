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

int lire_personne_fichier(struct Personne* ptr_pers, FILE *fd) {
	if (fscanf(fd, "%s\n%s\n%d\n%d\n%d\n%s", 	&ptr_pers->nom,
												&ptr_pers->prenom,
												&ptr_pers->naissance.day,
												&ptr_pers->naissance.month,
												&ptr_pers->naissance.year,
												&ptr_pers->numero
												) != 6)
		return 1;	
	else return 0;
}

struct Annuaire construire_annuaire_fichier(char path[20]) {
	struct Annuaire annuaire;
	annuaire.dernier = -1;
	FILE *fd;
	fd = fopen(path, "r");
	if (fd != NULL)
	{
		while (lire_personne_fichier(&(annuaire.contenu[annuaire.dernier+1]), fd) == 0)
		{
			annuaire.dernier++;
		}
		fclose(fd);
	}
	return annuaire;
}

void affich_personne(struct Personne* p) {
	char c;
	
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

int compare_personne(struct Personne p1, struct Personne p2) {
	return strcmp(p1.nom, p2.nom);
}

int rech_dicho(struct Annuaire annuaire, char target[50]) {
	int a = 0, b = annuaire.dernier;
	int c = (int)(a+b)/2;
	while (b >= a)
	{
		if (strcmp(annuaire.contenu[c].nom, target) == 0)
			return c;
		if (strcmp(annuaire.contenu[c].nom, target) < 0)
		{
			a = c+1;
		}
		else
		{
			b = c-1;
		}
		c = (int)(a+b)/2;
	}
	return -1;
}

int main(int argc, char* argv[]) {
	struct Annuaire annuaire;
	annuaire = construire_annuaire_fichier(argv[1]);	
	affich_annuaire(&annuaire);
	printf("%d\n", rech_dicho(annuaire, "Zebulon"));
}
