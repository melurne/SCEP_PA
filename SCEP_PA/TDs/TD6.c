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

typedef fifo scheduler[NB_PRIO];

Processus nop() {
	Processus proc = {0, "NOP", "root", "40"};
	return proc;
}

void ajout_queue(fifo *f, Processus proc) {
	Cellule *c = malloc(sizeof(Cellule));
	c->valeur = proc;
	c->suivant = NULL;
	if (f->tete == NULL)
	{
		f->tete = c;
		f->queue = c;
	}
	else
	{
		f->queue->suivant = c;
		f->queue = c;
	}	
}

void ajouter(scheduler s, Processus proc, int priorite) {
	ajout_queue(&(s[priorite]), proc);
}

Processus pop(fifo *file) {
	if (file->tete == NULL)
	{
		return nop();
	}
	Processus p = file->tete->valeur;
	Cellule *tete = file->tete;
	file->tete = file->tete->suivant;
	if (tete == file->queue)
	{
		file->queue = NULL;
	}
	free(tete);
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