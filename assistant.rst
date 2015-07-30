Assistant
=========
The Assistant (also referred to as a Wizard in some cases) provides step-by-step iteration through screens displayed to the user. These may be to simply display information, but are more commonly used to retrieve input in a specific order. A common use case includes the initial setup of an email client.

===========
Constructor
===========
The Assistant is constructed via::

  GtkWidget *assistant = gtk_assistant_new();

=======
Methods
=======
Pages are inserted into the Assistant by the following::

  gtk_assistant_append_page(GTK_ASSISTANT(assistant), page);
  gtk_assistant_prepend_page(GTK_ASSISTANT(assistant), page);
  gtk_assistant_insert_page(GTK_ASSISTANT(assistant), page, position);

All the methods take a page object, which is typically a container such as a :doc:`grid` or `box` from which additional widgets are added. The ``insert_page()`` method allows pages to be added at a specific point by referencing the position starting at ``0``.

A page can also be removed by defining the page number to remove::

  gtk_assistant_remove_page(GTK_ASSISTANT(assistant), position);

The visible page can be set via::

  gtk_assistant_set_current_page(GTK_ASSISTANT(assistant), position);

Alternatively, the currently visible page can be retrieved using::

  gtk_assistant_get_current_page(GTK_ASSISTANT(assistant));

The page widget located at a particular position can be retrieved by calling::

  gtk_assistant_get_nth_page(GTK_ASSISTANT(assistant), position);

To retrieve the total number of pages contained within the Assistant use::

  gtk_assistant_get_n_pages(GTK_ASSISTANT(assistant));

Each page within the Assistant can be of a particular type. The type is typically set based on the content of the screen. This is done by the method::

  gtk_assistant_set_page_type(GTK_ASSISTANT(assistant), page, page_type);

The *page* parameter should be set to the page object being typed. The *page_type* must be set to one of the following constants:

* ``GTK_ASSISTANT_PAGE_CONTENT`` - the page has regular content and both Back and Forward buttons will be displayed.
* ``GTK_ASSISTANT_PAGE_INTRO`` - only a Forward button is shown on the page which typically introduces the Assistant purpose.
* ``GTK_ASSISTANT_PAGE_CONFIRM`` - display to allow the user to confirm the changes. A Back and Apply button will be shown.
* ``GTK_ASSISTANT_PAGE_SUMMARY`` - inform user of changes made, and display only a Close button.
* ``GTK_ASSISTANT_PAGE_PROGRESS`` - used for tasks which take a long time to complete, with a Back button displayed.
* ``GTK_ASSISTANT_PAGE_CUSTOM`` - used when none of the other page types are appropriate. The buttons should be added manually.

A title can be associated with each page via::

  gtk_assistant_set_page_title(GTK_ASSISTANT(assistant), title);

In some cases, the Assistant should prevent the user from continuing unless the page has been completed. This can be set programmatically via the use of::

  gtk_assistant_set_page_complete(GTK_ASSISTANT(assistant), page, complete);

The *page* parameter should be set to the page widget. The *complete* argument will initially be set to ``FALSE``, and the page buttons will be insensitive. Once complete, the state can be set to ``TRUE`` and the buttons will be updated to allow the user to continue.

The action area is the location on the Assistant where the buttons are located. Additional widgets can be added and removed from this area via the methods::

  gtk_assistant_add_action_widget(GTK_ASSISTANT(assistant), widget);
  gtk_assistant_remove_action_widget(GTK_ASSISTANT(assistant), widget);

Additional methods are also available to control the Assistant::

  gtk_assistant_next_page(GTK_ASSISTANT(assistant));
  gtk_assistant_previous_page(GTK_ASSISTANT(assistant));
  gtk_assistant_commit(GTK_ASSISTANT(assistant));

The ``previous_page()`` and ``next_page()`` methods allow the Assistant to programmatically move backwards or forwards. The ``commit()`` method allows changes made up to the current page to be made permanent. This has the effect of clearing page visited history, and removing the Cancel button from subsequent pages.
