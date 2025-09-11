#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int cmp = 5;
int i = 5;
int ran;
int ajoute_joueurs();
int ajoute_one();
int ajoute_plusieurs();
int affiche_joueurs();
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
int data_jeu();
typedef struct
{
    char nom[100];
    char prenom[100];
    int age;
    char post[100];
    int buts;
    int statut;
    int id;
    int numeroMaillot;
} joueurs;
joueurs jeu[100];

int main()
{
    int choice;

    data_jeu();
    do
    {
        printf("====================== Gestion d’une Équipe de Football===========================\n\n");
        printf("1_AJOUT UN JOUEURS\n2_AFFICHEER LES JOUEURS\n3_MODIFIER UN JOUEUR\n4_SUPPRIMER UN JOUEUR\n5_RECHERCHER UN JOUEUR\n6_STATISTIQUE\n0_QUIT\n");
         printf("\n====================== Gestion d’une Équipe de Football===========================\n");
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
            affiche_joueurs();
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
        case 0:
            system("cls");
            return 0;
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
    printf("1_AJOUTE UN JOUEUR\n2_AJOUTE PLUSIEURS JOUEURS\n0_menu\n\n");
    printf("================= ajoute =================\n\n");
    printf(">>> ");
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
    case 0:
        system("cls");
        main();
    default:
        printf("choice invalid !!\n");
        break;
    }
}
int ajoute_one()
{
    int chose_post;
    getchar();
    printf("nom : ");
    fgets(jeu[i].nom, 100, stdin);
    printf("prenom : ");
    fgets(jeu[i].prenom, 100, stdin);
    printf("age : ");
    scanf("%d", &jeu[i].age);
reaplit_post:
    printf("post :\n1_gardien\n2_defenseur\n3_milieu\n4_attaquant\n >>> ");
    scanf("%d", &chose_post);
    if (chose_post == 1)
    {
        strcpy(jeu[i].post, "gardien");
    }
    else if (chose_post == 2)
    {
        strcpy(jeu[i].post, "defenseur");
    }
    else if (chose_post == 3)
    {
        strcpy(jeu[i].post, "milieu");
    }
    else if (chose_post == 4)
    {
        strcpy(jeu[i].post, "attaquant");
    }
    else
    {
        printf("chose invalid !! \n");
        goto reaplit_post;
    }
    printf("buts : ");
    scanf("%d", &jeu[i].buts);
    printf("numeroMaillot : ");
    scanf("%d", &jeu[i].numeroMaillot);
    printf("statut (1/ titulaire)(2/ remplacant) : ");
    scanf("%d", &jeu[i].statut);
    system("pause");
    srand(time(NULL));
    ran = rand() % 9999 + 10000;
    jeu[i].id = ran;

    i++;
    cmp++;
}
int ajoute_plusieurs()
{
    int houmuch;
    int chose_post;
    printf("nomber de joueurs : \n");
    scanf("%d", &houmuch);
    for (int u = 0; u < houmuch; u++)
    {
        printf("joueurs %d : \n", u + 1);
        getchar();
        printf("nom : ");
        fgets(jeu[i].nom, 100, stdin);
        printf("prenom : ");
        fgets(jeu[i].prenom, 100, stdin);
        printf("age : ");
        scanf("%d", &jeu[i].age);
    reaplit_post:
        printf("post :\n1_gardien\n2_defenseur\n3_milieu\n4_attaquant\n >>> ");
        scanf("%d", &chose_post);
        if (chose_post == 1)
        {
            strcpy(jeu[i].post, "gardien");
        }
        else if (chose_post == 2)
        {
            strcpy(jeu[i].post, "defenseur");
        }
        else if (chose_post == 3)
        {
            strcpy(jeu[i].post, "milieu");
        }
        else if (chose_post == 4)
        {
            strcpy(jeu[i].post, "attaquant");
        }
        else
        {
            printf("chose invalid !! ");
            goto reaplit_post;
        }
        printf("buts : ");
        scanf("%d", &jeu[i].buts);
        printf("numeroMaillot : ");
        scanf("%d", &jeu[i].numeroMaillot);
        printf("statut (1/ titulaire)(2/ remplacant) : ");
        scanf("%d", &jeu[i].statut);
        system("pause");
        system("cls");
        srand(time(NULL));
        ran = rand() % 9999 + 10000;

        jeu[i].id = ran;
        i++;
        cmp++;
    }
}
int affiche_joueurs()
{
    int choice3;
    printf("1_affiche tri par alphabe\n2_affiche tri pare age\n3_affiche tri par poste\n0_menu\n>>> ");
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
    case 0:
        main();
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
            if (jeu[g].nom[0] < jeu[x].nom[0])
            {
                x = g;
            }
        }
        char swap[6];
        strcpy(swap, jeu[c].nom);
        strcpy(jeu[c].nom, jeu[x].nom);
        strcpy(jeu[x].nom, swap);

        char swap2[6];
        strcpy(swap2, jeu[c].prenom);
        strcpy(jeu[c].prenom, jeu[x].prenom);
        strcpy(jeu[x].prenom, swap2);

        char swap3[6];
        strcpy(swap3, jeu[c].post);
        strcpy(jeu[c].post, jeu[x].post);
        strcpy(jeu[x].post, swap3);

        int swap4;
        swap4 = jeu[c].statut;
        jeu[c].statut = jeu[x].statut;
        jeu[x].statut = swap4;

        int swap5;
        swap5 = jeu[c].age;
        jeu[c].age = jeu[x].age;
        jeu[x].age = swap5;

        int swap6;
        swap6 = jeu[c].buts;
        jeu[c].buts = jeu[x].buts;
        jeu[x].buts = swap6;

        int swap7;
        swap7 = jeu[c].id;
        jeu[c].id = jeu[x].id;
        jeu[x].id = swap7;

        int swap8;
        swap8 = jeu[c].numeroMaillot;
        jeu[c].numeroMaillot = jeu[x].numeroMaillot;
        jeu[x].numeroMaillot = swap8;
    }
    for (int f = 0; f < cmp; f++)
    {
        char change[15] = "change";
        printf("============ les joueurs %d ============\n", f + 1);
        printf("//=> nom : %s", jeu[f].nom);
        printf("//=> prenom :%s", jeu[f].prenom);
        printf("//=> age : %d \n", jeu[f].age);
        printf("//=> post (gardien, defenseur, milieu, attaquant) : %s", jeu[f].post);
        printf("//=> buts : %d \n", jeu[f].buts);

        if (jeu[f].statut == 1)
        {
            strcpy(change, "titulare");
        }
        else if (jeu[f].statut == 2)
        {
            strcpy(change, "remplacant");
        }
        printf("//=> status : %s\n", change);
        printf("//=> numeroMaillot : %d \n", jeu[f].numeroMaillot);
        printf("//=> ID : %d \n", jeu[f].id);
    }
}
int tri_age()
{
    for (int e = 0; e < cmp; e++)
    {
        char x = e;
        for (int g = e; g < cmp; g++)
        {
            if (jeu[g].age < jeu[x].age)
            {
                x = g;
            }
        }
        char swap[6];
        strcpy(swap, jeu[e].nom);
        strcpy(jeu[e].nom, jeu[x].nom);
        strcpy(jeu[x].nom, swap);

        char swap2[6];
        strcpy(swap2, jeu[e].prenom);
        strcpy(jeu[e].prenom, jeu[x].prenom);
        strcpy(jeu[x].prenom, swap2);

        char swap3[6];
        strcpy(swap3, jeu[e].post);
        strcpy(jeu[e].post, jeu[x].post);
        strcpy(jeu[x].post, swap3);

        int swap4;
        swap4 = jeu[e].statut;
        jeu[e].statut = jeu[x].statut;
        jeu[x].statut = swap4;

        int swap5;
        swap5 = jeu[e].age;
        jeu[e].age = jeu[x].age;
        jeu[x].age = swap5;

        int swap6;
        swap6 = jeu[e].buts;
        jeu[e].buts = jeu[x].buts;
        jeu[x].buts = swap6;

        int swap7;
        swap7 = jeu[e].id;
        jeu[e].id = jeu[x].id;
        jeu[x].id = swap7;

        int swap8;
        swap8 = jeu[e].numeroMaillot;
        jeu[e].numeroMaillot = jeu[x].numeroMaillot;
        jeu[x].numeroMaillot = swap8;
    }
    for (int f = 0; f < cmp; f++)
    {
        char change[20] = "change";
        printf("============ les joueurs %d ============\n", f + 1);
        printf("//=> nom : %s", jeu[f].nom);
        printf("//=> prenom :%s ", jeu[f].prenom);
        printf("//=> age : %d \n", jeu[f].age);
        printf("//=> post : %s", jeu[f].post);
        printf("//=> buts : %d \n", jeu[f].buts);

        if (jeu[f].statut == 1)
        {
            strcpy(change, "titulare");
        }
        else if (jeu[f].statut == 2)
        {
            strcpy(change, "remplacant");
        }
        printf("//=> status : %s \n", change);
        printf("//=> numeroMaillot : %d \n", jeu[f].numeroMaillot);
        printf("//=> ID : %d \n", jeu[f].id);
    }
}
int tri_poste()
{
    for (int d = 0; d < cmp; d++)
    {
        for (int j = d + 1; j < cmp; j++)
        {
            if (strcmp(jeu[d].post, jeu[j].post) == 0)
            {
                char swap[15];
                strcpy(swap, jeu[d + 1].post);
                strcpy(jeu[d + 1].post, jeu[j].post);
                strcpy(jeu[j].post, swap);

                char swap2[15];
                strcpy(swap2, jeu[d + 1].nom);
                strcpy(jeu[d + 1].nom, jeu[j].nom);
                strcpy(jeu[j].nom, swap2);

                char swap3[15];
                strcpy(swap3, jeu[d + 1].prenom);
                strcpy(jeu[d + 1].prenom, jeu[j].prenom);
                strcpy(jeu[j].prenom, swap3);

                int swap4;
                swap4 = jeu[d + 1].statut;
                jeu[d + 1].statut = jeu[j].statut;
                jeu[j].statut = swap4;

                int swap5;
                swap5 = jeu[d + 1].age;
                jeu[d + 1].age = jeu[j].age;
                jeu[j].age = swap5;

                int swap6;
                swap6 = jeu[d + 1].buts;
                jeu[d + 1].buts = jeu[j].buts;
                jeu[j].buts = swap6;

                int swap7;
                swap7 = jeu[d + 1].id;
                jeu[d + 1].id = jeu[j].id;
                jeu[j].id = swap7;

                int swap8;
                swap8 = jeu[d + 1].numeroMaillot;
                jeu[d + 1].numeroMaillot = jeu[j].numeroMaillot;
                jeu[j].numeroMaillot = swap8;
            }
        }
    }
    for (int f = 0; f < cmp; f++)
    {
        char change[20] = "change";
        printf("============ post %s ============\n", jeu[f].post);
        printf("//=> nom : %s", jeu[f].nom);
        printf("//=> prenom :%s", jeu[f].prenom);
        printf("//=> age : %d \n", jeu[f].age);
        printf("//=> post : %s", jeu[f].post);
        printf("//=> buts : %d \n", jeu[f].buts);
        if (jeu[f].statut == 1)
        {
            strcpy(change, "titulare");
        }
        else if (jeu[f].statut == 2)
        {
            strcpy(change, "remplacant");
        }
        printf("//=> status : %s \n", change);
        printf("//=> numeroMaillot : %d \n", jeu[f].numeroMaillot);
        printf("//=> ID : %d \n", jeu[f].id);
        printf("============ post ============\n", jeu[f].post);
    }
}
int modifie_joueurs()
{
    int choice4;
    printf("\n============================================\n");
    printf("    1_Modifier le poste d’un joueur\n   2_Modifier l’âge d’un joueur\n  3_Modifier le nombre de buts marqués par un joueur\n");
    printf("\n============================================\n");
    printf(">>> ");
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
        break;

    default:
        break;
    }
}
int modifie_poste()
{
    int chose_post;
    int searche_id;
reapit:
    printf("ID : ");
    scanf("%d", &searche_id);

    for (int s = 0; s < cmp; s++)
    {

        if (searche_id == jeu[s].id)
        {
            printf("modifie le post de %s \n", jeu[s].nom);
            getchar();
            printf("nouvelle poste  : \n1_gardien\n2_defenseur\n3_milieu\n4_attaquant\n >>> ");
            scanf("%d", &chose_post);
            if (chose_post == 1)
            {
                strcpy(jeu[s].post, "gardien");
            }
            else if (chose_post == 2)
            {
                strcpy(jeu[s].post, "defenseur");
            }
            else if (chose_post == 3)
            {
                strcpy(jeu[s].post, "milieu");
            }
            else if (chose_post == 4)
            {
                strcpy(jeu[s].post, "attaquant");
            }
            else
            {
                printf("chose invalid !! \n");
                goto reapit;
            }
            break;
        }
    }
    system("pause");
}
int modifie_age()
{
    int searche_id;
reapit_age:
    printf("nom de ID : ");
    scanf("%d", &searche_id);
    for (int s = 0; s < cmp; s++)
    {

        if (searche_id == jeu[s].id)
        {
            printf("modifie le post de %s \n", jeu[s].nom);
            printf("nouvelle age : ");
            scanf("%d", &jeu[s].age);
            break;
        }
    }
    system("pause");
}
int modofie_buts()
{
    int searche_id;

    printf("ID : ");
    scanf("%d", &searche_id);
    for (int k = 0; k < cmp; k++)
    {

        if (searche_id == jeu[k].id)
        {
            printf("modifie le BUTS de %s \n", jeu[k].nom);
            printf("nouvelle buts : ");
            scanf("%d", &jeu[k].buts);
        }
    }
    system("pause");
}
int supprime_joueurs()
{
    int searche_id;
    int choix_supprime;
    printf("id : ");
    scanf("%d", &searche_id);
    for (int s = 0; s < cmp; s++)
    {

        if (searche_id == jeu[s].id)
        {
            printf("Est-ce que tu veux supprime %s (1/ yes)(2/ no):  ", jeu[s].nom);
            scanf("%d", &choix_supprime);
            if (choix_supprime == 1)
            {
                supprime(s);
                cmp--;
                i--;
                break;
            }
            else if (choix_supprime == 2)
            {
                main();
            }
            break;
        }
    }
    system("pause");
}
int supprime(int s)
{
    for (s; s < cmp; s++)
    {
        char swap[6];

        strcpy(jeu[s].post, jeu[s + 1].post);

        char swap2[6];

        strcpy(jeu[s].nom, jeu[s + 1].nom);

        char swap3[6];

        strcpy(jeu[s].prenom, jeu[s + 1].prenom);

        int swap4;

        jeu[s].statut = jeu[s + 1].statut;

        int swap5;

        jeu[s].age = jeu[s + 1].age;

        int swap6;

        jeu[s].buts = jeu[s + 1].buts;

        int swap7;

        jeu[s].id = jeu[s + 1].id;

        int swap8;

        jeu[s].numeroMaillot = jeu[s + 1].numeroMaillot;
    }
}
int recherche_joueurs()
{
    int choice5;
    printf("1_Rechercher un joueur par Identifiant\n2_Rechercher un joueur par Nom.\n0_menu\n>>> ");
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
    case 0:
        system("cls");
        main();
    default:
        break;
    }
}
int recherche_id()
{
    int searche_id;
    printf("id : ");
    scanf("%d", &searche_id);
    for (int s = 0; s < cmp; s++)
    {
        char change[15] = "change";
        if (searche_id == jeu[s].id)
        {
            printf("============ les joueurs %d ============\n", jeu[s].nom);
            printf("//=> nom : %s", jeu[s].nom);
            printf("//=> prenom :%s", jeu[s].prenom);
            printf("//=> age : %d \n", jeu[s].age);
            printf("//=> post  : %s", jeu[s].post);
            printf("//=> buts : %d \n", jeu[s].buts);

            if (jeu[s].statut == 1)
            {
                strcpy(change, "titulare");
            }
            else if (jeu[s].statut == 2)
            {
                strcpy(change, "remplacant");
            }
            printf("//=> status : %s\n", change);
            printf("//=> numeroMaillot : %d \n", jeu[s].numeroMaillot);
            printf("//=> ID : %d \n", jeu[s].id);
            break;
        }
    }
}
int recherche_nom()
{
    getchar();
    char recherche_nom[15];
    printf("nom : ");
    scanf("%s", &recherche_nom);
    for (int s = 0; s < cmp; s++)
    {

        if (strcmp(recherche_nom, jeu[s].nom) == 0)
        {
            printf("============ les joueurs %d ============\n", jeu[s].nom);
            printf("//=> nom : %s", jeu[s].nom);
            printf("//=> prenom :%s", jeu[s].prenom);
            printf("//=> age : %d \n", jeu[s].age);
            printf("//=> post (gardien, defenseur, milieu, attaquant) : %s", jeu[s].post);
            printf("//=> buts : %d \n", jeu[s].buts);

            if (jeu[s].statut == 1)
            {
                strcpy(recherche_nom, "titulare");
            }
            else if (jeu[s].statut == 2)
            {
                strcpy(recherche_nom, "remplacant");
            }
            printf("//=> status : %s\n", recherche_nom);
            printf("//=> numeroMaillot : %d \n", jeu[s].numeroMaillot);
            printf("//=> ID : %d \n", jeu[s].id);
            break;
        }
    }
}
int statistique()
{
    int choice7;
    printf("1_Afficher le nombre total de joueurs dans l’équipe.\n2_Afficher l’âge moyen des joueurs.\n3_Afficher les joueurs ayant marqué plus de X but\n4_Afficher le meilleur buteur\n5_Afficher le joueur le plus jeune et le plus âgé.\n0_menu\n>>> ");
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
    case 0:
        system("cls");
        main();
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
        k += jeu[p].age;
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
        if (jeu[m].buts > marque)
        {
            printf("=============================\n");
            printf("nom : %s \n", jeu[m].nom);
            printf("buts : %d \n", jeu[m].buts);
            printf("=============================\n");
        }
    }
}
int milleur_joueurs()
{
    int m = 0;
    int s = m;

    for (int l = m + 1; l < cmp; l++)
    {
        if (jeu[s].buts < jeu[l].buts)
        {
            s = l;
        }
    }

    printf("=============================\n");
    printf("nom : %s \n", jeu[s].nom);
    printf("buts : %d \n", jeu[s].buts);
    printf("=============================\n");
}
int plus_jeune_age()
{
    int m = 0;
    int s = m;

    for (int l = m + 1; l < cmp; l++)
    {
        if (jeu[s].age < jeu[l].age)
        {
            s = l;
        }
    }
    printf("=============================\n");
    printf("nom : %s \n", jeu[s].nom);
    printf("age : %d \n", jeu[s].age);
    printf("=============================\n");
    int k = 0;
    int z = k;

    for (int l = k + 1; l < cmp; l++)
    {
        if (jeu[z].age > jeu[l].age)
        {
            z = l;
        }
    }

    printf("=============================\n");
    printf("nom : %s \n", jeu[z].nom);
    printf("buts : %d \n", jeu[z].age);
    printf("=============================\n");
}
int data_jeu()
{
    char nom[100][100] = {"messi", "ronaldo", "mbappe", "modric", "hakimi"};
    char prenom[100][100] = {"lionel", "cristiano", "kylian", "luka", "achraf"};
    int age[100] = {37, 39, 26, 39, 27};
    char post[100][100] = {"attaquant", "attaquant", "attaquant", "milieu", "defenseur"};
    int buts[100] = {800, 850, 250, 150, 50};
    int statut[100] = {1, 1, 1, 1, 1};
    int id[100] = {33333, 11111, 22222, 55555, 44444};
    int numeroMaillot[100] = {10, 7, 7, 10, 2};
    for (int c = 0; c < 5; c++)
    {
        strcpy(jeu[c].nom, nom[c]);
        strcpy(jeu[c].prenom, prenom[c]);
        strcpy(jeu[c].post, post[c]);
        jeu[c].age = age[c];
        jeu[c].buts = buts[c];
        jeu[c].statut = statut[c];
        jeu[c].id = id[c];
        jeu[c].numeroMaillot = numeroMaillot[c];
    }
}