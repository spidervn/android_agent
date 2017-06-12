#!/usr/bin/python

from comic_studio import *

# All primitive machine
class SmoothWait(WorkChain):

    IDLE = 1
    WAIT = 2
    WAIT_LONG = 3

    def __init__(self):
        pass

    def getNextStep(self, state, inp):
        pass

class Switcher(WorkChain):

    def __init__(self, list_condition, list_listener):
        pass

#
#   Primitive Machine
#       CareMachine (General)
#       SmoothlyWait (General)
#
class AutoAskNode(WorkChain):

    def __init__(self):
        super()        

        wn_wait = SmoothWait()
        addNode(wm_wait)

