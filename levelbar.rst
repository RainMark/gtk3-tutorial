LevelBar
========
A LevelBar provides a bar on which a level indicator is displayed. It is commonly used to show the strength of a password or the capacity of a battery.

===========
Constructor
===========
The construction of the LevelBar is made by calling::

  GtkWidget *levelbar = gtk_level_bar_new();

The default range of the LevelBar is a value between 0.0 and 1.0. Alternatively, the range can be defined at construction with::

  GtkWidget *levelbar = gtk_level_bar_new(minimum, maximum);

=======
Methods
=======
The value on the LevelBar can be set using the call::

  gtk_level_bar_set_value(GTK_LEVEL_BAR(levelbar), value);

Retrieval of the value from the LevelBar can be done using::

  gtk_level_bar_get_value(GTK_LEVEL_BAR(levelbar));

The range used by the LevelBar can be set post-construction::

  gtk_level_bar_set_min_value(GTK_LEVEL_BAR(levelbar), minimum);
  gtk_level_bar_set_max_value(GTK_LEVEL_BAR(levelbar), maximum);

By default, the LevelBar (depending on orientation) fills from left-to-right or top-to-bottom. This can be inverted via::

  gtk_level_bar_set_inverted(GTK_LEVEL_BAR(levelbar), inverted);

An offset value can be applied to the LevelBar via the method::

  gtk_level_bar_add_offset_value(GTK_LEVEL_BAR(levelbar), name, value);

The *name* parameter should be an identifier for the offset value. The *value* should be within the minimum and maximum range. If a name is set on the LevelBar which already exists, the previous value is replaced with the new value.

The named offset value can be removed with::

  gtk_level_bar_remove_offset_value(GTK_LEVEL_BAR(levelbar), name);

=======
Example
=======
Below is an example of a LevelBar:

.. literalinclude:: _examples/levelbar.c

Download: :download:`LevelBar <_examples/levelbar.c>`
