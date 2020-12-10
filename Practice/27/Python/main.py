n = int(input())

arr = []

if n <= 5:
    for i in range(n):
        arr.append(int(input()))
        arr = list(reversed(sorted(arr)))

        print(arr)
else:
    for i in range(5):
        arr.append(int(input()))
        arr = list(reversed(sorted(arr)))

        print(arr)

    for i in range(5, n):
        cin = int(input())

        is_sorted = True
        for j in range(4, 0, -1):
            if cin < arr[j]:
                arr.pop(0)
                arr.append(cin)
                is_sorted = False
                break

        if not is_sorted:
            arr = list(reversed(sorted(arr)))

        print(arr)
