'''#factorial 
a=int(input("Enter "))
k=1
for i in range(1,a+1):
    k=k*i
print(k)
#prime number between
lower= int(input("lower= "))
upper= int(input("upper= "))
for num in range (lower,upper+1):
    if num > 1:
        for i in range(2,num):
            if(num%i)==0:
                break
    else:
        print(num)
def plus(a,b):
    sum = a+b
    return sum,a
sum,a=plus(3,4)
print(sum)'''

# for i in range(10):
#     print(i,end=" ")

# l=1,2,34,5,57,3,45,57,673543,3,4,65,4,67345,64,74
# print(type(l))
# for i in range(len(l)):
#     print(l[i],end=" ")

# sum = 0
# for i in range(1,11):
#     sum += i
#     print(sum)

# str = 1,2,3,4,5,6,7,8,9,0,10,12,13,14,15,16,17,18,19,20
# str = "123456789012345678901234567890"
# print(str[3:18])
# print(str[2:14:2])
# print(str[:7])
# print(str[2:-1:2])
# print(str[ -1::-1])

# def char(str,n):
#     l=str[1:]

def matrix():
    mat1=[[1,2],[3,4]]
    mat2=[[5,6],[7,8]]
    print("matrix1")
    for row in mat1:
        for ele in row:
            print(ele, end=" ")
        print()
    print("matrix2")
    for row in mat2:
        for ele in row:
            print(ele, end=" ")
        print()
    print("add")
    result1=[[0,0],[0,0]]
    for i in range(len(mat1)):
        for j in range(len(mat1[0])):
            result1[i][j] = mat1[i][j] + mat2[i][j]
    for row in result1:
        for ele in row:
            print(ele, end=" ")
        print()
    print("sub")
    result1=[[0,0],[0,0]]
    for i in range(len(mat1)):
        for j in range(len(mat1[0])):
            result1[i][j] = mat1[i][j] - mat2[i][j]
    for row in result1:
        for ele in row:
            print(ele, end=" ")
        print()
    print("tra")
    result1=[[0,0],[0,0]]
    for i in range(len(mat1)):
        for j in range(len(mat1[0])):
            result1[i][j] = mat1[j][i]
    for row in result1:
        for ele in row:
            print(ele, end=" ")
        print()
#matrix()

def com(f,g):
    return lambda x:f(g(x))
def add(x):
    return x+2
def mul(x):
    return x*2
#add_mul = com(mul,add)
#print(add_mul(5))

# try:
#     n1,n2= eval(input("Enter two number , separated by a comma :"))
#     result = n1/n2
#     print(result)
# except ZeroDivisionError:
#     print("Division by zero is error")
# except SyntaxError:
#     print("missing , ")
# except:
#     print("Wrong input")
# else:
# finally:
#     print("excute")


# my_file = open("/home/spdk/data/sh.txt",'a')

# with open("/home/spdk/data/sh.txt",'a',encoding='utf-8') as f:
#     f.write("#spdk\n")
#     my_file = open("/home/spdk/data/sh.txt",'r')
# print(my_file.read())

# import numpy as np 
# import pandas as pd
# numpyArray = np.array([[5,22,3],[13,24,6]])
# columns = ['x','y','z']
# panda_df = pd.DataFrame(data = numpyArray,index =["A","B"],columns=columns)
# print(panda_df)

# import tkinter as tk
# master = tk.TK()
# master.title("MarkSheet")
# mater.geomentry("700x250")
# e1 = tk.Enter(master)
# e2 = tk.Enter(master)
# e3 = tk.Enter(master)
# e4 = tk.Enter(master)
# e5 = tk.Enter(master)
# e6 = tk.Enter(master)
# e7 = tk.Enter(master)

import tkinter as tk

def calculate_total():
    try:
        # Get input values
        math_score = float(math_entry.get())
        science_score = float(science_entry.get())
        english_score = float(english_entry.get())

        # Calculate total and average
        total = math_score + science_score + english_score
        average = total / 3

        # Update labels
        total_label.config(text=f"Total: {total:.2f}")
        average_label.config(text=f"Average: {average:.2f}")
    except ValueError:
        total_label.config(text="Invalid input. Enter numeric scores.")

# Create the main window
root = tk.Tk()
root.title("Student Marksheet")

# Add input fields
math_label = tk.Label(root, text="Math Score:")
math_label.pack()
math_entry = tk.Entry(root)
math_entry.pack()

science_label = tk.Label(root, text="Science Score:")
science_label.pack()
science_entry = tk.Entry(root)
science_entry.pack()

english_label = tk.Label(root, text="English Score:")
english_label.pack()
english_entry = tk.Entry(root)
english_entry.pack()

# Add a button to calculate total
calculate_button = tk.Button(root, text="Calculate Total", command=calculate_total)
calculate_button.pack()

# Display total and average
total_label = tk.Label(root, text="")
total_label.pack()

average_label = tk.Label(root, text="")
average_label.pack()

# Start the Tkinter event loop
root.mainloop()

