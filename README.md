# Pagerank
Methode des puissances et accélération de Aitken

## Fichiers
* def : structures utilisées
* main : chrono (temps et itération) sur les différents fichiers
* matrice : importation d'une matrice à partir d'un fichier
* puissances : implémentation de la méthode des puissances Pagerank
* aitken : implémentation de l'accélération de Aitken
* normes.p : script génération des courbes avec GNUPLOT

## Remarque importante

Passer à l'étape suivante que s'il n'y a AUCUN problème de mémoire.

N'hésitez pas à créer des fichiers petits (comme web1 etc) pour tester les résultats à la main.

1. Tester d'abord sur les petits graphes. Vérifier les résultats à la main (dessin du graphe et de la matrice), on pourra décommenter les affichages.
2. Tester sur le plus petit des 6 graphes : "wb-cs-stanford" (37 000) valeurs.
3. Si aucun problème de mémoire, exécuter l'étape 2 sans le mode debug pour avoir des chronos plus propres.
4. Revenir à l'étape 2 avec un nouveau graphe par ordre croissant de taille

## Utilisation

1. Modifier dans le Makefile les variables DEBUG, GRAPHE et METHODE
2. Ensuite se placer dans App/ : ```cd App```
3. Pour la compilation et l'exécution : ```make```
4. Les affifachages (printf) de l'applications sont consultables dans le dossier App/graphes/ fichier "METHODE-GRAPHE"
5. ```make plot``` pour générer les courbes à partir des 6 fichiers résultats
