import operator
import math


Mynetwork = {}
class Node:
    def __init__(self, namn, x, y):   
        self.namn = namn
        self.x = int(x)
        self.y = int(y)
        self.Connection = []


dataFile = open('locations2016.csv')
dataFile.readline()
for dataLine in dataFile.readlines():
          datastring = dataLine[:-1]
          datastring1 = datastring.split(';')

          Mynode = Node(datastring1[0],datastring1[1],datastring1[2])
          Mynetwork[datastring1[0]]=Mynode
       #   print(Mynode.namn, Mynode.x, Mynode.y)
dataFile.close()
del dataFile

dataFile1 = open('connections2016.csv', 'r')
dataFile1.readline()
for dataLine in dataFile1.readlines():
          datastring = dataLine[:-1]
          datastring1 = datastring.split(';')
          

          fromobj, toobj = datastring1
          Mynetwork[fromobj].Connection.append(Mynetwork[toobj])
       
          #for i in Mynetwork:
          #    if datastring1[0] == i.namn:
          #       fromobj = i
          #    if datastring1[1] == i.namn:
          #       toobj = i
                   
dataFile1.close()
del dataFile1



def goaltest(node, Destination):
    if node == Destination:
        return True
    else:
        return False


def depthLimitedSearch(Start, Destination, Maxdept):

    frontier = [Start]
    depthList = {}
    depthList[Start] = 0
    cameFrom = {}
    visitedList = []

    while True:
        if not frontier:
            return False
        Mynode = frontier[0]
        frontier.remove(Mynode)
        visitedList.append(Mynode)
        if not depthList[Mynode] > Maxdept:
           # if goaltest(Mynode, Destination) == True:
           if Mynode == Destination:
                return reconstructpath(cameFrom, Start, Destination)
           for next in Mynode.Connection: 
                if (next not in visitedList and next not in frontier):
                    frontier.insert(0, next)
                    depthList[next] = depthList[Mynode]+1
                    cameFrom[next] = Mynode
       
    
def IterativeDeepeningSearch(star, sto):
    depth = 0
    begin = Mynetwork[star]
    end = Mynetwork[sto]
    while True:
        depth += 1
        result = depthLimitedSearch(begin, end, depth)
        if result != False:
            for obj in result:
                print(obj.namn)
            return result


def reconstructpath(camefrom, s, e):
    
    path=[]
    Mynode = e
    while True:
        if Mynode == s:
            path.append(Mynode)
            path.reverse()
            return path
        else:
            path.append(Mynode)
            Mynode = camefrom[Mynode]
            

    #for x in Mynetwork:
    #    if Mynode == e:
    #        return path
    #    else:
    #        path.append(Mynode)
    #        Mynode = camefrom[Mynode]

def goaltest(node, Destination):
    if node == Destination:
        return True
    else:
        return False


def depthLimitedSearch(Start, Destination, Maxdept):

    frontier = [Start]
    depthList = {}
    depthList[Start] = 0
    cameFrom = {}
    visitedList = []

    while True:
        if not frontier:
            return False
        Mynode = frontier[0]
        frontier.remove(Mynode)
        visitedList.append(Mynode)
        if not depthList[Mynode] > Maxdept:
           # if goaltest(Mynode, Destination) == True:
           if Mynode == Destination:
                return reconstructpath(cameFrom, Start, Destination)
           for next in Mynode.Connection: 
                if (next not in visitedList and next not in frontier):
                    frontier.append(next)
                    depthList[next] = depthList[Mynode]+1
                    cameFrom[next] = Mynode
       
    
def IterativeDeepeningSearch(star, sto):
    depth = 0
    begin = Mynetwork[star]
    end = Mynetwork[sto]
    while True:
        depth += 1
        result = depthLimitedSearch(begin, end, depth)
        if result != False:
            for obj in result:
                print(obj.namn,obj.x,obj.y)
            return result

def Heuristic(startNode, endNode):
    hx = startNode.x - endNode.x
    hy = startNode.y - endNode.y
    hx = math.pow(hx, 2)
    hy = math.pow(hy, 2)
    hh = math.sqrt(hy + hx)
    return hh

def PriorityQueue(frontier, goal, heuristicCost):
    score = {}                                                      
    for obj in frontier:                                           
        score[obj] = (heuristicCost[obj]+Heuristic(obj, goal))  
    return min(frontier, key=lambda x: score[x]) 

def a_star_search(start, goal):
    begin = Mynetwork[start]
    end = Mynetwork[goal]
    frontier = [begin]              
    cameFrom = {}                  
    costToNode = {begin : 0}        
    visitedList = []
    
    while True:
        if frontier == []:           
            return False            

        currentNode = PriorityQueue(frontier, end, costToNode)  
        frontier.remove(currentNode)                       
        visitedList.append(currentNode)                  

        if currentNode == end:                          
            path = reconstructpath(cameFrom, begin, end)
            for obj in path:
                print(obj.namn)
            return True

        else:
            for nextNode in currentNode.Connection:                            
                if nextNode not in visitedList and nextNode not in frontier:
                    frontier.append(nextNode)                                                           
                    cameFrom[nextNode] = currentNode                                                   
                    costToNode[nextNode] = costToNode[currentNode] + Heuristic(currentNode, nextNode)   

                if nextNode in visitedList:                                                                
                    if (costToNode[currentNode] + Heuristic(currentNode, nextNode)) < costToNode[nextNode]: 
                        cameFrom[nextNode] = currentNode                                                    
                        costToNode[nextNode] = costToNode[currentNode] + Heuristic(currentNode, nextNode)   
                        frontier.append(nextNode)                                                          
                        visitedList.remove(nextNode)                                                        

                if nextNode in frontier:                                                                    
                    if (costToNode[currentNode] + Heuristic(currentNode, nextNode)) < costToNode[nextNode]: 
                        cameFrom[nextNode] = currentNode                                                    
                        costToNode[nextNode] = costToNode[currentNode] + Heuristic(currentNode, nextNode)   


#val1 = ""
#val2 = ""
print("Välj Start: ")
val1 = input("")
print("\n")

print("Välj Slut: ")
val2 = input("")
print("\n")
print("Iterative: ")
IterativeDeepeningSearch(val1,val2)

print("a*: ")
a_star_search(val1, val2)


    #for obj in Mynetwork:
    #    if(obj.namn == val1):
    #        return obj.namn
    #        for obj2 in obj.Connection:
    #            return obj2.namn
    
