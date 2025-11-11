#include "cabinet.h"

//MENU ADMIN

patient* creer() {
    char test[9];
    patient* p = (patient*)malloc(sizeof(patient));
    if (p == NULL) {
        printf("erreur!\n");
        return NULL;
    }

    date d;
    printf("Entrer le nom du patient:\n");
    scanf("%s", p->nom);
    
    printf("Entrer le prenom du patient:\n");
    scanf("%s", p->prenom);
    
    do {
        printf("Entrer l'identifiant du patient: (8 chiffres)\n");
        scanf("%d", &p->id);
        sprintf(test, "%d", p->id);
    } while (strlen(test) != 8);

    do {
        printf("Entrer l'age du patient:\n");
        scanf("%d", &p->age);
    } while (p->age < 0);

    bool dateAvailable = false;
    while (!dateAvailable) {
        printf("Entrer le rendez vous du patient:\n");
        do {
            printf("jour: \n");
            scanf("%d", &d.jour);
            printf("mois: \n");
            scanf("%d", &d.mois);
            printf("annee: \n");
            scanf("%d", &d.annee);
        } while (d.annee < 2023 || d.mois < 1 || d.mois > 12 || d.jour < 1 || d.jour > 31);

        sprintf(p->date_rendez_vous, "%d/%d/%d", d.jour, d.mois, d.annee);

        if (isDateAvailable(p->date_rendez_vous, head)) {
            dateAvailable = true; 
        } else {
            printf("La date est déjà prise. Veuillez choisir une autre date.\n");
        }
    }
    printf("Entrer le mot de passe du patient:\n");
    scanf("%s", p->password);
    
    p->next = NULL;

    printf("\nCreation du patient avec succès\n");
    return p;
}


void ajouterPatientToListe(patient* newPatient) 
{
    if (newPatient == NULL) {
        printf("Invalid patient data.\n");
        return;
    }

    if (head == NULL) {
        head = newPatient;
        return;
    }
    patient* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newPatient;
    newPatient->next = NULL;
}

void afficherPatients() 
{
    printf("Informations des patients:\n\n");
    patient* current = head;
    int isEmpty = 1;

    while (current != NULL) {
        printf("%s %s %d %d %s %s\n", current->nom, current->prenom, current->id, current->age, current->date_rendez_vous, current->password);
        isEmpty = 0;
        current = current->next;
    }

    printf("\n********************************************************************\n\n");

    if (isEmpty) {
        printf("Pas de patients enregistres\n");
    }
}

int chercher_par_id(int id_recherche) 
{
    patient* current = head;
    int lineNum = 0;

    while (current != NULL) {
        if (current->id == id_recherche) {
            return lineNum;
        }

        lineNum++;
        current = current->next;
    }

    printf("Patient n'existe pas\n");
    return -1;
}


void modifierParId(int id) {
    date d;
    patient* current = head;
    int found = 0;

    while (current != NULL) {
        if (current->id == id) {
            found = 1;
            printf("Que voulez-vous modifier?\n");
            printf("1-Le nom \n");
            printf("2-Le prenom \n");
            printf("3-L'id \n");
            printf("4-L'age \n");
            printf("5-Le rendez vous \n");
            printf("6-Le mot de passe \n");
            printf("7-Revenir au menu principal \n");

            int choix;
            scanf("%d", &choix);

            switch (choix) {
                case 1:
                    printf("Entrer le nouveau nom\n");
                    scanf("%s", current->nom);
                    break;
                case 2:
                    printf("Entrer le nouveau prenom:\n");
                    scanf("%s", current->prenom);
                    break;
                case 3:
                    printf("Entrer la nouvelle id:\n");
                    scanf("%d", &(current->id));
                    break;
                case 4:
                    printf("Entrer la nouvelle age:\n");
                    scanf("%d", &(current->age));
                    break;
		case 5:
   		   
        printf("Entrer le nouveau date:\n");
        bool dateAvailable = false;
        date new_date;

        while (!dateAvailable) {
            printf("jour: \n");
            scanf("%d", &new_date.jour);
            printf("mois: \n");
            scanf("%d", &new_date.mois);
            printf("annee: \n");
            scanf("%d", &new_date.annee);

            if (new_date.annee >= 2023 && new_date.mois >= 1 && new_date.mois <= 12 && new_date.jour >= 1 && new_date.jour <= 31) {
                patient temp;
                strcpy(temp.date_rendez_vous, current->date_rendez_vous);
                sprintf(temp.date_rendez_vous, "%d/%d/%d", new_date.jour, new_date.mois, new_date.annee);

                if (isDateAvailable(temp.date_rendez_vous, head)) {
                    strcpy(current->date_rendez_vous, temp.date_rendez_vous);
                    dateAvailable = true; 
                } else {
                    printf("La date est déjà prise. Veuillez choisir une autre date.\n");
                }
            } else {
                printf("Date invalide. Veuillez saisir une date valide.\n");
            }
        }
        break;
                case 6:
                    printf("Entrer le nouveau mot de passe:\n");
                    scanf("%s", (current->password));
                    break;
                case 7:
                    MenuAdministartion();
                    break;
                default:
                    printf("Choix invalide.\n");
                    break;
            }
        }
        current = current->next;
    }

    if (!found) {
        printf("Patient avec ID %d pas trouvé\n", id);
    } else {
        printf("Patient modifié avec succès\n");
    }
}

int supprimer(int pos) 
{
    if (head == NULL) {
        printf("Liste de patients vide\n");
        return -1;
    }

    int found = 0;
    int lineNum = 0;

    patient* current = head;
    patient* previous = NULL;

    while (current != NULL && lineNum != pos) {
        previous = current;
        current = current->next;
        lineNum++;
    }

    if (current != NULL) {
        found = 1;
        if (previous == NULL) {
            head = current->next;
            free(current);
        } else {
            previous->next = current->next;
            free(current);
        }
    }

    if (!found) {
        printf("Patient n'existe pas\n");
        return -1;
    } else {
        return 0;
    }
}

void sauvegarder_patients(patient *head) 
{
    FILE *file = fopen("/home/kerim/TP1/Files/liste_patients.txt", "w");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    patient *current = head;
    while (current != NULL) {
        fprintf(file, "%s %s %d %d %s %s\n", current->nom, current->prenom, current->id, current->age, current->date_rendez_vous, current->password);
        current = current->next;
    }

    fclose(file);
}

patient* load_patients() 
{
    FILE *file = fopen("/home/kerim/TP1/Files/liste_patients.txt", "r");
    if (file == NULL) {
        printf("Fichier inexistant ou erreur lors de l'ouverture du fichier.\n");
        return NULL;
    }

    patient *head = NULL;
    patient *tail = NULL;
    patient *newPatient;

    while ((newPatient = malloc(sizeof(patient))) != NULL &&
            fscanf(file, "%s %s %d %d %s %s\n", newPatient->nom, newPatient->prenom, &newPatient->id, &newPatient->age, newPatient->date_rendez_vous, newPatient->password) == 6) {

        newPatient->next = NULL;

        if (head == NULL) {
            head = newPatient;
            tail = newPatient;
        } else {
            tail->next = newPatient;
            tail = newPatient;
        }
    }

    fclose(file);
    return head;
}

void afficherFeedbackFromFile() 
{
    FILE* file = fopen("/home/kerim/TP1/Files/feedback.txt", "r");
    if (file == NULL) {
        printf("erreur.\n");
        return;
    }

    char feedback[MAX_FEEDBACK_LENGTH];
    printf("***** Feedback *****\n\n");
    while (fgets(feedback, MAX_FEEDBACK_LENGTH, file) != NULL) {
        printf("%s\n", feedback);
    }

    fclose(file);
}


//MENU PATIENT ------------------------------

bool isDateAvailable(const char *rendez_vous, patient *head) 
{
    patient *current = head;

    while (current != NULL) {
        if (strcmp(current->date_rendez_vous, rendez_vous) == 0) {
            return false; 
        }
        current = current->next;
    }

    return true; 
}


int signup() 
{
    char test[9];
    patient *p = (patient *)malloc(sizeof(patient));
    if (p == NULL) {
        printf("Échec de l'allocation de mémoire pour le nouveau patient.\n");
        return -1;
    }

    date d;
    printf("Ton nom:\n");
    scanf("%s", p->nom);

    printf("Ton prenom:\n");
    scanf("%s", p->prenom);

    do {
        printf("Ton ID: (8 digits)\n");
        scanf("%d", &p->id);
        sprintf(test, "%d", p->id);
    } while (strlen(test) != 8);

    do {
        printf("Ton age:\n");
        scanf("%d", &p->age);
    } while (p->age < 0);

    bool dateAvailable = false;
    while (!dateAvailable) {
        printf("Ton rendez vous:\n");
        do {
            printf("jour: \n");
            scanf("%d", &d.jour);
            printf("mois: \n");
            scanf("%d", &d.mois);
            printf("annee: \n");
            scanf("%d", &d.annee);
        } while (d.annee < 2023 || d.mois < 1 || d.mois > 12 || d.jour < 1 || d.jour > 31);

        sprintf(p->date_rendez_vous, "%d/%d/%d", d.jour, d.mois, d.annee);

        if (isDateAvailable(p->date_rendez_vous, head)) {
            dateAvailable = true; 
        } else {
            printf("La date est déjà prise. Veuillez choisir une autre date.\n");
        }
    }
        printf("Ton mot de passe:\n");
        scanf("%s", p->password);
        
    p->next = NULL;

    printf("\nCreation du patient avec succès\n");


    if (head == NULL) {
        head = p;
    } else {
        patient *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = p;
    }

    return p->id;
}


void afficherPatientByID(patient *head, int loggedInId) {
    patient *current = head;
    int isEmpty = 1;

    while (current != NULL) {
        if (current->id == loggedInId) {
            printf("Votre informations:\n");
            printf("Nom: %s\n", current->nom);
            printf("Prenom: %s\n", current->prenom);
            printf("id: %d\n", current->id);
            printf("age: %d\n", current->age);
            printf("Date de rendez-vous: %s\n", current->date_rendez_vous);
            printf("Mot de passe: %s\n", current->password);
            isEmpty = 0;
            break; 
        }
        current = current->next;
    }

    if (isEmpty) {
        printf("Patient with ID %d not found.\n", loggedInId);
    }
}


bool patientExists(int id) {
    patient *current = head;
    while (current != NULL) {
        if (current->id == id) {
            return true;
        }
        current = current->next;
    }
    return false;
}

patient* trouverPatientParID(int id) {
    patient* current = head;

    while (current != NULL) {
        if (current->id == id) {
            return current; 
        }
        current = current->next;
    }

    return NULL;
}


int signUpOrConnect() 
{
    int id;
    char response;
    bool isExistingPatient = false;
    char Mot_De_Passe[20]; 

    printf("As tu un compte? (o/n):\n");   
    scanf(" %c", &response);

    if (response == 'o') {
        printf("Entrer votre id: ");
        scanf("%d", &id);

        isExistingPatient = patientExists(id);
        if (isExistingPatient) {
            printf("c'est votre ID %d? (o/n): ",id);
            scanf(" %c", &response);
            
            printf("Entrer le mot de passe: ");
            scanf(" %s", Mot_De_Passe);

            patient* Patient_Trouvee = trouverPatientParID(id);

            if (response == 'o' && Patient_Trouvee != NULL && strcmp(Mot_De_Passe, Patient_Trouvee->password) == 0) {
                printf("Logged in avec succés\n");
            } else {
                printf("Mot de passe incorrect ou patient non trouvé.\n\n");
                MenuPatient();
            }

        } else {
            MenuPatient();
        }
    } else {
        int newPatientID = signup(); 
        if (newPatientID != -1) {
            id = newPatientID; 
        } else {
            printf("Échec de la création du nouveau patient.\n");
                  MenuPatient();
        }
    }
    return id;
}

void modifierRendezVous(patient *head, int id) {
    patient *current = head;
    date d;
    int found = 0; 

    while (current != NULL) {
        if (current->id == id) {
            printf("Entrer le nouveau date:\n");
            bool dateAvailable = false;

            while (!dateAvailable) {
                date new_date;
                do {
                    printf("jour: \n");
                    scanf("%d", &new_date.jour);
                    printf("mois: \n");
                    scanf("%d", &new_date.mois);
                    printf("annee: \n");
                    scanf("%d", &new_date.annee);
                } while (new_date.annee < 2023 || new_date.mois < 1 || new_date.mois > 12 || new_date.jour < 1 || new_date.jour > 31);

                patient temp;
                strcpy(temp.date_rendez_vous, current->date_rendez_vous);

                sprintf(temp.date_rendez_vous, "%d/%d/%d", new_date.jour, new_date.mois, new_date.annee);

                if (isDateAvailable(temp.date_rendez_vous, head)) {
                    strcpy(current->date_rendez_vous, temp.date_rendez_vous);
                    printf("La date est disponible. Modification effectuée.\n");
                    dateAvailable = true; 
                } else {
                    printf("La date est déjà prise. Veuillez choisir une autre date.\n");
                }
            }

            found = 1; 
            
        }
        current = current->next;
    }

    if (!found) {
        printf("Patient avec ID %d pas trouvé.\n", id);
    }
}


void annulerRendezVous(patient *head, int id) 
{
    patient *current = head;
    date d;
    char response;

    while (current != NULL) {
        if (current->id == id) {
            printf("Confirmez-vous la suppression?[o/n] \n");
                scanf(" %c", &response);
                if(response=='o'){
                   sprintf(current->date_rendez_vous, "--/--/--");
                   printf("Appointment date deleted successfully.\n");
                   return;
                   }
                else {
                return;
            }
        }
        current = current->next;
    }

    printf("Patient avec ID %d pas trouvé.\n", id);
}

void upgrade(patient *head, int id) 
{
    patient *current = head;
    date d;
    char response;
    printf("Si vous payez un supplément de 50 DT, vous pouvez changer votre rendez-vous pour n'importe quel jour, même s'il est déjà pris. \n");
    while (current != NULL) {
        if (current->id == id) {
        printf("Confirmez-vous l'upgrade? [o/n] \n");
                scanf(" %c", &response);
                if(response=='o'){
                do {
       	 printf("jour: \n");
      		 scanf("%d", &d.jour);
     		 printf("mois: \n");
        	 scanf("%d", &d.mois);
       	 printf("annee: \n");
        	 scanf("%d", &d.annee);
    	} while (d.annee < 2023 || d.mois < 1 || d.mois > 12 || d.jour < 1 || d.jour > 31);

            sprintf(current->date_rendez_vous, "%d/%d/%d", d.jour, d.mois, d.annee);

            printf("Rendez vous modifié.\n");
            return;
            }
            else {
                return;
            }
        }
        current = current->next;
    }

    printf("Patient avec ID %d pas trouvé.\n", id);
}

void AjouterFeedbackToFile(const char* feedback) 
{
    FILE* file = fopen("/home/kerim/TP1/Files/feedback.txt", "a"); 
    if (file == NULL) {
        printf("erreur.\n");
        return;
    }

    fprintf(file, "%s\n", feedback);

    fclose(file);
    printf("Merci pour votre feedback!\n");
}
