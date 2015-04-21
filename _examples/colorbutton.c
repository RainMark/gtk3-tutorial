#include <gtk/gtk.h>
#include <gdk/gdk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

static void color_set(GtkWidget *widget, GtkColorButton *colorbutton)
{
    GdkColor color;
    
    gtk_color_button_get_color(colorbutton, &color);
}

int main(int argc, char *argv[])
{    
    gtk_init(&argc, &argv);
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    GtkWidget *colorbutton = gtk_color_button_new();
    g_signal_connect(colorbutton, "color-set", G_CALLBACK(color_set), (gpointer) colorbutton);
    gtk_container_add(GTK_CONTAINER(window), colorbutton);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
