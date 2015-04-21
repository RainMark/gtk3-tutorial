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
    
    GtkWidget *linkbutton = gtk_link_button_new_with_label("http://learngtk.org/", "Link Button");
    gtk_container_add(GTK_CONTAINER(window), linkbutton);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
