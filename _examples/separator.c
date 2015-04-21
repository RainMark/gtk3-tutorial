#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{    
    gtk_init(&argc, &argv);
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    GtkWidget *hbox = gtk_hbox_new(TRUE, 5);
    gtk_container_add(GTK_CONTAINER(window), hbox);
    
    GtkWidget *hseparator = gtk_hseparator_new();
    gtk_box_pack_start(GTK_BOX(hbox), hseparator, TRUE, TRUE, 0);
    GtkWidget *vseparator = gtk_vseparator_new();
    gtk_box_pack_start(GTK_BOX(hbox), vseparator, TRUE, TRUE, 0);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
