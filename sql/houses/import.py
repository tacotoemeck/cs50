from cs50 import SQL
from csv import reader
from sys import argv

db = SQL("sqlite:///students.db")

if len(argv) != 2:
    print("usage error, import.py characters.csv")
    exit()

with open(argv[1]) as student_file:
    file_reader = reader(student_file)
    for row in file_reader:
        if row[0] != 'name':
            full_name = row[0].split()
            if len(full_name) == 3 :
                db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                            full_name[0], full_name[1], full_name[2], row[1], row[2])
            else:
                    db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                            full_name[0], None, full_name[1], row[1], row[2])


