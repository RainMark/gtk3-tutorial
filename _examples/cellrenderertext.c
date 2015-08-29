#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

static void on_cell_edited(GtkWidget *cellrenderer, gchar *path, gchar *text, gpointer data)
{
    GtkTreeModel *model = (GtkTreeModel *)data;
    GtkTreePath *treepath = gtk_tree_path_new_from_string(path);
    GtkTreeIter treeiter;

    gtk_tree_model_get_iter(model, &treeiter, treepath);

    gtk_list_store_set(GTK_LIST_STORE(model), &treeiter, 1, text, -1);
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

    GtkListStore *liststore = gtk_list_store_new(2, G_TYPE_STRING, G_TYPE_STRING);
    GtkTreeIter treeiter;

    gtk_list_store_append(liststore, &treeiter);
    gtk_list_store_set(liststore, &treeiter, 0, "Potatoes", 1, "4", -1);
    gtk_list_store_append(liststore, &treeiter);
    gtk_list_store_set(liststore, &treeiter, 0, "Tissues", 1, "1", -1);
    gtk_list_store_append(liststore, &treeiter);
    gtk_list_store_set(liststore, &treeiter, 0, "Yoghurts", 1, "3", -1);
    gtk_list_store_append(liststore, &treeiter);
    gtk_list_store_set(liststore, &treeiter, 0, "Milk", 1, "2", -1);
    gtk_list_store_append(liststore, &treeiter);
    gtk_list_store_set(liststore, &treeiter, 0, "Soup", 1, "3", -1);

    GtkWidget *treeview = gtk_tree_view_new_with_model(GTK_TREE_MODEL(liststore));
    gtk_container_add(GTK_CONTAINER(window), treeview);

    GtkTreeViewColumn *treeviewcolumn;
    GtkCellRenderer *cellrenderertext;

    cellrenderertext = gtk_cell_renderer_text_new();
    treeviewcolumn = gtk_tree_view_column_new_with_attributes("Grocery",
                                                              cellrenderertext,
                                                              "text", 0,
                                                              NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), treeviewcolumn);
    treeviewcolumn = gtk_tree_view_column_new_with_attributes("Quantity",
                                                              cellrenderertext,
                                                              "text", 1, NULL);
    g_object_set(cellrenderertext, "editable", TRUE, NULL);
    g_signal_connect(cellrenderertext, "edited", G_CALLBACK(on_cell_edited), liststore);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), treeviewcolumn);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
