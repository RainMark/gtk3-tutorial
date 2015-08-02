ProgressBar
===========
A ProgressBar is used to display to the user how long a particular task has remaining to completion. This is often expressed in time or the number of items.

===========
Constructor
===========
The constructor for the ProgressBar widget is::

  GtkWidget *progressbar = gtk_progress_bar_new();

=======
Methods
=======
Setting the value completed on the ProgressBar is made via::

  gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar), fraction);

The *fraction* parameter should be a number between ``0.0`` and ``1.0``.

Alternatively, the completion rate can be retrieved by::

  gtk_progress_bar_get_fraction(GTK_PROGRESS_BAR(progressbar));

Text can be displayed within the ProgressBar and set using::

  gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progressbar), text);

The text displayed inside the ProgressBar can be made visible or not via::

  gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(progressbar), show_text);

If *show_text* is set to ``TRUE`` but no text string has been defined, the ProgressBar will display the value of the ``set_fraction()`` method.

If it is unknown how long is left until a task is completed, the ProgressBar can be made to pulse to indicate that the program is still responsive::

  gtk_progress_bar_pulse(GTK_PROGRESS_BAR(progressbar), pulse);

The operation of a ProgressBar usually grows from left-to-right if horizontal, or top-to-bottom if vertical. This can be inverted by calling::

  gtk_progress_bar_set_inverted(GTK_PROGRESS_BAR(progressbar), inverted);

=======
Example
=======
Below is an example of a ProgressBar:

.. literalinclude:: _examples/progressbar.c

Download: :download:`ProgressBar <_examples/progressbar.c>`
