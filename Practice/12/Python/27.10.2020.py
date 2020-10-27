def F(a: int):
    if a > 1:
        return F(a - 1) * a
    else:
        return 1


var = int(input())
print(F(var))
