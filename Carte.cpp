#include <iostream>
#include "Carte.h"

///CONSTRUCTEUR et DESTRUCTEUR

//constructeur par défaut pour faire pointer une Carte sur une carte non initialisée
Carte::Carte()
{

}

//constructeur surchargé pour construire mes créatures, énergies et spéciales
Carte::Carte(std::string nom, std::string description, std::string type) : m_nom(nom), m_descrition(description), m_type(type)
{

}


Carte::~Carte()
{

}

///GETTERS

std::string Carte::getNom() const
{
    return m_nom;
}

std::string Carte::getDescription() const
{
    return m_descrition;
}

std::string Carte::getType() const
{
    return m_type;
}

//getters virtuels pour Créatures
int Carte::getVie() const
{
    //La méthode est vide car elle est virtuelle : c'est pas elle qui va être appelée, c'est le getVie() de Melenchon, Lepen etc
    //Cette méthode sert juste à pouvoir appeler le get vie d'une créature qui est déclarée comme une carte
}

int Carte::getDefense() const
{

}

int Carte::getPointsEnergieEG() const
{

}

int Carte::getPointsEnergieG() const
{

}

int Carte::getPointsEnergieC() const
{

}

int Carte::getPointsEnergieD() const
{

}

int Carte::getPointsEnergieED() const
{

}

Attaque* Carte::getAttaque1() const
{

}

Attaque* Carte::getAttaque2() const
{

}

Defense* Carte::getDefense1() const
{

}

bool Carte::getIsAttackBoosted() const {}
bool Carte::getIsAttackDoubled() const {}
bool Carte::getIsRenvoiActive() const {}

//getter virtuel pour Energies
std::string Carte::getTypeEnergie() const
{

}

//getters virtuels pour Spéciales
bool Carte::getIsPermanant() const
{

}

bool Carte::getIsRecyclable() const
{

}

///---------------------------------------------------------------------------------------------------------------------------

///SETTERS
void Carte::setNom(std::string nom)
{
    m_nom=nom;
}

void Carte::setDescription(std::string description)
{
    m_descrition=description;
}

void Carte::setType(std::string type)
{
    m_type=type;
}


//setters virtuels pour Créatures
void Carte::setVie(int vie)
{

}

void Carte::setDefense(int defense)
{

}

void Carte::setPointsEnergieEG(int pointsEnergieEG)
{

}

void Carte::setPointsEnergieG(int pointsEnergieG)
{

}

void Carte::setPointsEnergieC(int pointsEnergieC)
{

}

void Carte::setPointsEnergieD(int pointsEnergieD)
{

}

void Carte::setPointsEnergieED(int pointsEnergieED)
{

}

void Carte::setAttaque1(Attaque* attaque1)
{

}

void Carte::setAttaque2(Attaque* attaque2)
{

}

void Carte::setDefense1(Defense* defense1)
{

}

void Carte::setIsAttackBoosted(bool isAttackBoosted){}
void Carte::setIsAttackDoubled(bool isAttackDoubled){}
void Carte::setIsRenvoiActive(bool isRenvoiActive){}

//setter virtuel pour Energies
void Carte::setTypeEnergie(std::string typeEnergie)
{

}

//setters virtuels pour Spéciales
void Carte::setIsPermanant(bool isPermanant)
{

}

void Carte::setIsRecyclable(bool isRecyclable)
{

}

///METHODES
//méthodes virtuelles pour créatures

void Carte::attaquer(Carte* creatureCible, Attaque* attaqueChoisie)
{

}

void Carte::recevoirDegats(Attaque* attaque, Carte* creatureAttaquante)
{

}

void Carte::seDefendre(Defense* defense)
{

}
