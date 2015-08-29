#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    GtkWidget *assistant = gtk_assistant_new();
    gtk_window_set_default_size(GTK_WINDOW(assistant), 450, -1);
    g_signal_connect(assistant, "cancel", G_CALLBACK(destroy), NULL);
    g_signal_connect(assistant, "close", G_CALLBACK(destroy), NULL);
    g_signal_connect(assistant, "apply", G_CALLBACK(destroy), NULL);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    GtkWidget *label = gtk_label_new("The first page of an Assistant widget is the intro page, which is used to display information about what the Assistant will do.\n\nThe page contains two buttons, a Forward to continue on to the next page and Cancel close the dialog.");
    gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_LEFT);
    gtk_label_set_line_wrap(GTK_LABEL(label), GTK_WRAP_WORD);
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 5);
    gtk_assistant_append_page(GTK_ASSISTANT(assistant), vbox);
    gtk_assistant_set_page_title(GTK_ASSISTANT(assistant), vbox, ("Page 1: Starting Out"));
    gtk_assistant_set_page_type(GTK_ASSISTANT(assistant), vbox, GTK_ASSISTANT_PAGE_INTRO);
    gtk_assistant_set_page_complete(GTK_ASSISTANT(assistant), vbox, TRUE);

    GtkWidget *vbox1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    GtkWidget *label1 = gtk_label_new("After the intro page, the content page is then displayed in the assistant. Usually this consists of labels, entries, buttons, etc. to allow the user to configure the application.\n\nThe assistant can contain as many content pages as necessary.\n\nContent pages have three buttons, a Back button, a Forward button continue on through the Assistant and a Cancel button to exit.");
    gtk_label_set_justify(GTK_LABEL(label1), GTK_JUSTIFY_LEFT);
    gtk_label_set_line_wrap(GTK_LABEL(label1), GTK_WRAP_WORD);
    gtk_box_pack_start(GTK_BOX(vbox1), label1, TRUE, TRUE, 5);
    gtk_assistant_append_page(GTK_ASSISTANT(assistant), vbox1);
    gtk_assistant_set_page_title(GTK_ASSISTANT(assistant), vbox1, ("Page 2: Moving On..."));
    gtk_assistant_set_page_type(GTK_ASSISTANT(assistant), vbox1, GTK_ASSISTANT_PAGE_CONTENT);
    gtk_assistant_set_page_complete(GTK_ASSISTANT(assistant), vbox1, TRUE);

    GtkWidget *vbox2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    GtkWidget *label2 = gtk_label_new("The Confirm page can be set as the final one in the Assistant and is used to check whether the user really wants to confirm the settings they have specified.\n\nIt also contains a Back and Cancel button, however also includes an Apply button to confirm the changes.");
    gtk_label_set_justify(GTK_LABEL(label2), GTK_JUSTIFY_LEFT);
    gtk_label_set_line_wrap(GTK_LABEL(label2), GTK_WRAP_WORD);
    gtk_box_pack_start(GTK_BOX(vbox2), label2, TRUE, TRUE, 5);
    gtk_assistant_append_page(GTK_ASSISTANT(assistant), vbox2);
    gtk_assistant_set_page_title(GTK_ASSISTANT(assistant), vbox2, ("Page 3: The Finale"));
    gtk_assistant_set_page_type(GTK_ASSISTANT(assistant), vbox2, GTK_ASSISTANT_PAGE_CONFIRM);
    gtk_assistant_set_page_complete(GTK_ASSISTANT(assistant), vbox2, TRUE);

    gtk_widget_show_all(assistant);

    gtk_main();

    return 0;
}
