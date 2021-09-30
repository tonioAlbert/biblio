#include"tools.h"


void Menue_Principale()
{
    int i;
    system("cls"); w();
    printf("\n\n");
    printf("\t\t\t       +-------------------------------+\n");
    printf("\t\t\t       |");color(27);printf("       MENUE PRINCIPALE        ");w();printf("|\n");
    printf("\t\t\t       +-------------------------------+\n");
    printf("\n\n\t\t\t\t\xC9");
    for (i=0;i<29;i++)
    {
        printf("\xCD");
    }
    printf("\xBB\n");
    printf("\t\t\t\t\xBA                             \xBA\n");
    printf("\t\t\t\t\xBA   ");loko('1');printf("-OUVRAGE     ");loko('2');printf("-AUTEUR    \xBA\n");
    printf("\t\t\t\t\xBA                             \xBA\n");
    printf("\t\t\t\t\xBA   ");loko('3');printf("-LECTEUR     ");loko('4');printf("-LIVRE     \xBA\n");
    printf("\t\t\t\t\xBA                             \xBA\n");
    printf("\t\t\t\t\xBA   ");loko('5');printf("-EDITEUR     ");loko('6');printf("-PRET      \xBA\n");
    printf("\t\t\t\t\xBA                             \xBA\n");
    printf("\t\t\t\t\xBA          ");loko('7');printf("-QUITTER          \xBA\n");
    printf("\t\t\t\t\xC8");
    for (i=0;i<29;i++)
    {
        printf("\xCD");
    }
    printf("\xBC\n\n\t\t Choix : ");
}

void TolotraModifSup()
{
    printf("\n\n\n\n                                %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",0xC9,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xBB);
    printf("\n                                \xBA ");
    loko('M');
    printf("odifier     %c",0xBA);
    printf("\n                                \xBA ");
    loko('S');
    printf("upprimer    %c",0xBA);
    printf("\n                                \xBA ");
    loko('R');
    printf("etour       %c",0xBA);
    printf("\n                                %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",0xC8,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xBC);
    printf("\nChoix: ");
    fflush(stdin);
}

void MenuValidation()
{
    //system("cls");
    printf("\n\n\n\n                                %c%c%c%c%c%c%c%c%c%c%c%c",0xC9,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xBB);
    printf("\n                                \xBA ");
    Vertchar('V');
    printf("alider  %c",0xBA);
    printf("\n                                \xBA ");
    Vertchar('M');
    printf("odifier %c",0xBA);
    printf("\n                                \xBA ");
    Vertchar('A');
    printf("nnuler  %c",0xBA);
    printf("\n                                %c%c%c%c%c%c%c%c%c%c%c%c\n",0xC8,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xBC);
    printf("\nChoix: ");
}


void SousMenu()
{
    system("cls");w();
    printf("\n\n\n\n                                %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",0xC9,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xBB);
    printf("\n                                \xBA");
    v();printf("  1-creation     ");w();printf("%c",0xBA);
    printf("\n                                \xBA  2-C");

    printf("onsultation %c",0xBA);
    printf("\n                                \xBA");

    j();printf("  3-liste        ");w();printf("%c",0xBA);
    printf("\n                                \xBA ");

    printf(" 4-quitter      %c",0xBA);
    printf("\n                                %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",0xC8,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xBC);
    printf("\n              Choix: ");w();
}



void SousMenu_pret()
{
    system("cls");w();
    printf("\n\n\n\n                                %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",0xC9,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xBB);
    printf("\n                                \xBA");
    v();printf("  1-creation     ");w();printf("%c",0xBA);
    printf("\n                                \xBA  2-R");

    printf("estitution  %c",0xBA);
    printf("\n                                \xBA");

    j();printf("  3-liste        ");w();printf("%c",0xBA);
    printf("\n                                \xBA ");

    printf(" 4-quitter      %c",0xBA);
    printf("\n                                %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",0xC8,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xBC);
    printf("\n              Choix: ");w();
}

void rien()
{

}


void attendre()
{
    int i;
    printf("\n\n\n\n\n\n\t\t CHARGEMENT! ATTENDEZ S'IL VOUS PLAIT\n         ");
    for (i=0;i<60;i++)
    {
        color(159);
        printf(" ");
        w();
        Sleep(10);
    }
    printf("\n\t\t\t    ");fr();printf("CHARGEMENT TERMINER\n");w();
    Sleep(500);
}






void waitEnter() /*Attendre l'appuye de la touche entr\x82e*/
{

    enum
    {
        CR = 13,
        dummy
    };

    int c;
    do
    {
        c = getch ();
    }while (c != CR);

};

void FondVerte()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_TURQUOISE | FOREGROUND_BLUE |BACKGROUND_BLUE| BACKGROUND_RED| BACKGROUND_INTENSITY);
}


void color(int couleurDuTexte)
{
   HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(H, couleurDuTexte);
}

void GetChoix()
{
    CONSOLE_SCREEN_BUFFER_INFO EtatAncien;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &EtatAncien);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    scanf("%1c",&choix); fflush(stdin);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), EtatAncien.wAttributes);

}


void loko(char x)
{

        CONSOLE_SCREEN_BUFFER_INFO EtatAncien;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &EtatAncien);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("%1c",x); fflush(stdin);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), EtatAncien.wAttributes);
}

void Turquoisefile(char *x,FILE *sorti)
{
    CONSOLE_SCREEN_BUFFER_INFO EtatAncien;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &EtatAncien);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_TURQUOISE | FOREGROUND_INTENSITY);
    fprintf(sorti,"%s",x);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), EtatAncien.wAttributes);
}


void Turquoise(char *x)
{
    CONSOLE_SCREEN_BUFFER_INFO EtatAncien;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &EtatAncien);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_TURQUOISE | FOREGROUND_INTENSITY);
    printf("%s",x);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), EtatAncien.wAttributes);
}











/*permet de mettre || à la fin d'une chaine. c'est surtout pour le cadre dans les menus*/

void calcspace(char *chaine,int nbrcase)
{
     int i,y;
     y=nbrcase-strlen(chaine);
     for (i=0;i<y;i++)
     {printf(" ");}
     printf("\xBA");

}


void calcspacefile(char *chaine,int nbrcase,FILE *entre)
{
     int i,y;
     y=nbrcase-strlen(chaine);
     for (i=0;i<y;i++)
     {fprintf(entre," ");}
     fprintf(entre,"\xBA");

}


void gotoxy (short x, short y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}




void initialisation()
{

}



void rose()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_ROSE );
}


void r()
{color(12);   //fonction couleur ROUGE
}

void bl()
{color(31);   //fonction couleur BLEUE
}

void w()
{color(15);  //fonction couleur BLANCHE
}

void v()
{ color(10); //fonction couleur VERTE
}

void j()   //fonction couleur JAUNE
{
     color(14);
 }

void fr()  //fonction couleur fonf ROUGE
{
     color(206);
}

void Vertchar(char x)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("%c",x);w();
}


void beep ()
{
   putchar ('\a');
}


int saisie(char *ligne,size_t max)
{
    enum
    {
    BS = 8,
    LF = 10,
    CR = 13,
    ESC = 27,
    dummy
    };

   int i = 0;
   int c;
   do
   {
      c = getch ();

      switch (c)
      {
         /* filtrage des codes étendus */
      case 0:
      case 224:

         if (kbhit ()) //kbhit signifie keyboard hit
         {
            /* lire, mais ignorer */
            getch ();
            beep ();
         }
         else
         {
            /* enregistrer (une facorisation du code est possible...) */
            if (i < max - 1)
            {
               /* echo */
               putch (c);

               /* enregistrement du caractere */
               ligne[i] = c;
               i++;
            }
            else
            {
               beep ();
            }
         }
         break;

      case CR:
         /* echo CRLF */
         putch (CR);
         putch (LF);

         /* terminer la ligne */
         ligne[i] = 0;

         break;

      case BS:
         if (i > 0)
         {
            /* echo 'effacement' */
            putch (BS);
            putch (' ');
            putch (BS);

            /* reculer (les donnees sont inchangees) */
            i--;
         }
         else
         {
            beep ();
         }
         break;
      case ESC:
         /* echo CRLF */
         putch (CR);
         putch (LF);
/* a part ca, pas d'echo, pas d'enregistrement. Rien ! */
         break;
      default:
         if (i < max - 1)
         {
            /* echo */
            putch (c);

            /* enregistrement du caractere */
            ligne[i] = c;
            i++;
         }
         else
         {
            beep ();
         }
      }
   }
   while (c != CR && c != ESC);

   if (c == CR)
   {
      /* debug : afficher la ligne saisie */
      return 1;
   }
   else
   {
      /* debug : afficher la ligne saisie */
     return 0;
   }

}

void bienvenue()
{
    system("cls");
    attendre();
    system("cls");
    Turquoise("\n\t\t\t Bienvenue sur ce logiciel de gestion de bibliotheque BiBLIO MANAGING 1.1\n\n\t\tAppuyer sur ENTREE pour CONTINUER......");
    waitEnter();
    system("cls");
}


void ecrire_space(int nb)
{
    int i;
    for (i=0;i<nb;i++)
   {
       printf(" ");

   };
   printf("\n");
}

void balayer_ecran(short y,int nb)
{
    int i;
    short x=0;
    gotoxy(x,y);
    for (i=0;i<nb;i++)
    {
       ecrire_space(90);
    };

}











