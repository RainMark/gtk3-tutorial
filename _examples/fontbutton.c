#include <gtk/gtk.h>
#include <gdk/gdk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

static void font_selected(GtkWidget *fontbutton, gpointer data)
{
    g_print("%s\n", gtk_font_button_get_font_name(GTK_FONT_BUTTON(fontbutton)));
}

int main(int argc, char *argv[])
{    
    gtk_init(&argc, &argv);
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    GtkWidget *fontbutton = gtk_font_button_new();
    g_signal_connect(fontbutton, "font-set", G_CALLBACK(font_selected), NULL);
    gtk_container_add(GTK_CONTAINER(window), fontbutton);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
