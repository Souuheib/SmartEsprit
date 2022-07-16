#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reclamation.h"
enum{
	RCIN,
	RNOM,
	RPRENOM,
	RTEXT,
	RJOUR,
	RMOIS,
	RANNEE,
	RTYPE,
	RSEXE,
	COLUMNS
};
void ajouter_reclamation(reclamation r){
	FILE *f;
	f=fopen("reclamation.txt","a+");
	if(f!=NULL)
	{
		fprintf(f,"%s %s %s %s %d %d %d %d %d\n",r.cin,r.nom,r.prenom,r.text,r.d.jour,r.d.mois,r.d.annee,r.type,r.sexe);
	}
	fclose(f);
}
void modifier_reclamation(reclamation r){
	reclamation r1;
	FILE *f,*ftmp;
	f=fopen("reclamation.txt","r");
	ftmp=fopen("tmp.txt","a+");
	while(fscanf(f,"%s %s %s %s %d %d %d %d %d\n",r1.cin,r1.nom,r1.prenom,r1.text,&r1.d.jour,&r1.d.mois,&r1.d.annee,&r1.type,&r1.sexe)!=EOF){
		if(strcmp(r1.cin,r.cin)!=0){
			fprintf(ftmp,"%s %s %s %s %d %d %d %d %d\n",r1.cin,r1.nom,r1.prenom,r1.text,r1.d.jour,r1.d.mois,r1.d.annee,r1.type,r1.sexe);
		}
		else{
			fprintf(ftmp,"%s %s %s %s %d %d %d %d %d\n",r.cin,r.nom,r.prenom,r.text,r.d.jour,r.d.mois,r.d.annee,r.type,r.sexe);
		}
	}
	fclose(ftmp);
	fclose(f);
	remove("reclamation.txt");
	rename("tmp.txt","reclamation.txt");

}
void supprimer_reclamation(char cin[30]){
	reclamation r;
	FILE *f,*ftmp;
	f=fopen("reclamation.txt","r");
	ftmp=fopen("tmp.txt","a+");
	while(fscanf(f,"%s %s %s %s %d %d %d %d %d\n",r.cin,r.nom,r.prenom,r.text,&r.d.jour,&r.d.mois,&r.d.annee,&r.type,&r.sexe)!=EOF)
		{
			if(strcmp(r.cin,cin)!=0){
				fprintf(ftmp,"%s %s %s %s %d %d %d %d %d\n",r.cin,r.nom,r.prenom,r.text,r.d.jour,r.d.mois,r.d.annee,r.type,r.sexe);
			}
		}
	fclose(ftmp);
	fclose(f);
	remove("reclamation.txt");
	rename("tmp.txt","reclamation.txt");	

}
void chercher_reclamation(char cin[30]){
	reclamation r;
	FILE *f =NULL,*ftmp=NULL;
	f=fopen("reclamation.txt","r");
	ftmp=fopen("recherche.txt","a+");
	if(f!=NULL){
		while (fscanf(f,"%s %s %s %s %d %d %d %d %d\n",r.cin,r.nom,r.prenom,r.text,&r.d.jour,&r.d.mois,&r.d.annee,&r.type,&r.sexe)!=EOF){
			if(strcmp(r.cin,cin)==0){
				fprintf(ftmp,"%s %s %s %s %d %d %d %d %d\n",r.cin,r.nom,r.prenom,r.text,r.d.jour,r.d.mois,r.d.annee,r.type,r.sexe);
			}
		
		}

	}
	fclose(f);
	fclose(ftmp);

}
void afficher_reclamation(GtkWidget *liste,char file[20]){
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter ;
	GtkListStore *store;
	reclamation r;
	char ch[11],ch1[2],ch2[2],ch3[4];
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("CIN",renderer,"text",RCIN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",RNOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		 renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",RPRENOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 

		 renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("text",renderer,"text",RTEXT,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
 
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",RJOUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",RMOIS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",RANNEE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",RTYPE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",RSEXE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		 
	}
		  
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
	f=fopen(file,"r");
	if(f==NULL){return;}
	else
	{
		 while(fscanf(f,"%s %s %s %s %d %d %d %d %d\n",r.cin,r.nom,r.prenom,r.text,&r.d.jour,&r.d.mois,&r.d.annee,&r.type,&r.sexe)!=EOF)
		 {

			if(r.type==0 && r.sexe==0)
			{
			
			gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,RCIN,r.cin,RNOM,r.nom,RPRENOM,r.prenom,RTEXT,r.text,RJOUR,r.d.jour,RMOIS,r.d.mois,RANNEE,r.d.annee,RTYPE,"Hebergement",RSEXE,"Homme",-1);
			}
			else if(r.type==0 && r.sexe==1)
			{
			
			gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,RCIN,r.cin,RNOM,r.nom,RPRENOM,r.prenom,RTEXT,r.text,RJOUR,r.d.jour,RMOIS,r.d.mois,RANNEE,r.d.annee,RTYPE,"Hebergement",RSEXE,"Femme",-1);
			}
			else if(r.type==1 && r.sexe==1)
			{
			
			gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,RCIN,r.cin,RNOM,r.nom,RPRENOM,r.prenom,RTEXT,r.text,RJOUR,r.d.jour,RMOIS,r.d.mois,RANNEE,r.d.annee,RTYPE,"Restauration",RSEXE,"Femme",-1);
			}
			else
			{
			
			gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,RCIN,r.cin,RNOM,r.nom,RPRENOM,r.prenom,RTEXT,r.text,RJOUR,r.d.jour,RMOIS,r.d.mois,RANNEE,r.d.annee,RTYPE,"Restauration",RSEXE,"Homme",-1);
			}
			

			
		 }
	 fclose(f);
	 gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	 g_object_unref(store);
	}

}


int service_plus_reclamer(){
	int x=0,y=0;
	reclamation r;
	FILE *f;
	f=fopen("reclamation.txt","r");
	if(f!=NULL){
		while(fscanf(f,"%s %s %s %s %d %d %d %d %d\n",r.cin,r.nom,r.prenom,r.text,&r.d.jour,&r.d.mois,&r.d.annee,&r.type,&r.sexe)!=EOF)
		{
			if(r.type==0)
				x++;
			else
				y++;
		}
	}
	if(x>y)
		return 0;
	else 
		return 1;
}
