#include<stdio.h>
#include<stdlib.h>

int compare(const void * pa, const void * pb) {
	return strcmp(*(char **)pa, *(char **)pb);
}

int main() {
	char *tab[] = {"hello", "world", "magic", "is", "in", "the", "air", "tonight"};
	qsort(tab, 8, sizeof(char*), compare);
	for (int i = 0; i<8; i++) 
	{
		printf("%s, ", tab[i]);
	}
}
