#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

static void entry_activated(GtkWidget *entry, gpointer data)
{
    g_print("Entry text: '%s'\n", gtk_entry_get_text(GTK_ENTRY(entry)));
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    GtkListStore *liststore = gtk_list_store_new(1, G_TYPE_STRING);
    GtkTreeIter iter;
    
    gtk_list_store_append(liststore, &iter);
    gtk_list_store_set(liststore, &iter, 0, "Fedora", -1);
    gtk_list_store_append(liststore, &iter);
    gtk_list_store_set(liststore, &iter, 0, "Sabayon", -1);
    gtk_list_store_append(liststore, &iter);
    gtk_list_store_set(liststore, &iter, 0, "Arch Linux", -1);
    gtk_list_store_append(liststore, &iter);
    gtk_list_store_set(liststore, &iter, 0, "SimplyMEPIS", -1);
    gtk_list_store_append(liststore, &iter);
    gtk_list_store_set(liststore, &iter, 0, "Debian", -1);
    
    GtkEntryCompletion *entrycompletion = gtk_entry_completion_new();
    gtk_entry_completion_set_model(GTK_ENTRY_COMPLETION(entrycompletion), GTK_TREE_MODEL(liststore));
    gtk_entry_completion_set_text_column(GTK_ENTRY_COMPLETION(entrycompletion), 0);
    
    GtkWidget *entry = gtk_entry_new();
    gtk_entry_set_completion(GTK_ENTRY(entry), entrycompletion);
    g_signal_connect(GTK_ENTRY(entry), "activate", G_CALLBACK(entry_activated), NULL);
    gtk_container_add(GTK_CONTAINER(window), entry);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
