#include <iostream>
#include "Attaque.h"

///constructeur et destructeur

Attaque::Attaque(std::string nom, std::string description, int pointsDeDegats, int pointsEnergieRecquis, std::string typeEnergieRecquis) :
    m_nom(nom), m_description(description), m_pointsDeDegats(pointsDeDegats), m_pointsEnergieRecquis(pointsEnergieRecquis), m_typeEnergieRecquis(typeEnergieRecquis)
{

}

Attaque::~Attaque()
{

}

///getters
std::string Attaque::getNom() const
{
    return m_nom;
}

std::string Attaque::getDescription() const
{
    return m_description;
}

int Attaque::getPointsDeDegats() const
{
    return m_pointsDeDegats;
}

int Attaque::getPointsEnergieRecquis() const
{
    return m_pointsEnergieRecquis;
}

std::string Attaque::getTypeEnergieRecquis() const
{
    return m_typeEnergieRecquis;
}

///setters
void Attaque::setNom(std::string nom)
{
    m_nom=nom;
}

void Attaque::setDescription(std::string description)
{
    m_description=description;
}

void Attaque::setPointsDeDegats(int pointsDeDegats)
{
    m_pointsDeDegats=pointsDeDegats;
}

void Attaque::setPointsEnergieRecquis(int pointsEnergieRecquis)
{
    m_pointsEnergieRecquis=pointsEnergieRecquis;
}

void Attaque::setTypeEnergieRecquis(std::string typeEnergieRecquis)
{
    m_typeEnergieRecquis=typeEnergieRecquis;
}


///méthodes


