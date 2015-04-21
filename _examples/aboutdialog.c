#include <gtk/gtk.h>

int main(int argc, char *argv[])
{   
    gtk_init(&argc, &argv);
    
    GtkWidget *aboutdialog = gtk_about_dialog_new();
    gtk_about_dialog_set_name(GTK_ABOUT_DIALOG(aboutdialog), "Learn GTK+");
    gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(aboutdialog), "1.0");
    gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(aboutdialog), "An introduction to using GTK+");
    gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(aboutdialog), "http://learngtk.org/");
    gtk_dialog_run(GTK_DIALOG(aboutdialog));
    gtk_widget_destroy(aboutdialog);
    
    return 0;
}
