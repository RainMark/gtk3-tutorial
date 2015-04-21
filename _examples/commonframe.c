#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{    
    gtk_init(&argc, &argv);
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), -1, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    GtkWidget *frame = gtk_frame_new(NULL);
    gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_NONE);
    gtk_container_add(GTK_CONTAINER(window), frame);
    
    GtkWidget *label1 = gtk_label_new("<b>Common Frame</b>");
    gtk_label_set_use_markup(GTK_LABEL(label1), TRUE);
    gtk_frame_set_label_widget(GTK_FRAME(frame), label1);
    
    GtkWidget *alignment = gtk_alignment_new(0.5, 0.5, 1.0, 1.0);
    gtk_alignment_set_padding(GTK_ALIGNMENT(alignment), 5, 0, 12, 0);
    gtk_container_add(GTK_CONTAINER(frame), alignment);
    
    GtkWidget *label2 = gtk_label_new("Label inside a Common Frame");
    gtk_container_add(GTK_CONTAINER(alignment), label2);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
