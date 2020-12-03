#include <iostream>
#include "fonctions.h"
#include <windows.h>

int main()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 2);//Le texte passe en vert
    std::cout << "REPUBLIMON" << std::endl;
    SetConsoleTextAttribute(hConsole, 7);//Le texte repasse en blanc

    Joueur* joueur1, joueur2;
    menu();
    return 0;
}
