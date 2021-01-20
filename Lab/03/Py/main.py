from tkinter import *
from PIL import Image, ImageTk
import os
from random import randint

root = Tk()


class Grid:
    __score = 0
    __grid_arr = []
    __balls_arr = []
    __bg_arr = []  # 0 - not selected, 1 - selected
    __buff = []

    def fill_buffer(self):
        for i in range(3):
            self.__buff = self.__balls_arr[randint(0, len(self.__balls_arr))]

    def __init__(self):
        # init arr of balls png
        ball_files = os.listdir(r'C:\Users\Armen\Documents\GitHub\programming\Lab\03\Py\balls img')
        for file in ball_files:
            self.__balls_arr.append(ImageTk.PhotoImage(Image.open('balls img/' + file).crop((1, 0, 67, 66))))

        # init of background
        self.__bg_arr.append(ImageTk.PhotoImage(Image.open('img/cell-bgr.png').crop((1, 0, 67, 66))))
        self.__bg_arr.append(ImageTk.PhotoImage(Image.open('img/cell-bgr.png').crop((1, 69, 67, 135))))

        for i in range(9):
            self.__grid_arr.append([])

            for j in range(9):
                self.__grid_arr[i].append([])

                self.__grid_arr[i][j] = self.__bg_arr[0]

    def get_grid_arr(self, i, j):
        return self.__grid_arr[i][j]

    def get_score(self):
        return self.__score

    def get_buff(self, i: int):
        if len(self.__buff) > i >= 0:
            return self.__buff[i]
        else:
            pass


grid = Grid()


def start_game() -> None:
    # grid
    for row in range(9):
        for col in range(9):
            lbl = Label(root,
                        image=grid.get_grid_arr(row, col),
                        borderwidth=0)
            lbl.grid(row=row,
                     column=col,
                     padx=1,
                     pady=1)

    # menu
    title = Label(root,
                  text='Линии 2',
                  font=("Arial Bold", 20),
                  borderwidth=0)

    title.grid(rowspan=2,
               row=0,
               column=10,
               ipadx=(960-720)/2,
               pady=1)

    score_menu = Label(root,
                       text='Счёт: ' + str(grid.get_score()),
                       font=("Arial", 18),
                       borderwidth=0)

    score_menu.grid(rowspan=1,
                    row=2,
                    column=10,
                    ipadx=(960-720)/2)

    prompt = Label(root,
                   text='Подсказка: ',
                   font=("Arial", 18),
                   borderwidth=0)

    prompt.grid(rowspan=1,
                row=3,
                column=10,
                ipadx=(960-720)/2)

#    for i in range(3):
#        lbl = Label(root,
#                    image=grid.get_buff(i),
#                    borderwidth=0)
#        lbl.grid(row=4,
#                 column=10 + i,
#                 padx=1,
#                 pady=1)


start_game()

root.geometry("960x720")
root.mainloop()
