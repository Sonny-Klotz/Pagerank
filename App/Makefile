#graphe à tester
GRAPHE = Stanford.txt

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
	valgrind ./$(EXEC) graphes/$(GRAPHE) > graphes/results-$(GRAPHE)
else
	./$(EXEC) graphes/$(GRAPHE) > graphes/results-$(GRAPHE)
endif

$(EXEC) : $(OBJ)
	@gcc $(CFLAGS) -o $@ $^


#Compilation des .c
main.o :matrice.h puissances.h aitken.h

%.o : %.c def.h
	@gcc $(CFLAGS) -o $@ -c $<


#Nettoyage du projet
.PHONY : $(EXEC) clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf pagerank
