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
    
    GtkListStore *liststore = gtk_list_store_new(2, G_TYPE_STRING, G_TYPE_STRING);
    GtkTreeIter treeiter;
    
    gtk_list_store_append(liststore, &treeiter);
    gtk_list_store_set(liststore, &treeiter, 0, "Television", 1, "", -1);
    gtk_list_store_append(liststore, &treeiter);
    gtk_list_store_set(liststore, &treeiter, 0, "Mobile Phone", 1, "", -1);
    gtk_list_store_append(liststore, &treeiter);
    gtk_list_store_set(liststore, &treeiter, 0, "DVD Player", 1, "", -1);
    
    GtkListStore *liststoreManufacturer = gtk_list_store_new(1, G_TYPE_STRING);
    GtkTreeIter treeiter2;
    
    gtk_list_store_append(liststoreManufacturer, &treeiter2);
    gtk_list_store_set(liststoreManufacturer, &treeiter2, 0, "Sony", -1);
    gtk_list_store_append(liststoreManufacturer, &treeiter2);
    gtk_list_store_set(liststoreManufacturer, &treeiter2, 0, "Samsung", -1);
    gtk_list_store_append(liststoreManufacturer, &treeiter2);
    gtk_list_store_set(liststoreManufacturer, &treeiter2, 0, "LG", -1);
    
    GtkWidget *treeview = gtk_tree_view_new_with_model(GTK_TREE_MODEL(liststore));
    gtk_container_add(GTK_CONTAINER(window), treeview);
    
    GtkTreeViewColumn *treeviewcolumn;
    GtkCellRenderer *cellrenderertext;
    GtkCellRenderer *cellrenderercombo;
    
    cellrenderertext = gtk_cell_renderer_text_new();
    treeviewcolumn = gtk_tree_view_column_new_with_attributes("Device",
                                                              cellrenderertext,
                                                              "text", 0, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), treeviewcolumn);
    cellrenderercombo = gtk_cell_renderer_combo_new();
    gtk_widget_set_property(GTK_WIDGET(cellrenderercombo), "model", liststoreManufacturer);
    treeviewcolumn = gtk_tree_view_column_new_with_attributes("Manufacturer",
                                                              cellrenderercombo,
                                                              "editable", TRUE,
                                                              "model", liststoreManufacturer,
                                                              "text-column", 0, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), treeviewcolumn);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
