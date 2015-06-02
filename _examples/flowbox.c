#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *flowbox;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

    flowbox = gtk_flow_box_new();
    gtk_container_add(GTK_CONTAINER(window), flowbox);

    GtkWidget *button = gtk_button_new_with_label("Child 1");
    gtk_flow_box_insert(GTK_FLOW_BOX(flowbox), button, 0);

    GtkWidget *label = gtk_label_new("Child 2");
    gtk_flow_box_insert(GTK_FLOW_BOX(flowbox), label, 1);

    GtkWidget *checkbutton = gtk_check_button_new_with_label("Child 3");
    gtk_flow_box_insert(GTK_FLOW_BOX(flowbox), checkbutton, 2);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
