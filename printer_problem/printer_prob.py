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

    numpageAlign8 = int(8*(math.ceil(numpage/8.0)))
    numpagea4 = int(math.ceil(numpageAlign8/8.0))
    numpage = int(8 * numpagea4)

    print(numpagea4)
    startId = startId-1

    for i in range(numpagea4):
        print(i)
        pid = i + 1
        ret.append(startId + 4*pid -2)
        ret.append(startId + numpageAlign8 - 4*pid +3)
        ret.append(startId + 4*pid)
        ret.append(startId + numpageAlign8 - 4*pid + 1)
        ret.append(startId + numpageAlign8 - 4*pid +4)
        ret.append(startId + 4*pid - 3)
        ret.append(startId + numpageAlign8-4*pid+2)
        ret.append(startId + 4*pid - 1)

    return ret

def print_pages01(frompage, topage):

    numpage = topage - frompage + 1
    return print_pages(numpage, frompage)

numpg = 3

r = print_pages01(219, 257)
print_readable(219, 257, r)
