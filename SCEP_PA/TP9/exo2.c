#include<stdio.h>
#include<stdbool.h>

int croissant(int a, int b) {
	if (a > b)
		return 1;
	if (a == b)
		return 0;
	if (a < b)
		return -1;
}

int decroissant(int a, int b) {
	if (a > b)
		return -1;
	if (a == b)
		return 0;
	if (a < b)
		return 1;
}

void swap(int t[], int i, int j) {
	int tmp = t[i];
	t[i] = t[j];
	t[j] = tmp;
}

void triGenerique(int compare(int, int), int t[], int size) {
	bool permut;
	int passage = 0;
	do {
		permut = false;
		for (int i=0; i<size-passage; i++)
		{
			if (compare(t[i], t[i+1])==1)
			{
				swap(t, i, i+1);
				permut = true;
			}
		}
		passage++;
	}while (permut == true);
}

int main() {
	int t[] = {1, 5, 4, 8, 7};
	triGenerique(decroissant, t, 5);
	for (int i = 0; i<5; i++)
	{
		printf("%d, ", t[i]);
	}
	printf("\n");
}
