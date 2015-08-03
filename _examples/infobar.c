#include <gtk/gtk.h>

GtkWidget *infobar;
GtkWidget *label;

static void button_clicked(GtkWidget *button, gchar* message)
{
    gchar *text = g_strdup_printf("InfoBar displaying %s message", message);
    gtk_label_set_text(GTK_LABEL(label), text);

    if (message == "information")
        gtk_info_bar_set_message_type(GTK_INFO_BAR(infobar), GTK_MESSAGE_INFO);
    else if (message == "warning")
        gtk_info_bar_set_message_type(GTK_INFO_BAR(infobar), GTK_MESSAGE_WARNING);
    else if (message == "question")
        gtk_info_bar_set_message_type(GTK_INFO_BAR(infobar), GTK_MESSAGE_QUESTION);
    else if (message == "error")
        gtk_info_bar_set_message_type(GTK_INFO_BAR(infobar), GTK_MESSAGE_ERROR);

    gtk_widget_show(GTK_WIDGET(infobar));
}

int main(int argc, char *argv[])
{
    GtkWidget *button;
    GtkWidget *content_area;

    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    infobar = gtk_info_bar_new();
    gtk_info_bar_add_button(GTK_INFO_BAR(infobar), "Close", GTK_RESPONSE_OK);
    g_signal_connect(infobar, "response", G_CALLBACK(gtk_widget_hide), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), infobar, TRUE, TRUE, 0);
    label = gtk_label_new("InfoBar displaying information message");
    content_area = gtk_info_bar_get_content_area(GTK_INFO_BAR(infobar));
    gtk_box_pack_start(GTK_BOX(content_area), label, TRUE, TRUE, 0);

    GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_end(GTK_BOX(vbox), hbox, FALSE, TRUE, 0);

    button = gtk_button_new_with_label("Information");
    g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), "information");
    gtk_box_pack_start(GTK_BOX(hbox), button, TRUE, TRUE, 0);
    button = gtk_button_new_with_label("Warning");
    g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), "warning");
    gtk_box_pack_start(GTK_BOX(hbox), button, TRUE, TRUE, 0);
    button = gtk_button_new_with_label("Question");
    g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), "question");
    gtk_box_pack_start(GTK_BOX(hbox), button, TRUE, TRUE, 0);
    button = gtk_button_new_with_label("Error");
    g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), "error");
    gtk_box_pack_start(GTK_BOX(hbox), button, TRUE, TRUE, 0);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
