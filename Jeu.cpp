#include "Jeu.h"
#include "Partie.h"

int fempty(char const *); // Prototype de la fonction vérifiant si le fichier est vide ou non.

Jeu::Jeu() { // Constructeur de la classe "Jeu".
    nbJoueursMax = 3; // 3 joueurs au maximum.

    cout << endl;
    cout << "Bienvenue dans le 'jeu vidéo' Havannah !" << endl << endl;

    char save = 'n';
    if(fempty("savefile.txt") == 0) { // Vérifie si le fichier de sauvegarde est vide ou non.
        cout << "Une ancienne sauvegarde a été détectée." << endl;
        cout << "Voulez vous charger cette partie (o/n) ? ";
        cin >> save;
    }

    ////// Structure préventive //////
    while(cin.fail() || (save != 'o' && save != 'O' && save != 'n' && save != 'N')) {
        cout << endl;
        cout << "~ La saisie est incorrecte ~" << endl;
        cout << endl;
        cout << "Voulez vous charger cette partie (o/n) ? ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> save;
    }

    if(save == 'o' || save == 'O') {
        int nombreJ;
        ifstream nbJ("nbjoueur.txt", ios::in);  // Ouverture du fichier de sauvegarde en lecture.
        if(nbJ) { // Si l'ouverture du fichier de sauvegarde a réussi.
            nbJ >> nombreJ;
        }
        else {
            cerr << "Le fichier de sauvegarde n'a pas pu s'ouvrir." << endl;
        }
        cout << endl;
        Partie *T = new Partie(nombreJ); // Création d'une nouvelle partie.
        T->charger(); // Charge la partie précédente.
    }
    else if(save == 'n' || save == 'N') { // Efface le contenu des différents fichiers de sauvegarde.
        // VIDE LE CONTENU DES FICHIERS DE SAUVEGARDE.
        ofstream s("savefile.txt", ios::out | ios::trunc);
        s.close();  // Fermeture du fichier de sauvegarde.
        ofstream n("nbjoueur.txt", ios::out | ios::trunc);
        n.close();  // Fermeture du fichier de sauvegarde.
        ofstream p("Tplateau.txt", ios::out | ios::trunc);
        p.close();  // Fermeture du fichier de sauvegarde.

        Partie P;
    }
}

int fempty(char const *fname) { // Vérifie si le fichier de sauvegarde est vide ou non.
	FILE *fdesc = fopen(fname, "r");
	int ret = 0;
	if(fdesc) {
		(void)fgetc(fdesc);
		if( feof(fdesc) ) {
			ret = 1;
		}
		fclose(fdesc);
	}
	return ret;
}
