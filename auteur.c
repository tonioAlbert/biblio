#include"auteur.h"

char choix;

auteur *pileAuteur=NULL;

void viderauteur()
{
    auteur *tmp;
    while(pileAuteur != NULL)
    {
        tmp = pileAuteur->suivant;
pileAuteur = NULL;
        free(pileAuteur);/*On libere la place occupée par le dernier pointeur*/

        pileAuteur=tmp;/*On reposition la PileEnseignant pour qu'il pointe toujours sur le dernier element*/
    }
}


void supprrAuteur(auteur* a)
{
if(a==NULL) return;
    auteur *tmp=pileAuteur;

    if(a==pileAuteur)//si le membre se trouve en debut de la pile
    {

        pileAuteur=a->suivant;
        a=NULL;
        free(a);
    }
    else  //mais si il se trouve dans une place quelconque
    {
        while (tmp)
        {

            if((tmp->suivant!=NULL)&&tmp->suivant==a)
            {
                tmp->suivant=a->suivant;
                a=NULL;
                free(a);
            };
            tmp=tmp->suivant;
        }
    }


}

void afficheAuteur(auteur *A)
{
    int i=0;
    char str[4];
    sprintf(str,"%03d",A->code);
    system("cls");
    printf("\n\n\t\t\t\xC9");
    for (i=0;i<40;i++) printf("\xCD");
    printf("\xBB\n");
    printf("\t\t\t\xBA");
    printf("  Code   : ");Turquoise(str);calcspace("000",29);printf("\n");
    printf("\t\t\t\xBA");
    printf("  Nom    : ");Turquoise(A->nom);calcspace(A->nom,29);printf("\n");
    printf("\t\t\t\xBA");
    printf("  Prenom : ");Turquoise(A->prenom);calcspace(A->prenom,29);printf("\n");
    printf("\t\t\t\xBA");
    printf("  Adresse: ");Turquoise(A->adresse);calcspace(A->adresse,29);printf("\n");

    printf("\t\t\t\xC8");
    for (i=0;i<40;i++) printf("\xCD");
    printf("\xBC\n");
}

void listerAureur()
{
    if (pileAuteur==NULL)
    {
        system("cls");color(15);printf("le fichier est vierge\n");
    }
    else
    {
        auteur *actuel=pileAuteur; int i; char str[4];
        printf("+---------------------+\n");
        printf("|");color(27);printf("    LISTE AUTEURS    ");w();printf("|\n");
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


            /*color(10);
            printf("code :%d \n",actuel->code); color(01); color(03);
            printf("nom :%s \n",actuel->nom); color(03); color(02);
            printf("prenom :%s \n",actuel->prenom);color(30);color(02);
            printf("adresse :%s \n",actuel->adresse);color(30);color(02);*/
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
}

auteur *rechercheAuteur(int code)
{

    auteur *tmp=pileAuteur;

    while (tmp)
    {

        if(tmp->code==code)
        {
            return tmp;
        }
        tmp=tmp->suivant;
    };
    return NULL;

}



void modifAuteur(auteur *amodif)
{
    fflush(stdin);
    printf("nom:\n");
    gets(amodif->nom);
    fflush(stdin);
    strupr(amodif->nom);
    printf("prenom :\n");
    gets(amodif->prenom);
    printf("adresse :\n");
    gets(amodif->adresse);
    fflush(stdin);
}

void pushAuteur(int code,char nom[32],char prenom[32],char adresse[100])
{

    auteur *tmp=NULL;
    auteur *tmp1=(auteur *)malloc(sizeof(auteur));
    if (tmp1==NULL)
    {
        system("cls");
        printf("probleme de memoire");
        exit(EXIT_FAILURE);
    }
    auteur *tmp2=pileAuteur;
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
    else pileAuteur=tmp1;
}


/*void affichemembre(Membre *M)
{
    printf("code: %d \n",M->code);
    printf("nom : %s \n",M->nom);
    printf("prenom: %s \n",M->prenom);
}*/

void saisieAuteur()
{
    int code,i;
    char nom[32];
    char prenom[32];
    char adresse[100];

debutsaisie:

    system("cls");
    fflush(stdin);
    printf("code : ");
    scanf("%d",&code); fflush(stdin);
    if (rechercheAuteur(code))
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
            modifAuteur(rechercheAuteur(code)); enregistrerAuteur();
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
    printf("nom : \n");
    gets(nom); fflush(stdin);
    strupr(nom);
    printf("prenom : \n");
    gets(prenom); fflush(stdin);
    printf("adresse :\n");
    gets(adresse); fflush(stdin);

menuvad:
    MenuValidation();
    GetChoix();
    if (choix=='V'||choix=='v')
    {
        pushAuteur(code,nom,prenom,adresse);
        enregistrerAuteur();
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

void enregistrerAuteur() /*enregistrement dans un fichier, elle sera appel\x82 à chaque fin de saisi*/
{
    auteur *tmp=pileAuteur;
    FILE *f;
    f=fopen("auteur.dat","wb");
    while (tmp)
    {
        fwrite(tmp, sizeof(auteur),1, f);
        tmp=tmp->suivant;

    }
    fclose (f);
    return;
}

void chargerAuteur()
{
   viderauteur();
    auteur *tmp = (auteur *) malloc( sizeof(auteur));
    FILE *f;
    f=fopen("auteur.dat","rb");
    if(f!=NULL)
    {
        while (!feof(f))
        {

            fread(tmp, sizeof(auteur),1, f);
            /*après la lecture de la dernière salle du fichier, fread ne renvoie pas un erreur ni feof, mais
             sont dernier appel, g\x82nère une erreur parce que le fichier est atteint
             c'est pour ça qu'il est nec\x82ssaire de mêtre break pour eviter d'afficher deux fois la deriniere salle*/
            if (feof(f)) break;
            pushAuteur(tmp->code,tmp->nom, tmp->prenom,tmp->adresse);
        }
    }
}

void consuAuteur()
{

    short a;

consult:
    system("cls");
    printf("Entrer l'ID du membre : ");
    scanf("%hd",&a);
    fflush(stdin);
    if(rechercheAuteur(a)!=NULL)
    {
        afficheAuteur(rechercheAuteur(a));
        listerOuvrageParAuteur(a);
        fflush(stdin);
debuaff:
        TolotraModifSup();
        GetChoix();
        if (choix=='M'||choix=='m')
        {
            system("cls");
            modifAuteur(rechercheAuteur(a));
            enregistrerAuteur();
            Turquoise("     Modification terminée........\n");
            waitEnter();
            system("cls");
        }
        else if (choix=='S'||choix=='s')
        {
            supprrAuteur(rechercheAuteur(a));
            system("cls");
            Turquoise("\n   Suppression termin\x82e.......");
            enregistrerAuteur();
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
            goto debuaff;
        }
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("              cet element n'existe pas");w();
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
            case '2': listerAureur();waitEnter();consuAuteur();break;
            case '3': goto fin;break;
            default :{r();printf("\n\n    Veuiller saisir le bon numero!!");w();waitEnter();system("cls");goto misafidy;}break;
        }

    }
fin:
    ;

}

void menue_auteur()
{


    chargerAuteur();
    printf("");
    attendre();


SousMenuauteur:

    SetConsoleTitle("AUTEUR");
    SousMenu();
    GetChoix();
    switch (choix)
    {
        case '1':

            {saisieAuteur();
             //enregistrerAuteur();
            waitEnter();
            system("cls");
            goto SousMenuauteur;
            }
        break;
        case '2':
        {
            consuAuteur();
            waitEnter();
            system("cls");
            goto SousMenuauteur;
        }
        break;
        case '3':
        {
            system("cls");
            listerAureur();
            waitEnter();
            system("cls");
            goto SousMenuauteur;
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
            goto SousMenuauteur;
        }break;
    }


ending:

    ;
}







