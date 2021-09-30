#include"tools.h"

#ifndef LIVRE_H_INCLUDED
#define LIVRE_H_INCLUDED

typedef struct livre livre;
struct livre
{
    int cote;
    int codeOuvrSourc;
    char titre[50];
    char sujet[50];
    char editeur[50];
    int anneeEdition;
    livre *suivant;
};
void viderlivre();
void supprlivre(livre* L);
void affichelivre(livre *L);
void listerlivre();
livre *rechercheLivre(int cote);
void modiflivre(livre *amodif);
void pushlivre(int cote,int codeouvsrc,char titre[50],char sujet[50],char editeur[50],int anneEd);
void saisielivre();
void enregistrerlivre();
void chargerlivre();
void consuLivre();
void menue_livre();


#endif // LIVRE_H_INCLUDED
