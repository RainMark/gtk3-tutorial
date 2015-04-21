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
    gtk_list_store_set(liststore, &treeiter, 0, "Zenwalk", 1, "http://www.zenwalk.org/", -1);
    gtk_list_store_append(liststore, &treeiter);
    gtk_list_store_set(liststore, &treeiter, 0, "CentOS", 1, "http://www.centos.org/", -1);
    gtk_list_store_append(liststore, &treeiter);
    gtk_list_store_set(liststore, &treeiter, 0, "Ubuntu", 1, "http://www.ubuntu.com/", -1);
    gtk_list_store_append(liststore, &treeiter);
    gtk_list_store_set(liststore, &treeiter, 0, "Puppy", 1, "http://www.puppylinux.org/", -1);
    gtk_list_store_append(liststore, &treeiter);
    gtk_list_store_set(liststore, &treeiter, 0, "Gentoo", 1, "http://www.gentoo.org/", -1);
    
    GtkWidget *treeview = gtk_tree_view_new_with_model(GTK_TREE_MODEL(liststore));
    gtk_container_add(GTK_CONTAINER(window), treeview);
    
    GtkTreeViewColumn *treeviewcolumn;
    GtkCellRenderer *cellrenderertext;
    
    cellrenderertext = gtk_cell_renderer_text_new();
    treeviewcolumn = gtk_tree_view_column_new_with_attributes("Distribution",
                                                              cellrenderertext,
                                                              "text", 0, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), treeviewcolumn);
    cellrenderertext = gtk_cell_renderer_text_new();
    gtk_widget_set_property(GTK_WIDGET(cellrenderertext), "editable", TRUE);
    treeviewcolumn = gtk_tree_view_column_new_with_attributes("Website",
                                                              cellrenderertext,
                                                              "text", 1, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), treeviewcolumn);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
