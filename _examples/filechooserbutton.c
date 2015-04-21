#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

static void file_selected(GtkWidget *filechooserbutton, gpointer data)
{
    g_print("Selected file: %s", gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(filechooserbutton)));
}

int main(int argc, char *argv[])
{    
    gtk_init(&argc, &argv);
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 200, -1);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    GtkWidget *filechooserbutton = gtk_file_chooser_button_new("FileChooserButton",
                                                               GTK_FILE_CHOOSER_ACTION_OPEN);
    g_signal_connect(filechooserbutton, "file-set", G_CALLBACK(file_selected), NULL);
    gtk_container_add(GTK_CONTAINER(window), filechooserbutton);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
