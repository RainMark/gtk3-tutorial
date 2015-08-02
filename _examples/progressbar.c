#include <gtk/gtk.h>

typedef struct _ProgressData {
    GtkWidget *progressbar;
    int timer;
    gboolean activity_mode;
} ProgressData;

static gboolean progress_timeout(gpointer data)
{
    ProgressData *progressdata = (ProgressData *)data;
    gdouble new_val;

    if (progressdata->activity_mode)
        gtk_progress_bar_pulse(GTK_PROGRESS_BAR(progressdata->progressbar));
    else
    {
        new_val = gtk_progress_bar_get_fraction(GTK_PROGRESS_BAR(progressdata->progressbar)) + 0.1;

        if (new_val > 1.0)
            new_val = 0.0;

        gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR (progressdata->progressbar), new_val);
    }

    return TRUE;
}

static void toggle_show_text(GtkWidget *widget, ProgressData *progressdata)
{
    if (gtk_progress_bar_get_text(GTK_PROGRESS_BAR (progressdata->progressbar)))
        gtk_progress_bar_set_text(GTK_PROGRESS_BAR (progressdata->progressbar), "");
    else
        gtk_progress_bar_set_text(GTK_PROGRESS_BAR (progressdata->progressbar), "Text");
}

static void toggle_activity_mode(GtkWidget *widget, ProgressData *progressdata)
{
    progressdata->activity_mode = !progressdata->activity_mode;

    if (progressdata->activity_mode)
        gtk_progress_bar_pulse(GTK_PROGRESS_BAR (progressdata->progressbar));
    else
        gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR (progressdata->progressbar), 0.0);
}

static void destroy_progress(GtkWidget *widget, ProgressData *progressdata)
{
    g_source_remove(progressdata->timer);
    progressdata->timer = 0;
    g_free(progressdata);
    gtk_main_quit();
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    ProgressData *progressdata;
    GtkWidget *checkbutton;

    progressdata = g_malloc(sizeof(ProgressData));

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK (destroy_progress), (gpointer) progressdata);
    gtk_container_set_border_width (GTK_CONTAINER (window), 0);

    GtkWidget *vbox = gtk_vbox_new(FALSE, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    progressdata->activity_mode = FALSE;

    progressdata->progressbar = gtk_progress_bar_new();
    gtk_box_pack_start(GTK_BOX(vbox), progressdata->progressbar, TRUE, FALSE, 0);

    checkbutton = gtk_check_button_new_with_label("Display text");
    g_signal_connect(checkbutton, "clicked", G_CALLBACK(toggle_show_text), progressdata);
    gtk_box_pack_start(GTK_BOX(vbox), checkbutton, TRUE, FALSE, 0);

    checkbutton = gtk_check_button_new_with_label("Activity mode");
    g_signal_connect(checkbutton, "clicked", G_CALLBACK(toggle_activity_mode), progressdata);
    gtk_box_pack_start(GTK_BOX(vbox), checkbutton, TRUE, FALSE, 0);

    gtk_widget_show_all(window);

    progressdata->timer = g_timeout_add(1000, progress_timeout, progressdata);

    gtk_main();

    return 0;
}
