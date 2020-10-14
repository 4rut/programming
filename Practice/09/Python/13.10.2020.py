import datetime

a = input()
b = input()

A = datetime.datetime.strptime(a, '%H:%M')
B = datetime.datetime.strptime(b, '%H:%M')

a1 = A.hour
b1 = B.hour
a2 = A.minute
b2 = B.minute

if a1 == b1:
    if (a2 < b2 and a2 + 15 >= b2) or (b2 < a2 and b2 + 15 >= a2):
        print("Встреча состоится\n")
    else:
        print("Встреча не состоится\n")
elif a1 > b1:
    if 60 - a2 + b2 <= 15:
        print("Встреча состоится\n")
    else:
        print("Встреча не состоится\n")
elif a1 < b1:
    if 60 - b2 + a2 <= 15:
        print("Встреча состоится\n")
    else:
        print("Встреча не состоится\n")
else:
    print("Встреча не состоится\n")
