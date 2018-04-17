#include "Case.h"

Case::Case() { // Constructeur de case.
    x = 0; // Coordonnées de la case initialisées à 0.
    y = 0;
    couleur = 0;
    visite = false;
}

void Case::afficher() { // Affiche la couleur d'une case.
    cout << this->couleur;
}

void Case::out() { // Initialise une case à 8 (hors plateau).
    this->couleur = 8;
}

void Case::J1() { // Initialise une case à 1 (joueur 1).
    this->couleur = 1;
}

void Case::J2() { // Initialise une case à 2 (joueur 2).
    this->couleur = 2;
}

void Case::J3() { // Initialise une case à 3 (joueur 3).
    this->couleur = 3;
}

bool Case::isOut() { // Vérifie si la case est hors plateau.
    if(this->couleur == 8) {
        return true;
    }
    return false;
}

bool Case::vide() { // Vérifie si la case est vide.
    if(this->couleur == 0) {
        return true;
    }
    return false;
}

bool Case::pleine() { // Vérifie si la case est pleine.
    if(this->couleur == 1 || this->couleur == 2 || this->couleur == 3) {
        return true;
    }
    return false;
}
