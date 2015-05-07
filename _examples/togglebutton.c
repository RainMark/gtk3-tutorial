#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

static void toggle_button_toggled(GtkWidget *checkbutton, gpointer data)
{
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkbutton)))
    {
        g_print("%s toggled on\n", gtk_button_get_label(GTK_BUTTON(checkbutton)));
    }
    else
    {
        g_print("%s toggled off\n", gtk_button_get_label(GTK_BUTTON(checkbutton)));
    }
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    GtkWidget *togglebutton;

    togglebutton = gtk_toggle_button_new_with_label("Toggle Button 1");
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(togglebutton), TRUE);
    g_signal_connect(togglebutton, "toggled", G_CALLBACK(toggle_button_toggled), NULL);
    gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(togglebutton), FALSE, FALSE, 0);

    togglebutton = gtk_toggle_button_new_with_label("Toggle Button 2");
    g_signal_connect(togglebutton, "toggled", G_CALLBACK(toggle_button_toggled), NULL);
    gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(togglebutton), FALSE, FALSE, 0);

    togglebutton = gtk_toggle_button_new_with_label("Toggle Button 3");
    g_signal_connect(togglebutton, "toggled", G_CALLBACK(toggle_button_toggled), NULL);
    gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(togglebutton), FALSE, FALSE, 0);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
