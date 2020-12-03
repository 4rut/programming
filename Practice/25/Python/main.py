import random


def bozo_sort(arr:[], bl:bool):
    checker = True
    while checker:
        rand1 = random.randint(0, len(arr) - 1)
        rand2 = random.randint(0, len(arr) - 1)

        tmp = arr[rand1]
        arr[rand1] = arr[rand2]
        arr[rand2] = tmp

        if bl:
            tmp_bool = True
            for i in range(len(arr) - 1):
                if arr[i] > arr[i + 1]:
                    tmp_bool = False
                    break
            checker = not tmp_bool

        else:
            tmp_bool = True
            for i in range(len(arr) - 1):
                if arr[i] < arr[i + 1]:
                    tmp_bool = False
                    break
            checker = not tmp_bool

    return arr


n = int(input())
arr = []

for i in range(n):
    arr.append(int(input()))

print(bozo_sort(arr, 0))
