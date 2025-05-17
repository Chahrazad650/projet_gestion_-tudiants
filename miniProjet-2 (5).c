#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
////////////declarations :
char mot;
int nm=0,n=0,choix=0,i,j,x=-1,quiter=-1;
struct Etudiant {
    char matricule[25];
    char nom[50];
    char prenom[50];
    int jj,mm,aa;
    char lieuDeNaissance[50];
    char adresse[50];
}Etudiant;
struct noeudEtudiant {
    struct Etudiant val;
    struct noeudEtudiant* suivant;
} noeudEtudiant;

struct Matiere {
    char designation[50];
    int Coefficient;
    char code[50];
};
struct noeudMatiere {
    struct Matiere val;
    struct noeudMatiere* suivant;
} noeudMatiere;
#define maxEtudiants 10
#define maxMatieres 5
struct Etudiant kaleb;
struct Matiere kaleb2;
FILE* f;
FILE* f2;
///////////les fonctions :

void SaisirUnEtudaint(){
if(n==maxEtudiants){
printf("\n\nmemoire saturee !\n");
return;
}
if (access("etudiants.dat", F_OK) != -1) {
        f=fopen("etudiants.dat","ab");
    } else {
        f=fopen("etudiants.dat","wb");
    }
printf("\n\nEntrez les informations de l'étudiant N°%d:\n",n+1);
    printf("Entrez la matricule de l'etudiant : ");
    scanf("%c", &mot);
    scanf("%[^\n]", kaleb.matricule);
    printf("Entrez le nom de l'etudiant : ");
    scanf("%c", &mot);
    scanf("%[^\n]", kaleb.nom);
    printf("Entrez le Prénom de l'etudiant : ");
    scanf("%c", &mot);
    scanf("%[^\n]",  kaleb.prenom);
    printf("Entrez la date de naissance de l'etudiant (jj/mm/aaaa) : ");
    do{
    printf("\n*jour:");
    scanf("%d",  &kaleb.jj);
    printf("*mois :");
    scanf("%d",  &kaleb.mm);
    printf("*annee :");
    scanf("%d",  &kaleb.aa);
    if (0>=kaleb.jj || kaleb.jj>31 || 0>=kaleb.mm || kaleb.mm>12 || 1970>kaleb.aa ||  kaleb.aa>2005){printf("\nErreur!!! entrez une date valide :");}
    }while(0>=kaleb.jj || kaleb.jj>31 || 0>=kaleb.mm || kaleb.mm>12 || 1970>kaleb.aa ||  kaleb.aa>2005);
    printf("Lieu de naissance : ");
    scanf("%c", &mot);
    scanf("%[^\n]",  kaleb.lieuDeNaissance);
    printf("Adresse : ");
    scanf("%c", &mot);
    scanf("%[^\n]",  kaleb.adresse);
    fwrite(&kaleb,sizeof(kaleb),1,f);
    fclose(f);
    n++;
    printf("\n--------------------------L'etudiant a ete ajoute avec succes---------------------------\n");
    system("PAUSE>null");
    system("cls");
}

void SaisirPlusieursEtudiants(){
int nombreDesEtudiantsaAjouter;
do {
printf("Entrez le nombre des etudiants que vous voulez ajouter  :");
scanf("%d",& nombreDesEtudiantsaAjouter);
if(n+nombreDesEtudiantsaAjouter>maxEtudiants){
printf ("la liste des etudiant est pleine,veilliez entrez un nombre plus petit.\n\n");}
}while(n+nombreDesEtudiantsaAjouter>maxEtudiants);
for (i=1;i<=nombreDesEtudiantsaAjouter;i++){
system("cls");
SaisirUnEtudaint();
}
}

void ModifierUnEtudiant() {
    int y = -1;
    char matricule[25];
    char mot;

    printf("Entrez le matricule de l'etudiant qui vous souhaitez modifier : ");
    scanf("%s", matricule);

    FILE* f = fopen("etudiants.dat", "rb+");
    if (f == NULL) {
        printf("!!!!!!!!!!!! ERREUR!!!!!!!!!! \nImpossible d'ouvrir le fichier.\n");
        return;
    }

    while (fread(&kaleb, sizeof(kaleb), 1, f) == 1) {
        if (strcmp(kaleb.matricule, matricule) == 0) {
            y = 1;
            printf("Entrez le nouveau nom de l'etudiant: ");
            scanf("%c", &mot);
            scanf("%[^\n]", kaleb.nom);
            printf("Entrez le nouveau prenom de l'etudiant  : ");
            scanf("%c", &mot);
            scanf("%[^\n]", kaleb.prenom);
            printf("Entrez la nouvelle date de naissance (jj/mm/aaaa) : ");
            do {
                printf("\nJour : ");
                scanf("%d", &kaleb.jj);
                printf("Mois : ");
                scanf("%d", &kaleb.mm);
                printf("Annee : ");
                scanf("%d", &kaleb.aa);
                if (0 >= kaleb.jj || kaleb.jj > 31 || 0 >= kaleb.mm || kaleb.mm > 12 || 1970 > kaleb.aa || kaleb.aa > 2005) {
                    printf("\nERREUR !Entrez une date valide : ");
                }
            } while (0 >= kaleb.jj || kaleb.jj > 31 || 0 >= kaleb.mm || kaleb.mm > 12 || 1970 > kaleb.aa || kaleb.aa > 2005);
            printf("Entrez le nouveau lieu de naissance de l'etudiant: ");
            scanf("%c", &mot);
            scanf("%[^\n]", kaleb.lieuDeNaissance);
            printf("Entrez la nouvelle adresse de l'etudiant: ");
            scanf("%c", &mot);
            scanf("%[^\n]", kaleb.adresse);
            fseek(f, -sizeof(kaleb), SEEK_CUR);
            fwrite(&kaleb, sizeof(kaleb), 1, f);
            printf("Les informations de l'etudiant ont ete mises a jour avec succes !\n");
            break;
        }
    }

    fclose(f);

    if (y == -1) {
        printf("l'etudiant n'est pas trouve!!! !\n");
    }

    system("PAUSE>null");
    system("cls");
}

void SupprimerUnEtudiant() {
    int index=-1;
    char matricule[25];
    printf("entrez la matricule de l'etudiant que vous souhaitez supprimer :");
    scanf("%c", &mot);
    scanf("%[^\n]",matricule);
    f2=fopen("supEtudiant.dat","wb");
    f=fopen("etudiants.dat","rb");
   while(fread(&kaleb, sizeof(kaleb), 1, f) == 1) {
        if (strcmp(kaleb.matricule,matricule)!=0) {
        fwrite(&kaleb,sizeof(kaleb),1,f2);}
        else{
        printf(" L'etudiant avec matricule %s a �t� supprim� avec succ�s\n", matricule);
        printf("---------------------------------------------------------------------------------------");
        n--;
        }
        }
      if (index==-1){
        printf("\nAucun �tudiant trouv� avec le matricule %s !\n", matricule);
      
    }
    fclose(f);
    fclose(f2);
    remove("etudiants.dat");
    rename("supEtudiant.dat","etudiants.dat");
      system("PAUSE>null");
        system("cls");
}

void SaisirUneMatiere() {
    if(nm==maxMatieres){
    printf("\n\nLa liste des matieres est pleine!\n");
    return;}
    if (access("matieres.dat", F_OK) != -1) {
        f=fopen("matieres.dat","ab");
    } else {
        f=fopen("matieres.dat","wb");
    }
    printf("Saisie des informations de la matiere N°%d :\n",nm+1);
    printf("Entrez le Code de la matiere : ");
    scanf("%c", &mot);scanf("%[^\n]", kaleb2.code);
    printf("Entrez la Designation de la matiere : ");
    scanf("%c", &mot);scanf("%[^\n]", kaleb2.designation);
    do {printf("Coefficient : ");
    scanf("%d", &kaleb2.Coefficient);
    if (kaleb2.Coefficient>7)printf("\nRessayer avec un Coefficient valide !\n");}while(kaleb2.Coefficient>7);
    
    fwrite(&kaleb2,sizeof(kaleb2),1,f);
    fclose(f);
    printf("\n\n La matiere a ete ajoute avec succes !!!!!!!\n");
    printf("--------------------------------------------------------------------");
    system("PAUSE>null");
    system("cls");
    nm++;
}

void SaisirPlusieursMatieres(){
int nombreDesMatieresaAjouter;
do {
printf("Entrez le nombre des matieres que vous souhaitez ajouter :");
scanf("%d",& nombreDesMatieresaAjouter);
if(nm+nombreDesMatieresaAjouter>maxMatieres){
printf ("Total des etdudiants depasse le nombre autorisee,Ressayer avec un nombre plus petit.\n\n");}
}while(nm+nombreDesMatieresaAjouter>maxMatieres);
for (i=1;i<=nombreDesMatieresaAjouter;i++){
system("cls");
SaisirUneMatiere();
}
}

void ModifierUneMatiere() {
    char code[25];
    int y = -1;
    char mot;

    printf("Entrez le code de la matiere que vous souhaitez modifier : ");
    scanf("%s", code);

    FILE* f = fopen("matieres.dat", "rb+");
    if (f == NULL) {
        printf("ERREUR!!!Impossible d'ouvrir le fichier.\n");
        return;
    }

    while (fread(&kaleb2, sizeof(kaleb2), 1, f) == 1) {
        if (strcmp(kaleb2.code, code) == 0) {
            y = 1;
            printf("Entrez la nouvelle designation de la matiere: ");
            scanf("%c", &mot);
            scanf("%[^\n]", kaleb2.designation);
            do {
                printf("Entrez le nouveau Coefficient de la matiere : ");
                scanf("%d", &kaleb2.Coefficient);
                if (kaleb2.Coefficient > 7) {
                    printf("\nEntrez un Coefficient valide !\n");
                }
            } while (kaleb2.Coefficient > 7);

            long position = ftell(f);
            fseek(f, position - sizeof(kaleb2), SEEK_SET);
            fwrite(&kaleb2, sizeof(kaleb2), 1, f);
            
            printf("\nLa matiere a ete modifiee avec succes !\n");
            break;
        }
    }

    fclose(f);

    if (y == -1) {
        printf("\nAucune matiere n'a ete trouvee avec ce code.Ressayer une autre fois.... \n");
    }

    system("PAUSE>null");
    system("cls");
}

void SupprimerUneMatiere() {
    int index = -1;
    char code[25];
    printf("donnez le code de la matiere � supprimer :");
    scanf("%c", &mot);scanf("%[^\n]",code);
    f=fopen("matieres.dat","rb");
    f2=fopen("supMatiere.dat","wb");
    while(fread(&kaleb2,sizeof(kaleb2),1,f)==1) {
        if (strcmp(kaleb2.code,code)!=0) {
        index=1;
        fwrite(&kaleb2,sizeof(kaleb2),1,f2);
        }else{
        printf("\n*---     La matiere avec le code %s a �t� supprim� avec succ�s !     ---*\n", code);
        nm--;
        }
    }
    fclose(f);
    fclose(f2);
    remove("matieres.dat");
    rename("supMatiere.dat","matieres.dat");
      if (index==-1){
        printf("\nAucune matiere trouv� avec le code %s .Ressayer une autre fois!!!!\n", code);
      
    }
      system("PAUSE>null");
      system("cls");
}

void Af2ichageOrdreDeSaisieE() {
    printf("          ***************     Liste des �tudiants       ************\n");
    printf("Matricule      Nom    Pr�nom       Date de naissance           Lieu de naissance          Adresse :\n\n");
    f=fopen("etudiants.dat","rb");
    while(fread(&kaleb, sizeof(kaleb), 1, f) == 1){
        printf("*%s         %s      %s          (%d/%d/%d)                  %s                        %s.\n", kaleb.matricule, kaleb.nom, kaleb.prenom, kaleb.jj,kaleb.mm,kaleb.aa, kaleb.lieuDeNaissance, kaleb.adresse);
    }
    fclose(f);
}

void Af2ichageOrdreAlphabetiqueE(){

   do {
        printf("       ***      Afichage de la liste des etudiants en ordre alphabetique de leur nom   ***\n");
        printf("          ========================================================= \n\n");
        printf("      [1] Ascendant       \n\n");
        printf("      [2]  descendant        \n\n");
        printf("          ========================================================= \n\n");
        scanf("%d", &choix);
        system("cls");
    } while (choix != 1 && choix != 2);

    struct noeudEtudiant* tete = NULL;

    f= fopen("etudiants.dat", "rb");
    if (f == NULL) {
        printf("ERREUR!!!!Impossible d'ouvrir le fichier.\n");
        return;
    }

    struct Etudiant kaleb;

    while (fread(&kaleb, sizeof(kaleb), 1, f) == 1) {
        struct noeudEtudiant* nouvelEtudiant = malloc(sizeof(struct noeudEtudiant));
        nouvelEtudiant->val = kaleb;
        nouvelEtudiant->suivant = NULL;

        switch (choix) {
            case 1:
                if (tete == NULL || strcmp(kaleb.nom, tete->val.nom) < 0) {
                    nouvelEtudiant->suivant = tete;
                    tete = nouvelEtudiant;
                } else {
                    struct noeudEtudiant* courant = tete;
                    while (courant->suivant != NULL && strcmp(kaleb.nom, courant->suivant->val.nom) >= 0) {
                        courant = courant->suivant;
                    }
                    nouvelEtudiant->suivant = courant->suivant;
                    courant->suivant = nouvelEtudiant;
                }
                break;

            case 2:
                if (tete == NULL || strcmp(kaleb.nom, tete->val.nom) > 0) {
                    nouvelEtudiant->suivant = tete;
                    tete = nouvelEtudiant;
                } else {
                    struct noeudEtudiant* courant = tete;
                    while (courant->suivant != NULL && strcmp(kaleb.nom, courant->suivant->val.nom) <= 0) {
                        courant = courant->suivant;
                    }
                    nouvelEtudiant->suivant = courant->suivant;
                    courant->suivant = nouvelEtudiant;
                }
                break;
        }
    }

    fclose(f);

    printf("                      ***      Liste des �tudiants :       ***\n");
    printf("Matricule / Nom / Pr�nom / Date de naissance / Lieu de naissance / Adresse :\n\n");

    struct noeudEtudiant* courant = tete;
    while (courant != NULL) {
        struct Etudiant etudiant = courant->val;
        printf("%s / %s / %s / (%d/%d/%d) / %s / %s\n",
               etudiant.matricule, etudiant.nom, etudiant.prenom, etudiant.jj, etudiant.mm, etudiant.aa, etudiant.lieuDeNaissance, etudiant.adresse);
        courant = courant->suivant;
    }
    
    courant = tete;
    while (courant != NULL) {
        struct noeudEtudiant* suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }
    }

void Af2ichageOrdreDeMoyenneE(){
    

}

void Af2ichageOrdreDeSaisieM(){
    printf("           ***        Liste des mati�res :code  /  designation  /  Coefficient      ***\n\n");
       f=fopen("matieres.dat","rb");
       i=0;
    while(fread(&kaleb2, sizeof(kaleb2), 1, f) == 1){
        i++;
        printf("Matiere N�%d: %s  /  %s  /  %d\n", i,kaleb2.code, kaleb2.designation,kaleb2.Coefficient);
    }
    fclose(f);
}

void Af2ichageOrdreAlphabetiqueM() {
    do {
        printf(" ------------------- Afichage de la liste des matieres en ordre alphabetique de leur designation----------------\n");
        printf("          ========================================================= \n\n");
        printf("    [1]  Ascendant           \n\n");
        printf("    [2]  Descendant \n\n");
        printf("          ========================================================= \n\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        system("cls");
    } while (choix != 1 && choix != 2);

    struct noeudMatiere* tete = NULL;

    f= fopen("matieres.dat", "rb");
    if (f== NULL) {
        printf("ERREUR!!!!Impossible d'ouvrir le fichier.\n");
        return;
    }

    struct Matiere matiere;

    while (fread(&matiere, sizeof(matiere), 1, f) == 1) {
        struct noeudMatiere* nouvelMatiere = malloc(sizeof(struct noeudMatiere));
        nouvelMatiere->val = matiere;
        nouvelMatiere->suivant = NULL;

        switch (choix) {
            case 1:
                if (tete == NULL || strcmp(matiere.designation, tete->val.designation) < 0) {
                    nouvelMatiere->suivant = tete;
                    tete = nouvelMatiere;
                } else {
                    struct noeudMatiere* courant = tete;
                    while (courant->suivant != NULL && strcmp(matiere.designation, courant->suivant->val.designation) >= 0) {
                        courant = courant->suivant;
                    }
                    nouvelMatiere->suivant = courant->suivant;
                    courant->suivant = nouvelMatiere;
                }
                break;

            case 2:
                if (tete == NULL || strcmp(matiere.designation, tete->val.designation) > 0) {
                    nouvelMatiere->suivant = tete;
                    tete = nouvelMatiere;
                } else {
                    struct noeudMatiere* courant = tete;
                    while (courant->suivant != NULL && strcmp(matiere.designation, courant->suivant->val.designation) <= 0) {
                        courant = courant->suivant;
                    }
                    nouvelMatiere->suivant = courant->suivant;
                    courant->suivant = nouvelMatiere;
                }
                break;
        }
    }

    fclose(f);

    printf(" ------------------------Liste des matieres-------------------------\n");
    printf("Designation         Coefficient       Code :\n\n");

    struct noeudMatiere* courant = tete;
    while (courant != NULL) {
        struct Matiere matiere = courant->val;
        printf("%s            %d               %s\n",
               matiere.designation, matiere.Coefficient, matiere.code);
        courant = courant->suivant;
    }

    courant = tete;
    while (courant != NULL) {
        struct noeudMatiere* suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }
}

void saisirLesNotes() {
    FILE* fichierEtudiants = fopen("etudiants.dat", "rb");
    FILE* fichierMatieres = fopen("matieres.dat", "rb");
    FILE* fichierNotes = fopen("notes.dat", "wb");

    if (fichierEtudiants == NULL || fichierMatieres == NULL || fichierNotes == NULL) {
        printf("ERREUR!!!!Impossible d'ouvrir les fichiers .\n");
        return;
    }
    struct noeudEtudiant* teteEtudiants = NULL;
    struct Etudiant etudiant;
    while (fread(&etudiant, sizeof(struct Etudiant), 1, fichierEtudiants) == 1) {
        struct noeudEtudiant* nouvelEtudiant = malloc(sizeof(struct noeudEtudiant));
        nouvelEtudiant->val = etudiant;
        nouvelEtudiant->suivant = NULL;

        if (teteEtudiants == NULL) {
            teteEtudiants = nouvelEtudiant;
        } else {
            struct noeudEtudiant* courant = teteEtudiants;
            while (courant->suivant != NULL) {
                courant = courant->suivant;
            }
            courant->suivant = nouvelEtudiant;
        }
    }
    struct noeudMatiere* teteMatieres = NULL;
    struct Matiere matiere;
    while (fread(&matiere, sizeof(struct Matiere), 1, fichierMatieres) == 1) {
        struct noeudMatiere* nouvelleMatiere = malloc(sizeof(struct noeudMatiere));
        nouvelleMatiere->val = matiere;
        nouvelleMatiere->suivant = NULL;

        if (teteMatieres == NULL) {
            teteMatieres = nouvelleMatiere;
        } else {
            struct noeudMatiere* courant = teteMatieres;
            while (courant->suivant != NULL) {
                courant = courant->suivant;
            }
            courant->suivant = nouvelleMatiere;
        }
    }

    if (teteEtudiants == NULL || teteMatieres == NULL) {
        printf("L'etudiants ou la matieres n'existe pas.\n");
    } else {
        struct noeudEtudiant* courantEtudiants = teteEtudiants;
        while (courantEtudiants != NULL) {
            printf("\nEtudiant : %s %s\n", courantEtudiants->val.nom, courantEtudiants->val.prenom);

            struct noeudMatiere* courantMatieres = teteMatieres;
            while (courantMatieres != NULL) {
                float note;
                do {
                    printf("* Note pour %s : ", courantMatieres->val.designation);
                    scanf("%f", &note);
                    if (note < 0 || note > 20) {
                        printf("\nRessayer avec une note valide !\n");
                    }
                } while (note < 0 || note > 20);

                fwrite(&note, sizeof(float), 1, fichierNotes);
                courantMatieres = courantMatieres->suivant;
            }

            courantEtudiants = courantEtudiants->suivant;
        }

        x = 1;
        printf("\n\n Notes saisies avec succes \n");
    }

    fclose(fichierEtudiants);
    fclose(fichierMatieres);
    fclose(fichierNotes);
    system("PAUSE>null");
    system("cls");
}

void af2icherLesNotes() {
    FILE* fichierEtudiants = fopen("etudiants.dat", "rb");
    FILE* fichierMatieres = fopen("matieres.dat", "rb");
    FILE* fichierNotes = fopen("notes.dat", "rb");

    if (fichierEtudiants == NULL || fichierMatieres == NULL || fichierNotes == NULL) {
        printf("Impossible d'ouvrir les fichiers .\n");
        return;
    }

    struct noeudEtudiant* teteEtudiants = NULL;
    struct Etudiant etudiant;
    while (fread(&etudiant, sizeof(struct Etudiant), 1, fichierEtudiants) == 1) {
        struct noeudEtudiant* nouvelEtudiant = malloc(sizeof(struct noeudEtudiant));
        nouvelEtudiant->val = etudiant;
        nouvelEtudiant->suivant = NULL;

        if (teteEtudiants == NULL) {
            teteEtudiants = nouvelEtudiant;
        } else {
            struct noeudEtudiant* courant = teteEtudiants;
            while (courant->suivant != NULL) {
                courant = courant->suivant;
            }
            courant->suivant = nouvelEtudiant;
        }
    }

    struct noeudMatiere* teteMatieres = NULL;
    struct Matiere matiere;
    while (fread(&matiere, sizeof(struct Matiere), 1, fichierMatieres) == 1) {
        struct noeudMatiere* nouvelleMatiere = malloc(sizeof(struct noeudMatiere));
        nouvelleMatiere->val = matiere;
        nouvelleMatiere->suivant = NULL;

        if (teteMatieres == NULL) {
            teteMatieres = nouvelleMatiere;
        } else {
            struct noeudMatiere* courant = teteMatieres;
            while (courant->suivant != NULL) {
                courant = courant->suivant;
            }
            courant->suivant = nouvelleMatiere;
        }
    }

    if (teteEtudiants == NULL || teteMatieres == NULL) {
        printf("L'etudiants ou la matieres n'existe pas.\n");
    } else {
        struct noeudEtudiant* courantEtudiants = teteEtudiants;
        while (courantEtudiants != NULL) {
            printf("\nEtudiant : %s %s\n", courantEtudiants->val.nom, courantEtudiants->val.prenom);

            struct noeudMatiere* courantMatieres = teteMatieres;
            while (courantMatieres != NULL) {
                float note;
                fread(&note, sizeof(float), 1, fichierNotes);
                printf("* Note pour %s : %.2f\n", courantMatieres->val.designation, note);

                courantMatieres = courantMatieres->suivant;
            }

            courantEtudiants = courantEtudiants->suivant;
        }
    }

    fclose(fichierEtudiants);
    fclose(fichierMatieres);
    fclose(fichierNotes);
    system("PAUSE>null");
    system("cls");
}

void menu1(){
 choix=0; 
 do {
 printf("\n\n          ========================================================= \n\n");
 printf("      [1]  Saisir plusiurs etudiants \n");
 printf("      [2]  Saisir un etudaint \n");
 printf("      [3]  Modifier un etudiant \n");
 printf("      [4]  Supprimer un etudiant \n");
 printf("      [5]  Quitter \n");
 printf("\n          ========================================================= \n\n");
 printf("Entre votre choix : ");
 scanf("%d",&choix);
   printf("\n\n");
   switch(choix){
case 1: system("cls");SaisirPlusieursEtudiants();break;
case 2: system("cls");SaisirUnEtudaint();break;
case 3: system("cls");ModifierUnEtudiant();break;
case 4: system("cls");SupprimerUnEtudiant();break;
case 5: system("cls");main();break;
default: system("cls");printf("le code de l'operation n'existe pas!\n Entrez un choix valide .\n");
   }
    }while(choix!=5 && quiter==-1);
}
   
void sousMenu2(){
 choix=0;
 do {
 printf("\n\n          ========================================================= \n\n");
 printf("      [1]  Saisir plusiurs matieres \n");
 printf("      [2]  Saisir une matiere \n");
 printf("      [3]  Modifier une matiere\n");
 printf("      [4]  Supprimer une matiere \n");
 printf("      [5]  Quitter\n");
 printf("\n          ========================================================= \n\n");
 printf("Entrez votre choix : ");
 scanf("%d",&choix);
   printf("\n\n");
   switch(choix){
case 1 : system("cls");SaisirPlusieursMatieres();break;
case 2: system("cls");SaisirUneMatiere();break;
case 3: system("cls");ModifierUneMatiere();break;
case 4: system("cls");SupprimerUneMatiere();break;
case 5: system("cls");main();break;
default: system("cls");printf("le code de l'operation n'existe pas!\n Entrez un choix valide.\n");
   }
   }while(choix!=5 && quiter==-1);
}


void menu4(){
 choix=0;
   if (n == 0) {
        printf("\n\nLa liste d'etudiant est vide !!!!!!!\n");system("PAUSE>null");system("cls");
        return;
    }
do{
printf("\n\n          ============================================================================ \n\n");
 printf("      [1]  Afficher avec l'ordre enregistre lors de la saisie \n");
 printf("      [2]  Afficher avec l'ordre alphabetique (ascendant/descendant) de leur nom \n");
 printf("      [3]  Afficher avec l'ordre croissant/decroissant de leur moyenne \n");
 printf("      [4]  Quitter \n");
 printf("\n          ============================================================================= \n\n");
 printf("Entre votre choix : ");
 scanf("%d",&choix);
   printf("\n\n");
   switch(choix){
case 1: system("cls");Af2ichageOrdreDeSaisieE();break;
case 2: system("cls");Af2ichageOrdreAlphabetiqueE();break;
case 3: system("cls");Af2ichageOrdreDeMoyenneE();break;
case 4: system("cls");main();break;
default: system("cls");printf("votre choix est invalide ,entrez un choix valide .\n");
   }
   }while(choix!=4 && quiter==-1);
}

void sousMenu5(){
 choix=0;
  if (nm == 0) {
        printf("\n\nLa liste des matieres est vide !\n");system("PAUSE>null");system("cls");
        return;
    }
do{
 printf("\n\n          =================================================================================== \n\n");
 printf("      [1]   avec l'ordre enregistr� lors de la saisie\n");
 printf("      [2]   avec l'ordre alphab�tique (ascendant/descendant) de leur d�signation \n");
 printf("      [3]   avec l'ordre croissant/d�croissant de leur moyenne \n");
 printf("      [4]  Quitter \n");
 printf("\n          =================================================================================== \n\n");
 printf("Entre votre choix : ");
 scanf("%d",&choix);
 printf("\n\n");
   switch(choix){
case 1: system("cls");Af2ichageOrdreDeSaisieM();break;
case 2: system("cls");Af2ichageOrdreAlphabetiqueM();break;
case 3: system("cls");//Af2ichageOrdreDeMoyenneM();break;
case 4: system("cls");main();break;
default: system("cls");printf("entrez un choix valide .\n");
   }
   }while(choix!=4 && quiter==-1);
}

void quitter(){
 quiter=1;
 printf("\n\n\n\n\n\n\n                     *---------     FIN     ---------*\n");
}

//////menu principale :

int main(){
n=0;nm=0;
f=fopen("etudiants.dat","rb");
f2=fopen("matieres.dat","rb");
while(fread(&kaleb, sizeof(kaleb), 1, f) == 1){
n++;
}
while(fread(&kaleb2, sizeof(kaleb2), 1, f2) == 1){
nm++;
}
fclose(f);
fclose(f2);
 do {printf("\n                 *******  *******    Bienvenue dans votre espace etudiant     ******* ****** \n\n");
           printf("          ========================================================= \n\n");
           printf("      [1]  Ajouter, modifier et supprimer des �tudiants \n");
           printf("      [2]  Ajouter, modifier et supprimer des mati�res\n");
           printf("      [3]  Afficher les notes des etudiants\n");
           printf("      [4]  Saisir les notes des mati�res pour les �tudiants\n");
           printf("      [5]  Afficher la liste des etudiants\n");
           printf("      [6]  Afficher la liste des mati�res  \n");
           printf("      [7]  Quitter\n\n\n\n\n\n\n\n\n");
           printf("          =============================================================================================== ");

                     
           printf("          ======================================================================================================= \n\n\n\n\n\n");
           printf("  Totale des eleves : %d                               Totale des matieres : %d\n\n",n,nm);
           printf("Entre votre choix  : ");
            
           scanf("%d",&choix);
           printf("\n\n\n\n\n\n");
           switch(choix)
{
case 1: system("cls");menu1();break;
case 2: system("cls");sousMenu2();break;
case 3: system("cls");af2icherLesNotes();break;
case 4: system("cls");saisirLesNotes();break;
case 5: system("cls");menu4();break;
case 6: system("cls");sousMenu5();break;
case 7: system("cls");quitter();break;
default : system("cls");printf("Le code d'operation n'existe pas ,entrez un choix valide .\n");
}      }while(choix!=7);
    return 0;
}




