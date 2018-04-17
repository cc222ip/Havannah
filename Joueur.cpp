#include "Joueur.h"

Joueur::Joueur() { // Contructeur de joueur - Créé un joueur avec des attributs vides.
    nom = "";
    couleur = 0;
}

void Joueur::creerJ(int numJ) { // Créé un nouveau joueur avec sa couleur en argument.
    cout << "Entrez votre nom de joueur : ";
    cin >> nom;

    ////// Structure préventive //////
    while(cin.fail() || nom.size() > 40) {
        cout << endl;
        cout << "~ La saisie est incorrecte ~" << endl;
        cout << endl;
        cout << "Entrez votre nom de joueur : ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> nom;
    }
    cout << endl;
    couleur = numJ;

    /*
    Possibilité de proposer au joueur de choisir sa couleur.
    cout << "Entrez votre couleur (1, 2 ou 3) : ";
    cin >> couleur;

    ////// Structure préventive //////
    while(cin.fail() || couleur <= 0 || couleur > 3) {
        cout << endl;
        cout << "~ La saisie est incorrecte ~" << endl;
        cout << endl;
        cout << "Entrez votre couleur (1, 2 ou 3) : ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> couleur;
    }
    cout << endl;
    */
}
