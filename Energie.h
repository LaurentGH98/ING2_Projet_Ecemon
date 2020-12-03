#ifndef ENERGIE_H_INCLUDED
#define ENERGIE_H_INCLUDED

#include "Carte.h"

class Energie : public Carte
{
protected :
    std::string m_typeEnergie;

public :
    ///constructeur et destructeur
    Energie(std::string nom, std::string description, std::string type, std::string typeEnergie); //appelle le constructeur de Carte
    ~Energie();

    ///Getter(s)
    std::string getTypeEnergie() const;

    ///Setter(s)
    void setTypeEnergie(std::string typeEnergie);

    ///Méthode(s)

};

///CLASSES DES CARTES DE TYPE ENERGIE, ELLE HERITENT TOUTES DE ENERGIE
///énergie = domaine = parti politique dans ce jeu (ici 5 partis)

class ExtremeGauche : public Energie
{
private:
public:
    ExtremeGauche();
    ~ExtremeGauche();
};

class Gauche : public Energie
{
private:
public:
    Gauche();
    ~Gauche();
};

class Centre : public Energie
{
private:
public:
    Centre();
    ~Centre();
};

class Droite : public Energie
{
private:
public:
    Droite();
    ~Droite();
};

class ExtremeDroite : public Energie
{
private:
public:
    ExtremeDroite();
    ~ExtremeDroite();
};




#endif // ENERGIE_H_INCLUDED
