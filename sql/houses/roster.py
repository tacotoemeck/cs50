from cs50 import SQL
from csv import reader
from sys import argv

db = SQL("sqlite:///students.db")

if len(argv) != 2:
    print("usage error, roster.py houseName")
    exit()

students = db.execute("SELECT * FROM students WHERE house = (?) ORDER BY last", argv[1])

for student in students:
    student_details = f"{student['first']} {student['middle'] or '' } {student['last'] }, born {student['birth']}"
    print(student_details)