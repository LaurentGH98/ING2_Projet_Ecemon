#include <iostream>
#include "Speciale.h"

///CLASSE SPECIALE
///CONSTRUCTEUR ET DESTRUCTEUR
Speciale::Speciale(std::string nom, std::string description, std::string type, bool isPermanant, bool isRecyclable) :
    Carte(nom, description, type), m_isPermanant(isPermanant), m_isRecyclable(isRecyclable)
{

}


Speciale::~Speciale()
{

}

///getters

bool Speciale::getIsPermanant() const
{
    return m_isPermanant;
}

bool Speciale::getIsRecyclable() const
{
    return m_isRecyclable;
}

///setters

void Speciale::setIsPermanant(bool isPermanant)
{
    m_isPermanant=isPermanant;
}

void Speciale::setIsRecyclable(bool isRecyclable)
{
    m_isRecyclable=isRecyclable;
}

///Méthodes



///CLASSES DE TOUTES LES CARTES SPECIALES
///constructeur et destructeur
Kamikaze::Kamikaze() :
    Speciale("Kamikaze",
             "Dernieres paroles : votre creature meurt instantanement mais inflige 10 points de degats a la creature adverse.", "Speciale", false, false)
{

}

Kamikaze::~Kamikaze()
{

}

BoostVie::BoostVie() :
    Speciale("BoostVie",
              "L ego de votre creature gonfle ! Elle gagne 5 points de vie. 1 seule utilisation.", "Speciale", false, true)
{

}

BoostVie::~BoostVie()
{

}

BoostDef::BoostDef() :
    Speciale("BoostDef",
              "Vos adherents vous soutiennent, la creature gagne 2 points de defense permanants", "Speciale", true, true)
{

}

BoostDef::~BoostDef()
{

}

BoostAttaque::BoostAttaque() :
    Speciale("BoostAttaque",
             "La repartie de votre creature devient inaretable ! Elle gagne 2 points de degats permanants sur ses attaques !",
             "Speciale", true, true)
{

}

BoostAttaque::~BoostAttaque()
{

}

Attaquex2::Attaquex2() :
    Speciale("Attaquex2",
             "Votre Creature coupe la parole a son adversaire ! Impoli peut etre mais efficace : elle attaque 2 fois ! 1 seule utilisation.",
             "Speciale", false, false)
{

}

Attaquex2::~Attaquex2()
{

}

Renvoi::Renvoi() :
    Speciale("Renvoi", "Vous devenez indifferent a la critique. Vous renvoyez les degats de votre adversaire !", "Speciale", false, true)
{

}

Renvoi::~Renvoi()
{

}
