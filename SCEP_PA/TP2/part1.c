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
	if (fscanf(fd, "%s", &ptr_pers->nom) != 1)
		return 1;	
	fscanf(fd, "%s", &ptr_pers->prenom);
	fscanf(fd, "%d", &ptr_pers->naissance.day);
	fscanf(fd, "%d", &ptr_pers->naissance.month);
	fscanf(fd, "%d", &ptr_pers->naissance.year);
	fscanf(fd, "%s", &ptr_pers->numero);
	return 0;
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

int main(int argc, char* argv[]) {
	struct Annuaire annuaire;
	annuaire = construire_annuaire_fichier(argv[1]);	
	affich_annuaire(&annuaire);
}