#include <gtk/gtk.h>

GtkWidget *window;
GtkWidget *button;
GtkWidget *messagedialog;

static void on_button_clicked(GtkWidget *button, gchar* message)
{
    gchar *text = g_strdup_printf("MessageDialog displaying %s message", message);

    messagedialog = gtk_message_dialog_new(GTK_WINDOW(window), 0, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, text);

    gtk_dialog_run(GTK_DIALOG(messagedialog));
    gtk_widget_destroy(messagedialog);
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    button = gtk_button_new_with_label("Information");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), "information");
    gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(button), TRUE, TRUE, 0);
    button = gtk_button_new_with_label("Warning");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), "warning");
    gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(button), TRUE, TRUE, 0);
    button = gtk_button_new_with_label("Question");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), "question");
    gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(button), TRUE, TRUE, 0);
    button = gtk_button_new_with_label("Error");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), "error");
    gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(button), TRUE, TRUE, 0);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
