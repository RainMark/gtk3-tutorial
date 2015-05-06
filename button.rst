Button
======
The Button widget provides a way for a user to click to begin an operation. Examples of their use include deleting a file or spell checking a file.

===========
Constructor
===========
A Button is constructed with the call::

  GtkWidget *button = gtk_button_new();

Alternatively, if label text is to be set on the Button at construction::

  GtkWidget *button = gtk_button_new_with_label(text);

=======
Methods
=======
The label text to be displayed on the Button can be set post-construction with::

  gtk_button_set_label(GTK_BUTTON(button), text);

Text set on the Button can also be retrieved::

  gtk_button_get_label(GTK_BUTTON(button));

Mnemonic accelerator keys are accessibility features allowing a combination of :kbd:`ALT` and a chosen letter to be used as a shortcut. These shortcuts are identified by an underscore beneath a letter. This feature is enabled or disabled with::

  gtk_button_set_use_underline(GTK_BUTTON(button), use_underline);

When *use_underline* is set to ``TRUE``, the underscore in the Label is positioned under the letter it is before.

By default, Button widgets have a border and appear raised up. This can be adjusted with::

  gtk_button_set_relief(GTK_BUTTON(button), relief);

The *relief* parameter should be set to one of the following:

* ``GTK_RELIEF_NORMAL``
* ``GTK_RELIEF_NONE``

An image can be displayed on the Button via::

  gtk_button_set_image(GTK_BUTTON(button), image);

The *image* value should be set to the :doc:`image` to be displayed.

The position of any image added to the Button is set by::

  gtk_button_set_image_position(GTK_BUTTON(button), position);

Set the *position* value to one of the following:

* ``GTK_POS_LEFT``
* ``GTK_POS_RIGHT``
* ``GTK_POS_TOP``
* ``GTK_POS_BOTTOM``

Typically, when a Button is clicked, the Button gains the input focus. In some cases, this may not be desirable and can be configured with::

  gtk_button_set_focus_on_click(GTK_BUTTON(button), focus_on_click)

When *focus_on_click* is set to ``False``, the input will remain with the main content rather than on the Button.

=======
Example
=======
Below is an example of a Button:

.. literalinclude:: _examples/button.c

Download: :download:`Button <_examples/button.c>`
