import random


def bozo_sort_one_dimensional(arr: [], bl: bool):
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


def bozo_sort_two_dimensional(arr: [], bl: bool):
    m = len(arr)
    n = len(arr[0])
    checker = True

    while checker:
        rand_1_1 = random.randint(0, n)
        rand_1_2 = random.randint(0, m)
        rand_2_1 = random.randint(0, n)
        rand_2_2 = random.randint(0, m)

        tmp = arr[rand_1_2][rand_1_1]
        arr[rand_1_2][rand_1_1] = arr[rand_2_2][rand_2_1]

        if bl:
            tmp_bool = True
            previous_number = arr[0][0]

            for i in range(m):
                for j in range(n):
                    if previous_number > arr[i][j]:
                        tmp_bool = False

                    previous_number = arr[i][j]

        else:
            tmp_bool = True
            previous_number = arr[0][0]

            for i in range(m):
                for j in range(n):
                    if previous_number < arr[i][j]:
                        tmp_bool = False
                    previous_number = arr[i][j]

        if tmp_bool:
            checker = False
        else:
            checker = True

        return arr



n = int(input())
arr = []

print(bozo_sort_two_dimensional(arr, 0))
