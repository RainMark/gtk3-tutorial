ToolPalette
===========
The ToolPalette is commonly used as an alternative to the :doc:`toolbar` in applications which make heavy user of tool items. The ToolPalette displays items in grids, which are grouped into common functionality.

Common examples include graphics or video editing applications.

===========
Constructor
===========
The ToolPalette widget is constructed using::

  GtkWidget *toolpalette = gtk_tool_palette_new();

=======
Methods
=======
The ToolPalette is the container for :doc:`toolitemgroup` sub-containers, which actually hold the items. These are added to the ToolPalette by::

  gtk_container_add(GTK_CONTAINER(toolpalette), toolitemgroup);

By default, grouped items can be expanded and collapsed individually. To set a particular group to open exclusively, call::

  gtk_tool_palette_set_exclusive(toolpalette, group, exclusive);

The *group* parameter should be set to the :doc:`toolitemgroup` to be made exclusive. When the *exclusive* value is set to ``TRUE``, opening the exclusive group will collapse all other open groups.

To programatically expand or collapse a ToolItemGroup use::

  gtk_tool_palette_set_expand(toolpalette, expand);

The position of a ToolItemGroup within the stack can be set with the positional value via::

  gtk_tool_palette_set_group_position(toolpalette, group, position);

The *group* value should be the name of the ToolItemGroup to be positioned, and the *position* value is a numerical value indicating the insert location, starting with ``0``.

The icon size of items within each ToolItemGroup is configurable with::

  gtk_tool_palette_set_icon_size(toolpalette, size);

The *size* value should be set to one of:

* ``GTK_ICON_SIZE_INVALID``
* ``GTK_ICON_SIZE_MENU`` (16 pixels)
* ``GTK_ICON_SIZE_SMALL_TOOLBAR`` (16 pixels)
* ``GTK_ICON_SIZE_LARGE_TOOLBAR`` (24 pixels)
* ``GTK_ICON_SIZE_BUTTON`` (16 pixels)
* ``GTK_ICON_SIZE_DND`` (32 pixels)
* ``GTK_ICON_SIZE_DIALOG`` (48 pixels)

=======
Example
=======
Below is an example of a ToolPalette:

.. literalinclude:: _examples/toolpalette.c

Download: :download:`ToolPalette <_examples/toolpalette.c>`
