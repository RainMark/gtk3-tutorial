ActionBar
=========
The ActionBar container provides a location on which to add contextual actions. It is commonly placed at the bottom of a window and is expanded to the full width.

===========
Constructor
===========
Construction of the ActionBar is made using the call::

  GtkWidget *actionbar = gtk_action_bar_new();

=======
Methods
=======
Items can either be added at the start (left-side) or end (right-side) of the ActionBar via::

  gtk_action_bar_pack_start(GTK_ACTION_BAR(actionbar), child);
  gtk_action_bar_pack_end(GTK_ACTION_BAR(actionbar), child);

To place items centrally within the ActionBar call::

  gtk_action_bar_set_center_widget(GTK_ACTION_BAR(actionbar), child);

=======
Example
=======
Below is an example of an ActionBar:

.. literalinclude:: _examples/actionbar.c

Download: :download:`ActionBar <_examples/actionbar.c>`
