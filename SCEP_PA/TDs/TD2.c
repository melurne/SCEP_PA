#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define NBE 4
#define NN 2
#define MAX_ELEVES 10
#define MAX_STR 20
#define NIP_LEN 8

struct Date {
	int day;
	int month;
	int year;
};

struct Eleve {
	char NIP[NIP_LEN];
	char nom[MAX_STR];
	char prenom[MAX_STR];
	struct Date naissance;
	float notes[NN];	
};

struct Classe {
	int dernier;
	struct Eleve effectif[MAX_ELEVES];
};

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
			if (strcmp(class->effectif[i].NIP, class->effectif[i+1].NIP)>0)
			{
				swapEleve(class, i, i+1);
				permut = true;
			}
		}
		passage++;
	}while (permut == true);
}

int find_eleve(struct Classe *class, char NIP_target[NIP_LEN]) {
	int i =0;
	while (i <= class->dernier && strcmp(class->effectif[i].NIP, NIP_target)<0)
	{
		i++;
	}

	if (i <= class->dernier)
	{
		return i;
	}
	else return -1;
}

void add_eleve(struct Classe *class, struct Eleve *eleve) {
	if (class->dernier < MAX_ELEVES-1)
	{
		class->dernier ++;
		class->effectif[class->dernier] = *eleve;
		int i = class->dernier;
		while (i>0 && strcmp(class->effectif[i-1].NIP, class->effectif[i].NIP)>0)
		{
			swapEleve(class, i-1, i);
			i=i-1;
		}
	}
	else printf("La classe est deja pleine\n");
}

void remove_eleve(struct Classe *class, char NIP_eleve) {
	for (int i = find_eleve(class, NIP); i<dernier; i++)
	{
		swapEleve(class, i, i+1);
	}
	class->dernier = class->dernier-1;
}
int main() {
	float notes[4][2] = {{10.0, 15.0}, {14.0, 13.0}, {11.0, 11.0}, {16.0, 12.0}};

	struct Eleve elv1 = {"SMITH", "John", {1, 1, 2000}, notes[0]};
	struct Eleve elv2 = {"CUNIN", "Mathis" ,{28, 6, 2000}, notes[1]};
	struct Eleve elv3 = {"TACIAK", "Pierre", {24, 1, 2000}, notes[2]};
	struct Eleve elv4 = {"GAILLARD", "Eva", {14, 9, 2000}, notes[3]};
	struct Classe classe = ;
}
