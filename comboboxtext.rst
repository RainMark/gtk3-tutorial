ComboBoxText
============
A ComboBoxText provides a quick and easy way to build a drop-down widget without the extra functionality provided by the :doc:`combobox`. The widget does look exactly the same however.

===========
Constructor
===========
A ComboBoxText is constructed with the call::

  GtkWidget *combobox = gtk_combo_box_text_new();

It can also be constructed with a text entry providing a way for the user to enter items now already in the menu::

  GtkWidget *combobox = gtk_combo_box_text_new_with_entry();

=======
Methods
=======
Items can be added to the ComboBoxText via the methods::

  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combobox), item);
  gtk_combo_box_text_prepend_text(GTK_COMBO_BOX_TEXT(combobox), item);
  gtk_combo_box_text_insert_text(GTK_COMBO_BOX_TEXT(combobox), position, item);

The ``append_text()`` and ``prepend_text()`` methods add items to the widget after or before the executed order. The ``insert_text()`` method allows a specific *position* to be defined where the item should be inserted. The *item* value should be the string of text to be added.

Text can also be added to the ComboBoxText with an associated identifier::

  gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combobox), id, item);
  gtk_combo_box_text_prepend(GTK_COMBO_BOX_TEXT(combobox), id, item);
  gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(combobox), position, id, item);

The *item* and *position* items are the same as above. The extra *id* attribute should be a string of text identifying the text item.

The selected text can be retrieved from the item via::

  gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(combobox));

Items can be removed from the ComboBoxText with::

  gtk_combo_box_text_remove(GTK_COMBO_BOX_TEXT(combobox), position);

The *position* value is the location value of the item in the ComboBoxText, with the first item represented by ``0``.

All the items can be cleared from the widget using::

  gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(combobox));

=======
Example
=======
Below is an example of a ComboBoxText:

.. literalinclude:: _examples/comboboxtext.c

Download: :download:`ComboBoxText <_examples/comboboxtext.c>`
