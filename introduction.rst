Introduction
============

==========================
Before using this tutorial
==========================
Before working through any of this tutorial, it is advised that you have a good grasp of C programming. Working with graphical interfaces poses new challenges and problems compared to interacting with the Standard Output.

Prior knowledge of GTK+ is not required, but experience with its use in other languages is beneficial.

===================
About this tutorial
===================
This guide does not walk through creating an application. It merely provides informational on each widget in GTK+, and describes their use.

It also assumes that you are using up-to-date versions of GCC or Clang, and GTK+. The GTK+ version is recommended to be as new as possible, with the tutorial being written using 3.16.

===========
Deprecation
===========
Deprecation is the process of preparing features within software to be decommisioned or removed. GTK+ deprecates objects by providing warnings both in the GTK+ framework and documentation prior to removal at a later date. This allows developers to change their code before a feature is removed.

Reasons for deprecation include:

* A feature has been replaced.
* A feature is no longer seen as widely-used.
* A feature no longer can be used.

It is highly recommended to not use deprecated features of GTK+ when developing applications, particularly when learning as they can cause problems when understanding other areas of the library.

This tutorial does not cover widgets which have been marked as deprecated. Any widgets marked as deprecated by GTK+ in the future will also be removed from future versions of the tutorial.

=======
Contact
=======
Please contact me at andrew@andrewsteele.me.uk to report issues, bugs and provide comments. All suggestions are welcome.

=======
License
=======
* The tutorial text and code examples are released under a `CC0 1.0 Universal <http://creativecommons.org/publicdomain/zero/1.0/>`_ (CC0 1.0) license (this essentially makes them Public Domain).
* The GTK+ logo used for examples and the site favicon is released under the `Creative Commons Attribution-Share Alike 3.0 Unported <http://creativecommons.org/licenses/by-sa/3.0/deed.en>`_ license.
