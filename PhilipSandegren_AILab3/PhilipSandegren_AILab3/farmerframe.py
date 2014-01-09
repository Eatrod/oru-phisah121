import tkinter
from math import *
import random
import time

from resources import Resources
from simulation import Simulation, Cell, Agent

# Displays a window with the farmers world, ticks the simulation and visualizes the results
class FarmerFrame(tkinter.Frame):

    def __init__(self, ai):
        # Setup visualization frame
        print("Intializing frame...\n")
        tkinter.Frame.__init__(self, None)
        self.master.title('Farmer')
        self.canvas = tkinter.Canvas(self,width=1024, height=768, bg='white')
        self.canvas.pack(expand=0, anchor=tkinter.CENTER)
        self.pack()
        self.tkraise()
        #self.font = tkFont.Font(size=12)
        #self.canvas.bind("<Button-1>", self.mouseClick)
        #self.canvas.bind("<ButtonRelease-1>", self.mouseRelease)
        self.offset = [0,0]
        self.canvas.bind_all("<Key>", self.mykey)
        #self.canvas.bind("<Motion>", self.mouseMotion)
        self.mouseState=False
        # Load graphic resources
        Resources.res = Resources()

        # Create simulator
        self.simulation = Simulation(20)
        self.simulation.player.ai = ai

        # Start running the simulation+visualization
        self.draw()
        self.after(200,self.tick)

    def mykey(self, event):
        if event.char == 'a':
            self.simulation.player.manualAction(Agent.WalkWest)
        if event.char == 'd':
            self.simulation.player.manualAction(Agent.WalkEast)
        if event.char == 'w':
            self.simulation.player.manualAction(Agent.WalkNorth)
        if event.char == 's':
            self.simulation.player.manualAction(Agent.WalkSouth)
        if event.char == 'j':
            self.simulation.player.manualAction(Agent.DoRest)
        if event.char == 'l':
            self.simulation.player.manualAction(Agent.DoHarvest)
        if event.char == 'k':
            self.simulation.player.manualAction(Agent.DoSow)

    def draw(self):
        tileset = Resources.res.tileset
        #ticktime = self.simulation.currentTick
        # First delete all old canvas stuff (I wish we could use a better toolkit here)
        for item in self.canvas.find_all():
            self.canvas.delete(item)
        # Create new canvas items to draw the graphics
        for y in range(0, self.simulation.size):
            for x in range(0, self.simulation.size):
                c = self.simulation.cells[x][y]
                images = c.image
                #x2 = 32 * x - 32 * y - self.offset[0]
                xVis = 32 * x
                yVis = 32 * y
                #y2 = 16 * x + 16 * y - c.elevation * 32 - self.offset[1]
                for i in images:
                    if type(i) is tuple:
                        print("tuple", i[0], " and ", i[1])
                        self.canvas.create_image(xVis + i[0], yVis + i[1],
                            image = tileset[i[2]], anchor = tkinter.SW)
                    else:
                        self.canvas.create_image(xVis, yVis,
                            image = tileset[i], anchor = tkinter.SW)

            for a in self.simulation.agents:
                # Draw this agent
                #onCell = a.simulation.cells[a.x][a.y]
                dx, dy, image = a.getImage()
                #print("a.x=", a.x, " a.y=", a.y, "cell.x=", onCell.x, "cell.y=", onCell.y)
                self.canvas.create_image(32 * a.x - 16, 32 * a.y - 16,
                    image = image, anchor = tkinter.SW)
                self.canvas.create_polygon(32 * a.x - 32, 32 * a.y - 32, 32 * a.x, 32 * a.y )


    def tick(self):
        self.simulation.update()
        self.draw()
        self.after(120, self.tick)
