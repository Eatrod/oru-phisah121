import tkinter
from math import *
from simulation import *

# Container for loaded resources such as images
class Resources:
    res=None
    def __init__(self):
        self.tileset = []
        #for i in range(0,166):
            #self.tileset.append(tkinter.PhotoImage(file="./images/tileset_%d.gif"%(i,)))
        self.tileset.append(tkinter.PhotoImage(file = "./gifs/dirt.gif"))
        self.tileset.append(tkinter.PhotoImage(file = "./gifs/grass.gif"))
        self.tileset.append(tkinter.PhotoImage(file = "./gifs/wheat.gif"))
        self.tileset.append(tkinter.PhotoImage(file = "./gifs/seed.gif"))
        self.sprite = []
        for i in range(0,32):
            self.sprite.append(tkinter.PhotoImage(file="./images/agent_%d.gif"%(i,)))
        self.dead = tkinter.PhotoImage(file="./images/dead.gif")
        self.rabbit=[]
        for dir in ["nw","se","ne","sw"]:
            L=[]
            for i in range(0,8):
                name="./images/rabbit/walking %s%04d.gif"%(dir,i)
                L.append(tkinter.PhotoImage(file=name))
            self.rabbit.append(L)
        for i in [3, 7, 5, 1]:
            name="./images/rabbit/stopped%04d.gif"%(i,)
            self.rabbit.append([(tkinter.PhotoImage(file=name))])
        for i in [3, 7, 5, 1]:
            name="./images/rabbit/sits%04d.gif"%(i,)
            self.rabbit.append([(tkinter.PhotoImage(file=name))])
