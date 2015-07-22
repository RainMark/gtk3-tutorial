ComboBox
========
The ComboBox widget provides a dropdown menu for the user to select an item from a defined list. It can also be configured to allow the user to enter a value which is not in the list.

For simple string listing uses, a :doc:`comboboxtext` widget is simpler to use and quicker to setup.

===========
Constructor
===========
A ComboBox in its most basic form can be constructed with::

  GtkWidget *combobox = gtk_combo_box_new();

Alternatively, a ComboBox can be constructed with either an attached model or entry provided::

  GtkWidget *combobox = gtk_combo_box_new_with_model(model);
  GtkWidget *combobox = gtk_combo_box_new_with_entry();

Both a model and entry can be added in a single construction statement via::

  GtkWidget *combobox = gtk_combo_box_new_with_model_and_entry(model);

The *model* parameter should be an appropriate :doc:`liststore` which will hold the items for display in the ComboBox.

=======
Methods
=======
A model can be attached to the ComboBox after construction with::

  gtk_combo_box_set_model(GTK_COMBOBOX(combobox), model);

The active item can be programatically set in a number of ways::

  gtk_combo_box_set_active(GTK_COMBOBOX(combobox), index);
  gtk_combo_box_set_active_iter(GTK_COMBOBOX(combobox), treeiter);

The ``set_active()`` method allows the *index* of the item in the model to be displayed, with the first item identified by ``0``. The ``set_active_iter()`` call allows the TreeIter of the item to be passed as *iter*.

Alternatively, an ID can be passed for display::

  gtk_combo_box_set_active_id(GTK_COMBOBOX(combobox), id);

The *id* value should be set to a string which identifies the item to be shown to the user.

An ID column must be defined to use the ``set_active_id()`` method. The column holding the ID must be a string type::

  gtk_combo_box_set_id_column(GTK_COMBOBOX(combobox), column);

By default, all items are placed in a single list. If the list becomes to long, this becomes unmanageable. To mitigate this, the items can be placed into multiple rows and columns with::

  gtk_combo_box_set_row_span_column(GTK_COMBOBOX(combobox), row_span);
  gtk_combo_box_set_column_span_column(GTK_COMBOBOX(combobox), column_span);

You can check whether the ComboBox has an Entry with::

  gtk_combo_box_get_has_entry(GTK_COMBOBOX(combobox));

The ComboBox can be configured to accept focus or not when clicked via::

  gtk_combo_box_set_focus_on_click(GTK_COMBOBOX(combobox), focus);
