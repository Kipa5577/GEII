//http://list.alwaysdata.net/Info1/GO.html 
#include "PrjInfo2022.h"


void main(void) {
	Tparametre parametre;
	bool l_bool_jouer = true;
	int l_int_joueur = 1;
	int l_int_vinqueur = 0;
	parametre = menu();
	reInit();
	while (l_bool_jouer){
		if (l_int_vinqueur != 0) {
			afficher(parametre);
			gagne(l_int_vinqueur);
			l_int_vinqueur = 0;
			l_bool_jouer = DemandeContinuer();
		}
		else{
			afficher(parametre);
			jouer(l_int_joueur, parametre);
			l_int_vinqueur=calculervinqueur(parametre);
		}
		l_int_joueur = (l_int_joueur % parametre.m_int_nbrJoueurs)+1;
	}
}