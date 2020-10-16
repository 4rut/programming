from random import randint
import random

print("*Приветственное сообщение от игры*")
gameOver = 1
seedGen = 0

while gameOver == 1:
    random.seed(seedGen)
    num = randint(0, 100)

    checker = 0

    for i in range(5):
        a = int(input())

        if num > a:
            print("Загаданное число больше")

        if num < a:
            print("Загаданное число меньше")

        if num == a:
            print("Поздравляю! Вы угадали")
            checker = 1
            break

    if checker != 1:
        print("Вы проиграли. Было загадано:", num, '\n')

    gameOver = int(input("Хотите начать сначала? (1 - ДА )"))
    seedGen += 1
