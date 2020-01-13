import sys
import math

def print_pages(numpage, startId=1):
    ret = []


    numpagea4 = int(math.ceil(numpage/8.0))
    numpage = int(8 * numpagea4)

    print(numpagea4)
    startId = startId-1

    for i in range(numpagea4):
        print(i)
        pid = i + 1
        ret.append(startId + 4*pid -2)
        ret.append(startId + numpage - 4*pid +3)
        ret.append(startId + 4*pid)
        ret.append(startId + numpage - 4*pid + 1)
        ret.append(startId + numpage - 4*pid +4)
        ret.append(startId + 4*pid - 3)
        ret.append(startId + numpage-4*pid+2)
        ret.append(startId + 4*pid - 1)

    return ret


r = print_pages(9)
print(r)

print(math.ceil(2.1))