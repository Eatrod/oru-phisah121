labyrinth = [[0,0,0,0,0,0,3,0],
[0,1,0,1,1,1,1,0],
[0,1,1,1,0,1,0,0],
[0,1,0,0,0,0,0,0],
[0,1,1,0,1,1,1,0],
[0,0,1,1,1,0,0,0],
[0,1,1,0,1,1,1,3],
[0,2,0,0,0,0,0,0]]


print (labyrinth[0][6])

class nodeClass:
    x = 0
    y = 0
    link = []
    nodeType = 4
    def __init__(self,x,y,nodetype):
        self.x = x
        self.y = y
        self.nodeType = nodetype

def nodeListGenerator(labyrinth):
    list = []
    for x in range(len(labyrinth)):
        for y in range(len(labyrinth)):
            wallCheck = labyrinth[x][y]
            if wallCheck != 0:                
                list.append(nodeClass(x,y,wallCheck))
    return list

def nodeLinkGenerator(list):
    for m in list:
        for n in list:
            if m.x == n.x and m.y == n.y:
                m.link.append(n)

nodeLinkGenerator(nodeListGenerator(labyrinth))
           
def depthFirstSearch(maze,start,goal):
    path = []
    frontier = [start]
    while frontier != []: 
        v = frontier.pop()
        if v not in path and v != 0:
            path.append(v)
        if v == 3:
            return path
        for i in range (0,8):
            for j in range(0,8):
                if maze == 3:
                    return path 
    return path

print (depthFirstSearch(nodeListGenerator(labyrinth),2,3))