#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

static void scale_adjustment(GtkWidget *widget, gpointer data)
{
    double value = gtk_range_get_value(GTK_RANGE(widget));
    printf("Adjustment value: %f\n", value);
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

    GtkWidget *box = gtk_box_new(TRUE, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    GtkAdjustment *hadjustment = gtk_adjustment_new(50, 0, 100, 1, 10, 0);
    GtkWidget *hscale = gtk_scale_new(GTK_ORIENTATION_HORIZONTAL, GTK_ADJUSTMENT(hadjustment));
    g_signal_connect(hscale, "value-changed", G_CALLBACK(scale_adjustment), NULL);
    gtk_box_pack_start(GTK_BOX(box), hscale, TRUE, TRUE, 0);

    GtkAdjustment *vadjustment = gtk_adjustment_new(30, 0, 100, 1, 10, 0);
    GtkWidget *vscale = gtk_scale_new(GTK_ORIENTATION_VERTICAL, GTK_ADJUSTMENT(vadjustment));
    gtk_scale_set_digits(GTK_SCALE(vscale), 0);
    g_signal_connect(vscale, "value-changed", G_CALLBACK(scale_adjustment), NULL);
    gtk_box_pack_start(GTK_BOX(box), vscale, TRUE, TRUE, 0);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
