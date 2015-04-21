#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 200, -1);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    GtkWidget *vbox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    
    GtkWidget *menubar = gtk_menu_bar_new();
    gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);
    
    GtkWidget *toolbar = gtk_toolbar_new();
    gtk_box_pack_start(GTK_BOX(vbox), toolbar, FALSE, FALSE, 0);

    GtkActionGroup *actiongroup = gtk_action_group_new("ActionGroup");
    
    GtkAction *action;
    
    action = gtk_action_new("actionFile", "_File", NULL, NULL);
    gtk_action_group_add_action(GTK_ACTION_GROUP(actiongroup), action);
    GtkWidget *menuitemFile = gtk_action_create_menu_item(GTK_ACTION(action));
    gtk_menu_bar_append(GTK_MENU_BAR(menubar), menuitemFile);
    
    GtkWidget *menu = gtk_menu_new();
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuitemFile), menu);
        
    action = gtk_action_new("actionNew", "_New", "Create a new document", GTK_STOCK_NEW);
    gtk_action_group_add_action(GTK_ACTION_GROUP(actiongroup), action);
    GtkWidget *menuitemNew = gtk_action_create_menu_item(GTK_ACTION(action));
    gtk_menu_append(GTK_MENU(menu), menuitemNew);
    GtkToolItem *toolitemNew = gtk_action_create_tool_item(GTK_ACTION(action));
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolitemNew, 0);
    
    action = gtk_action_new("actionOpen", "_Open", "Open a file", GTK_STOCK_OPEN);
    gtk_action_group_add_action(GTK_ACTION_GROUP(actiongroup), action);
    GtkWidget *menuitemOpen = gtk_action_create_menu_item(GTK_ACTION(action));
    gtk_menu_append(GTK_MENU(menu), menuitemOpen);
    GtkToolItem *toolitemOpen = gtk_action_create_tool_item(GTK_ACTION(action));
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolitemOpen, 1);
    
    action = gtk_action_new("actionSave", "_Save", "Save the current file", GTK_STOCK_SAVE);
    gtk_action_group_add_action(GTK_ACTION_GROUP(actiongroup), action);
    GtkWidget *menuitemSave = gtk_action_create_menu_item(GTK_ACTION(action));
    gtk_menu_append(GTK_MENU(menu), menuitemSave);
    GtkToolItem *toolitemSave = gtk_action_create_tool_item(GTK_ACTION(action));
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), toolitemSave, 2);

    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
