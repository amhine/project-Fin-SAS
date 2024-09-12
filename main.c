#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int anne;
    int mois;
    int jours;
} Naissance;

typedef struct {
    int numero;
    char nom[100];
    char prenom[100];
    Naissance datenaissance;
    char departement[100];
    int notegenerale;
} Etudes;

Etudes etudiant[1000];
int conteur = 0;

void afficher_etudiants() {
    if (conteur > 0) {
        for (int i = 0; i < conteur; i++) {
            printf("Numero: %d\n", etudiant[i].numero);
            printf("Nom: %s\n", etudiant[i].nom);
            printf("Prenom: %s\n", etudiant[i].prenom);
            printf("Note: %d\n", etudiant[i].notegenerale);
            printf("Departement: %s\n", etudiant[i].departement);
            printf("Date de naissance: %d-%d-%d\n", etudiant[i].datenaissance.anne, etudiant[i].datenaissance.mois, etudiant[i].datenaissance.jours);
        }
    } else {
        printf("La liste des etudiants est vide.\n");
    }
}

void trimoyen() {
    //j'ai utuliser methode de selection
    for (int i = 0; i < conteur - 1; i++) {
        int max = i;
        for (int j = i + 1; j < conteur; j++) {
            if (etudiant[j].notegenerale > etudiant[max].notegenerale) {
                max = j;
            }
        }

        Etudes TEMP = etudiant[i];
        etudiant[i] = etudiant[max];
        etudiant[max] = TEMP;
    }


}

void etudientdefaut() {
    if (conteur == 0) {
        strcpy(etudiant[conteur].nom, "Nihad");
        strcpy(etudiant[conteur].prenom, "Amhine");
        etudiant[conteur].datenaissance.anne = 2002;
        etudiant[conteur].datenaissance.mois = 8;
        etudiant[conteur].datenaissance.jours = 22;
        strcpy(etudiant[conteur].departement, "SMA");
        etudiant[conteur].notegenerale = 17;
        etudiant[conteur].numero = conteur;
        conteur++;

        strcpy(etudiant[conteur].nom, "Hadia");
        strcpy(etudiant[conteur].prenom, "Amhine");
        etudiant[conteur].datenaissance.anne = 1999;
        etudiant[conteur].datenaissance.mois = 10;
        etudiant[conteur].datenaissance.jours = 21;
        strcpy(etudiant[conteur].departement, "SMI");
        etudiant[conteur].notegenerale = 19;
        etudiant[conteur].numero = conteur;
        conteur++;

        strcpy(etudiant[conteur].nom, "Wiam");
        strcpy(etudiant[conteur].prenom, "Sliman");
        etudiant[conteur].datenaissance.anne = 2001;
        etudiant[conteur].datenaissance.mois = 7;
        etudiant[conteur].datenaissance.jours = 16;
        strcpy(etudiant[conteur].departement, "SMP");
        etudiant[conteur].notegenerale = 14;
        etudiant[conteur].numero = conteur;
        conteur++;

        strcpy(etudiant[conteur].nom, "Haitam");
        strcpy(etudiant[conteur].prenom, "Amin");
        etudiant[conteur].datenaissance.anne = 2013;
        etudiant[conteur].datenaissance.mois = 27;
        etudiant[conteur].datenaissance.jours = 13;
        strcpy(etudiant[conteur].departement, "SMC");
        etudiant[conteur].notegenerale = 17;
        etudiant[conteur].numero = conteur;
        conteur++;
    }
}

void triparnom() {
    for (int i = 0; i < conteur - 1; i++) {
        for (int j = i + 1; j < conteur; j++) {
            if (strcmp(etudiant[i].nom, etudiant[j].nom) > 0) {
                Etudes tmp = etudiant[i];
                etudiant[i] = etudiant[j];
                etudiant[j] = tmp;
            }
        }
    }
}

void trireussi() {
    for (int i = 0; i < conteur; i++) {
        if (etudiant[i].notegenerale >= 10) {
            printf("Numero: %d\n", etudiant[i].numero);
            printf("Nom: %s\n", etudiant[i].nom);
            printf("Prenom: %s\n", etudiant[i].prenom);
            printf("Note: %d\n", etudiant[i].notegenerale);
            printf("Departement: %s\n", etudiant[i].departement);
            printf("Date de naissance: %d-%d-%d\n", etudiant[i].datenaissance.anne, etudiant[i].datenaissance.mois, etudiant[i].datenaissance.jours);
        }
    }
}
void affichernbrtotaletudiants() {
 printf("Nombre total d'etudiants inscrits : %d\n", conteur);
}
void afficherseuil(int seuil) {


    printf("les etudiant qu on note grande que seul %d:\n", seuil);
    for (int i = 0; i < conteur; i++) {
        if (etudiant[i].notegenerale >=seuil) {
            printf("Numero: %d\n", etudiant[i].numero);
            printf("Nom: %s\n", etudiant[i].nom);
            printf("Prenom: %s\n", etudiant[i].prenom);
            printf("Note: %d\n", etudiant[i].notegenerale);
            printf("Departement: %s\n", etudiant[i].departement);
            printf("Date de naissance: %d-%d-%d\n", etudiant[i].datenaissance.anne, etudiant[i].datenaissance.mois, etudiant[i].datenaissance.jours);
            printf("\n");

        }
    }
}
void affichage3mieurnotes(){
 trimoyen();
    for (int i = 0; i  < 3; i++) {
        printf("Numero: %d\n", etudiant[i].numero);
        printf("Nom: %s\n", etudiant[i].nom);
        printf("Prenom: %s\n", etudiant[i].prenom);
        printf("Note: %d\n", etudiant[i].notegenerale);
        printf("Departement: %s\n", etudiant[i].departement);
        printf("Date de naissance: %d %d %d\n", etudiant[i].datenaissance.anne, etudiant[i].datenaissance.mois, etudiant[i].datenaissance.jours);

    }
}
 char  departementRecherche[100];
void affiche_list_depart(char *departement) {
   int found = 0;
    for (int i = 0; i < 3; i++) {
        if (strcmp(etudiant[i].departement, departementRecherche) == 0) {
            printf("Numero: %d\n", etudiant[i].numero);
            printf("Nom: %s\n", etudiant[i].nom);
            printf("Prenom: %s\n", etudiant[i].prenom);
            printf("Note: %d\n", etudiant[i].notegenerale);
            printf("Departement: %s\n", etudiant[i].departement);
            printf("Date de naissance: %d-%d-%d\n", etudiant[i].datenaissance.jours, etudiant[i].datenaissance.mois, etudiant[i].datenaissance.anne);

            found = 1;
        }
    }
}
void calculer_moyennes() {
int sommenotes[50] = {0};//tablequ vide
    int nombreetudiants[50] = {0};
    char departements[50][100];
    int nombredepartements = 0;
    for (int i = 0; i < conteur; i++) {
        int existe = 0;
        for (int j = 0; j < nombredepartements; j++) {
            if (strcmp(etudiant[i].departement, departements[j]) == 0) {
                existe = 1;//il a trouver la departement
                break;
            }
        }
        if (!existe) {
            strcpy(departements[nombredepartements], etudiant[i].departement);
            nombredepartements++;
        }
    }
     for (int i = 0; i < conteur; i++) {
        for (int j = 0; j < nombredepartements; j++) {
            if (strcmp(etudiant[i].departement, departements[j]) == 0) {
                sommenotes[j] += etudiant[i].notegenerale;
                nombreetudiants[j]++;
                break;
            }
        }
    }
     printf("La moiyenne de la departement:\n");
    for (int i = 0; i < nombredepartements; i++) {
        printf("Departement: %s, Moyenne: %d\n", departements[i], sommenotes[i] / nombreetudiants[i]);
    }
}


void nombreDesEtudiantD(){
    int nombreDesEtSMA= 0;
    int nombreDesEtSMP= 0;
    int nombreDesEtSMC= 0;
    int nombreDesEtSMI= 0;
    for(int i =0 ; i<conteur ; i++){
        if(strcmp(etudiant[i].departement, "SMA")==0){
            nombreDesEtSMA++;
        }
         if(strcmp(etudiant[i].departement, "SMP")==0){
            nombreDesEtSMP++;
        }
         if(strcmp(etudiant[i].departement, "SMI")==0){
            nombreDesEtSMI++;
        }
         if(strcmp(etudiant[i].departement, "SMC")==0){
            nombreDesEtSMC++;
        }
    }

    printf("les nombre de departement de SMA  %d  \n\n" , nombreDesEtSMA);
    printf("les nombre de departement de SMI %d \n\n" , nombreDesEtSMI);
    printf("les nombre de departement de SMP %d \n\n" , nombreDesEtSMP);
    printf("les nombre de departement de SMC %d \n\n" , nombreDesEtSMC);


}

void nbretudiantreussi() {
    // tableaux pour stocker les départements et les comptages
    char departements[50][100];
    int nombreEtudiantsReussis[50] = {0}; // Initialiser  compteurs à 0
    int nombreDepartements = 0;

    // Trouver les départements
    for (int i = 0; i < conteur; i++) {
        int existe = 0;
        for (int j = 0; j < nombreDepartements; j++) {
            if (strcmp(etudiant[i].departement, departements[j]) == 0) {
                existe = 1;
                break;
            }
        }
        if (existe ==0) {//departement na pas trouver
            strcpy(departements[nombreDepartements], etudiant[i].departement);
            nombreDepartements++;
        }
    }

    // Compter le nombre d'étudiants ayant réussi dans chaque département
    for (int i = 0; i < conteur; i++) {
        if (etudiant[i].notegenerale >= 10) { // Vérifie si l'étudiant a réussi
            for (int j = 0; j < nombreDepartements; j++) {
                if (strcmp(etudiant[i].departement, departements[j]) == 0) {
                    nombreEtudiantsReussis[j]++;
                    break;
                }
            }
        }
    }

    // Afficher les résultats
    for (int i = 0; i < nombreDepartements; i++) {
        printf("departement: %s, nombre des etudient reusi: %d\n",
               departements[i], nombreEtudiantsReussis[i]);
    }
}


int main() {

    etudientdefaut();

    int choix;
    int nvnum;
    int nvnote;
    char nvnom[100], nvdepart[100];
    char nvprenom[100], nvdep[100];
    int tmp = -1;
    Naissance nvnaissance;
    char choiix, choixx, chooix, cchoix,chhoix;
    int ajout;
    char departement[50];


    do {
        printf("1 - Ajouter un etudiant\n");
        printf("    a - Ajouter un seul etudiant\n");
        printf("    b - Ajouter plusieurs etudiants\n");
        printf("    c - Liste par defaut\n");
        printf("2 - Modifier ou supprimer\n");
        printf("    a - Modifier\n");
        printf("    b - Supprimer\n");
        printf("3 - Afficher les details d'un etudiant\n");
        printf("4 - Calculer la moyenne generale\n");
        printf("5 - Statistique\n");
        printf("    a - Afficher le nombre total d'etudiants inscrits\n");
        printf("    b - Afficher le nombre d'etudiants dans chaque departement\n");
        printf("    c - Afficher les etudiants ayant une moyenne generale superieure a un certain seuil\n");
        printf("    d - Afficher les 3 etudiants ayant les meilleures notes\n");
        printf("    e - Afficher le nombre d'etudiants ayant reussi dans chaque departement\n");
        printf("    f - Afficher la liste des etudiants inscrits dans un departement specifique\n");
        printf("6 - Rechercher un etudiant\n");
        printf("    a - Rechercher par nom\n");
        printf("    b - Rechercher par departement\n");
        printf("7 - Trier\n");
        printf("    a - Tri alphabetique des etudiants\n");
        printf("    b - Tri des etudiants par moyenne generale\n");
        printf("    c - Tri des etudiants selon leur statut de reussite\n");
        printf("0 - Quitter\n");

        printf("Entrer votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("    a - Ajouter un seul etudiant\n");
                printf("    b - Ajouter plusieurs etudiants\n");
                printf("    c - Liste par defaut\n");
                printf("Saisir votre choix :\n ");
                scanf(" %c", &choixx);

                switch (choixx) {
                    case 'a':
                        if (conteur < 1000) {
                            printf("Saisir le nom:\n ");
                            scanf("%s", etudiant[conteur].nom);
                            printf("Saisir le prenom:\n ");
                            scanf("%s", etudiant[conteur].prenom);
                            printf("Saisir la date de naissance (annee mois jour):\n ");
                            scanf("%d %d %d", &etudiant[conteur].datenaissance.anne,
                                              &etudiant[conteur].datenaissance.mois,
                                              &etudiant[conteur].datenaissance.jours);
                            printf("Saisir le departement:\n ");
                            scanf("%s", etudiant[conteur].departement);
                            printf("Saisir la note generale: \n");
                            scanf("%d", &etudiant[conteur].notegenerale);

                            etudiant[conteur].numero = conteur;
                            conteur++;

                            printf("Etudiant ajoute avec succes.\n");
                        } else {
                            printf("Limite d'etudiants atteinte.\n");
                        }
                        break;

                    case 'b':
                        printf("Saisir le nombre d'etudiants a ajouter: ");
                        scanf("%d", &ajout);
                        for (int i = 0; i < ajout; i++) {
                            if (conteur < 1000) {
                                printf("Saisir le nom:\n ");
                                scanf("%s", etudiant[conteur].nom);
                                printf("Saisir le prenom:\n ");
                                scanf("%s", etudiant[conteur].prenom);
                                printf("Saisir la date de naissance (annee mois jour):\n ");
                                scanf("%d %d %d", &etudiant[conteur].datenaissance.anne,
                                                  &etudiant[conteur].datenaissance.mois,
                                                  &etudiant[conteur].datenaissance.jours);
                                printf("Saisir le departement:\n ");
                                scanf("%s", etudiant[conteur].departement);
                                printf("Saisir la note generale: \n");
                                scanf("%d", &etudiant[conteur].notegenerale);

                                etudiant[conteur].numero = conteur;
                                conteur++;

                                printf("Etudiant ajoute avec succes.\n");
                            } else {
                                printf("Limite d'etudiants atteinte.\n");
                                break;
                            }
                        }
                        break;

                    case 'c':
                        etudientdefaut();
                        break;
                }
                break;

            case 2:
                printf("Saisir votre choix pour modifier ou supprimer \n ");
                printf("a - Modifier\n");
                printf("b - Supprimer\n");
                scanf(" %c", &choiix);

                switch (choiix) {
                    case 'a':
                        printf("Saisir le numero de l'etudiant a modifier:\n ");
                        scanf("%d", &nvnum);
                        tmp = -1; // Si le numero n'est pas trouve
                        for (int i = 0; i < conteur; i++) {
                            if (etudiant[i].numero == nvnum) {
                                tmp = i; // Incrementation de numero unique
                                break;
                            }
                        }

                        if (tmp != -1) {
                            printf("Saisir le nouveau nom: ");
                            scanf("%s", nvnom);
                            strcpy(etudiant[tmp].nom, nvnom);

                            printf("Saisir le nouveau prenom: ");
                            scanf("%s", nvprenom);
                            strcpy(etudiant[tmp].prenom, nvprenom);

                            printf("Saisir la nouvelle date de naissance (annee mois jour):\n");
                            scanf("%d %d %d", &nvnaissance.anne, &nvnaissance.mois, &nvnaissance.jours);
                            etudiant[tmp].datenaissance = nvnaissance;

                            printf("Saisir la nouvelle note generale: ");
                            scanf("%d", &nvnote);
                            etudiant[tmp].notegenerale = nvnote;

                            printf("Saisir le nouveau departement: ");
                            scanf("%s", nvdepart);
                            strcpy(etudiant[tmp].departement, nvdepart);

                            printf("Etudiant modifie avec succes.\n");
                        } else {
                            printf("Etudiant non trouve.\n");
                        }
                        break;

                    case 'b':
                        printf("Saisir le numero de l'etudiant a supprimer: ");
                        scanf("%d", &nvnum);
                        tmp = -1;
                        for (int i = 0; i < conteur; i++) {
                            if (etudiant[i].numero == nvnum) {
                                tmp = i;
                                break;
                            }
                        }

                        if (tmp != -1) {
                            for (int i = tmp; i < conteur - 1; i++) {
                                etudiant[i] = etudiant[i + 1];
                            }
                            conteur--;
                            printf("Etudiant supprime avec succes.\n");
                        } else {
                            printf("Etudiant non trouve.\n");
                        }
                        break;
                }
                break;

            case 3:
                afficher_etudiants();
                break;

            case 4:
                // Calculer la moyenne generale
                calculer_moyennes();
                break;

            case 5:
                // Statistique

        printf("    a - Afficher le nombre total d'etudiants inscrits\n");
        printf("    b - Afficher le nombre d'etudiants dans chaque departement\n");
        printf("    c - Afficher les etudiants ayant une moyenne generale superieure a un certain seuil\n");
        printf("    d - Afficher les 3 etudiants ayant les meilleures notes\n");
        printf("    e - Afficher le nombre d'etudiants ayant reussi dans chaque departement\n");
        printf("    f - Afficher la liste des etudiants inscrits dans un departement specifique\n");
         printf("saisir votre choix svp\n");
        scanf(" %c",&chhoix);

        switch(chhoix){
            case 'a':
                affichernbrtotaletudiants();
                break;
            case 'b':
                //nbretuddepartement();
                nombreDesEtudiantD();
                break;
            case 'c':
                afficherseuil( 12);
                break;
            case 'd':
                affichage3mieurnotes();
                break;
            case 'e':
                nbretudiantreussi();
                break;
            case 'f':
                printf("Saisir le nom de departement: ");
                scanf("%s", departementRecherche);
               affiche_list_depart(departement);
                break;



        } break;
            case 6:
                printf("Saisir votre choix\n");
                printf("a - Rechercher par nom\n");
                printf("b - Rechercher par departement\n");
                scanf(" %c", &chooix);

                switch (chooix) {
                    case 'a':
                        printf("Saisir le nom a rechercher: ");
                        scanf("%s", nvnom);

                        if (conteur > 0) {
                            for (int i = 0; i < conteur; i++) {
                                if (strcmp(etudiant[i].nom, nvnom) == 0) {
                                    printf("Numero: %d\n", etudiant[i].numero);
                                    printf("Nom: %s\n", etudiant[i].nom);
                                    printf("Prenom: %s\n", etudiant[i].prenom);
                                    printf("Note: %d\n", etudiant[i].notegenerale);
                                    printf("Departement: %s\n", etudiant[i].departement);
                                    printf("Date de naissance: %d-%d-%d\n", etudiant[i].datenaissance.anne, etudiant[i].datenaissance.mois, etudiant[i].datenaissance.jours);
                                }
                            }
                        } else {
                            printf("Aucun etudiant disponible.\n");
                        }
                        break;

                    case 'b':
                        printf("Saisir le departement a rechercher: ");
                        scanf("%s", nvdep);

                        if (conteur > 0) {
                            for (int i = 0; i < conteur; i++) {
                                if (strcmp(etudiant[i].departement, nvdep) == 0) {
                                    printf("Numero: %d\n", etudiant[i].numero);
                                    printf("Nom: %s\n", etudiant[i].nom);
                                    printf("Prenom: %s\n", etudiant[i].prenom);
                                    printf("Note: %d\n", etudiant[i].notegenerale);
                                    printf("Departement: %s\n", etudiant[i].departement);
                                    printf("Date de naissance: %d-%d-%d\n", etudiant[i].datenaissance.anne, etudiant[i].datenaissance.mois, etudiant[i].datenaissance.jours);
                                }
                            }
                        } else {
                            printf("Aucun etudiant disponible.\n");
                        }
                        break;
                }
                break;

            case 7:
                printf("Saisir votre choix\n");
                printf("a - Tri alphabetique\n");
                printf("b - Tri par moyenne generale\n");
                printf("c - Tri par statut de reussite\n");
                scanf(" %c", &cchoix);

                switch (cchoix) {
                    case 'a':
                        triparnom();
                        break;
                    case 'b':
                        trimoyen();
                        break;
                    case 'c':
                        trireussi();
                        break;
                }
                break;

            case 0:
                printf("Quitter le programme.\n");
                break;

            default:
                printf("Choix invalide. Veuillez reessayer.\n");
                break;
        }
    } while (choix != 0);

    return 0;
}

