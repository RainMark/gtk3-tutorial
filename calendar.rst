Calendar
========
The Calendar widget allows for dates to be displayed and selected. It is customisable so that months and years can be viewed, and dates can be marked.

===========
Constructor
===========
The constructor for the Calendar widget is::

  GtkWidget *calendar = gtk_calendar_new();

=======
Methods
=======
There are two functions used for setting the date, month, and year::

  gtk_calendar_select_day(GTK_CALENDAR(calendar), day);
  gtk_calendar_select_month(GTK_CALENDAR(calendar), month, year);

The *day* value should be set to the date of the month. The *month* value is settable to a month number identifying the month, with ``0`` used for January and ``11`` for December. The *year* is set to the appropriate year.

The date is also retrievable using::

  gtk_calendar_get_date(GTK_CALENDAR(calendar));

The method returns the three values for the year, month, and day.

Marking of days is useful when an event is associated with a particular day. This places a marker next to the date and is set and unset with::

  gtk_calendar_mark_day(GTK_CALENDAR(calendar), day);
  gtk_calendar_unmark_day(GTK_CALENDAR(calendar), day);

To retrieve whether a day is marked, call::

  gtk_calendar_get_day_is_marked(GTK_CALENDAR(calendar), day);

All the marks set on the Calendar can be cleared via the method::

  gtk_calendar_clear_marks(GTK_CALENDAR(calendar));

The Calendar can be customised by setting a number of displays flags on the method::

  gtk_calendar_set_display_options(GTK_CALENDAR(calendar), flags);

The *flags* argument can be set to any of the following values:

* ``GTK_CALENDAR_SHOW_HEADING``
* ``GTK_CALENDAR_SHOW_DAY_NAMES``
* ``GTK_CALENDAR_NO_MONTH_CHANGE``
* ``GTK_CALENDAR_SHOW_WEEK_NUMBERS``
* ``GTK_CALENDAR_SHOW_DETAILS``

The ``GTK_CALENDAR_SHOW_HEADING`` flag enables the heading which displays the month and year. ``GTK_CALENDAR_SHOW_DAY_NAMES`` sets the three letter day to be displayed. Preventing month and year changes from being made by adding the flag ``GTK_CALENDAR_NO_MONTH_CHANGE``. In some cases, it is useful to display the week numbers via ``GTK_CALENDAR_SHOW_WEEK_NUMBERS``. Each flag should be separated from another by a pipe '|' character.
