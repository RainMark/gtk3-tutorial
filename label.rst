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

  gtk_label_get_label(GTK_LABEL(label));

By default, text aligns centrally on both horizontal and vertical planes. This can be configured using::

  gtk_label_set_xalign(GTK_LABEL(label), xalign);
  gtk_label_set_yalign(GTK_LABEL(label), yalign);

The *xalign* and *yalign* parameters should be set to a value between ``0.0`` and ``1.0``, with ``0.0`` indicating left or top, and ``1.0`` indicating right or bottom.

Text within the Label can be made selectable using the method::

  gtk_label_set_selectable(GTK_LABEL(label), selectable);

When *selectable* is set to ``TRUE`` the user will be able to highlight the text for copy-and-paste.

Some widgets cannot directly accept a mnemonic shortcut so an associated Label can be used with the mnemonic, which passes on focus when the shortcut key is used. The mnemonic widget can be set with::

  gtk_label_set_mnemonic_widget(GTK_LABEL(label), widget);

The default setting of the text alignment is to align to the left-edge. This can be changed via::

  gtk_label_set_justify(GTK_LABEL(label), justification);

The *justification* for the Label can be set to one of the following:

* ``GTK_JUSTIFY_LEFT``
* ``GTK_JUSTIFY_RIGHT``
* ``GTK_JUSTIFY_CENTER``
* ``GTK_JUSTIFY_FILL``

=======
Example
=======
Below is an example of a Label:

.. literalinclude:: _examples/label.c

Download: :download:`Label <_examples/label.c>`
