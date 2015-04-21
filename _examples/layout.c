#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{    
    gtk_init(&argc, &argv);
    
    GtkWidget *button;
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    GtkWidget *layout = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(window), layout);
    
    button = gtk_button_new_with_label("Button 1");
    gtk_layout_put(GTK_LAYOUT(layout), button, 100, 120);
    button = gtk_button_new_with_label("Button 2");
    gtk_layout_put(GTK_LAYOUT(layout), button, 220, 50);
    button = gtk_button_new_with_label("Button 3");
    gtk_layout_put(GTK_LAYOUT(layout), button, 40, 35);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
