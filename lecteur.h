


#ifndef LECTEUR_H_INCLUDED
#define LECTEUR_H_INCLUDED

#include"tools.h"

typedef struct Membre Membre;
struct Membre
{
    int code;
    char nom[32];
    char prenom[32];
    char adresse[50];
    Membre *suivant;
};
void vidermembr();
void supprrmembre(Membre* mb);
void pushMembre(int code,char nom[32],char prenom[32],char adresse[50]);
void listerMembre();
Membre *rechercheMembre(int code);
void modifMembre(Membre *amodif);
void affichemembre(Membre *M);
void saisiemembre();
void enregistrerMembre();
void chargerMembre();
void consunmbre();
void sous_menue_membre();

#endif // LECTEUR_H_INCLUDED
