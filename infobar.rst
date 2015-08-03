InfoBar
=======
The InfoBar widget can be used to display important messages to the end user, which are displayed within the window. Messages can be of a number of types including warnings and errors.

The widget is similar to a :doc:`messagedialog`, however it is more commonly used when the message should not necessarily interrupt the user.

===========
Constructor
===========
Construction of the InfoBar is made using::

  GtkWidget *infobar = gtk_info_bar_new();

=======
Methods
=======
The message type should be set correctly to properly alert the user of the message content. This is set via::

  gtk_info_bar_set_message_type(GTK_INFO_BAR(infobar), message_type);

The *message_type* should be set to:

* ``GTK_MESSAGE_INFO``
* ``GTK_MESSAGE_WARNING``
* ``GTK_MESSAGE_ERROR``
* ``GTK_MESSAGE_QUESTION``
* ``GTK_MESSAGE_OTHER``

An InfoBar can display one or more buttons. These can be added via::

  gtk_info_bar_add_button(GTK_INFO_BAR(infobar), text, response);

The *text* value should be the string of text to display on the button. The *response* parameter should be set to a number which is used to handle how the application proceeds.

Alternatively, multiple buttons can be added at once with::

  gtk_info_bar_add_buttons(GTK_INFO_BAR(infobar), text, response, text, response, ...);

In some cases, a button added to the InfoBar will need to be made insensitive. This can be done with::

  gtk_info_bar_set_response_insensitive(GTK_INFO_BAR(infobar), response, sensitive);

The *response* value should be set to the response value of the button. The *sensitive* value when set to ``FALSE`` "greys-out" the button.

A response can also be made default (i.e. it activates when the user pressed :kbd:`Enter` or :kbd:`Return`) via::

  gtk_info_bar_set_default_response(GTK_INFO_BAR(infobar), response);

If required, the InfoBar can be dismissed by a close button, which can be shown or hidden via::

  gtk_info_bar_set_show_close_button(GTK_INFO_BAR(infobar), close_button);

The content and action areas of the InfoBar can be retrieved using::

  gtk_info_bar_get_action_area(GTK_INFO_BAR(infobar));
  gtk_info_bar_get_content_area(GTK_INFO_BAR(infobar));

=======
Example
=======
Below is an example of a InfoBar:

.. literalinclude:: _examples/infobar.c

Download: :download:`InfoBar <_examples/infobar.c>`
