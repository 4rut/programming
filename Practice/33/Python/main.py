import config


def create(length, base, step):
    if length < 0:
        return None

    array = [base]

    for i in range(1, length):
        array.append(array[i - 1] + step)
    sort(array)
    return array


def sort(array):
    for i in range(1, len(array)):

        key = array[i]

        j = i - 1
        while j >= 0 and key < array[j]:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = key


length = int(input())
base = int(input())
step = int(input())

arr = create(length, base, step)

print(arr)
