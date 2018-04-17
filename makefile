main : main.o Jeu.o Partie.o Plateau.o Case.o Joueur.o
	g++ -o main main.o Jeu.o Partie.o Plateau.o Case.o Joueur.o

/main.o : main.cpp
	g++ -o /main.o -c main.cpp

/Jeu.o : Jeu.cpp
	g++ -o /Jeu.o -c Jeu.cpp

/Partie.o : Partie.cpp
	g++ -o /Partie.o -c Partie.cpp

/Plateau.o : Plateau.cpp
	g++ -o /Plateau.o -c Plateau.cpp

/Case.o : Case.cpp
	g++ -o /Case.o -c Case.cpp

/Joueur.o : Joueur.cpp
	g++ -o /Joueur.o -c Joueur.cpp

clean:
	rm -rf /*.o

mrproper: clean
	rm -rf main
