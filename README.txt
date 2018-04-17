Caractéristiques des classes :

Case : Coordonnées x et y / Couleur représentée un entier (0, 1, 2, 3 ou 8)

Plateau : Matrice (tableau de tableau) de case dont les cases hors plateau sont représentées par des ‘8’ / Taille paramétrable à travers l’interface grâce à un constructeur ou depuis le programme directement (mais décalage du numéro de la colonne pour plateaux de taille > 3). 

Joueur : Définit par sa couleur (1, 2 ou 3) et son nom qu’il doit renseigné en début de partie.

Partie : Définit par son nombre de joueurs (renseigné par l’utilisateur dans le constructeur de « Partie »).

Jeu : Définit par le nombre de joueurs maximum (= 3).

Fonctionnalités mises en place :

Case : 	void afficher(); -> Affiche la couleur d'une case.
        		void out(); -> Initialise la couleur de la case à 8 (hors plateau).
        		void J1(); -> Initialise la couleur de la case à 1 (joueur 1).
        		void J2(); -> Initialise la couleur de la case à 2 (joueur 2).
       		void J3(); -> Initialise la couleur de la case à 3 (joueur 3).
       	 	bool isOut(); -> Vérifie si la case est hors plateau (couleur = 8).
       	 	bool vide(); -> Vérifie si la case est vide (couleur = 0).
       	 	bool pleine(); // Vérifie si la case est remplie.

- Plateau : 	void afficher(); -> Affiche le plateau de jeu.
        		bool vide(); -> Détecte si le plateau de jeu est vide.
        		bool rempli(); -> Détecte si le plateau de jeu est rempli.
        		int getsize(); -> Récupère la taille du plateau de jeu.
        		Case **getP(); -> Récupère le tableau stockant le plateau de jeu.
        		Case *voisinHautD(Case *); -> Retourne le voisin haut droit de la case donnée.       		Case *voisinBasD(Case *); // Retourne le voisin bas droit de la case donnée.       			Case *voisinHautG(Case *); // Retourne le voisin haut gauche de la case donnée.       		Case *voisinBasG(Case *); // Retourne le voisin bas gauche de la case donnée.        		Case *voisinGauche(Case *); // Retourne le voisin gauche de la case donnée.        		Case *voisinDroit(Case *); // Retourne le voisin droit de la case donnée.
        		bool coin(Case *); // Détecte si la case donnée est sur un des coins du plateau.
        		int nbVoisin(Case *); // Renvoi le nombre de voisins de la case.        				Case *voisin(Case *, int); // Renvoi le (ou les) voisins de la case donnée.
        		bool haveVoisin(Case *); // Détecte si la case donnée à un (ou plusieurs) voisin(s).
        		// bool pont(Case *, int); // Condition de victoire du pont. Ne fonctionne pas.
        		bool bord(Case *); // Détecte si la case donnée est sur un des bords du plateau.

Jeu :		Jeu(); // Lance le jeu / Constructeur de la classe « Jeu ».

- Joueur : 	Joueur(); -> Contructeur de joueur - Créé un joueur avec des attributs vides.
       	 	void creerJ(int); -> Créé un nouveau joueur avec sa couleur en argument.

- Partie : 	Partie(); -> Constructeur de 'Partie' - Lance une nouvelle partie.
        		Partie(int); -> Constructeur de 'Partie' avec le nombre de joueurs en argument.
       		Case* tour(Plateau, Joueur, int &); -> Tour de jeu durant la partie.
        		void sauvegarde(Case *, Joueur, int); -> Sauvegarde une partie déjà commencée.
        		void charger(); -> Charge une partie stocké dans le fichier texte « savefile. txt».

-> Jouable jusqu’à trois joueurs.
-> Règle du gâteau mise en place également.
-> Gestion de la conformité des informations entrées par l’utilisateur (structures préventives).
-> Sauvegarde et chargement de partie implémentés.

Problèmes rencontrés :

Mise en place de la condition de victoire du pont. Bloqué la fin du développement du jeu.
Décallage du numéro de la colonne pour des plateaux dont la taille est supérieure à 3.