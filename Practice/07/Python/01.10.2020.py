from math import sqrt

choice = float(input())

if choice == 1:
    # Через стороны
    a = float(input())
    b = float(input())
    c = float(input())

    p = (a + b + c) / 2

    print("S = ", sqrt(p * (p - a) * (p - b) * (p - c)), '\n')
elif choice == 2:
    # через координаты

    ax = float(input())
    ay = float(input())
    bx = float(input())
    by = float(input())
    cx = float(input())
    cy = float(input())

    ab_vec_x = bx - ax
    ab_vec_y = by - ay
    ab = sqrt(ab_vec_x * ab_vec_x + ab_vec_y * ab_vec_y)

    ac_vec_x = cx - ax
    ac_vec_y = cy - ay
    ac = sqrt(ac_vec_x * ac_vec_x + ac_vec_y * ac_vec_y)

    bc_vec_x = cx - bx
    bc_vec_y = cy - by
    bc = sqrt(bc_vec_x * bc_vec_x + bc_vec_y * bc_vec_y)

    p = (ab + ac + bc) / 2

    s = sqrt(p * (p - ab) * (p - ac) * (p - bc))

    print("S = ", s)
else:
    print("Данные введены неверно!\n")