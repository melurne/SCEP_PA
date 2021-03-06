#include<stdio.h>
#include<string.h>

struct Date {
	int day;
	int month;
	int year;
};

struct Date lire_date() {
	struct Date date;
	printf("entrez une date dd/mm/yyyy\n");
	scanf("%d/%d/%d", &(date.day), &(date.month), &(date.year));
	return date;
}

void affich_date(struct Date *date) {
	printf("%2d/%2d/%4d\n", date->day, date->month, date->year);
}

int main() {
	struct Date my_date = lire_date();
	printf("La date entrée : ");
	affich_date(&my_date);
}