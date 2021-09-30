#include"tools.h"

#ifndef OUVRAGE_H_INCLUDED
#define OUVRAGE_H_INCLUDED
typedef struct ouvrage ouvrage;
struct ouvrage
{
    int code;
    int codeaut;
    char titre[50];
    char sujet[50];
    ouvrage *suivant;
};
void viderOuvrage();
void supprrOuvrage(ouvrage* o);
void afficheOuvrage(ouvrage *O);
void listerOuvrage();
void listerOuvrageParAuteur(int code);
ouvrage *rechercheOuvrage(int code);
void modifOuvrage(ouvrage *amodif);
void pushOuvrage(int code,int codeaut,char titre[50],char sujet[50]);
void saisieOuvrage();
void enregistrerOuvrage();
void chargerOuvrage();
void consuOuvrage();
void menue_ouvrage();


#endif // OUVRAGE_H_INCLUDED
