#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define NBE 4
#define NN 2


struct Date {
	int day;
	int month;
	int year;
};

struct Eleve {
	char nom[20];
	char prenom[20];
	struct Date naissance;
	float notes[NN];	
};

struct Classe {
	struct Eleve effectif[NBE];	
};

float moyenneEleve(struct Eleve eleve) {
	float somme = 0;
	for (int i = 0; i < NN; i++)
	{
		somme = somme + eleve.notes[i];
	}
	return somme/NN;
}

void affichClasse(struct Classe *classe) {
	struct Eleve eleve;
	for (int i = 0; i<NBE; i++)
	{
		eleve = classe->effectif[i];
		printf("%s %s %d / %d / %d %f\n",eleve.nom, eleve.prenom, eleve.naissance.day, eleve.naissance.month, eleve.naissance.year, moyenneEleve(eleve));
	}
}

int comparefull(struct Date d1, struct Date d2){
	if (d1.year > d2.year)
		return 1;
	if (d1.year < d2.year)
		return -1;
	if (d1.month > d2.month)
		return 1;
	if (d1.month < d2.month)
		return -1;
	if (d1.day > d2.day)
		return 1;
	if (d1.day < d2.day)
		return -1;
	else return 0;
}

void swapEleve(struct Classe *class, int a, int b) {
	struct Eleve tmp;
	tmp = class->effectif[a];
	class->effectif[a] = class->effectif[b];
	class->effectif[b] = tmp;
}

void triClasse(struct Classe *class) {
	bool permut;
	int passage = 0;
	do {
		permut = false;
		for (int i=0; i<NBE-passage; i++)
		{
			if (comparefull(class->effectif[i].naissance, class->effectif[i+1].naissance))
			{
				swapEleve(class, i, i+1);
				permut = true;
			}
		}
		passage++;
	}while (permut == true);
}

int main() {
	float notes[4][2] = {{10.0, 15.0}, {14.0, 13.0}, {11.0, 11.0}, {16.0, 12.0}};

	struct Eleve elv1 = {"SMITH", "John", {1, 1, 2000}, (*notes)[0]};
	struct Eleve elv2 = {"CUNIN", "Mathis" ,{28, 6, 2000}, (*notes)[1]};
	struct Eleve elv3 = {"TACIAK", "Pierre", {24, 1, 2000}, (*notes)[2]};
	struct Eleve elv4 = {"GAILLARD", "Eva", {14, 9, 2000}, (*notes)[3]};
	struct Classe classe = {{elv1, elv2, elv3, elv4}};
	affichClasse(&classe);
	triClasse(&classe);
	affichClasse(&classe);

}
