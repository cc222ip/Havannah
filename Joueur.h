#include <iostream>
using namespace std;

class Joueur {
    string nom; // Nom du joueur.
    int couleur; // 0 = Vide / 1 = J1 / 2 = J2 / 3 = J3
    friend class Partie; // Permet une interraction entre les classes 'Joueur' et 'Partie'.

    public:
        Joueur(); // Contructeur de joueur - Créé un joueur avec des attributs vides.
        void creerJ(int); // Créé un nouveau joueur avec sa couleur en argument.
};
