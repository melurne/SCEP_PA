#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"hashtable.h"

int hashFunc(char key) {
  printf("%d\n", (int)key);
  return (int)key;
}

int main(int argc, char const *argv[]) {
  hashtable table;
  table.hash = &hashFunc;


  char key = 'b';
  int elem = 42;
  printf("key :%d\n", (table.hash)(key));   
  affiche(table.content[98]);
  insert(&table, elem, key);
  affiche(table.content[98]);
  return 0;
}
