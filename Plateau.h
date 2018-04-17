#include <iostream>
using namespace std;
#include "Case.h"

class Plateau {
    int size; // Taille du plateau de jeu.
    Case **P; // Tableau représentant le plateau de jeu.
    friend class Case;

    public:
        Plateau(); // Créé le plateau de jeu en demandant au joueur de choisir sa taille.
        Plateau(int); // Créé le plateau de jeu avec une taille entrée par le développeur.
        ~Plateau();  //Destructeur de la classe "Plateau".
        void afficher(); // Affiche le plateau de jeu.
        bool vide(); // Détecte si le plateau de jeu est vide.
        bool rempli(); // Détecte si le plateau de jeu est rempli.
        int getsize() { return size; } // Récupère la taille du plateau de jeu.
        Case **getP() { return P; } // Récupère le tableau stockant le plateau de jeu.
        Case *voisinHautD(Case *); // Retourne le voisin haut droit de la case donnée en argument.
        Case *voisinBasD(Case *); // Retourne le voisin bas droit de la case donnée en argument.
        Case *voisinHautG(Case *); // Retourne le voisin haut gauche de la case donnée en argument.
        Case *voisinBasG(Case *); // Retourne le voisin bas gauche de la case donnée en argument.
        Case *voisinGauche(Case *); // Retourne le voisin gauche de la case donnée en argument.
        Case *voisinDroit(Case *); // Retourne le voisin droit de la case donnée en argument.
        bool coin(Case *); // Détecte si la case donnée en argument est sur un des coins du plateau.
        int nbVoisin(Case *); // Renvoi le nombre de voisins de la case donnée en argument.
        Case *voisin(Case *, int); // Renvoi le (ou les) voisins de la case donnée en arguement.
        bool haveVoisin(Case *); // Détecte si la case donnée en argument à un (ou plusieurs) voisin(s).
        //bool pont(Case *); //Condition de victoire du pont. Ne fonctionne pas.
        bool bord(Case *); // Détecte si la case donnée en argument est sur un des bords du plateau.
};
