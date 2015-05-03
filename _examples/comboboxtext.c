#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

static void combobox_changed(GtkWidget *combobox, gpointer data)
{
    const char *text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(combobox));
    printf("%s\n", text);
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    GtkWidget *combobox = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combobox), "Oak");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combobox), "Birch");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combobox), "Sycamore");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combobox), "Willow");
    gtk_combo_box_set_active(GTK_COMBO_BOX(combobox), 0);
    g_signal_connect(combobox, "changed", G_CALLBACK(combobox_changed), NULL);
    gtk_container_add(GTK_CONTAINER(window), combobox);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
