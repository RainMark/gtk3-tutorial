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
    
    GtkWidget *image = gtk_image_new_from_file("../resources/gtk.png");
    gtk_container_add(GTK_CONTAINER(window), image);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
