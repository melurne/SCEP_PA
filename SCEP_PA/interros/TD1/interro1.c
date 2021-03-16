"""
definition de la structure liste contigue
definition d'une fonction qui compare deux liste_contigue 
	return 1 si l1 = l2
	return 0 si l1 != l2

Merci à Clément Koperski pour son code
"""

#define NB 20

struct liste_contigue
{
	int L[NB];
	int dernier;
};

int isEqual(struct liste_contigue l1, struct liste_contigue l2)
{
	if (l1.dernier == -1 && l2.dernier == -1)
		return 1;

	if (l1.dernier != l2.dernier)
		return 0;
	for (int i=0; i<=l1.dernier;i++)
	{
		if (l1.L[i] != l2.L[i])
			return 0;
	}

	return 1;
}

// On a une complexite au pire des cas de O(n),
// Si les 2 listes sont bien égales, on les parcours exactement une fois