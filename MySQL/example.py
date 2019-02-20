# An example of using MySQL with Python
# Creating a school data base with information about students, classes, etc.
# Using XAMPP for the database and pymysql as the python connection library
import pymysql

# MySQL code for creating tables using XAMPP
"""
CREATE TABLE students(id INTEGER PRIMARY KEY AUTO_INCREMENT,
                       name VARCHAR(50),
                       student_id INT,
                       email VARCHAR(50),
                       phone VARCHAR(20))

CREATE TABLE classes(class_id INT,
                     title VARCHAR(50),
                     teacher VARCHAR(50))

CREATE TABLE student_classes(student_id INT,
                             class_id INT)

CREATE TABLE teachers(id INTEGER PRIMARY KEY AUTO_INCREMENT,
                      name VARCHAR(50),
                      email VARCHAR(50),
                      phone VARCHAR(20))
"""

# For Students table
def addStudent(connection, name='', student_id=0, email='', phone=''):
    # Adds student info into table
    try:
        with connection.cursor() as cursor:
            sql = "INSERT INTO students (name, student_id, email, phone) VALUES (%s, %s, %s, %s)"
            try:
                cursor.execute(sql, (name, student_id, email, phone))
            except:
                print('Failed to add student: {}'.format(name))
        connection.commit()
    except:
        print("Failed to commit student: {}".format(name))

def deleteStudentEntries(connection):
    # Removes entries from students table
    try:
        with connection.cursor() as cursor:
            sql = """DELETE FROM students
                     WHERE id>=0;"""
            try:
                cursor.execute(sql)
            except:
                print('Failed to delete students')
        connection.commit()
    except:
        print("Failed to commit delete students")

# For classes table
def addClass(connection, class_id = 0, title='', teacher=''):
    # Adds class info into table
    try:
        with connection.cursor() as cursor:
            sql = "INSERT INTO classes (class_id, title, teacher) VALUES (%s, %s, %s)"
            try:
                cursor.execute(sql, (class_id, title, teacher))
            except:
                print('Failed to add class: {}'.format(title))
        connection.commit()
    except:
        print("Failed to commit class: {}".format(title))

def deleteClassesEntries(connection):
    # Removes entries from classes table
    try:
        with connection.cursor() as cursor:
            sql = """DELETE FROM classes
                     WHERE class_id>=0;"""
            try:
                cursor.execute(sql)
            except:
                print('Failed to delete classes')
        connection.commit()
    except:
        print("Failed to commit delete classes")

# For student classes table
# Identifies which student is taking which class
def addStudentClass(connection, student_id=0, class_id=0):
    # Adds student class info into table
    try:
        with connection.cursor() as cursor:
            sql = "INSERT INTO student_classes (student_id, class_id) VALUES (%s, %s)"
            try:
                cursor.execute(sql, (student_id, class_id))
            except:
                print('Failed to add student class')
        connection.commit()
    except:
        print("Failed to commit student class")

def deleteStudentClassesEntries(connection):
    # Removes entries from classes table
    try:
        with connection.cursor() as cursor:
            sql = """DELETE FROM student_classes
                     WHERE student_id>=0;"""
            try:
                cursor.execute(sql)
            except:
                print('Failed to delete student classes')
        connection.commit()
    except:
        print("Failed to commit delete student classes")

# Teacher table
def addTeacher(connection, name='', email='', phone=''):
    # Adds student info into table
    try:
        with connection.cursor() as cursor:
            sql = "INSERT INTO teachers (name,  email, phone) VALUES (%s, %s, %s)"
            try:
                cursor.execute(sql, (name, email, phone))
            except:
                print('Failed to add teacher: {}'.format(name))
        connection.commit()
    except:
        print("Failed to commit teacher: {}".format(name))

def deleteTeacherEntries(connection):
    # Removes entries from students table
    try:
        with connection.cursor() as cursor:
            sql = """DELETE FROM teachers
                     WHERE id>=0;"""
            try:
                cursor.execute(sql)
            except:
                print('Failed to delete teachers')
        connection.commit()
    except:
        print("Failed to commit delete teachers")

# Put sample data into tables
def sampleTables(connection):
    # Adds sample data to tables

    # Student Info
    addStudent(connection, 'Aaron', 1111, 'aaron@school.edu', '263')
    addStudent(connection, 'Dylan', 1112, 'dylan@school.edu', '592')
    addStudent(connection, 'Brandon', 1113, 'brandon@school.edu', '163')
    addStudent(connection, 'Sally', 1114, 'sally@school.edu', '062')
    addStudent(connection, 'Sarah', 1115, 'sarah@school.edu', '954')
    addStudent(connection, 'Matt', 1116, 'matt@school.edu', '654')
    addStudent(connection, 'Billy', 1117, 'billy@school.edu', '741')

    # Teacher Info
    addTeacher(connection, 'Joe', 'joe@school.edu', '858')
    addTeacher(connection, 'George', 'george@school.edu', '952')
    addTeacher(connection, 'Jane', 'jane@school.edu', '949')
    addTeacher(connection, 'Molly', 'molly@school.edu', '365')

    # Class Info
    addClass(connection, 1, 'Physics', 'Joe')
    addClass(connection, 2, 'Programming Python', 'George')
    addClass(connection, 3, 'Programming SQL', 'George')
    addClass(connection, 4, 'History', 'Jane')
    addClass(connection, 5, 'Humanities', 'Jane')
    addClass(connection, 6, 'Art', 'Molly')
    addClass(connection, 7, 'Math', 'Joe')

    # Student Class Info
    addStudentClass(connection, 1111, 1)
    addStudentClass(connection, 1112, 1)
    addStudentClass(connection, 1113, 1)
    addStudentClass(connection, 1111, 2)
    addStudentClass(connection, 1111, 3)
    addStudentClass(connection, 1114, 7)
    addStudentClass(connection, 1112, 7)
    addStudentClass(connection, 1111, 7)
    addStudentClass(connection, 1117, 6)
    addStudentClass(connection, 1114, 6)
    addStudentClass(connection, 1115, 4)
    addStudentClass(connection, 1115, 5)
    addStudentClass(connection, 1116, 4)
    

def deleteAllTables(connection):
    # Removes the data from all tables
    deleteStudentEntries(connection)
    deleteClassesEntries(connection)
    deleteStudentClassesEntries(connection)
    deleteTeacherEntries(connection)
    print('Deleted all data from tables')

# Selecting Data
def printSelect(sqlFetch):
    # Prints each item separated by a tab
    result = ""
    for row in sqlFetch:
        for i, item in enumerate(row):
            result+=str(item)
            if i!=len(row)-1:
                result+='\t'
            else:
                result+='\n'
    print(result)

def selectStatement(connection, statement):
    # Executes the given SQL statement and prints the
    # data separated by tabs
    try:
        with connection.cursor() as cursor:
            cursor.execute(statement)
            result = cursor.fetchall()
            printSelect(result)
    except:
        print("Failed to execute select statement")
    

if __name__ == '__main__':
    # Connect to server
    try:
        connection = pymysql.connect(
            host='localhost',
            user='root',
            password='',
            db='school',
            )
        print('Connected')
    except:
        print('Failed to connect')

    # Create the sample data (need to run once)
    # Commented to prevent duplicate entries
    # sampleTables(connection)

    sql1 = """SELECT students.name, classes.title FROM students
              JOIN student_classes ON students.student_id = student_classes.student_id
              JOIN classes ON classes.class_id = student_classes.class_id
              ORDER BY students.name, classes.title
              """
    print('Name\tClass\n-------------')
    selectStatement(connection, sql1)

    sql2 = """SELECT DISTINCT classes.title, COUNT(student_id) as Number_Enrolled FROM classes
              JOIN student_classes ON student_classes.class_id = classes.class_id
              GROUP BY classes.title
              ORDER BY classes.title
           """
    print('Class\tNumber_Enrolled\n-----------------------')
    selectStatement(connection, sql2)

    # Delete all the data in the tables
    # Commented out to keep current data for reuse
    # deleteAllTables(connection)
    connection.close()
