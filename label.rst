Label
=====
The Label widget is commonly used for displaying small amounts of text, such as the purpose of another widget. It is however fairly powerful and can also be used to display longer strings of text with various formatting options such as bold or underlined text.

===========
Constructor
===========
The Label can be constructed using the call::

  GtkWidget *label = gtk_label_new(text);

The *text* value is used to declare the text to be displayed inside the Label when it is constructed.

=======
Methods
=======
The Label text can be defined after construction with::

  gtk_label_set_label(GTK_LABEL(label), text);

Text can also be retrieved from Label via::

  const char *text = gtk_label_get_text(GTK_LABEL(label));

=======
Example
=======
Below is an example of a Label:

.. literalinclude:: _examples/label.c

Download: :download:`Label <_examples/label.c>`
