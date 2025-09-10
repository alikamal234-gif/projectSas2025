#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int cmp = 0;
int i = 0;
int ran;
char x[15]="x";
int ajoute_joueurs();
int ajoute_one();
int ajoute_plusieurs();
int affiche_contact();
int tri_alphabe();
int tri_age();
typedef struct{
    char nom[100][100];
    char prenom[100][100];
    int age[100];
    char post[100][100];
    int buts[100];
    int statut[100];
    int id[100];
    int numeroMaillot[100];
}joueurs;
joueurs jeu;
int main(){
    int choice;
    do{
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
    case 2:
        system("cls");
        affiche_contact();
        break;
    default:
        printf("choice invalid !!");
        break;
    }
    }while(choice != 0);
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
        
        break;
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
    printf("numeroMaillot : ");
    scanf("%d",&jeu.numeroMaillot[i]);
    printf("statut (1/ titulaire)(2/ remplacant) : ");
    scanf("%d",&jeu.statut[i]);
    srand(time(NULL));
    ran = rand()%9999 + 10000;
    
    
        jeu.id[i]=ran;
    

    i++;
    cmp++;
}
int ajoute_plusieurs(){
    int houmuch;
    printf("nomber de joueurs : \n");
    scanf("%d",&houmuch);
    for(int u =i;u<houmuch;u++){
    printf("joueurs %d : \n",u+1);
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
    printf("numeroMaillot : ");
    scanf("%d",&jeu.numeroMaillot[u]);
    printf("statut (1/ titulaire)(2/ remplacant) : ");
    scanf("%d",&jeu.statut[u]);

    srand(time(NULL));
    ran = rand()%9999 + 10000;
    
        jeu.id[u]=ran;
    
    cmp++;
    }
}
int affiche_contact(){
    int choice3;
    printf("1_affiche tri par alphabe\n2_affiche tri pare age\n>>> ");
    scanf("%d",&choice3);
    switch(choice3){
        case 1:
        system("cls");
            tri_alphabe();
            break;
        case 2:
        system("cls");
             tri_age();
            break; 
        default:
            printf("choice invalid !!");  
            break;
    }
}
int tri_alphabe(){
    
    for(int c = 0;c<cmp;c++){
        char x = c;
        for(int g =c;g<cmp;g++){
            if(jeu.nom[g][0] < jeu.nom[x][0]){
                x = g;
            }
        }
        char swap[6];
        strcpy(swap,jeu.nom[c]);
        strcpy(jeu.nom[c],jeu.nom[x]);
        strcpy(jeu.nom[x],swap);
        
        char swap2[6];
        strcpy(swap2,jeu.prenom[c]);
        strcpy(jeu.prenom[c],jeu.prenom[x]);
        strcpy(jeu.prenom[x],swap2);
        
        char swap3[6];
        strcpy(swap3,jeu.post[c]);
        strcpy(jeu.post[c],jeu.post[x]);
        strcpy(jeu.post[x],swap3);
        
        int swap4;
        swap4=jeu.statut[c];
        jeu.statut[c]=jeu.statut[x];
        jeu.statut[x]=swap4;
        
        int swap5;
        swap5=jeu.age[c];
        jeu.age[c]=jeu.age[x];
        jeu.age[x]=swap5;
        
        int swap6;
        swap6=jeu.buts[c];
        jeu.buts[c]=jeu.buts[x];
        jeu.buts[x]=swap6;

        int swap7;
        swap7=jeu.id[c];
        jeu.id[c]=jeu.id[x];
        jeu.id[x]=swap7;
        
        int swap8;
        swap8=jeu.numeroMaillot[c];
        jeu.numeroMaillot[c]=jeu.numeroMaillot[x];
        jeu.numeroMaillot[x]=swap8;
        
    }
    for(int f =0;f<cmp;f++){
        printf("============ les joueurs %d ============\n",f+1);
        printf("//=> nom : %s",jeu.nom[f]);
        printf("//=> prenom :%s",jeu.prenom[f]);
        printf("//=> age : %d \n",jeu.age[f]);
        printf("//=> post : %s",jeu.post[f]);
        printf("//=> buts : %d \n",jeu.buts[f]);
        
        if(jeu.statut[f] == 1){
            strcpy(x,"titulare");
        }else if(jeu.statut[f] == 2){
            strcpy(x,"remplacant");
        }
        printf("//=> status : %s\n",x);
        printf("//=> numeroMaillot : %d \n",jeu.numeroMaillot[f]);
        printf("//=> ID : %d \n",jeu.id[f]);
        
        }
}
int tri_age(){
    for(int e = 0;e<cmp;e++){
        char x = e;
        for(int g =e;g<cmp;g++){
            if(jeu.age[g] < jeu.age[x]){
                x = g;
            }
        }
        char swap[6];
        strcpy(swap,jeu.nom[e]);
        strcpy(jeu.nom[e],jeu.nom[x]);
        strcpy(jeu.nom[x],swap);
        
        char swap2[6];
        strcpy(swap2,jeu.prenom[e]);
        strcpy(jeu.prenom[e],jeu.prenom[x]);
        strcpy(jeu.prenom[x],swap2);
        
        char swap3[6];
        strcpy(swap3,jeu.post[e]);
        strcpy(jeu.post[e],jeu.post[x]);
        strcpy(jeu.post[x],swap3);
        
        int swap4;
        swap4=jeu.statut[e];
        jeu.statut[e]=jeu.statut[x];
        jeu.statut[x]=swap4;
        
        int swap5;
        swap5=jeu.age[e];
        jeu.age[e]=jeu.age[x];
        jeu.age[x]=swap5;
        
        int swap6;
        swap6=jeu.buts[e];
        jeu.buts[e]=jeu.buts[x];
        jeu.buts[x]=swap6;

        int swap7;
        swap7=jeu.id[e];
        jeu.id[e]=jeu.id[x];
        jeu.id[x]=swap7;
        
        int swap8;
        swap8=jeu.numeroMaillot[e];
        jeu.numeroMaillot[e]=jeu.numeroMaillot[x];
        jeu.numeroMaillot[x]=swap8;
    }
    for(int f =0;f<cmp;f++){
        printf("============ les joueurs %d ============\n",f+1);
        printf("//=> nom : %s \n",jeu.nom[f]);
        printf("//=> prenom :%s \n",jeu.prenom[f]);
        printf("//=> age : %d \n",jeu.age[f]);
        printf("//=> post : %s \n",jeu.post[f]);
        printf("//=> buts : %d \n",jeu.buts[f]);
        
        if(jeu.statut[f] == 1){
            strcpy(x,"titulare");
        }else if(jeu.statut[f] == 2){
            strcpy(x,"remplacant");
        }
        printf("//=> status : %s \n",x);
        printf("//=> numeroMaillot : %d \n",jeu.numeroMaillot[f]);
        printf("//=> ID : %d \n",jeu.id[f]);
        
        }
}


    