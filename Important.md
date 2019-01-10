** LECTURE 7 **

START EXAMPLE-------------------------------------------------------------
# Application.py

`app = Flask(__name__)`

`@app.route("/")`
`def index():`
    `return render_template("index.html")`


app = Flask(__name__)
    - This means "Turn this application into a web application"

@app.route('/')
    - I want to build an app that has a route that is listening for '/'

def index():
    - Flask, whenever you see a '/', go ahead and call this function --> index

return render_template("index.html")
    - Then show/render a file called index.html


# Templates Directory

- Conventional to make a separate directory to store html files and templates
Files to go here:
    - index.html
    - layout.html


# Index.html

- {{ name }}
    -


# Application.py EDIT @ 16:45

`app = Flask(__name__)`

`@app.route("/")`
`def index():`
    `name = request.args.get("name", "world")`
    `return render_template("index.html", name=name)`

name = request.args.get("name, "world")
    - Check the incoming request
    - Check its arguments aka any HTML parameters passed in
    - Try to get something called "name"
    - If there is no input with name, display "world" as default value

return render_template("index.html", name=name)
    - I want to pass in a name-variable and set it equal to the
        name-variable that I just defined in index.html -- {{ name }}
    ** The first variables name has to match the name in the {{ }}
        - It could read foo=name and I would have to have {{ foo }}
            corresponding to it


FROSHIMS.0 ---------------------------------------------------------------

# index.html

`<form action="/register" method="post">`
`<input name="name" placeholder="Name" type="text">`

<input name="name" placeholder="Name" type="text">
- This creates a form that will be submitted by the user

<form action="/register" method="post">
- This defines: "Where do we want to submit the form"
- We will submit the information to a route called /register
- We use POST because we want to go to a database and DO something
    so we are POSTING information as opposed to GETTING information
- POST information doesn't end up in URL and therefore not History
    so it is more privately stored

# application.py

`@app.route("/register", methods=["POST"])`
`def register`
    `name = request.form.get("name")`
    `dorm = request.form.get("dorm")`
    `if not name or not dorm:`
        `return "failure"`
    `return render_template("success.html")`


@app.route("/register"methods=["POST"])
    - I want to define a route called /register
    - It should be listening specifically on POST (default is GET)

name = request.form.get("name")
dorm = request.form.get("dorm")
    - Request.form is used because both name and dorm information is
        "coming in" via a POST-form in the html
     ** if we had defined a "get" then we use .args. instead of .form.

if not name or not dorm:
    return "failure"
    - If the user hasn't cooperating with the proper input,
        display "failure"

return render_template("success.html")
    - If the user has cooperated, display a page called success.html

# layout.html JINJA SYNTAX

`{% block body %} {% endblock %}`

{% block body %} {% endblock %}
- This serves as a template for the HTML that will be different on
    several different pages
- The HTML code unique to each page will go between block-body and
    endblock

# index.html EDIT @ 40:00

`{% extends "layout.html" %}`

{% extends "layout.html" %}
- This is the link between layout (which has the normal html) and
    this file -- index.html