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
    
    GtkObject *hadjustment = gtk_adjustment_new(50, 0, 100, 1, 10, 0);
    GtkWidget *hscale = gtk_hscale_new(GTK_ADJUSTMENT(hadjustment));
    gtk_box_pack_start(GTK_BOX(hbox), hscale, TRUE, TRUE, 0);
    
    GtkObject *vadjustment = gtk_adjustment_new(50, 0, 100, 1, 10, 0);
    GtkWidget *vscale = gtk_vscale_new(GTK_ADJUSTMENT(vadjustment));
    gtk_box_pack_start(GTK_BOX(hbox), vscale, TRUE, TRUE, 0);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
