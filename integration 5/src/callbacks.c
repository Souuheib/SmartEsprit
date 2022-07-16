#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "capteur2.h"
#include "reclamation.h"
#include "callbacks.h"
#include "interface.h"
#include "verifier.h"
#include "support.h"
#include <string.h>


int a=0;

CAPTEUR C;
/*
void
on_boutton_ajouter_menu_clicked        (GtkWidget      *button,
                                        gpointer         user_data)
{	GtkWidget *window_ajouter, *menu;

	menu = lookup_widget(button,"gestion_des_capteurs");
	gtk_widget_hide(menu);
	//menu = create_gestion_des_capteurs();
	//gtk_widget_hide(menu);

	//window_ajouter=lookup_widget(button,"window_ajouter");
	window_ajouter = create_window_ajouter();
	//gtk_widget_hide(window_ajouter);
	//gtk_widget_destroy(window_ajouter);
	gtk_widget_show(window_ajouter);

	GtkWidget *window_consulter, *treeview;
	window_consulter = create_window_consulter();
	
	//gtk_widget_hide(treeview);
	gtk_widget_show(window_consulter);
	treeview = lookup_widget(window_consulter, "treeview1");
	consulter_capt(treeview,"liste_capteur.txt");  

	

}   */

void
on_button_valider_modifier_clicked     (GtkWidget       *button,
                                        gpointer         user_data)
{

	CAPTEUR C;
	FILE *f= NULL;
	GtkWidget *reference, *type ,*valeur, *etage, *etat;
	
	GtkWidget *window_consulter, *treeview;
	int n;
	//char id[20], val[20];

	//reference = lookup_widget(button, "entry_ref_ajouter");
	//type = lookup_widget(button, "combobox_entry_ajouter");
	//valeur = lookup_widget(button, "entry_valeur_ajouter");
	//etage = lookup_widget(button, "spinbutton_etage_ajouter");
	//etat = lookup_widget(button, "spinbutton_etat_ajouter");
	

	reference = lookup_widget(button, "comboboxentry_modifier_generer");
	type = lookup_widget(button, "combobox_entry_ajouter");
	valeur = lookup_widget(button, "entry_valeur_ajouter");
	etage = lookup_widget(button, "spinbutton_etage_ajouter");
	etat = lookup_widget(button, "spinbutton_etat_ajouter");
	
	strcpy(C.ref, gtk_combo_box_get_active_text(GTK_COMBO_BOX(reference)));
	strcpy(C.type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
	strcpy(C.valeur, gtk_entry_get_text(GTK_ENTRY(valeur)));
	C.etage = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (etage));
	C.etat = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (etat));
	
	modifier(C);
	//affichage des windows	
	/*
	window_consulter = create_window_consulter();
	
	//gtk_widget_hide(treeview);
	gtk_widget_show(window_consulter);
	treeview = lookup_widget(window_consulter, "treeview1");
	consulter_capt(treeview,"liste_capteur.txt"); 
*/
}




void
on_button_valider_ajouter_clicked(GtkWidget *button, gpointer user_data)
{
	CAPTEUR C;
	FILE *f= NULL;
	GtkWidget *reference;
	GtkWidget *type, *valeur, *etage , *etat;

	

	reference = lookup_widget(button, "entry_ref_ajouter");
	type = lookup_widget(button, "combobox_entry_ajouter");
	valeur = lookup_widget(button, "entry_valeur_ajouter");
	etage = lookup_widget(button, "spinbutton_etage_ajouter");
	etat = lookup_widget(button, "spinbutton_etat_ajouter");
	
	strcpy(C.ref, gtk_entry_get_text(GTK_ENTRY(reference)));
	strcpy(C.type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
	strcpy(C.valeur, gtk_entry_get_text(GTK_ENTRY(valeur)));
	C.etage = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (etage));
	C.etat = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (etat));
	
	if (atoi(C.valeur)>10 && atoi(C.valeur)<30){
	ajouter(C);
	ajouter_def(C);}
	else
	ajouter(C);	
	
	// afficher apres ajout
	GtkWidget *window_consulter, *treeview ,*window_ajouter;
	window_ajouter=lookup_widget(button,"window_ajouter");
	gtk_widget_destroy(window_ajouter);
	window_consulter = create_window_consulter();
	
	//gtk_widget_hide(treeview);
	gtk_widget_show(window_consulter);
	treeview = lookup_widget(window_consulter, "treeview1");
	consulter_capt(treeview,"liste_capteur.txt");  

	
}



/*

void
on_button_consulter_clicked            (GtkWidget       *button,
					
                                        gpointer         user_data)
{
	GtkWidget *window_consulter, *treeview, *menu;
	window_consulter = create_window_consulter();
	window_consulter = lookup_widget(window_consulter, "window_consulter");
	//gtk_widget_hide(treeview);
	gtk_widget_show(window_consulter);
	treeview = lookup_widget(window_consulter, "treeview1");
	consulter_capt(treeview,"liste_capteur.txt");  


	menu = lookup_widget(button,"gestion_des_capteurs");
	gtk_widget_hide(menu);
}





*/


void
on_treeview1_row_activated             (GtkTreeView    *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar *ref;
	gchar *type;
	gchar *valeur;
	gint *etat;
	gint *etage;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path)){
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&ref,1,&type,2,&valeur,3,&etat,4,&etage,-1);
		
	strcpy(C.ref,ref);
	strcpy(C.type,type);
	strcpy(C.valeur,valeur);
	etage=C.etage;
	etat=C.etat;
		supprimer_capt(ref);
		consulter_capt(treeview,"liste_capteur.txt");

	}	


}





/*
void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	{a=1;}

}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	a=2;
}   
*/

void
on_button_recherche_clicked            (GtkWidget      *button,
                                        gpointer         user_data)
{
	GtkWidget *ref;
	char id[20];
	ref=lookup_widget (button,"entry_ref_recherche");
	strcpy(id, gtk_entry_get_text(GTK_ENTRY(ref)));
	GtkWidget *windowafficher;
	GtkWidget *treeview;
	windowafficher=lookup_widget(button,"window_consulter");	
	treeview=lookup_widget(windowafficher,"treeview1");
	if(strcmp(id,"")!=0)
	{
		
		chercher_capt( id);
		
		consulter_capt(treeview,"recherche.txt" );
		remove("recherche.txt");
	}
	else
		consulter_capt(treeview,"liste_capteur.txt" );



}


void
on_button_acceuil_ajouter_clicked      (GtkWidget       *button,
                                        gpointer         user_data)
{

	GtkWidget *menu, *window_ajouter;
	
	menu = lookup_widget(button,"gestion_des_capteurs");
	window_ajouter=lookup_widget(button,"window_ajouter");
	
	gtk_widget_destroy(window_ajouter);
	menu = create_gestion_des_capteurs();
	gtk_widget_show(menu);

}


void
on_button_acceuil_consulter_clicked    (GtkWidget      *button,
                                        gpointer         user_data)
{

	GtkWidget *menu, *window_consulter;
	
	menu = lookup_widget(button,"gestion_des_capteurs");
	window_consulter=lookup_widget(button,"window_consulter");
	
	gtk_widget_destroy(window_consulter);
	menu = create_gestion_des_capteurs();
	gtk_widget_show(menu);


}






void
on_button_actualiser_consulter_clicked (GtkWidget       *button,
                                        gpointer         user_data)
{/*
	GtkWidget *window_consulter, *treeview;
	window_consulter = create_window_consulter();
	window_consulter = lookup_widget(window_consulter, "window_consulter");
	gtk_widget_destroy(window_consulter);
	
	gtk_widget_show(window_consulter);
	treeview = lookup_widget(window_consulter, "treeview1");
	consulter_capt(treeview,"liste_capteur.txt");

*/
}





void
on_button_generer_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

	GtkWidget *combo,*btn;
	combo=lookup_widget(button,"comboboxentry_modifier_generer");
	btn=lookup_widget(button,"generer");
	gtk_widget_set_sensitive ( btn, FALSE);//disable button
	fichierRef();

	char id[30];

	FILE *f=NULL;
	f = fopen("reference.txt","r");
	if(f!=NULL)
	{
 	 while (fscanf(f,"%s \n " ,id)!=EOF)
	gtk_combo_box_append_text (GTK_COMBO_BOX(combo),(id));
	}
fclose(f);
remove("reference.txt");


}


void
on_button_capteur_def_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

	
	GtkWidget *windowafficher;
	GtkWidget *treeview;
	windowafficher=lookup_widget(button,"window_consulter");	
	treeview=lookup_widget(windowafficher,"treeview1");
		
		consulter_capt(treeview,"liste_def.txt" );
		//remove("capteurs_def.txt");
	

}


void
on_button_consulter_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{

	GtkWidget *window_consulter, *treeview, *menu;
	window_consulter = create_window_consulter();
	window_consulter = lookup_widget(window_consulter, "window_consulter");
	//gtk_widget_hide(treeview);
	gtk_widget_show(window_consulter);
	treeview = lookup_widget(window_consulter, "treeview1");
	consulter_capt(treeview,"liste_capteur.txt");  


	menu = lookup_widget(button,"gestion_des_capteurs");
	gtk_widget_hide(menu);

}


void
on_boutton_ajouter_menu_clicked        (GtkWidget       *button,
                                        gpointer         user_data)
{

	GtkWidget *window_ajouter, *menu;

	menu = lookup_widget(button,"gestion_des_capteurs");
	gtk_widget_destroy(menu);
	//menu = create_gestion_des_capteurs();
	//gtk_widget_hide(menu);

	//window_ajouter=lookup_widget(button,"window_ajouter");
	window_ajouter = create_window_ajouter();
	//gtk_widget_hide(window_ajouter);
	//gtk_widget_destroy(window_ajouter);
	gtk_widget_show(window_ajouter);


}
/////////////////////////////////////////////////////////////////////////////////////////////////////
///callbacks HB


#include "personne.h"

void
on_ajouter_clicked


							(GtkWidget *objet,

							 gpointer user_data)
{

etudiantHB HB;

GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8 , *input9 , *pInfo1;

input1=lookup_widget(objet, "ID");

input2=lookup_widget (objet, "nom");

input3=lookup_widget (objet, "prenom");

input4=lookup_widget(objet, "nombre_chambre");

input5=lookup_widget(objet, "bloc_foyer");

input6=lookup_widget(objet, "radiobutton_homme");

input7=lookup_widget(objet, "radiobutton_femme");

input8=lookup_widget(objet, "combobox1");

input9=lookup_widget(objet, "Niveau");


strcpy(HB.ID,gtk_entry_get_text (GTK_ENTRY(input1)));
strcpy(HB.nom_hebergent,gtk_entry_get_text (GTK_ENTRY (input2)));
strcpy(HB.prenom_hebergent,gtk_entry_get_text (GTK_ENTRY(input3)));
strcpy(HB.chambre_etudiant,gtk_entry_get_text (GTK_ENTRY(input4)));
strcpy(HB.bloc_foyer,gtk_entry_get_text (GTK_ENTRY(input5)));
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input6)))
	{
		strcpy(HB.genre,"Homme");
	}
	else
	{
		strcpy(HB.genre,"Femme");
	}
strcpy(HB.type_chambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input8)));
strcpy(HB.Niveau,gtk_entry_get_text (GTK_ENTRY(input9)));

ajouter_etudiant(HB);
pInfo1=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"étudiant ajouté avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo1)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo1);
	break;
	}
}
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
void
on_afficher_clicked


							(GtkWidget *objet,

							 gpointer user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview2;

fenetre_ajout=lookup_widget(objet,"fenetre_ajout");

gtk_widget_destroy(fenetre_ajout);
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();

gtk_widget_show(fenetre_afficher);
treeview2=lookup_widget (fenetre_afficher,"treeview2");
afficher_etudiant(treeview2,"users.txt");
}

///////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////



void
on_retour_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *service_main, *fenetre_afficher;

fenetre_afficher=lookup_widget(objet,"fenetre_afficher");

gtk_widget_destroy(fenetre_afficher);
service_main=create_service_main();
gtk_widget_show(service_main);
}

void
on_radiobutton_homme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_retour1_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout, *service_main;

fenetre_ajout=lookup_widget(objet,"fenetre_ajout");

gtk_widget_destroy(fenetre_ajout);
service_main=create_service_main();
gtk_widget_show(service_main);
}

void
on_ajouterMain_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout, *service_main;

service_main=lookup_widget(objet,"service_main");

gtk_widget_destroy(service_main);
fenetre_ajout=create_fenetre_ajout();
gtk_widget_show(fenetre_ajout);
}


void
on_afficherMain_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher, *service_main;
GtkWidget *treeview2;

service_main=lookup_widget(objet,"service_main");

gtk_widget_destroy(service_main);
fenetre_afficher=create_fenetre_afficher();
gtk_widget_show(fenetre_afficher);
treeview2=lookup_widget (fenetre_afficher,"treeview2");
afficher_etudiant(treeview2,"users.txt");
}


void
on_modifierMain_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier, *service_main;

service_main=lookup_widget(objet,"service_main");

gtk_widget_destroy(service_main);
fenetre_modifier=create_fenetre_modifier();
gtk_widget_show(fenetre_modifier);
}

Calculer[5]={0,0,0,0,0};
char ch[60];
void
on_Confirmer_niveau_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *output;
	output=lookup_widget(objet,"output");
	int somme;
	somme=stats_etudiant(Calculer,"users.txt");
	sprintf(ch,"%d",somme);
	gtk_label_set_text(GTK_LABEL(output),ch);
}

void
on_Niveau1_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{Calculer[0]=1;
}
else
{Calculer[0]=0;}
}


void
on_Niveau2_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{Calculer[1]=1;
}
else
{Calculer[1]=0;}
}


void
on_Niveau3_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{Calculer[2]=1;
}
else
{Calculer[2]=0;}
}


void
on_Niveau4_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{Calculer[3]=1;
}
else
{Calculer[3]=0;}
}


void
on_Niveau5_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{Calculer[4]=1;
}
else
{Calculer[4]=0;}
}

void
on_statsMain_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_stats, *service_main;

service_main=lookup_widget(objet,"service_main");

gtk_widget_destroy(service_main);
fenetre_stats=create_fenetre_stats();
gtk_widget_show(fenetre_stats);
}


void
on_AfficherModif_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier, *fenetre_afficher,*treeview2;

fenetre_modifier=lookup_widget(objet,"fenetre_modifier");

gtk_widget_destroy(fenetre_modifier);
fenetre_afficher=create_fenetre_afficher();
gtk_widget_show(fenetre_afficher);
treeview2=lookup_widget (fenetre_afficher,"treeview2");
afficher_etudiant(treeview2,"users.txt");
}


void
on_modifier_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8 , *input9;
etudiantHB HB,HB1;
input1=lookup_widget(objet, "modif_ID");

input2=lookup_widget (objet, "modif_nom");

input3=lookup_widget (objet, "modif_prenom");

input4=lookup_widget(objet, "modif_nombre");

input5=lookup_widget(objet, "modif_bloc");

input6=lookup_widget(objet, "modif_radiobutton_homme");

input7=lookup_widget(objet, "modif_radiobutton_femme");

input8=lookup_widget(objet, "combobox2");

input9=lookup_widget(objet, "modif_Niveau");


strcpy(HB.ID,gtk_entry_get_text (GTK_ENTRY(input1)));
strcpy(HB.nom_hebergent,gtk_entry_get_text (GTK_ENTRY (input2)));
strcpy(HB.prenom_hebergent,gtk_entry_get_text (GTK_ENTRY(input3)));
strcpy(HB.chambre_etudiant,gtk_entry_get_text (GTK_ENTRY(input4)));
strcpy(HB.bloc_foyer,gtk_entry_get_text (GTK_ENTRY(input5)));
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input6)))
	{
		strcpy(HB.genre,"Homme");
	}
	else
	{
		strcpy(HB.genre,"Femme");
	}
strcpy(HB.type_chambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input8)));
strcpy(HB.Niveau,gtk_entry_get_text (GTK_ENTRY(input9)));
modifier_etudiant(HB);
}


void
on_Supprimer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
char id[30];
GtkWidget *supprimer,*treeview2,*fenetre_afficher,*pInfo2;
supprimer=lookup_widget(objet,"entry_supprimer");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(supprimer)));
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
treeview2=lookup_widget(fenetre_afficher,"treeview2");



pInfo2=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nsupprimer cet étudiant ?");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo2)))
	{
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(pInfo2);
	supprimer_etudiant(id);
	afficher_etudiant(treeview2,"users.txt");
	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pInfo2);
	break;
}	
}


void
on_actualiser_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview2,*fenetre_afficher;
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
treeview2=lookup_widget(fenetre_afficher,"treeview2");
afficher_etudiant(treeview2,"users.txt");
}

void
on_retourstats_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_stats, *service_main;

fenetre_stats=lookup_widget(objet,"fenetre_stats");

gtk_widget_destroy(fenetre_stats);
service_main=create_service_main();
gtk_widget_show(service_main);
}

void
on_rechercherHB_clicked                (GtkWidget       *objet,
                                       gpointer         user_data)
{
GtkWidget *ID,*treeview2,*fenetre_afficher;
	char iD[30];
	etudiantHB HB;
	fenetre_afficher=lookup_widget(objet,"fenetre_afficher");	
	ID=lookup_widget (objet,"ID_recherche");
	strcpy(iD, gtk_entry_get_text(GTK_ENTRY(ID)));	
	treeview2=lookup_widget(fenetre_afficher,"treeview2");
		chercher_etudiant(iD);
		afficher_etudiant(treeview2,"recherche.txt");
		remove("recherche.txt");
		
}



void
on_retourModifierHB_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier, *service_main;

fenetre_modifier=lookup_widget(objet,"fenetre_modifier");

gtk_widget_destroy(fenetre_modifier);
service_main=create_service_main();
gtk_widget_show(service_main);
}



void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	
etudiantHB HB;
GtkTreeIter iter;
gchar* ID;
gchar* nom;
gchar* prenom;
gchar* nombre_chambre;
gchar* bloc_foyer;
gchar* genre;
gchar* type_chambre;
gchar* Niveau;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter , path)) {
 //obtention des valeurs de la ligne selectionnée

	gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &ID, 1,&nom,2,&prenom,3,&nombre_chambre,4,&bloc_foyer,5,&genre,6,&type_chambre,7,&Niveau, -1);
//copie des valeurs dans la variable HB de type etudiantHB pour le passer à la fonction de suppression

strcpy(HB.ID,ID);
strcpy(HB.nom_hebergent, nom);
strcpy(HB.prenom_hebergent, prenom);
strcpy(HB.chambre_etudiant,nombre_chambre);
strcpy(HB.bloc_foyer,bloc_foyer);
strcpy(HB.genre,genre);
strcpy(HB.type_chambre,type_chambre);
strcpy(HB.Niveau,Niveau);
//appel de la fonction de suppression
supprimer_etudiant(HB.ID);
// mise à jour de l'affichage de la treeview
afficher_etudiant(treeview,"users.txt");
}

}


void
on_MAIN_ADMIN_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_MAIN_HB_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *service_main,*MENU_PRINCIPAL;
MENU_PRINCIPAL=lookup_widget(objet,"MENU_PRINCIPAL");

gtk_widget_destroy(MENU_PRINCIPAL);
service_main=create_service_main();
gtk_widget_show(service_main);
}


void
on_MAIN_CAPTEUR_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_des_capteurs,*MENU_PRINCIPAL;
MENU_PRINCIPAL=lookup_widget(objet,"MENU_PRINCIPAL");

gtk_widget_destroy(MENU_PRINCIPAL);
gestion_des_capteurs=create_gestion_des_capteurs();
gtk_widget_show(gestion_des_capteurs);
}


void
on_MAIN_NUTRITION_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *af,*MENU_PRINCIPAL,*treeview;
MENU_PRINCIPAL=lookup_widget(objet,"MENU_PRINCIPAL");

gtk_widget_destroy(MENU_PRINCIPAL);
af=create_af();
gtk_widget_show(af);
treeview=lookup_widget(af,"treeview");
afficher(treeview,"menu.txt");
}


void
on_radiobutton_femme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


///////////////////////////////////////////////////////////////////////////////:
//Calbacks Rec


int x=0,z=0;
void
on_buttonlist_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *windowajouter,*windowafficher,*treeview;
	windowajouter=lookup_widget(objet_graphique,"windowajouter");
	gtk_widget_destroy(windowajouter);
	windowafficher=lookup_widget(objet_graphique,"windowafficher");
	windowafficher=create_windowafficher();
	gtk_widget_show(windowafficher);
	treeview=lookup_widget(windowafficher,"treeviewreclamation");
	afficher_reclamation(treeview,"reclamation.txt");
	
}


void
on_buttonajouter_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	int er=0;
	GtkWidget *cin,*nom,*prenom,*text,*jour,*mois,*annee,*type,*sexe;
	reclamation r;
	
	cin=lookup_widget(objet_graphique,"entrycin");
	nom=lookup_widget(objet_graphique,"entrynom");
	prenom=lookup_widget(objet_graphique,"entryprenom");
	text=lookup_widget(objet_graphique,"entrytext");
	
	jour=lookup_widget(objet_graphique,"spinbuttonjour");
	mois=lookup_widget(objet_graphique,"spinbuttonmois");
	annee=lookup_widget(objet_graphique,"spinbuttonannee");
	
	type=lookup_widget(objet_graphique,"comboboxtype");
	
	strcpy(r.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
	strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(r.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
	strcpy(r.text,gtk_entry_get_text(GTK_ENTRY(text)));
	if(strcmp(r.cin,"")==0)
		er++;
	if(strcmp(r.nom,"")==0)
		er++;
	if(strcmp(r.prenom,"")==0)
		er++;
	if(strcmp(r.text,"")==0)
		er++;
	r.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
	r.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	r.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

	if(strcmp("Hebergement",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
		r.type=0;
	else
		r.type=1;
	r.sexe=x;

	
	if(er==0 && z==1)
		ajouter_reclamation(r);
	x=0;
	z=0;
}




void
on_treeviewreclamation_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar *cin ;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path)){
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&cin,-1);
		supprimer_reclamation(cin);
		afficher_reclamation(treeview,"reclamation.txt");

	}
}


void
on_buttonrecherche_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *cin;
	char cin1[30];
	cin=lookup_widget (objet_graphique,"entryrecherchecin");
	strcpy(cin1, gtk_entry_get_text(GTK_ENTRY(cin)));
	GtkWidget *windowafficher;
	GtkWidget *treeview;
	windowafficher=lookup_widget(objet_graphique,"windowafficher");	
	treeview=lookup_widget(windowafficher,"treeviewreclamation");
	if(strcmp(cin1,"")!=0)
	{
		chercher_reclamation(cin1);
		afficher_reclamation(treeview,"recherche.txt");
		remove("recherche.txt");
	}
	else
		afficher_reclamation(treeview,"reclamation.txt");
}


void
on_buttonreturn_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *windowajouter, *windowafficher;
	windowafficher=lookup_widget(objet_graphique,"windowafficher");
	windowajouter=lookup_widget(objet_graphique,"windowajouter");

	gtk_widget_destroy(windowafficher);
	windowajouter=create_windowajouter();
	gtk_widget_show(windowajouter);
}





void
on_buttonmodifier_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	int er=0;
	GtkWidget *cin,*nom,*prenom,*text,*jour,*mois,*annee,*type,*sexe;
	reclamation r;
	
	cin=lookup_widget(objet_graphique,"entrycin");
	nom=lookup_widget(objet_graphique,"entrynom");
	prenom=lookup_widget(objet_graphique,"entryprenom");
	text=lookup_widget(objet_graphique,"entrytext");
	
	jour=lookup_widget(objet_graphique,"spinbuttonjour");
	mois=lookup_widget(objet_graphique,"spinbuttonmois");
	annee=lookup_widget(objet_graphique,"spinbuttonannee");
	
	type=lookup_widget(objet_graphique,"comboboxtype");
	
	strcpy(r.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
	strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(r.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
	strcpy(r.text,gtk_entry_get_text(GTK_ENTRY(text)));
	if(strcmp(r.cin,"")==0)
		er++;
	if(strcmp(r.nom,"")==0)
		er++;
	if(strcmp(r.prenom,"")==0)
		er++;
	if(strcmp(r.text,"")==0)
		er++;
	r.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
	r.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	r.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

	if(strcmp("Hebergement",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
		r.type=0;
	else
		r.type=1;
	r.sexe=x;

	
	if(er==0 && z==1)
		modifier_reclamation(r);
	x=0;
	z=0;
}


void
on_buttongotomodifier_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *windowajouter,*windowafficher;
	GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* treeview,*comboboxtype;
	
	
        gchar* cin;
	gchar* nom;
	gchar* prenom;
	gchar* text;
	gint jour;
	gint mois;
	gint annee;
	gchar* type;
	gchar* sexe;
	windowafficher=lookup_widget(objet_graphique,"windowafficher");
        treeview=lookup_widget(windowafficher,"treeviewreclamation");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
		gtk_tree_model_get (model,&iter,0,&cin,1,&nom,2,&prenom,3,&text,4,&jour,5,&mois,6,&annee,7,&type,8,&sexe,-1);
		gtk_widget_destroy(windowafficher);
		windowajouter=lookup_widget(objet_graphique,"windowajouter");
		windowajouter=create_windowajouter();
		gtk_widget_show(windowajouter);

		comboboxtype=lookup_widget(windowajouter,"comboboxtype");
	        gtk_entry_set_text(GTK_ENTRY(lookup_widget(windowajouter,"entrycin")),cin);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(windowajouter,"entrynom")),nom);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(windowajouter,"entryprenom")),prenom);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(windowajouter,"entrytext")),text);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(windowajouter,"spinbuttonjour")),jour);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(windowajouter,"spinbuttonmois")),mois);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(windowajouter,"spinbuttonannee")),annee);
		if(strcmp("Hebergement",type)==0)
			gtk_combo_box_set_active(comboboxtype,1);
		else
			gtk_combo_box_set_active(comboboxtype,0);
 		
           
	   
	   
	
	}

}


void
on_radiobuttonhomme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		x=0;
	}
}


void
on_radiobuttonfemme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		x=1;
	}
}


void
on_buttonserviceplusreclamer_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *label;
	label=lookup_widget(objet_graphique,"labeltache2");
	if(service_plus_reclamer())
		gtk_label_set_text(GTK_LABEL(label),"Le service restauration est le plus reclamer");
	else
		gtk_label_set_text(GTK_LABEL(label),"Le service hebergement est le plus reclamer");
		

}


void
on_buttongototache2_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *window1, *windowafficher;
	windowafficher=lookup_widget(objet_graphique,"windowafficher");
	window1=lookup_widget(objet_graphique,"window1");

	gtk_widget_destroy(windowafficher);
	window1=create_window1();
	gtk_widget_show(window1);
}


void
on_buttonretour1_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *window1, *windowafficher,*treeview;
	windowafficher=lookup_widget(objet_graphique,"windowafficher");
	window1=lookup_widget(objet_graphique,"window1");

	gtk_widget_destroy(window1);
	windowafficher=create_windowafficher();
	gtk_widget_show(windowafficher);
	treeview=lookup_widget(windowafficher,"treeviewreclamation");
	afficher_reclamation(treeview,"reclamation.txt");
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
		z=1;
}

//////////////////////////////////////////////////////////////////////////////////////////
//Callbacks nutritioniste

#include "menu.h"

void
on_button_mod_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *pInfo3, *mod4;
menu u;
mod1=lookup_widget(objet,"mod1");
mod2=lookup_widget(objet,"mod2");
mod3=lookup_widget(objet,"mod3");
mod4=lookup_widget(objet,"comboboxNut");
strcpy(u.id,gtk_entry_get_text(GTK_ENTRY(mod1)));
u.type=gtk_combo_box_get_active(GTK_COMBO_BOX(mod4));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(mod2)));
u.dechet = atof(gtk_entry_get_text(GTK_ENTRY(mod3)));
modifierNutrition(u,"menu.txt");
pInfo3=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Menu modifié avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo3)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo3);
	break;
	}
}


void
on_check_id_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *pInfo4, *mod4;
menu p;
int a=0;
char ch[20], id[50];
FILE *f;
mod1=lookup_widget(objet,"mod1");
mod2=lookup_widget(objet,"mod2");
mod3=lookup_widget(objet,"mod3");
mod4=lookup_widget(objet,"comboboxNut");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(mod1)));
f = fopen("menu.txt","r");
if(f!=NULL){
while(fscanf(f,"%s %d %s %f %d %d %d\n",p.id,&(p.type),p.nom,&(p.dechet),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{
		if(strcmp(p.id,id)==0){
			a=1;
			break;
                 }
	}
fclose(f);
}
if(a==1){
gtk_entry_set_text(GTK_ENTRY(mod2),p.nom);
sprintf(ch,"%.2f",p.dechet);
gtk_entry_set_text(GTK_ENTRY(mod3),ch);
gtk_combo_box_set_active(GTK_COMBO_BOX(mod4),p.type);
}
else{
pInfo4=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Menu introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo4)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo4);
	break;
	}
}
}


void
on_button_aj_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj1, *aj2, *aj3, *a, *b, *c, *check, *pInfo5;
GtkCalendar *ajc;
menu u;
guint day, month, year;
aj1=lookup_widget(objet,"aj1");
aj2=lookup_widget(objet,"aj2");
aj3=lookup_widget(objet,"aj3");
ajc=lookup_widget(objet,"ajc");
a=lookup_widget(objet,"radiobutton1");
b=lookup_widget(objet,"radiobutton2");
c=lookup_widget(objet,"radiobutton3");
check=lookup_widget(objet,"check");
strcpy(u.id,gtk_entry_get_text(GTK_ENTRY(aj1)));
u.type=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(a))?0:gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b))?1:2;
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(aj2)));
u.dechet=gtk_spin_button_get_value(GTK_SPIN_BUTTON(aj3));
gtk_calendar_get_date(GTK_CALENDAR(ajc), &day, &month, &year);
u.d.j=year;
u.d.m=month+1;
u.d.a=day;
if(gtk_toggle_button_get_active(GTK_CHECK_BUTTON(check)))
ajouterNutrition(u,"menu.txt");
else{
	pInfo5=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Confirmation requise");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo5)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo5);
	break;
	}
	}
}


void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar *id;
	menu u;
	GtkWidget *pInfo6;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path)){
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,-1);
	strcpy(u.id,id);
	pInfo6=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nsupprimer ce menu?");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo6)))
	{
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(pInfo6);
	supprimer(u,"menu.txt");
	afficher(treeview,"menu.txt");
	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pInfo6);
	break;
}	
}
}




void
on_meilleur_menu_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *pInfo7;
char str[1000], ch[1000]="";
strcpy(ch,meilleur_menu("menu.txt"));
sprintf(str,"%s",ch);
pInfo7=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,str);
	switch(gtk_dialog_run(GTK_DIALOG(pInfo7)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo7);
	break;
	}
}


void
on_affichage_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af;
af=lookup_widget(objet,"af");
gtk_widget_destroy(af);
af=lookup_widget(objet,"af");
af=create_af();
gtk_widget_show(af);
treeview=lookup_widget(af,"treeview");
afficher(treeview,"menu.txt");
}


void
on_r2_clicked                          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod, *af;
mod=lookup_widget(objet,"mod");
gtk_widget_destroy(mod);
af=lookup_widget(objet,"af");
af=create_af();
gtk_widget_show(af);
}


void
on_r1_clicked                          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj, *af;
aj=lookup_widget(objet,"aj");
gtk_widget_destroy(aj);
af=lookup_widget(objet,"af");
af=create_af();
gtk_widget_show(af);
}



void
on_ajouterNut_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj, *dashboard;
dashboard=lookup_widget(objet,"af");
gtk_widget_destroy(dashboard);
aj=lookup_widget(objet,"aj");
aj=create_aj();
gtk_widget_show(aj);
}


void
on_modifierNut_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod, *dashboard;
dashboard=lookup_widget(objet,"af");
gtk_widget_destroy(dashboard);
mod=lookup_widget(objet,"mod");
mod=create_mod();
gtk_widget_show(mod);
}


void
on_MAIN_RECLAMATION_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowajouter,*MENU_PRINCIPAL;
MENU_PRINCIPAL=lookup_widget(objet,"MENU_PRINCIPAL");

gtk_widget_destroy(MENU_PRINCIPAL);
windowajouter=create_windowajouter();
gtk_widget_show(windowajouter);
}


void
on__clicked                            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowinterf,*MENU_PRINCIPAL;
MENU_PRINCIPAL=lookup_widget(objet,"MENU_PRINCIPAL");

gtk_widget_destroy(MENU_PRINCIPAL);
windowinterf=create_windowinterf();
gtk_widget_show(windowinterf);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "fonction.h"



void
on_buttonajout_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *quantt ,*typpe ,*idd,*interf,*Home,*treeview ;

char id[50]; 
char type[50]; 
int quant;


idd=lookup_widget(objet_graphique,"entry3");
typpe=lookup_widget(objet_graphique,"comboboxentrytype");
quantt=lookup_widget(objet_graphique,"spinbuttonct");


strcpy(id,gtk_entry_get_text(GTK_ENTRY(idd)));
strcpy(type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(typpe)));
quant=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(quantt));

ajouterstock(id,type,quant);

Home=lookup_widget(objet_graphique,"windowajout");
interf=create_windowinterf();
gtk_widget_show(interf);
gtk_widget_hide(Home);
treeview=lookup_widget(interf,"treeview_a");
afficherstock(treeview) ;
}

void
on_buttonretourajout_clicked           (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Home ,*Next ,*treeview ;
Home=lookup_widget(objet_graphique,"windowajout");
Next=create_windowinterf(); 
gtk_widget_show(Next);
gtk_widget_hide(Home);
treeview=lookup_widget(Next,"treeview_a");
afficherstock(treeview) ;
}


void
on_buttontoajou_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Home ,*Next ,*treeview ;
Home=lookup_widget(objet_graphique,"windowinterf");
Next=create_windowajout(); 
gtk_widget_show(Next);
gtk_widget_hide(Home);
treeview=lookup_widget(Next,"treeview_a");
afficherstock(treeview) ;

}

char id20[50];
void
on_buttonmodif_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Home ,*Next ,*treeview,*idd ;
idd=lookup_widget(objet_graphique,"entry4");
strcpy(id20,gtk_entry_get_text(GTK_ENTRY(idd)));
Home=lookup_widget(objet_graphique,"windowinterf");
Next=create_windowmodif(); 
gtk_widget_show(Next);
gtk_widget_hide(Home);
}


void
on_buttonSupp_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f ; 
GtkWidget *Home ,*idd ,*Next ,*treeview ;

char id[50] ; 

idd=lookup_widget(objet_graphique,"entry4");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(idd)));

supprimerstock(id);

Home=lookup_widget(objet_graphique,"windowinterf");
Next=create_windowinterf(); 
gtk_widget_show(Next);
gtk_widget_hide(Home);
treeview=lookup_widget(Next,"treeview_a");
afficherstock(treeview) ;
}




void
on_buttonmod_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f ; 
GtkWidget *Home ,*Next ,*qu ,*treeview ;
int quant;

qu=lookup_widget(objet_graphique,"spinbutton3");
quant=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(qu));

modifierstock(id20,quant);

Home=lookup_widget(objet_graphique,"windowmodif");
Next=create_windowinterf(); 
gtk_widget_show(Next);
gtk_widget_hide(Home);
treeview=lookup_widget(Next,"treeview_a");
afficherstock(treeview) ;
}


void
on_buttonretalerte_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Home ,*Next  ,*treeview ;
Home=lookup_widget(objet_graphique,"windowalert");
Next=create_windowinterf(); 
gtk_widget_show(Next);
gtk_widget_hide(Home);
treeview=lookup_widget(Next,"treeview_a");
afficherstock(treeview) ;
}


void
on_buttonalerte_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Home ,*Next  ,*treeview ;
Home=lookup_widget(objet_graphique,"windowinterf");
Next=create_windowalert(); 
alerte();
gtk_widget_show(Next);
gtk_widget_hide(Home);

treeview=lookup_widget(Next,"treeview_b");
afficheralerte(treeview) ;
}


void
on_buttonannulmodif_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Home ,*Next  ,*treeview ;
Home=lookup_widget(objet_graphique,"windowmodif");
Next=create_windowinterf(); 
gtk_widget_show(Next);
gtk_widget_hide(Home);
treeview=lookup_widget(Next,"treeview_a");
afficherstock(treeview) ;
}

void
on_buttonesprit_clicked                (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *service_main,*MENU_PRINCIPAL;
service_main=lookup_widget(objet,"service_main");

gtk_widget_destroy(service_main);
MENU_PRINCIPAL=create_MENU_PRINCIPAL();
gtk_widget_show(MENU_PRINCIPAL);
}


void
on_button_retour_cap_clicked           (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *MENU_PRINCIPAL,*gestion_des_capteurs;
gestion_des_capteurs=lookup_widget(objet,"gestion_des_capteurs");

gtk_widget_destroy(gestion_des_capteurs);
MENU_PRINCIPAL=create_MENU_PRINCIPAL();
gtk_widget_show(MENU_PRINCIPAL);
}


void
on_button_retour_reclam_clicked        (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *MENU_PRINCIPAL,*windowajouter;
windowajouter=lookup_widget(objet,"windowajouter");

gtk_widget_destroy(windowajouter);
MENU_PRINCIPAL=create_MENU_PRINCIPAL();
gtk_widget_show(MENU_PRINCIPAL);
}


void
on_button_retour_Nut_clicked           (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *af,*MENU_PRINCIPAL;
af=lookup_widget(objet,"af");

gtk_widget_destroy(af);
MENU_PRINCIPAL=create_MENU_PRINCIPAL();
gtk_widget_show(MENU_PRINCIPAL);
}


void
on_retourstockage_clicked              (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *windowinterf,*MENU_PRINCIPAL;
windowinterf=lookup_widget(objet,"windowinterf");

gtk_widget_destroy(windowinterf);
MENU_PRINCIPAL=create_MENU_PRINCIPAL();
gtk_widget_show(MENU_PRINCIPAL);
}

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////



void
on_button_connexion_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
FILE *f;
int role;
int c ; 
cverif v ; 

GtkWidget  *Login ,*Admin,*output; 

GtkWidget *input,*input1,*treeview,*Connexion; 

input=lookup_widget(objet,"entry_login");
input1=lookup_widget(objet,"entry_pass");
Login=lookup_widget(objet,"Connexion");
output=lookup_widget(objet,"label_unable");
strcpy(v.user,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(v.password,gtk_entry_get_text(GTK_ENTRY(input1)));
c=verifier(v);

if (c==1)
{
Connexion=lookup_widget(objet,"Connexion");

gtk_widget_destroy(Connexion);
Admin=create_MENU_PRINCIPAL();
gtk_widget_show(Admin);
}
else
gtk_label_set_text(GTK_LABEL(output),"Utilisateur ou Mot de passe invalide !");
}

void
on_button_hide_pressed                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *entry;
  entry=lookup_widget(objet,"entry_pass");
  gtk_entry_set_visibility (GTK_ENTRY (entry), TRUE);
  return FALSE;
}


void
on_button_hide_released                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *entry;
  entry=lookup_widget(objet,"entry_pass");
  gtk_entry_set_visibility (GTK_ENTRY (entry), FALSE);
  return FALSE;
}


void
on_button_hide_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_logout_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Connexion,*MENU_PRINCIPAL;
MENU_PRINCIPAL=lookup_widget(objet,"MENU_PRINCIPAL");

gtk_widget_destroy(MENU_PRINCIPAL);
Connexion=create_Connexion();
gtk_widget_show(Connexion);
}

