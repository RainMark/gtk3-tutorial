#include <gtk/gtk.h>

GtkWidget *switch1;

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

static void switch_toggled(GtkWidget *widget)
{
    if (gtk_switch_get_active(GTK_SWITCH(switch1)))
        printf("Switch toggled on\n");
    else
        printf("Switch toggled off\n");
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

    switch1 = gtk_switch_new();
    g_signal_connect(switch1, "notify::active", G_CALLBACK(switch_toggled), NULL);
    gtk_container_add(GTK_CONTAINER(window), switch1);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
