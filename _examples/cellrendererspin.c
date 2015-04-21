#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    GtkListStore *liststore = gtk_list_store_new(2, G_TYPE_STRING, G_TYPE_INT);
    GtkTreeIter treeiter;
    
    gtk_list_store_append(liststore, &treeiter);
    gtk_list_store_set(liststore, &treeiter, 0, "Orange", 1, 5, -1);
    gtk_list_store_append(liststore, &treeiter);
    gtk_list_store_set(liststore, &treeiter, 0, "Apple", 1, 4, -1);
    gtk_list_store_append(liststore, &treeiter);
    gtk_list_store_set(liststore, &treeiter, 0, "Pineapple", 1, 1, -1);
    gtk_list_store_append(liststore, &treeiter);
    gtk_list_store_set(liststore, &treeiter, 0, "Melon", 1, 2, -1);
    gtk_list_store_append(liststore, &treeiter);
    gtk_list_store_set(liststore, &treeiter, 0, "Banana", 1, 6, -1);
    
    GtkWidget *treeview = gtk_tree_view_new_with_model(GTK_TREE_MODEL(liststore));
    gtk_container_add(GTK_CONTAINER(window), treeview);
    
    GtkTreeViewColumn *treeviewcolumn;
    
    GtkCellRenderer *cellrenderertext = gtk_cell_renderer_text_new();
    treeviewcolumn = gtk_tree_view_column_new_with_attributes("Fruit",
                                                              cellrenderertext,
                                                              "text", 0, 
                                                              NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), treeviewcolumn);
    
    GtkCellRenderer *cellrendererspin = gtk_cell_renderer_spin_new();
    g_object_set(G_OBJECT(cellrendererspin), "editable", TRUE, NULL);
    GtkObject *adjustment = gtk_adjustment_new(0, 0, 10, 1, 2, 0);
    g_object_set(G_OBJECT(cellrendererspin), "adjustment", adjustment, NULL);
    treeviewcolumn = gtk_tree_view_column_new_with_attributes("Quantity",
                                                              cellrendererspin,
                                                              "text", 1,
                                                              NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), treeviewcolumn);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
