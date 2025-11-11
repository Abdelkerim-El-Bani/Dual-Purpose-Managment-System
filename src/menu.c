#include "cabinet.h"

int choixEspace()
{
    
int choixEspace; 

   while(1)
    {
        printf("\n\t          **** Bienvenue dans notre application  *****\n");
        printf("\t **** Veuillez saisir le nombre correspondant à votre choix ****\n\n");
        printf("\t          **** 1 - Espace Administration   *****\n");
        printf("\t          **** 2 - Espace Patient          *****\n");
        printf("\t          **** 3 - Quitter le programme    *****\n");
        printf("----------------------------------------------------------------------\n");
        printf("choix: ");
        scanf("%d",&choixEspace);
        printf("********************************************************************\n\n");
        switch(choixEspace){
        case 1:
            MenuAdministartion();
            break;
        case 2:
            MenuPatient();
            break;
        case 3:
            exit(0);
            break;
            
        default:
            printf("Option inexistante\n");
            break;
        }
       }
return 0;
}
        
int MenuAdministartion(){
date d;
int choix,taille=0,pos,choix_1,id, age;
char nom[20],prenom[20],Rendez_vous[20];
char response;
    while(1)
    {

        printf("\t\n                **** Bienvenue dans l'Espace Administration  *****\n");
        printf("\t **** Veuillez saisir le nombre correspondant à votre choix ****\n\n");
        printf("\t        **** 1 - Creer/Ajouter un patient  *****\n");
        printf("\t        **** 2 - Afficher les patients     *****\n");
        printf("\t        **** 3 - Modifier un patientt      *****\n");
        printf("\t        **** 4 - Supprimer un patient      *****\n");
        printf("\t        **** 5 - Afficher feedback         *****\n");
        printf("\t        **** 6 - Quitter le programme      *****\n");
        printf("----------------------------------------------------------------------\n");
        printf("choix: ");
        scanf("%d",&choix);
        printf("********************************************************************\n\n");
        switch(choix){
         case 1: {
            patient* newPatient = creer();
            if (newPatient != NULL) {
               ajouterPatientToListe(newPatient);
             }
        break;
        }
        case 2:
            afficherPatients();
            break;
        case 3:
            printf("Quel est l'id du patient que voulez-vous modifier?\n");
            scanf("%d",&id);
            modifierParId(id);
            break;
        case 4:
            printf("Quel est l'id du patient que voulez-vous supprimer ?\n");
            scanf("%d", &id);
            pos = chercher_par_id(id);
            if (pos != -1) {
               printf("Confirmez-vous la suppression?[o/n] \n");
               scanf(" %c", &response);
               if (response == 'o') {
                taille = supprimer(pos);
                if (taille != -1) {
                printf("Succès de la suppression\n");
            } else {
                printf("Échec de la suppression\n");
            }
        }
    } else {
        printf("Patient non trouvé\n");
    }
    break;

        case 5:
            afficherFeedbackFromFile();
            break;
            
        case 6:
              sauvegarder_patients(head);
              exit(0);
            break;
        default:
            printf("Option inexistante\n");
            break;
        }
    }

return 0;}

int MenuPatient(){

date d;
int choix,taille=0,pos,choix_1,choix_2,id, loggedInId, age;
char nom[20],prenom[20],Rendez_vous[20], feedback[MAX_FEEDBACK_LENGTH];
    loggedInId=signUpOrConnect(); 
    while(1)
    {
        printf("\t\n                **** Bienvenue dans l'Espace patient  *****\n");
        printf("\t **** Veuillez saisir le nombre correspondant à votre choix ****\n\n");
        printf("                **** 1 - acceder à vos informations  *****\n");
        printf("                **** 2 - Modifier rendez vous        *****\n");
        printf("                **** 3 - Annuler rendez vous         *****\n");
        printf("                **** 4 - Upgrade rendez vous         *****\n");
        printf("                **** 5 - Contactez nous              *****\n");
        printf("                **** 6 - Quitter le programme        *****\n");
        printf("----------------------------------------------------------------------\n");
        printf("choix: ");
        scanf("%d",&choix);
        printf("********************************************************************\n\n");
        switch(choix){
        case 1:
            afficherPatientByID(head, loggedInId);
            break;
        case 2:
            modifierRendezVous(head, loggedInId);
            break;
        case 3:
            annulerRendezVous(head, loggedInId);
            break;
        case 4:
            upgrade(head, loggedInId);
            break;
	case 5:
    		printf("                 ****             C O N T A C T         *****\n");
    		printf("Numéro: (+216)00-000-000  \n");
    		printf("e-mail: cabinet@test.com  \n\n");
    		printf("                **** 1 - Donner du feedback (max 150 char) *****\n");
    		printf("                **** 2 - Retour au menu principal          *****\n");
    		printf("----------------------------------------------------------------------\n");
    		printf("choix: ");
    		scanf("%d", &choix_2);
    		getchar(); 
		
    		printf("********************************************************************\n\n");
    		switch (choix_2) {
    		    case 1:
    		        fgets(feedback, MAX_FEEDBACK_LENGTH, stdin);
    		        feedback[strcspn(feedback, "\n")] = '\0';
    		        AjouterFeedbackToFile(feedback);
    		        break;
    		    case 2:
    		        break;
    		    default:
    		        break;
    		}
    		break;
        case 6:
            sauvegarder_patients(head);
            exit(0);
            break;
        default:
            printf("Option inexistante\n");
            break;
        }
      }
    
return 0;}

