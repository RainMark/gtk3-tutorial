FontButton
==========
The FontButton provides a standard Button-like display which launches a :doc:`fontchooserdialog` when clicked allowing the user to select a font, size, and style to be selected.

===========
Constructor
===========
Construction of the FontButton is made using::

  GtkWidget *fontbutton = gtk_font_button_new();

=======
Methods
=======
A pre-selected font can be specified via its name by calling::

  gtk_font_button_set_font_name(GTK_FONT_BUTTON(fontbutton), name);

The selected font and associated properties can be displayed on the FontButton. These settings can be configured with::

  gtk_font_button_set_show_style(GTK_FONT_BUTTON(fontbutton), show_style);
  gtk_font_button_set_show_size(GTK_FONT_BUTTON(fontbutton), show_size);

Previews can also be displayed on the FontButton for the selected font using::

  gtk_font_button_set_use_font(GTK_FONT_BUTTON(fontbutton), use_font);
  gtk_font_button_set_use_size(GTK_FONT_BUTTON(fontbutton), use_size);

The FontButton title to be displayed on the dialog can be set with::

  gtk_font_button_set_title(GTK_FONT_BUTTON(fontbutton), title);

=======
Example
=======
Below is an example of a FontButton:

.. literalinclude:: _examples/fontbutton.c

Download: :download:`FontButton <_examples/fontbutton.c>`
