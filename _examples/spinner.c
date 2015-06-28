#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

static void start_spinner(GtkWidget *button, GtkWidget *spinner)
{
    gtk_spinner_start(GTK_SPINNER(spinner));
}

static void stop_spinner(GtkWidget *button, GtkWidget *spinner)
{
    gtk_spinner_stop(GTK_SPINNER(spinner));
}

int main(int argc, char *argv[])
{
    GtkWidget *window;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    GtkWidget *spinner = gtk_spinner_new();
    gtk_widget_set_hexpand(GTK_WIDGET(spinner), TRUE);
    gtk_widget_set_vexpand(GTK_WIDGET(spinner), TRUE);
    gtk_grid_attach(GTK_GRID(grid), spinner, 0, 0, 2, 1);

    GtkWidget *buttonStart = gtk_button_new_with_label("Start");
    g_signal_connect(buttonStart, "clicked", G_CALLBACK(start_spinner), spinner);
    gtk_grid_attach(GTK_GRID(grid), buttonStart, 0, 1, 1, 1);
    GtkWidget *buttonStop = gtk_button_new_with_label("Stop");
    g_signal_connect(buttonStop, "clicked", G_CALLBACK(stop_spinner), spinner);
    gtk_grid_attach(GTK_GRID(grid), buttonStop, 1, 1, 1, 1);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
