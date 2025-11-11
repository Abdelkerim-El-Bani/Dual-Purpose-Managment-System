#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LINE_LENGTH 100
#define MAX_FEEDBACK_LENGTH 150
#ifndef PATIENTS_H
#define PATIENTS_H

typedef struct{
   int jour;
   int mois;
   int annee;
   
}date;

typedef struct patient{
    char nom[20];
    char prenom[20];
    int age;
    int id;
    char date_rendez_vous[20];
    char password[20];
    struct patient *next;
    
}patient;

extern patient *head;

int choixEspace();
int MenuAdministartion();
int MenuPatient();
//MENU ADMIN
patient* creer();
void afficherPatients();
int chercher_par_id(int id_recherche);
void modifierParId(int id);
void ajouterPatientToListe(patient* p);
int supprimer(int pos);
void sauvegarder_patients(patient* liste_patients);
patient* load_patients();
void afficherFeedbackFromFile();

//MENU PATIENT
bool isDateAvailable(const char *rendez_vous, patient *head);
int signup();
void afficherPatientByID(patient *head, int loggedInId);
void addPatientToList(const char *nom, const char *prenom, int id, int age, const char *date);
void loadPatientsFromFile();
bool patientExists(int id);
patient* trouverPatientParID(int id);
int signUpOrConnect();
void annulerRendezVous(patient *head, int id);
void modifierRendezVous(patient *head, int id);
void upgrade(patient *head, int id);
void AjouterFeedbackToFile(const char* feedback);

#endif


