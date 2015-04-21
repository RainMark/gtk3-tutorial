#include <gtk/gtk.h>

int main(int argc, char *argv[])
{    
    gtk_init(&argc, &argv);
    
    GtkWidget *colorselectiondialog = gtk_color_selection_dialog_new("ColorSelectionDialog");
    gtk_dialog_run(GTK_DIALOG(colorselectiondialog));
    gtk_widget_destroy(colorselectiondialog);
    
    return 0;
}
