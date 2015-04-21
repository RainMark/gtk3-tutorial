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
    
    GtkWidget *menubar = gtk_menu_bar_new();
    gtk_container_add(GTK_CONTAINER(window), menubar);
    
    GtkWidget *menuitem = gtk_menu_item_new_with_label("Recent Documents");
    gtk_menu_bar_append(GTK_MENU_BAR(menubar), menuitem);
    
    GtkWidget *recentchoosermenu = gtk_recent_chooser_menu_new();
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuitem), recentchoosermenu);
        
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
