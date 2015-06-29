Stack
=====
The Stack widget is similar to a :doc:`notebook` by showing only one child at a time.

The Stack on its own does not provide any way for the user to change which child is visible, so if this functionality is required, the :doc:`stackswitcher` should be also used.

===========
Constructor
===========
The construction for the Stack is made with::

  GtkWidget *stack = gtk_stack_new();

=======
Methods
=======
A child can be added to the Stack using::

  gtk_stack_add_named(GTK_STACK(stack), child, name);
  gtk_stack_add_titled(GTK_STACK(stack), child, name, title);

The *child* parameter should be specified, with a typical child being a container. The *name* parameter is specified to identify the child. The *title* argument is displayed on the StackSwitcher if in use.

The visible child can be set by declaring the child and name using::

  gtk_stack_set_visible_child(GTK_STACK(stack), child);
  gtk_stack_set_visible_child_name(GTK_STACK(stack), name);

The currently visible child and name can be retrieved using the methods::

  gtk_stack_get_visible_child(GTK_STACK(stack));
  gtk_stack_get_visible_child_name(GTK_STACK(stack));

The Stack can be made homogeneous, with the same size requested for all children with::

  gtk_stack_set_homogeneous(GTK_STACK(stack), homogeneous);

The vertical and horizontal homogeneous setting can be controlled individually via::

  gtk_stack_set_vhomogeneous(GTK_STACK(stack), homogeneous);
  gtk_stack_set_hhomogeneous(GTK_STACK(stack), homogeneous);

Configuration of the Stack widget transitions can be set by::

  gtk_stack_set_transition_type(GTK_STACK(stack), transition);

The *transition* value can be set to any of the following:

* ``Gtk.StackTransitionType.NONE``
* ``Gtk.StackTransitionType.CROSSFADE``
* ``Gtk.StackTransitionType.SLIDE_RIGHT``
* ``Gtk.StackTransitionType.SLIDE_LEFT``
* ``Gtk.StackTransitionType.SLIDE_UP``
* ``Gtk.StackTransitionType.SLIDE_DOWN``
* ``Gtk.StackTransitionType.SLIDE_LEFT_RIGHT``
* ``Gtk.StackTransitionType.SLIDE_UP_DOWN``
* ``Gtk.StackTransitionType.OVER_UP``
* ``Gtk.StackTransitionType.OVER_DOWN``
* ``Gtk.StackTransitionType.OVER_LEFT``
* ``Gtk.StackTransitionType.OVER_RIGHT``
* ``Gtk.StackTransitionType.UNDER_UP``
* ``Gtk.StackTransitionType.UNDER_DOWN``
* ``Gtk.StackTransitionType.UNDER_LEFT``
* ``Gtk.StackTransitionType.UNDER_RIGHT``
* ``Gtk.StackTransitionType.OVER_UP_DOWN``
* ``Gtk.StackTransitionType.OVER_DOWN_UP``
* ``Gtk.StackTransitionType.OVER_LEFT_RIGHT``
* ``Gtk.StackTransitionType.OVER_RIGHT_LEFT``

Transition animation times can also be set by calling::

  gtk_stack_set_transition_duration(GTK_STACK(stack), duration);

The *duration* parameter should be specified in milliseconds.
