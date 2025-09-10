#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int cmp = 0;
int i = 0;
int ran;
char x[15] = "x";
char search[15];
int searche_id;
char searche_nom[15];
int choix_supprime;
int ajoute_joueurs();
int ajoute_one();
int ajoute_plusieurs();
int affiche_contact();
int tri_alphabe();
int tri_age();
int tri_poste();
int modifie_joueurs();
int modifie_poste();
int modifie_age();
int modofie_buts();
int supprime_joueurs();
int supprime(int s);
int recherche_joueurs();
int recherche_id();
int recherche_nom();
int statistique();
int nomber_total();
int moyen_age();
int plus_marque();
int milleur_joueurs();
int plus_jeune_age();

typedef struct
{
    char nom[100][100];
    char prenom[100][100];
    int age[100];
    char post[100][100];
    int buts[100];
    int statut[100];
    int id[100];
    int numeroMaillot[100];
} joueurs;
joueurs jeu;
int main()
{
    int choice;
    do
    {
        printf("====================== Gestion d’une Équipe de Football===========================\n");
        printf("1_AJOUT UN JOUEURS\n2_AFFICHEER LES JOUEURS\n3_MODIFIER UN JOUEUR\n4_SUPPRIMER UN JOUEUR\n5_RECHERCHER UN JOUEUR\n6_STATISTIQUE\n");
        printf(">>> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            ajoute_joueurs();
            break;
        case 2:
            system("cls");
            affiche_contact();
            break;
        case 3:
            system("cls");
            modifie_joueurs();
            break;
        case 4:
            system("cls");
            supprime_joueurs();
            break;
        case 5:
            system("cls");
            recherche_joueurs();
            break;
        case 6:
            system("cls");
            statistique();
            break;
        default:
            printf("choice invalid !!");
            break;
        }
    } while (choice != 0);
}
int ajoute_joueurs()
{
    int choice2;
    printf("================= ajoute =================\n");
    printf("1_AJOUTE UN JOUEUR\n2_AJOUTE PLUSIEURS JOUEURS\n>>> ");
    scanf("%d", &choice2);
    switch (choice2)
    {
    case 1:
        system("cls");
        ajoute_one();

        break;
    case 2:
        system("cls");
        ajoute_plusieurs();

        break;
    default:
        printf("choice invalid !!");
        break;
    }
}
int ajoute_one()
{
    getchar();
    printf("nom : ");
    fgets(jeu.nom[i], sizeof(jeu.nom), stdin);
    printf("prenom : ");
    fgets(jeu.prenom[i], sizeof(jeu.prenom), stdin);
    printf("age : ");
    scanf("%d", &jeu.age[i]);
    getchar();
    printf("post  (gardien, defenseur, milieu, attaquant): ");
    fgets(jeu.post[i], sizeof(jeu.post), stdin);
    printf("buts : ");
    scanf("%d", &jeu.buts[i]);
    printf("numeroMaillot : ");
    scanf("%d", &jeu.numeroMaillot[i]);
    printf("statut (1/ titulaire)(2/ remplacant) : ");
    scanf("%d", &jeu.statut[i]);
    srand(time(NULL));
    ran = rand() % 9999 + 10000;
    jeu.id[i] = ran;

    i++;
    cmp++;
}
int ajoute_plusieurs()
{
    int houmuch;
    printf("nomber de joueurs : \n");
    scanf("%d", &houmuch);
    for (int u = i; u < houmuch; u++)
    {
        printf("joueurs %d : \n", u + 1);
        getchar();
        printf("nom : ");
        fgets(jeu.nom[u], sizeof(jeu.nom), stdin);
        printf("prenom : ");
        fgets(jeu.prenom[u], sizeof(jeu.prenom), stdin);
        printf("age : ");
        scanf("%d", &jeu.age[u]);
        getchar();
        printf("post (gardien, defenseur, milieu, attaquant): ");
        fgets(jeu.post[u], sizeof(jeu.post), stdin);
        printf("buts : ");
        scanf("%d", &jeu.buts[u]);
        printf("numeroMaillot : ");
        scanf("%d", &jeu.numeroMaillot[u]);
        printf("statut (1/ titulaire)(2/ remplacant) : ");
        scanf("%d", &jeu.statut[u]);

        srand(time(NULL));
        ran = rand() % 9999 + 10000;

        jeu.id[u] = ran;

        cmp++;
    }
}
int affiche_contact()
{
    int choice3;
    printf("1_affiche tri par alphabe\n2_affiche tri pare age\n3_affiche tri par poste\n>>> ");
    scanf("%d", &choice3);
    switch (choice3)
    {
    case 1:
        system("cls");
        tri_alphabe();
        break;
    case 2:
        system("cls");
        tri_age();
        break;
    case 3:
        tri_poste();
        break;
    default:
        printf("choice invalid !!");
        break;
    }
}
int tri_alphabe()
{

    for (int c = 0; c < cmp; c++)
    {
        char x = c;
        for (int g = c; g < cmp; g++)
        {
            if (jeu.nom[g][0] < jeu.nom[x][0])
            {
                x = g;
            }
        }
        char swap[6];
        strcpy(swap, jeu.nom[c]);
        strcpy(jeu.nom[c], jeu.nom[x]);
        strcpy(jeu.nom[x], swap);

        char swap2[6];
        strcpy(swap2, jeu.prenom[c]);
        strcpy(jeu.prenom[c], jeu.prenom[x]);
        strcpy(jeu.prenom[x], swap2);

        char swap3[6];
        strcpy(swap3, jeu.post[c]);
        strcpy(jeu.post[c], jeu.post[x]);
        strcpy(jeu.post[x], swap3);

        int swap4;
        swap4 = jeu.statut[c];
        jeu.statut[c] = jeu.statut[x];
        jeu.statut[x] = swap4;

        int swap5;
        swap5 = jeu.age[c];
        jeu.age[c] = jeu.age[x];
        jeu.age[x] = swap5;

        int swap6;
        swap6 = jeu.buts[c];
        jeu.buts[c] = jeu.buts[x];
        jeu.buts[x] = swap6;

        int swap7;
        swap7 = jeu.id[c];
        jeu.id[c] = jeu.id[x];
        jeu.id[x] = swap7;

        int swap8;
        swap8 = jeu.numeroMaillot[c];
        jeu.numeroMaillot[c] = jeu.numeroMaillot[x];
        jeu.numeroMaillot[x] = swap8;
    }
    for (int f = 0; f < cmp; f++)
    {
        printf("============ les joueurs %d ============\n", f + 1);
        printf("//=> nom : %s", jeu.nom[f]);
        printf("//=> prenom :%s", jeu.prenom[f]);
        printf("//=> age : %d \n", jeu.age[f]);
        printf("//=> post (gardien, defenseur, milieu, attaquant) : %s", jeu.post[f]);
        printf("//=> buts : %d \n", jeu.buts[f]);

        if (jeu.statut[f] == 1)
        {
            strcpy(x, "titulare");
        }
        else if (jeu.statut[f] == 2)
        {
            strcpy(x, "remplacant");
        }
        printf("//=> status : %s\n", x);
        printf("//=> numeroMaillot : %d \n", jeu.numeroMaillot[f]);
        printf("//=> ID : %d \n", jeu.id[f]);
    }
}
int tri_age()
{
    for (int e = 0; e < cmp; e++)
    {
        char x = e;
        for (int g = e; g < cmp; g++)
        {
            if (jeu.age[g] < jeu.age[x])
            {
                x = g;
            }
        }
        char swap[6];
        strcpy(swap, jeu.nom[e]);
        strcpy(jeu.nom[e], jeu.nom[x]);
        strcpy(jeu.nom[x], swap);

        char swap2[6];
        strcpy(swap2, jeu.prenom[e]);
        strcpy(jeu.prenom[e], jeu.prenom[x]);
        strcpy(jeu.prenom[x], swap2);

        char swap3[6];
        strcpy(swap3, jeu.post[e]);
        strcpy(jeu.post[e], jeu.post[x]);
        strcpy(jeu.post[x], swap3);

        int swap4;
        swap4 = jeu.statut[e];
        jeu.statut[e] = jeu.statut[x];
        jeu.statut[x] = swap4;

        int swap5;
        swap5 = jeu.age[e];
        jeu.age[e] = jeu.age[x];
        jeu.age[x] = swap5;

        int swap6;
        swap6 = jeu.buts[e];
        jeu.buts[e] = jeu.buts[x];
        jeu.buts[x] = swap6;

        int swap7;
        swap7 = jeu.id[e];
        jeu.id[e] = jeu.id[x];
        jeu.id[x] = swap7;

        int swap8;
        swap8 = jeu.numeroMaillot[e];
        jeu.numeroMaillot[e] = jeu.numeroMaillot[x];
        jeu.numeroMaillot[x] = swap8;
    }
    for (int f = 0; f < cmp; f++)
    {
        printf("============ les joueurs %d ============\n", f + 1);
        printf("//=> nom : %s", jeu.nom[f]);
        printf("//=> prenom :%s ", jeu.prenom[f]);
        printf("//=> age : %d \n", jeu.age[f]);
        printf("//=> post : %s", jeu.post[f]);
        printf("//=> buts : %d \n", jeu.buts[f]);

        if (jeu.statut[f] == 1)
        {
            strcpy(x, "titulare");
        }
        else if (jeu.statut[f] == 2)
        {
            strcpy(x, "remplacant");
        }
        printf("//=> status : %s \n", x);
        printf("//=> numeroMaillot : %d \n", jeu.numeroMaillot[f]);
        printf("//=> ID : %d \n", jeu.id[f]);
    }
}
int tri_poste()
{
    for (int d = 0; d < 6; d++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            if (jeu.post[i][0] == jeu.post[j][0])
            {
                char swap[6];
                strcpy(swap, jeu.post[i + 1]);
                strcpy(jeu.post[i + 1], jeu.post[j]);
                strcpy(jeu.post[j], swap);

                char swap2[6];
                strcpy(swap2, jeu.nom[i + 1]);
                strcpy(jeu.nom[i + 1], jeu.nom[j]);
                strcpy(jeu.nom[j], swap2);

                char swap3[6];
                strcpy(swap3, jeu.prenom[i + 1]);
                strcpy(jeu.prenom[i + 1], jeu.prenom[j]);
                strcpy(jeu.prenom[j], swap3);

                int swap4;
                swap4 = jeu.statut[i + 1];
                jeu.statut[i + 1] = jeu.statut[j];
                jeu.statut[j] = swap4;

                int swap5;
                swap5 = jeu.age[i + 1];
                jeu.age[i + 1] = jeu.age[j];
                jeu.age[j] = swap5;

                int swap6;
                swap6 = jeu.buts[i + 1];
                jeu.buts[i + 1] = jeu.buts[j];
                jeu.buts[j] = swap6;

                int swap7;
                swap7 = jeu.id[i + 1];
                jeu.id[i + 1] = jeu.id[j];
                jeu.id[j] = swap7;

                int swap8;
                swap8 = jeu.numeroMaillot[i + 1];
                jeu.numeroMaillot[i + 1] = jeu.numeroMaillot[j];
                jeu.numeroMaillot[j] = swap8;
            }
        }
    }
    for (int f = 0; f < cmp; f++)
    {
        printf("============ les joueurs %d ============\n", f + 1);
        printf("//=> nom : %s", jeu.nom[f]);
        printf("//=> prenom :%s", jeu.prenom[f]);
        printf("//=> age : %d \n", jeu.age[f]);
        printf("//=> post : %s", jeu.post[f]);
        printf("//=> buts : %d \n", jeu.buts[f]);

        if (jeu.statut[f] == 1)
        {
            strcpy(x, "titulare");
        }
        else if (jeu.statut[f] == 2)
        {
            strcpy(x, "remplacant");
        }
        printf("//=> status : %s \n", x);
        printf("//=> numeroMaillot : %d \n", jeu.numeroMaillot[f]);
        printf("//=> ID : %d \n", jeu.id[f]);
    }
}
int modifie_joueurs()
{
    int choice4;
    printf("1_Modifier le poste d’un joueur\n2_Modifier l’âge d’un joueur\n3_Modifier le nombre de buts marqués par un joueur\n>>> ");
    scanf("%d", &choice4);
    switch (choice4)
    {
    case 1:
        system("cls");
        modifie_poste();
        break;
    case 2:
        system("cls");
        modifie_age();
        break;
    case 3:
        system("cls");
        modofie_buts();
    default:
        break;
    }
}
int modifie_poste()
{

reapit:
    printf("nom de ID : ");
    scanf("%d", &searche_id);
    for (int s = 0; s < cmp; s++)
    {

        if (searche_id == jeu.id[s])
        {
            getchar();
            printf("nouvelle poste : ");
            fgets(jeu.post[s], 15, stdin);
            break;
        }
        else
        {
            printf("try again !!\n");
            goto reapit;
        }
    }
}
int modifie_age()
{

reapit_age:
    printf("nom de ID : ");
    scanf("%d", &searche_id);
    for (int s = 0; s < cmp; s++)
    {

        if (searche_id == jeu.id[s])
        {

            printf("nouvelle age : ");
            scanf("%d", &jeu.age[s]);
        }
        else
        {
            printf("try again !!\n");
            goto reapit_age;
        }
    }
}
int modofie_buts()
{

reapit_buts:
    printf("nom de ID : ");
    scanf("%d", &searche_id);
    for (int s = 0; s < cmp; s++)
    {

        if (searche_id == jeu.id[s])
        {
            printf("nouvelle buts : ");
            scanf("%d", &jeu.buts[s]);
        }
        else
        {
            printf("try again !!\n");
            goto reapit_buts;
        }
    }
}
int supprime_joueurs()
{
reaplit4:
    printf("id : ");
    scanf("%d", &searche_id);
    for (int s = 0; s < cmp; s++)
    {

        if (searche_id == jeu.id[s])
        {
            printf("Est-ce que tu veux supprime (1/ yes)(2/ no): %s ", jeu.nom[s]);
            scanf("%d", &choix_supprime);
            if (choix_supprime == 1)
            {
                supprime(s);
            }
            else if (choix_supprime == 2)
            {
                goto reaplit4;
            }
        }
        else
        {
            printf("try again !!\n");
        }
    }
}
int supprime(int s)
{
    for (s; s < cmp; s++)
    {
        char swap[6];

        strcpy(jeu.post[s], jeu.post[s + 1]);
        cmp--;
        i--;

        char swap2[6];

        strcpy(jeu.nom[s], jeu.nom[s + 1]);

        char swap3[6];

        strcpy(jeu.prenom[s], jeu.prenom[s + 1]);

        int swap4;

        jeu.statut[s] = jeu.statut[s + 1];

        int swap5;

        jeu.age[s] = jeu.age[s + 1];

        int swap6;

        jeu.buts[s] = jeu.buts[s + 1];

        int swap7;

        jeu.id[s] = jeu.id[s + 1];

        int swap8;

        jeu.numeroMaillot[s] = jeu.numeroMaillot[s + 1];
    }
}
int recherche_joueurs()
{
    int choice5;
    printf("1_Rechercher un joueur par Identifiant\n2_Rechercher un joueur par Nom.\n>>> ");
    scanf("%d", &choice5);
    switch (choice5)
    {
    case 1:
        system("cls");
        recherche_id();
        break;
    case 2:
        recherche_nom();
        break;
    default:
        break;
    }
}
int recherche_id()
{
reaplit5:
    printf("id : ");
    scanf("%d", &searche_id);
    for (int s = 0; s < cmp; s++)
    {

        if (searche_id == jeu.id[s])
        {
            printf("============ les joueurs %d ============\n", jeu.nom[s]);
            printf("//=> nom : %s", jeu.nom[s]);
            printf("//=> prenom :%s", jeu.prenom[s]);
            printf("//=> age : %d \n", jeu.age[s]);
            printf("//=> post (gardien, defenseur, milieu, attaquant) : %s", jeu.post[s]);
            printf("//=> buts : %d \n", jeu.buts[s]);

            if (jeu.statut[s] == 1)
            {
                strcpy(x, "titulare");
            }
            else if (jeu.statut[s] == 2)
            {
                strcpy(x, "remplacant");
            }
            printf("//=> status : %s\n", x);
            printf("//=> numeroMaillot : %d \n", jeu.numeroMaillot[s]);
            printf("//=> ID : %d \n", jeu.id[s]);
            break;
        }
        else
        {
            printf("try again !!\n");
            goto reaplit5;
        }
    }
}
int recherche_nom()
{
    getchar();
reaplit6:
    printf("nom : ");
    fgets(x, 15, stdin);
    for (int s = 0; s < cmp; s++)
    {

        if (strcmp(x, jeu.nom[s]) == 0)
        {
            printf("============ les joueurs %d ============\n", jeu.nom[s]);
            printf("//=> nom : %s", jeu.nom[s]);
            printf("//=> prenom :%s", jeu.prenom[s]);
            printf("//=> age : %d \n", jeu.age[s]);
            printf("//=> post (gardien, defenseur, milieu, attaquant) : %s", jeu.post[s]);
            printf("//=> buts : %d \n", jeu.buts[s]);

            if (jeu.statut[s] == 1)
            {
                strcpy(x, "titulare");
            }
            else if (jeu.statut[s] == 2)
            {
                strcpy(x, "remplacant");
            }
            printf("//=> status : %s\n", x);
            printf("//=> numeroMaillot : %d \n", jeu.numeroMaillot[s]);
            printf("//=> ID : %d \n", jeu.id[s]);
            break;
        }
        else
        {
            printf("try again !!\n");
            goto reaplit6;
        }
    }
}
int statistique()
{
    int choice7;
    printf("1_Afficher le nombre total de joueurs dans l’équipe.\n2_Afficher l’âge moyen des joueurs.\n3_Afficher les joueurs ayant marqué plus de X but\n4_Afficher le meilleur buteur\n5_Afficher le joueur le plus jeune et le plus âgé.\n>>> ");
    scanf("%d", &choice7);
    switch (choice7)
    {
    case 1:
        nomber_total();
        break;
    case 2:
        moyen_age();
        break;
    case 3:
        plus_marque();
        break;
    case 4:
        milleur_joueurs();
        break;
    case 5:
        plus_jeune_age();
        break;

    default:
        printf("le choix invalide !!");
        break;
    }
}
int nomber_total()
{
    printf("le nomber total de joueurs est %d \n", cmp);
}
int moyen_age()
{
    int k = 0;
    for (int p = 0; p < cmp; p++)
    {
        k += jeu.age[p];
    }
    k = k / cmp;
    printf("moyen de l'age de joueurs est %d \n", k);
}
int plus_marque()
{
    int marque;
    printf("number de goal : ");
    scanf("%d", &marque);
    for (int m = 0; m < cmp; m++)
    {
        if (jeu.buts[m] > marque)
        {
            printf("=============================\n");
            printf("nom : %s \n", jeu.nom[m]);
            printf("buts : %d \n", jeu.buts[m]);
            printf("=============================\n");
        }
    }
}
int milleur_joueurs()
{
    for (int m = 0; m < cmp; m++)
    {
        int s = m;
        for (int l = m + 1; l < cmp; l++)
        {
            if (jeu.buts[s] < jeu.buts[l])
            {
                s = l;
            }
        }
        printf("=============================\n");
        printf("nom : %s \n", jeu.nom[s]);
        printf("buts : %d \n", jeu.buts[s]);
        printf("=============================\n");
    }
}
int plus_jeune_age()
{
    for (int m = 0; m < cmp; m++)
    {
        int s = m;
        for (int l = m + 1; l < cmp; l++)
        {
            if (jeu.age[s] < jeu.age[l])
            {
                s = l;
            }
        }
        printf("============================= \n");
        printf("nom de joueur plus age : %s \n", jeu.nom[s]);
        printf("============================= \n");
    }
    for (int m = 0; m < cmp; m++)
    {
        int s = m;
        for (int l = m + 1; l < cmp; l++)
        {
            if (jeu.age[s] > jeu.age[l])
            {
                s = l;
            }
        }
        printf("============================= \n");
        printf("nom de joueur plus jeune : %s \n", jeu.nom[s]);
        printf("============================= \n");
    }
}