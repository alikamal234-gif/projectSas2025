#include <stdio.h>
#include <stdlib.h>
int i = 0;
int ajoute_joueurs();
int ajoute_one();
int ajoute_plusieurs();
typedef struct{
    char nom[100][100];
    char prenom[100][100];
    int age[100];
    char post[100][100];
    int buts[100];
    int statut[100];
}joueurs;
joueurs jeu;
int main(){
    int choice;
    printf("====================== Gestion d’une Équipe de Football===========================\n");
    printf("1_AJOUT UN JOUEURS\n2_AFFICHEER LES JOUEURS\n3_MODIFIER UN JOUEUR\n4_SUPPRIMER UN JOUEUR\n5_RECHERCHER UN JOUEUR\n6_STATISTIQUE\n");
    printf(">>> ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        system("cls");
        ajoute_joueurs();
        break;
    
    default:
        printf("choice invalid !!");
        break;
    }
}
int ajoute_joueurs(){
    int choice2;
    printf("================= ajoute =================\n");
    printf("1_AJOUTE UN JOUEUR\n2_AJOUTE PLUSIEURS JOUEURS\n>>> ");
    scanf("%d",&choice2);
    switch (choice2)
    {
    case 1:
        system("cls");
        ajoute_one();
        break;
    case 2:
        system("cls");
        ajoute_plusieurs();
    default:
        printf("choice invalid !!");
        break;
    }
}
int ajoute_one(){
    getchar();
    printf("nom : ");
    fgets(jeu.nom[i],sizeof(jeu.nom),stdin);
    printf("prenom : ");
    fgets(jeu.prenom[i],sizeof(jeu.prenom),stdin);
    printf("age : ");
    scanf("%d",&jeu.age[i]);
    getchar();
    printf("post : ");
    fgets(jeu.post[i],sizeof(jeu.post),stdin);
    printf("buts : ");
    scanf("%d",&jeu.buts[i]);
    printf("statut (1/ titulaire)(2/ remplacant) : ");
    scanf("%d",&jeu.statut[i]);
    i++;
}
int ajoute_plusieurs(){
    int houmuch;
    printf("nomber de joueurs : \n");
    scanf("%d",&houmuch);
    for(int u =i;u<houmuch+1;u++){
    printf("joueurs %d : ",u+1);
    getchar();
    printf("nom : ");
    fgets(jeu.nom[u],sizeof(jeu.nom),stdin);
    printf("prenom : ");
    fgets(jeu.prenom[u],sizeof(jeu.prenom),stdin);
    printf("age : ");
    scanf("%d",&jeu.age[u]);
    getchar();
    printf("post : ");
    fgets(jeu.post[u],sizeof(jeu.post),stdin);
    printf("buts : ");
    scanf("%d",&jeu.buts[u]);
    printf("statut (1/ titulaire)(2/ remplacant) : ");
    scanf("%d",&jeu.statut[u]);
    system("cls");
    }
}