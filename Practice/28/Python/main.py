def print_factorization(n: int) -> None:
    if n == 1:
        return

    for i in range(2, n):
        k = 0
        while n % i == 0:
            n /= i
            k += 1

        if k != 0:
            print(i, end="")

            if k != 1:
                print('^', k, end="", sep="")

            if n != 1:
                print('*', end="")


n = int(input())
print_factorization(n)
