MenuButton
==========
The MenuButton provides a widget similar to a :doc:`button`, but with an attached :doc:`menu` which appears when clicked.

===========
Constructor
===========
The MenuButton is constructed using::

  GtkWidget *menubutton = gtk_menu_button_new();

=======
Methods
=======
The Menu to popup is set after construction by using::

  gtk_menu_button_set_popup(GTK_MENU_BUTTON(menubutton), menu);

Alternatively, if the popup is to contain other widgets, a :doc:`popover` can be defined::

  gtk_menu_button_set_popover(GTK_MENU_BUTTON(menubutton), popover);

The direction on which the Menu appears can be configured via::

  gtk_menu_button_set_direction(GTK_MENU_BUTTON(menubutton), direction);

Setting of the *direction* parameter should be done to one of the following:

* ``GTK_ARROW_UP``
* ``GTK_ARROW_DOWN``
* ``GTK_ARROW_LEFT``
* ``GTK_ARROW_RIGHT``
* ``GTK_ARROW_NONE``

=======
Example
=======
Below is an example of a MenuButton:

.. literalinclude:: _examples/menubutton.c

Download: :download:`MenuButton <_examples/menubutton.c>`
