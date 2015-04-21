#include <gtk/gtk.h>
#include <gdk/gdk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

static void statusicon_menu(GtkWidget *widget, GtkWidget *statusicon)
{
    GtkWidget *menu = gtk_menu_new();
    GtkWidget *menuitemQuit = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, NULL);
    g_signal_connect(menuitemQuit, "activate", G_CALLBACK(destroy), NULL);
    gtk_menu_append(GTK_MENU(menu), menuitemQuit);
    
    gtk_widget_show_all(menu);
    gtk_menu_popup(GTK_MENU(menu), NULL, NULL, NULL, gtk_status_icon_position_menu, GDK_RIGHTBUTTON, gtk_get_current_event_time());
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    GtkStatusIcon *statusicon = gtk_status_icon_new_from_stock(GTK_STOCK_HOME);
    gtk_status_icon_set_visible(GTK_STATUS_ICON(statusicon), TRUE);
    g_signal_connect(statusicon, "popup-menu", G_CALLBACK(statusicon_menu), statusicon);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
