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
    
    GtkWidget *handlebox = gtk_handle_box_new();
    gtk_container_add(GTK_CONTAINER(window), handlebox);
    
    GtkWidget *toolbar = gtk_toolbar_new();
    gtk_widget_set_size_request(toolbar, 200, -1);
    gtk_container_add(GTK_CONTAINER(handlebox), toolbar);
    
    GtkToolItem *toolbuttonNew = gtk_tool_button_new_from_stock(GTK_STOCK_NEW);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolbuttonNew, 0);
    GtkToolItem *toolbuttonOpen = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolbuttonOpen, 1);
    GtkToolItem *toolbuttonSave = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolbuttonSave, 2);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
