#include <gtk/gtk.h>


typedef struct 
{char Reference[20] ;
char Type[20];
char Localisation[10];
char Valeur_Min[20];
char Valeur_Max[20];
char Etat[5];
} capteur;



typedef struct
{ int valeur;
int date;
int heure;
}temps;
typedef struct 
{char Reference[20] ;
char Type[20];
char Localisation[10];
char Valeur_Min[20];
char Valeur_Max[20];
char Etat[5];
} capdef;

void ajouter(capteur C);

void afficher_capteur(GtkWidget *liste);

void supprimer_capteur(char ref[]);

void modifier_capteur(capteur x);

void recherche_capteur(char nom_fichier[],char x[]);

void afficher_capteur_rechercher(char nom_fichier[],GtkWidget *liste);
////////////////
void afficher_capteur_deff(GtkWidget *liste);
void ajouter_capteurdeff(capteur c);
void affichercpadef(GtkWidget *liste);
