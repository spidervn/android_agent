#!/usr/bin/python

#
#   Exclusive method 
#
def execlude_array(arr1, arr2):
    arr_ret = []
    for a1 in arr1:
        found_in_A2 = False
        for a2 in arr2:
            if a1==a2:
                found_in_A2 = True
                break # For loop

        if not found_in_A2:
            arr_ret.append(a1)

    return arr_ret


def conflict_workflow():
    # Workflow of conflict 
    #   => result == true   => Ask for resolving
    #   => result == false  
    ret = True

    if ret:
        pass
    else:
        pass

    return 

def primitive_in_out():
    return

def main():
    print "Main function"
