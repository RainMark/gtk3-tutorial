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
    
    GtkWidget *hbox = gtk_hbox_new(TRUE, 5);
    gtk_container_add(GTK_CONTAINER(window), hbox);
    
    GtkWidget *button;
    
    GtkWidget *hbuttonbox = gtk_hbutton_box_new();
    gtk_box_pack_start(GTK_BOX(hbox), hbuttonbox, TRUE, TRUE, 0);
    button = gtk_button_new_with_label("Button 1");
    gtk_container_add(GTK_CONTAINER(hbuttonbox), button);
    button = gtk_button_new_with_label("Button 2");
    gtk_container_add(GTK_CONTAINER(hbuttonbox), button);
    button = gtk_button_new_with_label("Button 3");
    gtk_container_add(GTK_CONTAINER(hbuttonbox), button);
    
    GtkWidget *vbuttonbox = gtk_vbutton_box_new();
    gtk_box_pack_start(GTK_BOX(hbox), vbuttonbox, TRUE, TRUE, 0);
    button = gtk_button_new_with_label("Button 1");
    gtk_container_add(GTK_CONTAINER(vbuttonbox), button);
    button = gtk_button_new_with_label("Button 2");
    gtk_container_add(GTK_CONTAINER(vbuttonbox), button);
    button = gtk_button_new_with_label("Button 3");
    gtk_container_add(GTK_CONTAINER(vbuttonbox), button);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
