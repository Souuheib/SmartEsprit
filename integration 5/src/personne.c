#ifdef HAVE_CONFIG_H
# include<config.h>
#endif
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "personne.h"
#include<gtk/gtk.h>
enum{
	EID,
	ENOM,
	EPRENOM,
	ECHAMBRE,
	EFOYER,
	EGENRE,
	ETYPE_CHAMBRE,
	ENIVEAU,
	COLUMNS,

};


///////////////////////////////////////
void ajouter_etudiant(etudiantHB HB)
{
FILE *f;
f=fopen("users.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s %s %s \n",HB.ID,HB.nom_hebergent,HB.prenom_hebergent,HB.chambre_etudiant,HB.bloc_foyer,HB.genre,HB.type_chambre,HB.Niveau);
}
fclose(f);
}
///////////////////////////////////////
void afficher_etudiant(GtkWidget *liste,char file[300])
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	etudiantHB HB;

	char ID[30];
	char nom_hebergent[30];
	char prenom_hebergent[30];
	char chambre_etudiant[30];
	char bloc_foyer[30];
	char genre[30];
	char type_chambre[30];
	char Niveau[30];
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("ID",renderer,"text",EID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Nom hebergent",renderer,"text",ENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Prenom hebergent",renderer,"text",EPRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Chambre etudiant",renderer,"text",ECHAMBRE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Bloc foyer",renderer,"text",EFOYER,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Genre",renderer,"text",EGENRE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Type chambre",renderer,"text",ETYPE_CHAMBRE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Niveau",renderer,"text",ENIVEAU,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING);
	f=fopen(file,"r");
	if(f==NULL)
	{	
		return;
	}
	else
	
	{	f=fopen(file,"a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s \n",HB.ID,HB.nom_hebergent,HB.prenom_hebergent,HB.chambre_etudiant,HB.bloc_foyer,HB.genre,HB.type_chambre,HB.Niveau)!=EOF)
	{
			gtk_list_store_append(store,&iter);
							 gtk_list_store_set(store,&iter,EID,HB.ID,ENOM,HB.nom_hebergent,EPRENOM,HB.prenom_hebergent,ECHAMBRE,HB.chambre_etudiant,EFOYER,HB.bloc_foyer,EGENRE,HB.genre,ETYPE_CHAMBRE,HB.type_chambre,ENIVEAU,HB.Niveau, -1);
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
	}
			
  }
///////////////////////////////////////
void supprimer_etudiant(char ID[30])
{

etudiantHB HB1;
FILE *f,*g;
	f=fopen("users.txt","r");
	g=fopen("users2.txt","w");
	
	if(f==NULL || g==NULL)
		return;
	else
	{
		while(fscanf(f,"%s %s %s %s %s %s %s %s \n",HB1.ID,HB1.nom_hebergent,HB1.prenom_hebergent,HB1.chambre_etudiant,HB1.bloc_foyer,HB1.genre,HB1.type_chambre,HB1.Niveau)!=EOF)
		{
			if(strcmp(HB1.ID,ID)!=0 )
			fprintf(g,"%s %s %s %s %s %s %s %s \n",HB1.ID,HB1.nom_hebergent,HB1.prenom_hebergent,HB1.chambre_etudiant,HB1.bloc_foyer,HB1.genre,HB1.type_chambre,HB1.Niveau);
		}
		fclose(f);
		fclose(g);
remove("users.txt");
rename("users2.txt","users.txt");
}
}
//////////////////////////////////////////////
void modifier_etudiant(etudiantHB HB)
{
FILE *f1,*f2;
etudiantHB HB1;
f1=fopen("users.txt","r");
f2=fopen("users2.txt","w+");
while(fscanf(f1,"%s %s %s %s %s %s %s %s \n",HB1.ID,HB1.nom_hebergent,HB1.prenom_hebergent,HB1.chambre_etudiant,HB1.bloc_foyer,HB1.genre,HB1.type_chambre,HB1.Niveau)!=EOF)
{
if((strcmp(HB1.ID,HB.ID)!=0))
{
fprintf(f2,"%s %s %s %s %s %s %s %s \n",HB1.ID,HB1.nom_hebergent,HB1.prenom_hebergent,HB1.chambre_etudiant,HB1.bloc_foyer,HB1.genre,HB1.type_chambre,HB1.Niveau);
}
else
{
fprintf(f2,"%s %s %s %s %s %s %s %s \n",HB.ID,HB.nom_hebergent,HB.prenom_hebergent,HB.chambre_etudiant,HB.bloc_foyer,HB.genre,HB.type_chambre,HB.Niveau);
}
}
fclose(f1);
fclose(f2);
remove("users.txt");
rename("users2.txt","users.txt");
}

////////////////////////////////////////////////

void chercher_etudiant(char iD[30]){
	etudiantHB HB;
	FILE *f =NULL,*g=NULL;
	f=fopen("users.txt","r");
	g=fopen("recherche.txt","a+");
	if(f!=NULL){
		while (fscanf(f,"%s %s %s %s %s %s %s %s \n",HB.ID,HB.nom_hebergent,HB.prenom_hebergent,HB.chambre_etudiant,HB.bloc_foyer,HB.genre,HB.type_chambre,HB.Niveau)!=EOF){
			if(strcmp(HB.ID,iD)==0){
				fprintf(g,"%s %s %s %s %s %s %s %s \n",HB.ID,HB.nom_hebergent,HB.prenom_hebergent,HB.chambre_etudiant,HB.bloc_foyer,HB.genre,HB.type_chambre,HB.Niveau);
			}
		
		}

	}
	fclose(f);
	fclose(g);

}
/////////////////////////////////////////////////////

int stats_etudiant(int Calculer[],char file[])
{
FILE *f1=NULL;
etudiantHB HB;
f1=fopen("users.txt","r");
int n;
int n1=0,n2=0,n3=0,n4=0,n5=0,nfinal=0;
if(f1!=NULL)
  {while(fscanf(f1,"%s %s %s %s %s %s %s %s \n",HB.nom_hebergent,HB.prenom_hebergent,HB.chambre_etudiant,HB.bloc_foyer,HB.genre,HB.type_chambre,HB.ID,HB.Niveau)!=EOF)
{
	
				if((Calculer[0]==1) &&(strcmp(HB.Niveau,"1")==0))

                                 {
                                  n1++;

                                 }

  				if((Calculer[1]==1)&&(strcmp(HB.Niveau,"2")==0))
                                {
                                 n2++;

                                }

 				if((Calculer[2]==1)&&(strcmp(HB.Niveau,"3")==0))
                                {
              			 n3++;

            			}

 				if((Calculer[3]==1)&&(strcmp(HB.Niveau,"4")==0))
            			{
              			n4++;

            			}

 				if((Calculer[4]==1)&&(strcmp(HB.Niveau,"5")==0))
            			{
              			n5++;

            			}
       
       
    		}
nfinal=n1+n2+n3+n4+n5;
}
fclose(f1);
return nfinal;
}

