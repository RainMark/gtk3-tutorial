#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

static void plug_added(GtkWidget *widget, gpointer data)
{
    g_print("A plug has been added");
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    GtkWidget *socket = gtk_socket_new();
    g_signal_connect(socket, "plug-added", G_CALLBACK(plug_added), NULL);
    gtk_container_add(GTK_CONTAINER(window), socket);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}