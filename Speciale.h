#ifndef SPECIALE_H_INCLUDED
#define SPECIALE_H_INCLUDED

#include "Carte.h"

class Speciale : public Carte
{
protected:
    bool m_isPermanant; ///si la carte est permanante alors son usage est permanant et elle ne meurt pas
    bool m_isRecyclable; ///si la carte est recyclable alors elle ne va pas dans le cimetière mais directement au fond du deck

public:
    ///constructeur et destructeur
    Speciale(std::string name, std::string description, std::string type, bool isPermanant, bool isRecyclable);//appelle le constructeur de Carte
    ~Speciale();

    ///getters
    bool getIsPermanant() const;
    bool getIsRecyclable() const;

    ///setters
    void setIsPermanant(bool isPermanant);
    void setIsRecyclable(bool isRecyclable);

    ///méthodes
};

///CLASSES DES CARTES DE TYPE SPECIALE, ELLES HERITENT TOUTES DE SPECIALE
///pour le moment on en a 6 comme dans le cdc
///ATTENTION : penser à remplacer plus tard les noms Spe(i) par les noms des cartes spéciales

class Kamikaze : public Speciale
{
private:
public:
    Kamikaze();
    ~Kamikaze();
};

class BoostVie : public Speciale
{
private:
public:
    BoostVie();
    ~BoostVie();
};

class BoostDef : public Speciale
{
private:
public:
    BoostDef();
    ~BoostDef();
};

class BoostAttaque : public Speciale
{
private:
public:
    BoostAttaque();
    ~BoostAttaque();
};

class Attaquex2 : public Speciale
{
private:
public:
    Attaquex2();
    ~Attaquex2();
};

class Renvoi : public Speciale
{
private:
public:
    Renvoi();
    ~Renvoi();
};

#endif // SPECIALE_H_INCLUDED
