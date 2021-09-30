#include"tools.h"
#ifndef MENUE_H_INCLUDED
#define MENUE_H_INCLUDED

void Menue_Principale();
void TolotraModifSup();
void MenuValidation();
void SousMenu();
void rien();
void attendre();
void waitEnter();
void color(int couleurDuTexte);
void GetChoix();
void loko(char x);
void Turquoise(char *x);
void calcspace(char *chaine,int nbrcase);
void calcspacefile(char *chaine,int nbrcase,FILE *entre);
void initialisation();
void rose();
void r();
void bl();
void w();
void v();
void j();
void fr();
void Vertchar(char x);
void FondVerte();
void SousMenu_pret();
void bienvenue();
void beep ();
void gotoxy (short x, short y);
int saisie(char *ligne,size_t max);
void ecrire_space(int nb);
void balayer_ecran(short y,int nb);


#endif // MENUE_H_INCLUDED
