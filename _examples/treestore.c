#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{    
    gtk_init(&argc, &argv);
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    GtkTreeStore *treestore = gtk_tree_store_new(1, G_TYPE_STRING);
    GtkTreeIter treeiter;
    
    gtk_tree_store_append(treestore, &treeiter, NULL);
    gtk_tree_store_set(treestore, &treeiter, 0, "Mandriva", -1);
    gtk_tree_store_append(treestore, &treeiter, &treeiter);
    gtk_tree_store_set(treestore, &treeiter, 0, "http://www.mandriva.com/", -1);
    gtk_tree_store_append(treestore, &treeiter, NULL);
    gtk_tree_store_set(treestore, &treeiter, 0, "Slackware", -1);
    gtk_tree_store_append(treestore, &treeiter, &treeiter);
    gtk_tree_store_set(treestore, &treeiter, 0, "http://www.slackware.com/", -1);
    gtk_tree_store_append(treestore, &treeiter, NULL);
    gtk_tree_store_set(treestore, &treeiter, 0, "Chakra", -1);
    gtk_tree_store_append(treestore, &treeiter, &treeiter);
    gtk_tree_store_set(treestore, &treeiter, 0, "http://chakra-project.org/", -1);
    
    GtkWidget *treeview = gtk_tree_view_new_with_model(GTK_TREE_MODEL(treestore));
    gtk_container_add(GTK_CONTAINER(window), treeview);
    
    GtkCellRenderer *cellrenderertext = gtk_cell_renderer_text_new();
    
    
    GtkTreeViewColumn *treeviewcolumn = gtk_tree_view_column_new_with_attributes("Distributions", 
    										 cellrenderertext,
    										 "text", 0,
    										 NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), treeviewcolumn);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}