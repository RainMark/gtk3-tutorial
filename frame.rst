Frame
=====
A Frame provides a container for grouping widgets typically of a similar purpose. By default, a surrounding line indicates the edge of the Frame, and a title is also able to be added indicating the purpose of the contents.

.. note::

  The Frame widget border can be considered distracting if overused on a single interface. Typically, a Frame is not used by itself; rather in combination with other widgets and settings. This setup can be viewed on the :doc:`commonframe` page.

===========
Constructor
===========
Construction of the Frame widget is done with::

  GtkWidget *frame = gtk_frame_new();

=======
Methods
=======
Title text can be assigned to the Frame post-construction with::

  gtk_frame_set_label(GTK_FRAME(frame), text);

Alternatively, a :doc:`label` widget can be added instead::

  gtk_frame_set_label_widget(GTK_FRAME(frame), label);

Configuration of the label position can be set via::

  gtk_frame_set_label_align(GTK_FRAME(frame), xalign, yalign);

The *xalign* and *yalign* defaults are ``0.0`` and ``0.5`` to position the label on the left. The numbers should be set between ``0.0`` and ``1.0`` for both arguments.

The line around the Frame is referred to as the shadow and can be set with::

  gtk_frame_set_shadow_type(GTK_FRAME(frame), shadow);

The *shadow* value should be set to one of the following:

* ``GTK_SHADOW_NONE`` - display no frame.
* ``GTK_SHADOW_IN`` - outline is bevelled inwards.
* ``GTK_SHADOW_OUT`` - outline is bevelled outwards.
* ``GTK_SHADOW_ETCHED_IN`` - sunken 3D appearance.
* ``GTK_SHADOW_ETCHED_OUT`` - raised 3D appearance.

=======
Example
=======
Below is an example of a Frame:

.. literalinclude:: _examples/frame.c

Download: :download:`Frame <_examples/frame.c>`
