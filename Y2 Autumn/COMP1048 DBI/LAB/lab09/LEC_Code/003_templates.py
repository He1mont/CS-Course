#!/usr/bin/env python3

from flask import (Flask, render_template, url_for, redirect)
app = Flask(__name__)

@app.route('/')
def default():
    return redirect(url_for('get_modules_credits'))

@app.route('/hello/<name>')
def hello_person(name):
    # Strip - Removes and preceding and trailing whitespace from a string
    # Capitalize - capitalizes the first character
    lname = name.strip().capitalize()
    return render_template("greetings.html", person=lname)

@app.route('/modules/')
def get_modules_credits():
    # This is a dictionary of values, where the module codes act as
    # keys, and the module credits are values. 
    mod_creds = {'DBI':10,'PGA':20,'FYP':40}
    return render_template('module_credits.html', result = mod_creds)


@app.route('/inherit')
def inherit():
    return render_template("inherit.html")

if __name__ == '__main__':
    app.debug = True
    app.run(port=5000)
    