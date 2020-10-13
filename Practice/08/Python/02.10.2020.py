a = float(input())
sym = input()
b = float(input())

if sym == '/' and b == 0:
    print("На 0 делить нельзя!\n")
    exit(0)

if sym == '+':
    print(a+b)
if sym == '-':
    print(a-b)
if sym == '*':
    print(a*b)
if sym == '/':
    print(a/b)