#include "PrjInfo2022.h"
#define NBR_LIGNES 55  //max 50  m_int_lignes
#define NBR_COLONNES 75 // max 100 m_int_colonnes


int l_tabInt_grille[NBR_LIGNES][NBR_COLONNES];
int iBcl, iBclX, iBclY;
int g_tabInt_valeurjoue[NBR_COLONNES],
g_tabInt_grilleAnalise[6][4];


void Color(WORD x_word_attributes) {    // fonction d'affichage de couleurs
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, x_word_attributes);
}


bool DemandeContinuer(void)
{
	bool l_bool_movaiseSaisie;
	Color(15);
	char l_char_saisie;
	bool l_bool_continuer = TRUE;
	do {
		printf("\t Voulez vous continuer? (Y/N) \n");

		l_char_saisie = getchar();
		while (getchar() != '\n');
		switch (l_char_saisie)//securise la saisie
		{
		case'N':
		case'n':
			l_bool_movaiseSaisie = FALSE;
			l_bool_continuer = FALSE;
			break;
		case'Y':
		case'y':
			l_bool_movaiseSaisie = FALSE;
			l_bool_continuer = TRUE;
			break;
		default:
			l_bool_movaiseSaisie = TRUE;
		}
		system("CLS");

	} while (l_bool_movaiseSaisie);
	return l_bool_continuer;
}


Tparametre menu(void)
{//	m_int_nbrJoueurs m_bool_bot
	Tparametre parametre;
	bool l_bool_movaiseSaisie;
	char l_char_saisie;
	/*
	do {

		PlaySoundA("Menu.wav", NULL, SND_ASYNC); // joue le ficher de persentation
		printf("Recommencer le message (Y ou y) ou lancer le programme (autre touche).\n");
		l_char_saisie = getchar();
		while (getchar() != '\n');//attrape le caractere \n pour que sa fonctionne correctement

	} while (l_char_saisie == 'Y' || l_char_saisie == 'y'); //permet de rejouer le fichier
	PlaySoundA(NULL, NULL, SND_PURGE);
	system("CLS");
	//+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
	//Menu Principal
	//*/

	do {

		printf("\t   Menu Principal \n");
		printf("\t N Pour le mode normal N\n");
		printf("\t C Pour le mode custom C \n");

		l_char_saisie = getchar();
		while (getchar() != '\n');
		switch (l_char_saisie)//securise la saisie
		{
		case'N':
		case'n':
			l_bool_movaiseSaisie = FALSE;
			break;
		case'C':
		case'c':
			l_bool_movaiseSaisie = FALSE;
			break;
		default:
			l_bool_movaiseSaisie = TRUE;
		}
		system("CLS");

	} while (l_bool_movaiseSaisie);

	//+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
	//Parametre des modes
	// l_char_saisie = 'N';
	if (l_char_saisie == 'N' || l_char_saisie == 'n') {

		do {
			printf("\t B pour jouer contre un bot B \n ");
			printf("\t J pour du joueur contre joueur J\n");
			l_char_saisie = getchar();
			while (getchar() != '\n');
			switch (l_char_saisie)//securise la saisie
			{
			case'B':
			case'b':
				l_bool_movaiseSaisie = true;
				do {
					system("CLS");
					parametre.m_bool_bot = TRUE;
					printf("\t choisir niveau de dificulte bot (1 ou 2)\n");
					l_char_saisie = getchar();
					while (getchar() != '\n');
					if (l_char_saisie == '1') {
						l_bool_movaiseSaisie = FALSE;
						parametre.m_int_nivBot = 1;
					}if (l_char_saisie == '2') {
						l_bool_movaiseSaisie = FALSE;
						parametre.m_int_nivBot = 2;
					}

				} while (l_bool_movaiseSaisie);
				break;
			case'J':
			case'j':
				l_bool_movaiseSaisie = FALSE;
				parametre.m_bool_bot = FALSE;
				break;
			default:
				l_bool_movaiseSaisie = TRUE;
			}

			system("CLS");
		} while (l_bool_movaiseSaisie);


		parametre.m_int_lignes = 7;
		parametre.m_int_colonnes = 8;
		parametre.m_int_nbrJoueurs = 2;

	}
	else {

		do {
			printf("Vous voulez jouer que avec des Bots ? (N ou O)");

			l_char_saisie = getchar();
			while (getchar() != '\n');
			switch (l_char_saisie)//securise la saisie
			{
			case'N':
			case'n':
				l_bool_movaiseSaisie = FALSE;
				parametre.m_bool_bot = FALSE;
				break;
			case'O':
			case'o':
				parametre.m_bool_bot = TRUE;
				l_bool_movaiseSaisie = true;
				do {
					system("CLS");
					parametre.m_bool_bot = TRUE;
					printf("\t choisir niveau de dificulte bot (1 ou 2)\n");
					l_char_saisie = getchar();
					while (getchar() != '\n');
					if (l_char_saisie == '1') {
						l_bool_movaiseSaisie = FALSE;
						parametre.m_int_nivBot = 1;
					}if (l_char_saisie == '2') {
						l_bool_movaiseSaisie = FALSE;
						parametre.m_int_nivBot = 2;
					}

				} while (l_bool_movaiseSaisie);
				break;
			default:
				l_bool_movaiseSaisie = TRUE;
			}
			system("CLS");
		} while (l_bool_movaiseSaisie);

		do {//securise la saisie

			printf("Vous voulez jouer a combien ?(2 a 15) \n");
			scanf_s("%i", &parametre.m_int_nbrJoueurs);
			parametre.m_int_nbrJoueurs = (int)parametre.m_int_nbrJoueurs;
			system("CLS");
		} while (parametre.m_int_nbrJoueurs < 2 || parametre.m_int_nbrJoueurs>15);

		do {//securise la saisie

			printf("Vous voulez jouer avec combien de lignes (0 < N <= 50)?\n");
			scanf_s("%i", &parametre.m_int_lignes);
			parametre.m_int_lignes = (int)parametre.m_int_lignes;
			while (getchar() != '\n');
			system("CLS");
		} while (parametre.m_int_lignes <= 0 || parametre.m_int_lignes > 50);


		do {//securise la saisie

			printf("Vous voulez jouer avec combien de colognnes (0 < N <= 70)?\n");
			scanf_s("%i", &parametre.m_int_colonnes);
			while (getchar() != '\n');
			system("CLS");
		} while (parametre.m_int_colonnes <= 0 || parametre.m_int_colonnes > 70);
	}
	return parametre;
}


void gagne(int x_int_vinqueur)
{
	//afficher vinqueur
	//demander si rejouer
	int l_int_vinqueur = x_int_vinqueur;
	Color(l_int_vinqueur);
	printf("bravo joueur %i, tu as gagne!!\n", l_int_vinqueur);
	Sleep(5000);
	reInit();



}


void execo(void)
{
	Color(15);
	printf("personne as gagne!!\n");
	Sleep(5000);
	reInit();

}


void afficher(Tparametre xParametre) { //affiche la grille avec les pions de la bonne couleur (noir si personne ne joue)
	// si on veut mettre un effet il faudras voir ou on as joue pour voir le pion tomber



	system("CLS");
	for (iBcl = 0; iBcl < xParametre.m_int_colonnes; iBcl++) {
		printf("%02i|", iBcl + 1);
	}
	printf("\n");
	for (iBclY = 0; iBclY != xParametre.m_int_lignes; iBclY++) {
		for (iBclX = 0; iBclX < xParametre.m_int_colonnes; iBclX++) {
			Color(l_tabInt_grille[iBclY][iBclX + 1]*16);
				printf("[]");
			Color(15);
			printf("|");

		}
		printf("\n");
	}

	Color(15);
	for (iBcl = 0; iBcl < xParametre.m_int_colonnes; iBcl++) {
		printf("%02i|", iBcl + 1);
	}
	printf("\n");
}


void jouer(int x_int_joueur, Tparametre xParametre) { //demander ou jouer et remplire le tableau
	//ou gerer le bot pour qu'il joue
	int l_int_joueur = x_int_joueur;
	int l_int_colonneJouee;
	if (xParametre.m_bool_bot && l_int_joueur != 1) {
		Bot(l_int_joueur, xParametre);
	}
	else
	{

		do {//demande la cologne au joueur
			afficher(xParametre);
			l_int_colonneJouee = 0;
			Color(l_int_joueur * 16);
			printf("[]");
			Color(15);
			printf("\tjoueur %i entrez une colone de jeu:\n", l_int_joueur);
			scanf_s("%i", &l_int_colonneJouee);
			while (getchar() != '\n');

			//*reinitialise si 100
			if (l_int_colonneJouee == 100)
			{
				reInit();
				l_int_joueur = 1;
				afficher(xParametre);
			}
			//*/
		} while (l_int_colonneJouee > xParametre.m_int_colonnes || l_int_colonneJouee == 0 || !tesEmplacement(l_int_colonneJouee)); //redemande tant que colone existe pas ou deja remplie


		for (iBcl = 1; (l_tabInt_grille[iBcl][l_int_colonneJouee] == 0) && (iBcl < xParametre.m_int_lignes); iBcl++);// detection ou chute le pion

		l_tabInt_grille[iBcl - 1][l_int_colonneJouee] = l_int_joueur;
	}

}


int calculervinqueur(Tparametre xParametre) { //voir si quelqu'un a gagne
	//Detection de alignement horizontal
	int l_int_valeurAvant;
	int l_int_meme = 0;
	int l_int_vinqueur = 0;
	for (iBclY = 0; iBclY <= xParametre.m_int_lignes; iBclY++)
	{
		for (iBclX = 0; iBclX <= xParametre.m_int_colonnes - 3; iBclX++)
		{
			l_int_meme = 0;
			for (iBcl = 0; iBcl < 4; iBcl++)
			{
				if (l_tabInt_grille[iBclY][iBclX] == l_tabInt_grille[iBclY][iBclX + iBcl] && l_tabInt_grille[iBclY][iBclX] != 0)
				{
					l_int_meme++;
				}
				if (l_int_meme == 4 && l_int_vinqueur == 0)
				{
					l_int_vinqueur = l_tabInt_grille[iBclY][iBclX];
				}
			}
		}
	}
	//verticale
	for (iBclY = 0; iBclY <= xParametre.m_int_lignes - 3; iBclY++)
	{
		for (iBclX = 0; iBclX <= xParametre.m_int_colonnes; iBclX++)
		{
			l_int_meme = 0;
			for (iBcl = 0; iBcl < 4; iBcl++)
			{
				if (l_tabInt_grille[iBclY][iBclX] == l_tabInt_grille[iBclY + iBcl][iBclX] && l_tabInt_grille[iBclY][iBclX] != 0)
				{
					l_int_meme++;
				}
				if (l_int_meme == 4 && l_int_vinqueur == 0)
				{
					l_int_vinqueur = l_tabInt_grille[iBclY][iBclX];
				}
			}
		}
	}

	//haut droit vers bas gauche
	for (iBclY = 0; iBclY <= xParametre.m_int_lignes - 3; iBclY++)
	{
		for (iBclX = 3; iBclX <= xParametre.m_int_colonnes; iBclX++)
		{
			l_int_meme = 0;
			for (iBcl = 0; iBcl < 4; iBcl++)
			{
				if (l_tabInt_grille[iBclY][iBclX] == l_tabInt_grille[iBclY + iBcl][iBclX - iBcl] && l_tabInt_grille[iBclY][iBclX] != 0)
				{
					l_int_meme++;
				}
				if (l_int_meme == 4 && l_int_vinqueur == 0)
				{
					l_int_vinqueur = l_tabInt_grille[iBclY][iBclX];
				}
			}
		}
	}
	//haut gauche vers bas droite
	for (iBclY = 0; iBclY <= xParametre.m_int_lignes - 3; iBclY++)
	{
		for (iBclX = 0; iBclX <= xParametre.m_int_colonnes - 3; iBclX++)
		{
			l_int_meme = 0;
			for (iBcl = 0; iBcl < 4; iBcl++)
			{
				if (l_tabInt_grille[iBclY][iBclX] == l_tabInt_grille[iBclY + iBcl][iBclX + iBcl] && l_tabInt_grille[iBclY][iBclX] != 0)
				{
					l_int_meme++;
				}
				if (l_int_meme == 4 && l_int_vinqueur == 0)
				{
					l_int_vinqueur = l_tabInt_grille[iBclY][iBclX];
				}
			}
		}
	}



	l_int_meme = 0;
	for (iBcl = 0; iBcl <= xParametre.m_int_colonnes; iBcl++)
	{
		if (!tesEmplacement(iBcl))
		{
			l_int_meme++;
		}
		if (l_int_meme >= xParametre.m_int_colonnes)
		{
			execo();
		}
	}
	return l_int_vinqueur;
}


void reInit(void) { //  re initialise le tableau
	for (int iBcl1 = 0; iBcl1 < NBR_LIGNES; iBcl1++)
	{
		for (int iBcl2 = 0; iBcl2 < NBR_COLONNES; iBcl2++)
		{
			l_tabInt_grille[iBcl1][iBcl2] = 0;
		}
	}
}


bool tesEmplacement(int x_int_colonne)
{
	bool l_bool_libre = FALSE;
	if (l_tabInt_grille[0][x_int_colonne] == 0)
	{
		l_bool_libre = TRUE;
	}

	return l_bool_libre;
}


void Bot(int x_int_joueur, Tparametre xParametre)
{
	//**
	int l_int_max = -200;
	int l_int_valjoue = 0;

	for (iBcl = 0; iBcl < NBR_COLONNES; iBcl++)
	{
		g_tabInt_valeurjoue[iBcl] = 0;
	}
	do{
				//parcour tout le tableau
		for (iBclX = 1; iBclX <= xParametre.m_int_colonnes; iBclX++) {
			for (iBclY = 1; iBclY <= xParametre.m_int_lignes; iBclY++) {


					//detection horizontale
					//*
				if (iBclX + 3 <= xParametre.m_int_colonnes) {

					for (iBcl = 0; iBcl < 4; iBcl++) {
						g_tabInt_grilleAnalise[0][iBcl] = iBclX + iBcl;
						for (int iBcl1 = 0; iBcl1 < 5; iBcl1++) {
							g_tabInt_grilleAnalise[iBcl1+1][iBcl] = l_tabInt_grille[iBclY + iBcl1][iBclX + iBcl];
						}
						if (iBclY == xParametre.m_int_lignes-1) {
							g_tabInt_grilleAnalise[2][iBcl] = -1;
						}
						if (iBclY == xParametre.m_int_lignes - 2) {
							g_tabInt_grilleAnalise[3][iBcl] = -1;
						}
						if (iBclY == xParametre.m_int_lignes - 3) {
							g_tabInt_grilleAnalise[2][iBcl] = -1;
						}
						if (iBclY == xParametre.m_int_lignes - 4) {
							g_tabInt_grilleAnalise[3][iBcl] = -1;
						}
					}

					calcul_bot(xParametre.m_int_nivBot);
				}

				// */

					//detection diago haut gauche vers bas droit

				if (iBclX + 3 <= xParametre.m_int_colonnes && iBclY + 4 <= xParametre.m_int_lignes) {
					for (iBcl = 0; iBcl < 4; iBcl++) {
						g_tabInt_grilleAnalise[0][iBcl] = iBclX + iBcl;
						for (int iBcl1 = 0; iBcl1 < 5; iBcl1++) {
							if (iBclY + iBcl1 + iBcl < xParametre.m_int_lignes) {
								g_tabInt_grilleAnalise[iBcl1 + 1][iBcl] = l_tabInt_grille[iBclY + iBcl1 + iBcl][iBclX + iBcl];
							}
							else {
								g_tabInt_grilleAnalise[iBcl1 + 1][iBcl] = -1;
							}
						}
					}
					calcul_bot(xParametre.m_int_nivBot);

				}

				//detection diago bas gauche vers haut droit
				if (iBclX + 3 <= xParametre.m_int_colonnes && iBclY  >= 4 && iBclY< xParametre.m_int_lignes) {
					for (iBcl = 0; iBcl < 4; iBcl++) {
						g_tabInt_grilleAnalise[0][iBcl] = iBclX + iBcl;
						for (int iBcl1 = 0; iBcl1 < 5; iBcl1++) {
							if (iBclY + iBcl1 - iBcl < xParametre.m_int_lignes) {
								g_tabInt_grilleAnalise[iBcl1 + 1][iBcl] = l_tabInt_grille[iBclY + iBcl1 - iBcl][iBclX + iBcl];
							}
							else {
								g_tabInt_grilleAnalise[iBcl1 + 1][iBcl] = -1;
							}
						}
					}
					calcul_bot(xParametre.m_int_nivBot);

				}

				//detection verticale
				if (l_tabInt_grille[iBclY][iBclX] == 0 && l_tabInt_grille[iBclY+1][iBclX] != 0) {
					if (l_tabInt_grille[iBclY + 1][iBclX] != l_tabInt_grille[iBclY + 2][iBclX]) {
						g_tabInt_valeurjoue[iBclX] += 5;
					}
					else if (l_tabInt_grille[iBclY + 2][iBclX] != l_tabInt_grille[iBclY + 3][iBclX]) {
						g_tabInt_valeurjoue[iBclX] += 20;
					}
					else {
						g_tabInt_valeurjoue[iBclX] += 250;
					}

				}
				// */

			}
		}




				//analyse du tableau d'analyse

		for (iBcl = 1; iBcl <= xParametre.m_int_colonnes; iBcl++){

			//printf(" %i ",g_tabInt_valeurjoue[iBcl]);
			if (l_int_max < g_tabInt_valeurjoue[iBcl] && tesEmplacement(iBcl)){
				l_int_max = g_tabInt_valeurjoue[iBcl];
				l_int_valjoue = iBcl;
			}
		}
		//Sleep(3000);



			if (l_int_valjoue == 0)    // ne sert que si lo bot commance
			{
				l_int_valjoue = rand() % xParametre.m_int_colonnes + 1;
			}



	} while (!(tesEmplacement(l_int_valjoue)) || l_int_valjoue == 0);






		for (iBcl = 0; (l_tabInt_grille[iBcl][l_int_valjoue] == 0) && (iBcl < xParametre.m_int_lignes); iBcl++);// detection ou chute le pion
		l_tabInt_grille[iBcl - 1][l_int_valjoue] = x_int_joueur;
		//*
	}


void calcul_bot(int x_int_niveauDificulte)
	{
		int l_int_valPrio = 0;
		int l_tabInt_testEgal[3] = { 0, 0, 0 };
		int l_int_compteur;

		for (iBcl = 0; iBcl < 4; iBcl++)
		{
			if (g_tabInt_grilleAnalise[1][iBcl] != 0)
			{
				l_int_valPrio++;
			}
		}
		if (l_int_valPrio == 4)
		{
			l_int_valPrio = 0;
		}
		l_int_valPrio *= l_int_valPrio;
		if (l_int_valPrio == 9) {
			l_int_valPrio = 50;
		}
		//prio vaut 1 pour 1 detecte
		//4 pour 2 detecte
		//9 pour 3 detecte
		//0 pour 4 detecte (si il y as 4 pions et pas gagn? alors ils sont dif)




		switch (l_int_valPrio)
		{
		case 4:
			l_int_compteur = 0;
			for (iBcl = 0; iBcl < 4; iBcl++)
			{
				if (g_tabInt_grilleAnalise[1][iBcl] != 0)
				{
					l_tabInt_testEgal[l_int_compteur] = g_tabInt_grilleAnalise[1][iBcl];
					l_int_compteur++;
				}
			}
			if (l_tabInt_testEgal[0] != l_tabInt_testEgal[1])
			{
				l_int_valPrio = 0;
			}


			break;
		case 9:
		case 19:
		case 50:
			l_int_compteur = 0;
			for (iBcl = 0; iBcl < 4; iBcl++)
			{
				if (g_tabInt_grilleAnalise[1][iBcl] != 0)
				{
					l_tabInt_testEgal[l_int_compteur] = g_tabInt_grilleAnalise[1][iBcl];
					l_int_compteur++;
				}
			}
			if (l_tabInt_testEgal[0] != l_tabInt_testEgal[1] || l_tabInt_testEgal[0] != l_tabInt_testEgal[2])
			{
				l_int_valPrio = 0;
			}
			break;
		}


		for (iBcl = 0; iBcl < 4; iBcl++)
		{
			if (g_tabInt_grilleAnalise[1][iBcl] == 0) {
				if (g_tabInt_grilleAnalise[2][iBcl] != 0){
					g_tabInt_valeurjoue[g_tabInt_grilleAnalise[0][iBcl]] += 5*l_int_valPrio;
				}
				else if (g_tabInt_grilleAnalise[3][iBcl] != 0 && x_int_niveauDificulte == 2){
					g_tabInt_valeurjoue[g_tabInt_grilleAnalise[0][iBcl]] -= 3*l_int_valPrio;
				}
				else if (g_tabInt_grilleAnalise[4][iBcl] != 0 && x_int_niveauDificulte == 2) {
					g_tabInt_valeurjoue[g_tabInt_grilleAnalise[0][iBcl]] += 2*l_int_valPrio;
				}
				else if (g_tabInt_grilleAnalise[5][iBcl] != 0 && x_int_niveauDificulte == 2) {
					g_tabInt_valeurjoue[g_tabInt_grilleAnalise[0][iBcl]] -= l_int_valPrio;
				}
			}
		}

		for (int iBcl1 = 0; iBcl1 < 6; iBcl1++) {
			for (iBcl = 0; iBcl < 4; iBcl++) {
				g_tabInt_grilleAnalise[iBcl1][iBcl] = 0;
			}
		}
	}
