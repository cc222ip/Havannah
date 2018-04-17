#include "Partie.h"

Partie::Partie(int n) { // Constructeur de la classe "Partie" avec le nombre de joueurs en argument.
    nbJoueurs = n;
}

Partie::Partie() { // Constructeur de la classe "Partie".
    //CARACTÉRISTIQUES DE LA PARTIE :

    // Nombre de joueurs :
    cout << "Entrez le nombre de joueurs (compris entre 1 et 3) : ";
    cin >> nbJoueurs;

    ////// Structure préventive //////
    while(cin.fail() || nbJoueurs <= 0 || nbJoueurs > 3) {
        cout << endl;
        cout << "~ La saisie est incorrecte ~" << endl << endl;
        cout << "Entrez le nombre de joueurs (compris entre 1 et 3) : ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> nbJoueurs;
    }
    cout << endl;

    // Sauvegarde du nombre de joueurs de la partie dans un fichier texte.
    ofstream nbJ("nbjoueur.txt", ios::out | ios::app);  // Ouverture du fichier en écriture.
    if(nbJ) { // Si l'ouverture du fichier a réussi.
        nbJ << nbJoueurs;
        nbJ.close();  // Fermeture du fichier.
    }
    else  {
        cerr << "Le fichier de sauvegarde n'a pas pu s'ouvrir." << endl;
    }

    // Création des joueurs :
    Joueur j1; // On créé 3 joueurs même si la partie se déroule à 1 ou 2 joueurs.
    Joueur j2; // Les joueurs ont des attributs vides à ce niveau.
    Joueur j3;
    cout << "Création du joueur 1 (Jouera en premier) :" << endl;
    j1.creerJ(1); // Renseigne les attributs du joueur 1 quoi qu'il arrive.

    if(nbJoueurs > 1) { // Partie à 2 joueurs ou plus.
        cout << "Création du joueur 2 (Jouera en second) :" << endl;
        j2.creerJ(2); // Renseigne les attributs du joueur 2.

        if(nbJoueurs == 3) { // Partie à 3 joueurs.
            cout << "Création du joueur 3 (Jouera en dernier) :" << endl;
            j3.creerJ(3); // Renseigne les attributs du joueur 3.
        }
    }

    int tailleP = 6;
    Plateau P(tailleP); // Création du plateau de jeu - Plateau étroit pour faciliter le développement du jeu.

    ofstream size("Tplateau.txt", ios::out | ios::app);  //Ouverture du fichier de sauvegarde en écriture.
    if(size) { // Si l'ouverture du fichier a réussi.
        size << tailleP;
        size.close();  // Fermeture du fichier de sauvegarde.
    }
    else  {
        cerr << "Le fichier de sauvegarde n'a pas pu s'ouvrir." << endl;
    }

    // LA PARTIE COMMENCE VRAIMENT :

    cout << "La partie commence !" << endl << endl;
    P.afficher(); // Affichage du plateau de jeu.
    cout << endl;

    Case *T;
    Joueur tmp;

    int c = 1; // Compteur de tour.
    while(!P.rempli()) { // En attente des conditions de victoire.
        tour(P, j1, c); // Tour du joueur 1.
        if(nbJoueurs > 1) { // Si il y a plus d'un joueur.
            T = tour(P, j2, c); // Tour du joueur 2.
            if(T == NULL && c == 3) { // Si la règle du gateau est demandée.
                tmp = j1; // Échange du joueur 1 et 2.
                j1 = j2;
                j2 = tmp;
                int tmp2 = j1.couleur;
                j1.couleur = j2.couleur;
                j2.couleur = tmp2;
                cout << "~ "<< j1.nom << " joue désormais la couleur " << j1.couleur << " ~" << endl;
                cout << "~ "<< j2.nom << " joue désormais la couleur " << j2.couleur << " ~" << endl << endl;
                if(nbJoueurs == 2) { // Si il y a 2 joueurs.
                    tour(P, j2, c); // Tour du joueur 2.
                }
            }
            if(nbJoueurs == 3) { // Si il y a 3 joueurs.
                tour(P, j3, c); // Tour du joueur 3.
            }
        }
    }
    // VIDE LE CONTENU DES FICHIERS DE SAUVEGARDE.
    ofstream s("savefile.txt", ios::out | ios::trunc);  // Ouverture du fichier de sauvegarde en écriture.
    s.close();  // Fermeture du fichier de sauvegarde.
    ofstream n("nbjoueur.txt", ios::out | ios::trunc);  // Ouverture du fichier de sauvegarde en écriture.
    n.close();  // Fermeture du fichier de sauvegarde.
    ofstream p("Tplateau.txt", ios::out | ios::trunc);  // Ouverture du fichier de sauvegarde en écriture.
    p.close();  // Fermeture du fichier de sauvegarde.
    cout << "La partie est terminée." << endl;
}

Case *Partie::tour(Plateau P, Joueur j, int &count) { // Tour du joueur renseigné en attribut - Retourne la case sélectionné par le joueur.

    // INITIALISATION DES VARIABLES :

    Case *C = new Case(); // Variable stockant l'adresse de la case choisie par le joueur.
    int tailleP = (P.getsize() * 2) - 1; // Taille du plateau de jeu.
    int ligne; // Variable stockant la ligne choisie par le joueur du tour.
    int colonne; // Variable stockant la colonne choisie par le joueur du tour.
    int gateau = 1; // Variable stockant la décision prise par le joueur 2 pour la règle du gâteau.

    cout << "Tour de " << j.nom << " (Tour n°" << count << ") : " << endl;

    // RÈGLE DU GÂTEAU :

    if(count == 2 && j.couleur == 2) { // Si c'est le premier tour du joueur 2 :
        cout << "~ Selon la règle du gâteau, vous pouvez choisir de poursuivre en tant que second joueur ou de passer premier ~" << endl << endl;
        cout << "Quel est votre choix (1 - Je reste second / 2 - Je passe premier) ? ";
        cin >> gateau;
        cout << endl;

        ////// Structure préventive //////
        while(cin.fail() || (gateau != 1 && gateau != 2)) {
            cout << endl;
            cout << "~ La saisie est incorrecte ~" << endl << endl;
            cout << "Quel est votre choix (1 - Je reste second / 2 - Je passe premier) ? ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> gateau;
        }
    }
    if(gateau == 2) { // Si la règle du gâteau est demandée.
        count++;
        return NULL;
    }
    cout << endl;

    // SAISIE DU NUMÉRO DE LIGNE :

    cout << "Entrez un numéro de ligne : ";
    cin >> ligne;

    ////// Structure préventive //////
    while(cin.fail() || ligne >= tailleP || ligne < 0) {
        cout << endl;
        cout << "~ La saisie est incorrecte ~" << endl;
        cout << endl;
        cout << "Entrez un numéro de ligne : ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> ligne;
    }

    // SAISIE DU NUMÉRO DE COLONNE :

    cout << "Entrez un numéro de colonne : ";
    cin >> colonne;
    int m = (P.getsize() / 2) + 1; // Milieu du plateau de jeu (lignes / 2).
    if(ligne < m) { // Permet d'accéder à la première colonne de chaque ligne en demandant la colonne '0'.
        colonne = colonne + (m - ligne);
    }

    ////// Structure préventive //////
    while(cin.fail() || colonne >= tailleP || ligne < 0) {
        cout << endl;
        cout << "~ La saisie est incorrecte ~" << endl;
        cout << endl;
        cout << "Entrez un numéro de colonne : ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> colonne;
    }


    // VÉRICATION DE LA CONFORMITÉ DE LA CASE CHOISIE :
    ////// Structure préventive //////
    while(cin.fail() || P.getP()[ligne][colonne].isOut() || P.getP()[ligne][colonne].pleine()) {
        cout << endl;
        cout << "~ La case saisie saisie est invalide ~" << endl;
        cout << endl;
        cin.clear();
        cin.ignore(256, '\n');

        // SAISIE DU NUMÉRO DE LIGNE :

        cout << "Entrez un numéro de ligne : ";
        cin >> ligne;

        ////// Structure préventive //////
        while(cin.fail() || ligne >= tailleP || ligne < 0) {
            cout << endl;
            cout << "~ La saisie est incorrecte ~" << endl;
            cout << endl;
            cout << "Entrez un numéro de ligne : ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> ligne;
        }

        // SAISIE DU NUMÉRO DE COLONNE :

        cout << "Entrez un numéro de colonne : ";
        cin >> colonne;
        if(ligne < m) { // Permet d'accéder à la première colonne de chaque ligne en demandant la colonne '0'.
            colonne = colonne + (m - ligne);
        }

        ////// Structure préventive //////
        while(cin.fail() || colonne >= tailleP || ligne < 0) {
            cout << endl;
            cout << "~ La saisie est incorrecte ~" << endl;
            cout << endl;
            cout << "Entrez un numéro de colonne : ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> colonne;
        }
    }

    if(j.couleur == 1) { // Tour du joueur 1.
        P.getP()[ligne][colonne].J1(); // Placement du jeton.
    }
    else if(j.couleur == 2) { // Tour du joueur 2.
        P.getP()[ligne][colonne].J2(); // Placement du jeton.
    }
    else if(j.couleur == 3) { // Tour du joueur 3.
        P.getP()[ligne][colonne].J3(); // Placement du jeton.
    }
    C = &P.getP()[ligne][colonne]; // Stockage de l'adresse de la case choisie dans la variable C.
    C->x = ligne;
    if(C->x < m) {
        C->y = colonne - (m - ligne);
    }
    else {
        C->y = colonne;
    }

    P.afficher(); // Affichage du plateau de jeu après placement.
    cout << endl;

    /*if(P.pont(C) == true) {
        cout << j.nom << " remporte la partie par la méthode du pont !" << endl;
        exit(EXIT_SUCCESS);
    }*/

    count++; // Incrémentation du compteur de tour.
    sauvegarde(C, j, count);
    return C; // Retourne l'adresse de la case chosie.
}

void Partie::sauvegarde(Case *C, Joueur j, int c) { // Sauvegarde une partie déjà commencée.
    ofstream save("savefile.txt", ios::out | ios::app);  //Ouverture du fichier de sauvegarde en écriture.

    if(save) { // Si l'ouverture du fichier a réussi.
        save << '\n' << j.couleur << " " << j.nom << " " << c << " " << C->x << " " << C->y;
        save.close();  // Fermeture du fichier de sauvegarde.
    }
    else  {
        cerr << "Le fichier de sauvegarde n'a pas pu s'ouvrir." << endl;
    }
}

void Partie::charger() { // Charge une partie stocké dans le fichier texte "savefile".
    // CHARGEMENT DES DONNÉES DE LA PARTIE :
    int taillePlateau;
    ifstream size("Tplateau.txt", ios::in);  // Ouverture du fichier de sauvegarde en lecture.
    if(size) { // Si l'ouverture du fichier de sauvegarde a réussi.
        size >> taillePlateau; // Récupère la taille du plateau de jeu.
    }
    else {
        cerr << "Le fichier de sauvegarde n'a pas pu s'ouvrir." << endl;
    }
    Plateau P(taillePlateau);

    Joueur j1, j2, j3; // Création de 3 joueurs.
    string ligne, name;
    int m = (P.getsize() / 2) + 1; // Milieu du plateau de jeu (lignes / 2).
    int numJ, c, x, y; // Compteur de tour et coordonées de case.
    ifstream save("savefile.txt", ios::in);  // Ouverture du fichier de sauvegarde en lecture.
    if(save) { // Si l'ouverture du fichier de sauvegarde a réussi.
        while(getline(save, ligne)) {
            save >> numJ >> name >> c >> x >> y;
            if(x < m) {
                y = y + (m - x);
            }
            if(numJ == 1) {
                j1.nom = name;
                j1.couleur = numJ;
                P.getP()[x][y].J1();
            }
            else if(numJ == 2) {
                j2.nom = name;
                j2.couleur = numJ;
                P.getP()[x][y].J2();
            }
            else if(numJ == 3) {
                j3.nom = name;
                j3.couleur = numJ;
                P.getP()[x][y].J3();
            }
        }
    }
    else {
        cerr << "Le fichier de sauvegarde n'a pas pu s'ouvrir." << endl;
    }
    save.close();  // Fermeture du fichier.

    // REPRISE DE LA PARTIE :
    cout << "La partie reprend !" << endl << endl;
    P.afficher(); // Affichage du plateau de jeu.
    cout << endl;

    // REPRISE DES TOURS :
    Case * T;
    if(numJ == 1) { // Si le joueur 1 était le dernier à jouer.
        while(!P.rempli()) { // En attente des conditions de victoire.
            if(nbJoueurs > 1) { // Si il y a plus d'un joueur.
                T = tour(P, j2, c); // Tour du joueur 2.
                if(T == NULL && c == 3) { // Si la règle du gateau est demandée.
                    Joueur tmp = j1; // Échange du joueur 1 et 2.
                    j1 = j2;
                    j2 = tmp;
                    int tmp2 = j1.couleur;
                    j1.couleur = j2.couleur;
                    j2.couleur = tmp2;
                    cout << "~ "<< j1.nom << " joue désormais la couleur " << j1.couleur << " ~" << endl;
                    cout << "~ "<< j2.nom << " joue désormais la couleur " << j2.couleur << " ~" << endl << endl;
                    if(nbJoueurs == 2) { // Si il y a 2 joueurs.
                        tour(P, j2, c); // Tour du joueur 2.
                    }
                }
                if(nbJoueurs == 3) { // Si il y a 3 joueurs.
                    tour(P, j3, c); // Tour du joueur 3.
                }
            }
            tour(P, j1, c); // Tour du joueur 1.
        }
    }

    if(numJ == 2) { // Si le joueur 2 était le dernier à jouer.
        while(!P.rempli()) { // En attente des conditions de victoire.
            if(nbJoueurs == 3) { // Si il y a 3 joueurs.
                tour(P, j3, c); // Tour du joueur 3.
            }
            tour(P, j1, c); // Tour du joueur 1.
            tour(P, j2, c); // Tour du joueur 2.
        }
    }

    if(numJ == 3) { // Si le joueur 3 était le dernier à jouer.
        while(!P.rempli()) { // En attente des conditions de victoire.
            tour(P, j1, c); // Tour du joueur 1.
            tour(P, j2, c); // Tour du joueur 2.
            tour(P, j3, c); // Tour du joueur 3.
        }
    }
}
