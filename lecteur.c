#include"lecteur.h"


char choix;

Membre *pileMembre=NULL;

void vidermembr()
{
    Membre *tmp;
    while(pileMembre != NULL)
    {
        tmp = pileMembre->suivant;
pileMembre = NULL;
        free(pileMembre);/*On libere la place occupée par le dernier pointeur*/

        pileMembre=tmp;/*On reposition la PileEnseignant pour qu'il pointe toujours sur le dernier element*/
    }
}

void supprrmembre(Membre* mb)
{
    if(mb==NULL) return;
    Membre *tmp=pileMembre;

    if(mb==pileMembre)//si le membre se trouve en debut de la pile
    {

        pileMembre=mb->suivant;
        mb=NULL;
        free(mb);
    }
    else  //mais si il se trouve dans une place quelconque
    {
        while (tmp)
        {

            if((tmp->suivant!=NULL)&&tmp->suivant==mb)
            {
                tmp->suivant=mb->suivant;
                mb=NULL;
                free(mb);
            };
            tmp=tmp->suivant;
        }
    }


}

void pushMembre(int code,char nom[32],char prenom[32],char adresse[50])
{

    Membre *tmp=NULL;
    Membre *tmp1=(Membre *)malloc(sizeof(Membre));
    if (tmp1==NULL)
    {
        system("cls");
        printf("probleme de memoire");
        exit(EXIT_FAILURE);
    }
    Membre *tmp2=pileMembre;
    while (tmp2 && tmp2->code<code)
    {
        tmp=tmp2;
        tmp2=tmp2->suivant;
    }
    tmp1->suivant=tmp2;
    tmp1->code=code;
    strcpy(tmp1->nom,nom);
    strcpy(tmp1->prenom,prenom);
    strcpy(tmp1->adresse,adresse);
    if (tmp)
    {
        tmp->suivant=tmp1;
    }
    else pileMembre=tmp1;
}


void listerMembre()
{
    if (pileMembre==NULL)
    {
        system("cls");color(15);printf("le fichier est vierge\n");
    }
    else
    {
        Membre *actuel=pileMembre;
        char str[4];
        int i=0;//system("cls");
        printf("+---------------------+\n");
        printf("|");color(27);printf("     LISTE MEMBRE    ");w();printf("|\n");
         printf("+---------------------+\n");
        printf("\n\n   \xC9");
            for(i=0; i<68; i++)
            {
            if ((i==10)|| (i==39)) printf("\xCB");
            else printf("\xCD");
            };
            printf("\xBB"); /*tracer la ligne*/
            printf("\n   \xBA    CODE  \xBA\t\t ");printf("NOMS");calcspace("NOMS",18);printf("\t    ");printf("PRENOMS");calcspace("PRENOMS",20);
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
            printf("\n   \xBA       ");Turquoise(str);printf("\xBA");printf("  ");Turquoise(actuel->nom);calcspace(actuel->nom,26);printf("  ");Turquoise(actuel->prenom);calcspace(actuel->prenom,26);
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
    w();
    //waitEnter();
}

Membre *rechercheMembre(int code)
{

    Membre *tmp=pileMembre;
    if (tmp)
    {
        while (tmp)
        {

            if(tmp->code==code)
            {
                return tmp;
            }
            tmp=tmp->suivant;
        };
    }
    else
    {
        return NULL;
    }

}

void modifMembre(Membre *amodif)
{
    fflush(stdin);
    printf("nom:\n");
    gets(amodif->nom);
    fflush(stdin);
    printf("prenom :\n");
    gets(amodif->prenom);
    fflush(stdin);
    printf("adresse :\n");
    gets(amodif->adresse);
    fflush(stdin);
}

void affichemembre(Membre *M)
{
    int i=0;
    char str[4];
    sprintf(str,"%03d",M->code);
    system("cls");
    printf("\n\n\n\n\t\t\t\xC9");
    for (i=0;i<40;i++) printf("\xCD");
    printf("\xBB\n");
    printf("\t\t\t\xBA");
    printf("  Code   : ");Turquoise(str);calcspace("000",29);printf("\n");
    printf("\t\t\t\xBA");
    printf("  Nom    : ");Turquoise(M->nom);calcspace(M->nom,29);printf("\n");
    printf("\t\t\t\xBA");
    printf("  Prenom : ");Turquoise(M->prenom);calcspace(M->prenom,29);printf("\n");
    printf("\t\t\t\xBA");
    printf("  Adresse: ");Turquoise(M->adresse);calcspace(M->adresse,29);printf("\n");
    printf("\t\t\t\xC8");
    for (i=0;i<40;i++) printf("\xCD");
    printf("\xBC\n");
}

void saisiemembre()
{
    int code,i=0;
    char nom[32];
    char prenom[32];
    char adresse[50];

debutsaisie:

    system("cls");
    fflush(stdin);
    printf("+-------------------------+\n");
    printf("|");color(27);printf("      Saisie Membre    ");w();printf("|\n");
    printf("+-------------------------+\n");
    printf("\n\n\n\n\t\t");

    color(159);
    printf(" code        :\n"); w();
    printf("\t\t");
    printf("                                                        \n");w();
    printf("\t\t");
    color(159);
    printf(" Nom         :\n"); w();
    printf("\t\t");

    printf("                                                        \n");w();
    printf("\t\t");
    color(159);
    printf(" Prenom      :\n"); w();
    printf("\t\t");

    printf("                                                        \n");w();
    printf("\t\t");
    color(159);
    printf(" Adresse     :\n"); w();

    x:
    gotoxy(32,7);
    printf("                 ");
    gotoxy(32,7); fflush(stdin);
    scanf("%03d",&code); fflush(stdin);
    if (rechercheMembre(code))
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
            goto farany;
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
    if (1==saisie(nom,50))
        {goto z;}
    else
        {goto y;}

z:
    gotoxy(32,11);
    printf("                 ");
    gotoxy(32,11);
    if (1==saisie(prenom,50))
        {goto t;}
    else
        {goto z;}
t:
    gotoxy(32,13);
    printf("                 "); fflush(stdin);
    gotoxy(32,13);

    if (1==saisie(adresse,50))
        {goto validena;}
    else
        {goto t;}
 validena:
        MenuValidation();
        GetChoix();
        if (choix=='V'||choix=='v')
        {
            pushMembre(code,nom,prenom,adresse);
            enregistrerMembre();
        }
        else if (choix=='M'||choix=='m')
        {
            system("cls");
            goto debutsaisie;
        }
        else if (choix=='A'||choix=='a')
        {
            goto farany;
        }



farany:

    rien();
}


void enregistrerMembre() /*enregistrement dans un fichier, elle sera appel\x82 à chaque fin de saisi*/
{
    Membre *tmp=pileMembre;
    FILE *f;
    f=fopen("membre.dat","wb");
    while (tmp)
    {
        fwrite(tmp, sizeof(Membre),1, f);
        tmp=tmp->suivant;

    }
    fclose (f);
    return;
}

void chargerMembre()
{
   vidermembr();
    Membre *tmp = (Membre *) malloc( sizeof(Membre));
    FILE *f;
    f=fopen("membre.dat","rb");
    if(f!=NULL)
    {
        while (!feof(f))
        {

            fread(tmp, sizeof(Membre),1, f);
            /*après la lecture de la dernière salle du fichier, fread ne renvoie pas un erreur ni feof, mais
             sont dernier appel, g\x82nère une erreur parce que le fichier est atteint
             c'est pour ça qu'il est nec\x82ssaire de mêtre break pour eviter d'afficher deux fois la deriniere salle*/
            if (feof(f)) break;
            pushMembre(tmp->code,tmp->nom, tmp->prenom,tmp->adresse);
        }
    }
}

void consunmbre()
{
    short a;

consult:
    system("cls");
    printf("Entrer l'ID du membre : ");
    scanf("%hd",&a);
    fflush(stdin);
    if(rechercheMembre(a)!=NULL)
    {

  debutaff:
        affichemembre(rechercheMembre(a));
        fflush(stdin);
        TolotraModifSup();
        GetChoix();
        if (choix=='M'||choix=='m')
        {
            system("cls");
            modifMembre(rechercheMembre(a));
            system("cls");
        }
        else if (choix=='S'||choix=='s')
        {
            supprrmembre(rechercheMembre(a));
            system("cls");
            Turquoise("\n   Suppression terminée.......");
            enregistrerMembre();
            waitEnter();
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
        printf("\n\n\n              cet element n'existe pas");w();
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
            case '2': listerMembre();consunmbre();break;
            case '3': goto fin;break;
            default :{r();printf("\n\n    Veuiller saisir le bon numero!!");w();waitEnter();system("cls");goto misafidy;}break;
        }

    }
fin :
    rien();
}


void exporetermembre()
{
    Membre *actuel=pileMembre;
    FILE *ficest;
    ficest=fopen("membre.doc","w");
        char str[4];
        int i=0;//system("cls");
        fprintf(ficest,"+---------------------+\n");
        fprintf(ficest,"|     LISTE MEMBRE    |\n");
        fprintf(ficest,"+---------------------+\n");
        fprintf(ficest,"\n\n   +");
            for(i=0; i<68; i++)
            {
            if ((i==10)|| (i==39)) fprintf(ficest,"\xCB");
            else fprintf(ficest,"\xCD");
            };
            fprintf(ficest,"\xBB"); /*tracer la ligne*/
            fprintf(ficest,"\n   \xBA    CODE  \xBA\t\t ");fprintf(ficest,"NOMS");calcspacefile("NOMS",18,ficest);fprintf(ficest,"\t    ");fprintf(ficest,"PRENOMS");calcspacefile("PRENOMS",20,ficest);
            fprintf(ficest,"\n   \xCC");
            for(i=0; i<68; i++)
            {
            if ((i==10)|| (i==39)) fprintf(ficest,"\xCE");
            else fprintf(ficest,"\xCD");
            };
            fprintf(ficest,"\xB9");

        while (actuel!=NULL)
        {



            sprintf(str,"%03d",actuel->code);
            fprintf(ficest,"\n   \xBA       ");Turquoisefile(str,ficest);fprintf(ficest,"\xBA");fprintf(ficest,"  ");Turquoisefile(actuel->nom,ficest);calcspacefile(actuel->nom,26,ficest);fprintf(ficest,"  ");Turquoisefile(actuel->prenom,ficest);calcspacefile(actuel->prenom,26,ficest);
            actuel=actuel->suivant;
        }
        fprintf(ficest,"\n   \xC8");
        for(i=0; i<68; i++)
        {
            if ((i==10)|| (i==39)) fprintf(ficest,"\xCA");
            else fprintf(ficest,"\xCD");
        }
        fprintf(ficest,"\xBC\n");

}


void sous_menue_membre()
{
    vidermembr();
    SetConsoleTitle("MENUE MEMBRE");
    chargerMembre();
    printf("");
    attendre();

SousMenuMembre:

    SousMenu();
    GetChoix();
    switch (choix)
    {
        case '1':

            {saisiemembre();
             system("cls");
            goto SousMenuMembre;
            }
        break;
        case '2':
        {
            consunmbre();
            goto SousMenuMembre;
        }
        break;
        case '3':
        {
            system("cls");listerMembre();waitEnter();
            system("cls");
            goto SousMenuMembre;
        }
        break;
        case '4':
        goto end;
        break;
        default :
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED|FOREGROUND_INTENSITY);
            printf("\n\nveuiller saisir le bon numero");w();
            waitEnter();
            system("cls");
            goto SousMenuMembre;
        }break;
    }


end:
    ;//exporetermembre();
}









