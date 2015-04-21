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
    
    GtkWidget *expander = gtk_expander_new("Expander");
    gtk_container_add(GTK_CONTAINER(window), expander);
    
    GtkWidget *label = gtk_label_new("Expander with Label");
    gtk_widget_set_size_request(GTK_WIDGET(label), 200, 200);
    gtk_container_add(GTK_CONTAINER(expander), label);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
