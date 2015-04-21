#include <gtk/gtk.h>

int main(int argc, char *argv[])
{    
    gtk_init(&argc, &argv);
    
    GtkWidget *filechooserdialog = gtk_file_chooser_dialog_new("FileChooserDialog", NULL, GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN, GTK_RESPONSE_OK, NULL);
    gtk_dialog_run(GTK_DIALOG(filechooserdialog));
    g_print("Selected file: %s", gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(filechooserdialog)));
    gtk_widget_destroy(filechooserdialog);
    
    return 0;
}
