#Philip Sandegren
#AI-Lab 3
#Python 3.3

from decisionTree import *
import random
from math import log2

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
        self.manualControl = True
        # if you want your agent to execute the action that you
        # return, then you have to say False here. Otherwise, anything
        # you return will be overwritten by the manual input of the human.
        self.notifyLaps = 0
        self.storedActions = []
        self.attributes = {'onMyPosition':1,'onCellNorth':2,'onCellEast':3,
               'onCellSouth':4,'onCellWest':5,'myEnergy':6}
        self.ID3Tree = None
        self.myTree = DecisionFork("onMyPosition",
                        {PerceptValue.Seed: DecisionLeaf(AI.DoRest),
                        PerceptValue.Dirt: DecisionLeaf(AI.DoSow),
                        PerceptValue.Wheat: DecisionLeaf(AI.DoHarvest),
                        PerceptValue.Grass: DecisionFork("onCellNorth",
                       {
                            PerceptValue.Dirt : DecisionLeaf(AI.DoSow), 
                            PerceptValue.Wheat : DecisionLeaf(AI.DoHarvest), 
                            PerceptValue.Grass : DecisionFork("myEnergy", {PerceptValue.Low : DecisionLeaf(AI.DoRest), PerceptValue.Ok : DecisionLeaf(self.randomActionPick())}),
                            PerceptValue.Seed : DecisionFork("myEnergy", {PerceptValue.Low : DecisionLeaf(AI.DoRest), PerceptValue.Ok : DecisionLeaf(self.randomActionPick())})
                       })
                       ,"onCellWest": 
                       DecisionFork("onMyPosition",
                       {
                            PerceptValue.Dirt : DecisionLeaf(AI.DoSow), 
                            PerceptValue.Wheat : DecisionLeaf(AI.DoHarvest), 
                            PerceptValue.Grass : DecisionFork("myEnergy", {PerceptValue.Low : DecisionLeaf(AI.DoRest), PerceptValue.Ok : DecisionLeaf(self.randomActionPick())}),
                            PerceptValue.Seed : DecisionFork("myEnergy", {PerceptValue.Low : DecisionLeaf(AI.DoRest), PerceptValue.Ok : DecisionLeaf(self.randomActionPick())})
                       })
                       ,"onCellEast": 
                       DecisionFork("onMyPosition",
                       {
                            PerceptValue.Dirt : DecisionLeaf(AI.DoSow), 
                            PerceptValue.Wheat : DecisionLeaf(AI.DoHarvest), 
                            PerceptValue.Grass : DecisionFork("myEnergy", {PerceptValue.Low : DecisionLeaf(AI.DoRest), PerceptValue.Ok : DecisionLeaf(self.randomActionPick())}),
                            PerceptValue.Seed : DecisionFork("myEnergy", {PerceptValue.Low : DecisionLeaf(AI.DoRest), PerceptValue.Ok : DecisionLeaf(self.randomActionPick())})
                       })
                       ,"onCellSouth": 
                       DecisionFork("onMyPosition",
                       {
                            PerceptValue.Dirt : DecisionLeaf(AI.DoSow),   
                            PerceptValue.Wheat : DecisionLeaf(AI.DoHarvest), 
                            PerceptValue.Grass : DecisionFork("myEnergy", {PerceptValue.Low : DecisionLeaf(AI.DoRest), PerceptValue.Ok: DecisionLeaf(self.randomActionPick())}),
                            PerceptValue.Seed : DecisionFork("myEnergy", {PerceptValue.Low : DecisionLeaf(AI.DoRest), PerceptValue.Ok : DecisionLeaf(self.randomActionPick())})
                       })})
       

    # This function is called by the agent's update function. it gets the
    # sensor data in form of a percept dictionary (there is a new one generated
    # for every tick. the dictionary has the form:
    # {"onMyPosition" : <value>, "onCellNorth" : <value>, "onCellEast" : <value>, "onCellSouth" : <value>, "onCellWest" : <value>, "myEnergy" : <value>}
    # the range of the values is given by PerceptValue.Grass ,....
    # the first 5 attributes describe what is the cell on the agent' position and on the cells around, the last describes the energy level 
    # This function shall return an action.
    def randomActionPick(self):
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

    def parseDecisionTree(self, nodeType, percept):     
        if(isinstance(nodeType,DecisionLeaf)):
            return nodeType
        elif(isinstance(nodeType,DecisionFork)):
            return self.parseDecisionTree(nodeType.get(percept),percept)
   
    def reason(self, percept):
        theResult = self.parseDecisionTree(self.ID3Tree.get(percept),percept)
        return theResult.result

    #Converts the number of the action to actions name
    def actionNumberConvert(self,actionNumber):
        if actionNumber == 0: return "WalkEast"
        if actionNumber == 1: return "WalkWest"
        if actionNumber == 2: return "WalkNorth" 
        if actionNumber == 3: return "WalkSouth"
        if actionNumber == 4: return "DoHarvest"
        if actionNumber == 5: return "DoRest"
        if actionNumber == 6: return "DoSow"

    # This function is called by the agent's manualAction function for
    # informing you about the user's selected action in a particular situation
    # expressed by the percept. You need to extend this function for solving 
    # task b. Currently it contains a stub that simply prints everything to 
    # demonstrate that it is automatically called.
    def notify(self,tick,percept,action):
        self.notifyLaps += 1
        if self.notifyLaps == 100:
            self.manualControl = False
            self.ID3Tree = self.ID3(self.storedActions,self.attributes)
        row = [action,percept['onMyPosition'],percept['onCellNorth'],percept['onCellEast'],
               percept['onCellSouth'],percept['onCellWest'],percept['myEnergy']]
        self.storedActions += [row]
        print(percept)

    def toString(self,action):
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

########################################################################
################# ID3 Section  #########################################
########################################################################
    def ID3(self,values,attributes):          
        def delAttribute(attributes,X):
            copy = attributes.copy()
            if X in copy:
                del copy[X]
            return copy
        same, action = self.duplicateCheck(values)
        if(same):
            print("DecisionLeaf",action)
            return DecisionLeaf(action)
        empty, action = self.noneCheck(values,attributes)  
        if(empty):
            print("DecisionLeaf",action)
            return DecisionLeaf(action) 
        Values, X = self.calculate(values,attributes)
        print("DecisionFork: ", X)
        tree = DecisionFork(X,{})
        for valueIndex in Values[X]:
             print("Value: ",valueIndex," Attribute: ",X)
             valuesValueindex = self.getSubTable(valueIndex,X,values,attributes)
             if(len(valuesValueindex) == 0):
                 tree.add(valueIndex, DecisionLeaf(self.mostCommon(values)))
                 print("DecisionLeaf")
             else:
                 tree.add(valueIndex, self.ID3(valuesValueindex,delAttribute(attributes,X)))
        return tree
        
    def getSubTable(self,valueIndex,X,values,attributes):
        subtable = []
        for value in values:
            if(value[self.attributes[X]] == valueIndex):
                subtable.append(value)
        return subtable

    def duplicateCheck(self,values):
        issame = True
        old = values[0][0]
        for value in values:
            new = value[0]
            if(new != old):
                issame = False
                old = new
        if(issame):
            return True,old
        else:
            return False,old

    def mostCommon(self,values):
        walkEast = walkWest = walkNorth = walkSouth = DoHarvest = DoRest = DoSow = 0
        for value in values:
            if value[0] == 0:
                walkEast += 1
            if value[0] == 1:
                walkWest += 1
            if value[0] == 2:
                walkNorth += 1
            if value[0] == 3:
                walkSouth += 1
            if value[0] == 4:
                DoHarvest += 1
            if value[0] == 5:
                DoRest += 1
            if value[0] == 6:
                DoSow += 1
        #List =[walkEast,walkWest,walkNorth,walkSouth,DoHarvest,DoRest,DoSow]
        #return max(List)
        List ={0 : walkEast, 1 : walkWest, 2 : walkNorth, 3 : walkSouth, 4 : DoHarvest, 5: DoRest, 6 : DoSow}
        var = max(List,key = lambda x: List[x])            
        return var


    def noneCheck(self,values,attributes):
        if (len(attributes) == 0):
            walkEast = 0
            walkWest = 0
            walkNorth = 0
            walkSouth = 0
            DoHarvest = 0
            DoRest = 0
            DoSow = 0
            for value in values:
                if value[0] == 0:
                    walkEast += 1
                if value[0] == 1:
                    walkWest += 1
                if value[0] == 2:
                    walkNorth += 1
                if value[0] == 3:
                    walkSouth += 1
                if value[0] == 4:
                    DoHarvest += 1
                if value[0] == 5:
                    DoRest += 1
                if value[0] == 6:
                    DoSow += 1
            #List =[walkEast,walkWest,walkNorth,walkSouth,DoHarvest,DoRest,DoSow]
            List ={0:walkEast, 1:walkWest, 2:walkNorth, 3:walkSouth, 4:DoHarvest, 5:DoRest, 6:DoSow}
            var = max(List,key = lambda x: List[x])            
            #return var
            return True, var
        else:
            return False, 0

    #This is the calculation for ID3
    def calculate(self,values,attributes):
        HS = self.actionIG(values)
        HSDict = {}
        tableGrass = []
        tableDirt = []
        tableSeed = []
        tableWheat = []
        tableOk = []
        tableLow = []
        tableHigh = []
        for attribute in attributes:          
            if(attribute == 'myEnergy'):
                for value in values:
                    if(value[attributes[attribute]] == PerceptValue.High):
                        subTableHigh += [value]
                    elif(value[attributes[attribute]] == PerceptValue.Ok):
                        subTableOk += [value]
                    elif(value[attributes[attribute]] == PerceptValue.Low):
                        subTableLow += [value]
                TotalRows = len(values)
                HighIG = self.actionIG(subTableHigh)
                OkIG = self.actionIG(subTableOk)
                LowIG = self.actionIG(subTableLow);
                HSDict[attribute] = HS - (len(subTableHigh)/TotalRows*HighIG +
                                 len(subTableOk)/TotalRows*OkIG +
                                 len(subTableLow)/TotalRows*LowIG)
            else:
                for value in values:
                    if(value[attributes[attribute]] == PerceptValue.Grass):
                        subTableGrass += [value]
                    elif(value[attributes[attribute]] == PerceptValue.Dirt):
                        subTableDirt += [value]
                    elif(value[attributes[attribute]] == PerceptValue.Seed):
                        subTableSeed += [value]
                    elif(value[attributes[attribute]] == PerceptValue.Wheat):
                        subTableWheat += [value]
                totalRows = len(values)
                grassIG = self.actionIG(tableGrass)
                dirtIG = self.actionIG(tableDirt)
                seedIG = self.actionIG(tableSeed)
                wheatIG = self.actionIG(subTableWheat)
                HSDict[attribute] = HS - (len(tableGrass)/TotalRows*GrassIG +
                                 len(tableDirt)/TotalRows*DirtIG +
                                 len(tableSeed)/TotalRows*SeedIG +
                                 len(tableWheat)/TotalRows*WheatIG)
            tableGrass.clear()
            tableDirt.clear()
            tableSeed.clear()
            tableWheat.clear()
            tableHigh.clear()
            tableOk.clear()
            tableLow.clear()
        var = max(attributes,key = lambda x: HSDict[x])
        dictValues = {}
        if(var == 'myEnergy'):
            List = [0,1,2]
        else:
            List = [0,1,2,3]
        dictValues[var] = List
        return dictValues, var
     
    #IG calculates how many times an action occurs
    def actionIG(self,values):
        def IGHelper(action, nrOfRows):
            if(action == 0 or nrOfRows == 0):
                return 0
            else:
                return ((action/nrOfRows) * log2(action/nrOfRows))
        numberOfRows = len(values)
        WalkEast = 0
        WalkWest = 0
        WalkNorth = 0
        WalkSouth = 0
        DoHarvest = 0
        DoRest = 0
        DoSow = 0
        for value in values:
            if(values[0] == 0):
                WalkEast += 1
            elif(values[0] == 1):
                WalkWest += 1
            elif(values[0] == 2):
                WalkNorth += 1
            elif(values[0] == 3):
                WalkSouth += 1
            elif(values[0] == 4):
                DoHarvest += 1
            elif(values[0] == 5):
                DoRest += 1
            else:
                DoSow += 1
        IG = (-IGHelper(WalkEast,numberOfRows)
              -IGHelper(WalkWest,numberOfRows)
              -IGHelper(WalkNorth,numberOfRows)
              -IGHelper(WalkSouth,numberOfRows)
              -IGHelper(DoHarvest,numberOfRows)
              -IGHelper(DoRest,numberOfRows)
              -IGHelper(DoSow,numberOfRows))
        return IG
