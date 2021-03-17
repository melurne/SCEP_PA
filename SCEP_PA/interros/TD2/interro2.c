"""
Definition de la structure liste contigue
Fonction qui renvoie le nombre d'élement d'une liste contigue l
qui sont supérieurs à un entier donné x

Code de NEUS Maxence
"""

#define MAX_LEN 20

typedef struct Liste {
	int L[MAX_LEN];
	int dernier;
} Liste;

int superieur(Liste l, int x) {
	if (l.dernier == -1)
		{return 0;}
	int output = 0;
	for (int i = 0; i <= l.dernier; i++)
	{
		if (l.L[i] >= x) 
			{output++;}
	}
	return output;
}