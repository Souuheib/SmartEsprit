#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct date
{
    int j;
    int m;
    int a;
}date;

typedef struct menu
{
    char id[20];
    int type;
    char nom[20];
    float dechet;
    date d;
}menu;

void ajouterNutrition(menu u, char *fname);
void supprimer(menu u, char *fname);
void modifierNutrition(menu u, char *fname);
void afficher(GtkWidget *liste, char *fname);
char* meilleur_menu(char *fname);
int year_week(const struct tm *tmptr, int *year, int *week);

