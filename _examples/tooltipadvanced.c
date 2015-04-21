#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

static gboolean on_query_tooltip(GtkWidget *widget,
                                 gint x, gint y,
                                 gboolean keyboard_tip,
                                 GtkTooltip *tooltip,
                                 gpointer data)
{
    gtk_tooltip_set_text(GTK_TOOLTIP(tooltip), data);
    
    return TRUE;
}

int main(int argc, char *argv[])
{    
    gtk_init(&argc, &argv);
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    GtkWidget *vbox = gtk_vbox_new(TRUE, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    
    GtkWidget *button = gtk_button_new_with_label("Button");
    gtk_widget_set_has_tooltip(GTK_WIDGET(button), TRUE);
    g_signal_connect(button, "query-tooltip", G_CALLBACK(on_query_tooltip), "Button with advanced Tooltip");
    gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, TRUE, 0);
    
    GtkWidget *label = gtk_label_new("Label");
    gtk_widget_set_has_tooltip(GTK_WIDGET(label), TRUE);
    g_signal_connect(label, "query-tooltip", G_CALLBACK(on_query_tooltip), "Label with advanced Tooltip");
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);
    
    GtkWidget *entry = gtk_entry_new();
    gtk_widget_set_has_tooltip(GTK_WIDGET(entry), TRUE);
    g_signal_connect(entry, "query-tooltip", G_CALLBACK(on_query_tooltip), "Entry with advanced Tooltip");
    gtk_box_pack_start(GTK_BOX(vbox), entry, TRUE, TRUE, 0);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
