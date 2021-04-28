#include"liste_chainee.h"
#define MAX_LEN 128

typedef struct hashtable {
  Liste content[MAX_LEN];
  int (*hash)(char);
} hashtable;

void insert(hashtable*, int, char);
