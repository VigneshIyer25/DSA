#!/bin/python3

## https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true
## WHAT I LEARNT:
# instead of actually maintaining the sum of elements in the new array, we are just maintainging the range here.
# this way we just have to update two elements in the array instead of all the elements, increasing time complexity
# At the last we traverse the new array to get the max sum


import math
import os
import random
import re
import sys

#
# Complete the 'arrayManipulation' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. 2D_INTEGER_ARRAY queries
#

def arrayManipulation(n, queries):
    # Write your code here
    res = [0]*n
    for query in queries:
        start = query[0]-1
        end = query[1]
        p = query[2]
        res[start] += p
        if end < n: res[end] -= p;
    max_ = x = 0
    for i in res:
        x=x+i
        if x>max_: max_=x
    return max_

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    queries = []

    for _ in range(m):
        queries.append(list(map(int, input().rstrip().split())))

    result = arrayManipulation(n, queries)

    fptr.write(str(result) + '\n')

    fptr.close()
