#include "Plateau.h"

Plateau::Plateau() { // Construit le plateau de jeu vide.
    cout << "Entrez la taille du plateau de jeu (entre 2 et 10) : ";
    cin >> size; // Taille du plateau de jeu saisie par l'utilisateur :

    ////// Structure préventive //////
    while(cin.fail() || size > 10 || size < 2) { // La taille entrée ne peut être supérieure à 10 pour éviter les plateau trop grand.
        cout << endl;
        cout << "~ La saisie est incorrecte ~" << endl << endl;
        cout << "Entrez la taille du plateau de jeu (entre 2 et 10) : ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> size;
    }
    cout << endl;

    // Allocation de la mémoire :
    int t = (size * 2) - 1; // Taille du tableau en fonction de la taille du plateau.
    P = new Case *[t]; // Création d'un tableau à une dimension.
    for(int i = 0; i < t; i++) {
        P[i] = new Case[t]; // Allocation de la deuxième dimension du tableau P.
    }

    // Création du plateau de jeu :
    int m = (t / 2); // Milieu du plateau.

    for(int i = 0; i < t; i++) {
        for(int j = 0; j < t; j++) {
            if(i < m) {
                if(j < m - i) {
                    P[i][j].out();
                }
            }
            else if(j >= t - (i - m)) {
                P[i][j].out();
            }
        }
    }
}

Plateau::Plateau(int taille) { // Construit le plateau de jeu vide avec une taille déjà définie.
    // Allocation de la mémoire :
    size = taille;
    int t = (size * 2) - 1;
    P = new Case *[t];
    for(int i = 0; i < t; i++) {
        P[i] = new Case[t];
    }

    // Création du plateau de jeu :
    int m = (t / 2);

    for(int i = 0; i < t; i++) {
        for(int j = 0; j < t; j++) {
            if(i < m) {
                if(j < m - i) {
                    P[i][j].out();
                }
            }
            else if(j >= t - (i - m)) {
                P[i][j].out();
            }
        }
    }
}

Plateau::~Plateau() { // Destructeur de la classe "Plateau".
    /*int t = (size * 2) - 1;
    for(int i = 0; i < t; i++) {
        delete[] P[i];
    }
    delete [] P;*/
}

void Plateau::afficher() { // Affiche le plateau de jeu.
    int x = (size * 2) - 1;

    int m = (x / 2) - 1;

    string s = "                               ";
    int t = 0;

    for(int i = 0; i < x; i++) {
        cout << i << "  ";
        if(i > m) {
            if(i < 10) {
                cout << s.substr(0, t);
                t++;
            }
            else {
                cout << s.substr(0, t - 1);
                t++;
            }
        }
        for(int j = 0; j < x; j++) {
            if(!P[i][j].isOut()) {
                P[i][j].afficher();
            }
            cout << " ";
        }
    cout << endl;
    }
}

bool Plateau::vide() { // Test si le plateau est vide.
    int t = (size * 2) - 1;

    for(int i = 0; i < t; i++) {
        for(int j = 0; j < t; j++) {
            if(!P[i][j].vide()) {
                if(!P[i][j].isOut()) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Plateau::rempli() { // Test si le plateau est rempli.
    int t = (size * 2) - 1;

    for(int i = 0; i < t; i++) {
        for(int j = 0; j < t; j++) {
            if(!P[i][j].pleine()) {
                if(!P[i][j].isOut()) {
                    return false;
                }
            }
        }
    }
    return true;
}

Case *Plateau::voisinHautG(Case *c) { // Retourne le voisin haut gauche de la case donnée en argument.
    int m = (getsize() / 2) + 1; // Milieu du plateau de jeu.
    int t;
    if(c->x < m) {
        t = c->y + (m - c->x);
        if(c->x-1 >= 0) {
            return &P[c->x-1][t];
        }
    }
    if(c->x-1 >= 0) {
        return &P[c->x-1][c->y];
    }
    return &P[0][0]; // Permet de mettre à '8' les cases hors plateau.
}

Case *Plateau::voisinHautD(Case *c) { // Retourne le voisin haut droit de la case donnée en argument.
    int m = (getsize() / 2) + 1; // Milieu du plateau de jeu.
    int t;
    if(c->x < m) {
        t = c->y + (m - c->x);
        if(c->x-1 >= 0 && t+1 <= m*2) {
            return &P[c->x-1][t+1];
        }
    }
    if(c->x-1 >= 0 && c->y+1 <= m * 2) {
        return &P[c->x-1][c->y+1];
    }
    return &P[0][0]; // Permet de mettre à '8' les cases hors plateau.
}

Case *Plateau::voisinBasD(Case *c) { // Retourne le voisin bas droit de la case donnée en argument.
    int m = (getsize() / 2) + 1; // Milieu du plateau de jeu.
    int t;
    if(c->x < m) {
        t = c->y + (m - c->x);
        if(c->x+1 <= m * 2) {
            return &P[c->x+1][t];
        }
    }
    if(c->x+1 <= m * 2) {
        return &P[c->x+1][c->y];
    }
    return &P[0][0]; // Permet de retrouner à '8' les cases hors plateau.
}

Case *Plateau::voisinBasG(Case *c) { // Retourne le voisin bas gauche de la case donnée en argument.
    int m = (getsize() / 2) + 1; // Milieu du plateau de jeu.
    int t;
    if(c->x < m) {
        t = c->y + (m - c->x);
        if(c->x+1 <= m * 2 && t-1 >= 0) {
            return &P[c->x+1][t-1];
        }
    }
    if(c->x+1 <= m * 2 && c->y-1 >= 0) {
        return &P[c->x+1][c->y-1];
    }
    return &P[0][0]; // Permet de mettre à '8' les cases hors plateau.
}

Case *Plateau::voisinGauche(Case *c) { // Retourne le voisin gauche de la case donnée en argument.
    int m = (getsize() / 2) + 1; // Milieu du plateau de jeu.
    int t;
    if(c->x < m) {
        t = c->y + (m - c->x);
        if(t-1 >= 0) {
            return &P[c->x][t-1];
        }
    }
    if(c->y-1 >= 0) {
        return &P[c->x][c->y-1];
    }
    return &P[0][0]; // Permet de mettre à '8' les cases hors plateau.
}

Case *Plateau::voisinDroit(Case *c) { // Retourne le voisin droit de la case donnée en argument.
    int m = (getsize() / 2) + 1; // Milieu du plateau de jeu.
    int t;
    if(c->x < m) {
        t = c->y + (m - c->x);
        if(t+1 <= m * 2) {
            return &P[c->x][t+1];
        }
    }
    if(c->y+1 <= m * 2) {
        return &P[c->x][c->y+1];
    }
    return &P[0][0]; // Permet de mettre à '8' les cases hors plateau.
}

bool Plateau::coin(Case *c) { // Détecte si la case donnée en argument est sur un des coins du plateau.
    if(c->x == 0 && c->y == 0) {
        return true;
    }
    if(c->x == 0 && c->y == size - 1) {
        return true;
    }
    if(c->x == size - 1 && c->y == 0) {
        return true;
    }
    if(c->x == size - 1 && c->y == (size - 1) * 2) {
        return true;
    }
    if(c->x == (size - 1) * 2 && c->y == 0) {
        return true;
    }
    if(c->x == (size - 1) * 2 && c->y == size - 1) {
        return true;
    }
    return false;
}

int Plateau::nbVoisin(Case *c) { // Renvoi le nombre de voisins de la case donnée en argument.
    int count = 0;
    if(voisinBasD(c)->couleur == c->couleur) {
        count++;
    }
    if(voisinBasG(c)->couleur == c->couleur) {
        count++;
    }
    if(voisinHautG(c)->couleur == c->couleur) {
        count++;
    }
    if(voisinHautD(c)->couleur == c->couleur) {
        count++;
    }
    if(voisinGauche(c)->couleur == c->couleur) {
        count++;
    }
    if(voisinDroit(c)->couleur == c->couleur) {
        count++;
    }
    return count;
}

Case *Plateau::voisin(Case *c, int i) { // Renvoi le (ou les) voisins de la case donnée en arguement.
    switch(i) {
        case 0:
            if(voisinHautG(c)->couleur == c->couleur) {
                return voisinHautG(c);
            }
        case 1:
            if(voisinHautD(c)->couleur == c->couleur) {
                return voisinHautD(c);
            }
        case 2:
            if(voisinDroit(c)->couleur == c->couleur) {
                return voisinDroit(c);
            }
        case 3:
            if(voisinBasD(c)->couleur == c->couleur) {
                return voisinBasD(c);
            }
        case 4:
            if(voisinBasD(c)->couleur == c->couleur) {
                return voisinBasD(c);
            }
        case 5:
            if(voisinBasG(c)->couleur == c->couleur) {
                return voisinBasG(c);
            }
    }
    return c;
}

bool Plateau::haveVoisin(Case *c) { // Détecte si la case donnée en argument à un (ou plusieurs) voisin(s).
    if(voisinBasD(c)->couleur == c->couleur||voisinBasG(c)->couleur == c->couleur||voisinHautG(c)->couleur == c->couleur||voisinHautD(c)->couleur == c->couleur||voisinGauche(c)->couleur == c->couleur||voisinDroit(c)->couleur == c->couleur) {
        return true;
    }
    return false;
}
// "VISITE" modifie tout le fonctionnement du programme. Impossible de faire un chemin sans ça...
/*
bool Plateau::pont(Case *c) {
    if(haveVoisin(c)) {
        for(int i = 0; i < 6; i++) {
            if(voisin(c, i)->visite == false) {
                c->visite = true;
                if(coin(voisin(c, i)) && voisin(c, i)->visite == false && voisin(c, i) != c) {
                    return true;
                }
                pont(c);
            }
        }
    }
    return false;
}
*/
bool Plateau::bord(Case *c) { // Détecte si la case 'c' est sur un des bords du plateau.
    int m = (getsize() / 2) + 1;
    if(c->y == 0 && !coin(c)) {
        return true;
    }
    if(c->x == size * 2 - 2 && !coin(c)) {
        return true;
    }
    if(c->y == m - 1 || c->y == m+1) {
        return true;
    }
    return false;
}
