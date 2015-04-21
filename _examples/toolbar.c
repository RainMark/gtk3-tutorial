#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{    
    gtk_init(&argc, &argv);
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 400, -1);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    GtkWidget *toolbar = gtk_toolbar_new();
    gtk_container_add(GTK_CONTAINER(window), toolbar);
    
    GtkToolItem *toolitem;
    GtkToolItem *separator;
    GSList *group;
    
    toolitem = gtk_tool_button_new_from_stock(GTK_STOCK_NEW);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolitem, 0);
    toolitem = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolitem, 1);
    separator = gtk_separator_tool_item_new();
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), separator, 2);
    toolitem = gtk_toggle_tool_button_new_from_stock(GTK_STOCK_MEDIA_PLAY);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolitem, 3);
    separator = gtk_separator_tool_item_new();
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), separator, 4);
    toolitem = gtk_menu_tool_button_new_from_stock(GTK_STOCK_GO_BACK);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolitem, 5);
    toolitem = gtk_menu_tool_button_new_from_stock(GTK_STOCK_GO_FORWARD);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolitem, 6);
    separator = gtk_separator_tool_item_new();
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), separator, 7);
    toolitem = gtk_radio_tool_button_new_from_stock(NULL, GTK_STOCK_ADD);
    group = gtk_radio_tool_button_get_group(GTK_RADIO_TOOL_BUTTON(toolitem));
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolitem, 8);
    toolitem = gtk_radio_tool_button_new_from_stock(group, GTK_STOCK_REMOVE);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolitem, 9);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
