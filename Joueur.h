#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include "Collection.h"
#include "Creature.h"

class Joueur
{
private :
    std::string m_nom;
    int m_vie;
    Collection* m_collec = new Collection;

    Carte* m_carteEnjeu; //enjeu de la partie
    Carte* m_creatureActive;
    int m_nbCreaturesDispo; //nombre de créatures dans le deck, puis -1 à chaque fois qu'une créature meurt.
    std::vector<Carte*> m_energiesActives; //On peut avoir plusieurs énergies actives sur le terrain
                                           //Elles disparaissent lorsqu'on attaque, avec une attaque qui les consomme
    Carte* m_specialeActive;

    std::vector<Carte*> m_graveyard;


    ///à voir si on utilise un booléen ou si on fait simplement if joueur.getHP()<0 le joueur est mort
    bool m_state; //true pour vivant false pour mort


public :
    ///Constructeur(s) et destructeur
    //Joueur(std::string nom);
    Joueur();
    ~Joueur();

    ///Getters
    std::string getNom() const;
    int getVie() const;
    bool getState() const;
    Collection* getClasseCollec() const; //ce getter retourne la classe Collection, qui contient la collection et le deck
    Carte* getCarteEnjeu() const;
    Carte* getCreatureActive() const;
    int getNbCreaturesDispo() const;
    std::vector<Carte*> getEnergiesActives() const;
    Carte* getSpecialeActive() const;
    std::vector<Carte*> getGraveyard() const;

    ///Setters
    void setNom(std::string nom);
    void setVie(int vie);
    void setState(bool state);
    void setClasseCollec(Collection* collec);
    void setCarteEnjeu(Carte* carteEnjeu);
    void setCreatureActive(Carte* creatureActive);
    void setNbCreaturesDispo(int nbCreaturesDispo);
    void setEnergiesActives(std::vector<Carte*> energiesActives);
    void setSpecialeActive(Carte* specialeActive);
    void setGraveyard(std::vector<Carte*> graveyard);

    ///METHODES :
    //void ChargerCollec();
    void clearEnergiesActives();
    void clearGraveyard();              //ces 2 clear permettent d'avoir un vecteur vide en début de partie

    void ajouterAuCimetiere(Carte* carteMorte);
    void ajouterAuxEnergiesActives (Carte* carteEnergie);

    void recevoirDegats(); //il prend des dégats dès que les pv de sa créature morte sont négatifs
};

#endif // JOUEUR_H_INCLUDED
