#include <gtk/gtk.h>

int main(int argc, char *argv[])
{    
    gtk_init(&argc, &argv);
    
    GtkWidget *fontselectiondialog = gtk_font_selection_dialog_new("FontSelectionDialog");
    gtk_dialog_run(GTK_DIALOG(fontselectiondialog));
    g_print("%s\n", gtk_font_selection_dialog_get_font_name(GTK_FONT_SELECTION_DIALOG(fontselectiondialog)));
    gtk_widget_destroy(fontselectiondialog);
    
    return 0;
}
