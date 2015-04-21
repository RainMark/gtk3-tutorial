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
    
    GtkWidget *table = gtk_table_new(3, 3, FALSE);
    gtk_container_add(GTK_CONTAINER(window), table);
    
    GtkWidget *button1 = gtk_button_new_with_label("Button 1");
    gtk_table_attach(GTK_TABLE(table), button1, 0, 1, 0, 1, GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL, 0, 0);
    GtkWidget *button2 = gtk_button_new_with_label("Button 2");
    gtk_table_attach(GTK_TABLE(table), button2, 1, 3, 0, 1, GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL, 0, 0);
    GtkWidget *button3 = gtk_button_new_with_label("Button 3");
    gtk_table_attach(GTK_TABLE(table), button3, 0, 1, 1, 3, GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL, 0, 0);
    GtkWidget *button4 = gtk_button_new_with_label("Button 4");
    gtk_table_attach(GTK_TABLE(table), button4, 1, 3, 1, 2, GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL, 0, 0);
    GtkWidget *button5 = gtk_button_new_with_label("Button 5");
    gtk_table_attach(GTK_TABLE(table), button5, 1, 2, 2, 3, GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL, 0, 0);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
