#ifndef LABOUTIQUE_H_INCLUDED
#define LABOUTIQUE_H_INCLUDED
#include <vector>
#include <iostream>

#include "Carte.h"
#include "Joueur.h"

class Boutique
{
protected:
    Joueur* m_joueur; //utile pour la fonction acheterCarte
    std::vector<Carte*> m_listeDesCartes;
public:
     ///constructeur/destructeur
    Boutique();
    ~Boutique();

    ///Methode(s)
    void acheterCarte(std::string carte_btq,Joueur* joueur); //carte_btq correspond à carte boutique
};

#endif // LABOUTIQUE_H_INCLUDED
