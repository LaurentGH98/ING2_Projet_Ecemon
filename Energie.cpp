#include <iostream>
#include "Energie.h"

///CLASSE ENERGIE
///CONSTRUCTEUR et DESTRUCTEUR
Energie::Energie(std::string nom, std::string description, std::string type, std::string typeEnergie) :
    Carte(nom, description, type), m_typeEnergie(typeEnergie)
{

}


Energie::~Energie()
{

}

///Getter(s)

std::string Energie::getTypeEnergie() const
{
    return m_typeEnergie;
}

///Setter(s)

void Energie::setTypeEnergie(std::string typeEnergie)
{
    m_typeEnergie=typeEnergie;
}

///Méthode(s)


///CLASSES DE TOUTES LES CARTES ENERGIE
///il y en a 5
///constructeurs et destructeurs
ExtremeGauche::ExtremeGauche() :
    Energie("Extreme Gauche", "Apporte un point d energie dans le domaine Extreme Gauche.", "Energie", "EG")
{

}

ExtremeGauche::~ExtremeGauche()
{

}

Gauche::Gauche() :
    Energie("Gauche", "Apporte un point d energie dans le domaine Gauche.", "Energie", "G")
{

}

Gauche::~Gauche()
{

}

Centre::Centre() :
    Energie("Centre", "Apporte un point d energie dans le domaine Centre.", "Energie", "C")
{

}

Centre::~Centre()
{

}

Droite::Droite() :
    Energie("Droite", "Apporte un point d energie dans le domaine Droite.", "Energie", "D")
{

}

Droite::~Droite()
{

}

ExtremeDroite::ExtremeDroite() :
    Energie("Extreme Droite", "Apporte un point d energie dans le domaine Extreme Droite.", "Energie", "ED")
{

}

ExtremeDroite::~ExtremeDroite()
{

}


