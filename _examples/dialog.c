#include <gtk/gtk.h>

int main(int argc, char *argv[])
{    
    gtk_init(&argc, &argv);
    
    GtkWidget *dialog = gtk_dialog_new_with_buttons("Dialog", NULL, 0, GTK_STOCK_OK, GTK_RESPONSE_OK);
    gtk_window_set_default_size(GTK_WINDOW(dialog), 250, 300);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    
    return 0;
}
