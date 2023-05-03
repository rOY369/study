# Structure of a Django Website

- A project is split into separate apps
- Each app handles a self-contained function that the site needs to perform. Here function is not programmatic function but as in a specific `functionality` of the website.
- For example instagram typically would have following django apps to provide separate functionalities
    - User Management : login, logout, register
    - Image feed : uploading, editing
    - Private msg
- There are 2 levels of configuration - project level and app level. Here configuration means general settings, URLs, templates and static files.
- A django app is structured to support the model-view-controller pattern. In each app, there are 3 separate files which handle 3 main pieces of logic 
    - Model: This defines the database and is the base layer to an application. 
    - View: Displays some or all data with HTML and CSS
    - Controller: handles how database and view interact. 
- Django is based on the MVC pattern but it handles the controller part by itself. 
- Django is more based on MVT (model-view-template) pattern where the view and template make up the view in MVC pattern. 

# Starting Project and Building First App

```
django-admin startproject <project-name>
```
Creates the project directory with required files.

```
python3 manage.py startapp <app-name>
```
Creates the app directory.

- Once an app is created, it needs to be added in `INSTALLED_APPS` of project settings.
- Views in an app are a collection of functions or classes where each func or class handles the logic that gets processed each time a different URL is visited. 
- `render` looks for HTML templates inside `<app>/templates/`
- URL configuration is added in project level urls.py using `urlpatterns` for mapping b/w url and app 
- Shared templates can be added in project level templates directory. A simple shared template is as follows

```
{% block page_content %}{% endblock %}
```
which is imported by app level template as follows

```
{% extends "base.html" %}

{% block page_content %}
<content>
{% endblock %}
```

# Models

- Django has built-in ORM (object relational model) that allows you to create classes that correspond to database tables. 
- Class attributes correspond to columns and instances of the class are rows. 
- Classes that represent tables are referred to as models. These classes live in models.py module of each app. 
- By default, Django ORM creates db in SQLite but we can use other databases that use the SQL language such as postgresql or MySQL
- To start the process of creating our db, we need to create a migration. A migration is a file containing the Migration class with rules that tell django what changes to make to the db. To create the migration, run the command

```
python3 manage.py makemigrations <app>
```

To apply the migration run
```
python3 manage.py migrate <app>
```

- Django shell can be used to create rows in a table
- `python3 manage.py shell` runs the shell