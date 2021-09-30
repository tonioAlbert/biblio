#include"tools.h"

#ifndef EDITEUR_H_INCLUDED
#define EDITEUR_H_INCLUDED

typedef struct Editeur Editeur;
struct Editeur
{
    char RaisonSociale[50];
    char adresse[50];
    Editeur *suivant;
};
void viderEditeur();
void supprrEditeur(Editeur* E);
void afficheEditeur(Editeur *E);
void listerEditeur();
Editeur *rechercheEditeur(char *boutraison);
void modifEditeur(Editeur *amodif);
void pushEditeur(char RaisonSociale[50],char adresse[50]);
void saisieEditeur();
void enregistrerEditeur();
void chargerEditeur();
void consuEditeur();
void menue_editeur();


#endif // EDITEUR_H_INCLUDED
