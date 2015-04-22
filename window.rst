Window
======
The Window is the basis of most applications created using GTK+. It is the widget which provides the framework on which other widgets ca be added. Therefore it is known as a container widget.

By itself, a Window can only pack a single widget within its container.

===========
Constructor
===========
The Window can be constructed using::

  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

=======
Methods
=======
The title of the Window can be set using the following method::

  gtk_window_set_title(GTK_WINDOW(window), "Window");

By default, the Window is not shown by GTK+. This needs to be called explicitly with::

  gtk_widget_show_all(window);

.. note::

  It is recommended to use the ``gtk_widget_show_all(window)`` method once all the widgets have been added to the interface. This ensures that on very slow machines, the window displays all widgets at once rather than a blank window, and all other widgets added as they are processed.
  
Window widgets can also be hidden again with::

  gtk_widget_hide(window);

=======
Example
=======
Below is an example of a Window:

.. literalinclude:: _examples/window.c

Download: :download:`Window <_examples/window.c>`
