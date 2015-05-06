Switch
======
A Switch widget is a simple On/Off state toggle. It is commonly used to represent the state of physical items such as the state of a wireless network connection.

===========
Constructor
===========
The constructor for the Switch is::

  GtkWidget *switch = gtk_switch_new();

=======
Methods
=======
To retrieve whether the Switch is active (on) or inactive (off), call::

  gtk_switch_get_active(GTK_SWITCH(switch));

If the Switch is on, ``TRUE`` will be returned, otherwise ``FALSE`` is returned.

The state of the Switch can be set programatically with::

  gtk_switch_set_active(GTK_SWITCH(switch), state);

=======
Example
=======
Below is an example of a Switch:

.. literalinclude:: _examples/switch.c

Download: :download:`Switch <_examples/switch.c>`
