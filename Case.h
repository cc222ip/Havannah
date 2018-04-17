#include <iostream>
using namespace std;

class Case {
    int x; // Coordonnées de la case
    int y;
    int couleur; // 0 = Vide / 1 = J1 / 2 = J2 / 3 = J3 / 8 = Hors plateau
    bool visite;
    friend class Partie;
    friend class Plateau;

    public:
        Case(); // Constructeur de case.
        void afficher(); // Affiche la couleur d'une case.
        void out(); // Initialise une case à 8 (hors plateau).
        void J1(); // Initialise une case à 1 (joueur 1).
        void J2(); // Initialise une case à 2 (joueur 2).
        void J3(); // Initialise une case à 3 (joueur 3).
        bool isOut(); // Vérifie si la case est hors plateau.
        bool vide(); // Vérifie si la case est vide.
        bool pleine(); // Vérifie si la case est pleine.
};
