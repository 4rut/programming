def pow(a:int):
    if a == 0:
        return 0

    var = 2
    counter = 1

    while var < a:
        var *= 2
        counter += 1
    return counter

num = int(input())

print(pow(num))
