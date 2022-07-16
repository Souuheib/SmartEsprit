#include <gtk/gtk.h>
typedef struct
{
	int jour;
	int mois;
	int annee;
}daterec;
typedef struct 
{
	char cin[30];
	char nom[30];
	char prenom[30];
	char text[50];
	daterec d;
	int type;
	int sexe;
}reclamation;
void ajouter_reclamation(reclamation r);
void afficher_reclamation(GtkWidget *liste,char file[20]);
void modifier_reclamation(reclamation r);
void supprimer_reclamation(char cin[30]);
int service_plus_reclamer();
