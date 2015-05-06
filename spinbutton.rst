SpinButton
==========
A SpinButton allows for adjustments in numerical values either by adjustment buttons or entering text via the keyboard.

===========
Constructor
===========
A ComboBoxText is constructed with the call::

  gtk_spin_button_new(adjustment, climb_rate, digits);

The *adjustment* parameter can be set to an :doc:`adjustment` object which handles the currently set value and minimum and maximum values. The *climb_rate* should be set to a value indicating how much the SpinButton changes when adjusted. Finally, the *digits* parameter specifies how many decimal places should be displayed, with setting ``0`` showing only whole numbers.

An alternative constructor which specifies a range at initialisation is also available::

  gtk_spin_button_new_with_range(minimum, maximum, step);

The *minimum* and *maximum* values indicate the lowest and highest accepted values in the SpinButton. The *step* value controls the adjustment amount when the user clicks the adjustment buttons.

=======
Methods
=======
The value set on the SpinButton is set using::

  gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton), value);

Retrieval of the SpinButton value is retrieved via two functions::

  gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton));
  gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton));

The ``get_value()`` method returns a double type number. Alternatively, an integer value can be returned using ``get_value_as_int()``.

Limiting the range of numbers which can be entered is done with the call::

  gtk_spin_button_set_range(GTK_SPIN_BUTTON(spinbutton), minimum, maximum);

The amount the value in the SpinButton changes which clicking on the adjustment buttons can be changed with::

  gtk_spin_button_set_increments(GTK_SPIN_BUTTON(spinbutton), step, page);

The *step* value is the amount to change when left-clicking on the adjustment buttons. The *page* value is used when the adjustment buttons are middle-clicked.

In some cases, it may be useful to limit the SpinButton value to the nearest step value. This is done with::

  gtk_spin_button_set_snap_to_ticks(GTK_SPIN_BUTTON(spinbutton), snap_to_ticks);

When *snap_to_ticks* is set to ``TRUE``, the SpinButton will wrap to the nearest acceptable value.

=======
Example
=======
Below is an example of a SpinButton:

.. literalinclude:: _examples/spinbutton.c

Download: :download:`SpinButton <_examples/spinbutton.c>`
