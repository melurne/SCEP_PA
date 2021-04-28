#include<stdio.h>
#include<string.h>
#include<stdbool.h>

typedef struct flights {
  int id;
  char* name;
} flights;

typedef struct Node {
  flights vol;
  struct Node* gauche;  // g <= r
  struct Node* droit;   // d > r
} Node;


flights recherche(Node* arbre, int target_id) {
  if (arbre == NULL)
    flights none;
    none.id = -1;
    strcpy(none.name, "none");
    return none;
  if (arbre->vol.id == target_id)
    return arbre->vol;
  if (arbre->vol.id > target_id)
    recherche(arbre->gauche, target_id);
  else
    recherche(arbre->droit, target_id);
}

bool compare(flights vol1, flights vol2) {
  return vol1.id <= vol2.id;
}

void ajout_feuille(Node** arbre, flights vol) {
  Node* feuille = malloc(sizeof(Node));
  feuille->vol = vol;
  feuille->gauche = NULL;
  feuille->droit = NULL;
  *arbre = feuille;
}

void ajout_trie(Node** arbre, flights vol, bool compare(flights, flights)) {
  if (*arbre == NULL)
    ajout_feuille(arbre, vol);
  if (compare(vol, *(arbre)->vol) == true)
    ajout_trie(&(*(arbre)->gauche), vol);
  else
    ajout_trie(&(*(arbre)->droit), vol);
}
