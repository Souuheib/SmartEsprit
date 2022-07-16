#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"
#include "callbacks.h"
#include <gtk/gtk.h>

enum
{
	ID,
	TYPE,
	NOM,
	DECHET,
	DATE,
	COLUMNS
};


/**Ajouter**/
void ajouterNutrition(menu u, char *fname){
GtkWidget *pQuestion, *pInfo;
FILE *f;
int b=0;
gpointer user_data;
menu p;
f=fopen(fname,"a+");
if(f!=NULL)
{	while(fscanf(f,"%s %d %s %f %d %d %d\n",p.id,&(p.type),p.nom,&(p.dechet),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{	
		if(strcmp(u.id,p.id)==0)
		b++;
	}
	if(b==0){
	fprintf(f,"%s %d %s %.2f %d %d %d\n",u.id,u.type,u.nom,u.dechet,u.d.j,u.d.m,u.d.a);
	pQuestion=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Menu ajouté avec succès !");
	switch(gtk_dialog_run(GTK_DIALOG(pQuestion)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pQuestion);
	break;
	}
	}
	if(b!=0){
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,"Menu déja existant !");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
	fclose(f);
}
}

/**Modifier**/
void modifierNutrition(menu u, char *fname){
menu p;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
f=fopen(fname,"r");
g=fopen("dump.txt","w");
if(f==NULL||g==NULL)
{
	return;
}
else{
	while(fscanf(f,"%s %d %s %f %d %d %d\n",p.id,&(p.type),p.nom,&(p.dechet),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{
		if(strcmp(p.id,u.id)!=0)
			fprintf(g,"%s %d %s %.2f %d %d %d\n",p.id,p.type,p.nom,p.dechet,p.d.j,p.d.m,p.d.a);
		else
			fprintf(g,"%s %d %s %.2f %d %d %d\n",p.id,u.type,u.nom,u.dechet,p.d.j,p.d.m,p.d.a);
	}
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Menu modifié avec succès !");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	fclose(f);
	fclose(g);
remove(fname);
rename("dump.txt",fname);
}
}

/**Afficher**/
void afficher(GtkWidget *liste, char *fname)
{
menu p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
gchar date_menu[50], dechet[10], type[20];
FILE *f;


store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" ID", renderer,"text",ID, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Type", renderer,"text",TYPE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Nom", renderer,"text",NOM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Déchets", renderer,"text",DECHET, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_resizable(column,TRUE);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Date", renderer,"text",DATE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);




store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen(fname,"r");
if(f!=NULL)

{ f = fopen(fname,"a+");
		while(fscanf(f,"%s %d %s %f %d %d %d\n",p.id,&(p.type),p.nom,&(p.dechet),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{
sprintf(type,p.type==0?"Petit déjeuner":p.type==1?"Déjeuner":"Diner");
sprintf(dechet,"%.2f",p.dechet);
sprintf(date_menu,"%d/%d/%d",p.d.j,p.d.m,p.d.a);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,p.id,TYPE,type,NOM,p.nom,DECHET,dechet,DATE,date_menu,-1);
	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
}

/**Supprimer**/
void supprimer(menu u, char *fname)
{
menu p;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
f=fopen(fname,"r");
g=fopen("dump.txt","w");
if(f!=NULL&&g!=NULL){
	while(fscanf(f,"%s %d %s %f %d %d %d\n",p.id,&(p.type),p.nom,&(p.dechet),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{
		if(strcmp(p.id,u.id)!=0)
			fprintf(g,"%s %d %s %.2f %d %d %d\n",p.id,p.type,p.nom,p.dechet,p.d.j,p.d.m,p.d.a);
	}
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Menu supprimé avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	fclose(f);
	fclose(g);
remove(fname);
rename("dump.txt",fname);
}
}

/**Meilleur Menu**/
char* meilleur_menu(char *fname){
int err, err1, y=0, y1=0, w=0, w1=0;
struct tm tm = { 0 };
menu p;
char* ch = (char*) malloc(1000);
time_t t;
time(&t);
err = year_week(localtime(&t),&y,&w);
char gl[50], gll[50];
float gd, gdd, min=99999999.00;
FILE *f, *g;
f=fopen(fname,"a+");
g=fopen("tmp.txt","w+");
if(g!=NULL){
if(f!=NULL)
{	while(fscanf(f,"%s %d %s %f %d %d %d\n",p.id,&(p.type),p.nom,&(p.dechet),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF){
	tm.tm_year = p.d.a - 1900;
	tm.tm_mon = p.d.m - 1;
	tm.tm_mday = p.d.j;
	tm.tm_isdst = -1;
	err1 = year_week(&tm,&y1,&w1);
	if(w==w1){
        fprintf(g,"%s %.2f\n",p.nom,p.dechet);// %s, p.type
	}
}
fclose(f);
}
fclose(g);
}
g=fopen("tmp.txt","r");
if(g!=NULL){
	while(fscanf(g,"%s %f\n",gl,&gd)!=EOF){
    if(gd<min)
        min=gd;
}
fclose(g);
}
g=fopen("tmp.txt","r");
if(g!=NULL){
	while(fscanf(g,"%s %f\n",gll,&gdd)!=EOF){
    if(gdd==min)
        break;
}
fclose(g);
}
sprintf(ch,"Meilleur menu de la semaine : %s",gll);
remove("tmp.txt");
return ch;
}

/**Calendrier**/
int year_week(const struct tm *tmptr, int *year, int *week) {
  // work with local copy
  struct tm tm = *tmptr;
  // fully populate the yday and wday fields.
  if (mktime(&tm) == -1) {
    return 1;
  }

  // Find day-of-the-week: 0 to 6.
  // Week starts on Monday per ISO 8601
  // 0 <= DayOfTheWeek <= 6, Monday, Tuesday ... Sunday
  int DayOfTheWeek = (tm.tm_wday + (7 - 1)) % 7;

  // Offset the month day to the Monday of the week.
  tm.tm_mday -= DayOfTheWeek;
  // Offset the month day to the mid-week (Thursday) of the week, 3 days later.
  tm.tm_mday += 3;
  // Re-evaluate tm_year and tm_yday  (local time)
  if (mktime(&tm) == -1) {
    return 1;
  }

  *year = tm.tm_year + 1900;
  // Convert yday to week of the year, stating with 1.
  *week = tm.tm_yday / 7 + 1;
  return 0;
}
