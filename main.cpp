#include <iostream>
#include <cstdlib>
#include <chrono>
#include <ratio>
#include "fonctions.h"   //Contient les fonctions et les types utilisEes.

/********************
**  Programme: Le jeu de la vie de Conway?
**
**  version: 1.0b
**  Auteur: Youssouf
**  Date: 26-03-2014(01:) 27-03-2014 (01:)
**
** Contact: nzomedia2@gmail.com
**  TODO: faire des tests et optimiser.
************************/

using namespace std;

int main()
{
    const int largeurAireDeJeu = 45;
    const int hauteurAireDeJeu = 35;
    int **aireDeJeu;
    aireDeJeu = (int **)malloc(sizeof(int *)*hauteurAireDeJeu);
    for(int i = 0; i < hauteurAireDeJeu; ++i)
            aireDeJeu[i] = (int *)malloc(sizeof(int)*largeurAireDeJeu);

    system("clear");
    std::cout << "######### Jeu de la vie #######\n\n";
    init(aireDeJeu, largeurAireDeJeu, hauteurAireDeJeu);

    using std::chrono::system_clock;
    system_clock::time_point debut = system_clock::now();
    chrono::duration<int, ratio<1> > duree(180);  //duree de l'animation en secondes.
    system_clock::time_point fin = debut + duree;

    std::chrono::microseconds chron;

    do{
    system("clear");
    afficherAireDeJeu(aireDeJeu, largeurAireDeJeu, hauteurAireDeJeu);
    usleep(33333);  //30ips
    update(aireDeJeu, largeurAireDeJeu-1, hauteurAireDeJeu-1);

    chron = system_clock::now() - debut;
    std::cout << "\nDepuis " << chron.count()/1000000 << " secondes.\n";
    }
    while(system_clock::now() < fin);
    return 0;
}
