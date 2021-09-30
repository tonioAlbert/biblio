#include"ouvrage.h"

ouvrage *pileOuvrage=NULL;


char choix;

void viderOuvrage()
{
    ouvrage *tmpo;
    while(pileOuvrage != NULL)
    {
        tmpo = pileOuvrage->suivant;
pileOuvrage = NULL;
        free(pileOuvrage);/*On libere la place occupée par le dernier pointeur*/

        pileOuvrage=tmpo;/*On reposition la PileEnseignant pour qu'il pointe toujours sur le dernier element*/
    }
}


void supprrOuvrage(ouvrage* o)
{
if(o==NULL) return;
    ouvrage *tmpo=pileOuvrage;

    if(o==pileOuvrage)//si le membre se trouve en debut de la pile
    {

        pileOuvrage=o->suivant;
        o=NULL;
        free(o);
    }
    else  //mais si il se trouve dans une place quelconque
    {
        while (tmpo)
        {

            if((tmpo->suivant!=NULL)&&tmpo->suivant==o)
            {
                tmpo->suivant=o->suivant;
                o=NULL;
                free(o);
            };
            tmpo=tmpo->suivant;
        }
    }


}
void afficheOuvrage(ouvrage *O)
{
    int i=0;
    char str[4];
    auteur *A=(auteur *)malloc(sizeof(auteur));
    sprintf(str,"%03d",O->code);
    system("cls");
    printf("\n\n\n\n\t\t\t\xC9");
    for (i=0;i<40;i++) printf("\xCD");
    printf("\xBB\n");
    printf("\t\t\t\xBA");
    printf("  Code   : %s",str);calcspace("000",29);printf("\n");
    printf("\t\t\t\xBA");
    printf("  Titre  : %s",O->titre);calcspace(O->titre,29);printf("\n");
    printf("\t\t\t\xBA");
    printf("  sujet  : %s",O->sujet);calcspace(O->sujet,29);printf("\n");
    A=rechercheAuteur(O->codeaut);
    printf("\t\t\t\xBA");
    printf("   auteur: %s",A->nom);calcspace(A->nom,29);printf("\n");

    /*printf("\t\t\t\xBA");
    printf("  Adresse: %s",O->adresse);calcspace(O->adresse,29);printf("\n");*/

    printf("\t\t\t\xC8");
    for (i=0;i<40;i++) printf("\xCD");
    printf("\xBC\n");
}
 short nombreouvrage()
{
    ouvrage *sl=pileOuvrage;
    short n=0;
    while(sl)
    {
        n++;
        sl = sl->suivant;
    }
    return n;
}

short nombreouvrageAut(int codeaut)
{
    ouvrage *sl=pileOuvrage;
    short n=0;
    while(sl)
    {
        if (sl->codeaut==codeaut)
        {
            n++;
        }
        sl = sl->suivant;
    }
    return n;
}

void listerOuvrage()
{
    if (pileOuvrage==NULL)
    {
        system("cls");color(15);printf("le fichier est vierge\n");
    }
    else
    {
        ouvrage *actuel=pileOuvrage; int i; char str[4]; short j;
        printf("+---------------------+\n");
        printf("|");color(27);printf("    LISTE OUVRAGES   ");w();printf("|\n");
        printf("+---------------------+\n");
        printf("\n\n   \xC9");

        for(i=0; i<68; i++)
        {
            if ((i==10)|| (i==39)) printf("\xCB");
            else printf("\xCD");
        };

        printf("\xBB"); /*tracer la ligne*/
        printf("\n   \xBA    CODE  \xBA\t\t ");printf("TITRE");calcspace("TITRE",18);printf("\t    ");printf("SUJET");calcspace("SUJET",20);
        printf("\n   \xCC");

        for(i=0; i<68; i++)
        {
            if ((i==10)|| (i==39)) printf("\xCE");
            else printf("\xCD");
        };

        printf("\xB9");

        while (actuel!=NULL)
        {
            sprintf(str,"%03d",actuel->code);
            printf("\n   \xBA       ");Turquoise(str);printf("\xBA");printf("  ");Turquoise(actuel->titre);calcspace(actuel->titre,26);printf("  ");Turquoise(actuel->sujet);calcspace(actuel->sujet,26);



            actuel=actuel->suivant;
            j++;
        }
        printf("\n   \xC8");
        for(i=0; i<68; i++)
        {
            if ((i==10)|| (i==39)) printf("\xCA");
            else printf("\xCD");
        }
        printf("\xBC\n");
    }
    printf("\n\t\t total : %d",nombreouvrage());
    waitEnter();
}

void listerOuvrageParAuteur(int code)
{
    if (pileOuvrage==NULL)
    {
        system("cls");color(15);printf("le fichier est vierge\n");
    }
    else
    {
        ouvrage *actuel=pileOuvrage; int i; char str[4]; int j=0;
        printf("+-------------------------+\n");
        printf("|");color(27);printf("      OUVRAGES ECRITE   ");w();printf("|\n");
        printf("+-------------------------+\n");
        printf("\n\n   \xC9");

        for(i=0; i<68; i++)
        {
            if ((i==10)|| (i==39)) printf("\xCB");
            else printf("\xCD");
        };

        printf("\xBB"); /*tracer la ligne*/
        printf("\n   \xBA");printf("    CODE  ");printf("\xBA");printf("\t\t TITRE");calcspace("TITRE",18);printf("\t    ");printf("SUJET");calcspace("SUJET",20);
        printf("\n   \xCC");

        for(i=0; i<68; i++)
        {
            if ((i==10)|| (i==39)) printf("\xCE");
            else printf("\xCD");
        };

        printf("\xB9");

        while (actuel!=NULL)
        {

            if (actuel->codeaut==code)
            {
                sprintf(str,"%03d",actuel->code);
                printf("\n   \xBA       ");Turquoise(str);printf("\xBA");printf("  ");Turquoise(actuel->titre);calcspace(actuel->titre,26);printf("  ");Turquoise(actuel->sujet);calcspace(actuel->sujet,26);

            }

            actuel=actuel->suivant;
        }
        printf("\n   \xC8");
        for(i=0; i<68; i++)
        {
            if ((i==10)|| (i==39)) printf("\xCA");
            else printf("\xCD");
        }
        printf("\xBC\n");
    }
    if (nombreouvrageAut(code)==0)
    printf("Pas encore de livre ecrit\n");
    else
    color(159);printf("                 Total : ");
    printf("%d",nombreouvrageAut(code));w();

}

ouvrage *rechercheOuvrage(int code)
{

    ouvrage *tmpo=pileOuvrage;

    while (tmpo)
    {

        if(tmpo->code==code)
        {
            return tmpo;
        }
        tmpo=tmpo->suivant;
    };
    return NULL;

}

void modifOuvrage(ouvrage *amodif)
{
    fflush(stdin);
    printf("titre:\n");
    gets(amodif->titre);
    fflush(stdin);
    printf("sujet :\n");
    gets(amodif->sujet);
    /*printf("adresse :\n");
    gets(amodif->adresse);*/
    fflush(stdin);
}

void pushOuvrage(int code,int codeaut,char titre[50],char sujet[50])
{

    ouvrage *tmpo=NULL;
    ouvrage *tmpo1=(ouvrage *)malloc(sizeof(ouvrage));
    if (tmpo1==NULL)
    {
        system("cls");
        printf("probleme de memoire");
        exit(EXIT_FAILURE);
    }
    ouvrage *tmpo2=pileOuvrage;
    while (tmpo2 && tmpo2->code<code)
    {
        tmpo=tmpo2;
        tmpo2=tmpo2->suivant;
    }
    tmpo1->suivant=tmpo2;
    tmpo1->code=code;
    tmpo1->codeaut=codeaut;
    strcpy(tmpo1->titre,titre);
    strcpy(tmpo1->sujet,sujet);
   // strcpy(tmp1->adresse,adresse);
    if (tmpo)
    {
        tmpo->suivant=tmpo1;
    }
    else pileOuvrage=tmpo1;
}

/*void saisieOuvrage()
{
    int code,i,codeaut;
    char titre[50];
    char sujet[50];

debutsaisie:

    system("cls");
    fflush(stdin);
    printf("code : ");
    scanf("%d",&code); fflush(stdin);
    if (rechercheOuvrage(code))
    {

misafidy:
        system("cls");
        printf("\n\n\n\n\t\t\t");
        w();printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",0xC9,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xBB);
        printf("\t\t\t%c                             %c\n\t\t\t%c",0xBA,0xBA,0xBA);
        r();printf("  CET ELEMENT EXISTE DEJA!!  ");w();
        printf("%c\n",0xBA);
        printf("\t\t\t\xBA                             \xBA\n");
        printf("\t\t\t\xBA");w();
        for (i=0;i<29;i++)
        {
            printf("\xDC");
        }
        w();printf("\xBA\n");
        printf("\t\t\t%c                             %c\n\t\t\t%c",0xBA,0xBA,0xBA);
        r();printf("   QUE VOULLEZ VOUS FAIRE ?  ");w();
        printf("%c\n",0xBA);
        printf("\t\t\t\xBA                             \xBA\n");
        printf("\t\t  %c%c%c%c%c%c\xCA",0xC9,0xCD,0xCD,0xCD,0xCD,0xCD);
        for (i=0;i<29;i++)
        {
            printf("\xCD");
        }
        printf("\xCA\xCD\xCD\xCD\xCD\xCD\xBB\n");
        printf("\t\t\  \xBA    ");loko('1');printf("-Ecraser   ");loko('2');printf("-Resaisir   ");loko('3');printf("-Sortir    \xBA\n");
        printf("\t\t\  \xC8");
        for (i=0;i<41;i++)
        {
            printf("\xCD");
        }
        printf("\xBC\n\n\t\t\t Choix: ");
        GetChoix();
        if (choix=='1')
        {
            system("cls");
            modifOuvrage(rechercheOuvrage(code)); enregistrerOuvrage();
        }
        else if (choix=='2')
        {
            system("cls");
            goto debutsaisie;
        }
        else if (choix=='3')
        {
            goto finSaisieAut;
        }
        else
        {
            r();printf("\n            VEILLEZ SAISIR LE BON NUMERO");w(); waitEnter();
            goto misafidy;
        }

    }
    auteur *A=(auteur *)malloc(sizeof(auteur));
    printf("titre : \n");
    gets(titre); fflush(stdin);
    printf("sujet : \n");
    gets(sujet); fflush(stdin);
    printf("code auteur :");
    scanf("%d",&codeaut); fflush(stdin);
    A=rechercheAuteur(codeaut);
    if (A)
    {
        printf("auteur existant");
        waitEnter();
        goto menuvad;
    }
    else
    {
        printf("l'auteur n'existe pas!\nveuillez aller au menue auteur pour y voir\n");
        goto finSaisieAut;
    }


menuvad:
    MenuValidation();
    GetChoix();
    if (choix=='V'||choix=='v')
    {
        pushOuvrage(code,codeaut,titre,sujet);
        enregistrerOuvrage();
    }
    else if (choix=='M'||choix=='m')
    {
        goto debutsaisie;
    }
    else if (choix=='A'||choix=='a')
    {
        goto finSaisieAut;
    }
    else
    {
        r();printf("\n      CHOIX INVALIDE!!!  VEUILLEZ RESSAISIR\n");w(); waitEnter();
        goto menuvad;
    }

finSaisieAut:
    rien();
}*/

void saisieOuvrage()
{
    int code,i,codeaut;
    char titre[50];
    char sujet[50];

debutsaisie:

    system("cls");
    fflush(stdin);
    printf("+-------------------------+\n");
    printf("|");color(27);printf("      Saisie Ouvrage     ");w();printf("|\n");
    printf("+-------------------------+\n");
    printf("\n\n\n\n\t\t");

    color(159);
    printf(" code        :\n");w();
    printf("\t\t");
    printf("                                                        \n");w();
    printf("\t\t");
    color(159);
    printf(" titre       :\n");w();
    printf("\t\t");

    printf("                                                        \n");w();
    printf("\t\t");
    color(159);
    printf(" sujet       :\n");w();
    printf("\t\t");

    printf("                                                        \n");w();
    printf("\t\t");
    color(159);
    printf(" code auteur :\n");w();
x:
    gotoxy(30,7);
    printf("                                          \n");
    gotoxy(32,7); fflush(stdin);
    scanf("%03d",&code); fflush(stdin);
    if (rechercheOuvrage(code))
    {

misafidy:
        gotoxy(3,40);
        w();printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",0xC9,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xBB);
        printf("\t\t\t%c                             %c\n\t\t\t%c",0xBA,0xBA,0xBA);
        r();printf("  CET ELEMENT EXISTE DEJA!!  ");w();
        printf("%c\n",0xBA);
        printf("\t\t\t\xBA                             \xBA\n");
        printf("\t\t\t\xBA");w();
        for (i=0;i<29;i++)
        {
            printf("\xDC");
        }
        w();printf("\xBA\n");
        printf("\t\t\t%c                             %c\n\t\t\t%c",0xBA,0xBA,0xBA);
        r();printf("   QUE VOULLEZ VOUS FAIRE ?  ");w();
        printf("%c\n",0xBA);
        printf("\t\t\t\xBA                             \xBA\n");
        printf("\t\t  %c%c%c%c%c%c\xCA",0xC9,0xCD,0xCD,0xCD,0xCD,0xCD);
        for (i=0;i<29;i++)
        {
            printf("\xCD");
        }
        printf("\xCA\xCD\xCD\xCD\xCD\xCD\xBB\n");
        printf("\t\t\  \xBA       ");loko('1');printf("-Resaisir            ");loko('2');printf("-Sortir    \xBA\n");
        printf("\t\t\  \xC8");
        for (i=0;i<41;i++)
        {
            printf("\xCD");
        }
        printf("\xBC\n\n\t\t\t Choix: ");
        GetChoix();
        if (choix=='1')
        {
            system("cls");//balayer_ecran(30,20);
            goto debutsaisie;
        }
        else if (choix=='2')
        {
            goto finSaisieAut;
        }
        else
        {
            r();printf("\n            VEILLEZ SAISIR LE BON NUMERO");w(); waitEnter();
            goto misafidy;
        }

    }

 y:
    gotoxy(32,9);
    printf("                 ");
    gotoxy(32,9);
    if (1==saisie(titre,50))
        {goto z;}
    else
        {goto y;}

z:
    gotoxy(32,11);
    printf("                 ");
    gotoxy(32,11);
    if (1==saisie(sujet,50))
        {goto t;}
    else
        {goto z;}
t:
    gotoxy(32,13);
    printf("                 "); fflush(stdin);
    gotoxy(32,13);
    scanf("%d",&codeaut); fflush(stdin);

    if (rechercheAuteur(codeaut))
    {

        goto menuvad;
    }
    else
    {
  m:
      gotoxy(0,15);

      Turquoise("\n\tCet auteur n'existe pas dans nos registre!\n\tVeuillez le verifier dans la liste ci-apres:\n");w();
        listerAureur();
        printf(" Est ce que l'auteur s'y trouve?  "); loko('O');printf(" / ");loko('N');printf("\n\t choix: ");fflush(stdin);
        GetChoix();fflush(stdin);
        if (choix=='o'||choix=='O')
        {
            balayer_ecran(15,20);
            j();printf("Veuillez saisir le bon code de l'auteur");w();
            balayer_ecran(15,30);
            goto t;
        }
        else if (choix=='n'||choix=='N')
        {
            Turquoise("saisie annule...");Sleep(1000);
            Turquoise("\nAppuyer sur ENTREE pour continuer.....");
            goto finSaisieAut;
        }
        else
        {
            r();printf("CHOIX INVALIDE!!!");w();Sleep(500);
            balayer_ecran(15,30);
            goto m;
        }
    }



menuvad:
    MenuValidation();
    GetChoix();
    if (choix=='V'||choix=='v')
    {
        pushOuvrage(code,codeaut,titre,sujet);
        enregistrerOuvrage();
    }
    else if (choix=='M'||choix=='m')
    {
        goto debutsaisie;
    }
    else if (choix=='A'||choix=='a')
    {
        goto finSaisieAut;
    }
    else
    {
        r();printf("\n      CHOIX INVALIDE!!!  VEUILLEZ RESSAISIR\n");w(); waitEnter();
        goto menuvad;
    }



finSaisieAut:
;
}

void enregistrerOuvrage() /*enregistrement dans un fichier, elle sera appel\x82 à chaque fin de saisi*/
{
    ouvrage *tmpo=pileOuvrage;
    FILE *f;
    f=fopen("ouvrage.dat","wb");
    while (tmpo)
    {
        fwrite(tmpo, sizeof(ouvrage),1, f);
        tmpo=tmpo->suivant;

    }
    fclose (f);
    return;
}

void chargerOuvrage()
{
   viderOuvrage();
    ouvrage *tmpo = (ouvrage *) malloc( sizeof(ouvrage));
    FILE *f;
    f=fopen("ouvrage.dat","rb");
    if(f!=NULL)
    {
        while (!feof(f))
        {

            fread(tmpo, sizeof(ouvrage),1, f);
            /*après la lecture de la dernière salle du fichier, fread ne renvoie pas un erreur ni feof, mais
             sont dernier appel, g\x82nère une erreur parce que le fichier est atteint
             c'est pour ça qu'il est nec\x82ssaire de mêtre break pour eviter d'afficher deux fois la deriniere salle*/
            if (feof(f)) break;
            pushOuvrage(tmpo->code,tmpo->codeaut,tmpo->titre, tmpo->sujet);
        }
    }


}

void consuOuvrage()
{
    short a;

consult:
    system("cls");
    printf("Entrer l'ID de l'ouvrage : ");
    scanf("%hd",&a);
    fflush(stdin);
    if(rechercheOuvrage(a)!=NULL)
    {
       debutaff:
        afficheOuvrage(rechercheOuvrage(a));
        fflush(stdin);
        TolotraModifSup();
        GetChoix();
        if (choix=='M'||choix=='m')
        {
            system("cls");
            modifOuvrage(rechercheOuvrage(a));
            system("cls");
        }
        else if (choix=='S'||choix=='s')
        {
            supprrOuvrage(rechercheOuvrage(a));
            system("cls");
            Turquoise("\n   Suppression terminée.......");
            enregistrerOuvrage();
        }
        else if (choix=='R'||choix=='r')
        {
            goto fin;
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED|FOREGROUND_INTENSITY);
            printf("\n\nveuiller saisir le bon numero");w();
            waitEnter();
            system("cls");
            goto debutaff;
        }
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("              cet element n'existe pas");w();
        waitEnter();
        int i;

    misafidy:

        printf("\n\n\n\t\t  %c%c%c%c%c%c\xCd",0xC9,0xCD,0xCD,0xCD,0xCD,0xCD);
        for (i=0;i<29;i++)
        {
            printf("\xCD");
        }
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
        printf("\t\t\  \xBA    ");loko('1');printf("-Resaisir   ");loko('2');printf("-Lister    ");loko('3');printf("-Sortir    \xBA\n");
        printf("\t\t\  \xC8");
        for (i=0;i<41;i++)
        {
            printf("\xCD");
        }
        printf("\xBC\n\n\t\t\t Choix: ");
        GetChoix();
        switch (choix)
        {
            case '1': goto consult;break;
            case '2': listerOuvrage();consuOuvrage();break;
            case '3': goto fin;break;
            default :{r();printf("\n\n    Veuiller saisir le bon numero!!");w();waitEnter();system("cls");goto misafidy;}break;
        }
    }
  fin:
    rien();
}

void menue_ouvrage()
{
    chargerOuvrage();
    printf("");
    attendre();
    SetConsoleTitle("OUVRAGE");

SousMenuMembre:

    SousMenu();
    GetChoix();
    switch (choix)
    {
        case '1':

            {saisieOuvrage();
             //enregistrerAuteur();
            waitEnter();
            system("cls");
            goto SousMenuMembre;
            }
        break;
        case '2':
        {
            consuOuvrage();
            waitEnter();
            system("cls");
            goto SousMenuMembre;
        }
        break;
        case '3':
        {
            system("cls");
            listerOuvrage();
//            waitEnter();
            system("cls");
            goto SousMenuMembre;
        }
        break;
        case '4':
        goto ending;
        break;
        default :
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED|FOREGROUND_INTENSITY);
            printf("\n\nveuiller saisir le bon numero");
            waitEnter();
            system("cls");
            goto SousMenuMembre;
        }break;
    }


ending:

    rien();
}







