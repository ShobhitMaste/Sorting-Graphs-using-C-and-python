from faker import Faker
import random
import pandas as pd


fake = Faker()
# for generating names

# salary data i made 
salary = [10000,20000,30000,40000,50000,60000,70000,80000,90000,100000,120000,130000,140000,150000,55000,72000,85000,12000,5000,24000,83000,39343,46205,37731,43525,39891,56642,60150,54445,64445,57189,63218,55794,56957,57081,61111,67938,66029,83088,81363,93940,91738,98273,101302,113812,109431,105582,116969,112635,122391,121872]

# make 5000 record random Data
with open("./5000_record/random_employees_5000.csv", "w") as f:
    f.write("empID,Name,Salary\n")
    for x in range(5000):
        empid = str(x)
        name = fake.name()
        Salary = str(random.choice(salary))
        f.write(empid + "," + name + "," + Salary +"\n")

# make 10000 record random Data

with open("./10000_record/random_employees_10000.csv", "w") as f:
    f.write("empID,Name,Salary\n")
    for x in range(10000):
        empid = str(x)
        name = fake.name()
        Salary = str(random.choice(salary))
        f.write(empid + "," + name + "," + Salary +"\n")

# make 15000 record random Data

with open("./15000_record/random_employees_15000.csv", "w") as f:
    f.write("empID,Name,Salary\n")
    for x in range(15000):
        empid = str(x)
        name = fake.name()
        Salary = str(random.choice(salary))
        f.write(empid + "," + name + "," + Salary +"\n")


ascending5000 = []
ascending10000 = []
ascending15000 = []
descending5000 = []
descending10000 = []
descending15000 = []

record5000 = []
record10000 = []
record15000 = []

for i in range(5000):
    empid = str(i)
    name = fake.name()
    Salary = random.choice(salary)
    record5000.append([Salary, empid, name])

for i in range(10000):
    empid = str(i)
    name = fake.name()
    Salary = random.choice(salary)
    record10000.append([Salary, empid, name])

for i in range(15000):
    empid = str(i)
    name = fake.name()
    Salary = random.choice(salary)
    record15000.append([Salary, empid, name])

ascending5000 = sorted(record5000)
ascending10000 = sorted(record10000)
ascending15000 = sorted(record15000)
descending5000 = sorted(record5000 , reverse=True)
descending10000 = sorted(record10000 , reverse=True)
descending15000 = sorted(record15000 , reverse=True)


# ascending 5000 employee generate

with open("./5000_record/ascending_employees_5000.csv", "w") as f:
    f.write("empID,Name,Salary\n")
    for x in range(5000):
        empid = str(ascending5000[x][1])
        name = ascending5000[x][2]
        Salary = str(ascending5000[x][0])
        f.write(empid + "," + name + "," + Salary +"\n")

# ascending 10000 employee generate

with open("./10000_record/ascending_employees_10000.csv", "w") as f:
    f.write("empID,Name,Salary\n")
    for x in range(10000):
        empid = str(ascending10000[x][1])
        name = ascending10000[x][2]
        Salary = str(ascending10000[x][0])
        f.write(empid + "," + name + "," + Salary +"\n")

# ascending 15000 employee generate

with open("./15000_record/ascending_employees_15000.csv", "w") as f:
    f.write("empID,Name,Salary\n")
    for x in range(15000):
        empid = str(ascending15000[x][1])
        name = ascending15000[x][2]
        Salary = str(ascending15000[x][0])
        f.write(empid + "," + name + "," + Salary +"\n")

# descending 5000 employee generate

with open("./5000_record/descending_employees_5000.csv", "w") as f:
    f.write("empID,Name,Salary\n")
    for x in range(5000):
        empid = str(descending5000[x][1])
        name = descending5000[x][2]
        Salary = str(descending5000[x][0])
        f.write(empid + "," + name + "," + Salary +"\n")

# ascending 10000 employee generate

with open("./10000_record/descending_employees_10000.csv", "w") as f:
    f.write("empID,Name,Salary\n")
    for x in range(10000):
        empid = str(descending10000[x][1])
        name = descending10000[x][2]
        Salary = str(descending10000[x][0])
        f.write(empid + "," + name + "," + Salary +"\n")

# ascending 15000 employee generate

with open("./15000_record/descending_employees_15000.csv", "w") as f:
    f.write("empID,Name,Salary\n")
    for x in range(15000):
        empid = str(descending15000[x][1])
        name = descending15000[x][2]
        Salary = str(descending15000[x][0])
        f.write(empid + "," + name + "," + Salary +"\n")
        

