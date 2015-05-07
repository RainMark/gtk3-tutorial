ListStore
=========
A ListStore is an object used to store data for use in a :doc:`treeview` or :doc:`combobox`. It can be used to store a variety of data types such as text, values, and images. The ListStore itself is not actually visible and it is simply used as the model for other widgets to show the contents it holds.

===========
Constructor
===========
The constructor for the ListStore is::

  GtkListStore *liststore = gtk_liststore_new(columns, type, type, type...);

The *columns* parameter indicates the number of columns the ListStore will hold. A matching number of *type* declarations can then be supplied which indicate what type of data will be stored in each column. The types permissible include::

* ``G_TYPE_STRING``
* ``G_TYPE_INT``
* ``G_TYPE_FLOAT``
* ``G_TYPE_DOUBLE``
* ``G_TYPE_BOOLEAN``
* ``G_TYPE_CHAR``
* ``G_TYPE_OBJECT``

=======
Methods
=======
New rows are added to the ListStore with::

  gtk_liststore_prepend(liststore, treeiter);
  gtk_liststore_append(liststore, treeiter);
  gtk_liststore_insert(liststore, treeiter, position);

The *treeiter* parameter should point to an appropriate :doc:`treeiter` object which identifies the particular row being added. The ``insert()`` method also takes the *position* value indicating the location where the row should be added.

Once the row has been added, the data can then be added::

  gtk_liststore_set(liststore, treeiter, data, -1);

Individual items can be removed from the ListStore via::

  gtk_liststore_remove(liststore, treeiter);

The *treeiter* parameter points to the TreeIter object of the row to be removed. If the TreeIter is valid and the row is remove, the method returns ``True``, otherwise ``FALSE`` is removed.

All the items can be cleared from the ListStore using::

  gtk_liststore_clear(liststore);

Two rows can be swapped by specifying the TreeIter of both with::

  gtk_liststore_swap(liststore, treeiter1, treeiter2);

.. note::

  The ``swap()`` function only works on ListStore objects which are unsorted.

Rows can also be moved above or below an existing item by calling::

  gtk_liststore_move_before(liststore, treeiter, position);
  gtk_liststore_move_after(liststore, treeiter, position);

The *treeiter* call in both methods takes the TreeIter of the item to be moved. The *position* argument is also a TreeIter, but it is that of the existing item to place the moved row above or below.

.. note::

  The ``move_before()`` and ``move_after()`` methods only work on ListStore objects which are unsorted.
