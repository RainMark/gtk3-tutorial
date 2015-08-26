HeaderBar
=========
A HeaderBar is placed at the top of the window which contains it, often replacing the titlebar decoration traditionally drawn by the window manager. Usually included within the HeaderBar is the window title, the close button, the minimise button, and the maximise button.

===========
Constructor
===========
The constructor for the HeaderBar is::

  GtkWidget *headerbar = gtk_header_bar_new();

=======
Methods
=======
The title on the HeaderBar is settable with the method::

  gtk_header_bar_set_title(GTK_HEADER_BAR(headerbar), title);

A subtitle can also be added which is displayed beneath the title::

  gtk_header_bar_set_subtitle(GTK_HEADER_BAR(headerbar), subtitle);

If no subtitle is to be set, but the space for it should be reserved for future use, use::

  gtk_header_bar_set_has_subtitle(GTK_HEADER_BAR(headerbar), has_subtitle);

When the *has_subtitle* parameter is set to ``FALSE``, any text set by the ``set_subtitle()`` method will be hidden from view.

Other widgets can be packed into the HeaderBar by using the methods::

  gtk_header_bar_pack_start(GTK_HEADER_BAR(headerbar), child);
  gtk_header_bar_pack_end(GTK_HEADER_BAR(headerbar), child);

The close, minimise, and maximise buttons can be hidden from view by using::

  gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(headerbar), close);

=======
Example
=======
Below is an example of a HeaderBar:

.. literalinclude:: _examples/headerbar.c

Download: :download:`HeaderBar <_examples/headerbar.c>`
