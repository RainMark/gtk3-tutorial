#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

    GtkWidget *label = gtk_label_new("This is an example Label");
    gtk_container_add(GTK_CONTAINER(window), label);

    const char *text = gtk_label_get_text(GTK_LABEL(label));
    printf("%s\n", text);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
