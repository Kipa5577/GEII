#pragma once
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h> 
#include <time.h>


#pragma comment(lib,"Winmm.lib")
#pragma comment(lib,"winmm")


typedef struct {
	int m_int_nbrJoueurs;
	int m_int_lignes;
	int m_int_colonnes;
	bool m_bool_bot;
	int m_int_nivBot;
} Tparametre;


// 1 sans parametre sans valeur retourne
//1 parametre sans valeur retourne
//2 parametre entree et valeur retourne
//1 appelee par 1 autre fct

void Color(WORD x_word_attributes);						//change la couleure de la console


Tparametre menu(void);									//permet au joueur de rentrer les parametres de jeu
void gagne(int x_int_vinqueur);							//affiche x_int_vinqueur comme le vinqueur
void afficher(Tparametre xParametre);					//affiche la grille de jeu
void jouer(int x_int_joueur, Tparametre xParametre);	//permet au joueur x_int_joueur de jouer
int calculervinqueur(Tparametre xParametre);			//regarder si il y as un vinqueur et le retourne (retourne 0 si pas de vinqueur)
void reInit(void);										//reintialise le tableau de jeu


void Bot(int x_int_joueur, Tparametre xParametre);		//fait jouer le bot en temps que joueur x_int_joueur
void execo(void);										//affiche si une partie fini sans vinqueur
bool DemandeContinuer(void);							//permet de demander aux joueurs si on continue de jouer
bool tesEmplacement(int x_int_colonne);					//regarde si on peut jouer dans la colonne x_int_colonne
void calcul_bot(int x_int_niveauDificulte);				//fait les calculs d'analyse du bot
