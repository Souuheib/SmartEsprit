#include <gtk/gtk.h>

void ajouterstock (char id[],char type[],int quant);
void supprimerstock(char id1[]);
void modifierstock(char id1[],int quant1);
void afficherstock (GtkTreeView *liste);
void alerte ();
void afficheralerte (GtkTreeView *liste);


