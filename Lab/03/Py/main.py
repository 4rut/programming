from tkinter import *
from PIL import Image, ImageTk

score = 0

root = Tk()


#class Grid:


img = Image.open("img/cell-bgr.png")
img = ImageTk.PhotoImage(img.crop((1, 0, 67, 66)))

grid_arr = []
for i in range(9):
    grid_arr.append([])

    for j in range(9):
        grid_arr[i].append([])

        grid_arr[i][j] = img


for row in range(9):
    for col in range(9):
        lbl = Label(root,
                    image=grid_arr[row][col],
                    borderwidth=0)
        lbl.grid(row=row,
                 column=col,
                 padx=1,
                 pady=1)


def set_menu() -> None:
    title = Label(root,
                  text='Линии 2',
                  font=("Arial Bold", 20),
                  borderwidth=0)

    title.place(width=150,
                height=50,
                x=720,
                y=50)

    score_menu = Label(root,
                       text='Счёт: ' + str(score),
                       font=("Arial", 18),
                       borderwidth=0)

    score_menu.place(width=150,
                     height=50,
                     x=720,
                     y=120)


set_menu()

root.geometry("960x720")
root.mainloop()
