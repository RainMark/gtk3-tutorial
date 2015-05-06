Grid
====
The Grid container provides a dynamically sizing layout on which other widgets can be placed. It allows widgets to be placed in rows and columns with a coordinate-like system.

===========
Constructor
===========
The constructor for the Grid is::

  GtkWidget *grid = gtk_grid_new();

=======
Methods
=======
Items are added into the Grid using the method::

  gtk_grid_attach(GTK_GRID(grid), child, left, top, width, height);

The *child* parameter is the name of the child widget to be added to the Grid. The *left* and *top* values are integer numbers with ``0`` for both positioning in the top-left corner. The *width* and *height* parameters specify how many rows or columns the widget should span when added.

Widgets can also be attached next to a sibling widget::

  gtk_grid_attach_next_to(GTK_GRID(grid), child, sibling, side, width, height);

The first argument takes the *child* widget to be added, with the *sibling* indicating the widget the child will be added relative to. The *width* and *height* specifies how many rows or columns the child widget will span. Finally, the *side* should be set to one of the following:

* ``GTK_POS_LEFT``
* ``GTK_POS_RIGHT``
* ``GTK_POS_TOP``
* ``GTK_POS_BOTTOM``

When using ``GTK_POS_TOP`` or ``GTK_POS_BOTTOM``, the child is added above or below the sibling. Alternatively, ``GTK_POS_LEFT`` and ``GTK_POS_RIGHT`` allow the child to be added to the left or right side of the sibling.

By default, the widgets have no space between each other. This can be adjusted using::

  gtk_grid_set_row_spacing(GTK_GRID(grid), spacing);
  gtk_grid_set_column_spacing(GTK_GRID(grid), spacing);

The *spacing* value should be set to an integer value specifying the number of pixels between each row and column.

In some cases, it may be useful to ensure that each widget is allocated the same space in the Grid::

  gtk_grid_set_row_homogeneous(GTK_GRID(grid), homogeneous);
  gtk_grid_set_column_homogeneous(GTK_GRID(grid), homogeneous);

When *homogeneous* is set to ``True``, the Grid will force each widget to be the same size, with the largest widget dictating the overall size.

The number of rows and columns in the Grid can be increased or decreased by::

  gtk_grid_insert_row(GTK_GRID(grid), position);
  gtk_grid_insert_column(GTK_GRID(grid), position);
  gtk_grid_remove_row(GTK_GRID(grid), position);
  gtk_grid_remove_column(GTK_GRID(grid), position);

The *position* value should be an integer value indicating the row or column to remove, with ``0`` referencing the first row or column. Children in the row/column being removed are also removed, while children spanning the row/column will be shrunk. When inserting, rows and columns are moved down/right to make way for the new row or column.

Additional rows and columns can be inserted relative to a sibling via::

  gtk_grid_insert_next_to(GTK_GRID(grid), sibling, side);

The *sibling* argument should be set to the child widget which the row or column is going to be inserted next to. The *side* value should be set to one of the following:

* ``GTK_POS_LEFT``
* ``GTK_POS_RIGHT``
* ``GTK_POS_TOP``
* ``GTK_POS_BOTTOM``

When ``GTK_POS_TOP`` or ``GTK_POS_BOTTOM`` is used, a row is inserted and when ``GTK_POS_LEFT`` and ``GTK_POS_RIGHT`` is used, a column is added.

The child located in a particular row and column can be retrieved with::

  gtk_grid_get_child_at(GTK_GRID(grid), left, top);
