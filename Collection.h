#ifndef COLLECTION_H_INCLUDED
#define COLLECTION_H_INCLUDED

#include "Carte.h"
#include <vector>


class Collection
{
private :
    std::vector <Carte*> m_collection;
    std::vector <Carte*> m_deck; ///LE DECK DU JOUEUR EST DANS SA COLLECTION -> facile à gérer

public :
    ///Constructeur et destructeur
    Collection();
    ~Collection();

    ///getters
    std::vector<Carte*> GetCollection() const;
    std::vector <Carte*> GetDeck() const;

    ///setters
    void SetCollection (std::vector <std::string> cardname); //on set la collection avec le nom de carte
    void SetDeck (std::vector <std::string> cardname); //idem

    ///Méthodes
    void AjouterCarteCollec (Carte* nouvCarte);
    void RetirerCarteCollec (Carte* carteR);
    void afficherCollec();
    void effacerElementCollection(int i);
    void clearCollection();

    void AjouterCarteDeck (Carte* nouvCarte);
    void RetirerCarteDeck (Carte* carteR);
    void afficherDeck();

    void DetruireDeck();

    void MelangerDeck();

};

#endif // COLLECTION_H_INCLUDED
