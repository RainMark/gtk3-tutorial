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

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    GtkWidget *entry;
    GtkEntryBuffer *entrybuffer = gtk_entry_buffer_new("EntryBuffer example", -1);

    entry = gtk_entry_new_with_buffer(GTK_ENTRY_BUFFER(entrybuffer));
    gtk_box_pack_start(GTK_BOX(vbox), entry, FALSE, FALSE, 0);
    entry = gtk_entry_new_with_buffer(GTK_ENTRY_BUFFER(entrybuffer));
    gtk_box_pack_start(GTK_BOX(vbox), entry, FALSE, FALSE, 0);
    entry = gtk_entry_new_with_buffer(GTK_ENTRY_BUFFER(entrybuffer));
    gtk_box_pack_start(GTK_BOX(vbox), entry, FALSE, FALSE, 0);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
