Toolbar
=======
A Toolbar is common in applications to provide access to common tasks. It takes the form of a horizontal bar with icons inserted which the user can quickly access. Common uses include opening and saving files, change font sizes, or launching a search function.

=======
Methods
=======
Insertion of items into the Toolbar is made using::

  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), item, position);

The *item* value should be that of the item to be added. The *position* specifies the location on the Toolbar of the item being inserted, with ``0`` indicating the first item.

The particular item at a given location can be obtained via::

  gtk_toolbar_get_nth_item(GTK_TOOLBAR(toolbar), position);

The position index of a given item can also be retrieved::

  gtk_toolbar_get_item_index(GTK_TOOLBAR(toolbar), item);

Retrieval of the number of items held by the Toolbar can be done with::

  gtk_toolbar_get_n_items(GTK_TOOLBAR(toolbar));

Typically, the Toolbar should match the set global settings with regards to displaying text beneath an icon, at the size, or displaying no text at all. The style can be set manually using::

  gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), style);

Setting of the *style* parameter should be one of the following:

* ``GTK_TOOLBAR_ICONS`` - display only icons.
* ``GTK_TOOLBAR_TEXT`` - display only text.
* ``GTK_TOOLBAR_BOTH`` - display icons above text.
* ``GTK_TOOLBAR_BOTH_HORIZ`` - display icons and text alongside each other.

The style can be unset if required by::

  gtk_toolbar_unset_style(GTK_TOOLBAR(toolbar));

As with style, the size of the icons should in most cases be handled globally. The size can however be configured manually with::

  gtk_toolbar_set_icon_size(size);

The *size* parameter should be one of the following::

* ``GTK_ICON_SIZE_MENU`` - 16 pixels.
* ``GTK_ICON_SIZE_SMALL_TOOLBAR`` - 16 pixels.
* ``GTK_ICON_SIZE_LARGE_TOOLBAR`` - 24 pixels.
* ``GTK_ICON_SIZE_BUTTON`` - 16 pixels.
* ``GTK_ICON_SIZE_DND`` - 32 pixels.
* ``GTK_ICON_SIZE_DIALOG`` - 48 pixels.

=======
Example
=======
Below is an example of a Toolbar:

.. literalinclude:: _examples/toolbar.c

Download: :download:`Toolbar <_examples/toolbar.c>`
