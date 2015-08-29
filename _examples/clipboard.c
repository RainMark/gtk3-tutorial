#include <gtk/gtk.h>
#include <gdk/gdk.h>

GtkWidget *entry;

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

static void on_cut_text(GtkWidget *button, gpointer data)
{
    GtkClipboard *clip = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
    const gchar *text = gtk_entry_get_text(GTK_ENTRY(entry));
    gtk_clipboard_set_text(clip, text, -1);
    gtk_entry_set_text(GTK_ENTRY(entry), "");
}

static void on_copy_text(GtkWidget *button, gpointer data)
{
    GtkClipboard *clip = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
    const gchar *text = gtk_entry_get_text(GTK_ENTRY(entry));
    gtk_clipboard_set_text(clip, text, -1);
}

static void on_paste_text(GtkWidget *button, gpointer data)
{
    gchar *text = gtk_clipboard_wait_for_text(gtk_clipboard_get(GDK_SELECTION_CLIPBOARD));
    gtk_entry_set_text(GTK_ENTRY(entry), text);
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

    GtkWidget *box1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_container_add(GTK_CONTAINER(window), box1);
    entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(box1), entry, FALSE, FALSE, 0);

    GtkWidget *box2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(box1), box2, FALSE, FALSE, 0);

    GtkWidget *button;

    button = gtk_button_new_with_label("_Cut");
    gtk_button_set_use_underline(GTK_BUTTON(button), TRUE);
    g_signal_connect(button, "clicked", G_CALLBACK(on_cut_text), NULL);
    gtk_box_pack_start(GTK_BOX(box2), button, FALSE, TRUE, 0);
    button = gtk_button_new_with_label("_Copy");
    gtk_button_set_use_underline(GTK_BUTTON(button), TRUE);
    g_signal_connect(button, "clicked", G_CALLBACK(on_copy_text), NULL);
    gtk_box_pack_start(GTK_BOX(box2), button, FALSE, TRUE, 0);
    button = gtk_button_new_with_label("_Paste");
    gtk_button_set_use_underline(GTK_BUTTON(button), TRUE);
    g_signal_connect(button, "clicked", G_CALLBACK(on_paste_text), NULL);
    gtk_box_pack_start(GTK_BOX(box2), button, FALSE, TRUE, 0);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
