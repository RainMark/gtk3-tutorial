StackSidebar
============
The StackSidebar can be connected to the :doc:`stack` to provide a sidebar for switching between the children contained in the Stack.

===========
Constructor
===========
A StackSidebar is constructed using::

  stacksidebar = gtk_stack_sidebar_new();

=======
Methods
=======
To associate the Stack with the StackSidebar call::

  stacksidebar.set_stack(stack)

Retrieval of the Stack associated can be made via::

  stacksidebar.get_stack()
