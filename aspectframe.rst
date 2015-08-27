AspectFrame
===========
An AspectFrame is similar to the :doc:`frame` container widget, however it adds the ability to maintain a specific ratio for the child widget.

===========
Constructor
===========
The AspectFrame is constructed using the call::

  GtkWidget *aspectframe = gtk_aspect_frame_new(label, xalign, yalign, ratio, obey_child);

The *label* parameter sets the string which will be displayed on the AspectFrame. The *xalign* and *yalign* sets both the horizontal and vertical alignment of the child, with permissable values ranging from ``0.0`` to ``1.0``. The *ratio* determines the aspect ratio to use. Alternatively, if *obey_child* is set to ``TRUE``, the ratio value is ignored and the aspect ratio is instead taken from the child.

=======
Methods
=======
The AspectFrame values can be set after construction using::

  gtk_aspect_frame_set(GTK_ASPECT_FRAME(aspectframe), label, xalign, yalign, ratio, obey_child);

=======
Example
=======
Below is an example of a AspectFrame:

.. literalinclude:: _examples/aspectframe.c

Download: :download:`AspectFrame <_examples/aspectframe.c>`
