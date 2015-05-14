ButtonBox
=========
A ButtonBox is a container used typically to group :doc:`button` widgets horizontally or vertically, while aiming to give each button an appropriate size.

===========
Constructor
===========
The ButtonBox is constructed using the call::

  GtkWidget *buttonbox = gtk_button_box_new(orientation);

The *orientation* should be set to one of the following:

* ``GTK_ORIENTATION_HORIZONTAL``
* ``GTK_ORIENTATION_VERTICAL``

=======
Methods
=======
Child widgets are added to the ButtonBox by calling::

  gtk_container_add(GTK_CONTAINER(buttonbox), child);

The ButtonBox layout defaults to centering all of the child widgets in the middle of the container. This can be adjusted by::

  gtk_button_box_set_layout_style(GTK_BUTTON_BOX(buttonbox), style);

The *style* parameter should be set to one of the following constants:

* ``GTK_BUTTONBOX_SPREAD`` - evenly space the child widgets across the container.
* ``GTK_BUTTONBOX_EDGE`` - place widgets at container edges.
* ``GTK_BUTTONBOX_START`` - position buttons at left or top of container.
* ``GTK_BUTTONBOX_END`` - position buttons at right or bottom of container.
* ``GTK_BUTTONBOX_CENTER`` - center the buttons within the container.
* ``GTK_BUTTONBOX_EXPAND`` - expand child buttons to fill all the space available.

The layout chosen can also be retrieved via::

  gtk_button_box_get_layout(GTK_BUTTON_BOX(buttonbox));

The child widgets by default have no space between themselves. This can be configured after construction with::

  gtk_box_set_spacing(GTK_BOX(buttonbox), spacing);

The *spacing* value should be the number of pixels of space to insert between each child.

In some cases, it may be useful to add a secondary child widget. This can be defined with::

  gtk_button_box_set_child_secondary(GTK_BUTTON_BOX(buttonbox), child, is_secondary);

The *child* parameter should be set to the name of the widget which is to be made secondary. The *is_secondary* argument when set to ``TRUE`` enables the secondary functionality. When enabled, the secondary child will appear visibly separate from the other widgets.

The ButtonBox attempts to make all child widgets to the same size. To configure this for a particular widget call::

  gtk_button_box_set_child_non_homogeneous(GTK_BUTTON_BOX(buttonbox), child, non_homogeneous);

The *child* argument should be set to the name of the widget. The *non-homogeneous* parameter when set to ``TRUE`` excludes the child from homogeneous sizing.

=======
Example
=======
Below is an example of a ButtonBox:

.. literalinclude:: _examples/buttonbox.c

Download: :download:`ButtonBox <_examples/buttonbox.c>`
