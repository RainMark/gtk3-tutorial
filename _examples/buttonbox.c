#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    GtkWidget *buttonbox;
    GtkWidget *button;

    buttonbox = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_box_set_spacing(GTK_BOX(buttonbox), 5);
    gtk_box_pack_start(GTK_BOX(box), buttonbox, TRUE, TRUE, 0);
    button = gtk_button_new_with_label("Button 1");
    gtk_container_add(GTK_CONTAINER(buttonbox), button);
    button = gtk_button_new_with_label("Button 2");
    gtk_container_add(GTK_CONTAINER(buttonbox), button);
    button = gtk_button_new_with_label("Button 3");
    gtk_container_add(GTK_CONTAINER(buttonbox), button);

    buttonbox = gtk_button_box_new(GTK_ORIENTATION_VERTICAL);
    gtk_box_set_spacing(GTK_BOX(buttonbox), 10);
    gtk_box_pack_start(GTK_BOX(box), buttonbox, TRUE, TRUE, 0);
    button = gtk_button_new_with_label("Button 1");
    gtk_container_add(GTK_CONTAINER(buttonbox), button);
    button = gtk_button_new_with_label("Button 2");
    gtk_container_add(GTK_CONTAINER(buttonbox), button);
    button = gtk_button_new_with_label("Button 3");
    gtk_container_add(GTK_CONTAINER(buttonbox), button);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
