#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"fonction.h"
#include <gtk/gtk.h>

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

void ajouterstock (char id[],char type[],int quant)
{
char id1[50];
char type1[50];
int quant1;
int v=0;
char empty[50]="\0" ;
FILE *f;
f=fopen("prod.txt","a+");
if(f!=NULL)

{while(fscanf(f,"%s %s %d \n",id1,type1,&quant1)!=EOF)
          {
               if (strcmp(id,id1)==0) 
                   {
                       v=1 ;
                   }  
               if ( (strcmp(id,empty)==0) || (strcmp(type,empty)==0)) 
                   {
                      v=1 ;
                   }
          }
if(v==0)
{fprintf(f,"%s %s %d \n",id,type,quant);
fclose(f);}
}
}


void supprimerstock(char id1[])

{
FILE *f;
FILE *f1;

int r;


char id[50]; 
int quant;
char type[50]; 



f=fopen("prod.txt","r");
f1=fopen("prod1.txt","w");
if (f!=NULL){
    if(f1!=NULL){
while(fscanf(f,"%s %s %d \n",id,type,&quant)!=EOF ) {
    if(strcmp(id1,id)!=0)  
    {
        fprintf(f1,"%s %s %d \n",id,type,quant);
        r=1;
    }
}
    }
    fclose(f1);
}

fclose(f);
if (r){
	remove ("prod.txt");
	rename ("prod1.txt","prod.txt");
	}

}




void modifierstock(char id1[],int quant1)
{
FILE *f;
FILE *f1;
 
int r;
char id[50]; 
int quant;
char type[50]; 


f=fopen("prod.txt","r");
f1=fopen("prod1.txt","w");
if (f!=NULL)
{
    if(f1!=NULL)
     {
while(fscanf(f,"%s %s %d \n",id,type,&quant)!=EOF  ) 
{
    if(strcmp(id1,id)==0)  
            {
        fprintf(f1,"%s %s %d \n",id,type,quant1);
            }
     else 
          {fprintf(f1,"%s %s %d \n",id,type,quant);} 
}
}
}
fclose(f1);
fclose(f);

	remove ("prod.txt");
	rename ("prod1.txt","prod.txt");
	
}

void alerte ()
{char id[50];
char type[50];
int quant;
FILE *f;
FILE *f1;
f=fopen("prod.txt","r");
f1=fopen("alerte.txt","w");
if(f!=NULL)
{if(f1!=NULL)
{while(fscanf(f,"%s %s %d \n",id,type,&quant)!=EOF) 
{
    if(quant<3)
            {
        fprintf(f1,"%s %s %d \n",id,type,quant);
            }

}
fclose(f1);
fclose(f);
}
}
}




enum 
{
ID ,
TYPE,
QUANT, 
COLUMNS1
}; 


void afficherstock (GtkTreeView *liste)
{
GtkCellRenderer *render ;
GtkTreeViewColumn *column ; 
GtkTreeIter iter ; 

GtkListStore *store ;

char id[50]; 
int quant;
char type[50]; 
store=NULL ; 
FILE* f ; 

store=gtk_tree_view_get_model(liste) ; 
if (store==NULL) 
{
render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("id",render,"text",ID,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("type",render,"text",TYPE,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("quant",render,"text",QUANT,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 



store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT) ; 

f=fopen("prod.txt","r") ; 
if (f==NULL) 
{
return ; 
}
else 
{
f=fopen("prod.txt","a+") ;
 while(fscanf(f,"%s %s %d \n",id,type,&quant)!=EOF) 
{
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,ID,id,TYPE,type,QUANT,quant,-1) ; 
}
fclose(f) ; }
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)); 
g_object_unref (store) ; 

}
}



enum 
{
ID2 ,
TYPE2,
QUANT2, 
COLUMNS2
}; 


void afficheralerte (GtkTreeView *liste)
{
GtkCellRenderer *render ;
GtkTreeViewColumn *column ; 
GtkTreeIter iter ; 

GtkListStore *store ;

char id[50]; 
int quant;
char type[50]; 
store=NULL ; 
FILE* f ; 

store=gtk_tree_view_get_model(liste) ; 
if (store==NULL) 
{
render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("id",render,"text",ID2,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("type",render,"text",TYPE2,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("quant",render,"text",QUANT2,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 



store=gtk_list_store_new(COLUMNS2,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT) ; 

f=fopen("alerte.txt","r") ; 
if (f==NULL) 
{
return ; 
}
else 
{
f=fopen("alerte.txt","a+") ;
 while(fscanf(f,"%s %s %d \n",id,type,&quant)!=EOF) 
{
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,ID2,id,TYPE2,type,QUANT2,quant,-1) ; 
}
fclose(f) ; }
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)); 
g_object_unref (store) ; 

}
}


