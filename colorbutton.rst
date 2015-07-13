ColorButton
===========
The ColorButton allows for the selection of a colour. The Button-like widget displays the chosen colour, and when clicked, a :doc:`colorchooserdialog` is displayed allowing the selection of the colour.

===========
Constructor
===========
Construction of the ColorButton is made with::

  GtkWidget *colorbutton = gtk_color_button_new();

=======
Methods
=======
The title of the dialog launched when the ColorButton is clicked can be set via::

  gtk_color_button_set_title(GTK_COLOR_BUTTON(colorbutton), title);

