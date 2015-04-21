#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{    
    gtk_init(&argc, &argv);
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), -1, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    GtkWidget *label;
    
    GtkWidget *hbox = gtk_hbox_new(TRUE, 5);
    gtk_container_add(GTK_CONTAINER(window), hbox);
    label = gtk_label_new("Label 1 packed in HBox");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, TRUE, 0);
    label = gtk_label_new("Label 2 packed in HBox");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, TRUE, 0);
    
    GtkWidget *vbox = gtk_vbox_new(TRUE, 5);
    gtk_box_pack_start(GTK_BOX(hbox), vbox, TRUE, TRUE, 0);
    label = gtk_label_new("Label 3 packed in VBox");
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);
    label = gtk_label_new("Label 4 packed in VBox");
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
