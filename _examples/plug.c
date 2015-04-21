#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

static void embed_event(GtkWidget *widget, gpointer data)
{
    g_print("Embed event occurred");
}

static void entry_activated(GtkWidget *widget, gpointer data)
{
    g_print("Entry activated");
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    
    GtkWidget *plug = gtk_plug_new(NULL);
    g_print("%i", gtk_plug_get_id(GTK_PLUG(plug)));
    g_signal_connect(plug, "destroy", G_CALLBACK(destroy), NULL);
    g_signal_connect(plug, "embed-event", G_CALLBACK(embed_event), NULL);
    
    GtkWidget *entry = gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(entry), "Plug and Socket");
    g_signal_connect(entry, "activate", G_CALLBACK(entry_activated), NULL);
    gtk_plug_add(GTK_PLUG(plug), entry);
    
    gtk_widget_show_all(plug);
    
    gtk_main();
    
    return 0;
}