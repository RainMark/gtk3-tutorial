#include <gtk/gtk.h>
#include <glib.h>
#include <stdlib.h>

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
    
    GtkWidget *notebook = gtk_notebook_new();
    gtk_container_add(GTK_CONTAINER(window), notebook);

    int count;
    gchar *text;
    
    for (count = 1; count <= 5; count++)
    {
        GtkWidget *vbox = gtk_vbox_new(FALSE, 5);
        text = g_strdup_printf("Page %d", count);
        GtkWidget *label = gtk_label_new(text);
        
        gtk_notebook_append_page(GTK_NOTEBOOK(notebook), vbox, label);
    }
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
