Spinner
=======
A Spinner widget provides an animated spinning ticker which is used to indicate activity within the application. Examples of their usage include the loading of a webpage or waiting for a process to complete.

Using a Spinner is often preferred when the time taken to complete the job is unknown. If the user should know how long is remaining, it is best to use a :doc:`progressbar`.

===========
Constructor
===========
The construction of the Spinner is done using::

  GtkWidget *spinner = gtk_spinner_new();

=======
Methods
=======
The Spinner has two methods to start and stop the animation::

  gtk_spinner_start(GTK_SPINNER(spinner));
  gtk_spinner_stop(GTK_SPINNER(spinner));

=======
Example
=======
Below is an example of a Spinner:

.. literalinclude:: _examples/spinner.c

Download: :download:`Spinner <_examples/spinner.c>`
