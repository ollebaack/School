import math
import operator

class Var:
    def __init__(self, name):   
        self.name = name
        self.word = ''
        #self.word = domain
        self.domain = ['ADD', 'ADO', 'AGE', 'AGO', 'AID', 'AIL', 'AIM', 'AIR', 'AND',
                       'ANY', 'APE', 'APT', 'ARC', 'ARE', 'ARK', 'ARM', 'ART',
                       'ASH', 'ASK', 'AUK', 'AWE', 'AWL', 'AYE', 'BAD', 'BAG',
                       'BAN', 'BAT', 'BEE', 'BOA', 'EAR', 'EEL', 'EFT', 'FAR', 'FAT',
                       'FIT', 'LEE', 'OAF', 'RAT', 'TAR', 'TIE']

A0 = Var()
A0.name = "A0"
A1 = Var()
A1.name = "A1"
A2 = Var()
A2.name = "A2"
D0 = Var()
D0.name = "D0"
D1 = Var()
D1.name = "D1"
D2 = Var()
D2.name = "D2"


def TestConstraints(var1, word1, var2, word2):   #(A2, ADD, D1, AGE)
    
    x = var1.name[1] #x=2
    y = var2.name[1] #y=1

    if word1[int(y)] == word2[int(x)]:
        print("Du har stor kuk")
    else:
        print("lite du har")



TestConstraints(A2, 'ADD', D1, 'AGE')





    #for a0 in A0.domain:
    #    A0.name = a0
    #    for d0 in D0.domain:
    #        if a1 != d0:
    #            D0.word = d0

    #            if A0.word[0] == D0.word[0]:
    #                for d1 in D1.domain:
    #                    if(a0 != d1) or (d0 != d1):
                
    #                        D1.word = d1
    #                        if A0.word[1] == D1[0]:
    #                            for d2 in D2.domain:
                                     


  
    


#def SELECT_UNASSIGNED_VAR(CSP.Var, assignment, CSP):

def BacktrackingSearch(CSP):

    if True:
        return solution
    else:
        return RecursiveBacktrackingSearch({}, CSP)
   
  
def RecursiveBackTrackingSearch( assignment, CSP):

    if (assignment == True):
        return assignment
    else:
        return "Fail"

    #var = SELECT?UNASSIGNED?VAR(CSP.var, assignment, CSP)
    #for value in ORDERED?DOMAIN?VALUES(var, assignment, csp) :
    #    if (value is consistent with assignment given CSP.constraints) :
    #        add [var = value] to assignment (and propagate consequences)
    #        result = RecursiveBackTrackingSearch(assignment, CSP)
    #    if result�!=�failure then return result
    #        remove [var=value] from assignment
    #        return failure

    
    

