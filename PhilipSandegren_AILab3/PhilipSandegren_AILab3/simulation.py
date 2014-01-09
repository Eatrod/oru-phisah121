#import tkinter
from math import *
import random
#import time
#import thread
#import tkfont

from resources import Resources


def clamp(v, mi, ma):
    return max(mi, min(v, ma))


# Heading should be understandable; I prefer this instead of
# Numbers -> less errorprone
class Heading:

    North, East, South, West = range(0, 4)


# Qualitative values for the energylevel
class EnergyLevel:

    High, Ok, Low = range(0, 3)


# Represents an individual cell in the world
class Cell:

    Grass, Dirt, Wheat, Seed = range(0, 4)

    def __init__(self, myMap):
        self.type = Cell.Grass
        self.count = 0
        self.map = myMap
        # so the cell always can access the map without global variables!
        # the cell will also get x and y values when the map is generated.
        # the cell will also get slots for its neighboring cells ...

    def isWalkable(self, who):
        return self.type in [Cell.Grass, Cell.Dirt, Cell.Wheat]

    def updateImage(self):
        self.image = [1]
        if self.type == Cell.Grass:
            self.image = [1]
        elif self.type == Cell.Dirt:
            self.image = [0]
        elif self.type == Cell.Wheat:
            self.image = [2]
        elif self.type == Cell.Seed:
            self.image = [3]


# Performs the simulation of the world
class Simulation():

    def __init__(self, size):
        # parameters of the environment and its dynamics:
        self.size = size
        self.timeToWheat = 40
        self.timeToGrass = 40
        # initialization of the environment
        self.cells = []
        for x in range(0, size):
            self.cells.append([])
            for y in range(0, size):
                c = Cell(self)
                c.x, c.y = x, y
                self.cells[x].append(c)
        self.linkCells()
        self.computeImages()
        self.currentTick = 0

        middlePos = round(self.size / 2)
        self.player = Agent(self, [middlePos, middlePos], 100)
        # place the player in the middle of the map
        self.player.onCell = self.cells[middlePos][middlePos]
        self.agents = [self.player]


    def linkCells(self):
        size = self.size
        for x in range(0, size):
            for y in range(0, size):
                theCell = self.cells[x][y]
                # with this connections the map becomes a torus
                if not x - 1 < 0:
                    theCell.west = self.cells[x - 1][y]
                else:
                    theCell.west = self.cells[size - 1][y]
                if not y - 1 < 0:
                    theCell.north = self.cells[x][y - 1]
                else:
                    theCell.north = self.cells[x][size - 1]
                if not x + 1 == size:
                    theCell.east = self.cells[x + 1][y]
                else:
                    theCell.east = self.cells[0][y]
                if not y + 1 == size:
                    theCell.south = self.cells[x][y + 1]
                else:
                    theCell.south = self.cells[x][0]

    def computeImages(self):
        for x in range(0, self.size):
            for y in range(0, self.size):
                c = self.cells[x][y]
                c.updateImage()

    def update(self):
        self.currentTick = self.currentTick + 1
        for agent in self.agents:
            agent.update()
            # update the cells
        for x in range(0, self.size):
            for y in range(0, self.size):
                theCell = self.cells[x][y]
                theCell.count = theCell.count + 1
                # cell dynamics
                if theCell.type == Cell.Seed and theCell.count == self.timeToWheat:
                    theCell.type = Cell.Wheat
                    theCell.count = 0
                    theCell.updateImage()
                # wheat ceases to continue to be wheat after some time
                if theCell.type == Cell.Wheat and theCell.count == self.timeToGrass:
                    theCell.type = Cell.Grass
                    theCell.count = 0
                    theCell.updateImage()
                # random process for transforming Grass to Dirt and vice versa
                if theCell.type == Cell.Grass and random.randrange(0, 100) == 0:
                    theCell.type = Cell.Dirt
                    theCell.count = 0
                    theCell.updateImage()
                if theCell.type == Cell.Dirt and random.randrange(0, 100) == 0:
                    theCell.type = Cell.Grass
                    theCell.count = 0
                    theCell.updateImage()


class Agent:
    # The actions that the agent is allowed to do
    WalkEast, WalkWest, WalkNorth, WalkSouth, DoHarvest, DoRest, DoSow = range(0, 7)
    # energy levels
    High, Ok, Low = range(0, 3)

    def __init__(self, simulation, position, initialEnergy):
        self.x = position[0]
        self.y = position[1]
        self.simulation = simulation
        self.status = "Hello brave new world!"
        self.energyLevel = initialEnergy
        self.energyConsumptionPerAction = 1
        self.energyFromHarvesting = 50
        self.name = "John Doe"
        self.isAlive = True
        self.ai = False
        self.heading = Heading.North

    def getImage(self):
        resources = Resources.res
        if not self.isAlive:
            t = self.simulation.currentTick
            # the ghost is sligthly drifting
            return int(sin(t * 0.1) * 5), int(sin(t * 0.21) * 8), resources.dead
        if self.heading == Heading.West:
            return 0, 0, resources.sprite[16]
        elif self.heading == Heading.East:
            return 0, 0, resources.sprite[24]
        elif self.heading == Heading.North:
            return 0, 0, resources.sprite[8]
        elif self.heading == Heading.South:
            return 0, 0, resources.sprite[0]


    def consumeEnergy(self, delta):
        self.energyLevel = self.energyLevel - delta


    def checkAlife(self):
        if self.energyLevel < 0:
            self.status = "Died of hunger!"
            self.isAlive = False


    def createCurrentPercept(self):
        onCell = self.simulation.cells[self.x][self.y]
        return {"onMyPosition" : onCell.type, 
                "onCellNorth" : onCell.north.type, 
                "onCellEast" : onCell.east.type, 
                "onCellSouth" : onCell.south.type, 
                "onCellWest" : onCell.west.type, 
                "myEnergy" : self.getQualitativeEnergyLevel()}


    def getQualitativeEnergyLevel(self):
        if self.energyLevel > 60:
            return EnergyLevel.High
        elif self.energyLevel > 30:
            return EnergyLevel.Ok
        else:
            return EnergyLevel.Low

    def update(self):
        if self.ai:
            if not self.ai.manualControl:
                self.execute(
                    self.ai.reason(
                        self.createCurrentPercept()))
        self.checkAlife()


    def manualAction(self, action):
        if self.ai.manualControl:
            self.ai.notify(self.simulation.currentTick,
                self.createCurrentPercept(), action)
            self.execute(action)
        self.checkAlife()


    def execute(self, action):
        if not self.isAlive:
            return False
        onCell = self.simulation.cells[self.x][self.y]
        if not action == Agent.DoRest:
            self.consumeEnergy(self.energyConsumptionPerAction)
            if action == Agent.WalkNorth:
                self.moveToCell(onCell.north)
                self.heading = Heading.North
            elif action == Agent.WalkWest:
                self.moveToCell(onCell.west)
                self.heading = Heading.West
            elif action == Agent.WalkSouth:
                self.moveToCell(onCell.south)
                self.heading = Heading.South
            elif action == Agent.WalkEast:
                self.moveToCell(onCell.east)
                self.heading = Heading.East
            elif action == Agent.DoHarvest and onCell.type == Cell.Wheat:
                self.harvest(onCell)
            elif action == Agent.DoSow and onCell.type == Cell.Dirt:
                self.sow(onCell)
            else:
                print("Attempting ", action, "\n")

    def moveToCell(self, nextCell):
        #onCell = self.simulation.cells[self.x][self.y]
        self.x, self.y = nextCell.x, nextCell.y
        moved = True
        return moved

    def harvest(self, onCell):
        self.energyLevel = self.energyLevel + self.energyFromHarvesting
        onCell.type = Cell.Dirt
        onCell.count = 0
        onCell.updateImage()

    def sow(self, onCell):
        onCell.type = Cell.Seed
        onCell.count = 0
        onCell.updateImage()




