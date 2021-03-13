#include<stdio.h>
#include<string.h>
#define MAX_STR 50
#define NB_PRIO 41

typedef struct processus {
	int pid;
	char nom[MAX_STR];
	char user[MAX_STR];
	int priorite;
} Processus;

typedef struct Cellule {
	Processus valeur;
	struct Cellule *suivant;
} Cellule;

typedef struct fifo {
	Cellule *tete;
	Cellule *queue;
} fifo;

typedef struct file {
	fifo file_attente[NB_PRIO];
} file;

Processus nop() {
	Processus proc = {0, "NOP", "root", "40"};
	return proc;
}

void ajout_queue(fifo *f, Processus proc) {
	Cellule *c = malloc(sizeof(Cellule));
	c->valeur = proc;
	c->suivant = NULL;
	f->queue->suivant = c;
	f->queue = c;
}

Processus pop(fifo *file) {
	if (file->tete == NULL)
	{
		return nop();
	}
	Processus p = file->tete->valeur;
	file->tete = file->tete->suivant;
	return p;
}

Processus suivant(file f) {
	int i =0;
	while (i<NB_PRIO && f.file_attente[i].tete == NULL)
	{
		i++;
	}
	if (i == NB_PRIO)
	{
		return nop();
	}
	return pop(&f.file_attente[i]);
}