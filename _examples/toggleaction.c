#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    GtkWidget *menubar = gtk_menu_bar_new();
    gtk_container_add(GTK_CONTAINER(window), menubar);

    GtkActionGroup *actiongroup = gtk_action_group_new("ActionGroup");
    
    GtkAction *action = gtk_action_new("actionFile", "_File", NULL, NULL);
    gtk_action_group_add_action(GTK_ACTION_GROUP(actiongroup), action);
    GtkWidget *menuitemFile = gtk_action_create_menu_item(GTK_ACTION(action));
    gtk_menu_bar_append(GTK_MENU_BAR(menubar), menuitemFile);
    
    GtkWidget *menu = gtk_menu_new();
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuitemFile), menu);
    
    GtkToggleAction *toggleaction;
    
    toggleaction = gtk_toggle_action_new("actionNew", "_New", "Create a new document", GTK_STOCK_NEW);
    gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(toggleaction), TRUE);
    gtk_action_group_add_action(GTK_ACTION_GROUP(actiongroup), GTK_ACTION(toggleaction));
    GtkWidget *menuitemNew = gtk_action_create_menu_item(GTK_ACTION(toggleaction));
    gtk_menu_append(GTK_MENU(menu), menuitemNew);
    toggleaction = gtk_toggle_action_new("actionOpen", "_Open", "Open a file", GTK_STOCK_OPEN);
    gtk_action_group_add_action(GTK_ACTION_GROUP(actiongroup), GTK_ACTION(toggleaction));
    GtkWidget *menuitemOpen = gtk_action_create_menu_item(GTK_ACTION(toggleaction));
    gtk_menu_append(GTK_MENU(menu), menuitemOpen);
    toggleaction = gtk_toggle_action_new("actionSave", "_Save", "Save a file", GTK_STOCK_SAVE);
    gtk_action_group_add_action(GTK_ACTION_GROUP(actiongroup), GTK_ACTION(toggleaction));
    GtkWidget *menuitemSave = gtk_action_create_menu_item(GTK_ACTION(toggleaction));
    gtk_menu_append(GTK_MENU(menu), menuitemSave);

    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
