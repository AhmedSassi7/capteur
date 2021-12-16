#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include <string.h>

enum
{
	EREFERENCE,
	ETYPE,
	ELOCALISATION,	
	EVALMIN,
	EVALMAX,
	EETAT,
	COLUMNS,
};


void afficher_capteur(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
 	GtkTreeIter iter;
	GtkListStore *store;


	char reference[30];
	char type[30];
	char localisation[30];
	char valmin[30];
	char valmax[30];
	char etat[10];
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{

	renderer = gtk_cell_renderer_text_new ();	
	column = gtk_tree_view_column_new_with_attributes ("Reference", renderer, "text" ,EREFERENCE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();	
	column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text" ,ETYPE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();	
	column = gtk_tree_view_column_new_with_attributes("Localisation", renderer, "text" ,ELOCALISATION, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();	
	column = gtk_tree_view_column_new_with_attributes("Valeur Min", renderer, "text" ,EVALMIN, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();	
	column = gtk_tree_view_column_new_with_attributes("Valeur Max", renderer, "text" ,EVALMAX, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();	
	column = gtk_tree_view_column_new_with_attributes("Etat", renderer, "text" ,EETAT, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}

	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen("capteurs.txt","r");
	if(f=NULL)

	{
		return;
	}
	else
	{	f=fopen("capteurs.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s\n ",reference,type,localisation,valmin,valmax,etat)!=EOF)
		{
			gtk_list_store_append (store,&iter);
			gtk_list_store_set (store, &iter, EREFERENCE, reference, ETYPE, type, ELOCALISATION, localisation, EVALMIN, valmin, EVALMAX, valmax, EETAT, etat, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}
}
//////////////////////////////////////////////////
void supprimer_capteur(char ref[])
{
capteur c2;
FILE *f,*g;

		f=fopen("capteurs.txt","r");
		g=fopen("capt.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s",c2.Reference,c2.Type,c2.Localisation,c2.Valeur_Min,c2.Valeur_Max,c2.Etat)!=EOF)
		{
			if(strcmp(ref,c2.Reference)!=0)
			fprintf(g,"%s %s %s %s %s %s\n",c2.Reference,c2.Type,c2.Localisation,c2.Valeur_Min,c2.Valeur_Max,c2.Etat);
				

		}
				
		fclose(f);
		fclose(g);
		remove("capteurs.txt");
		rename("capt.txt","capteurs.txt");
}
///////////////////////////////////////////ajouter////////////////////////////////////////////////////

void ajouter(capteur C)
{
    FILE *f;
    f=fopen("capteurs.txt","a+");
    if (f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s %s\n",C.Reference,C.Type,C.Localisation,C.Valeur_Min,C.Valeur_Max,C.Etat);
        fclose(f);

    }
    else
    {
      printf("impossible d'ouvrir le fichier");
    }
}

void modifier_capteur(capteur x)
{

    FILE *f;
    FILE *tmp;
    capteur c;

 
    f=fopen("capteurs.txt","r");
    tmp=fopen("tmp.txt","a+");

     while(fscanf(f,"%s %s %s %s %s %s \n",c.Reference,c.Type,c.Localisation,c.Valeur_Min,c.Valeur_Max,c.Etat)!=EOF)
        {
        if (strcmp(x.Reference,c.Reference)!=0)
            {
                fprintf(tmp,"%s %s %s %s %s %s \n",c.Reference,c.Type,c.Localisation,c.Valeur_Min,c.Valeur_Max,c.Etat);
            }
        else if(strcmp(x.Reference,c.Reference)==0)
	{
		fprintf(tmp,"%s %s %s %s %s %s \n",x.Reference,x.Type,x.Localisation,x.Valeur_Min,x.Valeur_Max,x.Etat);
		
 	}
        }
        fclose(f);
        fclose(tmp);
        remove("capteurs.txt");
        rename("tmp.txt","capteurs.txt");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void afficher_capteur_rechercher(char nom_fichier[],GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
 	GtkTreeIter iter;
	GtkListStore *store;


	char reference[30];
	char type[30];
	char localisation[30];
	char valmin[30];
	char valmax[30];
	char etat[10];
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{

	renderer = gtk_cell_renderer_text_new ();	
	column = gtk_tree_view_column_new_with_attributes ("Reference", renderer, "text" ,EREFERENCE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();	
	column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text" ,ETYPE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();	
	column = gtk_tree_view_column_new_with_attributes("Localisation", renderer, "text" ,ELOCALISATION, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();	
	column = gtk_tree_view_column_new_with_attributes("Valeur Min", renderer, "text" ,EVALMIN, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();	
	column = gtk_tree_view_column_new_with_attributes("Valeur Max", renderer, "text" ,EVALMAX, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();	
	column = gtk_tree_view_column_new_with_attributes("Etat", renderer, "text" ,EETAT, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}

	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen(nom_fichier,"r");
	if(f==NULL)

	{
		return;
	}
	else
	{	f=fopen(nom_fichier,"a+");
		while(fscanf(f,"%s %s %s %s %s %s\n ",reference,type,localisation,valmin,valmax,etat)!=EOF)
		{
			gtk_list_store_append (store,&iter);
			gtk_list_store_set (store, &iter, EREFERENCE, reference, ETYPE, type, ELOCALISATION, localisation, EVALMIN, valmin, EVALMAX, valmax, EETAT, etat, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}
remove(nom_fichier);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void recherche_capteur(char nom_fichier[],char x[])
{
FILE *f,*tmp;
capteur c;

f=fopen("capteurs.txt","r");
tmp=fopen(nom_fichier,"a+");

if(f!=NULL && tmp!=NULL)
{
	while(fscanf(f,"%s %s %s %s %s %s \n",c.Reference,c.Type,c.Localisation,c.Valeur_Min,c.Valeur_Max,c.Etat)!=EOF)
	{
		if (strcmp(x,c.Reference)==0)
		fprintf(tmp,"%s %s %s %s %s %s \n",c.Reference,c.Type,c.Localisation,c.Valeur_Min,c.Valeur_Max,c.Etat);
	}
}
else
return;
fclose(f);
fclose(tmp);

}



///////////////////////////////////////////////


void afficher_capteur_deff(GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
 	GtkTreeIter iter;
	GtkListStore *store;


	char reference[30];
	char type[30];
	char localisation[30];
	char valmin[30];
	char valmax[30];
	char etat[10];
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{

	renderer = gtk_cell_renderer_text_new ();	
	column = gtk_tree_view_column_new_with_attributes ("Reference", renderer, "text" ,EREFERENCE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();	
	column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text" ,ETYPE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();	
	column = gtk_tree_view_column_new_with_attributes("Localisation", renderer, "text" ,ELOCALISATION, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();	
	column = gtk_tree_view_column_new_with_attributes("Valeur Min", renderer, "text" ,EVALMIN, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();	
	column = gtk_tree_view_column_new_with_attributes("Valeur Max", renderer, "text" ,EVALMAX, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();	
	column = gtk_tree_view_column_new_with_attributes("Etat", renderer, "text" ,EETAT, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}

	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen( "captdeff.txt","r+");
	if(f==NULL)

	{
		return;
	}
	else
	{	f=fopen( "captdeff.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s\n ",reference,type,localisation,valmin,valmax,etat)!=EOF)
		{
			gtk_list_store_append (store,&iter);
			gtk_list_store_set (store, &iter, EREFERENCE, reference, ETYPE, type, ELOCALISATION, localisation, EVALMIN, valmin, EVALMAX, valmax, EETAT, etat, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}

}


void ajouter_capteurdeff(capteur c)
{
int vmax,vmin;

FILE *f1;
FILE *f2;
capteur capt;
f1=fopen("capteurs.txt","r+");
while ((fscanf(f1,"%s %s %s %s %s %s\n ",capt.Reference,capt.Type,capt.Localisation,capt.Valeur_Min,capt.Valeur_Max,capt.Etat)!=EOF));
	{
	strcpy(c.Reference,capt.Reference);
	strcpy(c.Type,capt.Type);
	strcpy(c.Localisation,capt.Localisation);
	strcpy(c.Valeur_Min,capt.Valeur_Min);
	strcpy(c.Valeur_Max,capt.Valeur_Max);
	strcpy(c.Etat,capt.Etat);
	}
	
fclose(f1);
f2=fopen("captdeff.txt","a+");
if (f2!=NULL)
	{
	fprintf(f2,"%s %s %s %s %s %s\n ",c.Reference,c.Type,c.Localisation,c.Valeur_Min,c.Valeur_Max,c.Etat);
	}
fclose(f2);
}


enum
{
	EREFEREN,
	ETY,
	ELOCALISATI,	
	EVALM,
	EVAL,
	EET,
	COLUM,
};
void affichercpadef(GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
 	GtkTreeIter iter;
	GtkListStore *store;

int za,ee;
	char reference[30];
	char type[30];
	char localisation[30];
	int valmin;
	int valmax;
	char etat[10];
	store=NULL;

	FILE *f=NULL;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{

	renderer = gtk_cell_renderer_text_new ();	
	column = gtk_tree_view_column_new_with_attributes ("Reference", renderer, "text" ,EREFEREN, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();	
	column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text" ,ETY, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();	
	column = gtk_tree_view_column_new_with_attributes("Localisation", renderer, "text" ,ELOCALISATI, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();	
	column = gtk_tree_view_column_new_with_attributes("Valeur Min", renderer, "text" ,EVALM, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();	
	column = gtk_tree_view_column_new_with_attributes("Valeur Max", renderer, "text" ,EVAL, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();	
	column = gtk_tree_view_column_new_with_attributes("Etat", renderer, "text" ,EET, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}

	store=gtk_list_store_new (COLUM, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING);

	f=fopen( "capteurs.txt","r");
	if(f==NULL)

	{
		return;
	}
	else
	{
      	f=fopen( "capteurs.txt","r");
	while(fscanf(f,"%s %s %s %d %d %s\n ",reference,type,localisation,&valmin,&valmax,etat)!=EOF)
		{



              za=valmax-valmin;
		if(za>40)
		{

			gtk_list_store_append (store,&iter);
			gtk_list_store_set (store, &iter, EREFEREN, reference, ETY, type, ELOCALISATI,localisation, EVALM, valmin, EVAL, valmax, EET, etat, -1);

		}
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}
}
















