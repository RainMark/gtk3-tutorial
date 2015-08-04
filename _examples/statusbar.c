#include <gtk/gtk.h>
#include <glib.h>
#include <stdlib.h>

GtkWidget *statusbar;

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

static void push_button_clicked(GtkWidget *widget, gpointer data)
{
    static int count = 1;
    gchar *buffer;

    buffer = g_strdup_printf("Item %d", count++);
    gtk_statusbar_push(GTK_STATUSBAR(statusbar), GPOINTER_TO_INT(data), buffer);
    g_free(buffer);
}

static void pop_button_clicked(GtkWidget *widget, gpointer data)
{
    gtk_statusbar_pop(GTK_STATUSBAR(statusbar), GPOINTER_TO_INT(data));
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    statusbar = gtk_statusbar_new();
    gtk_box_pack_end(GTK_BOX(vbox), statusbar, FALSE, TRUE, 0);
    gint context_id = gtk_statusbar_get_context_id(GTK_STATUSBAR(statusbar), "Statusbar example");

    GtkWidget *buttonPush = gtk_button_new_with_label("Push message");
    gtk_box_pack_start(GTK_BOX(vbox), buttonPush, FALSE, TRUE, 0);
    g_signal_connect(buttonPush, "clicked", G_CALLBACK(push_button_clicked), GINT_TO_POINTER (context_id));
    GtkWidget *buttonPop = gtk_button_new_with_label("Pop message");
    gtk_box_pack_start(GTK_BOX(vbox), buttonPop, FALSE, TRUE, 0);
    g_signal_connect(buttonPop, "clicked", G_CALLBACK(pop_button_clicked), GINT_TO_POINTER (context_id));

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
