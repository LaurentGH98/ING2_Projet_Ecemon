#include "fonctions.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>

///--------------------------------------------------MENU--------------------------------------------------------
using namespace std;
void menu()
{
    bool boucle=true;
    int choix=0;
    Joueur* joueur1 = new Joueur;
    Joueur* joueur2 = new Joueur;

    while(boucle)
    {
        std::cout<<"1) Nouvelle Partie"<<std::endl;
        std::cout<<"2) Creer un joueur"<<std::endl;
        std::cout<<"3) Boutique"<<std::endl;
        std::cout<<"4) Voir la collection d'un joueur"<<std::endl;
        std::cout<<"5) Regles du jeu"<<std::endl;
        std::cout<<"6) Quitter"<<std::endl;
        std::cout<<"Quel est votre choix : ";
        std::cin>>choix;
        std::cout<<std::endl;

        switch(choix)
        {
        case 1:
            //debuter une partie
            lancerPartie(joueur1);
            lancerPartie(joueur2);
            jouer(joueur1, joueur2);
            break;
        case 2:
            //creer un joueur
            creerJoueur();
            break;
        case 3:
            afficherBoutique();
            break;
        case 4:
            //voir collection
            break;
        case 5:
            //voir règles du jeu
            std::cout<<std::endl<<"\t\t\t\t\t---- LES REGLES DE REPUBLIMON ----"<<std::endl;
            std::cout<<std::endl;
            std::cout<<"\tPour commencer, chaque joueur doit se creer un deck a partir de sa collection de cartes. Ce deck de cartes lui  permettra d affronter d autres joueurs lors d'une partie. Il y a 3 types de cartes qui constitueront son deck: "<<std::endl;
            std::cout<<std::endl;
            std::cout<<"  - Les Cartes Creatures = qui sont des politiciens francais connus de tous"<<std::endl;
            std::cout<<std::endl;
            std::cout<<"  - Les Cartes Speciales = qui permettent d alterer le cours d une partie mais attention au contre coups!"<<std::endl;
            std::cout<<std::endl;
            std::cout<<"  - Et les Cartes Energies = Il y en a 5 et sont necessaires pour lancer des attaques avec vos politiciens"<<std::endl;
            std::cout<<std::endl;
            std::cout<<"Au cours d une partie, 2 joueurs s affrontent a coups de scandales et punchlines devastatrices jusqu a ce que l un des  joueurs n ait plus de politicien et s incline lors de cet affrontement au SOMMET !"<<std::endl;
            std::cout<<std::endl;
            break;
        case 6:
            //quitter
            boucle=false; //fin de la boucle du menu
            break;
        }
    }
}

///-----------------------------------------------AFFICHER BOUTIQUE-------------------------------------------------------------
void afficherBoutique()
{
    std::cout << "La boutique se compose donc de : " << std::endl << std::endl;
    std::cout << "Cartes CREATURES                                Cartes ENERGIE                             Cartes Speciales" << std::endl << std::endl;
    std::cout << "-1)Melenchon            cout : 5      |         -11)Extreme Gauche   cout : 3    |         -16)Kamikaze       cout : 6" << std::endl;
    std::cout << "-2)Marchais             cout : 5      |         -12)Gauche           cout : 3    |         -17)BoostVie       cout : 6" << std::endl;
    std::cout << "-3)Hamon                cout : 5      |         -13)Centre           cout : 3    |         -18)BoostDef       cout : 6" << std::endl;
    std::cout << "-4)Hollande             cout : 5      |         -14)Droite           cout : 3    |         -19)BoostAttaque   cout : 6" << std::endl;
    std::cout << "-5)Macron               cout : 5      |         -15)Extreme Droite   cout : 3    |         -20)Attaquex2      cout : 6" << std::endl;
    std::cout << "-6)Lassalle             cout : 5      |                                          |         -21)Renvoi         cout : 6" << std::endl;
    std::cout << "-7)Fillon               cout : 5      |                                          |" << std::endl;
    std::cout << "-8)Sarkozy              cout : 5      |                                          |" << std::endl;
    std::cout << "-9)Jean-Marie Lepen     cout : 5      |                                          |"  << std::endl;
    std::cout << "-10)Marine Lepen        cout : 5      |                                          |" << std::endl << std::endl;

}



///-----------------------------------------------CREER JOUEUR------------------------------------------------------------------
void creerJoueur()
{
    /*
    ***entrer le nom du joueur
    ***la boutique affiche toutes les cartes
    ***le joueur achète une collection, carte par carte, à la boutique
    ***quand il a fini, sa collection s'affiche, puis s'enregistre dans un fichier
    ***entrer une commande pour retourner au menu
    */
    int choix;//pour choisir les cartes de la boutique
    int argent=100;

    ///entrer le nom d'un joueur
    std::string nom;
    std::cout << "Vous allez creer un joueur, saisissez son nom" << std::endl;
    std::cin >> nom;
    std::cout << "Le joueur s'appelle donc " << nom << std::endl;

    ///on sauvegarde son nom, ou même pas d'ailleurs puisque le fichier porte le nom du joueur
    std::string nomFichier=nom+".txt";
    std::ofstream Flux(nomFichier.c_str());//ouverture du fichier en écriture

    if(Flux)  //On teste si tout est OK
    {
        ///Flux<<nom<<std::endl; //pas besoin d'écrire le nom normalement, puisque le fichier porte le nom du joueur

    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }


    ///La boutique affiche toutes les cartes
    afficherBoutique();

    ///Le joueur achète une collection, carte par carte, à la boutique
    std::cout << "Vous devez acheter 25 cartes au choix : 5 cartes creature, 15 cartes energie et 5 cartes speciales" << std::endl;
    std::cout << "ATTENTION : vous ne pouvez acheter que 1 exemplaire maximum d'une meme carte Creature ou Speciale!" << std::endl;
    std::cout << "Vous possedez 100 euros." << std::endl;
    std::cout << "Quelles cartes souhaitez-vous acheter ? Entrez simplement leur numero" << std::endl;
    std::vector<std::string> tableauNomsDeCartes;
    std::vector<int> tableauDeNumeros; //pour ensuite trier les cartes lors de l'affichage de la collection
    for (int i=0; i<25; ++i)
    {
        std::cin >> choix;

        switch (choix)
        {
        case 1 :
            argent=argent-5;
            std::cout << "Vous avez choisi Melenchon,il vous reste " << argent << "euros." << std::endl;
            tableauDeNumeros.push_back(1);
            break;
        case 2 :
            argent=argent-5;
            std::cout << "Vous avez choisi Marchais,il vous reste " << argent << "euros." << std::endl;
            tableauDeNumeros.push_back(2);
            break;
        case 3 :
            argent=argent-5;
            std::cout << "Vous avez choisi Hamon,il vous reste " << argent << "euros." << std::endl;
            tableauDeNumeros.push_back(3);
            break;
        case 4 :
            argent=argent-5;
            std::cout << "Vous avez choisi Hollande,il vous reste " << argent << "euros." << std::endl;
            tableauDeNumeros.push_back(4);
            break;
        case 5 :
            argent=argent-5;
            std::cout << "Vous avez choisi Macron,il vous reste " << argent << "euros." << std::endl;
            tableauDeNumeros.push_back(5);
            break;
        case 6 :
            argent=argent-5;
            std::cout << "Vous avez choisi Lassalle,il vous reste " << argent << "euros." << std::endl;
            tableauDeNumeros.push_back(6);
            break;
        case 7 :
            argent=argent-5;
            std::cout << "Vous avez choisi Fillon,il vous reste " << argent << "euros." << std::endl;
            tableauDeNumeros.push_back(7);
            break;
        case 8 :
            argent=argent-5;
            std::cout << "Vous avez choisi Sarkozy,il vous reste " << argent << "euros." << std::endl;
            tableauDeNumeros.push_back(8);
            break;
        case 9 :
            argent=argent-5;
            std::cout << "Vous avez choisi Jean-Marie Lepen,il vous reste " << argent << "euros." << std::endl;
            tableauDeNumeros.push_back(9);
            break;
        case 10 :
            argent=argent-5;
            std::cout << "Vous avez choisi Marine Lepen,il vous reste " << argent << "euros." << std::endl;
            tableauDeNumeros.push_back(10);
            break;
        case 11 :
            argent=argent-3;
            std::cout << "Vous avez choisi Extreme Gauche,il vous reste " << argent << "euros." << std::endl;
            tableauDeNumeros.push_back(11);
            break;
        case 12 :
            argent=argent-3;
            std::cout << "Vous avez choisi Gauche,il vous reste " << argent << "euros." << std::endl;
            tableauDeNumeros.push_back(12);
            break;
        case 13 :
            argent=argent-3;
            std::cout << "Vous avez choisi Centre,il vous reste " << argent << "euros." << std::endl;
            tableauDeNumeros.push_back(13);
            break;
        case 14 :
            argent=argent-3;
            std::cout << "Vous avez choisi Droite,il vous reste " << argent << "euros." << std::endl;
            tableauDeNumeros.push_back(14);
            break;
        case 15 :
            argent=argent-3;
            std::cout << "Vous avez choisi Extreme Droite,il vous reste " << argent << "euros." << std::endl;
            tableauDeNumeros.push_back(15);
            break;
        case 16 :
            argent=argent-6;
            std::cout << "Vous avez choisi Kamikaze,il vous reste " << argent << "euros." << std::endl;
            tableauDeNumeros.push_back(16);
            break;
        case 17 :
            argent=argent-6;
            std::cout << "Vous avez choisi BoostVie,il vous reste " << argent << "euros." << std::endl;
            tableauDeNumeros.push_back(17);
            break;
        case 18 :
            argent=argent-6;
            std::cout << "Vous avez choisi BoostDef,il vous reste " << argent << "euros." << std::endl;
            tableauDeNumeros.push_back(18);
            break;
        case 19 :
            argent=argent-6;
            std::cout << "Vous avez choisi BoostAttaque,il vous reste " << argent << "euros." << std::endl;
            tableauDeNumeros.push_back(19);
            break;
        case 20 :
            argent=argent-6;
            std::cout << "Vous avez choisi Attaquex2,il vous reste " << argent << "euros." << std::endl;
            tableauDeNumeros.push_back(20);
            break;
        case 21 :
            argent=argent-6;
            std::cout << "Vous avez choisi Renvoi,il vous reste " << argent << "euros." << std::endl;
            tableauDeNumeros.push_back(21);
            break;
        default :
            std::cout << "Veuillez rentrer un nombre entre 1 et 21." << std::endl;
            break;
        }
    }

    ///quand il a fini, sa collection est triée et s'affiche, puis on l'écrit dans un fichier
    sort(tableauDeNumeros.begin(), tableauDeNumeros.end()); //on trie les numéros pour afficher les cartes dans l'ordre
    for (int i=0; i<25; ++i)
    {
        switch (tableauDeNumeros[i])
        {
        case 1 :
            tableauNomsDeCartes.push_back("Melenchon");
            break;
        case 2 :
            tableauNomsDeCartes.push_back("Marchais");
            break;
        case 3 :
            tableauNomsDeCartes.push_back("Hamon");
            break;
        case 4 :
            tableauNomsDeCartes.push_back("Hollande");
            break;
        case 5 :
            tableauNomsDeCartes.push_back("Macron");
            break;
        case 6 :
            tableauNomsDeCartes.push_back("Lassalle");
            break;
        case 7 :
            tableauNomsDeCartes.push_back("Fillon");
            break;
        case 8 :
            tableauNomsDeCartes.push_back("Sarkozy");
            break;
        case 9 :
            tableauNomsDeCartes.push_back("Jean-Marie Lepen");
            break;
        case 10 :
            tableauNomsDeCartes.push_back("Marine Lepen");
            break;
        case 11 :
            tableauNomsDeCartes.push_back("Extreme Gauche");
            break;
        case 12 :
            tableauNomsDeCartes.push_back("Gauche");
            break;
        case 13 :
            tableauNomsDeCartes.push_back("Centre");
            break;
        case 14 :
            tableauNomsDeCartes.push_back("Droite");
            break;
        case 15 :
            tableauNomsDeCartes.push_back("Extreme Droite");
            break;
        case 16 :
            tableauNomsDeCartes.push_back("Kamikaze");
            break;
        case 17 :
            tableauNomsDeCartes.push_back("BoostVie");
            break;
        case 18 :
            tableauNomsDeCartes.push_back("BoostDef");
            break;
        case 19 :
            tableauNomsDeCartes.push_back("BoostAttaque");
            break;
        case 20 :
            tableauNomsDeCartes.push_back("Attaquex2");
            break;
        case 21 :
            tableauNomsDeCartes.push_back("Renvoi");
            break;
        }
    }
    std::cout << std::endl << std::endl;
    std::cout << "Votre collection est composee de : " << std::endl;
    for (auto elem : tableauNomsDeCartes)
    {
        std::cout << elem << std::endl; //on affiche la collection sur la console
        if(Flux)  //On teste si tout est OK
        {
            Flux<<elem<<std::endl;  //on écrit les noms des cartes dans le fichier du joueur
            ///pour le moment on écrit que le nom des cartes, mais le joueur n'a pas encore de collection
            ///il n'a une collection que lorsque la partie commence, après la saisie de 2 joueurs déjà existants
        }
        else
        {
            std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
        }
    }
    std::cout << std::endl;
}
///----------------Blindage du choix des cartes lors de la création du deck, par une fonction qui retourne un booléen----------------
bool isChoiceOk(int choix, Joueur* joueur)
{
    bool isPresent = false;

    if(choix ==1)
    {
        for (auto &elem : joueur->getClasseCollec()->GetCollection())
        {
            if(elem->getNom()=="Melenchon")
                isPresent = true;
        }
    }
    if(choix ==2)
    {
        for (auto &elem : joueur->getClasseCollec()->GetCollection())
        {
            if(elem->getNom()=="Marchais")
                isPresent = true;
        }
    }
    if(choix ==3)
    {
        for (auto &elem : joueur->getClasseCollec()->GetCollection())
        {
            if(elem->getNom()=="Hamon")
                isPresent = true;
        }
    }
    if(choix ==4)
    {
        for (auto &elem : joueur->getClasseCollec()->GetCollection())
        {
            if(elem->getNom()=="Hollande")
                isPresent = true;
        }
    }
    if(choix ==5)
    {
        for (auto &elem : joueur->getClasseCollec()->GetCollection())
        {
            if(elem->getNom()=="Macron")
                isPresent = true;
        }
    }
    if(choix ==6)
    {
        for (auto &elem : joueur->getClasseCollec()->GetCollection())
        {
            if(elem->getNom()=="Lassalle")
                isPresent = true;
        }
    }
    if(choix ==7)
    {
        for (auto &elem : joueur->getClasseCollec()->GetCollection())
        {
            if(elem->getNom()=="Fillon")
                isPresent = true;
        }
    }
    if(choix ==8)
    {
        for (auto &elem : joueur->getClasseCollec()->GetCollection())
        {
            if(elem->getNom()=="Sarkozy")
                isPresent = true;
        }
    }
    if(choix ==9)
    {
        for (auto &elem : joueur->getClasseCollec()->GetCollection())
        {
            if(elem->getNom()=="JMLepen")
                isPresent = true;
        }
    }
    if(choix ==10)
    {
        for (auto &elem : joueur->getClasseCollec()->GetCollection())
        {
            if(elem->getNom()=="MLepen")
                isPresent = true;
        }
    }
    if(choix ==11)
    {
        for (auto &elem : joueur->getClasseCollec()->GetCollection())
        {
            if(elem->getNom()=="Extreme Gauche")
                isPresent = true;
        }
    }
    if(choix ==12)
    {
        for (auto &elem : joueur->getClasseCollec()->GetCollection())
        {
            if(elem->getNom()=="Gauche")
                isPresent = true;
        }
    }
    if(choix ==13)
    {
        for (auto &elem : joueur->getClasseCollec()->GetCollection())
        {
            if(elem->getNom()=="Centre")
                isPresent = true;
        }
    }
    if(choix ==14)
    {
        for (auto &elem : joueur->getClasseCollec()->GetCollection())
        {
            if(elem->getNom()=="Droite")
                isPresent = true;
        }
    }
    if(choix ==15)
    {
        for (auto &elem : joueur->getClasseCollec()->GetCollection())
        {
            if(elem->getNom()=="Extreme Droite")
                isPresent = true;
        }
    }
    if(choix ==16)
    {
        for (auto &elem : joueur->getClasseCollec()->GetCollection())
        {
            if(elem->getNom()=="Kamikaze")
                isPresent = true;
        }
    }
    if(choix ==17)
    {
        for (auto &elem : joueur->getClasseCollec()->GetCollection())
        {
            if(elem->getNom()=="BoostVie")
                isPresent = true;
        }
    }
    if(choix ==18)
    {
        for (auto &elem : joueur->getClasseCollec()->GetCollection())
        {
            if(elem->getNom()=="BoostDef")
                isPresent = true;
        }
    }
    if(choix ==19)
    {
        for (auto &elem : joueur->getClasseCollec()->GetCollection())
        {
            if(elem->getNom()=="BoostAttaque")
                isPresent = true;
        }
    }
    if(choix ==20)
    {
        for (auto &elem : joueur->getClasseCollec()->GetCollection())
        {
            if(elem->getNom()=="Attaquex2")
                isPresent = true;
        }
    }
    if(choix ==21)
    {
        for (auto &elem : joueur->getClasseCollec()->GetCollection())
        {
            if(elem->getNom()=="Renvoi")
                isPresent = true;
        }
    }


    return isPresent;
}

///-----------------------------------------------LANCER PARTIE----------------------------------------------------------------------
void lancerPartie(Joueur* joueur)
{
    /// ICI LES JOUEURS NE SONT PAS INITIALISES


    ///LES ETAPES SUIVANTES DOIVENT ETRE FAITES POUR LES 2 JOUEURS
    Carte* currentCarte; //va servir à créer les cartes de la collection en fonctions du nom lu dans le fichier
    Carte* currentCarte2; //même principe, mais pour le deck

    ///1)entrer le nom d'un joueur déjà existant : on crée et on affiche sa collection
    std::string nomJoueur;

    int conditionArret=0; //si le fichier s'ouvre ca passe a 1
    while (conditionArret==0) //tant que le fichier ne s'ouvre pas on redemande une sausie du nom
    {
        std::cout << "Saisir le nom du joueur, deja existant" << std::endl;
        std::cin >> nomJoueur;
        std::ifstream Flux((nomJoueur+".txt").c_str());//ouverture du fichier en lecture
        if(Flux)  //On teste si tout est OK
        {
            //SI LE FICHIER S OUVRE C EST QUE LE JOUEUR EXISTE DANS LES FICHIERS DONC ON PEUT L INITIALISER
            joueur->setNom(nomJoueur);


            std::string ligne; //ligne nous permettant de lire le fichier ligne par ligne
            while (getline(Flux, ligne)) //Tant qu'on n'est pas à la fin, on lit une ligne complète
            {
                if (ligne=="Melenchon")
                {
                    currentCarte = new Melenchon();
                }
                else if (ligne=="Marchais")
                {
                    currentCarte = new Marchais();
                }
                else if (ligne=="Hamon")
                {
                    currentCarte = new Hamon();
                }
                else if (ligne=="Hollande")
                {
                    currentCarte = new Hollande();
                }
                else if (ligne=="Macron")
                {
                    currentCarte = new Macron();
                }
                else if (ligne=="Lassalle")
                {
                    currentCarte = new Lassalle();
                }
                else if (ligne=="Fillon")
                {
                    currentCarte = new Fillon();
                }
                else if (ligne=="Sarkozy")
                {
                    currentCarte = new Sarkozy();
                }
                else if (ligne=="JMLepen")
                {
                    currentCarte = new JMLepen();
                }
                else if (ligne=="MLepen")
                {
                    currentCarte = new MLepen();
                }
                else if (ligne=="Extreme Gauche")
                {
                    currentCarte = new ExtremeGauche();
                }
                else if (ligne=="Gauche")
                {
                    currentCarte = new Gauche();
                }
                else if (ligne=="Centre")
                {
                    currentCarte = new Centre();
                }
                else if (ligne=="Droite")
                {
                    currentCarte = new Droite();
                }
                else if (ligne=="Extreme Droite")
                {
                    currentCarte = new ExtremeDroite();
                }
                else if (ligne=="Kamikaze")
                {
                    currentCarte = new Kamikaze();
                }
                else if (ligne=="BoostVie")
                {
                    currentCarte = new BoostVie();
                }
                else if (ligne=="BoostDef")
                {
                    currentCarte = new BoostDef();
                }
                else if (ligne=="BoostAttaque")
                {
                    currentCarte = new BoostAttaque();
                }
                else if (ligne=="Attaquex2")
                {
                    currentCarte = new Attaquex2();
                }
                else if (ligne=="Renvoi")
                {
                    currentCarte = new Renvoi();
                }
                //IMPORTANT : Une fois que la currentCarte est initialisée sur la bonne carte, on ajoute la carte à la collection
                joueur->getClasseCollec()->AjouterCarteCollec(currentCarte);
            }//fin while get line
            conditionArret=1;
        }//fin if flux
        else
        {
            std::cout << "ERREUR: Impossible d'ouvrir le fichier. Le joueur " << nomJoueur << " n'existe pas." <<  std::endl;
        }
    }


    joueur->getClasseCollec()->afficherCollec();

    ///2)le joueur ajoute des cartes, une par une, à son deck depuis sa collection
    std::cout << std::endl;
    std::cout << "A partir de cette collection, former un deck de 16 cartes : 3 Creatures, 10 Energies, 3 Speciales" << std::endl;
    std::cout << "Saisissez les numeros des cartes que vous voulez, pour creer votre deck" << std::endl;
    int choix;

    for (int i=0; i<16; ++i)
    {
        std::cin >> choix;
        switch (choix)
        {
        case 1 :
            if(isChoiceOk(choix,joueur)) //permet de vérifier si la carte choisie par l'utilisateur est présente dans son deck
            {
                currentCarte2 = new Melenchon();
                joueur->getClasseCollec()->AjouterCarteDeck(currentCarte2);
            }
            else
            {
                std::cout << "Cette carte n est pas dans votre collection, veuillez en saisir une autre" << std::endl;
                i--; //permet de ne pas prendre en compte le tour de boucle en cours
            }
            break;
        case 2 :
            if(isChoiceOk(choix,joueur))
            {
                currentCarte2 = new Marchais();
                joueur->getClasseCollec()->AjouterCarteDeck(currentCarte2);
            }
            else
            {
                std::cout << "Cette carte n est pas dans votre collection, veuillez en saisir une autre" << std::endl;
                i--;
            }
            break;
        case 3 :
            if(isChoiceOk(choix,joueur))
            {
                currentCarte2 = new Hamon();
                joueur->getClasseCollec()->AjouterCarteDeck(currentCarte2);
            }
            else
            {
                std::cout << "Cette carte n est pas dans votre collection, veuillez en saisir une autre" << std::endl;
                i--;
            }
            break;
        case 4 :
            if(isChoiceOk(choix,joueur))
            {
                currentCarte2 = new Hollande();
                joueur->getClasseCollec()->AjouterCarteDeck(currentCarte2);
            }
            else
            {
                std::cout << "Cette carte n est pas dans votre collection, veuillez en saisir une autre" << std::endl;
                i--;
            }
            break;
        case 5 :
            if(isChoiceOk(choix,joueur))
            {
                currentCarte2 = new Macron();
                joueur->getClasseCollec()->AjouterCarteDeck(currentCarte2);
            }
            else
            {
                std::cout << "Cette carte n est pas dans votre collection, veuillez en saisir une autre" << std::endl;
                i--;
            }
            break;
        case 6 :
            if(isChoiceOk(choix,joueur))
            {
                currentCarte2 = new Lassalle();
                joueur->getClasseCollec()->AjouterCarteDeck(currentCarte2);
            }
            else
            {
                std::cout << "Cette carte n est pas dans votre collection, veuillez en saisir une autre" << std::endl;
                i--;
            }
            break;
        case 7 :
            if(isChoiceOk(choix,joueur))
            {
                currentCarte2 = new Fillon();
                joueur->getClasseCollec()->AjouterCarteDeck(currentCarte2);
            }
            else
            {
                std::cout << "Cette carte n est pas dans votre collection, veuillez en saisir une autre" << std::endl;
                i--;
            }
            break;
        case 8 :
            if(isChoiceOk(choix,joueur))
            {
                currentCarte2 = new Sarkozy();
                joueur->getClasseCollec()->AjouterCarteDeck(currentCarte2);
            }
            else
            {
                std::cout << "Cette carte n est pas dans votre collection, veuillez en saisir une autre" << std::endl;
                i--;
            }
            break;
        case 9 :
            if(isChoiceOk(choix,joueur))
            {
                currentCarte2 = new JMLepen();
                joueur->getClasseCollec()->AjouterCarteDeck(currentCarte2);
            }
            else
            {
                std::cout << "Cette carte n est pas dans votre collection, veuillez en saisir une autre" << std::endl;
                i--;
            }
            break;
        case 10 :
            if(isChoiceOk(choix,joueur))
            {
                currentCarte2 = new MLepen();
                joueur->getClasseCollec()->AjouterCarteDeck(currentCarte2);
            }
            else
            {
                std::cout << "Cette carte n est pas dans votre collection, veuillez en saisir une autre" << std::endl;
                i--;
            }
            break;
        case 11 :
            if(isChoiceOk(choix,joueur))
            {
                currentCarte2 = new ExtremeGauche();
                joueur->getClasseCollec()->AjouterCarteDeck(currentCarte2);
            }
            else
            {
                std::cout << "Cette carte n est pas dans votre collection, veuillez en saisir une autre" << std::endl;
                i--;
            }
            break;
        case 12 :
            if(isChoiceOk(choix,joueur))
            {
                currentCarte2 = new Gauche();
                joueur->getClasseCollec()->AjouterCarteDeck(currentCarte2);
            }
            else
            {
                std::cout << "Cette carte n est pas dans votre collection, veuillez en saisir une autre" << std::endl;
                i--;
            }
            break;
        case 13 :
            if(isChoiceOk(choix,joueur))
            {
                currentCarte2 = new Centre();
                joueur->getClasseCollec()->AjouterCarteDeck(currentCarte2);
            }
            else
            {
                std::cout << "Cette carte n est pas dans votre collection, veuillez en saisir une autre" << std::endl;
                i--;
            }
            break;
        case 14 :
            if(isChoiceOk(choix,joueur))
            {
                currentCarte2 = new Droite();
                joueur->getClasseCollec()->AjouterCarteDeck(currentCarte2);
            }
            else
            {
                std::cout << "Cette carte n est pas dans votre collection, veuillez en saisir une autre" << std::endl;
                i--;
            }
            break;
        case 15 :
            if(isChoiceOk(choix,joueur))
            {
                currentCarte2 = new ExtremeDroite();
                joueur->getClasseCollec()->AjouterCarteDeck(currentCarte2);
            }
            else
            {
                std::cout << "Cette carte n est pas dans votre collection, veuillez en saisir une autre" << std::endl;
                i--;
            }
            break;
        case 16 :
            if(isChoiceOk(choix,joueur))
            {
                currentCarte2 = new Kamikaze();
                joueur->getClasseCollec()->AjouterCarteDeck(currentCarte2);
            }
            else
            {
                std::cout << "Cette carte n est pas dans votre collection, veuillez en saisir une autre" << std::endl;
                i--;
            }
            break;
        case 17 :
            if(isChoiceOk(choix,joueur))
            {
                currentCarte2 = new BoostVie() ;
                joueur->getClasseCollec()->AjouterCarteDeck(currentCarte2);
            }
            else
            {
                std::cout << "Cette carte n est pas dans votre collection, veuillez en saisir une autre" << std::endl;
                i--;
            }
            break;
        case 18 :
            if(isChoiceOk(choix,joueur))
            {
                currentCarte2 = new BoostDef();
                joueur->getClasseCollec()->AjouterCarteDeck(currentCarte2);
            }
            else
            {
                std::cout << "Cette carte n est pas dans votre collection, veuillez en saisir une autre" << std::endl;
                i--;
            }
            break;
        case 19 :
            if(isChoiceOk(choix,joueur))
            {
                currentCarte2 = new BoostAttaque();
                joueur->getClasseCollec()->AjouterCarteDeck(currentCarte2);
            }
            else
            {
                std::cout << "Cette carte n est pas dans votre collection, veuillez en saisir une autre" << std::endl;
                i--;
            }
            break;
        case 20 :
            if(isChoiceOk(choix,joueur))
            {
                currentCarte2 = new Attaquex2() ;
                joueur->getClasseCollec()->AjouterCarteDeck(currentCarte2);
            }
            else
            {
                std::cout << "Cette carte n est pas dans votre collection, veuillez en saisir une autre" << std::endl;
                i--;
            }
            break;
        case 21 :
            if(isChoiceOk(choix,joueur))
            {
                currentCarte2 = new Renvoi();
                joueur->getClasseCollec()->AjouterCarteDeck(currentCarte2);
            }
            else
            {
                std::cout << "Cette carte n est pas dans votre collection, veuillez en saisir une autre" << std::endl;
                i--;
            }
            break;
        default :
            std::cout << "Veuillez rentrer un nombre valide" << std::endl;
            i--;
            break;

        }
    }
    joueur->getClasseCollec()->afficherDeck();
}


///---------------------------------------CHOIX DE LA CARTE ENJEU pour un joueur------------------------------------------------------
void choixCarteEnjeu(Joueur* joueur)
{
    Carte* CarteEnjeu;
    int numeroCarteEnjeu; //indice de la carte dans le vecteur de Carte* Collection
    numeroCarteEnjeu = rand()%(joueur->getClasseCollec()->GetCollection().size()-1-0+1)+0;
    CarteEnjeu = joueur->getClasseCollec()->GetCollection()[numeroCarteEnjeu];
    joueur->setCarteEnjeu(CarteEnjeu); //on la stocke dans l'attribut carteEnjeu du joueur
    std::cout << "La carte enjeu choisie aleatoirement dans la collection de  " << joueur->getNom() << " est : " << joueur->getCarteEnjeu()->getNom() << std::endl;
}


///-------------------------------------------------INITIALISATION DU JOUEUR-----------------------------------------------------------
void initaliserJoueur(Joueur* joueur)
{
    //nbCreaDispo = nb crea dispo dans le deck;
    //Normalement c'est inutile de parcourir le deck du joueur pour compter le nombre de créatures
    //car si le choix est blindé pour un nombre d'exemplaires précis, ce sera forcément 3

    //On va le faire quand même, car c'est plus logique
    int nbCreaturesDispo=0;
    for (auto &elem : joueur->getClasseCollec()->GetDeck())
    {
        if (elem->getType()=="Creature")
        {
            nbCreaturesDispo+=1;
        }
    }
    joueur->setNbCreaturesDispo(nbCreaturesDispo);
    joueur->setVie(10);
    joueur->setCreatureActive(NULL);
    joueur->clearEnergiesActives(); //équivalent à un setEnergiesActives qui rendrait le vecteur de Carte* vide
    joueur->setSpecialeActive(NULL);
    joueur->clearGraveyard(); //équivalent à un setGraveyard qui rendrait le vecteur de Carte* vide

}


///--------------------------------------------------AFFICHER TERRAIN------------------------------------------------------------------
void afficherTerrain(Joueur* joueur) //affichage pas très propre car on appelle 2 fois, 1 fois par joueur
{
    std::cout << std::endl;
    std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;
    ///Afficher le terrain (Vie du joueur, carte crea avec description, energies posées, spéciale active)
    std::cout << "Joueur : " << joueur->getNom() << std::endl;

    ///vie du joueur :
    std::cout << "Vous avez " << joueur->getVie() << " points de vie" << std::endl;

    ///Nombre de créatures restantes
    std::cout << "Il vous reste " << joueur->getNbCreaturesDispo() << " Creature(s)" << std::endl;

    ///carte Creature active ?
    if (joueur->getCreatureActive()!=NULL)
    {
        std::cout << "Creature active : " << joueur->getCreatureActive()->getNom() << std::endl;
        std::cout << "Description : " << joueur->getCreatureActive()->getDescription() << std::endl;
        std::cout << "Il reste " << joueur->getCreatureActive()->getVie() << " points de vie a la Creature" << std::endl;

        //on affiche aussi ses attaques avec le nb d'énergies et le type recquis, pour aider le joueur lors de son tour
        //attaque1
        std::cout << "Attaque 1 : " << joueur->getCreatureActive()->getAttaque1()->getNom() << std::endl;
        std::cout << "Description : " << joueur->getCreatureActive()->getAttaque1()->getDescription() << std::endl;
        std::cout << "Necessite " << joueur->getCreatureActive()->getAttaque1()->getPointsEnergieRecquis() <<" point(s) d energie dans le type ";
        if (joueur->getCreatureActive()->getAttaque1()->getTypeEnergieRecquis()=="EG")
        {
            std::cout << "Extreme Gauche." << std::endl;
        }
        if (joueur->getCreatureActive()->getAttaque1()->getTypeEnergieRecquis()=="G")
        {
            std::cout << "Gauche." << std::endl;
        }
        if (joueur->getCreatureActive()->getAttaque1()->getTypeEnergieRecquis()=="C")
        {
            std::cout << "Centre." << std::endl;
        }
        if (joueur->getCreatureActive()->getAttaque1()->getTypeEnergieRecquis()=="D")
        {
            std::cout << "Droite." << std::endl;
        }
        if (joueur->getCreatureActive()->getAttaque1()->getTypeEnergieRecquis()=="ED")
        {
            std::cout << "Extreme Droite." << std::endl;
        }

        std::cout << std::endl;

        //attaque 2
        std::cout << "Attaque 2 : " << joueur->getCreatureActive()->getAttaque2()->getNom() << std::endl;
        std::cout << "Description : " << joueur->getCreatureActive()->getAttaque2()->getDescription() << std::endl;
        std::cout << "Necessite " << joueur->getCreatureActive()->getAttaque2()->getPointsEnergieRecquis() <<" point(s) d energie dans le type ";
        if (joueur->getCreatureActive()->getAttaque2()->getTypeEnergieRecquis()=="EG")
        {
            std::cout << "Extreme Gauche." << std::endl;
        }
        if (joueur->getCreatureActive()->getAttaque2()->getTypeEnergieRecquis()=="G")
        {
            std::cout << "Gauche." << std::endl;
        }
        if (joueur->getCreatureActive()->getAttaque2()->getTypeEnergieRecquis()=="C")
        {
            std::cout << "Centre." << std::endl;
        }
        if (joueur->getCreatureActive()->getAttaque2()->getTypeEnergieRecquis()=="D")
        {
            std::cout << "Droite." << std::endl;
        }
        if (joueur->getCreatureActive()->getAttaque2()->getTypeEnergieRecquis()=="ED")
        {
            std::cout << "Extreme Droite." << std::endl;
        }
    }
    else
        std::cout << "En ce moment le joueur n'a pas de Creature sur le Terrain" << std::endl;

    ///carte(s) energie active(s) ?
    if(joueur->getEnergiesActives().size()!=0) //si il y a des energies actives...
    {
        //on parcourt le vecteur et on affiche ses éléments (les énergies actives)
        std::cout << "Energie(s) active(s) : " << std::endl;
        for (auto &elem : joueur->getEnergiesActives())
        {
            std::cout << elem->getNom() << std::endl;
        }
    }
    else
        std::cout << "Aucune energie posee sur le Terrain pour le moment." << std::endl;

    ///carte Spéciale active ?
    if(joueur->getSpecialeActive()!=NULL)
    {
        std::cout << "Speciale active : " << joueur->getSpecialeActive()->getNom() << std::endl;
        std::cout << "Description : " << joueur->getSpecialeActive()->getDescription() << std::endl;
    }
    else
        std::cout << "Aucune carte Speciale posee sur le Terrain pour le moment." << std::endl;

}

///AFFICHAGE DU TERRAIN POUR LES 2 JOUEURS (affichage plus propre, avec joueur1 à gauche et joueur2 à droite)
///à faire si j'ai le temps
/*
void afficherTerrain(Joueur* joueur1, Joueur* joueur2) //affichage pour les 2 joueurs
{
    ///Afficher le terrain (carte crea pour le joueur, les energies posées etc.)
    std::cout << "Joueur : " << joueur1->getNom() << "                  |                   Joueur : " << joueur2->getNom() << std::endl;
    //carte Creature active ?
    if (joueur1->getCreatureActive()!=NULL &&  joueur2->getCreatureActive()!=NULL)
    {
        std::cout << "Creature active : " << joueur1->getCreatureActive()->getNom()
        << "                  |                   Creature active : " <<  joueur2->getCreatureActive()->getNom() << std::endl;
        //std::cout << "Vie restante : " << joueur1->getCreatureActive()->
    }
    if (joueur1->getCreatureActive()!=NULL && joueur2->getCreatureActive()==NULL)
    {
        std::cout << "Creature active : " << joueur1->getCreatureActive()->getNom()
        << "                  |                   Creature active : aucune"  << std::endl;
    }


    //carte(s) energie active(s) ?
    if(joueur1->getEnergiesActives().size()!=0) //si il y a des energies actives...
    {
        //on parcourt le vecteur et on affiche ses éléments (les énergies actives)
        std::cout << "Energie(s) active(s) : " << std::endl;
        for (auto &elem : joueur1->getEnergiesActives())
        {
            std::cout << elem->getNom() << std::endl;
        }
    }
    else
        std::cout << "Aucune energie posee sur le Terrain pour le moment." << std::endl;

    //carte Spéciale active ?
    if(joueur1->getSpecialeActive()!=NULL)
    {
        std::cout << "Speciale active : " << joueur1->getSpecialeActive()->getNom() << std::endl;
    }
    else
        std::cout << "Aucune carte Speciale posee sur le Terrain pour le moment." << std::endl;

}
*/
///-------------------------------DEFILE LE DECK JUSQU'A AVOIR UNE CREATURE POUR LES 2 JOUEURS-----------------------------------------
void defileJusquaCrea(Joueur* joueur)
{
    ///Check si les deux joueurs ont une creature active

    //On déroule le deck
    while(joueur->getCreatureActive() == NULL)
    {
        for(auto &elem : joueur->getClasseCollec()->GetDeck())
        {
            if(elem->getType() == "Creature")
            {
                joueur->setCreatureActive(elem);
                joueur->getClasseCollec()->RetirerCarteDeck(elem); //on n'oublie pas de rertirer la créature du deck
            }
        }
    }

}


///-------------------------------------------AFFICHE ATTAQUES DISPONIBLES-------------------------------------------------------------
void afficherAttaquesDispo(Joueur* joueur)//affiche les attaques disponibles du joueur, avant qu'il ne fasse le choix d'attaquer ou défendre
{
    //on parcourt les énergies actives du joueur...

    for (auto &elem : joueur->getEnergiesActives())
    {
        //on compte le nombre de cartes énergies pour chaque type
        if (elem->getTypeEnergie()=="EG")
        {
            //points EG de la crea_active augmentent de 1
            joueur->getCreatureActive()->setPointsEnergieEG(joueur->getCreatureActive()->getPointsEnergieEG() + 1);
        }
        if (elem->getTypeEnergie()=="G")
        {
            joueur->getCreatureActive()->setPointsEnergieG(joueur->getCreatureActive()->getPointsEnergieG() + 1);
        }
        if (elem->getTypeEnergie()=="C")
        {
            joueur->getCreatureActive()->setPointsEnergieC(joueur->getCreatureActive()->getPointsEnergieC() + 1);

        }
        if (elem->getTypeEnergie()=="D")
        {
            joueur->getCreatureActive()->setPointsEnergieD(joueur->getCreatureActive()->getPointsEnergieD() + 1);

        }
        if (elem->getTypeEnergie()=="ED")
        {
            joueur->getCreatureActive()->setPointsEnergieED(joueur->getCreatureActive()->getPointsEnergieED() + 1);

        }
    }

    //Une fois les énergies comptées, on détermine les attaques dispos :
    std::cout << "Attaque(s) disponible(s)" << std::endl;

    if (joueur->getCreatureActive()->getAttaque1()->getTypeEnergieRecquis()=="EG")
    {
        if (joueur->getCreatureActive()->getPointsEnergieEG() < joueur->getCreatureActive()->getAttaque1()->getPointsEnergieRecquis())
        {
            std::cout << "Aucune" << std::endl;
        }
        if(joueur->getCreatureActive()->getPointsEnergieEG() >= joueur->getCreatureActive()->getAttaque1()->getPointsEnergieRecquis())
        {
            std::cout << "Attaque 1 : " << joueur->getCreatureActive()->getAttaque1()->getNom() << std::endl;
            std::cout << "Description : " << joueur->getCreatureActive()->getAttaque1()->getDescription() << std::endl;
        }
        if (joueur->getCreatureActive()->getPointsEnergieEG() >= joueur->getCreatureActive()->getAttaque2()->getPointsEnergieRecquis())
        {
            std::cout << "Attaque 2 : "  << joueur->getCreatureActive()->getAttaque2()->getNom() << std::endl;
            std::cout << "Description : " << joueur->getCreatureActive()->getAttaque2()->getNom() << std::endl;
        }
        std::cout << std::endl;

    }

    if (joueur->getCreatureActive()->getAttaque1()->getTypeEnergieRecquis()=="G")
    {
        if (joueur->getCreatureActive()->getPointsEnergieG() < joueur->getCreatureActive()->getAttaque1()->getPointsEnergieRecquis())
        {
            std::cout << "Aucune" << std::endl;
        }
        if(joueur->getCreatureActive()->getPointsEnergieG() >= joueur->getCreatureActive()->getAttaque1()->getPointsEnergieRecquis())
        {
            std::cout << "Attaque 1 : " << joueur->getCreatureActive()->getAttaque1()->getNom() << std::endl;
            std::cout << "Description : " << joueur->getCreatureActive()->getAttaque1()->getDescription() << std::endl;
        }
        if (joueur->getCreatureActive()->getPointsEnergieG() >= joueur->getCreatureActive()->getAttaque2()->getPointsEnergieRecquis())
        {
            std::cout << "Attaque 2 : "  << joueur->getCreatureActive()->getAttaque2()->getNom() << std::endl;
            std::cout << "Description : " << joueur->getCreatureActive()->getAttaque2()->getNom() << std::endl;
        }
        std::cout << std::endl;
    }

    if (joueur->getCreatureActive()->getAttaque1()->getTypeEnergieRecquis()=="C")
    {
        if (joueur->getCreatureActive()->getPointsEnergieC() < joueur->getCreatureActive()->getAttaque1()->getPointsEnergieRecquis())
        {
            std::cout << "Aucune" << std::endl;
        }
        if(joueur->getCreatureActive()->getPointsEnergieC() >= joueur->getCreatureActive()->getAttaque1()->getPointsEnergieRecquis())
        {
            std::cout << "Attaque 1 : " << joueur->getCreatureActive()->getAttaque1()->getNom() << std::endl;
            std::cout << "Description : " << joueur->getCreatureActive()->getAttaque1()->getDescription() << std::endl;
        }
        if (joueur->getCreatureActive()->getPointsEnergieC() >= joueur->getCreatureActive()->getAttaque2()->getPointsEnergieRecquis())
        {
            std::cout << "Attaque 2 : "  << joueur->getCreatureActive()->getAttaque2()->getNom() << std::endl;
            std::cout << "Description : " << joueur->getCreatureActive()->getAttaque2()->getNom() << std::endl;
        }
        std::cout << std::endl;
    }

    if (joueur->getCreatureActive()->getAttaque1()->getTypeEnergieRecquis()=="D")
    {
        if (joueur->getCreatureActive()->getPointsEnergieD() < joueur->getCreatureActive()->getAttaque1()->getPointsEnergieRecquis())
        {
            std::cout << "Aucune" << std::endl;
        }
        if(joueur->getCreatureActive()->getPointsEnergieD() >= joueur->getCreatureActive()->getAttaque1()->getPointsEnergieRecquis())
        {
            std::cout << "Attaque 1 : " << joueur->getCreatureActive()->getAttaque1()->getNom() << std::endl;
            std::cout << "Description : " << joueur->getCreatureActive()->getAttaque1()->getDescription() << std::endl;
        }
        if (joueur->getCreatureActive()->getPointsEnergieD() >= joueur->getCreatureActive()->getAttaque2()->getPointsEnergieRecquis())
        {
            std::cout << "Attaque 2 : "  << joueur->getCreatureActive()->getAttaque2()->getNom() << std::endl;
            std::cout << "Description : " << joueur->getCreatureActive()->getAttaque2()->getNom() << std::endl;
        }
        std::cout << std::endl;
    }

    if (joueur->getCreatureActive()->getAttaque1()->getTypeEnergieRecquis()=="ED")
    {
        if (joueur->getCreatureActive()->getPointsEnergieED() < joueur->getCreatureActive()->getAttaque1()->getPointsEnergieRecquis())
        {
            std::cout << "Aucune" << std::endl;
        }
        if(joueur->getCreatureActive()->getPointsEnergieED() >= joueur->getCreatureActive()->getAttaque1()->getPointsEnergieRecquis())
        {
            std::cout << "Attaque 1 : " << joueur->getCreatureActive()->getAttaque1()->getNom() << std::endl;
            std::cout << "Description : " << joueur->getCreatureActive()->getAttaque1()->getDescription() << std::endl;
        }
        if (joueur->getCreatureActive()->getPointsEnergieED() >= joueur->getCreatureActive()->getAttaque2()->getPointsEnergieRecquis())
        {
            std::cout << "Attaque 2 : "  << joueur->getCreatureActive()->getAttaque2()->getNom() << std::endl;
            std::cout << "Description : " << joueur->getCreatureActive()->getAttaque2()->getNom() << std::endl;
        }
        std::cout << std::endl;
    }
}

///-------------------------------------------VERIFIE SI L ATTAQUE EST DISPONIBLE------------------------------------------------------
///cette méthode est appelée après afficherAttaquesDispo
///Or afficherAttaquesDispo a déjà set les points d'énergie...
///on n'a plus qu'à vérifier si l'attaque choisie (choix) est valide, grâce aux getPointsEnergie
bool verifAttaque(int choix, Joueur* joueur)//retourne un booléen : true pour attaque ok, false pour attaque impossible
{
    bool valide;
    //le choix vaut FORCEMENT 1 ou 2

    if (choix==1) //Si le joueur a choisit l'attaque1
    {
        //Si attaque1 valide
        //valide=true
        //sinon
        //valide=false
        if (joueur->getCreatureActive()->getAttaque1()->getTypeEnergieRecquis()=="EG")
        {
            if (joueur->getCreatureActive()->getPointsEnergieEG() < joueur->getCreatureActive()->getAttaque1()->getPointsEnergieRecquis())
            {
                valide=false;
            }
            if(joueur->getCreatureActive()->getPointsEnergieEG() >= joueur->getCreatureActive()->getAttaque1()->getPointsEnergieRecquis())
            {
                valide=true;
            }
        }

        if (joueur->getCreatureActive()->getAttaque1()->getTypeEnergieRecquis()=="G")
        {
            if (joueur->getCreatureActive()->getPointsEnergieG() < joueur->getCreatureActive()->getAttaque1()->getPointsEnergieRecquis())
            {
                valide=false;
            }
            if(joueur->getCreatureActive()->getPointsEnergieG() >= joueur->getCreatureActive()->getAttaque1()->getPointsEnergieRecquis())
            {
                valide=true;
            }
        }

        if (joueur->getCreatureActive()->getAttaque1()->getTypeEnergieRecquis()=="C")
        {
            if (joueur->getCreatureActive()->getPointsEnergieC() < joueur->getCreatureActive()->getAttaque1()->getPointsEnergieRecquis())
            {
                valide=false;
            }
            if(joueur->getCreatureActive()->getPointsEnergieC() >= joueur->getCreatureActive()->getAttaque1()->getPointsEnergieRecquis())
            {
                valide=true;
            }
        }

        if (joueur->getCreatureActive()->getAttaque1()->getTypeEnergieRecquis()=="D")
        {
            if (joueur->getCreatureActive()->getPointsEnergieD() < joueur->getCreatureActive()->getAttaque1()->getPointsEnergieRecquis())
            {
                valide=false;
            }
            if(joueur->getCreatureActive()->getPointsEnergieD() >= joueur->getCreatureActive()->getAttaque1()->getPointsEnergieRecquis())
            {
                valide=true;
            }
        }

        if (joueur->getCreatureActive()->getAttaque1()->getTypeEnergieRecquis()=="ED")
        {
            if (joueur->getCreatureActive()->getPointsEnergieED() < joueur->getCreatureActive()->getAttaque1()->getPointsEnergieRecquis())
            {
                valide=false;
            }
            if(joueur->getCreatureActive()->getPointsEnergieED() >= joueur->getCreatureActive()->getAttaque1()->getPointsEnergieRecquis())
            {
                valide=true;
            }
        }

    }
//-------------------------------------------------------------------------------------------------------------
    else //Si il choisit la 2ème on fait de même
    {
        //Si attaque2 valide
        //valide=true
        //sinon
        //valide=false
        if (joueur->getCreatureActive()->getAttaque2()->getTypeEnergieRecquis()=="EG")
        {
            if (joueur->getCreatureActive()->getPointsEnergieEG() < joueur->getCreatureActive()->getAttaque2()->getPointsEnergieRecquis())
            {
                valide=false;
            }
            if(joueur->getCreatureActive()->getPointsEnergieEG() >= joueur->getCreatureActive()->getAttaque2()->getPointsEnergieRecquis())
            {
                valide=true;
            }
        }

        if (joueur->getCreatureActive()->getAttaque2()->getTypeEnergieRecquis()=="G")
        {
            if (joueur->getCreatureActive()->getPointsEnergieG() < joueur->getCreatureActive()->getAttaque2()->getPointsEnergieRecquis())
            {
                valide=false;
            }
            if(joueur->getCreatureActive()->getPointsEnergieG() >= joueur->getCreatureActive()->getAttaque2()->getPointsEnergieRecquis())
            {
                valide=true;
            }
        }

        if (joueur->getCreatureActive()->getAttaque2()->getTypeEnergieRecquis()=="C")
        {
            if (joueur->getCreatureActive()->getPointsEnergieC() < joueur->getCreatureActive()->getAttaque2()->getPointsEnergieRecquis())
            {
                valide=false;
            }
            if(joueur->getCreatureActive()->getPointsEnergieC() >= joueur->getCreatureActive()->getAttaque2()->getPointsEnergieRecquis())
            {
                valide=true;
            }
        }

        if (joueur->getCreatureActive()->getAttaque2()->getTypeEnergieRecquis()=="D")
        {
            if (joueur->getCreatureActive()->getPointsEnergieD() < joueur->getCreatureActive()->getAttaque2()->getPointsEnergieRecquis())
            {
                valide=false;
            }
            if(joueur->getCreatureActive()->getPointsEnergieD() >= joueur->getCreatureActive()->getAttaque2()->getPointsEnergieRecquis())
            {
                valide=true;
            }
        }

        if (joueur->getCreatureActive()->getAttaque2()->getTypeEnergieRecquis()=="ED")
        {
            if (joueur->getCreatureActive()->getPointsEnergieED() < joueur->getCreatureActive()->getAttaque2()->getPointsEnergieRecquis())
            {
                valide=false;
            }
            if(joueur->getCreatureActive()->getPointsEnergieED() >= joueur->getCreatureActive()->getAttaque2()->getPointsEnergieRecquis())
            {
                valide=true;
            }
        }
    }

    return valide;
}

///--------------------------------------------------------TOUR DE JEU-----------------------------------------------------------------
void tourDeJeu(Joueur* joueur, Joueur* joueurCible) //joueur cible est utile lorsqu'on veut attaquer l'adversaire
{
    std::cout << std::endl;
    std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "TOUR DE " << joueur->getNom() << std::endl;
    ///le joueur pioche une carte de son deck (c'est toujours celle qui est en tête)
    std::cout << "Carte en tete..." << std::endl;
    Carte* cartePiochee = new Carte;
    cartePiochee = joueur->getClasseCollec()->GetDeck().front();

    ///on affiche son nom et sa description
    std::cout << cartePiochee->getNom() << std::endl;
    std::cout << "Description : " << cartePiochee->getDescription() << std::endl << std::endl;


    ///RAPPEL IMPORTANT : chaque fois qu'une carte est piochée, qu'elle soit jouée ou refusée, elle est retirée du deck
    ///on retire la carte piochée du deck
    joueur->getClasseCollec()->RetirerCarteDeck(cartePiochee);




    ///En fonction du type de la carte piochée, on demande au joueur des actions :

    ///si c'est une carte Spéciale :
    if (cartePiochee->getType()=="Speciale")
    {
        if(joueur->getSpecialeActive()==NULL)//si pas de spéciale active
        {
            std::cout << "Vous n avez pas de speciale active sur le Terrain..." << std::endl;
        }

        else //si il y a déjà une carte spéciale active
        {
           std::cout << "Vous avez deja " << joueur->getSpecialeActive()->getNom() << " active sur le terrain." << std::endl;
        }

        std::cout << "Voulez vous jouer " << cartePiochee->getNom() << " ?" << std::endl;
        std::cout << "Son effet : " << cartePiochee->getDescription() << std::endl;
        std::cout << "1)Oui" << std::endl << "2)Non" << std::endl;
        std::cout << "Note : Si vous jouez la carte alors que vous avez deja une speciale active, vous la remplacerez.." << std::endl;
        std::cout << "Si la carte speciale remplacee est recyclable elle va au fond du deck, sinon elle part au cimetiere" << std::endl;

        int choix=0;
        while (choix!=1 && choix!=2)
        {
            std::cout << "Saisir 1 ou 2" << std::endl;
            std::cin >> choix;
            if (choix==1)
            {//on joue la carte...
                if(joueur->getSpecialeActive()!=NULL)//si il y a déjà une carte spéciale active...
                {
                    //on remplace la carte spéciale active, qui part au cimetiere...
                    joueur->ajouterAuCimetiere(joueur->getSpecialeActive());

                    //et la nouvelle devient la spéciale active
                    joueur->setSpecialeActive(cartePiochee);
                }

                else //si pas de spéciale active...
                {
                    //la carte piochée devient directement la spéciale active
                    joueur->setSpecialeActive(cartePiochee);
                }

            }
            else
            {
                //la carte piochée part au cimetière et la carte déjà active le reste
                joueur->ajouterAuCimetiere(cartePiochee);
            }
        }
    }

    ///Si c'est une carte Energie :
    if (cartePiochee->getType()=="Energie")
    {
        std::cout << "Vous avez pioche une carte Energie, elle restera sur le terrain tout le long de la partie (vous pouvez reutiliser les energies)." << std::endl;
        std::cout << "Carte Energie piochee : " << cartePiochee->getNom() << std::endl;
        std::cout << "Description : " << cartePiochee->getDescription() << std::endl;

        //on l'ajoute au vecteur de Carte* EnergiesActives
        joueur->ajouterAuxEnergiesActives(cartePiochee); //de cette manière elle sera affichée avec les autres au tour suivant
    }


    ///Si c'est une carte Créature
    if (cartePiochee->getType()=="Creature")
    {

        if(joueur->getCreatureActive()==NULL)//si il n'y a pas deja une Créature sur le Terrain...
        {
            std::cout << "Vous n avez pas de Creature sur le Terrain actuellement. Celle ci sera donc automatiquement jouee!" << std::endl;

            //la carte Créature piochée devient alors la carte Créature active :
            if (cartePiochee->getNom()=="Melenchon")
            {
                cartePiochee = new Melenchon();
            }
            if (cartePiochee->getNom()=="Marchais")
            {
                cartePiochee= new Marchais();
            }
            if (cartePiochee->getNom()=="Hamon")
            {
                cartePiochee = new Hamon();
            }
            if (cartePiochee->getNom()=="Hollande")
            {
                cartePiochee = new Hollande();
            }
            if (cartePiochee->getNom()=="Macron")
            {
                cartePiochee = new Macron();
            }
            if (cartePiochee->getNom()=="Lassalle")
            {
                cartePiochee = new Lassalle();
            }
            if (cartePiochee->getNom()=="Fillon")
            {
                cartePiochee = new Fillon();
            }
            if (cartePiochee->getNom()=="Sarkozy")
            {
                cartePiochee = new Sarkozy();
            }
            if (cartePiochee->getNom()=="JMLepen")
            {
                cartePiochee = new JMLepen();
            }
            if (cartePiochee->getNom()=="MLepen")
            {
                cartePiochee = new MLepen();
            }

            joueur->setCreatureActive(cartePiochee);
            std::cout<< "Vie restante : " << joueur->getCreatureActive()->getVie()<<std::endl;
        }

        else //si il y a déjà une créature active...
        {
            int choix=0; //on le met à 0 pour qu'au prochain tour de boucle, on rentre dans le while et on redemande la saisie
            std::cout << joueur->getCreatureActive()->getNom() << " est deja sur le terrain, voulez vous la remplacer ?" << std::endl;
            std::cout << "1)Oui" << std::endl << "2)Non" << std::endl;
            while (choix!=1 && choix!=2)//blindage du choix
            {
                std::cout << "Saisir 1 ou 2" << std::endl;
                std::cin >> choix;
                if (choix==1) //si on remplace la Créature active par la nouvelle...
                {
                    std::cout << "l ancienne créature part au cimetière...";
                    joueur->ajouterAuCimetiere(joueur->getCreatureActive());

                    std::cout << "et " << cartePiochee->getNom() << " devient la créature active !" << std::endl;
                    joueur->setCreatureActive(cartePiochee);

                    //Et le nombre de créatures dispos dans le deck du joueur diminue de 1
                    joueur->setNbCreaturesDispo(joueur->getNbCreaturesDispo()-1);
                }
                else //Si on la refuse..
                {
                    //la nouvelle carte créature part au cimetière...
                    std::cout << cartePiochee->getNom() << " part au cimetiere...";
                    joueur->ajouterAuCimetiere(cartePiochee);

                    //l'ancienne reste sur le terrain
                    std::cout << "et " << joueur->getCreatureActive()->getNom() << " reste sur le terrain !" << std::endl;

                    //Et le nombre de créatures dispos dans le deck du joueur diminue de 1
                    joueur->setNbCreaturesDispo(joueur->getNbCreaturesDispo()-1);
                }
            }
        }



    }

    ///Une fois que la carte est piochée et qu'on demande l'action au joueur, on lui demande si il veut Attaquer ou Défendre
    if (joueur->getCreatureActive()!=NULL)
    {
        std::cout << "Souhaitez vous attaquer ou defendre ?" << std::endl;
        afficherAttaquesDispo(joueur); //affiche les attaques disponibles en fonction des énergies actives
        std::cout << "1)Attaquer" << std::endl << "2)Defendre" << std::endl;

        int choix=0;

        while (choix!=1 && choix!=2)
        {
            std::cin >> choix;
            if (choix==1) //si on attaque
            {
                //les attaques dispos étant affichées...

                std::cout << "Quelle attaque voulez vous effectuer ?" << std::endl;
                std::cout << "1)Attaque1" << std::endl << "2)Attaque2" << std::endl << "3)Aucune : se defendre" << std::endl;
                int choix2=0;

                while (choix2!=1 && choix2!=2 && choix2!=3)
                {
                    std::cout << "Saisir 1, 2 ou 3" << std::endl;
                    std::cin >> choix2;

                    if (choix2==1) //si attaque1
                    {
                        if (verifAttaque(choix2, joueur)==true)//si l'attaque1 est valide
                        {
                            //on attaque
                            //le joueur attaque le joueurCible, ou du moins sa carte créature, qui perd des points de vie
                            joueur->getCreatureActive()->attaquer(joueurCible->getCreatureActive(), joueur->getCreatureActive()->getAttaque1());

                            if(joueurCible->getCreatureActive()->getVie() <= 0) //si la créature cible meurt
                            {
                                std::cout << "Les points de vie de " << joueurCible->getCreatureActive()->getNom() << " adverse tombent a 0 !" << std::endl;
                                std::cout << "La creature adverse meurt et part au cimetiere, bien joue ! Un ennemi en moins!" << std::endl;

                                //elle part au cimetière
                                joueurCible->ajouterAuCimetiere(joueur->getCreatureActive());

                                //le nombre de créatures dispos de l'adversaire diminue
                                joueurCible->setNbCreaturesDispo(joueurCible->getNbCreaturesDispo()-1);

                                //le joueur adverse n'a plus de créature active
                                joueurCible->setCreatureActive(NULL);

                                //et le joueur adverse prend les dégats restants en fonctions des pv négatifs de sa créature
                                //si sa créature a 0 pv il ne perd rien, évidemment
                                joueurCible->recevoirDegats();
                            }
                        }

                        else  //sinon
                        {
                            //on attaque pas car si l'attaque1 n'est pas possible, la 2ème ne l'est pas non plus
                            std::cout << "Vous ne pouvez pas attaquer, vous n avez pas de point d energie dans le type recquis de cette attaque" << std::endl;

                            //et le choix2 passe à 3 pour aller dans le 3e cas, pour ensuite defendre
                            std::cout << "Vous etes contraint de defendre" << std::endl;
                            choix2=3;
                        }

                    }

                    if (choix2==2) //si attaque2
                    {
                        if (verifAttaque(choix2, joueur)==true)//si l'attaque2 est valide
                        {
                            //on attaque
                            //le joueur attaque le joueurCible, ou du moins sa carte créature, qui perd des points de vie
                            joueur->getCreatureActive()->attaquer(joueurCible->getCreatureActive(), joueur->getCreatureActive()->getAttaque2());

                            if(joueurCible->getCreatureActive()->getVie() <= 0) //si la créature cible meurt
                            {
                                std::cout << "Les points de vie de " << joueurCible->getCreatureActive()->getNom() << " adverse tombent a 0 !" << std::endl;
                                std::cout << "La creature adverse meurt et part au cimetiere, bien joue ! Un ennemi en moins!" << std::endl;

                                //elle part au cimetière
                                joueurCible->ajouterAuCimetiere(joueur->getCreatureActive());

                                //le nombre de créatures dispos de l'adversaire diminue
                                joueurCible->setNbCreaturesDispo(joueurCible->getNbCreaturesDispo()-1);

                                //le joueur adverse n'a plus de créature active
                                joueurCible->setCreatureActive(NULL);

                                //et le joueur adverse prend les dégats restants en fonctions des pv négatifs de sa créature
                                //si sa créature a 0 pv il ne perd rien, évidemment
                                joueurCible->recevoirDegats();
                            }
                        }

                        else  //sinon
                        {
                            //on ne peut pas utiliser l'attaque2
                            std::cout << "Vous ne pouvez pas utiliser l attaque2" << std::endl;

                            //et le choix2 passe à 4, pour refaire un tour de boucle et resaisir 1, 2 ou 3
                            choix2=4;
                        }
                    }

                    else //si "aucune : se défendre"
                        choix=2; //permet de sortir du if attaquer et aller dans le else qui gère la défense
                }


            }

            else //si défense
            {
                //la défense est identique pour toutes les créatures et ne nécessite pas de point d'énergie
                joueur->getCreatureActive()->seDefendre(joueur->getCreatureActive()->getDefense1());
            }
        }
    }



}


///---------------------------------------------------FONCTION JOUER-------------------------------------------------------------------
/*
///fonction de test (un seul joueur pour aller plus vite)
void jouer(Joueur* joueur)
{
    ///on commence par mélanger le deck des deux joueurs
    joueur->getClasseCollec()->MelangerDeck();
    //on affiche le deck pour voir si le mélange a été fait
    joueur->getClasseCollec()->afficherDeck();
}
*/

void jouer(Joueur* joueur1, Joueur* joueur2)
{
    ///on commence par mélanger le deck des deux joueurs
    joueur1->getClasseCollec()->MelangerDeck();
    joueur2->getClasseCollec()->MelangerDeck();
    //Test d'affichage pour voir si le deck est mélangé
    //joueur1->getClasseCollec()->afficherDeck();

    ///Le joueur qui commence est choisi aléatoirement
    std::cout << "Vos 2 decks ont ete melanges ! Voyons qui va commencer..." << std::endl;
    srand(time(NULL));
    int x = rand()%(2-1+1)+1; //(max - min +1) + min, ici entre 1 et 2
    Joueur* joueurTemporaire = new Joueur;

    if (x==2) //si on tombe sur 2, le joueur 2 commence, et on le fait devenir joueur1 pour ne pas gêner l'ordre de jeu de la fonction
    {
        joueurTemporaire=joueur1;
        joueur1=joueur2;            //on inverse les 2 joueurs avec une variable temporaire
        joueur2=joueurTemporaire;
    }

    std::cout << "C est " << joueur1->getNom() << " qui commence !" << std::endl << std::endl;

    ///L'enjeu (la carte de l'adversaire à gagner en cas de victoire) est choisie aléatoirement pour les 2 joueurs
    choixCarteEnjeu(joueur1);
    choixCarteEnjeu(joueur2);
    std::cout << std::endl;

    ///ON PEUT ENFIN COMMENCER LA PARTIE !!!!!!!!
    std::cout << "Maintenant que vous avez chacun votre deck melange, vous pouvez commencer la partie !" << std::endl;
    std::cout << "Pour rappel, un joueur perd lorsqu'il n'a plus de points de vie ou qu'il n'a plus de cartes creatures sur le terrain" << std::endl;
    std::cout << "Le gagnant remportera la carte enjeu de l adversaire et l ajoutera a sa collection !!" << std::endl;
    std::cout << "Vous etes prets ? C est parti !" << std::endl;
    std::cout << std::endl;

    ///initialisations
    initaliserJoueur(joueur1);
    initaliserJoueur(joueur2);

    ///BOUCLE DE JEU
    while(joueur1->getVie()>0 && joueur2->getVie()>0 && joueur1->getNbCreaturesDispo()>0 && joueur2->getNbCreaturesDispo()>0)
    {
        ///Défiler pour avoir une creature active à chaque début de tour
        defileJusquaCrea(joueur1);
        defileJusquaCrea(joueur2);


        ///Afficher le terrain des 2 joueurs (vie du joueur, carte crea active, les Energies posées et la potentielle Spéciale active.)
        afficherTerrain(joueur1);
        afficherTerrain(joueur2);
        std::cout << std::endl;

        ///tourDeJeu(Joueur1); le joueur 2 est le joueurCible
        tourDeJeu(joueur1, joueur2);

        ///Après le tour du joueur 1, il se peut que le j1 ait tué la cré du j2 (ou creature de j1 se soit os), donc on refait le check, est ce que j1 et j2 ont des créatures actives
        //On appelle la même méthode qu'au début du while
        defileJusquaCrea(joueur1);
        defileJusquaCrea(joueur2);

        ///tourDeJeu(Joueur2); le joueur 1 est le joueurCible
        tourDeJeu(joueur2, joueur1);
        std::cout <<std::endl;
        std::cout <<"----------------------------------------TOUR SUIVANT-----------------------------------------------" << std::endl;

    }

    ///Afficher le gagnant, et gérer la carte enjeu du perdant
    std::cout << "LA PARTIE EST TERMINEE !!!" << std::endl;
    if (joueur1->getNbCreaturesDispo()==0 || joueur1->getVie()<=0) //si le j1 perd
    {
        //j2 est le gagnant
        std::cout << joueur2->getNom() << " , vous remportez la partie, BRAVO ! Vous gagnez donc la carte enjeu de l adversaire !" << std::endl;
        ///Gérer la carte enjeu du perdant
        //on a tiré au sort la carte enjeu de chaque joueur, qui a été set dans l'attribut carteEnjeu de chacun
        //donc on doit juste la récup avec un get, afficher son nom et sa description, puis l'ajouter à la collec du gagnant

        //AJOUTER CARTE ENJEU DU PERDANT A LA COLLEC DU GAGNANT
        std::cout << "La carte enjeu de " << joueur1->getNom() <<" etait " << joueur1->getCarteEnjeu()->getNom() <<
                  " ! Vous l ajoutez a votre collection !" << std::endl;
        joueur2->getClasseCollec()->AjouterCarteCollec(joueur1->getCarteEnjeu());

        //RETIRER L ENJEU DU PERDANT DE SA COLLECTION
        joueur1->getClasseCollec()->RetirerCarteCollec(joueur1->getCarteEnjeu());


    }
    else //le contraire, on inverse juste les joueur1 / joueur2
    {
        std::cout << joueur1->getNom() << " , vous remportez la partie, BRAVO ! Vous gagnez donc la carte enjeu de l adversaire !" << std::endl;
        ///Gérer la carte enjeu du perdant
        //on a tiré au sort la carte enjeu de chaque joueur, qui a été set dans l'attribut carteEnjeu de chacun
        //donc on doit juste la récup avec un get, afficher son nom et sa description, puis l'ajouter à la collec du gagnant

        //AJOUTER CARTE ENJEU DU PERDANT A LA COLLEC DU GAGNANT
        std::cout << "La carte enjeu de " << joueur2->getNom() <<" etait " << joueur2->getCarteEnjeu()->getNom() <<
                  " ! Vous l ajoutez a votre collection !" << std::endl;
        joueur1->getClasseCollec()->AjouterCarteCollec(joueur2->getCarteEnjeu());

        //RETIRER L ENJEU DU PERDANT DE SA COLLECTION
        joueur2->getClasseCollec()->RetirerCarteCollec(joueur2->getCarteEnjeu());

    }

    //MAJ DU FICHIER COLLECTION DES POUR CHAQUE JOUEUR (on écrase l'ancien fichier nomjoueur.txt pour les 2 joueurs,
    //puis on écrit la collec actuelle). Le gagnant aura 1 carte de plus, le perdant 1 carte de moins
    //ON COMMENCE PAR TRIER LES CARTES PAR NUMERO EN FONCTION DE LEUR NOM POUR AVOIR UN BEL AFFICHAGE A LA PROCHAINE PARTIE
    std::vector<int> tableauDeNumeros;
    for (auto &elem : joueur1->getClasseCollec()->GetCollection()) //on parcourt la collection mise à jour pour l'accès aux noms de cartes
    {
        int numero;

        if(elem->getNom()=="Melenchon")
        {
            numero=1;
        }
        if(elem->getNom()=="Marchais")
        {
            numero=2;
        }
        if(elem->getNom()=="Hamon")
        {
            numero=3;
        }
        if(elem->getNom()=="Hollande")
        {
            numero=4;
        }
        if(elem->getNom()=="Macron")
        {
            numero=5;
        }
        if(elem->getNom()=="Lassalle")
        {
            numero=6;
        }
        if(elem->getNom()=="Fillon")
        {
            numero=7;
        }
        if(elem->getNom()=="Sarkozy")
        {
            numero=8;
        }
        if(elem->getNom()=="JMLepen")
        {
            numero=9;
        }
        if(elem->getNom()=="MLepen")
        {
            numero=10;
        }
        if(elem->getNom()=="Extreme Gauche")
        {
            numero=11;
        }
        if(elem->getNom()=="Gauche")
        {
            numero=12;
        }
        if(elem->getNom()=="Centre")
        {
            numero=13;
        }
        if(elem->getNom()=="Droite")
        {
            numero=14;
        }
        if(elem->getNom()=="Extreme Droite")
        {
            numero=15;
        }
        if(elem->getNom()=="Kamikaze")
        {
            numero=16;
        }
        if(elem->getNom()=="BoostVie")
        {
            numero=17;
        }
        if(elem->getNom()=="BoostDef")
        {
            numero=18;
        }
        if(elem->getNom()=="BoostAttaque")
        {
            numero=19;
        }
        if(elem->getNom()=="Attaquex2")
        {
            numero=20;
        }
        if(elem->getNom()=="Renvoi")
        {
            numero=21;
        }

        tableauDeNumeros.push_back(numero);
    }

    sort(tableauDeNumeros.begin(), tableauDeNumeros.end()); //on trie les numéros pour afficher les cartes dans l'ordre

    //On sauvegarde la nouvelle collec triée en écrasant l'ancien fichier : on réécrit le nom des cartes dans l'ordre dans le fichier
    std::string nomFichier=joueur1->getNom()+".txt";
    std::ofstream Flux(nomFichier.c_str());//ouverture du fichier en écriture

    if(Flux)  //On teste si tout est OK
    {
        //on parcourt le tableauDeNuméros et on écrit les noms de cartes, en fonction de leur num, dans le fichier
        for (auto &elem : tableauDeNumeros)
        {
            if (elem==1)
            {
                Flux<<"Melenchon"<<std::endl;
            }
            if (elem==2)
            {
                Flux<<"Marchais"<<std::endl;
            }
            if (elem==3)
            {
                Flux<<"Hamon"<<std::endl;
            }
            if (elem==4)
            {
                Flux<<"Hollande"<<std::endl;
            }
            if (elem==5)
            {
                Flux<<"Macron"<<std::endl;
            }
            if (elem==6)
            {
                Flux<<"Lassalle"<<std::endl;
            }
            if (elem==7)
            {
                Flux<<"Fillon"<<std::endl;
            }
            if (elem==8)
            {
                Flux<<"Sarkozy"<<std::endl;
            }
            if (elem==9)
            {
                Flux<<"Jean-Marie Lepen"<<std::endl;
            }
            if (elem==10)
            {
                Flux<<"Marine Lepen"<<std::endl;
            }
            if (elem==11)
            {
                Flux<<"Extreme Gauche"<<std::endl;
            }
            if (elem==12)
            {
                Flux<<"Gauche"<<std::endl;
            }
            if (elem==13)
            {
                Flux<<"Centre"<<std::endl;
            }
            if (elem==14)
            {
                Flux<<"Droite"<<std::endl;
            }
            if (elem==15)
            {
                Flux<<"Extreme Droite"<<std::endl;
            }
            if (elem==16)
            {
                Flux<<"Kamikaze"<<std::endl;
            }
            if (elem==17)
            {
                Flux<<"BoostVie"<<std::endl;
            }
            if (elem==18)
            {
                Flux<<"BoostDef"<<std::endl;
            }
            if (elem==19)
            {
                Flux<<"BoostAttaque"<<std::endl;
            }
            if (elem==20)
            {
                Flux<<"Attaquex2"<<std::endl;
            }
            if (elem==21)
            {
                Flux<<"Renvoi"<<std::endl;
            }

        }


    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }


    //-------------------------------------------------------2EME JOUEUR------------------------------------------------------------

    std::vector<int> tableauDeNumeros2;
    for (auto &elem : joueur2->getClasseCollec()->GetCollection()) //on parcourt la collection mise à jour pour l'accès aux noms de cartes
    {
        int numero;

        if(elem->getNom()=="Melenchon")
        {
            numero=1;
        }
        if(elem->getNom()=="Marchais")
        {
            numero=2;
        }
        if(elem->getNom()=="Hamon")
        {
            numero=3;
        }
        if(elem->getNom()=="Hollande")
        {
            numero=4;
        }
        if(elem->getNom()=="Macron")
        {
            numero=5;
        }
        if(elem->getNom()=="Lassalle")
        {
            numero=6;
        }
        if(elem->getNom()=="Fillon")
        {
            numero=7;
        }
        if(elem->getNom()=="Sarkozy")
        {
            numero=8;
        }
        if(elem->getNom()=="JMLepen")
        {
            numero=9;
        }
        if(elem->getNom()=="MLepen")
        {
            numero=10;
        }
        if(elem->getNom()=="Extreme Gauche")
        {
            numero=11;
        }
        if(elem->getNom()=="Gauche")
        {
            numero=12;
        }
        if(elem->getNom()=="Centre")
        {
            numero=13;
        }
        if(elem->getNom()=="Droite")
        {
            numero=14;
        }
        if(elem->getNom()=="Extreme Droite")
        {
            numero=15;
        }
        if(elem->getNom()=="Kamikaze")
        {
            numero=16;
        }
        if(elem->getNom()=="BoostVie")
        {
            numero=17;
        }
        if(elem->getNom()=="BoostDef")
        {
            numero=18;
        }
        if(elem->getNom()=="BoostAttaque")
        {
            numero=19;
        }
        if(elem->getNom()=="Attaquex2")
        {
            numero=20;
        }
        if(elem->getNom()=="Renvoi")
        {
            numero=21;
        }

        tableauDeNumeros2.push_back(numero);
    }

    sort(tableauDeNumeros2.begin(), tableauDeNumeros.end()); //on trie les numéros pour afficher les cartes dans l'ordre

    //On sauvegarde la nouvelle collec triée en écrasant l'ancien fichier : on réécrit le nom des cartes dans l'ordre dans le fichier
    std::string nomFichier2=joueur2->getNom()+".txt";
    std::ofstream Flux2(nomFichier2.c_str());//ouverture du fichier en écriture

    if(Flux2)  //On teste si tout est OK
    {
        //on parcourt le tableauDeNuméros2 et on écrit les noms de cartes, en fonction de leur num, dans le fichier
        for (auto &elem : tableauDeNumeros)
        {
            if (elem==1)
            {
                Flux<<"Melenchon"<<std::endl;
            }
            if (elem==2)
            {
                Flux<<"Marchais"<<std::endl;
            }
            if (elem==3)
            {
                Flux<<"Hamon"<<std::endl;
            }
            if (elem==4)
            {
                Flux<<"Hollande"<<std::endl;
            }
            if (elem==5)
            {
                Flux<<"Macron"<<std::endl;
            }
            if (elem==6)
            {
                Flux<<"Lassalle"<<std::endl;
            }
            if (elem==7)
            {
                Flux<<"Fillon"<<std::endl;
            }
            if (elem==8)
            {
                Flux<<"Sarkozy"<<std::endl;
            }
            if (elem==9)
            {
                Flux<<"Jean-Marie Lepen"<<std::endl;
            }
            if (elem==10)
            {
                Flux<<"Marine Lepen"<<std::endl;
            }
            if (elem==11)
            {
                Flux<<"Extreme Gauche"<<std::endl;
            }
            if (elem==12)
            {
                Flux<<"Gauche"<<std::endl;
            }
            if (elem==13)
            {
                Flux<<"Centre"<<std::endl;
            }
            if (elem==14)
            {
                Flux<<"Droite"<<std::endl;
            }
            if (elem==15)
            {
                Flux<<"Extreme Droite"<<std::endl;
            }
            if (elem==16)
            {
                Flux<<"Kamikaze"<<std::endl;
            }
            if (elem==17)
            {
                Flux<<"BoostVie"<<std::endl;
            }
            if (elem==18)
            {
                Flux<<"BoostDef"<<std::endl;
            }
            if (elem==19)
            {
                Flux<<"BoostAttaque"<<std::endl;
            }
            if (elem==20)
            {
                Flux<<"Attaquex2"<<std::endl;
            }
            if (elem==21)
            {
                Flux<<"Renvoi"<<std::endl;
            }

        }


    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }



    ///Retourner au menu -> se fait instantanément lorsque les conditions d'arrêt de la boucle de jeu sont remplies
}












