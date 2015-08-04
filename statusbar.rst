Statusbar
=========
The Statusbar is seen in a variety of applications such as file managers and text editors. It is commonly used to display status messages such as whether a connection is up or down, or the column and line number.

Messages are pushed and popped from the Statusbar in a stack-like fashion. This means that the first message on is the last message off. Different message types can also have different contexts, allowing the management of multiple stacks of messages.

===========
Constructor
===========
Construction of the Statusbar object is made using::

  GtkWidget *statusbar = gtk_statusbar_new();

=======
Methods
=======
Once the Statusbar has been constructed, the context which identifies a particular group of messages can be retrieved::

  context_id = gtk_statusbar_get_context_id(GTK_STATUSBAR(statusbar), context);

The *context* parameter should be a textual description of the Statusbar messages to be displayed. The ``get_context_id()`` method can be called many times with different context descriptions for differing message types. The method returns an integer which is used by a number of other methods to control the display.

To add a message to the Statusbar, call::

  message_id = gtk_statusbar_push(GTK_STATUSBAR(statusbar), context_id, message);

The *context_id* parameter should be set ot the appropriate context in which the *message* parameter text will be added. The method returns a unique *message_id* which identifies the pushed message.

Messages can be taken of the stack via::

  gtk_statusbar_pop(GTK_STATUSBAR(statusbar), context_id);

An individual message can be completely removed with the call::

  gtk_statusbar_remove(GTK_STATUSBAR(statusbar), context_id, message_id);

The *context_id* and *message_id* should be set for the correct message to use. Incorrect setting of one may remove an incorrect message.

All the messages held by the Statusbar can be removed with::

  gtk_statusbar_remove_all(GTK_STATUSBAR(statusbar), context_id);

The *context_id* value indicates which context all the messages should be removed from.

=======
Signals
=======

=======
Example
=======
Below is an example of a Statusbar:

.. literalinclude:: _examples/statusbar.c

Download: :download:`Statusbar <_examples/statusbar.c>`
