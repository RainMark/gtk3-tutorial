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
    
    GtkAdjustment *adjustment = gtk_adjustment_new(0, 0, 10, 1, 2, 0);
    
    GtkWidget *spinbutton = gtk_spin_button_new(GTK_ADJUSTMENT(adjustment), 0, 0);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton), 5);
    gtk_container_add(GTK_CONTAINER(window), spinbutton);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
