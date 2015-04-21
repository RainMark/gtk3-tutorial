#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

static void button_clicked(GtkWidget *button, gpointer data)
{
    g_print("Button clicked\n");
}

int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *button;
    
    gtk_init(&argc, &argv);
    
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    button = gtk_button_new_with_label("Button");
    g_signal_connect(GTK_BUTTON(button), "clicked", G_CALLBACK(button_clicked), NULL);
    gtk_container_add(GTK_CONTAINER(window), button);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
