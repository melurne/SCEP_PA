#include"hashtable.h"

void insert(hashtable* table, int elem, char key) {
  ajout_tete( &(table->content[(table->hash)(key)]),
              elem);
}
