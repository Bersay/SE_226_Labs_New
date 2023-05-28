import mysql.connector
import tkinter as tk
from tkinter import messagebox, simpledialog

def create_database_and_table():
    database = mysql.connector.connect(
        host="localhost",
        user="root",
        password="admin"
    )
    cursorObject = database.cursor()
    cursorObject.execute("DROP DATABASE IF EXISTS lab9database")
    cursorObject.execute("CREATE DATABASE lab9database")
    connection = mysql.connector.connect(
        host="localhost",
        user="root",
        database="lab9database",
        password="admin"
    )
    cursorObject = connection.cursor()
    cursorObject.execute("DROP TABLE IF EXISTS Marvel")
    create_query = """CREATE TABLE Marvel (
                            ID int(11) NOT NULL,
                            Movie varchar(250) NOT NULL,
                            DateInfo varchar(250) NOT NULL,
                            Mcu_Phase varchar(250),
                            PRIMARY KEY (ID))"""
    cursorObject.execute(create_query)
    connection.close()

def populate_table():
    connection = mysql.connector.connect(
        host="localhost",
        user="root",
        database="lab9database",
        password="admin"
    )
    cursorObject = connection.cursor()
    with open("Marvel.txt", "r") as file:
        for line in file:
            parts = line.strip().split()
            if len(parts) == 4:
                ID, MOVIE, DATE, MCU_PHASE = parts
                insert_query = """INSERT INTO Marvel (ID, Movie, DateInfo, Mcu_Phase) VALUES (%s, %s, %s, %s)"""
                record = (ID, MOVIE, DATE, MCU_PHASE)
                cursorObject.execute(insert_query, record)
    connection.commit()
    connection.close()


def update_text_box():
    selected_id = dropdown_var.get()
    connection = mysql.connector.connect(host="localhost", user="root", database="lab9database", password="admin")
    cursor = connection.cursor()
    cursor.execute(f"SELECT * FROM Marvel WHERE ID = {selected_id}")
    record = cursor.fetchone()
    connection.close()
    text_box.delete(1.0, tk.END)
    if record:
        text_box.insert(tk.END, record)

def add_movie():
    new_movie = simpledialog.askstring("Input", "Enter the new movie in the format: ID MOVIE DATE MCU_PHASE")
    if new_movie:
        ID, MOVIE, DATE, MCU_PHASE = new_movie.split()
        connection = mysql.connector.connect(host="localhost", user="root", database="lab9database", password="admin")
        cursor = connection.cursor()
        insert_query = """INSERT INTO Marvel (ID, Movie, DateInfo, Mcu_Phase) VALUES (%s, %s, %s, %s)"""
        record = (ID, MOVIE, DATE, MCU_PHASE)
        cursor.execute(insert_query, record)
        connection.commit()
        connection.close()
        dropdown_var.set("")
        text_box.delete(1.0, tk.END)

def list_all():
    connection = mysql.connector.connect(host="localhost", user="root", database="lab9database", password="admin")
    cursor = connection.cursor()
    cursor.execute("SELECT * FROM Marvel")
    records = cursor.fetchall()
    connection.close()
    text_box.delete(1.0, tk.END)
    for record in records:
        text_box.insert(tk.END, record)
        text_box.insert(tk.END, "\n")

create_database_and_table()
populate_table()

root = tk.Tk()

dropdown_var = tk.StringVar(root)
dropdown_var.trace('w', lambda *args: update_text_box())

connection = mysql.connector.connect(host="localhost", user="root", database="lab9database", password="admin")
cursor = connection.cursor()
cursor.execute("SELECT ID FROM Marvel")
ids = [id[0] for id in cursor.fetchall()]
connection.close()

dropdown = tk.OptionMenu(root, dropdown_var, *ids)
dropdown.pack()

text_box = tk.Text(root)
text_box.pack()

add_button = tk.Button(root, text="Add", command=add_movie)
add_button.pack()

list_all_button = tk.Button(root, text="List All", command=list_all)
list_all_button.pack()

root.mainloop()