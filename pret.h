#include"tools.h"

#ifndef PRET_H_INCLUDED
#define PRET_H_INCLUDED

//typedef struct tm daty;

typedef struct andro andro; //cette varriable facilite le calcul des dates
struct andro
{
    int jour;
    int mois;
    int annee;
};

typedef struct Pret Pret;
struct Pret
{
    int code;
    int cotelivre;
    int codelecteur;
    andro datePret;
    andro dateRetourPrev;
    andro dateRetourEff;
    int etat;
    Pret *suivant;
};

andro calcret(andro today);
void viderpret();
void supprrpretpret(Pret* P);
void affichepret(Pret *P);
void listerpret( );
Pret *recherchepret(int code);
Pret *recherchePretparlect(int codelect);
Pret *recherchePretparlivre(int cote);
void modifpret(Pret *P);

void pushPret(int code,int clect,int clivre,andro dateP,andro dateRp,andro dateRE,int etat);

void saisiepret();
void enregistrerpret();
void chargerpret();
void consupret();
void pret();



#endif // PRET_H_INCLUDED
