#include <gtk/gtk.h>

GtkWidget *volumebutton;

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

static void value_changed(GtkWidget *scalebutton, gpointer data)
{
    int value = gtk_scale_button_get_value(GTK_SCALE_BUTTON(volumebutton));
    g_print("%i\n", value);
}

int main(int argc, char *argv[])
{    
    gtk_init(&argc, &argv);
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    volumebutton = gtk_volume_button_new();
    g_signal_connect(volumebutton, "value-changed", G_CALLBACK(value_changed), NULL);
    gtk_container_add(GTK_CONTAINER(window), volumebutton);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
