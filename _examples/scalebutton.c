#include <gtk/gtk.h>

GtkWidget *scalebutton;

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

static void value_changed(GtkWidget *scalebutton, gpointer data)
{
    int value = gtk_scale_button_get_value(GTK_SCALE_BUTTON(scalebutton));
    g_print("%i\n", value);
}

int main(int argc, char *argv[])
{    
    gtk_init(&argc, &argv);
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    scalebutton = gtk_scale_button_new(GTK_ICON_SIZE_BUTTON, 0, 100, 1, NULL);
    g_signal_connect(scalebutton, "value-changed", G_CALLBACK(value_changed), NULL);
    gtk_container_add(GTK_CONTAINER(window), scalebutton);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
