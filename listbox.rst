ListBox
=======
The ListBox is a container which stores children vertically. It allows those widgets to be sorted and filtered dynamically.

Use of a ListBox is often done as an alternative to a :doc:`treeview` as it allows more complicated layouts than what can be achieved using CellRenderer's.

===========
Constructor
===========
ListBox construction is made using the call::

  GtkWidget *listbox = gtk_list_box_new();

=======
Methods
=======
Items can be added to the ListBox with the methods::

  gtk_list_box_prepend(GTK_WIDGET(child))
  gtk_list_box_insert(GTK_WIDGET(child), position)

The *child* parameter for both methods takes another widget which is to be added. The *position* value indicates the location at which the child should be added.

All the rows in the ListBox can be selected and unselected with the use of::

  gtk_list_box_select_all(GTK_LIST_BOX(listbox));
  gtk_list_box_unselect_all(GTK_LIST_BOX(listbox));

An individual item can be selected or unselected with::

  gtk_list_box_select_row(GTK_LIST_BOX(listbox), row);
  gtk_list_box_unselect_row(GTK_LIST_BOX(listbox), row);

The *row* parameter should be set to an appropriate ListBoxRow object contained within the ListBox.

By default, rows are selected by double-clicked. Single-click activation can be enabled with::

  gtk_list_box_set_activate_on_single_click(single);

A placeholder widget can be added for situations when the ListBox is empty::

  gtk_list_box_set_placeholder(GTK_LIST_BOX(listbox), widget);

To configure the row selection functionality call::

  gtk_list_box_set_selection_mode(GTK_LIST_BOX(listbox), mode);

The *mode* should be set to one of the following:

* ``GTK_SELECTION_NONE``
* ``GTK_SELECTION_SINGLE``
* ``GTK_SELECTION_BROWSE``
* ``GTK_SELECTION_MULTIPLE``

The selected rows, depending on the selection mode in use, can be obtained via::

  gtk_list_box_get_selected_row(GTK_LIST_BOX(listbox));
  gtk_list_box_get_selected_rows(GTK_LIST_BOX(listbox));

=======
Example
=======
Below is an example of a ListBox:

.. literalinclude:: _examples/listbox.c

Download: :download:`ListBox <_examples/listbox.c>`
