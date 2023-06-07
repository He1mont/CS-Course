#!/usr/bin/env python3
import sqlite3
from flask import (Flask, render_template, url_for, redirect, request)
app = Flask(__name__)

@app.route('/')
def get_students_info():
	
	# Establish a connection with our Student DB file
	conn = sqlite3.connect('Students.db')
	
	# Converts the plain tuple result into a more useful object.
	conn.row_factory = sqlite3.Row

	# sqlite3.Cursor allows us to execute SQLite statements, fetch data 
	# from the result sets of the queries.
	cur = conn.cursor()

	# Here we say - execute this SQL query 
	cur.execute("SELECT * FROM Student LEFT JOIN Grade ON Student.ID = Grade.ID;")
	
	# Fetch all the results from the above query. 
	# We may alternatively request a single - fetchone
	rows = cur.fetchall()
	
	return render_template("students.html",rows = rows)

@app.route('/add_new_student/')
def add_new_student():
	return render_template("addStudent.html")

@app.route('/add_student_to_db/', methods = ['POST'])
def add_student_to_db():
	
	# Should always be true, as we specified the Method above
	if request.method == 'POST':
		id = request.form['id']
		first = request.form['first']
		last = request.form['last']
	
	# Using "with" will automatically close the connection to the
	# sqlite DB after the inner block completes
	with sqlite3.connect("Students.db") as conn:
		# Uncomment the below statement to enable autocommits
		# conn.isolation_level = None
		try:
			cur = conn.cursor()
			cur.execute("INSERT INTO Student (ID,First,Last) VALUES (?,?,?)", (id, first, last) )
			# IMPORTANT - Commit your changes, or they (may) be lost
			conn.commit()
		except sqlite3.Error as er:
			print("There  was an error adding a new student to the DB!")
			print(er)
		
	return redirect(url_for('get_students_info'))
	
if __name__ == '__main__':
	app.debug = True
	app.run(port=5000)
	