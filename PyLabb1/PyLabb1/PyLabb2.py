import math
import operator
import copy

class Var:
    def __init__(self, name):   
        self.name = name
        self.word = ''
        #self.word = domain
        #self.domain = ['ADD', 'ADO', 'AGE', 'AGO', 'AID', 'AIL', 'AIM', 'AIR', 'AND',
        #               'ANY', 'APE', 'APT', 'ARC', 'ARE', 'ARK', 'ARM', 'ART',
        #               'ASH', 'ASK', 'AUK', 'AWE', 'AWL', 'AYE', 'BAD', 'BAG',
        #               'BAN', 'BAT', 'BEE', 'BOA', 'EAR', 'EEL', 'EFT', 'FAR', 'FAT',
        #               'FIT', 'LEE', 'OAF', 'RAT', 'TAR', 'TIE']
        self.domain = ['ADD','BEE', 'OAF','ART','BOA', 'EAR', 'EFT']

A0 = Var("A0")
A1 = Var("A1")
A2 = Var("A2")
D0 = Var("D0")
D1 = Var("D1")
D2 = Var("D2")

Global = [A0, A1, A2, D0, D1, D2]
A_D_words = [] + Global
def TestConstraints(var1, word1, var2, word2):   #(A2, ADD, D1, AGE)
    if word1==word2:
        return False
    x = var1.name[1] #x=2
    y = var2.name[1] #y=1

    if (word1[int(y)] == word2[int(x)] or var1.name[0] == var2.name[0]): 

        return True
    else:
        return False


def testempty(varlist):
    for var in varlist:
        if(var.word ==''):
            return var
      


def test(varlist,var,word):
    for v in varlist:
       if v.word != '':
           if TestConstraints(var,word,v,v.word) == False:
              return False
    return True
           



def arc(x):
    queue = []
    for y in A_D_words:
        if(y!=x):
            queue.append(y)
            queue.append(x)
    while queue != []:
        xi = queue.pop(0)
        xj = queue.pop(0)
        if(remove_consistant_value((xi,xj))==True): # tuples
           for xk in not xi:
                queue.append(xk)
                queue.append(xi)

def remove_consistant_value(arc):   
    removed = False
    for x in arc[0].domain:
        consistant = False
        for y in arc[1].domain:
            if (arc[0].name[0] != arc[1].name[0]):
                TestConstraints(arc[0],x,arc[1],y) #anropa dina constraints
                consistant = True
    if consistant == True:
        removed = True
        return removed


def recbacktrack(varlist):
    
    kopialista = []
  
    # skriver resultat

    var = testempty(varlist)# kollar tom plats
    if(varlist[0].word !='' and varlist[1].word !='' and varlist[2].word !='' and varlist[3].word !='' and varlist[4].word!='' and varlist[5].word!=''):
        return varlist
    if(varlist[0].word !='' and varlist[1].word !='' and varlist[2].word !='' and varlist[3].word !='' and varlist[4].word!=''):
        print("ALMOSSSTTTT")
    #if not var:
    #    return varlist

    for value in var.domain:
        if(test(varlist,var,value)==True):
            var.word = value 
            arc(value)
            kopialista=copy.deepcopy(varlist)
            result= recbacktrack(kopialista)
            if result != False:
                #print(varlist[0].word , varlist[1].word , varlist[2].word , varlist[3].word , varlist[4].word , varlist[5].word)
                return result
            var.word = ''
         
    return False



resultat = recbacktrack(Global)
for it in resultat:
    print(it.name," ",it.word)




    

