#include <gtk/gtk.h>

/*
void
on_boutton_ajouter_menu_clicked        (GtkWidget       *button,
                                        gpointer         user_data);
*/
void
on_button_valider_ajouter_clicked      (GtkWidget       *button,
                                        gpointer         user_data);





void
on_button_modifier_clicked             (GtkWidget       *button,
                                        gpointer         user_data);



void
on_button_supprimer_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_valider_supprimer_clicked    (GtkWidget      *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
/*
void
on_button_consulter_clicked            (GtkWidget       *button,
                                        gpointer         user_data);
*/


void
on_button_recherche_clicked            (GtkWidget      *button,
                                        gpointer         user_data);

void
on_button_acceuil_ajouter_clicked      (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_acceuil_consulter_clicked    (GtkWidget       *button,
                                        gpointer         user_data);



void
on_button_actualiser_consulter_clicked (GtkWidget      *button,
                                        gpointer         user_data);

void
on_button_valider_modifier_clicked     (GtkWidget      *button,
                                        gpointer         user_data);

void
on_button_generer_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_capteur_def_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_consulter_clicked            (GtkWidget      *button,
                                        gpointer         user_data);

void
on_boutton_ajouter_menu_clicked        (GtkWidget       *button,
                                        gpointer         user_data);

//////////////////////////////////////////////////////////////////////////////////
//callbacks.h HB


#include <gtk/gtk.h>



void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);



void
on_ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retour_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton_femme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_homme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_retour1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ajouterMain_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_afficherMain_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_modifierMain_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_statsMain_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_AfficherModif_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_modifier_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_Supprimer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_actualiser_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_Confirmer_niveau_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retourstats_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retourRecheche_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_rechercherHB_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_cherchrMain_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_rechercherHB_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_actualiserChercher_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_Confirmer_niveau_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_actualiserChercher_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retourModifierHB_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_MAIN_ADMIN_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_MAIN_HB_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_MAIN_CAPTEUR_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_MAIN_NUTRITION_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton_femme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Niveau1_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Niveau2_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Niveau3_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Niveau4_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Niveau5_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

////////////////////////////////////////////////////////////////////////////////
//Callbacks Rec

void
on_buttonlist_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonajouter_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_radiobuttonencours_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonresolue_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeviewreclamation_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonrecherche_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonreturn_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button3_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonmodifier_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttongotomodifier_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_radiobuttonhomme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonfemme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonserviceplusreclamer_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttongototache2_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonretour1_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

//////////////////////////////////////////////////////////////////////////
//Callbacks.h nutrtion

void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button3_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button4_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_mod_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_check_id_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_af_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_aj_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_meilleur_menu_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_affichage_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_r2_clicked                          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_r1_clicked                          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ajouterNut_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_modifierNut_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_MAIN_RECLAMATION_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on__clicked                            (GtkWidget       *objet,
                                        gpointer         user_data);

////////////////////////////////////////////////////////////////////
void
on_Cnx_clicked                         (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonajout_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonretourajout_clicked           (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_buttontoajou_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonmodif_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonSupp_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonlogout_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonmod_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonretalerte_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonalerte_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonannulmodif_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonesprit_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_retour_cap_clicked           (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_reclam_clicked        (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_Nut_clicked           (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_retourstockage_clicked              (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_connexion_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_hide_pressed                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_hide_released                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_hide_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_logout_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);
