#!/usr/bin/env python3

from flask import (Flask, url_for, render_template, request)
app = Flask(__name__)

@app.route('/')
def show_form():
    return render_template("form.html")


@app.route('/sayhi/', methods=['GET','POST'])
def sayhi():
    # Note the difference in accessing form values depending
    # on how the information is sent to the server (POST vs GET)
    if request.method == 'GET':
        name = request.args['name']
        age = request.args['age']
        tel = request.args['tel']
        return '[GET] - {}, {}, and {}'.format(name,age,tel)
    else:
        name = request.form['name']
        age = request.form['age']
        tel = request.form['tel']
        return '[POST] - {}, {}, and {}'.format(name,age,tel)
    
if __name__ == '__main__':
    app.debug = True
    app.run(port=5000)
