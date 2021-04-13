#include<stdio.h>

int fois_deux(int a) {
	return 2*a;
}

void appliquer_tableau(int f(int), int t[], int size) {
	for (int i = 0; i<size; i++)
	{
		t[i] = f(t[i]);
	}
}

int main() {
	int tab[] = {1, 2, 3, 4};
	appliquer_tableau(fois_deux, tab, 4);
	for (int i = 0; i<4; i++)
	{
		printf("%d, ", tab[i]);
	}
	printf("\n");
}
