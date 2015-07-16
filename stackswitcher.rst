StackSwitcher
=============
A StackSwitcher is an object associated with a :doc:`stack` to provide an interface to switch children in the Stack. The layout provides a horizontal bar with a button for each child in the Stack.

===========
Constructor
===========
The StackSwitcher can be constructed via::

  stackswitcher = gtk_stack_switcher_new();

=======
Methods
=======
The StackSwitcher can be attached to the Stack via::

  stackswitcher.set_stack(stack)

Retrival of the associated Stack object can be made using::

  stackswitcher.get_stack()
