EntryCompletion
===============
An EntryCompletion provides suggestions on completing text entered into an :doc:`entry`. Completions are either done inline, by completing the letters entered, or displayed in a dropdown menu for selection.

===========
Constructor
===========
The EntryCompletion object is constructed via the call::

  GtkWidget *entrycompletion = gtk_entry_completion_new();

=======
Methods
=======
The EntryCompletion uses a model such as a :doc:`liststore` to store items for completion. This is defined with::

  gtk_entry_completion_set_model(GTK_ENTRY_COMPLETION(entrycompletion), model);

When the model has been set, the column number where the items for completion are stored must be set::

  gtk_entry_completion_set_text_column(GTK_ENTRY_COMPLETION(entrycompletion), column);

The *column* value should be set to an integer which starts with ``0`` to indicate the first column.

To prevent the completion being called immediately, the minimum key length can be defined with::

  gtk_entry_completion_set_minimum_key_length(GTK_ENTRY_COMPLETION(entrycompletion), length);

The *length* parameter should be set to an integer value.

To enable inline completion where the completion text is inserted into the Entry, use::

  gtk_entry_completion_set_inline_completion(GTK_ENTRY_COMPLETION(entrycompletion), inline);

The ability to cycle through completions within the Entry is set with::

  gtk_entry_completion_set_inline_selection(GTK_ENTRY_COMPLETION(entrycompletion), inline);

A completion can be programatically forced using the entered text as the key via::

  gtk_entry_completion_complete(GTK_ENTRY_COMPLETION(entrycompletion));
