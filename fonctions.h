#ifndef FONCTIONS_H
#define FONCTIONS_H
#include <iomanip>

/***********************
**  Contient les fonctions utilisees dans le jeux:
**
************************/


/*****
** les differents etats d'une cellule:
**
**************/
enum {morte=0, jeune=1};


/******************
**  Fonction pour initialiser l'aire de jeu:
**  Nom: init
**  Arguments: largeur = largeur de l'aire de jeu (nombre de colones de la matrice)
**             hauteur = hauteur de l'aire de jeu (nombre de lignes de la matrice)
*******************/
void init(int ** aire, int largeur, int hauteur){
    int i, j;

    for(i = 0; i < hauteur; ++i){
        for(j = 0; j < largeur; ++j){
            if(i == 5 && (j > 5 && j <= 8))
                aire[i][j] = morte;
        }
    }
    int midCol = (largeur/2)-3;
    int midLine = (hauteur/2)-4;
    aire[midLine][midCol] = jeune;
    aire[midLine+1][midCol] = jeune;

    aire[midLine+2][midCol] = jeune;
    aire[midLine+2][midCol+1] = jeune;
    aire[midLine+2][midCol+2] = jeune;

    aire[midLine][midCol+2] = jeune;
    aire[midLine+1][midCol+2] = jeune;

    //you have made me what i am and i am yours.
    //my love theres so many ways.... i love you
    aire[midLine+4][midCol+2] = jeune;
    aire[midLine+4][midCol] = jeune;
    aire[midLine+4][midCol+1] = jeune;

    aire[midLine-2][midCol+2] = jeune;
    aire[midLine-2][midCol] = jeune;
    aire[midLine-2][midCol+1] = jeune;
}



/******************
**  Fonction pour connaitre le nombre de voisins
**  vivants d'une cellule.
**
**  Nom:    voisinsVivants
**  Arguments:
**              colone = le numero de colone de la cellule cible.
**              ligne = le numero de ligne de la cellule cible.
**              aire =   l'aire de jeu
**              largeur = la largeur de l'aire de jeu.
**              hauteur = la hauteur de l'aire de jeu.
**
**  Retour: Le nombre de cellules etant dans un etat different de mort.
**
*******************/
int voisinsVivants(int ligne, int colonne , int **aire){
    int nbCellules = 0;

    for(int i = ligne-1; (i < (ligne+2)); ++i){
        for(int j = colonne-1; (j < (colonne+2)); ++j){
            if(!(i == ligne && j == colonne) && aire[i][j] != morte)
                ++nbCellules;
        }
    }
    return nbCellules;
}

/******************
**  Fonction pour faire evoluer les cellules et
**  mettre a jour l'affichage.
**
**
*******************/

void update(int **aire, int largeur, int hauteur)
{
    int compteur;
    for(int i = 1; i < hauteur; ++i){
        for(int j = 1; j < largeur; ++j){
            compteur = voisinsVivants(i, j, aire); //verifier l'etat des voisin de chaque cellule

            if(aire[i][j] == morte){
                if(compteur == 3)
                    aire[i][j] = jeune;  //naissance d'une cellule.
            }
            else if(compteur != 2 && compteur != 3) //une cellule vivante n'ayant ni 2 ni 3 voisines vivantes doit mourir.
                    aire[i][j] = morte;
        }
    }
}


/**********************
**  Fonction pour afficher l'aire de jeu:
**
**  Nom: afficherAireDeJeu
**  Arguments: aire =  L'aire de jeu.
**             largeur = la largeur de l'aire de jeu.
**             hauteur = la hauteur de l'aire de jeu.
**
**
************************/

void afficherAireDeJeu(int **aire, int largeur, int hauteur){
    for(int i = 0; i < hauteur; ++i){
        for(int j = 0; j < largeur; j++){
            if(aire[i][j] == 0)
                std::cout << std::setw(2) << ' ';
            else
            std::cout << std::setw(2) << '@';//aire[i][j];
        }
        std::cout << '\n';
    }
}


#endif
