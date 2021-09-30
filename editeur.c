#include"editeur.h"



Editeur *pileEditeur=NULL;


void viderEditeur()
{
    Editeur *tmpe;
    while(pileEditeur != NULL)
    {
        tmpe = pileEditeur->suivant;
pileEditeur = NULL;
        free(pileEditeur);/*On libere la place occupée par le dernier pointeur*/

        pileEditeur=tmpe;/*On reposition la PileEnseignant pour qu'il pointe toujours sur le dernier element*/
    }
}


void supprrEditeur(Editeur* E)
{
if(E==NULL) return;
    Editeur *tmpe=pileEditeur;

    if(E==pileEditeur)//si le membre se trouve en debut de la pile
    {

        pileEditeur=E->suivant;
        E=NULL;
        free(E);
    }
    else  //mais si il se trouve dans une place quelconque
    {
        while (tmpe)
        {

            if((tmpe->suivant!=NULL)&&tmpe->suivant==E)
            {
                tmpe->suivant=E->suivant;
                E=NULL;
                free(E);
            };
            tmpe=tmpe->suivant;
        }
    }


}

void afficheEditeur(Editeur *E)
{
    int i=0;
    system("cls");
    printf("\n\n\n\n\t\t\t\xC9");
    for (i=0;i<40;i++) printf("\xCD");
    printf("\xBB\n");
    printf("\t\t\t\xBA");
    printf("  Nom    : %s",E->RaisonSociale);calcspace(E->RaisonSociale,29);printf("\n");
    printf("\t\t\t\xBA");
    printf("  Prenom : %s",E->adresse);calcspace(E->adresse,29);printf("\n");
    /*printf("\t\t\t\xBA");
    printf("  Adresse: %s",O->adresse);calcspace(O->adresse,29);printf("\n");*/

    printf("\t\t\t\xC8");
    for (i=0;i<40;i++) printf("\xCD");
    printf("\xBC\n");
}
 /*color(10);
            printf("code :%d \n",actuel->code); color(01); color(03);
            printf("nom :%s \n",actuel->nom); color(03); color(02);
            printf("prenom :%s \n",actuel->prenom);color(30);color(02);*/

void listerEditeur()
{
    if (pileEditeur==NULL)
    {
        system("cls");color(15);printf("le fichier est vierge\n");
    }
    else
    {
        Editeur *actuel=pileEditeur; int i;
        printf("+---------------------+\n");
        printf("|");color(27);printf("    LISTE EDITEURS   ");w();printf("|\n");
        printf("+---------------------+\n");
        printf("\n\n   \xC9");

        for(i=0; i<58; i++)
        {
            if ( i==29) printf("\xCB");
            else printf("\xCD");
        };

        printf("\xBB"); /*tracer la ligne*/
        printf("\n   \xBA\t\t ");printf("RAISON SOCIALE");calcspace("RAISON SOCIALE",18);printf("\t    ");printf("ADRESSE");calcspace("ADRESSE",20);
        printf("\n   \xCC");

        for(i=0; i<58; i++)
        {
            if (i==29) printf("\xCE");
            else printf("\xCD");
        };

        printf("\xB9");

        while (actuel!=NULL)
        {

            printf("\n   \xBA");printf("  ");Turquoise(actuel->RaisonSociale);calcspace(actuel->RaisonSociale,26);printf("  ");Turquoise(actuel->adresse);calcspace(actuel->adresse,26);


            /*color(10);
            printf("code :%d \n",actuel->code); color(01); color(03);
            printf("nom :%s \n",actuel->nom); color(03); color(02);
            printf("prenom :%s \n",actuel->prenom);color(30);color(02);
            printf("adresse :%s \n",actuel->adresse);color(30);color(02);*/
            actuel=actuel->suivant;
        }
        printf("\n   \xC8");
        for(i=0; i<58; i++)
        {
            if (i==39) printf("\xCA");
            else printf("\xCD");
        }
        printf("\xBC\n");
    }
}

Editeur *rechercheEditeur(char *boutraison)
{

    Editeur *tmpE=pileEditeur;
    strupr(boutraison);

    while (tmpE)
    {

        if(strstr(tmpE->RaisonSociale,boutraison))
        {
            return tmpE;
        }
        tmpE=tmpE->suivant;
    };
    return NULL;

}

void modifEditeur(Editeur *amodif)
{
    fflush(stdin);
    printf("raison sociale:\n");
    gets(amodif->RaisonSociale);
    fflush(stdin);
    strupr(amodif->RaisonSociale);
    /*printf("adress :\n");
    gets(amodif->sujet);*/
    printf("adresse :\n");
    gets(amodif->adresse);
    fflush(stdin);
}

void pushEditeur(char RaisonSociale[50],char adresse[50])
{

    Editeur *tmpe=NULL;
    Editeur *tmpe1=(Editeur *)malloc(sizeof(Editeur));
    if (tmpe1==NULL)
    {
        system("cls");
        printf("probleme de memoire");
        exit(EXIT_FAILURE);
    }
    Editeur *tmpe2=pileEditeur;
    while (tmpe2 && strnicmp(tmpe2->RaisonSociale,RaisonSociale,5)<0)
    {
        tmpe=tmpe2;
        tmpe2=tmpe2->suivant;
    }
    tmpe1->suivant=tmpe2;
    //tmpo1->code=code;
    strcpy(tmpe1->RaisonSociale,RaisonSociale);
    strcpy(tmpe1->adresse,adresse);
   // strcpy(tmp1->adresse,adresse);
    if (tmpe)
    {
        tmpe->suivant=tmpe1;
    }
    else pileEditeur=tmpe1;
}


/*void affichemembre(Membre *M)
{
    printf("code: %d \n",M->code);
    printf("nom : %s \n",M->nom);
    printf("prenom: %s \n",M->prenom);
}*/

void saisieEditeur()
{
    int i;
    char RaisonSociale[50];
    char adresse[50];

debutsaisie:

    system("cls");
    fflush(stdin);
    /*printf("code : ");
    scanf("%d",&code); fflush(stdin);*/
    printf("raison sociale :  ");
    gets(RaisonSociale); fflush(stdin);
    strupr(RaisonSociale);
    if (rechercheEditeur(RaisonSociale))
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
            supprrEditeur(rechercheEditeur(RaisonSociale)); enregistrerEditeur();
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

    printf("adresse : \n");
    gets(adresse); fflush(stdin);


menuvad:
    MenuValidation();
    GetChoix();
    if (choix=='V'||choix=='v')
    {
        pushEditeur(RaisonSociale,adresse);
        enregistrerEditeur();
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

void enregistrerEditeur() /*enregistrement dans un fichier, elle sera appel\x82 à chaque fin de saisi*/
{
    Editeur *tmpE=pileEditeur;
    FILE *f;
    f=fopen("editeur.dat","wb");
    while (tmpE)
    {
        fwrite(tmpE, sizeof(Editeur),1, f);
        tmpE=tmpE->suivant;

    }
    fclose (f);
    return;
}

void chargerEditeur()
{
   viderEditeur();
    Editeur *tmpE = (Editeur *) malloc( sizeof(Editeur));
    FILE *f;
    f=fopen("editeur.dat","rb");
    if(f!=NULL)
    {
        while (!feof(f))
        {

            fread(tmpE, sizeof(Editeur),1, f);
            /*après la lecture de la dernière salle du fichier, fread ne renvoie pas un erreur ni feof, mais
             sont dernier appel, g\x82nère une erreur parce que le fichier est atteint
             c'est pour ça qu'il est nec\x82ssaire de mêtre break pour eviter d'afficher deux fois la deriniere salle*/
            if (feof(f)) break;
            pushEditeur(tmpE->RaisonSociale, tmpE->adresse);
        }
    }
}
void consuEditeur()
{
    char a[50];

consult:
    system("cls");
    printf("Entrer la raison sociale de l'editeur : ");
    gets(a);fflush(stdin);
    strupr(a);

    if(rechercheEditeur(a)!=NULL)
    {
debuaff:
        afficheEditeur(rechercheEditeur(a));
        fflush(stdin);
        TolotraModifSup();
        GetChoix();
        if ((choix=='m')||(choix=='M'))
        {
            modifEditeur(rechercheEditeur(a));
            enregistrerEditeur();
            Turquoise("    Modification terminee....");
            waitEnter();
        }
        else if ((choix=='s')||(choix=='S'))
        {
            supprrEditeur(rechercheEditeur(a));
            enregistrerEditeur();
            Turquoise("    suppression terminee......");
        }
        else if ((choix=='r')||(choix=='R'))
        {
             goto fin;
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED|FOREGROUND_INTENSITY);
            printf("\n\nveuiller saisir le bon numero");w();
            waitEnter();
            system("cls");
            goto debuaff;
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
            case '2': listerEditeur();waitEnter();consuEditeur();break;
            case '3': goto fin;break;
            default :{r();printf("\n\n    Veuiller saisir le bon numero!!");w();waitEnter();system("cls");goto misafidy;}break;
        }
    }
fin:
    ;
}

void menue_editeur()
{
    chargerEditeur();
    printf("");
    attendre();

    SetConsoleTitle("EDITEUR");
SousMenuMembre:

    SousMenu();
    GetChoix();
    switch (choix)
    {
        case '1':

            {saisieEditeur();
             //enregistrerAuteur();
            waitEnter();
            system("cls");
            goto SousMenuMembre;
            }
        break;
        case '2':
        {
            consuEditeur();
            waitEnter();
            system("cls");
            goto SousMenuMembre;
        }
        break;
        case '3':
        {
            system("cls");
            listerEditeur();
            waitEnter();
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

    ;
}







