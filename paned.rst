Paned
=====
The Paned widget is a container which offers two panels from which additional containers or widgets can be inserted. The separator between the panels can be adjusted to increase (and decrease) the size of the panels.

===========
Constructor
===========
The constructor for the Paned widget is::

  GtkWidget *paned = gtk_paned_new(orientation);

The *orientation* parameter determines whether the Paned container lays added widgets horizontally or vertically and can be set to either:

* ``GTK_ORIENTATION_HORIZONTAL``
* ``GTK_ORIENTATION_VERTICAL``

=======
Methods
=======
Child widgets can be added to the panels via::

  gtk_paned_add1(GTK_PANED(paned), widget);
  gtk_paned_add2(GTK_PANED(paned), widget);

The ``add1()`` method adds the child widget to the top or left panel based on orientation. Using ``add2()`` adds the widget to the bottom or right panel.

Alternatively, widgets can be added with more control over the handling of the sizing::

  gtk_paned_pack1(GTK_PANED(paned), widget, resize, shrink);
  gtk_paned_pack2(GTK_PANED(paned), widget, resize, shrink);

The *resize* parameter can be set to ``TRUE`` to allow the child to expand when the widget is resized. The *shrink* parameter also when ``TRUE`` permits whether the child can be made smaller than the panel.

The child widgets attached to the Paned can be obtained via::

  gtk_paned_get_child1(GTK_PANED(paned));
  gtk_paned_get_child2(GTK_PANED(paned));

The position of the handle can be set in pixels with::

  gtk_paned_set_position(GTK_PANED(paned), position);

The *position* value should be set to the appropriate number of pixels from the top or left edge depending on the pane orientation.

To retrieve the current position of the handle call::

  gtk_paned_get_position(GTK_PANED(paned));

In some cases, it may be beneficial to have a wide handle which allows the user to grab the separator more easily. This is set by::

  gtk_paned_set_wide_handle(GTK_PANED(paned), wide);

=======
Example
=======
Below is an example of a Paned:

.. literalinclude:: _examples/paned.c

Download: :download:`Paned <_examples/paned.c>`
