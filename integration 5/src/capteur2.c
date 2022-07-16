#include "capteur2.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>


enum { 
	EREF,
	ETYPE,
	EVALEUR,
	EETAT,
	EETAGE,
	COLUMNS


};



void ajouter( CAPTEUR C)
{
    FILE *f;
    f=fopen("liste_capteur.txt","a+");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %d %d \n",C.ref, C.type, C.valeur, C.etat, C.etage);
        
    }
 fclose(f);
}

void ajouter_def( CAPTEUR C)
{
    FILE *f;
    f=fopen("liste_def.txt","a+");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %d %d \n",C.ref, C.type, C.valeur, C.etat, C.etage);
        
    }
 fclose(f);
}

void modifier(CAPTEUR C)
{
	//supprimer_capt(id);
	//ajouter(C);



FILE *f = NULL;
FILE *f2= NULL;
CAPTEUR	C1;

f=fopen("liste_capteur.txt","r");
f2=fopen("aux.txt","w");


while(fscanf(f,"%s %s %s %d %d  \n",C1.ref, C1.type, C1.valeur, &C1.etat, &C1.etage)!=EOF) 
    {
    if (strcmp(C.ref , C1.ref)!=0) {
	    //strcpy(C.valeur,valeur_new); 
            fprintf(f2,"%s %s %s %d %d \n",C1.ref, C1.type, C1.valeur, C1.etat, C1.etage);
        }
        else {
        fprintf(f2," %s %s %s %d %d  \n",C.ref, C.type, C.valeur, C.etat, C.etage);
        }
    }
    fclose(f);
    fclose(f2);
    remove("liste_capteur.txt");
    rename("aux.txt","liste_capteur.txt");
	
    }

void fichierRef() {
	CAPTEUR C;
	FILE*f=NULL;
	FILE*f1=NULL;
	CAPTEUR c;
	f=fopen("liste_capteur.txt","r");
	f1=fopen("reference.txt","w+");
	while (fscanf(f,"%s %s %s %d %d \n" ,C.ref, C.type, C.valeur, &C.etat, &C.etage)!=EOF)
	{

	fprintf(f1,"%s \n",C.ref);

	}

	fclose(f);
	fclose(f1);

}



void supprimer_capt( char id[20])
{
    CAPTEUR C;
    FILE *f=NULL;
    FILE *f2=NULL;
    FILE *f1=NULL;
    FILE *f3=NULL;
    f= fopen("liste_capteur.txt","r");
    f2 = fopen("aux.txt", "w");

	
    while(fscanf(f,"%s %s %s %d %d \n", C.ref, C.type, C.valeur, &C.etat, &C.etage)!=EOF)
	{
        
	if (strcmp(id , C.ref)!=0) {
           fprintf(f2,"%s %s %s %d %d \n",C.ref, C.type, C.valeur, C.etat, C.etage);
        }
    
    }
    fclose(f2);	
    fclose(f);
    
    remove("liste_capteur.txt");
    rename("aux.txt","liste_capteur.txt");

	f1= fopen("liste_def.txt","r");
    f3 = fopen("aux.txt", "w");

	
    while(fscanf(f1,"%s %s %s %d %d \n", C.ref, C.type, C.valeur, &C.etat, &C.etage)!=EOF)
	{
        
	if (strcmp(id , C.ref)!=0) {
           fprintf(f3,"%s %s %s %d %d \n",C.ref, C.type, C.valeur, C.etat, C.etage);
        }
    
    }
    fclose(f2);	
    fclose(f);
	
	remove("liste_def.txt");
    rename("aux.txt","liste_def.txt");

 
}



void consulter_capt(GtkWidget *liste, char fichier[20])
{

	
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char ref[20];
	char type[20];
	char valeur[20];
	int etat;
	int etage;
	store = gtk_tree_view_get_model(liste);
	store= NULL;
	    
	CAPTEUR C;
	FILE *f;

	if (store==NULL)
	{

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ref", renderer, "text", EREF, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type", renderer, "text", ETYPE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("valeur", renderer, "text", EVALEUR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("etat", renderer, "text", EETAT, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("etage", renderer, "text", EETAGE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);		
	}
	store = gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT);
    
   
    f=fopen(fichier,"r");	
if(f==NULL){return;}
	else
	{
	f=fopen(fichier,"a+");
    while (fscanf(f,"%s %s %s %d %d \n", C.ref, C.type, C.valeur, &C.etat, &C.etage)!=EOF){
    	//printf("%d %d %f %d %d \n", C.ref, C.type, C.valeur, C.etat, C.etage);
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, EREF, C.ref, ETYPE, C.type, EVALEUR, C.valeur, EETAT, C.etat, EETAGE, C.etage,-1);
        
    }
    fclose(f); 
    gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
    g_object_unref (store);   
    
}
}



void chercher_capt(char id[])
{ 
    CAPTEUR C; 
    
    FILE *f = NULL;
    FILE *f2=NULL;
    
    
    	
    f = fopen("liste_capteur.txt","r");
    f2 = fopen("recherche.txt", "a+");

    while (fscanf(f,"%s %s %s %d %d \n", C.ref, C.type, C.valeur, &C.etat, &C.etage)!=EOF) { 

        if(strcmp(C.ref,id) ==0){ 
            
        fprintf(f2,"%s %s %s %d %d\n",C.ref, C.type, C.valeur, C.etat, C.etage);
        }
    }
fclose(f);
fclose(f2);
}
 /* void capteur_def()
{
  /*  
    FILE *f=NULL;
    FILE *f1=NULL;
    f=fopen("temperature.txt","r");
    f1=fopen("capteur2.txt","w");
     while(fscanf(f,"%s %s %s %d %d \n" ,C.ref, C.type, C.valeur, &C.etat, &C.etage)!=EOF)
     {
        if (atoi(c.valeur)<10 || atoi(c.valeur)>30)
        fprintf(f1,"%s %s \n" ,"--",C.ref, "--" ,  C.valeur);
     }
     fclose(f);


CAPTEUR C; 
    
    FILE *f = NULL;
    FILE *f2=NULL;
    
    
    	
    f = fopen("temperature.txt","r");
    f2 = fopen("capteurs_def.txt", "w");

    while (fscanf(f,"%s %s  %s  \n", C.ref, C.type, C.valeur)!=EOF) { 

        if (atoi(C.valeur)<10 || atoi(C.valeur)>30){ 
            
        fprintf(f2,"%s %s %s %s  \n",C.ref, C.type, C.valeur, "--");
        }
    }

}
/*
void chang_background(GtkWidget *widget, int w, int h, const gchar *path) {

	gtk_widget_set_app_paintable(widget, TRUE);
	gtk_widget_realize(widget);
	
	gtk_widget_queue_draw(widget);
	GdkPixbuf *src_pixbuf = gtk_pixbuf_new_from_file(path,NULL);
	GdkPixbuf *dst_pixbuf = gtk_pixbuf_scale_simple(src_pixbuf, w, h, GDK_INTERP_BILINEAR);
	GdkPixmap *pixmap = NULL;
	
	g_object_unref(src_pixbuf);
	g_object_unref(dst_pixbuf);
	g_object_unref(pixmap);

}


*/
