#include <gtk/gtk.h> 

typedef struct capteur {
	char ref[20];
	char type[20];
	char valeur[20];
	int etat;
	int etage;
} CAPTEUR;

void ajouter(CAPTEUR C);
void ajouter_def(CAPTEUR C);
void modifier(CAPTEUR C);
void supprimer_capt(char id[20] );
void consulter_capt(GtkWidget *liste, char fichier[20]);
void chercher_capt( char id[20]);
void capteur_def();
