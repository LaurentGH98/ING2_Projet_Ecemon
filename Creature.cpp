#include <iostream>
#include "Creature.h"

///CLASSE CREATURE
///CONSTRUCTEUR et DESTRUCTEUR
// Les classes Carte et Creature, (ainsi que Energie et Speciale) n'existent pas à proprement parler
// On pourrait en faire des classes virtuelles
// On fait quand même un constructeur par défaut de Creature, histoire que toutes les cartes créatures aient
// les mêmes points de vie, points d'attaque et défense.

Creature::Creature()
{

}

Creature::Creature(std::string nom, std::string description, std::string type, int vie, int defense, int pointsEnergieEG,
                    int pointsEnergieG, int pointsEnergieC, int pointsEnergieD, int pointsEnergieED, Attaque* attaque1, Attaque* attaque2, Defense* defense1):
    Carte(nom, description, type), m_vie(vie), m_defense(defense), m_pointsEnergieEG(pointsEnergieEG), m_pointsEnergieG(pointsEnergieG),
     m_pointsEnergieC(pointsEnergieC), m_pointsEnergieD(pointsEnergieD), m_pointsEnergieED(pointsEnergieED), m_attaque1(attaque1), m_attaque2(attaque2), m_defense1(defense1)
{

}

Creature::~Creature()
{

}

///Getters

int Creature::getVie() const
{
    return m_vie;
}

int Creature::getDefense() const
{
    return m_defense;
}

int Creature::getPointsEnergieEG() const
{
    return m_pointsEnergieEG;
}

int Creature::getPointsEnergieG() const
{
    return m_pointsEnergieG;
}

int Creature::getPointsEnergieC() const
{
   return m_pointsEnergieC;
}

int Creature::getPointsEnergieD() const
{
    return m_pointsEnergieD;
}

int Creature::getPointsEnergieED() const
{
    return m_pointsEnergieED;
}

Attaque* Creature::getAttaque1() const
{
    return m_attaque1;
}

Attaque* Creature::getAttaque2() const
{
    return m_attaque2;
}

Defense* Creature::getDefense1() const
{
    return m_defense1;
}

///Setters

void Creature::setVie(int vie)
{
    m_vie=vie;
}

void Creature::setDefense(int defense)
{
    m_defense=defense;
}

void Creature::setPointsEnergieEG(int pointsEnergieEG)
{
    m_pointsEnergieEG=pointsEnergieEG;
}

void Creature::setPointsEnergieG(int pointsEnergieG)
{
    m_pointsEnergieG=pointsEnergieG;
}

void Creature::setPointsEnergieC(int pointsEnergieC)
{
    m_pointsEnergieC=pointsEnergieC;
}

void Creature::setPointsEnergieD(int pointsEnergieD)
{
    m_pointsEnergieD=pointsEnergieD;
}

void Creature::setPointsEnergieED(int pointsEnergieED)
{
    m_pointsEnergieED=pointsEnergieED;
}

void Creature::setAttaque1(Attaque* attaque1)
{
    m_attaque1=attaque1;
}

void Creature::setAttaque2(Attaque* attaque2)
{
    m_attaque2=attaque2;
}

void Creature::setDefense1(Defense* defense1)
{
    m_defense1=defense1;
}

///Méthodes de Creature
void Creature::attaquer(Carte* creatureCible, Attaque* attaqueChoisie)
{
    //Le nom et la description de l'attaque sont affichés dans la console
    std::cout << "Vous utilisez " << attaqueChoisie->getNom() << std::endl;
    std::cout << "Description : " << attaqueChoisie->getDescription() << std::endl;

    //La créature cible reçoit des dégats
    creatureCible->recevoirDegats(attaqueChoisie);
}

void Creature::recevoirDegats(Attaque* attaque)
{
    //Si la defense de la cible est supérieure ou égale aux dégats de l'attaque, la créature perd 0
    if(this->getDefense() >= attaque->getPointsDeDegats())
    {
        std::cout<<this->getNom()<<" se defend completement de l attaque. Aucun degat recu."<<std::endl;
    }
    //sinon, il perd de la vie
    else
    {
        std::cout<<this->getNom()<<" a une defense de "<<this->getDefense()<<", la creature perd donc : "<<attaque->getPointsDeDegats()-this->getDefense()<<" point(s) de vie." << std::endl;
        this->setVie(this->getVie() + this->getDefense() - attaque->getPointsDeDegats());
    }
    //après une attaque, ses points de défense accumulés disparaissent
    this->setDefense(0);
}

void Creature::seDefendre(Defense* defense)
{
    //Le nom et la description de la défense sont affichés dans la console
    std::cout << "Vous utilisez " << defense->getNom() << std::endl;
    std::cout << "Description : " << defense->getDescription() << std::endl;

    //la créature augmente sa défense
    this->setDefense(this->getDefense() + defense->getPointsDeDefense());
    std::cout << "Defense ! Les degats de la prochaine attaque sont reduits de " << this->getDefense() << " !" << std::endl;
}

///TOUTES LES CLASSES DES CARTES CREATURES
///constructeurs et destructeurs
Melenchon::Melenchon() :
    Creature("Melenchon", "Ce politicien d'extreme gauche est loquace ! Mefiez-vous! Il saura vaincre ses adversaires par son sens de la repartie.",
              "Creature", 10, 0, 0, 0, 0, 0, 0, new Attaque("La Republique, c est moi!", "Occasionne 4 points de degats", 4, 1, "EG"),
              new Attaque("Discours enflamme", "Occasionne 8 points de degats", 8, 2, "EG"),
              new Defense("Defense Ouvriere", "Reduit les degats de 3 pour la prochaine attaque.", 3, 0,""))
{

}

Melenchon::~Melenchon()
{

}

Marchais::Marchais() :
    Creature("Marchais", "Ce politicien d'extreme gauche s y connait dans l art de la punchline. Il saura en destabiliser plus d un.",
              "Creature", 10, 0, 0, 0, 0, 0, 0, new Attaque("Punchline devastatrice", "Occasionne 4 points de degats", 4, 1, "EG"),
              new Attaque("Fais tes valises, on rentre a Paris!", "Occasionne 8 points de degats", 8, 2, "EG"),
              new Defense("Defense Ouvriere", "Reduit les degats de 3 pour la prochaine attaque.", 3, 0,""))
{

}

Marchais::~Marchais()
{

}

Hamon::Hamon() :
    Creature("Hamon", "Ce politicien de gauche possede une aura redoutable (non on rigole) mais il peut quand meme faire des degats aux adversaires.",
              "Creature", 10, 0, 0, 0, 0, 0, 0, new Attaque("KEBABHAMON", "Occasionne 4 points de degats", 4, 1, "G"),
              new Attaque("Rose kipik", "occasionne 8 points de degats", 8, 2, "G"),
              new Defense("Couverture du peuple", "Reduit les degats de 3 pour la prochaine attaque.", 3, 0,""))
{

}

Hamon::~Hamon()
{

}

Hollande::Hollande() :
    Creature("Hollande", "Cet ancien president de gauche semble mou mais il peut se reveler impitoyable.",
              "Creature", 10, 0, 0, 0, 0, 0, 0, new Attaque("You can do be what we want to do", "Occasionne 4 points de degats", 4, 1, "G"),
              new Attaque("Les Mous peuvent atteindre l excellence", "occasionne 8 points de degats", 8, 2, "G"),
              new Defense("Couverture du peuple", "Reduit les degats de 3 pour la prochaine attaque.", 3, 0,""))
{

}

Hollande::~Hollande()
{

}

Macron::Macron() :
    Creature("Macron", "Ce president de Centre est extremement puissant ! Mefiez vous de son charisme devastateur!",
              "Creature", 10, 0, 0, 0, 0, 0, 0, new Attaque("C est notre projeeeeet !", "Occasionne 4 points de degats", 4, 1, "C"),
              new Attaque("En marche", "occasionne 8 points de degats", 8, 2, "C"),
              new Defense("Appel a la Garde Nationale", "Reduit les degats de 3 pour la prochaine attaque.", 3, 0,""))
{

}

Macron::~Macron()
{

}

Lassalle::Lassalle() :
    Creature("Lassalle", "Cet homme de la campagne a su se frayer une place dans les hautes spheres de la politique, ne le sous-estimez pas ! Il est du Centre.",
              "Creature", 10, 0, 0, 0, 0, 0, 0, new Attaque("Qi tres legerement au dessus de 0.", "Occasionne 4 points de degats", 4, 1, "C"),
              new Attaque("Mon cochon prefere ??", "occasionne 8 points de degats", 8, 2, "C"),
              new Defense("Appel a la Garde Nationale", "Reduit les degats de 3 pour la prochaine attaque.", 3, 0,""))
{

}

Lassalle::~Lassalle()
{

}

Fillon::Fillon() :
    Creature("Fillon", "Ce politicien de Droite connait tous les bons coups pour reussir dans la vie. Bon il s est fait choper mais tranquille ca passe..",
              "Creature", 10, 0, 0, 0, 0, 0, 0, new Attaque("Detournement", "Occasionne 4 points de degats", 4, 1, "D"),
              new Attaque("Emploi fictif", "occasionne 8 points de degats", 8, 2, "D"),
              new Defense("Protection Bourgeoise", "Reduit les degats de 3 pour la prochaine attaque.", 3, 0,""))
{

}

Fillon::~Fillon()
{

}

Sarkozy::Sarkozy() :
    Creature("Sarkozy", "Cet ancien president de Droite est puissant, il connait les bons plans pour gagner la bataille.",
              "Creature", 10, 0, 0, 0, 0, 0, 0, new Attaque("Quelle indignite", "Occasionne 4 points de degats", 4, 1, "D"),
              new Attaque("Financement Lybien", "occasionne 8 points de degats", 8, 2, "D"),
              new Defense("Protection Bourgeoise", "Reduit les degats de 3 pour la prochaine attaque.", 3, 0,""))
{

}

Sarkozy::~Sarkozy()
{

}

JMLepen::JMLepen() :
    Creature("JMLepen", "Ce politicen d’extreme Droite n est pas a sous-estimer. Toujours vivant il hante les couloir de l’Assemblee Nationale.",
              "Creature", 10, 0, 0, 0, 0, 0, 0, new Attaque("Jeanne, au secours !", "Occasionne 4 points de degats", 4, 1, "ED"),
              new Attaque("Mr Ebola peut regler ca en 3 mois.", "Occasionne 8 points de degats", 8, 2, "ED"),
              new Defense("La France aux francais", "Reduit les degats de 3 pour la prochaine attaque.", 3, 0,""))
{

}

JMLepen::~JMLepen()
{

}

MLepen::MLepen() :
    Creature("MLepen", "Cette politicienne d’extreme droite nous fait peur, alors un conseil , preparez vous au pire!",
              "Creature", 10, 0, 0, 0, 0, 0, 0, new Attaque("Transformation : le FN devient le RN", "Occasionne 4 points de degats", 4, 1, "ED"),
              new Attaque("Fraude", "occasionne 8 points de degats", 8, 2, "ED"),
              new Defense("La France aux francais", "Reduit les degats de 3 pour la prochaine attaque.", 3, 0,""))
{

}

MLepen::~MLepen()
{

}
