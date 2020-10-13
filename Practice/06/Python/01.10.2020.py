from math import sqrt


a = float(input())
b = float(input())
c = float(input())

if a == 0:
    print("x = ", -c / b, '\n')
else:
    D = b * b - 4 * a * c

    if D < 0:
        print("Корней нет\n")

    elif D == 0:
        print("x = ", -b / (2 * a), '\n')
    else:
        print("x1 = ", (-b + sqrt(D)) / (2 * a), '\n')
        print("x2 = ", (-b - sqrt(D)) / (2 * a), '\n')