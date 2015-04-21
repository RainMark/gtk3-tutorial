#include <gtk/gtk.h>

int main(int argc, char *argv[])
{    
    gtk_init(&argc, &argv);
    
    GtkWidget *recentchooserdialog = gtk_recent_chooser_dialog_new("RecentChooserDialog", NULL, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN, GTK_RESPONSE_OK, NULL);
    gtk_dialog_run(GTK_DIALOG(recentchooserdialog));
    gtk_widget_destroy(recentchooserdialog);
    
    return 0;
}
