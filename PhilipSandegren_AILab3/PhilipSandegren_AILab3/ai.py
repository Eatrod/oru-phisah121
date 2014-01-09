#import decisionTree
import random


# The agent receives a dictionary as percept that contains the different attributes as
# keys values to the attributes. I wanted to make more explicit what the different values
# mean, therefore I introduced this form of class attributes as more speaking representatives
# of the different values.
class PerceptValue:
    # Class variables for the types of object that can be contained in a cell
    # as well as for the energy level
    Grass, Dirt, Wheat, Seed = range(0, 4)
    Low, Ok, High = range(0, 3)

 

# The class is a stub of what you should use to implement your decision maker.
class AI():

    # The actions that an agent can take (duplicated from simulation.py)
    # the reason function shall return one of these!
    WalkEast, WalkWest, WalkNorth, WalkSouth, DoHarvest, DoRest, DoSow = range(0, 7)

    def __init__(self):
        self.manualControl = False
        # if you want your agent to execute the action that you
        # return, then you have to say False here. Otherwise, anything
        # you return will be overwritten by the manual input of the human.
        self.Age = 0
        # this is just a dummy variable to show to you that the AI can
        # use an internal data structue, e.g. containing a decision tree
        # a knowledge base out of rules, etc.
        # if you want to test your hand-made decision tree, you may
        # generate and fill it here

        #myTree = DecisionFork("direction", "north": 
                       #DecisionFork("status",{
                        #"dirt" : 
                            #DecisionLeaf("Sow"), 
                        #"wheat" : 
                            #DecisionLeaf("Harvest"), 
                        #"grass" : 
                            #DecisionFork("energy", {"low" : DecisionLeaf("Rest"), "Ok" : DecisionLeaf("Rest")}
                        #"Seed" :
                            #DecisionFork("energy", {"low" : DecisionLeaf("Rest"), "Ok" : DecisionLeaf("Rest")}

    # This function is called by the agent's update function. it gets the
    # sensor data in form of a percept dictionary (there is a new one generated
    # for every tick. the dictionary has the form:
    # {"onMyPosition" : <value>, "onCellNorth" : <value>, "onCellEast" : <value>, "onCellSouth" : <value>, "onCellWest" : <value>, "myEnergy" : <value>}
    # the range of the values is given by PerceptValue.Grass ,....
    # the first 5 attributes describe what is the cell on the agent' position and on the cells around, the last describes the energy level 
    # This function shall return an action.
    def reason(self, percept):
        # This is a simple if construct that should serve as an _example_ only
        # to show what you get and how you return actions. This you need to fill with 
        # a function that parses a decision tree! 
        # here you see how to use the speaking class attributes of the PerceptValue Class.
        if True == PerceptValue.Low:
            return AI.DoRest
        if percept["onMyPosition"] == PerceptValue.Wheat:
            return AI.DoHarvest
        elif percept["onMyPosition"] == PerceptValue.Dirt:
            return AI.DoSow
        else:
            rDraw = random.randrange(0, 5)
            if rDraw == 0:
                return AI.WalkEast
            elif rDraw == 1:
                return AI.WalkNorth
            elif rDraw == 2:
                return AI.WalkWest
            elif rDraw == 3:
                return AI.WalkSouth
            else:   
                return AI.DoRest
        return None

    # This function is called by the agent's manualAction function for
    # informing you about the user's selected action in a particular situation
    # expressed by the percept. You need to extend this function for solving 
    # task b. Currently it contains a stub that simply prints everything to 
    # demonstrate that it is automatically called.
    def notify(self, tick, percept, action):
        print(tick, ": this is the percept: ", percept, "and this is what the human did:", self.toString(action))

    def toString(self, action):
        if action == AI.WalkEast:
            return "east"
        elif action == AI.WalkNorth:
            return "north"
        elif action == AI.WalkSouth:
            return "south"
        elif action == AI.WalkWest:
            return "west"
        elif action == AI.DoRest:
            return "rest"
        elif action == AI.DoHarvest:
            return "harvest"
        elif action == AI.DoSow:
            return "sow"




