ScaleButton
===========
The ScaleButton provides a small button which when clicked, displays a popup containing a slider similar to a :doc:`scale` widget. The widget is commonly used where space in the interface is at a premium and a normal Scale widget would be too large.

===========
Constructor
===========
The ScaleButton is constructable via the call::

  GtkWidget *scalebutton = gtk_scale_button_new(size, minimum, maximum, step, icons);

A *minimum* and *maximum* value should be set to provide the range within which the ScaleButton operates. A *step* value indicates the amount of change the slider makes. The *icons* argument shoud be a list of icons which will be displayed as the slider is changed, or alternatively this can be set to ``NULL`` at construction time. The *size* parameter indicates the size allocated to the icon and should be set to one of:

* ``GTK_ICON_SIZE_MENU``
* ``GTK_ICON_SIZE_SMALL_TOOLBAR``
* ``GTK_ICON_SIZE_LARGE_TOOLBAR``
* ``GTK_ICON_SIZE_BUTTON``
* ``GTK_ICON_SIZE_DND``
* ``GTK_ICON_SIZE_DIALOG``

=======
Methods
=======
The value currently set on the ScaleButton can be retrieved with::

  gtk_scale_button_get_value(GTK_SCALE_BUTTON(scalebutton));

Alternatively, a value is able to be programatically set using::

  gtk_scale_button_set_value(GTK_SCALE_BUTTON(scalebutton), value);

The icons used by the ScaleButton are customisable with::

  gtk_scale_button_set_icons(GTK_SCALE_BUTTON(scalebutton), icons);

Icons are displayed via the *icons* parameter on the ScaleButton to indicate the current status of the value. This is set with the use of a list. It is recommended that at least three icons are specified, with each icon being used to indicate a different value. For example, it two icons are in use then the bottom 50% of the slider will show the first icon, and the top 50% will show the second.

The ScaleButton can also be associated with an :doc:`adjustment` object via::

  gtk_scale_button_set_adjustment(GTK_SCALE_BUTTON(scalebutton), adjustment);

The Adjustment object can also be fetched with the method::

  gtk_scale_button_get_adjustment(GTK_SCALE_BUTTON(scalebutton));

=======
Example
=======
Below is an example of a ScaleButton:

.. literalinclude:: _examples/scalebutton.c

Download: :download:`ScaleButton <_examples/scalebutton.c>`
