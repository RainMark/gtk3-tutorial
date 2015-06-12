FlowBox
=======
The FlowBox allows child widgets to be added to the container, which arranges the added widgets into rows and columns. Depending on the width or height of the child, the amount of space it occupies within the FlowBox is adjusted. In addition, items can be sorted and filtered as required.

A FlowBox is also similar to a :doc:`listbox`.

===========
Constructor
===========
The FlowBox is constructed by the call::

  GtkWidget *flowbox = gtk_flow_box_new();

=======
Methods
=======
Child widgets are added to the FlowBox with the method::

  gtk_flow_box_insert(GTK_FLOW_BOX(flowbox), child, position);

The *child* parameter should be set to the child being added. The *position* value specifies the order in which the child should be added. If ``-1`` is used, the child will be appended to the end of the FlowBox.

The child widget at a particular position can be obtained via the position value with::

  gtk_flow_box_get_child_at_index(GTK_FLOW_BOX(flowbox), position);

Spacing between rows and columns can be set via::

  gtk_flow_box_set_row_spacing(GTK_FLOW_BOX(flowbox), spacing);
  gtk_flow_box_set_column_spacing(GTK_FLOW_BOX(flowbox), spacing);

To ensure that all rows and columns are assigned the same size call::

  gtk_flow_box_set_homogeneous(GTK_FLOW_BOX(flowbox), homogeneous);

The child rows contained by the FlowBox are able to be selected or unselected using::

  gtk_flow_box_select_all(GTK_FLOW_BOX(flowbox));
  gtk_flow_box_unselect_all(GTK_FLOW_BOX(flowbox));

The minimum and maximum children per line can be fixed via::

  gtk_flow_box_set_min_children_per_line(GTK_FLOW_BOX(flowbox), number);
  gtk_flow_box_set_max_children_per_line(GTK_FLOW_BOX(flowbox), number);

Children contained within the FlowBox can be selected by the user. This can be configured via::

  gtk_flow_box_set_selection_mode(GTK_FLOW_BOX(flowbox), selection);

The *selection* parameter should be set to one of the following constants::

* ``GTK_SELECTION_NONE`` - allow no selections to be made.
* ``GTK_SELECTION_SINGLE`` - allow a single selection.
* ``GTK_SELECTION_MULTIPLE`` - allow multiple selections.
* ``GTK_SELECTION_BROWSE`` - allow a single selection, and only allow the currently selected item to be deselected when another item is selected.
