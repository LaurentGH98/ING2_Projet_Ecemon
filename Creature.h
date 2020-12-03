#ifndef CREATURE_H_INCLUDED
#define CREATURE_H_INCLUDED

#include "Carte.h"
#include "Attaque.h"
#include "Defense.h"

class Creature : public Carte
{
protected:
    int m_vie;
    int m_defense; //augment� par l'action de se defendre de la cr�ature, PUIS on fait degats_recus = degatsAttaque - m_defense

    //utile pour les points d'�nergie recquis par les attaques
    int m_pointsEnergieEG; //extr�me gauche
    int m_pointsEnergieG; //gauche
    int m_pointsEnergieC; //centre
    int m_pointsEnergieD; //droite
    int m_pointsEnergieED; //extr�me droite

    Attaque* m_attaque1;
    Attaque* m_attaque2;

    Defense* m_defense1; //la cr�ature peut lancer une defense, ce qui augmentera l'entier m_defense

    ///Les attributs pour les cartes sp�ciales
    bool m_isAttackBoosted;
    bool m_isAttackDoubled;
    bool m_isRenvoiActive;

public :
    ///constructeurs et destructeur
    Creature();
    Creature(std::string nom, std::string description, std::string type, int vie, int defense, int pointsEnergieEG, int pointsEnergieG, int pointsEnergieC, int pointsEnergieD, int pointsEnergieED, Attaque* attaque1, Attaque* attaque2, Defense* defense1);
    ~Creature();

    ///Getters
    int getVie() const;
    int getDefense() const;
    int getPointsEnergieEG() const;
    int getPointsEnergieG() const;
    int getPointsEnergieC() const;
    int getPointsEnergieD() const;
    int getPointsEnergieED() const;

    Attaque* getAttaque1() const;
    Attaque* getAttaque2() const;

    Defense* getDefense1() const;

    ///Setters pour les boost de cartes sp�ciales
    bool getIsAttackBoosted() const;
    bool getIsAttackDoubled() const;
    bool getIsRenvoiActive() const;

    ///Setters
    void setVie (int vie);
    void setDefense (int defense);
    void setPointsEnergieEG (int pointsEnergieEG);
    void setPointsEnergieG(int pointsEnergieG);
    void setPointsEnergieC(int pointsEnergieC);
    void setPointsEnergieD(int pointsEnergieD);
    void setPointsEnergieED(int pointsEnergieED);

    void setAttaque1(Attaque* attaque1);
    void setAttaque2(Attaque* attaque2);

    void setDefense1(Defense* defense1);

    ///Setters pour les boost de cartes sp�ciales
    void setIsAttackBoosted(bool isAttackBoosted);
    void setIsAttackDoubled(bool isAttackDoubled);
    void setIsRenvoiActive(bool isRenvoiActive);

    ///m�thodes
    //Pour les m�thodes, ce n'est la peine de remettre le nom des m�thodes de la classe m�re (Carte) que si on les modifie

    void attaquer(Carte* creatureCible, Attaque* attaqueChoisie); //La cr�ature attaque la cr�ature cible de l'adversaire avec
                                                                  //une attaque choisie : la cible perd des points de vie

    void recevoirDegats(Attaque* attaque, Carte* creatureAttaquante); //pour que la cr�ature cible perde des points de vie

    //Si la cr�ature inflige des d�g�ts � la cr�ature cible sup�rieurs � ses points de vie restants, les pv du joueur adverse diminuent
    //Dans ce cas on mettra dans le tour de jeu : si getPV(creatureCible)<0, on appelle joueurAdverse->recevoirDegats

    void seDefendre(Defense* defense);
};

///CLASSES DE TOUTES LES CARTES CREATURES, ELLES HERITENT TOUTES DE CREATURE
///on verra plus tard si on les utilise toutes lors d'une vraie partie
class Melenchon : public Creature
{
 private:
 public:
    Melenchon();
    ~Melenchon();
};

class Marchais :public Creature
{
private:
public:
    Marchais();
    ~Marchais();
};

class Hamon : public Creature
{
private:
public:
    Hamon();
    ~Hamon();
};

class Hollande : public Creature
{
private:
public:
    Hollande();
    ~Hollande();
};

class Macron : public Creature
{
private :
public:
    Macron();
    ~Macron();
};

class Lassalle : public Creature
{
private:
public:
    Lassalle();
    ~Lassalle();
};

class Fillon : public Creature
{
private:
public:
    Fillon();
    ~Fillon();
};

class Sarkozy : public Creature
{
private:
public:
    Sarkozy();
    ~Sarkozy();
};

class JMLepen : public Creature
{
private:
public:
    JMLepen();
    ~JMLepen();
};

class MLepen : public Creature
{
private:
public:
    MLepen();
    ~MLepen();
};

#endif // CREATURE_H_INCLUDED
