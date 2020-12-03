#include <iostream>
#include "Defense.h"

///constructeur et destructeur
Defense::Defense(std::string nom, std::string description, int pointsDeDefense, int pointsEnergieRecquis, std::string typeEnergieRecquis) :
    m_nom(nom), m_description(description), m_pointsDeDefense(pointsDeDefense), m_pointsEnergieRecquis(pointsEnergieRecquis), m_typeEnergieRecquis(typeEnergieRecquis)
{

}

Defense::~Defense()
{

}

///getters
std::string Defense::getNom() const
{
    return m_nom;
}

std::string Defense::getDescription() const
{
    return m_description;
}

int Defense::getPointsDeDefense() const
{
    return m_pointsDeDefense;
}

int Defense::getPointsEnergieRecquis() const
{
    return m_pointsEnergieRecquis;
}

std::string Defense::getTypeEnergieRecquis() const
{
    return m_typeEnergieRecquis;
}

///setters
void Defense::setNom(std::string nom)
{
    m_nom=nom;
}

void Defense::setDescription(std::string description)
{
    m_description=description;
}

void Defense::setPointsDeDefense(int pointsDeDefense)
{
    m_pointsDeDefense=pointsDeDefense;
}

void Defense::setPointsEnergieRecquis(int pointsEnergieRecquis)
{
    m_pointsEnergieRecquis=pointsEnergieRecquis;
}

void Defense::setTypeEnergieRecquis(std::string typeEnergieRecquis)
{
    m_typeEnergieRecquis=typeEnergieRecquis;
}

///méthodes
