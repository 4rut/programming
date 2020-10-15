n = int(input())

s = [True for _ in range(n + 1)]

x = 2

while x * x <= n:
    if s[x]:
        y = x * x
        while y <= n:
            s[y] = False
            y += x
    x += 1

if s[n]:
    print("Простое\n")
else:
    print("Составное\n")
