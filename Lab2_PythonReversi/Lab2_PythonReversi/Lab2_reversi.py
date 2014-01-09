import tkinter
from math import *
import random
import time
import _thread
# import tkFont
# mco: import
# changed Tkinter to tkinter, tkFont cannot be found and changed thread to _thread

# Class for representing a state of the game
# grid: array integers: 0 = empty, 1 = first player (human), 2 = second player (computer)
# ply: next player to make a move, 1 or 2
# nMoves: the total number of moves performed since the start of the current game
class ReversiState():
    directions = [(-1, -1), (0, -1), (1, -1), (-1, 0), (-1, 1), (1, 0), (1, 1), (0, 1)]
    
    def __init__(self,clone):
        if clone:
            self.grid = [X[:] for X in clone.grid]
            self.ply = clone.ply
            self.nMoves = clone.nMoves
        else:
            self.grid = [[0,0,0,0,0,0,0,0],
                         [0,0,0,0,0,0,0,0],
                         [0,0,0,0,0,0,0,0],
                         [0,0,0,2,1,0,0,0],
                         [0,0,0,1,2,0,0,0],
                         [0,0,0,0,0,0,0,0],
                         [0,0,0,0,0,0,0,0],
                         [0,0,0,0,0,0,0,0]]
            self.ply = 1 
            self.nMoves = 0

    def __getitem__(self,X):
        return self.grid[X]

    def withinGrid (self, x, y):
        size = len(self.grid)
        return not(x < 0 or y < 0 or x >= size or y >= size)
    
    def getEntry (self, x, y):
        return self.grid[y][x]

    def setEntry (self, x, y, entry):
        self.grid[y][x] = entry

    def isEmpty (self, x, y):
        return self.grid[y][x] == 0

    def opponentPly (self):
        return (self.ply + 2) % 2 + 1
    
    # Returns how many pieces we would flip if start at
    # (x,y) going in the direction (dx,dy)
    def mayFlipNumber(self, x, y, dx, dy):
        count=0
        for i in range(1,8):
            x2 = x + i*dx
            y2 = y + i*dy
            # mco: force the type to int
            x2 = int (x2)
            y2 = int (y2)
            if not self.withinGrid(x2, y2) :
                return 0
            elif self.isEmpty(x2, y2) : 
                return 0
            elif self.getEntry(x2, y2) == self.ply:
                return count
            else:
                count=count+1;
        return 0
    
    # Decides if a move is legal
    def isLegal(self,x,y):
        # mco: force the type to int
        x = int (x)
        y = int (y)
        if not self.isEmpty(x,y) :
            return False
        for (dx, dy) in ReversiState.directions :
            if self.mayFlipNumber(x, y, dx, dy) > 0:
                return True
        return False

    # Performs a game move, and returns the number of flipped pieces
    def move(self,x,y):
        me = self.ply
        opponent = self.opponentPly()
        count = 0
        self.nMoves = self.nMoves + 1
        for (dx, dy) in ReversiState.directions :
            if self.mayFlipNumber(x, y, dx, dy) > 0:   
                for i in range(1,8):
                    x2 = x + i * dx
                    y2 = y + i * dy
                    # mco: force the type to int
                    #x2 = int (x2)
                    #y2 = int (y2)
                    if not self.withinGrid(x2,y2) :
                        break
                    elif self.getEntry(x2, y2) != opponent:
                        break
                    else:
                        self.setEntry(x2, y2, me) 
                        count = count + 1
        self.setEntry(x, y, me) 
        self.ply = opponent
        return count

    # Returns the current score as a tupel (ply1,ply2)
    def score(self):
        score = {1 : 0, 2 : 0}
        for x in range(0,8):
            for y in range(0,8):
                p=self.getEntry(x,y)
                if p != 0:
                    score[p] = score[p] + 1
        return (score[1], score[2])

    # Returns a list of all legal moves, this is done in an _extremly_ naive way
    # a move is hereby a tupel containing x and y
    def legalMoves(self):
        moves=[]
        for x in range(0,8):
            for y in range(0,8):
                if self.isLegal(x,y):
                    moves.append((x,y))
        return moves


####################################################################################################
# The frame for showing the game board and interacting with the human player
class ReversiFrame(tkinter.Frame):

    # Creates an instance of the game using the given AI's.
    # Pass in None in place of an AI to use the human player instead
    def __init__(self, ai1, ai2):
        tkinter.Frame.__init__(self,None)
        self.master.title('Reversi')
        self.canvas = tkinter.Canvas(self,width=64*8,height=64*8+60,bg='white')
        self.canvas.pack(expand=1,anchor=tkinter.CENTER)
        self.pack()
        self.tkraise()
        self.state = ReversiState(None)
        self.images = {}
       
        # store the player information in a dictionary. 
        # key is the ply-marker in the grid, value is the ai object or none.
        self.ai = {1 : ai1, 2: ai2}

        for img in ['ply1','ply2','cell','cell-hi']:
            self.images[img]=tkinter.PhotoImage(file='./images/'+img+'.gif')
        self.text_item=self.canvas.create_text(40,8*64,anchor=tkinter.NW, text='') #, font=self.font)  -- mco
        self.canvas.bind("<Button-1>", self.mouseClick)        
        self.draw()
        if not self.isHuman(self.state.ply):
            self.after(100,self.runAI)

    def isHuman (self, plyMarker):
        return self.ai[plyMarker] == None  
    
    # Accepts mouseclicks and interprets them as the humans move, if legal and if it is his turn
    def mouseClick(self,event):
        x = int(event.x/64)
        y = int(event.y/64)
        gameState = self.state
        if gameState.withinGrid(x, y) and self.isHuman(self.state.ply) and gameState.isLegal(x,y):
            gameState.move(x,y)
            self.draw()
            if gameState.legalMoves() == []:
                self.announceWinner()
                return None
            if not self.isHuman(self.state.ply):
                self.after(100,self.runAI)

    # Runs the next AI one step
    def runAI(self):
        self.ai[self.state.ply].doMove(self.state)
        self.draw()
        moves=self.state.legalMoves()
        if moves == []:
            self.announceWinner()
            return None
        if not self.isHuman(self.state.ply):
            self.after(10, self.runAI) 
            ### fkl: this is ugly, this recursiveness unnecessarily builds up an long 
            ### function stack from which the programm never returns before somebody has won.
            ### A good solution would be creating a game loop that regains the control after the
            ### AI has done its action, but this has to interact with the human and would mean
            ### larger changes in the code.

    # Prints who is the winner.
    def announceWinner(self):
        (s1, s2) = self.state.score()
        if s1 > s2:
            t="Player 1 is the winner!"
        elif s2 > s1:
            t="Player 2 is the winner!"
        else:
            t="The game is a draw"
        self.canvas.itemconfigure(self.text_item, text="%s\nScore: %d / %d"%(t,s1,s2))

    # Draws the gameboard to the screen
    def draw(self):
        moves = self.state.legalMoves()
        for y in range(len(self.state.grid)):
            for x in range(len(self.state.grid[0])):
                if self.state[y][x] == 1:
                    im = self.images['ply1']
                elif self.state[y][x] == 2:
                    im = self.images['ply2']
                elif (x,y) in moves:
                    im = self.images['cell-hi']
                else:
                    im = self.images['cell']
                self.canvas.create_image(x*64,y*64,image=im,anchor=tkinter.NW)
        (s1, s2) = self.state.score()
        self.canvas.itemconfigure(self.text_item, text="Player %d's move\nScore: %d / %d"%(self.state.ply,s1,s2))

#################################################################################################


# This is a naive AI that just makes a random choice between
# the possible legal moves.

class ReversiRandomAI():
    def doMove(self,state):
        moves = state.legalMoves()
        (x, y) = moves[random.randrange(0,len(moves))]
        state.move(x, y)


#################################################################################################

class GreedyAI():
    def doMove(self, state):
        moves = state.legalMoves()
        currentlyBestMove = moves[0]
        currentlyBestScore = self.evaluate(state, currentlyBestMove)
        for candMove in moves[1:] :
            score = self.evaluate(state, candMove)
            if score > currentlyBestScore :
                currentlyBestScore = score
                currentlyBestMove = candMove
        (x, y) = currentlyBestMove 
        state.move(x, y)

    def evaluate(self, state, move) :
        futureState = ReversiState(state)
        (x, y) = move
        futureState.move(x, y)
        (ply1Score, ply2Score) = futureState.score()
        if state.ply == 1 :
            return ply1Score
        else :
            return ply2Score

####################################################################################################

#Mini-Max AI
class minmaxAI():
    def doMove(self, state):
        bestMove = self.minmaxDecision(state,4)
        (x, y) = bestMove
        state.move(x, y)

    #Decision function
    def minmaxDecision(self,state,depth):
        lowScore = float("inf")
        moves = state.legalMoves()
        score = 0
        for move in moves[0:]:
            clone = ReversiState(state)
            (x,y) = move
            clone.move(x,y) 
            score = self.minValue(clone, depth-1) 
            if score < lowScore:
                lowScore = score
                bestMove = move
        return bestMove
        
    
    #Max function
    def maxValue(self,state,depth):
        if state.legalMoves == [] or depth == 0:
            return self.evaluate(state)
        highestScore = -float("inf")
        score = 0 
        moves = state.legalMoves()
        for move in moves[0:]:
            clone = ReversiState(state)
            (x,y) = move
            clone.move(x,y)
            score = self.minValue(clone,depth-1)
            if score > highestScore:
                highestScore = score
        return highestScore
    
    #Min function
    def minValue(self,state,depth): 
        if state.legalMoves == [] or depth == 0:
            return self.evaluate(state)
        score = 0 
        lowestScore = float("inf")
        moves = state.legalMoves()
        for move in moves[0:]:
            clone = ReversiState(state)
            (x,y) = move
            clone.move(x,y)
            score = self.maxValue(clone,depth-1)
            if score < lowestScore:
                lowestScore = score
        return lowestScore

    #Evaluation function
    def evaluate(self, state):
        (ply1Score, ply2Score) = state.score()
        
        #Corner moves = very good!
        #Controlling the corner is vital in reversi because corner pieces can never be taken over
        #Having the corner also often means you control then entire edge
        if state.grid[0][0] == 1 or state.grid[0][7] == 1 or state.grid[7][0] == 1 or state.grid[7][7] == 1:
            ply1Score += 10
        elif state.grid[0][0] == 2 or state.grid[0][7] == 2 or state.grid[7][0] == 2 or state.grid[7][7] == 2:
            ply2Score += 10

        #Gives your opponent potenial acess to corner = bad!
        #This is called 'corner edge' the place that is one step towards the center from the corner
        #Controlling this often means you lost your chance of getting the corner
        if state.grid[1][1] == 1 or state.grid[6][6] == 1 or state.grid[1][6] == 1 or state.grid[6][1] == 1:
            ply1Score -= 5
        elif state.grid[1][1] == 2 or state.grid[6][6] == 2 or state.grid[1][6] == 2 or state.grid[6][1] == 2:
            ply2Score -= 5

        #Rewards 'mobility' = having a lot of moves available
        #The more moves you have the lesser chance is it that you're opponent will leave you with no moves at all
        #Also it gives the minmax AI more search options so the best move can be found
        moves = state.legalMoves()
        for move in moves[0:]:
            if state.ply == 1:
                ply1Score += 1
            else:
                ply2Score += 1

        if state.ply == 1:
            return ply2Score - ply1Score
        else:
            return ply1Score - ply2Score



####################################################################################################

# This function performs 10 matches between the two given AI's and reports the total score. 
# The AI's take turn playing black/white to compensate for any irregularities 
def doTournament(ai1, ai2, noGames):
    score=[0,0]
    draws=0
    for i in range(0,noGames):
        state=ReversiState(None)
        while state.legalMoves() != []:
            if (state.ply-1+i)%2 == 0: 
                ai1.doMove(state)
            else:
                ai2.doMove(state)
        s = state.score()
        print ("Game finished: ",s[i%2],s[(i+1)%2])

        if s[0]>s[1]:
            score[i%2] += 1
        elif s[1]>s[0]:
            score[(1+i)%2] += 1
        else:
            draws += 1
    print("Total scores: AI1 %d wins vs. AI2 %d wins. (%d draws)"%(score[0],score[1],draws))


# Naive, Random AI given in lab
aiRA = ReversiRandomAI()

# Your own AI needs to be a class in analogy to the class ReversiRandomAI 
# it needs to implement a function doMove that is called by the main game loop.
# then integrate your implementation in a similar way: create a variable containing
# an instance of your class and hand it over to the ReversiFrame instance as below. 

# Replace the arguments with your AIs ... 
# If any argument is None, then that player is a human.
#f = ReversiFrame(None,aiRA)
#f = ReversiFrame(None,minmaxAI())
f = ReversiFrame(minmaxAI(),GreedyAI())
#f = ReversiFrame(GreedyAI(),minmaxAI())
#f = ReversiFrame(minmaxAI(),aiRA)
#f = ReversiFrame(minmaxAI(),minmaxAI())
#f = ReversiFrame(minmaxAI(),aiRA)
f.mainloop()


# Use a function call if you wish to test the performance
# of your AI's. This call compares two random AIs which is
# quite stupid :-)
#doTournament(minmaxAI(), aiRA, 10)
#doTournament(minmaxAI(), GreedyAI(), 10)