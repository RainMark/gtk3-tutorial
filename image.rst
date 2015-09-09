Image
=====
The Image widget provides functionality for displaying images within an application. It can be used for small icons up to large photographs, and provides the ability to load from a variety of sources.

===========
Constructor
===========
The constructor for the Image widget is::

  GtkWidget *image = gtk_image_new();

Alternatively, the image to be loaded can be supplied at construction time with::

  GtkWidget *image = gtk_image_new_from_file(filename);
  GtkWidget *image = gtk_image_new_from_pixbuf(pixbuf);
  GtkWidget *image = gtk_image_new_from_icon_name(name, size);

The *filename* parameter of the ``gtk_image_new_from_file`` constructor should be set to the full path of an image (e.g. a JPG, PNG, SVG, GIF, etc). The *pixbuf* argument allows a GTK+ pixbuf object to be loaded and shown with the ``gtk_image_new_from_pixbuf`` method. Icons can also be displayed by supplying the *name* in the ``gtk_image_new_from_icon_name`` method, with a *size* also required which should be set to:

* ``GTK_ICON_SIZE_MENU`` - 16 pixels
* ``GTK_ICON_SIZE_SMALL_TOOLBAR`` - 16 pixels
* ``GTK_ICON_SIZE_LARGE_TOOLBAR`` - 24 pixels
* ``GTK_ICON_SIZE_BUTTON`` - 16 pixels
* ``GTK_ICON_SIZE_DND`` - 32 pixels
* ``GTK_ICON_SIZE_DIALOG`` - 48 pixels

=======
Methods
=======
The image displayed on the widget can be changed post-construction by calling::

  gtk_image_set_from_file(GTK_IMAGE(image), filename);
  gtk_image_set_from_pixbuf(GTK_IMAGE(image), pixbuf);
  gtk_image_set_from_icon_name(GTK_IMAGE(image), name, size);

Clearing of the Image widget and removing the associated image is done via::

  gtk_image_clear(GTK_IMAGE(image));
