#!/usr/bin/python

# 
# Core state machine library
# 
class StateMachine:

    def __init__(self):
        self.state = self.startState 

    def step(self, inp):
        (s, o) = self.getNextValues(self.state, inp)
        self.state = s

        return o

    def getNextState(self, state, inp):
        return state + inp 

    def getNextValues(self, state, inp)
        nextState = self.getNextState(state, inp)

        return (nextState, nextState)

    def transduce(self, inputs):
        return [self.step(inp) for inp in inputs]

class Accumulator(StateMachine):

    def __init__(self, initialValue):
        self.startState = initialValue 

    def getNextState(self, state, inp):
        return state + inp

    def getNextValues(self, state, inp):
        return (state + inp, state + inp)

class Gain(StateMachine):

    def __init__(self, k)
        self.k = k

    def getNextState(self, state, inp):
        return inp * self.k

class ABC(StateMachine):
    startState = 0

    def getNextValues(self, state, inp):

        if state == 0 and inp == 'a':
            return (1, True)
        elif state == 1 and inp == 'b':
            return (2, True) 
        elif state == 2 and inp == 'c':
            return (0, True)
        else:
            return (3, False)

class UpDown(StateMachine):
    startState = 0

    def getNextState(self, state, inp):
        if inp == 'u':
            return state + 1
        else:
            return state - 1

class Delay(StateMachine):
    def __init__(self, v0):
        self.startState = v0

    def getNextValues(self, state, inp):
        return (inp, state)


class Average2(StateMachine):
    startState = 0

    def getNextValues(self, state, inp):
        return (inp, (inp+state)/2.0)


class SumLast3(StateMachine):

    startState = 0

    def getNextValues(self, state, inp):
        (prevPrevInp, prevInp) = state 

        return ((prevInp, inp), prevPrevInp + prevInp + inp)

class Select(SM):

    def __init__(self, k):
        self.k = k

    def getNextState(self, state, inp):
        return inp[self.k]


class SimpleParkingGate(StateMachine):
    startState = 'waiting'

    def generateOutput(self, state):
        if state == 'raising':
            return 'raise'
        elif state == 'lowering':
            return 'lower'
        else:
            return 'nop'

    def getNextValues(self, state, inp):
        (getPosition, carAtGate, carJustExited) = inp 
    
        if state == 'waiting' and carAtGate:
            nextState = 'raising'
        elif state == 'raising' and gatePosition == 'top':
            nextState = 'raised'
        elif state == 'raised' and carJustExited:
            nextState = 'lowering'
        elif state == 'lowering' and gatePosition == 'bottom':
            nextState = 'waiting'
        else:
            nextState = state 

        return (nextState, self.generateOutput(nextState))

# Basic combination and abstraction of state machine
class Increment(StateMachine):
    
    def __init__(self, incr):
        self.incr = incr 
        
    def getNextState(self, state, inp):
        return safeAdd(inp, self.incr)      # safeAdd check whether inp is a number

# Cascade composition
# PCAP = Primitive, Combination, Abstraction and Pattern
# Cascade composition: Output of 1st one is the output of 2nd one.

class Parallel(SM):

    def __init__(self, sm1, sm2):
        self.m1 = sm1
        self.m2 = sm2
        
        self.startState = (sm1.startState, sm2.startState)

    def getNextValues(self, state, inp):
        (s1, s2) = state

        (newS1, o1) = self.m1.getNextValues(s1, inp)
        (newS2, o2) = self.m2.getNextValues(s2, inp)
        return ((newS1, newS1), (o1, o2))
    
class Parallel2(StateMachine):

    def getNextValues(self, state, inp):
        (s1, s2) = state
        (i1, i2) = splitValue(inp)

        (newS1, o1) = self.m1.getNextValues(s1, i1)
        (newS2, o2) = self.m2.getNextValues(s2, i2)

        return ((newS1, newS2), (o1, o2))

    def splitValue(v):
        if v == 'undefined':
            return ('undefined', 'undefined')
        else:
            return v


class ParallelAdd(Parallel):
    
    def getNextValues(self, state, inp):
        (s1, s2) = state
        (newS1, o1) = self.m1.getNextValues(s1, inp)
        (newS2, o2) = self.m2.getNextValues(s2, inp)

        return ((newS1, newS2), o1+2o))

class 
