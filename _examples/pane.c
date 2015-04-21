#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{    
    gtk_init(&argc, &argv);
    
    GtkWidget *label;
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    GtkWidget *hbox = gtk_hbox_new(TRUE, 5);
    gtk_container_add(GTK_CONTAINER(window), hbox);
    
    GtkWidget *hpane = gtk_hpaned_new();
    gtk_box_pack_start(GTK_BOX(hbox), hpane, TRUE, TRUE, 0);
    
    label = gtk_label_new("Label 1");
    gtk_paned_add1(GTK_PANED(hpane), label);
    label = gtk_label_new("Label 2");
    gtk_paned_add2(GTK_PANED(hpane), label);
    
    GtkWidget *vpane = gtk_vpaned_new();
    gtk_box_pack_start(GTK_BOX(hbox), vpane, TRUE, TRUE, 0);
    
    label = gtk_label_new("Label 1");
    gtk_paned_add1(GTK_PANED(vpane), label);
    label = gtk_label_new("Label 2");
    gtk_paned_add2(GTK_PANED(vpane), label);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
