#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{    
    gtk_init(&argc, &argv);
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    GtkWidget *vbox = gtk_vbox_new(TRUE, 2);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    GtkSizeGroup *sizegroup = gtk_size_group_new(GTK_SIZE_GROUP_BOTH);

    GtkWidget *button1 = gtk_button_new_with_label("Button 1");
    gtk_size_group_add_widget(GTK_SIZE_GROUP(sizegroup), button1);
    gtk_box_pack_start(GTK_BOX(vbox), button1, TRUE, TRUE, 0);
    GtkWidget *button2 = gtk_button_new_with_label("Button 2");
    gtk_size_group_add_widget(GTK_SIZE_GROUP(sizegroup), button2);
    gtk_box_pack_start(GTK_BOX(vbox), button2, TRUE, TRUE, 0);
    GtkWidget *button3 = gtk_button_new_with_label("Button 3");
    gtk_size_group_add_widget(GTK_SIZE_GROUP(sizegroup), button3);
    gtk_box_pack_start(GTK_BOX(vbox), button3, TRUE, TRUE, 0);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
