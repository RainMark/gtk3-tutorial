Separator
=========
The Separator widget provides a way to add a vertical or horizontal line to the interface, providing a visual divider between content.

.. note::

  The use of Separator widgets can be visually distracting if overused, and should only be used when absolutely necessary. In many cases, it may be best to use a :doc:`commonframe`.

===========
Constructor
===========
The Separator is constructed via::

  GtkWidget *separator = gtk_separator_new(orientation);

The *orientation* value should be set to one of the following:

* ``GTK_ORIENTATION_VERTICAL``
* ``GTK_ORIENTATION_HORIZONTAL``

=======
Methods
=======
To set the orientation of the Separator after construction use::

  gtk_widget_set_orientation(GTK_WIDGET(separator), orientation);

=======
Example
=======
Below is an example of a Separator:

.. literalinclude:: _examples/separator.c

Download: :download:`Separator <_examples/separator.c>`
