#include <stdio.h>

typedef struct date {
    int annee;
    int mois;
    int jour;

} date;

typedef struct person {
    char name[10];
    char lastName[10];
    date dateN;
    int age;
} person;
// function for sorting by  age, i used bubble sorting
void triParAge(person student[], int nbrEtudiants) {
    int i, j;
    person temp;

    for (i = 0; i < nbrEtudiants - 1; i++) {
        for (j = 0; j < nbrEtudiants - i - 1; j++) {
            if (student[j].age > student[j + 1].age) {
                temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }
}
// function for display list of students
void displayStudents(person student[], int nbrEtudiants) {
    for (int i = 0; i < nbrEtudiants; i++) {
        printf("Name: %s, Last Name: %s, Age: %d, Birth Date: %d/%d/%d\n",
               student[i].name, student[i].lastName, student[i].age,
               student[i].dateN.annee, student[i].dateN.mois, student[i].dateN.jour);
    }
}
// function to calc max age
void max_age( person student[], int nbrEtudiants){
    int i;
    int max = student[0].age;
    char maxAgeName[20];

    for ( i = 1 ; i <nbrEtudiants ; i++){
        if(max < student[i].age){
            max = student[i].age;
            strcpy(maxAgeName, student[i].name);
        }
    }
    printf("l apprenant le plus age est %s his age :  %d ",maxAgeName,max);
}
// function to calc min age
void min_age( person student[], int nbrEtudiants){
    int i;
    int min = student[0].age;
    char minAgeName[20];

    for ( i = 1 ; i < nbrEtudiants ; i++){
        if(min > student[i].age){
            min = student[i].age;
            strcpy(minAgeName, student[i].name);
        }
    }
    printf("l apprenant le plus jeune est %s his age :  %d ",minAgeName,min);
}

// function to calc moyenne age
void moyenne( person student[], int nbrEtudiants){
    int i, ageM = 0;
    for ( i = 0 ; i <nbrEtudiants ; i++){
        ageM = ageM + student[i].age;

    }
    printf("l age moyenne est %d",ageM/nbrEtudiants);

}

// function for search by name
void searchByName(person student[], int nbrEtudiants, char name[]) {
    int i;
    int found = 0;

    for (i = 0; i < nbrEtudiants; i++) {
        if (strcmp(name, student[i].name) == 0) {
            printf("Apprenant trouve : %s %s, age : %d\n", student[i].name, student[i].lastName, student[i].age);
            found = 1;
        }
    }

    if (!found) {
        printf("Aucun apprenant trouvé avec ce nom.\n");
    }
}
// function for search by last Name
void searchByLastName(person student[], int nbrEtudiants, char lname[]) {
    int i;
    int found = 0;

    for (i = 0; i < nbrEtudiants; i++) {
        if (strcmp(lname, student[i].lastName) == 0) {
            printf("Apprenant trouve : %s %s, age : %d\n", student[i].name, student[i].lastName, student[i].age);
            found = 1;
        }
    }

    if (!found) {
        printf("Aucun apprenant trouvé avec ce nom.\n");
    }
}
// function for search by date of birth (year)
void searchByDate(person student[], int nbrEtudiants, int pdate) {
    int i;
    int found = 0;

    for (i = 0; i < nbrEtudiants; i++) {
        if (pdate == student[i].dateN.annee) {
            printf("Apprenant trouvé : %s %s, âge : %d\n", student[i].name, student[i].lastName, student[i].age);
            found = 1;
        }
    }

    if (!found) {
        printf("Aucun apprenant trouvé avec cette année de naissance.\n");
    }
}
// function for modify by name
void modByName(person student[], int nbrEtudiants, char name[], char newname[]) {
    int i;
    int found = 0;

   for (i = 0; i < nbrEtudiants; i++) {
        if (strcmp(name, student[i].name) == 0) {
            strcpy(student[i].name, newname);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Aucun apprenant trouvé pour modifier.\n");
    }
}
// modify  last name
void modBylastName(person student[], int nbrEtudiants, char prename[], char newprename[]) {
    int i;
    int found = 0;

   for (i = 0; i < nbrEtudiants; i++) {
        if (strcmp(prename, student[i].lastName) == 0) {
            strcpy(student[i].lastName, newprename);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Aucun apprenant trouvé pour modifier.\n");
    }
}
// modify  date naissance
    void modifyByLastName(person student[], int nbrEtudiants,char name[],int newpjour, int newpmois, int newpannee){
    int i;
    int found = 0;

   for (i = 0; i < nbrEtudiants; i++) {
        if (strcmp(name, student[i].name) == 0) {
            student[i].dateN.mois = newpmois;
            student[i].dateN.annee = newpannee;
            student[i].dateN.jour = newpjour;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Aucun apprenant trouvé pour modifier.\n");
    }
}

// supprimer un apprenant
void supprimer(person student[], int *nbrEtudiants, char name[]) {
    int i;
    int found = 0;

    for (i = 0; i < *nbrEtudiants; i++) {
        if (strcmp(name, student[i].name) == 0) {
            for (int j = i; j < *nbrEtudiants - 1; j++) {
                student[j] = student[j + 1];
            }
            (*nbrEtudiants)--;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Aucun apprenant trouvé pour supprimer.\n");
    }
}


int main() {
    char maxAgeName[10], minAgeName[10] , name[10], lname[10], newname[10], prename[10], newprename[10];
    int i,nbrEtudiants,choix,max,min,ageM,choixSearch,pdate, newpjour, newpmois, newpannee,quitter = 0;
    printf("saisir le nomber des apprenants ");
    scanf("%d",&nbrEtudiants);
    person student[nbrEtudiants];

    for (i = 0; i < nbrEtudiants; i++){
        printf("nom de l apprenants (%d) : ", i+1);
        scanf("%s", &student[i].name);
        printf("prenom de l apprenants (%d) : ", i+1);
        scanf("%s", &student[i].lastName);
        printf("la date de naissance de l apprenants \n");
        printf("annee : ");
        scanf("%d", &student[i].dateN.annee);
        printf("mois : ");
        scanf("%d", &student[i].dateN.mois);
        printf("jours : ");
        scanf("%d", &student[i].dateN.jour);
    }
    for(i = 0; i < nbrEtudiants ; i++){
        student[i].age = 2023 -  student[i].dateN.annee;
    }
    printf("la list des apprenants : ");
    displayStudents(student, nbrEtudiants) ;
    printf("la list des apprenants apres le tri : ");
    triParAge(student, nbrEtudiants) ;
    displayStudents(student, nbrEtudiants) ;


    printf("\n1 - Afficher l'apprenant le plus age.\n");
    printf("2 - Afficher l'apprenant le plus jeune.\n");
    printf("3 - Calculer et afficher l'âge moyen de la classe.\n");
    printf("4 - rechercher des apprenants par nom, prenom ou date de naissance.\n");
    printf("5 - Modification des Donnees des apprenants par nom, prenom ou date de naissance.\n");
    printf("6 - supprimer un apprenant .\n");
    printf("7 - quitter program .\n");
    scanf("%d",&choix);
    while (quitter == 0)
    {
        switch (choix)
    {
    case 1 :
        max_age(student, nbrEtudiants);
        break;
    case 2 :
        min_age(student, nbrEtudiants);
        break;
    case 3 :
        moyenne(student, nbrEtudiants);
        break;
    case 4 :
        printf("1 => par nom .\n2 => prenom\n3 => date de naissance.\n");
        scanf("%d",&choixSearch);

        switch (choixSearch) {
            case 1:
                printf("entre le nom d apprenants que vous voullez trouver : \n");
                scanf("%s",&name);
                searchByName(student,nbrEtudiants,name);

                break;
            case 2:
                printf("entre le prenom d apprenants que vous voullez trouver : \n");
                scanf("%s",&lname);
                searchByLastName(student, nbrEtudiants,lname);
                break;
            case 3:
                printf("entre l age d apprenants que vous voullez trouver : \n");
                scanf("%d",&pdate);
                searchByLastName(student, nbrEtudiants,pdate);
                break;
            default:
                printf("-----------------------------\n");
        }
        break;
    case 5 :
        printf("1 => par nom .\n2 => prenom\n3 => date de naissance.\n");
        scanf("%d",&choixSearch);

        switch (choixSearch) {
            case 1:
                printf("entre le nom d apprenants que vous voullez modifier : \n");
                scanf("%s",&name);
                printf("entre le nouveau nom : \n");
                scanf("%s",&newname);
                modByName(student,nbrEtudiants, name, newname) ;
                displayStudents(student, nbrEtudiants) ;


                break;
            case 2:
                printf("entre le prenom d apprenants que vous voullez modifier : \n");
                scanf("%s",&prename);
                printf("entre le nouveau prenom : \n");
                scanf("%s",&newprename);
                modBylastName(student,nbrEtudiants, prename, newprename) ;
                displayStudents(student, nbrEtudiants) ;
                break;
            case 3:
                printf("entre le nom de l apprenants que vous voullez modifier : \n");
                scanf("%s",&name);

                printf("entre le nouveau date naissance : \n");
                printf("jours : \n");
                scanf("%d",&newpjour);
                printf("mois : \n");
                scanf("%d",&newpmois);
                printf("annee : \n");
                scanf("%d",&newpannee);
                modifyByLastName(student, nbrEtudiants,name, newpjour, newpmois, newpannee);
                displayStudents(student, nbrEtudiants) ;
                break;
            default:
                printf("-----------------------------\n");
        }
        break;
    case 6 :
        printf("entre le nom de l apprenants que vous voullez supprimer : \n");
        scanf("%s",&name);
        supprimer(student, &nbrEtudiants,name);
        displayStudents(student, nbrEtudiants) ;
        break;
    case 7 :
        quitter = 1;
        break;
    default:
        break;
    }
    }


    return 0;
}
