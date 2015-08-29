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

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    GtkWidget *button = gtk_button_new_with_label("Button");
    gtk_widget_set_tooltip_text(GTK_WIDGET(button), "Button with basic Tooltip");
    gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, TRUE, 0);
    GtkWidget *label = gtk_label_new("Label");
    gtk_widget_set_tooltip_text(GTK_WIDGET(label), "Label with basic Tooltip");
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);
    GtkWidget *entry = gtk_entry_new();
    gtk_widget_set_tooltip_text(GTK_WIDGET(entry), "Entry with basic Tooltip");
    gtk_box_pack_start(GTK_BOX(vbox), entry, TRUE, TRUE, 0);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
