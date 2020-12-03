#include <iostream>
#include "Collection.h"
#include "Creature.h"
#include "Energie.h"
#include "Speciale.h"
#include <algorithm>

//ces deux là pour l'aléatoire (mélanger le deck)
#include <ctime>
#include <cstdlib>



///constructeur et destructeur

Collection::Collection()
{

}

Collection::~Collection()
{

}

///Getters

std::vector<Carte*> Collection::GetCollection()const
{
    return m_collection;
}

std::vector <Carte*> Collection::GetDeck() const
{
    return m_deck;
}

///setters
/*
void Collection::SetCollection(std::vector<std::string> cardname)
{
    Carte* C1 = new Macron; //  IL FAUT INCLURE LES DIFFERENTS TYPES DE CARTES, on verra plus tard
    Carte* C2 = new Lepen;
    Carte* C10 = new BoostDegat;
    ///etc, on met ici les noms de cartes créatures, spéciales et énergies

    std::vector<Carte*>*sauvegarde = new std::vector<Carte*>; ///on fait un pointeur sur un vecteur de cartes, qui sera l'attribut m_collection à la fin

    for(auto elem : cardname)
    {
        if (elem== "Macron")
            sauvegarde->push_back(C1); //pas de point mais une flèche car sauvegarde est un pointeur
        if (elem=="Lepen")
            sauvegarde->push_back(C2);
        if (elem=="BoostDegat")
            sauvegarde->push_back(C10);
    }
    m_collection = *sauvegarde
}


void Collection::SetDeck(std::vector<std::string> cardname)
{
    ///la même
}

*/

///Méthodes
//collection
void Collection::AjouterCarteCollec(Carte* nouvCarte)
{
    m_collection.push_back(nouvCarte);
}

void Collection::RetirerCarteCollec(Carte* carteR)
{
    int condition=0; //si condition passe à 1 cela veut dire que la carte n'est plus dans la collection

    for (auto &elem : m_collection) //on parcourt la collection
    {
        if(elem->getNom()== carteR->getNom())
        {
            elem = m_collection.back(); ///back pour dernier élément
            m_collection.back()=carteR;
            condition=1;
        }
    }
    if (condition==1)
        m_collection.pop_back(); //on retire la dernière carte qui corresond à carteR; la carte à retirer
    else
        std::cout << "La carte a retirer n'est deja plus dans votre collection." << std::endl;
}

void Collection::afficherCollec()
{
    std::cout<<"Votre collection est composee des cartes suivantes : "<<std::endl;
    for (auto &elem : m_collection) //on parcourt la collection
    {
        ///quand on affiche la collection, on pense à mettre les numéros pour que le joueur puisse choisir
        ///ses cartes à partir de celle ci lorsqu'il veut créer son deck
        if (elem->getNom()=="Melenchon")
            std::cout << "1)";
        if (elem->getNom()=="Marchais")
            std::cout << "2)";
        if (elem->getNom()=="Hamon")
            std::cout << "3)";
        if (elem->getNom()=="Hollande")
            std::cout << "4)";
        if (elem->getNom()=="Macron")
            std::cout << "5)";
        if (elem->getNom()=="Lassalle")
            std::cout << "6)";
        if (elem->getNom()=="Fillon")
            std::cout << "7)";
        if (elem->getNom()=="Sarkozy")
            std::cout << "8)";
        if (elem->getNom()=="JMLepen")
            std::cout << "9)";
        if (elem->getNom()=="MLepen")
            std::cout << "10)";
        if (elem->getNom()=="Extreme Gauche")
            std::cout << "11)";
        if (elem->getNom()=="Gauche")
            std::cout << "12)";
        if (elem->getNom()=="Centre")
            std::cout << "13)";
        if (elem->getNom()=="Droite")
            std::cout << "14)";
        if (elem->getNom()=="Extreme Droite")
            std::cout << "15)";
        if (elem->getNom()=="Kamikaze")
            std::cout << "16)";
        if (elem->getNom()=="BoostVie")
            std::cout << "17)";
        if (elem->getNom()=="BoostDef")
            std::cout << "18)";
        if (elem->getNom()=="BoostAttaque")
            std::cout << "19)";
        if (elem->getNom()=="Attaquex2")
            std::cout << "20)";
        if (elem->getNom()=="Renvoi")
            std::cout << "21)";

        std::cout<< elem->getNom() <<std::endl; //Ici on fait un getNom car pour la afficher la collection
        //on n'a besoin d'afficher que le nom des cartes, elem étant une Carte*
    }
    std::cout << std::endl;
}


//Deck

void Collection::AjouterCarteDeck(Carte* nouvCarte)
{
    m_deck.push_back(nouvCarte);
}

void Collection::RetirerCarteDeck(Carte* carteR)
{
    int condition;
    for (auto &elem : m_deck)
    {
        if (elem->getNom()==carteR->getNom())
        {
            elem=m_deck.back();
            m_deck.back()=carteR;
            condition=1;
        }
    }
    if (condition==1)
        m_deck.pop_back();
    else
        std::cout << "La carte a retirer n'est deja plus dans le deck." << std::endl;
}

void Collection::DetruireDeck()
{
    for (int i=0; i<20; ++i)
    {
        m_deck.pop_back();//on détruit le deck en retirant toutes les cartes
    }
}

void Collection::afficherDeck()
{
    std::cout<<"Votre deck est compose des cartes suivantes : "<<std::endl;
    for (auto &elem : m_deck) //on parcourt le deck
    {
        std::cout << elem->getNom() << std::endl; //elem est une Carte*, donc on affiche son nom avec le getter
    }
    std::cout << std::endl;
}

void Collection::MelangerDeck()
{
    srand(time==NULL);
    std::random_shuffle(m_deck.begin(),m_deck.end());
    std::cout<<"Le deck a ete melange ! "<<std::endl;
}
