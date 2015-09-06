TreeStore
=========
A TreeStore is similar to a :doc:`liststore`, however it allows items to be inserted at sublevels to other items rather than simply as a flat list. It is most commonly used alongside :doc:`treeview` widgets, and is able to store a number of data types including text, values, and images. As with the ListStore, the object is not visible.

===========
Constructor
===========
The constructor for the TreeStore object is::

  GtkTreeStore *treestore = gtk_treestore_new(columns, type, type, type...);

The *columns* parameter indicates the number of columns the TreeStore will hold. A matching number of *type* declarations can then be supplied which indicate what type of data will be stored in each column. The types permissible include::

* ``G_TYPE_STRING``
* ``G_TYPE_INT``
* ``G_TYPE_FLOAT``
* ``G_TYPE_DOUBLE``
* ``G_TYPE_BOOLEAN``
* ``G_TYPE_CHAR``
* ``G_TYPE_OBJECT``

=======
Example
=======
Below is an example of a TreeStore:

.. literalinclude:: _examples/treestore.c

Download: :download:`TreeStore <_examples/treestore.c>`
