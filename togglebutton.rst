ToggleButton
============
A ToggleButton has the appearance of a standard :doc:`button` widget however it is able to have an on or off state. Its functionality is similar to a :doc:`checkbutton`.

===========
Constructor
===========
A ToggleButton is constructed with the call::

  gtk_toggle_button_new();

The ToggleButton is also able to be constructed with a label::

  gtk_toggle_button_new_with_label(label);

An associated mnemonic accelerator can be added at construction with::

  gtk_toggle_button_new_with_mnemonic(label);

=======
Methods
=======
The active state can be set on the ToggleButton using the method::

  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(togglebutton), active);

Retrieving the state from the ToggleButton is done with::

  gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton));

The label displayed on the ToggleButton can be changed via::

  gtk_toggle_button_set_label(GTK_TOGGLE_BUTTON(togglebutton), label);

=======
Signals
=======


=======
Example
=======
Below is an example of a ToggleButton:

.. literalinclude:: _examples/togglebutton.c

Download: :download:`ToggleButton <_examples/togglebutton.c>`
