a = float(input())
b = float(input())

print(a, b)
t = a
a = b
b = t
print(a, b)
a += b;
b = a - b;
a -= b;
print(a, b)