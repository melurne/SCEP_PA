/*
 * Source Code From Laure Gonnord, 2012
 * Adapted from Bernard Carre, 2011
 * Re-adapted by Walter Rudametkin in 2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 *List library : reminder, the word have maximal size  MAXSIZE
 */
#include "listechaines.h"

/*
 *Size of the hashtables
 */
#define TABLE_SIZE 1

/*
 * Hash function
 */
int asciis(char *word)
{
	int i=0;
	int h=0;
	while(word[i]!='\0')
	{
		h=h+(word[i]-96);
		i++;
	}
	return h;
}

/*
 * Index function: hashes the word and returns a valid index
 */
int get_hashed_index(char *word)
{
	return (asciis(word) % TABLE_SIZE);
}



/****************************************
 *
 * TODO : write the following functions
 *
 ****************************************/

/*
 * Declaration of type Hashtable
 */
//!!! TODO: Wrong type, used only for compiling, please FIX!
typedef	Liste Hashtable[TABLE_SIZE];

/*
 * Initialisation of a given Hashtable
 */
void init_ht(Hashtable ht)
{
	printf("init\n");
	for (int i = 0; i<TABLE_SIZE;i++)
	{
		ht[i] = NULL;
	}
}

/*
 * Update of the hashtable : add the given word in the table!
 */
void update_ht(char *word, Hashtable ht)
{
	printf("update\n");
	ajout_alphab(&(ht[get_hashed_index(word)]), word);
}

/*
 * Load the file in the internal structure ht
 */
void load_ht(FILE *fp, Hashtable ht)
{
	printf("load\n");
	char *word;
	while (fscanf(fp, "%s", &word) == 1)
	{
		update_ht(word, ht);
	}
}

/*
 * Count the collisions
 */
void collisions(Hashtable ht)
{
	//TODO
}

/*
 * Maximal hash of the words of the given file
 * returns max_word such that get_hashed_index(max_word)=hmax
 */
void max_hash(FILE *fp, char *max_word, int *hmax)
{
	//TODO
}

/*
 * Main function
 */
int main(int argc, char *argv[])
{
	//Guard clause: is text file is missing from parameter ?
	if (argc < 2)
	{
		fprintf(stderr, "usage: hash <file_name>\n");
		return EXIT_FAILURE;
	}

	FILE *fp;
	fp=fopen(argv[1], "r");
	if (fp==NULL)
	{
		fprintf(stderr, "no such file, or unreachable: %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	/*
	 * File is open, continue processing
	 */

	//Initial load using linked lists !
	Hashtable ht;
	init_ht(ht);
	load_ht(fp,ht);
	
	printf("printing\n");
	for (int i = 0; i<TABLE_SIZE; i++)
	{
		afficher_liste(ht[i]); //For testing, print list
	}

	//TODO !
	//replace by declaration and use of hashtables!
	//TODO !


	printf("Finished\n");

	return EXIT_SUCCESS;
}
