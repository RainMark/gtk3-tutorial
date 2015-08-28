Revealer
========
The Revealer container is similar to a :doc:`expander` in that it provides an expandable/collapsable frame in which to place a child widget. Typically widgets added here are seldom used by the end-user. They are also used for advanced features which shouldn't be shown to users unless they specifically ask for them.

===========
Constructor
===========
The construction of the Revealer widget is made using::

  GtkWidget *revealer = gtk_revealer_new();

=======
Methods
=======
The child contained in the Revealer can be programatically shown using::

  gtk_revealer_set_reveal_child(GTK_REVEALER(revealer), reveal);

When *reveal* is set to ``TRUE``, the animation runs and the child is displayed.

The state of the Revealer can also be obtained via::

  gtk_revealer_get_reveal_child(GTK_REVEALER(revealer));

Customisation of the animation transition can be changed with::

  gtk_revealer_set_transition_duration(GTK_REVEALER(revealer), duration);

The *duration* value should be specified in milliseconds.

A transition type can be defined for the Revealer by calling::

  gtk_revealer_set_transitiion_type(GTK_REVEALER(revealer), transition);

The *transition* value should be set to one of the following:

* ``GTK_REVEALER_TRANSITION_TYPE_NONE`` - no transition
* ``GTK_REVEALER_TRANSITION_TYPE_CROSSFADE`` - fade in
* ``GTK_REVEALER_TRANSITION_TYPE_SLIDE_RIGHT`` - slide in from left
* ``GTK_REVEALER_TRANSITION_TYPE_SLIDE_LEFT`` - slide in from right
* ``GTK_REVEALER_TRANSITION_TYPE_SLIDE_UP`` - slide in from bottom
* ``GTK_REVEALER_TRANSITION_TYPE_SLIDE_DOWN`` - slide in from top
