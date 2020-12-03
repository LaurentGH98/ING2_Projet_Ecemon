#include <iostream>
#include "Joueur.h"
#include <vector>
#include <sstream>

///CONSTRUCTEUR(S) et DESTRUCTEUR

Joueur::Joueur() : m_nom("pas de nom")
{

}

Joueur::~Joueur()
{

}

///GETTERS

std::string Joueur::getNom() const
{
    return m_nom;
}

int Joueur::getVie() const
{
    return m_vie;
}

bool Joueur::getState() const
{
    return m_state;
}

Collection* Joueur::getClasseCollec() const
{
    return m_collec;
}

Carte* Joueur::getCarteEnjeu() const
{
    return m_carteEnjeu;
}

Carte* Joueur::getCreatureActive() const
{
    return m_creatureActive;
}

int Joueur::getNbCreaturesDispo() const
{
    return m_nbCreaturesDispo;
}

std::vector<Carte*> Joueur::getEnergiesActives() const
{
    return m_energiesActives;
}

Carte* Joueur::getSpecialeActive() const
{
    return m_specialeActive;
}

std::vector<Carte*> Joueur::getGraveyard() const
{
    return m_graveyard;
}

///SETTERS

void Joueur::setNom(std::string nom)
{
    m_nom=nom;
}

void Joueur::setVie(int vie)
{
    m_vie=vie;
}

void Joueur::setState(bool state)
{
    m_state=state;
}

void Joueur::setClasseCollec(Collection* collec)
{
    m_collec=collec;
}

void Joueur::setCarteEnjeu(Carte* carteEnjeu)
{
    m_carteEnjeu=carteEnjeu;
}

void Joueur::setCreatureActive(Carte* creatureActive)
{
    m_creatureActive=creatureActive;
}

void Joueur::setNbCreaturesDispo(int nbCreaturesDispo)
{
    m_nbCreaturesDispo=nbCreaturesDispo;
}

void Joueur::setEnergiesActives(std::vector<Carte*> energiesActives)
{
    m_energiesActives=energiesActives;
}

void Joueur::setSpecialeActive(Carte* specialActive)
{
    m_specialeActive=specialActive;
}

void Joueur::setGraveyard(std::vector<Carte*> graveyard)
{
    m_graveyard=graveyard;
}

///METHODES

void Joueur::clearGraveyard()
{
    m_graveyard.clear();
}

void Joueur::clearEnergiesActives()
{
    m_energiesActives.clear();
}

void Joueur::ajouterAuCimetiere(Carte* carteMorte)
{
    m_graveyard.push_back(carteMorte);
}

void Joueur::ajouterAuxEnergiesActives(Carte* carteEnergie)
{
    m_energiesActives.push_back(carteEnergie);
}

void Joueur::recevoirDegats()
{
    if (this->getCreatureActive()->getVie() <= 0)
    {
        this->setVie(this->getVie() + this->getCreatureActive()->getVie()); //on additionne aux pv du joueur les pv négatifs
                                                                            //sa créature (donc ils diminuent...)
                                                                            //évidemment si sa créature a 0 pv il ne perd rien
    }
}
