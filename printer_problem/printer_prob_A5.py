# Python 3
import sys
import math

def print_readable(frompage, topage, arr):
    for i in range(len(arr)):
        if i > 0:
            print(",", end="")
        if arr[i] <= topage:
            print(arr[i], end="")
        else:
            print("OUT", end="")
    print("")

def print_pages(numpage, startId=1):
    ret = []

    numpageAlign4 = int(4*(math.ceil(numpage/4.0)))
    numpagea4 = int(math.ceil(numpageAlign4/4.0))
    numpage = int(4 * numpagea4)

    print(numpagea4)
    startId = startId-1

    for i in range(numpagea4):
        print(i)
        pid = i + 1
        ret.append(startId + 2*pid)
        ret.append(startId + numpageAlign4 - 2*pid + 1)
        ret.append(startId + numpageAlign4-2*pid+2)
        ret.append(startId + 2*pid - 1)

    return ret

def print_pages01(frompage, topage):

    numpage = topage - frompage + 1
    return print_pages(numpage, frompage)

numpg = 3

frompg=1
topg=16

r = print_pages01(frompg, topg)
print_readable(frompg, topg, r)
