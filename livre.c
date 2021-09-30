#include"livre.h"



char choix;


livre *pilelivre=NULL;


void viderlivre()
{
    livre *tmpl;
    while(pilelivre != NULL)
    {
        tmpl = pilelivre->suivant;
pilelivre = NULL;
        free(pilelivre);/*On libere la place occupée par le dernier pointeur*/

        pilelivre=tmpl;/*On reposition la PileEnseignant pour qu'il pointe toujours sur le dernier element*/
    }
}


void supprlivre(livre* L)
{
    if(L==NULL) return;

    livre *tmpl=pilelivre;

    if(L==pilelivre)//si le membre se trouve en debut de la pile
    {

        pilelivre=L->suivant;
        L=NULL;
        free(L);
    }
    else  //mais si il se trouve dans une place quelconque
    {
        while (tmpl)
        {

            if((tmpl->suivant!=NULL)&&tmpl->suivant==L)
            {
                tmpl->suivant=L->suivant;
                L=NULL;
                free(L);
            };
            tmpl=tmpl->suivant;
        }
    }


}

void affichelivre(livre *L)
{
    int i=0;
    char str[4],couvsrc[4],dateed[12];
    //sprintf(str,"%03d",L->cote);
    //sprintf(couvsrc,"%03d",L->codeOuvrSourc);
    sprintf(dateed,"%04d",L->anneeEdition);
    system("cls");
    printf("\n\n\n\n\t\t\t\xC9");
    for (i=0;i<40;i++) printf("\xCD");
    printf("\xBB\n");
    printf("\t\t\t\xBA");
    printf("  Cote   : %03d",L->cote);calcspace("000",29);printf("\n");
    printf("\t\t\t\xBA");
    ouvrage *O=rechercheOuvrage(L->codeOuvrSourc);
    printf("  ouvrage source  : %s",O->titre);calcspace(O->titre,20);printf("\n");
    printf("\t\t\t\xBA");
    printf("  Titre  : %s",L->titre);calcspace(L->titre,29);printf("\n");
    printf("\t\t\t\xBA");
    printf("  Sujet  : %s",L->sujet);calcspace(L->sujet,29);printf("\n");
    printf("\t\t\t\xBA");
    printf("  Editeur: %s",L->editeur);calcspace(L->editeur,29);printf("\n");
    printf("\t\t\t\xBA");
    printf("  Anne d'edition: %s",dateed);calcspace(dateed,22);printf("\n");

    printf("\t\t\t\xC8");
    for (i=0;i<40;i++) printf("\xCD");
    printf("\xBC\n");
}
 /*color(10);
            printf("code :%d \n",actuel->code); color(01); color(03);
            printf("nom :%s \n",actuel->nom); color(03); color(02);
            printf("prenom :%s \n",actuel->prenom);color(30);color(02);*/

void listerlivre()
{
    if (pilelivre==NULL)
    {
        system("cls");color(15);printf("le fichier est vierge\n");
    }
    else
    {
        livre *actuel=pilelivre; int i; char str[4];
        printf("+---------------------+\n");
        printf("|");color(27);printf("    LISTE des LIVRES  ");w();printf("|\n");
        printf("+---------------------+\n");
        printf("\n\n   \xC9");

        for(i=0; i<68; i++)
        {
            if ((i==10)|| (i==39)) printf("\xCB");
            else printf("\xCD");
        };

        printf("\xBB"); /*tracer la ligne*/
        printf("\n   \xBA    COTE  \xBA\t\t ");printf("TITRE");calcspace("TITRE",18);printf("\t    ");printf("SUJET");calcspace("SUJET",20);
        printf("\n   \xCC");

        for(i=0; i<68; i++)
        {
            if ((i==10)|| (i==39)) printf("\xCE");
            else printf("\xCD");
        };

        printf("\xB9");

        while (actuel!=NULL)
        {
            sprintf(str,"%03d",actuel->cote);
            printf("\n   \xBA       ");Turquoise(str);printf("\xBA");printf("  ");Turquoise(actuel->titre);calcspace(actuel->titre,26);printf("  ");Turquoise(actuel->sujet);calcspace(actuel->sujet,26);


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

livre *rechercheLivre(int cote)
{

    livre *tmpl=pilelivre;

    while (tmpl)
    {

        if(tmpl->cote==cote)
        {
            return tmpl;
        }
        tmpl=tmpl->suivant;
    };
    return NULL;

}

void modiflivre(livre *amodif)
{
    fflush(stdin);
    printf ("code ouvrage source:\n");
    scanf("%d",&amodif->codeOuvrSourc); fflush(stdin);
    printf("titre:\n");
    gets(amodif->titre);
    fflush(stdin);
    printf("sujet :\n");
    gets(amodif->sujet);
    printf("editeur :\n");
    gets(amodif->editeur); fflush(stdin);
    printf("annee d'edition :\n");
    scanf("%d",&amodif->anneeEdition);
    fflush(stdin);
}

void pushlivre(int cote,int codeouvsrc,char titre[50],char sujet[50],char editeur[50],int anneEd)
{

    livre *tmpl=NULL;
    livre *tmpl1=(livre *)malloc(sizeof(livre));
    if (tmpl1==NULL)
    {
        system("cls");
        printf("probleme de memoire");
        exit(EXIT_FAILURE);
    }
    livre *tmpl2=pilelivre;
    while (tmpl2 && tmpl2->cote<cote)
    {
        tmpl=tmpl2;
        tmpl2=tmpl2->suivant;
    }
    tmpl1->suivant=tmpl2;
    tmpl1->cote=cote;
    tmpl1->codeOuvrSourc=codeouvsrc;
    strcpy(tmpl1->titre,titre);
    strcpy(tmpl1->sujet,sujet);
    strcpy(tmpl1->editeur,editeur);
    tmpl1->anneeEdition=anneEd;
    if (tmpl)
    {
        tmpl->suivant=tmpl1;
    }
    else pilelivre=tmpl1;
}


/*void affichemembre(Membre *M)
{
    printf("code: %d \n",M->code);
    printf("nom : %s \n",M->nom);
    printf("prenom: %s \n",M->prenom);
}*/

void saisielivre()
{
    int cote,i;
    char titre[50];
    char sujet[50];
    char editeur[50];
    int anneEd,codeouvsrc;

debutsaisie:

    system("cls");
    fflush(stdin);
    printf("cote : ");
    scanf("%d",&cote); fflush(stdin);
    if (rechercheLivre(cote))
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
            modiflivre(rechercheLivre(cote)); enregistrerlivre();
        }
        else if (choix=='2')
        {
            system("cls");
            goto debutsaisie;
        }
        else if (choix=='3')
        {
            goto finSaisielivre;
        }
        else
        {
            r();printf("\n            VEILLEZ SAISIR LE BON NUMERO");w(); waitEnter();
            goto misafidy;
        }

    }
saisiecodeouvrage:

    printf("code ouvrage source:\n");
    scanf("%d",&codeouvsrc);fflush(stdin);
    if (rechercheOuvrage(codeouvsrc))
    {
        goto fincond;
    }
    else
    {
  choisir:
        system("cls");
        printf("\n\n\n\n\t\t\t");
        w();printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",0xC9,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xBB);
        printf("\t\t\t%c                             %c\n\t\t\t%c",0xBA,0xBA,0xBA);
        r();printf(" CET ELEMENT N'EXISTE PAS!!  ");w();
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
        printf("\t\t\  \xBA ");loko('1');printf("-Resaisir   ");loko('2');printf("-Liste ouvrage   ");loko('3');printf("-Sortir \xBA\n");
        printf("\t\t\  \xC8");
        for (i=0;i<41;i++)
        {
            printf("\xCD");
        }
        printf("\xBC\n\n\t\t\t Choix: ");
        GetChoix();fflush(stdin);
        switch(choix)
        {
            case '1': goto saisiecodeouvrage;break;
            case '2': system("cls");listerOuvrage();goto saisiecodeouvrage;break;
            case '3': goto finSaisielivre;
            default : {
            r();printf("\n            VEILLEZ SAISIR LE BON NUMERO");w(); waitEnter();
            goto choisir;
        }break;
        }
    }

 fincond:
    printf("titre : \n");
    gets(titre); fflush(stdin);
    printf("sujet : \n");
    gets(sujet); fflush(stdin);

editeurr:
    printf("Editeur : \n");
    saisie(editeur,50); fflush(stdin);
        if (rechercheEditeur(editeur))
    {

        goto annee;
    }
    else
    {
  fidy:
        system("cls");
        printf("\n\n\n\n\t\t\t");
        w();printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",0xC9,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xBB);
        printf("\t\t\t%c                             %c\n\t\t\t%c",0xBA,0xBA,0xBA);
        r();printf(" CET ELEMENT N'EXISTE PAS!!  ");w();
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
        printf("\t\t\  \xBA ");loko('1');printf("-Resaisir   ");loko('2');printf("-Liste editeurs   ");loko('3');printf("-Sortir \xBA\n");
        printf("\t\t\  \xC8");
        for (i=0;i<41;i++)
        {
            printf("\xCD");
        }
        printf("\xBC\n\n\t\t\t Choix: ");
        GetChoix();fflush(stdin);
        switch(choix)
        {
            case '1': goto editeurr;break;
            case '2': system("cls");listerEditeur();goto editeurr;break;
            case '3': goto finSaisielivre;
            default : {
            r();printf("\n            VEILLEZ SAISIR LE BON NUMERO");w(); waitEnter();
            goto fidy;
        }break;
        }
    }

annee:
    printf("annee d'edition :\n");
    scanf("%d",&anneEd);fflush(stdin);
    daty *tp;
    time_t t;
    time(&t);
    tp=malloc(sizeof(daty));
    tp=localtime(&t);
    tp->tm_year=1900+tp->tm_year;
    if (anneEd>tp->tm_year)
    {
        r();printf("anne invalide!!!\n");w();
        goto annee;
    }


menuvad:
    MenuValidation();
    GetChoix();
    if (choix=='V'||choix=='v')
    {
        pushlivre(cote,codeouvsrc,titre,sujet,rechercheEditeur(editeur)->RaisonSociale,anneEd);
        enregistrerlivre();
    }
    else if (choix=='M'||choix=='m')
    {
        goto debutsaisie;
    }
    else if (choix=='A'||choix=='a')
    {
        goto finSaisielivre;
    }
    else
    {
        r();printf("\n      CHOIX INVALIDE!!!  VEUILLEZ RESSAISIR\n");w(); waitEnter();
        goto menuvad;
    }

finSaisielivre:
    ;
}

void enregistrerlivre() /*enregistrement dans un fichier, elle sera appel\x82 à chaque fin de saisi*/
{
    livre *tmpl=pilelivre;
    FILE *f;
    f=fopen("livre.dat","wb");
    while (tmpl)
    {
        fwrite(tmpl, sizeof(livre),1, f);
        tmpl=tmpl->suivant;

    }
    fclose (f);
    return;
}

void chargerlivre()
{
   viderlivre();
    livre *tmpl = (livre *) malloc( sizeof(livre));
    FILE *f;
    f=fopen("livre.dat","rb");
    if(f!=NULL)
    {
        while (!feof(f))
        {

            fread(tmpl, sizeof(livre),1, f);
            /*après la lecture de la dernière salle du fichier, fread ne renvoie pas un erreur ni feof, mais
             sont dernier appel, g\x82nère une erreur parce que le fichier est atteint
             c'est pour ça qu'il est nec\x82ssaire de mêtre break pour eviter d'afficher deux fois la deriniere salle*/
            if (feof(f)) break;
            pushlivre(tmpl->cote,tmpl->codeOuvrSourc,tmpl->titre, tmpl->sujet,tmpl->editeur,tmpl->anneeEdition);
        }
    }
}

void consuLivre()
{
    short a;

consult:
    system("cls");
    printf("Entrer le cote du livre : ");
    scanf("%hd",&a);
    fflush(stdin);
    if(rechercheLivre(a)!=NULL)
    {
        affichelivre(rechercheLivre(a));
        fflush(stdin);
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED|FOREGROUND_INTENSITY);
        printf("              cet element n'existe pas");w();
        waitEnter();
        goto consult;
    }
}

void menue_livre()
{
    chargerlivre();
    printf("");
    attendre();
    SetConsoleTitle("LIVRE");

SousMenuMembre:

    SousMenu();
    GetChoix();
    switch (choix)
    {
        case '1':

            {saisielivre();
             //enregistrerAuteur();
            waitEnter();
            system("cls");
            goto SousMenuMembre;
            }
        break;
        case '2':
        {
            consuLivre();
            waitEnter();
            system("cls");
            goto SousMenuMembre;
        }
        break;
        case '3':
        {
            system("cls");
            listerlivre();
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








