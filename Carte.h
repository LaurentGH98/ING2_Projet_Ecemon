#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED

#include "Attaque.h"
#include "Defense.h"

class Carte
{
protected : //protected car Carte est la classe m�re des Creatures, Energies et Speciales
    std::string m_nom;
    std::string m_descrition;
    std::string m_type; //Cr�ature Energie ou Sp�ciale

public :
    ///Constructeurs et Destructeur
    Carte();
    Carte(std::string nom, std::string description, std::string type);
    ~Carte();

    ///Getters
    std::string getNom() const;
    std::string getDescription() const;
    std::string getType() const;

    //getters virtuels pour Cr�atures
    virtual int getVie() const;
    virtual int getDefense() const;
    virtual int getPointsEnergieEG() const;
    virtual int getPointsEnergieG() const;
    virtual int getPointsEnergieC() const;
    virtual int getPointsEnergieD() const;
    virtual int getPointsEnergieED() const;

    virtual Attaque* getAttaque1() const;
    virtual Attaque* getAttaque2() const;

    virtual Defense* getDefense1() const;

    //getter virtuel pour Energies
    virtual std::string getTypeEnergie() const;

    //getters virtuels pour Sp�ciales
    virtual bool getIsPermanant() const;
    virtual bool getIsRecyclable() const;


    ///Setters
    void setNom(std::string nom);
    void setDescription(std::string description);
    void setType(std::string type);

    //setters virtuels pour Cr�atures
    virtual void setVie (int vie);
    virtual void setDefense(int defense);
    virtual void setPointsEnergieEG(int pointsEnergieEG);
    virtual void setPointsEnergieG(int pointsEnergieG);
    virtual void setPointsEnergieC(int pointsEnergieC);
    virtual void setPointsEnergieD(int pointsEnergieD);
    virtual void setPointsEnergieED(int pointsEnergieED);

    virtual void setAttaque1(Attaque* attaque1);
    virtual void setAttaque2(Attaque* attaque2);

    virtual void setDefense1(Defense* defense1);

    //setter virtuel pour Energies
    virtual void setTypeEnergie(std::string typeEnergie);

    //setters virtuels pour Sp�ciales
    virtual void setIsPermanant(bool isPermanant);
    virtual void setIsRecyclable(bool isRecyclable);

    ///METHODES
    ///m�thodes virtuelles pour cr�atures
    virtual void attaquer(Carte* creatureCible, Attaque* attaqueChoisie); //La cr�ature attaque la cr�ature cible de l'adversaire avec
                                                                          //une attaque choisie : la cible perd des points de vie

    virtual void recevoirDegats(Attaque* attaque); //pour que la cr�ature cible perde des points de vie

    //Si la cr�ature inflige des d�g�ts � la cr�ature cible sup�rieurs � ses points de vie restants, les pv du joueur adverse diminuent
    //Dans ce cas on mettra dans le tour de jeu : si getPV(creatureCible)<0, on appelle joueurAdverse->recevoirDegats

    virtual void seDefendre(Defense* defense);
};

#endif // CARTE_H_INCLUDED
