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
    
    GtkWidget *entry = gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(entry), "A Text Entry Widget");
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Placeholder Text");
    g_signal_connect(GTK_ENTRY(entry), "activate", G_CALLBACK(entry_activated), NULL);
    gtk_container_add(GTK_CONTAINER(window), entry);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
