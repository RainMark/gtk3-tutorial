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
    
    GtkWidget *table = gtk_table_new(2, 2, FALSE);
    gtk_container_add(GTK_CONTAINER(window), table);
    
    GtkWidget *layout = gtk_layout_new(NULL, NULL);
    gtk_layout_set_size(GTK_LAYOUT(layout), 2000, 800);
    gtk_table_attach(GTK_TABLE(table), layout, 0, 1, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
    GtkAdjustment *vadjustment = gtk_layout_get_vadjustment(GTK_LAYOUT(layout));
    GtkAdjustment *hadjustment = gtk_layout_get_hadjustment(GTK_LAYOUT(layout));
    
    GtkWidget *vscrollbar = gtk_vscrollbar_new(vadjustment);
    gtk_table_attach(GTK_TABLE(table), vscrollbar, 1, 2, 0, 1, GTK_SHRINK, GTK_FILL | GTK_EXPAND, 0, 0);
    
    GtkWidget *hscrollbar = gtk_hscrollbar_new(hadjustment);
    gtk_table_attach(GTK_TABLE(table), hscrollbar, 0, 1, 1, 2, GTK_EXPAND | GTK_FILL, GTK_SHRINK, 0, 0);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}