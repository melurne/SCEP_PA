#include<stdio.h>
#include"listechainees.c"

int main() {
	Liste L = NULL;
	ajout_tete(&L, "hello");
	afficher_liste(L);
}
