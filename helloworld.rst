Hello, World!
=============
As is customary with any programming tutorial, a "Hello, World!" example is required.

.. literalinclude:: _examples/helloworld.c

Download: :download:`Hello World <_examples/helloworld.c>`

The example above showcases the simple display of a :doc:`window`, with an embedded :doc:`label` to display the text. It can be compiled using GCC with the following:

``gcc helloworld.c `pkg-config --libs --cflags gtk+-3.0` helloworld``

Alternatively, if you use the Clang compiler:

``clang helloworld.c `pkg-config --libs --cflags gtk+-3.0` helloworld``
