#include"tools.h"
#ifndef AUTEUR_H_INCLUDED
#define AUTEUR_H_INCLUDED

typedef struct auteur auteur;
struct auteur
{
    int code;
    char nom[32];
    char prenom[32];
    char adresse[100];
    auteur *suivant;
};



void viderauteur();
void supprrAuteur(auteur* a);
void afficheAuteur(auteur *A);
void listerAureur( );
auteur *rechercheAuteur(int code);
void modifAuteur(auteur *amodif);
void pushAuteur(int code,char nom[32],char prenom[32],char adresse[100]);
void saisieAuteur();
void enregistrerAuteur();
void chargerAuteur();
void consuAuteur();
void menue_auteur();



#endif // AUTEUR_H_INCLUDED
