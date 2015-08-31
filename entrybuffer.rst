EntryBuffer
===========
The EntryBuffer object attaches to an :doc:`entry` widget, and provides a store for text entered. It is commonly not explicitly required as an Entry stores its own text in an automatically constructed buffer.

===========
Constructor
===========
Construction of the EntryBuffer is made using::

  GtkEntryBuffer *entrybuffer = gtk_entry_buffer_new(text, length);

The *text* parameter allows setting of the text to be stored within the EntryBuffer immediately after construction. A *length* parameter is also required indicating how many characters are to be stored, however this can be set to ``-1`` if no limit is required.

=======
Methods
=======
The text held by the EntryBuffer can be set after construction using::

  gtk_entry_buffer_set_text(GTK_ENTRY_BUFFER(entrybuffer), text, length);

Retrieval of the text from the EntryBuffer is done via::

  gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(entrybuffer));

To obtain the length of the text within the EntryBuffer call::

  gtk_entry_buffer_get_length(GTK_ENTRY_BUFFER(entrybuffer));

Limiting the amount of text which is allowed to be stored in the EntryBuffer is done with the method::

  gtk_entry_buffer_set_max_length(GTK_ENTRY_BUFFER(entrybuffer), length);

Text can also be inserted into the EntryBuffer rather than overwriting the existing text::

  gtk_entry_buffer_insert_text(GTK_ENTRY_BUFFER(entrybuffer), position, chars, length);

The *position* value indicates the location within the existing buffer where the new text should be inserted. Using ``0`` indicates the start of the string. The *chars* argument specifies the text which will be added. Finally, the length parameter sets how long the string being added is, with ``-1`` defining an unspecified length.

Text within the buffer can also be deleted with::

  gtk_entry_buffer_delete_text(GTK_ENTRY_BUFFER(entrybuffer), position, length);

The *position* value sets where the text should be deleted from with the *length parameter defining the number of characters from position to delete.

=======
Example
=======
Below is an example of an EntryBuffer:

.. literalinclude:: _examples/entrybuffer.c

Download: :download:`EntryBuffer <_examples/entrybuffer.c>`
