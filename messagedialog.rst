MessageDialog
=============
The MessageDialog is used to convey messages to the user about the state of a process. It is commonly used to ask questions, warn about issues, or display encountered errors.

===========
Constructor
===========
The MessageDialog can be constructed using::

  messagedialog = gtk_message_dialog_new(parent, flags, type, buttons, text);

If the MessageDialog is to display formatted text, another constructor can be used::

  messagedialog = gtk_message_dialog_new_with_markup(parent, flags, type, buttons, text);

Both calls take on a number of arguments. The first is the *parent* which is set to the parent :doc:`window` or :doc:`dialog` which owns the MessageDialog. The *flags* parameter determines some of the features of the dialog and is able to be set to:

* ``GTK_DIALOG_MODAL``
* ``GTK_DIALOG_DESTROY_WITH_PARENT`` - close the dialog when the parent is closed.
* ``GTK_DIALOG_USE_HEADER_BAR`` - create dialog with actions in the header bar rather than the action area.

The *type* parameter indicates the purpose of the MessageDialog and should be set to one of:

* ``GTK_MESSAGE_INFO``
* ``GTK_MESSAGE_WARNING``
* ``GTK_MESSAGE_QUESTION``
* ``GTK_MESSAGE_ERROR``
* ``GTK_MESSAGE_OTHER``

Buttons can also be configured at construction time with:

* ``GTK_BUTTONS_NONE``
* ``GTK_BUTTONS_OK``
* ``GTK_BUTTONS_CLOSE``
* ``GTK_BUTTONS_CANCEL``
* ``GTK_BUTTONS_YES_NO``
* ``GTK_BUTTONS_OK_CANCEL``

Finally, the text to display can also be set with the *text* argument set to the string to show.

=======
Methods
=======
Text with (and without) markup can be set on the MessageDialog using::

  gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(messagedialog), text);

If a more detailed explaination of the MessageDialog content is required, use::

  gtk_message_dialog_format_secondary_markup(GTK_MESSAGE_DIALOG(messagedialog), text);

The *text* parameter accepts markup if required. When used, the primary message will be made larger and bolder.

Additional content can be added to the message area of the dialog by retrieving the child :doc:`box` container::

  gtk_message_dialog_get_message_area(GTK_MESSAGE_DIALOG(messagedialog));

=======
Example
=======
Below is an example of a MessageDialog:

.. literalinclude:: _examples/messagedialog.c

Download: :download:`MessageDialog <_examples/messagedialog.c>`
