#include <gtk/gtk.h>

typedef struct{
	char nom_hebergent[30];
	char prenom_hebergent[30];
	char chambre_etudiant[30];
	char bloc_foyer[30];
	char ID[30];
	char Niveau[30];
	char genre[30];
	char type_chambre[30];
}etudiantHB;
 
void ajouter_etudiant(etudiantHB HB);
void afficher_etudiant(GtkWidget *liste,char file[300]);
void supprimer_etudiant(char ID[30]);
void modifier_etudiant(etudiantHB HB);
void chercher_etudiant(char ID[30]);
int stats_etudiant(int Calculer[],char file[]);
