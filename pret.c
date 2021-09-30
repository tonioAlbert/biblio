#include"pret.h"




Pret *pilepret=NULL;


char choix;

andro niany;

andro calcret(andro today) //Cette fonction permet de calculer
{                          //automatiquement la date de retour prevu a partir de la date de pret.
    int a;
    andro resultat;
    if ((today.mois==1)||(today.mois==3)||(today.mois==5)||(today.mois==7)||(today.mois==8)||(today.mois==10))
    {
        a=31-today.jour;
    calcauto:
        if(a<7)
        {
            resultat.jour=7-a;
            resultat.mois=1+today.mois;
            resultat.annee=today.annee;
            return resultat;
        }
        else
        {
            resultat.jour=7+today.jour;
            resultat.mois=today.mois;
            resultat.annee=today.annee;
            return resultat;
        }
    }
    else if (today.mois==2)
    {
        if(today.annee%4==0)
        {
            a=29-today.jour;
            goto calcauto;

        }
        else
        {
            a=28-today.jour;
            goto calcauto;

        }
    }
    else if (today.mois==12)
    {

        a=31-today.jour;

        if(a<7)
        {
            resultat.jour=7-a;
            resultat.mois=1;
            resultat.annee=1+today.annee;
            return resultat;
        }
        else
        {
            resultat.jour=7+today.jour;
            resultat.mois=today.mois;
            resultat.annee=today.annee;
            return resultat;
        }
    }
    else
    {
        a=30-today.jour;
        goto calcauto;

    }

}

void viderpret()
{
    Pret *tmp;
    while(pilepret != NULL)
    {
        tmp = pilepret->suivant;
pilepret = NULL;
        free(pilepret);/*On libere la place occupée par le dernier pointeur*/

        pilepret=tmp;/*On reposition la PileEnseignant pour qu'il pointe toujours sur le dernier element*/
    }
}


void supprrpretpret(Pret* P)
{
if(P==NULL) return;
    Pret *tmp=pilepret;//tmp est la varriable que l'on declare pou parcourir la liste chainé

    if(P==pilepret)//si le membre se trouve en debut de la pile
    {

        pilepret=P->suivant;
        P=NULL;
        free(P);
    }
    else  //mais si il se trouve dans une place quelconque
    {
        while (tmp)
        {

            if((tmp->suivant!=NULL)&&tmp->suivant==P)
            {
                tmp->suivant=P->suivant;
                P=NULL;
                free(P);
            };
            tmp=tmp->suivant;
        }
    }


}

void affichepret(Pret *P)
{
    int i=0;
    char str[4],datepret[12],dateret[12],nomlect[100];
    sprintf(str,"%03d",P->code);
    livre *L=rechercheLivre(P->cotelivre);
    Membre *M=rechercheMembre(P->codelecteur);
    strcpy(nomlect,M->nom);
    strcat(nomlect," ");
    sprintf(datepret,"%02d/%02d/%04d",P->datePret.jour,P->datePret.mois,P->datePret.annee);
    sprintf(dateret,"%02d/%02d/%04d",P->dateRetourPrev.jour,P->dateRetourPrev.mois,P->dateRetourPrev.annee);
    system("cls");
    printf("\n\n\n\n\t\t\t\xC9");
    for (i=0;i<40;i++) printf("\xCD");
    printf("\xBB\n");
    printf("\t\t\t\xBA");
    printf("  Code        : ");Turquoise(str);calcspace("000",24);printf("\n");
    printf("\t\t\t\xBA");
    printf("  Livre       : ");Turquoise(L->titre);calcspace(L->titre,24);printf("\n");
    printf("\t\t\t\xBA");
    printf("  Lecteur     : ");Turquoise(strcat(nomlect,M->prenom));calcspace(nomlect,24);printf("\n");
    printf("\t\t\t\xBA");
    printf("  Date de pret: ");Turquoise(datepret);calcspace(datepret,24);printf("\n");
    printf("\t\t\t\xBA");
    printf("  Date de retour PREVU: ");Turquoise(dateret);calcspace(dateret,16);printf("\n");
    printf("\t\t\t\xBA");
    printf("  Etat pret   : ");
    if (P->etat==0)
    {
        r();printf("NON RESTITUE");w();
        calcspace("NON RESTITUE",24); printf("\n");

    }
    else
    {
        Turquoise("RESTITUE");
        calcspace("RESTITUE",24);printf("\n");
    }

    printf("\t\t\t\xC8");

    for (i=0;i<40;i++) printf("\xCD");
    printf("\xBC\n");
}


void listerpret( )
{
    if (pilepret==NULL)
    {
        system("cls");color(15);printf("le fichier est vierge\n");
    }
    else
    {
        Pret *actuel=pilepret; int i; char str[4],clect[4],clivre[4],datepret[12],dateret[12];
        printf("+---------------------+\n");
        printf("|");color(27);printf("   LISTE des PRETS   ");w();printf("|\n");
        printf("+---------------------+\n");
        printf("\n\n     \xC9");
        for(i=0; i<68; i++)
        {
            if ((i==6)|| (i==21) || (i==35) || (i==52)) printf("\xCB");
            else printf("\xCD");
        };
        printf("\xBB"); /*tracer la ligne*/
        printf("\n     \xBA CODE \xBA ");printf("CODE LECTEUR \xBA");printf(" ");printf("CODE LIVRE  \xBA");printf("    DATE PRET   \xBA DATE RETOUR   \xBA");
        printf("\n     \xCC");
        for(i=0; i<68; i++)
        {
            if ((i==6)|| (i==21) || (i==35) || (i==52)) printf("\xCE");
            else printf("\xCD");
        };
        printf("\xB9");
        while (actuel!=NULL)
        {
            sprintf(str,"%03d",actuel->code);
            sprintf(clect,"%03d",actuel->codelecteur);
            sprintf(clivre,"%03d",actuel->cotelivre);
            sprintf(datepret,"%02d/%02d/%04d",actuel->datePret.jour,actuel->datePret.mois,actuel->datePret.annee);
            sprintf(dateret,"%02d/%02d/%04d",actuel->dateRetourPrev.jour,actuel->dateRetourPrev.mois,actuel->dateRetourPrev.annee);
            printf("\n     \xBA   ");Turquoise(str);printf("\xBA           ");Turquoise(clect);printf("\xBA          ");Turquoise(clivre);printf("\xBA      ");Turquoise(datepret);printf("\xBA     ");Turquoise(dateret);printf("\xBA");
            actuel=actuel->suivant;
        }
        printf("\n     \xC8");
        for(i=0; i<68; i++)
        {
            if ((i==6)|| (i==21) || (i==35) || (i==52)) printf("\xCA");
            else printf("\xCD");
        }
        printf("\xBC\n");
    }
}

Pret *recherchepret(int code)
{

    Pret *tmp=pilepret;

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

Pret *recherchePretparlect(int codelect)
{

    Pret *tmp=pilepret;

    while (tmp)
    {

        if(tmp->codelecteur==codelect)
        {
            return tmp;
        }
        tmp=tmp->suivant;
    };
    return NULL;

}

Pret *recherchePretparlivre(int cote)
{

    Pret *tmp=pilepret;

    while (tmp)
    {

        if(tmp->cotelivre==cote)
        {
            return tmp;
        }
        tmp=tmp->suivant;
    };
    return NULL;

}

void modifpret(Pret *P)
{
    daty *tp;
    time_t *t;
    time(t);
    tp=malloc(sizeof(daty));
    tp=localtime(t);
    tp->tm_year=1900+tp->tm_year;
    fflush(stdin);
    printf("code lecteur:\n");
    gets(P->codelecteur);
    fflush(stdin);
    printf("cote livre :\n");
    gets(P->cotelivre); fflush(stdin);
    printf(" DATE PRET:\n");
    printf(" jour: "); fflush(stdin);
    scanf("%d",P->datePret.jour);
    printf(" mois: ");
    scanf("%d",P->datePret.mois);
    fflush(stdin);
    P->datePret.annee=tp->tm_year;
    printf("anne : %d",P->datePret.annee);
    P->dateRetourPrev=calcret(P->datePret);
    printf("  Date de retour pret : %02d/%02d/%04d\n",P->dateRetourPrev.jour,P->dateRetourPrev.mois,P->dateRetourPrev.annee); waitEnter();
}

void pushPret(int code,int clect,int clivre,andro dateP,andro dateRp,andro dateRE,int etat)
{

    Pret *tmp=NULL;
    Pret *tmp1=(Pret *)malloc(sizeof(Pret));
    if (tmp1==NULL)
    {
        system("cls");
        printf("probleme de memoire");
        exit(EXIT_FAILURE);
    }
    Pret *tmp2=pilepret;
    while (tmp2 && tmp2->code<code)
    {
        tmp=tmp2;
        tmp2=tmp2->suivant;
    }
    tmp1->suivant=tmp2;
    tmp1->code=code;
    tmp1->codelecteur=clect;
    tmp1->cotelivre=clivre;
    tmp1->datePret=dateP;
    tmp1->dateRetourPrev=dateRp;
    tmp1->dateRetourEff=dateRE;
    tmp1->etat=etat;
    if (tmp)
    {
        tmp->suivant=tmp1;
    }
    else pilepret=tmp1;
}

void androniany()
{
    daty *dt;
    time_t d;
    time(&d);
    dt=malloc(sizeof(daty));
    dt=localtime(&d);
    dt->tm_year=1900+dt->tm_year;
    dt->tm_mon+=1;
    niany.jour=dt->tm_mday;
    niany.mois=dt->tm_mon;
    niany.annee=dt->tm_year;
}




void saisiepret()
{
    int code,clect,clivre,i,etat;
    andro dateP,dateRP,dateRE;
debutsaisie:

    system("cls");
    fflush(stdin);
    printf("+-------------------------+\n");
    printf("|");color(27);printf("      Saisie des prets   ");w();printf("|\n");
    printf("+-------------------------+\n");
    printf("\n\n\n\n\t\t");

    color(159);
    printf("  code               :\n"); w();
    printf("\t\t");
    printf("                                                        \n");w();
    printf("\t\t");
    color(159);
    printf("  Code lecteur       :\n"); w();
    printf("\t\t");

    printf("                                                        \n");w();
    printf("\t\t");
    color(159);
    printf("  Cote livre         :\n"); w();
    printf("\t\t");

    printf("                                                        \n");w();
    printf("\t\t");
    color(159);
    printf("  Date pret          :\n"); w();
    printf("\t\t");

    printf("                                                        \n");w();
    printf("\t\t");
    color(159);
    printf("  Date retour prevue :\n"); w();
x:
    gotoxy(40,7);
    printf("                 ");
    gotoxy(40,7); fflush(stdin);
    scanf("%03d",&code); fflush(stdin);

    if (recherchepret(code))
    {

misafidy:
        gotoxy(3,50);
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
            goto finSaisiepret;
        }
        else
        {
            r();beep();printf("\n            VEILLEZ SAISIR LE BON NUMERO");w();waitEnter();
            balayer_ecran(40,25);

            goto misafidy;
        }


    }
debutlect:
    gotoxy(40,9);
    printf("                                         ");
    gotoxy(40,9);
    scanf("%d",&clect);fflush(stdin);
    if (rechercheMembre(clect))
    {
        if (recherchePretparlect(clect)!=NULL && recherchePretparlect(clect)->etat==0)
        {
            gotoxy(0,20);
            Turquoise("le lecteur n'a pas encore retourner son dernier pret!\n le pret vas etre annule");w();
            goto finSaisiepret;
        }
        else
        {
            goto debutlivre;   //validation;
        }
    }
    else
    {
veriflect:
        balayer_ecran(17,30);
        gotoxy(0,20);

        Turquoise("\n\tCe code n'existe pas dans nos registre!\n\tVeuillez le verifier dans la liste ci-apres:\n");w();
        listerMembre();
        printf(" Est ce que le lecteur s'y trouve?  "); loko('O');printf(" / ");loko('N');printf("\n\t choix: ");fflush(stdin);
        GetChoix();fflush(stdin);
        if (choix=='o'||choix=='O')
        {
            balayer_ecran(20,17);
            j();printf("Veuillez saisir le bon code du lecteur");w();
            goto debutlect;
        }
        else if (choix=='n'||choix=='N')
        {
            Turquoise("Le pret va etre annule...");Sleep(1000);
            Turquoise("\nAppuyer sur ENTREE pour continuer.....");
            goto finSaisiepret;
        }
        else
        {
            r();printf("CHOIX INVALIDE!!!");w();Sleep(500);
            goto veriflect;
        }
    }

debutlivre:
   // balayer_ecran(20,20);
    gotoxy(40,11);
    printf("                                         ");
    gotoxy(40,11);
    scanf("%d",&clivre);fflush(stdin);
    if (rechercheLivre(clivre))
    {
        if (recherchePretparlivre(clivre)!=NULL && recherchePretparlivre(clivre)->etat==0)
        {
            gotoxy(0,20);
            Turquoise("le livre n'a pas encore ete raporté!\n le pret vas etre annule");w();
            goto finSaisiepret;
        }
        else
        {
            goto datejiaby;   //validation;
        }
    }
    else
    {
veriflivre:
        balayer_ecran(17,30);
        gotoxy(0,20);

        Turquoise("\n\tCe livre n'existe pas dans nos registre!\n\tVeuillez le verifier dans la liste ci-apres:\n");w();
        listerlivre();
        printf(" Est ce que le livre s'y trouve?  "); loko('O');printf(" / ");loko('N');printf("\n\t choix: ");fflush(stdin);
        GetChoix();fflush(stdin);
        if (choix=='o'||choix=='O')
        {
            balayer_ecran(20,17);
            j();printf("Veuillez saisir le bon cote du livre");w();
            goto debutlivre;
        }
        else if (choix=='n'||choix=='N')
        {
            Turquoise("Le pret va etre annule...");Sleep(1000);
            Turquoise("\nAppuyer sur ENTREE pour continuer.....");
            goto finSaisiepret;
        }
        else
        {
            r();printf("CHOIX INVALIDE!!!");w();Sleep(500);
            goto veriflivre;
        }
    }
datejiaby:


    dateP=niany;
    dateRP=calcret(dateP);
    dateRE.jour=0;
    dateRE.mois=0;
    dateRE.annee=0;
    etat=0;
    gotoxy(40,13);
    printf(" %02d/%02d/%04d\n",dateP.jour,dateP.mois,dateP.annee);
    gotoxy(40,15);
    printf(" %02d/%02d/%04d\n",dateRP.jour,dateRP.mois,dateRP.annee);


tolotraValider:
     MenuValidation();
    GetChoix();
    if (choix=='V'||choix=='v')
    {
        pushPret(code,clect,clivre,dateP,dateRP,dateRE,etat);
        enregistrerpret();
    }
    else if (choix=='M'||choix=='m')
    {
        goto debutsaisie;
    }
    else if (choix=='A'||choix=='a')
    {
        goto finSaisiepret;
    }
    else
    {
        r();printf("\n      CHOIX INVALIDE!!!  VEUILLEZ RESSAISIR\n");w(); waitEnter();
        balayer_ecran(17,20);
        goto tolotraValider;
    }




finSaisiepret:
;
}



Pret *pretmixte(int codemembre,int cotelivre)
{
    Pret *P=pilepret;

    int n;

    while (P)
    {
        if (P->codelecteur==codemembre&&P->cotelivre==cotelivre&&P->etat==0)
        {
            return P;
        }
        P=P->suivant;
    }
    return NULL;

}

int testdate(andro date1,andro date2)
{

   if ((date1.jour<date2.jour && date1.mois<=date2.mois && date1.annee<=date2.annee)||(date1.jour>=date2.jour && date1.mois<date2.mois && date1.annee<=date2.annee))
        return -1;
   else if (date1.jour==date2.jour&&date1.mois==date2.mois&&date1.annee==date2.annee)
    return 0;
    else
    return 1;

}

void restitution(Pret *P)
{
    P->etat=2;
}

int testpret(Pret *P)
{
    if(P!=NULL)
    return 0;
    else
    return 1;
}

void mamerina_boky()
{
    int cotelivre,codelecteur,i=0;
    Pret *testp = NULL;  //=(Pret *)malloc(sizeof(Pret));
     system("cls");
    /*fflush(stdin);
    printf("+-------------------------+\n");
    printf("|");color(27);printf("  Restitution de pret  ");w();printf("|\n");
    printf("+-------------------------+\n");
    printf("\n\n\n\n\t\t");*/


   /* while (testpret(testp)==0)
    {*/
debut_restit: //i++;
        if ( i == 5)
        {
            printf("\n\n\n\t Vous avez fait 5 erreur consecutif!\n\n\t Alors la restitution va etre annulee....\n");
            waitEnter();
            goto sortie_restit;
        }

        system("cls");
        fflush(stdin);
        printf("+-------------------------+\n");
        printf("|");color(27);printf("  Restitution de pret  ");w();printf("|\n");
        printf("+-------------------------+\n");
        printf("\n\n\n\n\t\t");
        color(159);
        printf("  Cote livre         :\n"); w();
        printf("\t\t");
        printf("                                                        \n");w();
        printf("\t\t");
        color(159);
        printf("  Code lecteur       :\n"); w();
        gotoxy(40,7);
        printf("                 ");
        gotoxy(40,7); fflush(stdin);
        scanf("%03d",&cotelivre); fflush(stdin);
        gotoxy(40,9);
        printf("                 ");
        gotoxy(40,9); fflush(stdin);
        scanf("%03d",&codelecteur); fflush(stdin);
        testp=pretmixte(codelecteur,cotelivre);

        if (testp == NULL)
        {
            i++;
            gotoxy(40,9);
            r();printf("\n\t\t VERIFIER BIEN VOTRE ORTOGRAPHE!......");w();
            waitEnter();
            goto debut_restit;


        }
         //i++;

    //}


    restitution(testp);

    enregistrerpret();

    Turquoise("\n\t\t Pret restituee....");
    waitEnter();

sortie_restit:

;
}

int recup_last_id()
{
    Pret *P=pilepret;

    if(P==NULL)
    {
        return 0;
    }

    while (P)
    {
        if(P->suivant==NULL)
        {
            if(P->datePret.mois<niany.mois)
            {
                return 0;
            }
            else
            {
                return P->code;
            }
        }
        P=P->suivant;
    }
}



void enregistrerpret() /*enregistrement dans un fichier, elle sera appel\x82 à chaque fin de saisi*/
{
   Pret *tmp=pilepret;
    FILE *f;
    f=fopen("pret.dat","wb");
    while (tmp)
    {
        fwrite(tmp, sizeof(Pret),1, f);
        tmp=tmp->suivant;

    }
    fclose (f);
    return;
}

void chargerpret()
{
   viderpret();
   Pret *tmp = (Pret *) malloc( sizeof(Pret));
    FILE *f;
    f=fopen("pret.dat","rb");
    if(f!=NULL)
    {
        while (!feof(f))
        {

            fread(tmp, sizeof(Pret),1, f);
            /*après la lecture de la dernière salle du fichier, fread ne renvoie pas un erreur ni feof, mais
             sont dernier appel, g\x82nère une erreur parce que le fichier est atteint
             c'est pour ça qu'il est nec\x82ssaire de mêtre break pour eviter d'afficher deux fois la deriniere salle*/
            if (feof(f)) break;
            pushPret(tmp->code,tmp->codelecteur, tmp->cotelivre,tmp->datePret,tmp->dateRetourPrev,tmp->dateRetourEff,tmp->etat);
        }
    }
}

void consupret()
{
    short a;

consult:
    system("cls");
    printf("\n\n\n\t\tEntrer le numero du pret : ");
    scanf("%hd",&a);
    fflush(stdin);
    if(recherchepret(a)!=NULL)
    {debuaff:
        affichepret(recherchepret(a));
        fflush(stdin);

        TolotraModifSup();
        GetChoix();
        if (choix=='M'||choix=='m')
        {
            system("cls");
            modifpret(recherchepret(a));
            enregistrerpret();
            Turquoise("     Modification terminée........\n");
            waitEnter();
            system("cls");
        }
        else if (choix=='S'||choix=='s')
        {
            supprrpretpret(recherchepret(a));
            system("cls");
            Turquoise("\n   Suppression terminée.......");
            enregistrerpret();
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
        r();
        printf("              cet element n'existe pas\n\n\t\tVERIFIER VOTRE ORTHOGRAPHE");w();
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
            case '2': listerpret();waitEnter();consupret();break;
            case '3': goto fin;break;
            default :{r();printf("\n\n    Veuiller saisir le bon numero!!");w();waitEnter();system("cls");goto misafidy;}break;
        }
    }
 fin:
    ;
}


int nombre_pret_non_ret_a_tps()
{
    Pret *P=pilepret;
    int n;
    while (P)
    {
        if (testdate(P->dateRetourPrev,niany)<1&&P->etat==0)
        {
            n++;
        }
        P=P->suivant;
    }
    return 0;
}

void pret()
{
    androniany();
    chargerpret();
    printf("");
    attendre();

    SetConsoleTitle("PRET");
SousMenuMembre:

    if (nombre_pret_non_ret_a_tps()>0)
    {
        Turquoise("\n\n\tLes pret suivant sont non restitue a temps :");
        Pret *actuel=pilepret; int i; char str[4],clect[4],clivre[4],datepret[12],dateret[12];
        printf("+---------------------+\n");
        printf("|");color(27);printf("   LISTE des PRETS   ");w();printf("|\n");
        printf("+---------------------+\n");
        printf("\n\n     \xC9");
        for(i=0; i<68; i++)
        {
            if ((i==6)|| (i==21) || (i==35) || (i==52)) printf("\xCB");
            else printf("\xCD");
        };
        printf("\xBB"); /*tracer la ligne*/
        printf("\n     \xBA CODE \xBA ");printf("CODE LECTEUR \xBA");printf(" ");printf("CODE LIVRE  \xBA");printf("    DATE PRET   \xBA DATE RETOUR   \xBA");
        printf("\n     \xCC");
        for(i=0; i<68; i++)
        {
            if ((i==6)|| (i==21) || (i==35) || (i==52)) printf("\xCE");
            else printf("\xCD");
        };
        printf("\xB9");
        while (actuel!=NULL)
        {
            if (testdate(actuel->dateRetourPrev,niany)<1&&actuel->etat==0)
            {
                sprintf(str,"%03d",actuel->code);
                sprintf(clect,"%03d",actuel->codelecteur);
                sprintf(clivre,"%03d",actuel->cotelivre);
                sprintf(datepret,"%02d/%02d/%04d",actuel->datePret.jour,actuel->datePret.mois,actuel->datePret.annee);
                sprintf(dateret,"%02d/%02d/%04d",actuel->dateRetourPrev.jour,actuel->dateRetourPrev.mois,actuel->dateRetourPrev.annee);
                printf("\n     \xBA   ");Turquoise(str);printf("\xBA           ");Turquoise(clect);printf("\xBA          ");Turquoise(clivre);printf("\xBA      ");Turquoise(datepret);printf("\xBA     ");Turquoise(dateret);printf("\xBA");
            }

            actuel=actuel->suivant;
        }
        printf("\n     \xC8");
        for(i=0; i<68; i++)
        {
            if ((i==6)|| (i==21) || (i==35) || (i==52)) printf("\xCA");
            else printf("\xCD");
        }
        printf("\xBC\n");
        Turquoise("\t Penser a les consulter");
        waitEnter();

    }

    system("cls");
    SousMenu_pret();
    GetChoix();
    switch (choix)
    {
        case '1':

            {saisiepret();
             //enregistrerpret();
            waitEnter();
            system("cls");
            goto SousMenuMembre;
            }
        break;
        case '2':
        {
            //consupret();
            mamerina_boky();
            //waitEnter();
            system("cls");
            goto SousMenuMembre;
        }
        break;
        case '3':
        {
            system("cls");
            listerpret();
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











