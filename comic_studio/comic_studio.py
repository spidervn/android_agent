#!/usr/bin/python

# Program interface first

def ComicStudioMain:

    def __init__(self):
        self.count = 0

        self.dict_knowledge = {}    # Dictionary of task 
        self.core_task = {}         # Core of Tasking
        self.combine_task = {}      # Combination of tasks


    def install_task():             # Ability to Install new task
        return

    def work():

        mainWork = AutoAskNode()
        
        while True:

            inp = get_user_input()

            mainWork.step(inp)

        return 

# Build all primitive nodes
class WorkChain:

    nodes = [] 

    def __init__(self):
        pass

    def addNode(self, wn):
        # Add new workNode
        n_ret = 0 # Success

        for current_wn in nodes:
            if current_wn.code == wn.code:
                n_ret = 1
                break

        if n_ret == 0:
            nodes.append(wn)

        return n_ret
    
    def starts(wn):
        # Define start Node
        pass

    def ends(wn):
        # Define end Node
        pass
    def run(inp):
        for wnode in nodes:
            wnode.doWork()            

class WorkNode:
    def __init__(self, code):
        self.code = code
        pass
    
    def doWork(inp):
        return None    

def DoDomesticTask:

    def __init__(self):
        self.count = 1

def AutoAsk:
    
    def __init__(self):
        print "Done"

    def __init__(self):
        print "Done"


