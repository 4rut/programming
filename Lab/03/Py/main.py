from tkinter import *
from PIL import Image, ImageTk
import os
from random import randint
import copy

root = Tk()

root.title("Линии 2")
root["bg"] = '#494949'


class Grid:
    __game_over = False
    __score = 0  # score

    __BALLS_IMG = []
    __BALLS_ARR_IND = []

    __BG_IS_SELECTED_ARR = []  # 0 - not selected, 1 - selected

    __grid_bg = []
    __grid_balls_info = []
    __grid_balls_img = []

    __buff = []

    def gen_buffer(self):
        for i in self.__buff:
            i = self.__BALLS_ARR_IND[randint(0, 6)]

    def __init__(self):
        # init arr of balls
        k = 0
        ball_files = os.listdir(r'C:\Users\Armen\Documents\GitHub\programming\Lab\03\Py\balls img')
        for file in ball_files:
            self.__BALLS_IMG.append(ImageTk.PhotoImage(Image.open('balls img/' + file).convert('RGBA').crop((1, 0, 67, 66))))

            self.__BALLS_ARR_IND.append(k)
            k += 1

        # init of background
        self.__BG_IS_SELECTED_ARR.append(ImageTk.PhotoImage(Image.open('img/cell-bgr.png').crop((1, 0, 67, 66))))
        self.__BG_IS_SELECTED_ARR.append(ImageTk.PhotoImage(Image.open('img/cell-bgr.png').crop((1, 69, 67, 135))))

        # grid bg
        for i in range(9):
            self.__grid_bg.append([])

            for j in range(9):
                self.__grid_bg[i].append([])

                self.__grid_bg[i][j] = self.__BG_IS_SELECTED_ARR[0]

        # set grid statement (-1 -> empty)
        for p in range(9):
            self.__grid_balls_info.append([])

            for q in range(9):
                self.__grid_balls_info[p].append([])

                self.__grid_balls_info[p][q] = None

            for n in range(9):
                self.__grid_balls_info.append([])

                for k in range(9):
                    self.__grid_balls_info[n].append([])

                    self.__grid_balls_info[n][k] = -1

        # gen & set len of buff
            for x in range(3):
                self.__buff.append(randint(0, 6))

    def make_move(self) -> None:
        game_over = 0
        emp_ind = []
        emp_ind_len = 0
        k = 0

        for i in range(9):
            for j in range(9):
                if self.__grid_balls_info[i][j] == -1:
                    game_over += 1

                    emp_ind.append([])
                    emp_ind[k].append(i)
                    emp_ind[k].append(j)
                    emp_ind_len += 1

        if game_over <= 3:
            self.__game_over = True
            return None

        tmp_buff = 0
        for n in range(3):
            selected_it = randint(0, emp_ind_len - 1)

            # FIXME out of range
            #self.__grid_balls_info[emp_ind[selected_it][0]][emp_ind[selected_it][1]] = self.__buff[tmp_buff]
            #self.__grid_balls_img[emp_ind[selected_it][0]][emp_ind[selected_it][1]] = self.__BALLS_IMG[self.__buff[n]]
            #emp_ind.pop(selected_it)

            tmp_buff += 1

        self.gen_buffer()

    def get_grid_arr(self, i, j):
        return self.__grid_bg[i][j]

    @property
    def get_score(self):
        return self.__score

    @property
    def get_buff_img(self):
        return self.__buff_img

    def grid_choice(self, event):
        pass


grid = Grid()


def play() -> None:
    # grid
    for row in range(9):
        for col in range(9):
            lbl = Label(root,
                        image=grid.get_grid_arr(row, col),
                        borderwidth=0)
            # lbl.bind("<Button-1>", grid.grid_choice)
            lbl.grid(row=row,
                     column=col,
                     padx=1,
                     pady=1)

    # menu
    title = Label(root,
                  text='Линии 2',
                  fg="white",
                  bg='#494949',
                  font=("Arial Bold", 20),
                  borderwidth=0)

    title.grid(rowspan=2,
               row=0,
               column=10,
               ipadx=(960-720)/2,
               pady=1)

    score_menu = Label(root,
                       text='Счёт: ' + str(grid.get_score),
                       fg="white",
                       bg='#494949',
                       font=("Arial", 18),
                       borderwidth=0)

    score_menu.grid(rowspan=1,
                    row=2,
                    column=10,

                    ipadx=(960-720)/2)

    make_move = Button(root, text="Сделать ход",
                       fg="white",
                       bg='#494949',
                       font=("Arial", 18),
                       borderwidth=0)
    make_move.bind("<Button-1>", grid.make_move())
    make_move.grid(row=3,
                   column=10)

    prompt = Label(root,
                   text='Подсказка: ',
                   fg="white",
                   bg='#494949',
                   font=("Arial", 18),
                   borderwidth=0)

    prompt.grid(rowspan=1,
                row=5,
                column=10,
                ipadx=(960-720)/2)


play()

root.geometry("960x720")
root.mainloop()
