#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{    
    gtk_init(&argc, &argv);
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 50);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    GtkWidget *hbox = gtk_hbox_new(TRUE, 5);
    gtk_container_add(GTK_CONTAINER(window), hbox);
    
    GtkWidget *arrowLeft = gtk_arrow_new(GTK_ARROW_LEFT, GTK_SHADOW_NONE);
    gtk_box_pack_start(GTK_BOX(hbox), arrowLeft, TRUE, TRUE, 0);
    GtkWidget *arrowUp = gtk_arrow_new(GTK_ARROW_UP, GTK_SHADOW_NONE);
    gtk_box_pack_start(GTK_BOX(hbox), arrowUp, TRUE, TRUE, 0);
    GtkWidget *arrowDown = gtk_arrow_new(GTK_ARROW_DOWN, GTK_SHADOW_NONE);
    gtk_box_pack_start(GTK_BOX(hbox), arrowDown, TRUE, TRUE, 0);
    GtkWidget *arrowRight = gtk_arrow_new(GTK_ARROW_RIGHT, GTK_SHADOW_NONE);
    gtk_box_pack_start(GTK_BOX(hbox), arrowRight, TRUE, TRUE, 0);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
