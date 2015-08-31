Dialog
======
A Dialog is similar to a :doc:`window`, however it provides an integrated content area and action area for buttons to be added. Typically, they are used for sub-windows of an application such as a preferences interface or to request additional information from the user.

===========
Constructor
===========
A Dialog widget is constructed via::

  GtkWidget *dialog = gtk_dialog_new();

.. note::

  The Dialog widget expects to be the child of another main application Window, and will commonly have a transient parent set. If no parent window is set for the dialog, GTK+ will display a message stating that no parent dialogs are discouraged.

=======
Methods
=======
A title can be set for the Dialog by calling::

  gtk_window_set_title(GTK_DIALOG(dialog), title);

An individual button can be added to the Dialog using::

  gtk_dialog_add_button(GTK_DIALOG(dialog), text, response);

The *text* value will be set to the text content to be displayed on the button. The response is a GTK+ constant which indicates the response of the button when clicked. The available responses are:

* ``GTK_RESPONSE_OK``
* ``GTK_RESPONSE_CANCEL``
* ``GTK_RESPONSE_APPLY``
* ``GTK_RESPONSE_CLOSE``
* ``GTK_RESPONSE_ACCEPT``
* ``GTK_RESPONSE_REJECT``
* ``GTK_RESPONSE_YES``
* ``GTK_RESPONSE_NO``
* ``GTK_RESPONSE_HELP``
* ``GTK_RESPONSE_DELETE_EVENT``
* ``GTK_RESPONSE_NONE

Alternatively, a positive integer value can be specified in place of the constant. The integer can then be handled to run the appropriate code.

Multiple buttons can be added in a single statement via::

  gtk_dialog_add_buttons(GTK_DIALOG(dialog), text, response, text, response, ...);

The default button which is highlighted when the dialog opens can be set with::

  gtk_dialog_set_default_response(GTK_DIALOG(dialog), response);

In some cases, buttons should be made insensitive. For example, you may want to prevent the user clicking OK without choosing an option. This can be done with::

  gtk_dialog_set_response_sensitive(GTK_DIALOG(dialog), response, sensitive);

The *response* should be set as when creating the button. The *sensitive* when set to ``FALSE`` will grey-out the button.

A Dialog has two integrated areas which can be obtained::

  gtk_dialog_get_content_area(GTK_DIALOG(dialog));
  gtk_dialog_get_header_bar(GTK_DIALOG(dialog));

Additional widgets can be added to the action area with::

  gtk_dialog_add_action_widget(GTK_DIALOG(dialog), child, response);

The *child* value should be set to an appropriate widget to be added alongside the Dialog buttons.

Running the dialog is done with the method::

  gtk_dialog_run(GTK_DIALOG(dialog));

The Dialog can also be destroyed programmatically via::

  gtk_widget_destroy(dialog);

=======
Example
=======
Below is an example of a Dialog:

.. literalinclude:: _examples/dialog.c

Download: :download:`Dialog <_examples/dialog.c>`
