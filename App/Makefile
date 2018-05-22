#graphe et méthode à tester : puissances ou aitken
GRAPHE = wb-cs-stanford.txt
METHODE = aitken

#option -g debug pour exécuter avec valgrind : yes / no
DEBUG = yes

ifeq ($(DEBUG),yes)
	CFLAGS = -g
else
	CFLAGS =
endif

#Nom de l'exécutable
EXEC = pagerank

#Liste des fichiers sources et objets
SRC = $(wildcard *.c)
OBJ = $(SRC:.o=.c)


#Edition de liens / génération de l'exécutable
all: $(EXEC)
ifeq ($(DEBUG),yes)
	valgrind --track-origins=yes ./$(EXEC) $(METHODE) graphes/$(GRAPHE) > graphes/$(METHODE)-$(GRAPHE)
else
	./$(EXEC) $(METHODE) graphes/$(GRAPHE) > graphes/$(METHODE)-$(GRAPHE)
endif

$(EXEC) : $(OBJ)
	@gcc -o $@ $^ -lm

#Génération des graphes
plot:
	gnuplot normes.p

#Compilation des .c
main.o : matrice.h puissances.h aitken.h

%.o : %.c def.h
	@gcc $(CFLAGS) -o $@ -c $< 
	

#Nettoyage du projet
.PHONY : $(EXEC) plot clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf pagerank
