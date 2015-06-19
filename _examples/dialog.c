#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    int response;

    GtkWidget *dialog = gtk_dialog_new();
    gtk_window_set_title(GTK_WINDOW(dialog), "Dialog Example");
    gtk_window_set_default_size(GTK_WINDOW(dialog), 200, 200);
    gtk_dialog_add_button(GTK_DIALOG(dialog), "_Reject", GTK_RESPONSE_REJECT);
    gtk_dialog_add_button(GTK_DIALOG(dialog), "_Accept", GTK_RESPONSE_ACCEPT);
    response = gtk_dialog_run(GTK_DIALOG(dialog));

    if (response == -2)
        printf("Reject button clicked!\n");
    else if (response == -3)
        printf("Accept button clicked!\n");

    gtk_widget_destroy(dialog);

    return 0;
}
