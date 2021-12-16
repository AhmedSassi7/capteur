#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"

char tmp[15]={"temporaire.txt"};
capteur cz;
capteur C,R ;
int x;
int xa;
int euop;
void
on_button_Ajout_Ajouter_GestCapt_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ref, *type, *local, *vmin, *vmax, *etat,*et;




ref=lookup_widget(button,"entry_reference_GestCapt");
type=lookup_widget(button,"ahmed_combobox1");
local=lookup_widget(button,"entry_Localisation_GestCapt");
vmin=lookup_widget(button,"entry_Valeur_Min_GestCapt");
vmax=lookup_widget(button,"entry_Valeur_Max_GestCapt");


strcpy(C.Reference,gtk_entry_get_text(GTK_ENTRY(ref)));

strcpy(C.Valeur_Min,gtk_entry_get_text(GTK_ENTRY(vmin)));
strcpy(C.Valeur_Max,gtk_entry_get_text(GTK_ENTRY(vmax)));
strcpy(C.Localisation,gtk_entry_get_text(GTK_ENTRY(local)));
if(x==1)
strcpy(C.Etat,"1");
else if (x==2)
strcpy(C.Etat,"0");
if(strcmp("Temperature",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
strcpy(C.Type,"Temperature");
if(strcmp("Gaz",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
strcpy(C.Type,"Gaz");
if(strcmp("Humiditer",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
strcpy(C.Type,"Humiditer");
if(strcmp("Fumer",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
strcpy(C.Type,"Fumer");

ajouter(C);
}


void
on_button_Ajout_Annuler_GestCapt_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *annul;

annul=lookup_widget(button,"Ajouter");

gtk_widget_hide(annul);
}


void
on_button_interface_Modifier_GestCapt_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifi;


fenetre_modifi=lookup_widget(button,"Modification");

fenetre_modifi=create_Modification();
gtk_widget_show(fenetre_modifi);
}





void
on_button_interface_Ajouter_GestCapt_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajoute;


fenetre_ajoute=lookup_widget(button,"Ajouter");

fenetre_ajoute=create_Ajouter();
gtk_widget_show(fenetre_ajoute);
}
void
on_button_interface_supprimer_GestCapt_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *refenry;
char refe[20];
refenry=lookup_widget(button,"entry_interface_Rechercher_GestCapt");
strcpy(refe,gtk_entry_get_text(GTK_ENTRY(refenry)));
supprimer_capteur(refe);
GtkWidget *trv;
trv=lookup_widget(button,"treeview_affichage_GestCapt");
afficher_capteur(trv);
}

void
on_button_interface_Rechercher_GestCapt_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
capteur x;
GtkWidget *ref,*trv;

ref=lookup_widget(button,"entry_interface_Rechercher_GestCapt");
strcpy(x.Reference,gtk_entry_get_text(GTK_ENTRY(ref)));
recherche_capteur(tmp,x.Reference);

trv=lookup_widget(button,"treeview_affichage_GestCapt");
afficher_capteur_rechercher(tmp,trv);
}


void
on_button_Supprimer_OUI_GestCapt_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_Supprimer_NON_GestCapt_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_Modifier_OK_GestCapt_clicked (GtkButton       *button,
                                        gpointer         user_data)

{
GtkWidget *reference, *type, *localisation, *vmax, *vmin, *etat;

reference=lookup_widget(button,"entry_reference_Capteur_a_modifier_GestCapt");
type=lookup_widget(button,"entry_Nouveau_Type_GestCapt");
localisation=lookup_widget(button,"entry_Nouveau_localisation_GestCapt");
vmin=lookup_widget(button,"entry_Nouveau_Valeur_Min_GestCapt");
vmax=lookup_widget(button,"entry_Nouveau_Valeur_Max_GestCapt");
etat=lookup_widget(button,"entry_nouveau_Etat_GestCapt");

strcpy(R.Reference,gtk_entry_get_text(GTK_ENTRY(reference)));
strcpy(R.Type,gtk_entry_get_text(GTK_ENTRY(type)));
strcpy(R.Localisation,gtk_entry_get_text(GTK_ENTRY(localisation)));
strcpy(R.Valeur_Min,gtk_entry_get_text(GTK_ENTRY(vmin)));
strcpy(R.Valeur_Max,gtk_entry_get_text(GTK_ENTRY(vmax)));
strcpy(R.Etat,gtk_entry_get_text(GTK_ENTRY(etat)));
modifier_capteur(R);
}


void
on_button_Modifier_Retour_GestCapt_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modif;

modif=lookup_widget(button,"Modification");

gtk_widget_hide(modif);
}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* Reference;
	gchar* Type;
	gchar* Vocalisation;
	gchar* Valmin;
	gchar* Valmax;
	gchar* Etat;
	
        
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	
	if (gtk_tree_model_get_iter(model, &iter, path))	
{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &Reference, 1, &Type, 2,&Vocalisation, 3,&Valmin, 4,&Valmax, 5,&Etat, -1);
	strcpy(cz.Reference,Reference);
	strcpy(cz.Type,Type);
	strcpy(cz.Localisation,Vocalisation);
	strcpy(cz.Valeur_Min,Valmin);
	strcpy(cz.Valeur_Max,Valmax);
	strcpy(cz.Etat,Etat);
	
	
}
}

void
on_button_affichage_trv_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *trv;
trv=lookup_widget(button,"treeview_affichage_GestCapt");
afficher_capteur(trv);
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button_ok_supprimer_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
if(xa==1) 
supprimer_capteur(cz.Reference);
else if(xa==2)
{
GtkWidget *modif;

modif=lookup_widget(button,"ahmed_supprimer");

gtk_widget_hide(modif);
}


}


void
on_ahmed_radio_1_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
x=1;
}


void
on_ahmed_raddio_0_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
x=2;
}

//////////////////////////////////////////////////////////

void
on_button1_deff_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_captdeff;
GtkWidget *treeviewcapt;
capteur c;

ajouter_capteurdeff(c);


fenetre_captdeff=lookup_widget(objet_graphique,"fenetre_captdeff");
fenetre_captdeff=create_fenetre_captdeff();

gtk_widget_show(fenetre_captdeff);


treeviewcapt=lookup_widget(objet_graphique,"treeview1");

}

/*
void
on_treeviewcapt_row_activated          (GtkTreeView     *treeviewcapt,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	
	
}

*/
void
on_button1_retourcapt_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modif;

modif=lookup_widget(button,"fenetre_captdeff");

gtk_widget_hide(modif);
}

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* Reference;
	gchar* Type;
	gchar* Vocalisation;
	gchar* Valmin;
	gchar* Valmax;
	gchar* Etat;
	capteur c;
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	
	if (gtk_tree_model_get_iter(model, &iter, path))	
{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &Reference, 1, &Type, 2,&Vocalisation, 3,&Valmin, 4,&Valmax, 5,&Etat, -1);
	strcpy(c.Reference,Reference);
	strcpy(c.Type,Type);
	strcpy(c.Localisation,Vocalisation);
	strcpy(c.Valeur_Min,Valmin);
	strcpy(c.Valeur_Max,Valmax);
	strcpy(c.Etat,Etat);

	supprimer_capteur(c.Reference);
	afficher_capteur_deff(treeview);
}

}


void
on_ahmedaffichagedeff_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeviewcapt;
treeviewcapt=lookup_widget(button,"treeview1");

affichercpadef(treeviewcapt);
}


void
on_non_checkahmed_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)) 
xa=2;
}


void
on_ahmed_checkbutton1_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)) 
xa=1;



}





void
on_sassi_buton_supp_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajoute;

fenetre_ajoute=create_ahmed_supprimer();
gtk_widget_show(fenetre_ajoute);
}

