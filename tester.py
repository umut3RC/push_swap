import random

min = -2147483648
max = 2147483647
rang = 500
liste = []
check = 0
b = ""
for i in range(0, rang):
    while (1):
        a = random.randint(min, max)
        for j in liste:
            if (a == j):
                check = 1
                break
        if (check == 0):
            break
    liste.append(a)
for i in liste:
    b = b + " " + str(i)
f = open("argv.txt", "w")
f.write(b)