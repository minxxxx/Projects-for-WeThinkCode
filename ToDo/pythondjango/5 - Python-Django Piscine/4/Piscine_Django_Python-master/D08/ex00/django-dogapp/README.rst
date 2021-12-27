=====
dogapp
=====

dogapp is a simple Django app to select dog images.

Detailed documentation is in the "docs" directory.

Quick start
-----------

1. Add "dogapp" to your INSTALLED_APPS setting like this::

    INSTALLED_APPS = [
        ...
        'dogapp',
    ]

2. Include the polls URLconf in your project urls.py like this::

    url(r'^dogapp/', include('dogapp.urls')),

3. Run `python manage.py migrate` to create the dogapp models.

4. Start the development server and visit http://127.0.0.1:8000/dogapp/
   to start using the app