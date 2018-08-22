""" docstring
Input          : 
Output         : 
Initialization : 
                 
Maintenance    : 
                 
Termination    : 
Paradigm       : Divide and Conquer
Analysis       : 
"""

# https://github.com/liuxinyu95/AlgoXY/blob/algoxy/sorting/merge-sort/src/mergesort.py

########################################################################
from inliner import inline

@inline
def end(list):
    return len(list) <= 1

def merge1(leftList, rightList, newList = []):
    while (len(leftList) > 0 and len(rightList) > 0): 
        if (leftList[0] <= rightList[0]):
            newList.append(leftList[0])
            del leftList[0]
        else:
            newList.append(rightList[0])
            del rightList[0]
    while (len(leftList) > 0):
        newList.append(leftList[0])
        del leftList[0]
    while (len(rightList) > 0):
        newList.append(rightList[0])
        del rightList[0]
    return newList

def divide1(mainList):
    mid = len(mainList) / 2
    return mainList[:mid], mainList[mid:]
  
def mergeSort1(mainList):
    if end(mainList):
        return mainList
    leftList, rightList = divide1(mainList)
    return merge1(mergeSort1(leftList), mergeSort1(rightList))

########################################################################
from inliner import inline

@inline
def increment(i):
    return i = i + 1
  
def merge2(leftList, rightList, newList = [], iLeft = 0, iRight = 0):
    while (iLeft < len(leftList) and iRight < len(rightList)): 
        if (leftList[iLeft] <= rightList[iRight]):
            newList.append(leftList[iLeft])
            increment(iLeft)
        else:
            newList.append(rightList[iRight])
            increment(iRight)
    while (iLeft < len(leftList)):
        newList.append(leftList[iLeft])
        increment(iLeft)
    while (iRight < len(rightList)):
        newList.append(rightList[iRight])
        increment(iRight)
    return newList

def divide2(mainList):
    mid = len(mainList) / 2
    return mainList[:mid], mainList[mid:]
  
def mergeSort2(mainList):
    if len(mainList) <= 1:
        return mainList
    leftList, rightList = divide2(mainList)
    return merge2(mergeSort2(leftList), mergeSort2(rightList))
  
########################################################################
  
if __name__ == "__main__":
    list = [int(i) for i in input("Input Elements: ").split()]
    print(mergeSort1(list))
    print(mergeSort2(list))
