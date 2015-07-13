FileChooserButton
=================
A FileChooserButton provides a Button-style widget which when clicked launches a :doc`filechooserdialog`.

===========
Constructor
===========
The FileChooserButton is constructed using::

  GtkWidget *filechooserbutton = gtk_file_chooser_button_new();

=======
Methods
=======
The title displayed on the dialog can be set with::

  gtk_file_chooser_button_set_title(GTK_FILE_CHOOSER_BUTTON(filechooserbutton), title);

Customisation of the FileChooserButton width can be made via::

  gtk_file_chooser_button_set_width_chars(GTK_FILE_CHOOSER_BUTTON(filechooserbutton), width);

The *width* should be a value set in pixels.
