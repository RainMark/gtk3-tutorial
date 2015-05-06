Scale
=====
The Scale widget provides a way to adjust a slider to output a number between a minimum and maximum range.

===========
Constructor
===========
A Scale widget is constructed by the call::

  GtkWidget *scale = gtk_scale_new();

=======
Methods
=======
The value of the Scale is retrievable using::

  gtk_scale_get_value(GTK_SCALE(scale));

Values can also be set onto the Scale with the method::

  gtk_scale_set_value(GTK_SCALE(scale), value);

The *value* will need to be a number in between the minimum and maximum range allowance. If the number is outside of this range, the value will be wrapped to the nearest minimum or maximum.

By default, the current value held by the Scale is drawn on above the marker. This can be configured using::

  gtk_scale_set_draw_value(GTK_SCALE(scale), draw_value);

The position of the drawn value is customisable with the method::

  gtk_scale_set_value_pos(GTK_SCALE(scale), position);

The *position* argument should be set to one of the following constants:

* ``GTK_POS_LEFT``
* ``GTK_POS_RIGHT``
* ``GTK_POS_TOP``
* ``GTK_POS_BOTTOM``

The number of decimal places displayed on the Scale value is set with::

  gtk_scale_set_digits(GTK_SCALE(scale), digits);

The *digits* value can be set to ``0`` to ensure an integer value is displayed on screen.

An indicator mark can be added to the Scale via::

  gtk_scale_add_mark(GTK_SCALE(scale), value, position, markup);

The *value* argument is the value at which the mark should be placed on the Scale. The *markup* parameter can be set to ``NULL`` if not required, or alternatively a string of text to be displayed alongside the mark, typically as an identifier for the purpose of the mark. Finally, the position is settable to one of the constants:

* ``GTK_POS_LEFT``
* ``GTK_POS_RIGHT``
* ``GTK_POS_TOP``
* ``GTK_POS_BOTTOM``

Marks can be cleared from the Scale with the call::

  gtk_scale_clear_marks(GTK_SCALE(scale));

=======
Example
=======
Below is an example of a Scale:

.. literalinclude:: _examples/scale.c

Download: :download:`Scale <_examples/scale.c>`
