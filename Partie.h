#include <iostream>
using namespace std;
#include "Plateau.h"
#include "Joueur.h"
#include <fstream> // Permet de lire et d'écrire sur des fichiers (utile pour la sauvegarde de partie).


class Partie {
    int nbJoueurs; // Nombre de joueurs de la partie.

    public:
        Partie(); // Constructeur de 'Partie' - Lance une nouvelle partie.
        Partie(int); // Constructeur de 'Partie' avec le nombre de joueurs en argument.
        Case* tour(Plateau, Joueur, int &); // Tour de jeu durant la partie.
        void sauvegarde(Case *, Joueur, int); // Sauvegarde une partie déjà commencée.
        void charger(); // Charge une partie stocké dans le fichier texte "savefile".
};
