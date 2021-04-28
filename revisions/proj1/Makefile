bin/build : lib/main.o lib/liste_chainee.o
	gcc lib/main.o lib/liste_chainee.o -o bin/build

lib/main.o : src/main.c
	gcc -c -w -Wall -Wextra src/main.c -o lib/main.o

lib/liste_chainee.o : src/liste_chainee.c
	gcc -c -w -Wall -Wextra src/liste_chainee.c -o lib/liste_chainee.o
