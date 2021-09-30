#include"tools.h"

extern char choix;

COORD  dwSize;
int main()
{
     dwSize.X=100;
    dwSize.Y=200;
/*reglage de la resolution*/
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),dwSize);
     SetConsoleTitle("BIBLIO MANAGING");
    chargerAuteur();
    chargerEditeur();
    chargerlivre();
    chargerMembre();
    chargerOuvrage();
    chargerpret();
    androniany();
    bienvenue();

mainmenue:
fflush(stdin);
    Menue_Principale();
    fflush(stdin);
    GetChoix();
    switch (choix)
    {
        case '1':
        {
            system("cls");
            menue_ouvrage();
            goto mainmenue;
        }break;

        case '3':
        {
            system("cls");
            sous_menue_membre();
        goto mainmenue;}
        break;

        case '2':
        {
            system("cls");
            menue_auteur();
        goto mainmenue;}
        break;

        case '4':
        {menue_livre();
        goto mainmenue;}
        break;

        case '5':
        {
            system("cls");
            menue_editeur();goto mainmenue;}
        break;

        case '6':
        {
            system("cls");
            pret();goto mainmenue;}
        break;

        case '7':
        exit(0);
        break;
        default:
        r();printf("\n\n\t VEUILLEZ SAISIR LA TOUCHE APPROPRIEE");waitEnter();
        goto mainmenue;break;
    }

    return 0;
}
