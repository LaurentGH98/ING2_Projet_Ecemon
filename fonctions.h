#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#include <iostream>
#include "Carte.h"
#include "Joueur.h"
#include "Collection.h"
#include "Boutique.h"
#include "Creature.h"
#include "Energie.h"
#include "Speciale.h"
#include "Attaque.h"
#include "Defense.h"
#include <fstream>

void menu();

void afficherBoutique();

void creerJoueur(); //On saisit le nom du nouveau joueur et on décide de sa collection
                    //Dans un fichier portant le nom du joueur on écrit tous les noms de cartes de sa collec, mais
                    //ce ne sont que des strings à ce stade, les cartes ne sont pas encore crées
                    //L'écriture dans le fichier est trié en fonction du numéro de carte

bool isChoiceOk(int choix, Joueur* joueur); //Vérifie si le choix des cartes lors de la création du deck est ok
                                            //En d'autres termes vérifie si la carte choisie par l'utilisateur
                                            //est présente dans sa collection

void lancerPartie(Joueur* joueur); //simplement la création des collections et decks des 2 joueurs

void choixCarteEnjeu(Joueur* joueur);//choisit aléatoirement la carte enjeu dans la collection du joueur

void initaliserJoueur(Joueur* joueur); //initalise le joueur en début de partie
                                       //il a déja un nom, une collection et un deck, et une carte enjeu, il reste les autres attributs

void afficherTerrain(Joueur* joueur); //affichage pas très propre car on appelle 2 fois, 1 fois par joueur

void afficherTerrain(Joueur* joueur, Joueur* joueur2); //A FAIRE SI J'AI LE TEMPS : affiche les infos pour les 2 : plus propre

void defileJusquaCrea(Joueur* joueur); //permet de toujours avoir une créature sur le terrain (tant qu'il y en a dans le deck)

void afficherAttaquesDispo(Joueur* joueur); //affiche les attaques disponibles à chaque tour

bool verifAttaque(int choix, Joueur* joueur); //retourne un entier : 1 pour attaque ok, 2 pour attaque refusée, en fonction de l'attaque choisie

void tourDeJeu(Joueur* joueur, Joueur* joueurCible);   //on appelle le tourDeJeu pour le joueur1 puis pour le joueur2

void jouer(Joueur* joueur1, Joueur* joueur2); //on lance enfin le jeu !
                                              //on fait le tour par tour, on détermine le gagnat à la fin puis on gère la carte enjeu
                                              //les nouvelles collections mises à jour sont sauvegardées dans le fichier des 2 joueurs

void jouer(Joueur* joueur1); //fonction de test (un seul joueur donc plus rapide de lancer une partie)

void jouerCarteSpeciale(Joueur* joueur, Joueur* joueurCible, Carte* cartePiochee);//active l'effet d'une carte spéciale

#endif // FONCTIONS_H_INCLUDED
