AboutDialog
===========
An AboutDialog is used to display information about the application to the end user. Typically, this includes a name, a short description, version number, website, possibly names and contact details of the developers.

===========
Constructor
===========
The construction call for the AboutDialog is::

  GtkWidget *aboutdialog = gtk_about_dialog_new();

=======
Methods
=======
The program name can be set via::

  gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(aboutdialog), name);

Most of the methods are fairly self-explanatory::

  gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(aboutdialog), version);
  gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(aboutdialog), copyright);
  gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(aboutdialog), comments);
  gtk_about_dialog_set_license(GTK_ABOUT_DIALOG(aboutdialog), license);
  gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(aboutdialog), license);
  gtk_about_dialog_set_website_label(GTK_ABOUT_DIALOG(aboutdialog), license);

To configure whether the license text is automatically wrapped, use::

  gtk_about_dialog_set_wrap_license(GTK_ABOUT_DIALOG(aboutdialog), wrap_license);

The license type can be defined using constants within GTK+::

  gtk_about_dialog_set_license_type(GTK_ABOUT_DIALOG(aboutdialog), license_type);

If the ``set_license_type()`` method is used, it overrides the ``set_license`` method. The *license_type* parameter can be set to one of the following:

* ``GTK_LICENSE_GPL_2_0``
* ``GTK_LICENSE_GPL_3_0``
* ``GTK_LICENSE_LGPL_2_1``
* ``GTK_LICENSE_LGPL_3_0``
* ``GTK_LICENSE_BSD``
* ``GTK_LICENSE_MIT_X11``
* ``GTK_LICENSE_ARTISTIC``
* ``GTK_LICENSE_GPL_2_0_ONLY``
* ``GTK_LICENSE_GPL_3_0_ONLY``
* ``GTK_LICENSE_LGPL_2_1_ONLY``
* ``GTK_LICENSE_LGPL_3_0_ONLY``

A list of authors (developers), artists, documenters, and translators can be defined for display with the methods::

  gtk_about_dialog_set_authors(GTK_ABOUT_DIALOG(aboutdialog), authors);
  gtk_about_dialog_set_artists(GTK_ABOUT_DIALOG(aboutdialog), artists);
  gtk_about_dialog_set_documenters(GTK_ABOUT_DIALOG(aboutdialog), documenters);
  gtk_about_dialog_set_translators(GTK_ABOUT_DIALOG(aboutdialog), translators);

The logo for the program can also be displayed on the AboutDialog with::

  gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(aboutdialog), logo);

The *logo* parameter passed should be a GdkPixbuf object.

=======
Example
=======
Below is an example of an AboutDialog:

.. literalinclude:: _examples/aboutdialog.c

Download: :download:`AboutDialog <_examples/aboutdialog.c>`
