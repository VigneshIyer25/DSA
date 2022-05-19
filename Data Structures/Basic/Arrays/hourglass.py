## https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'hourglassSum' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#
def getSum(arr):
    s = 0
    print(arr)
    s+=sum(arr[0][:])
    s+=arr[1][1]
    s+=sum(arr[2][:])
    return s

def hourglassSum(arr):
    # Write your code here
    max_sum = -9999
    for i in range(0,4):
        for j in range(0,4):
            temp = []
            temp.append(arr[i][j:j+3])
            temp.append(arr[i+1][j:j+3])
            temp.append(arr[i+2][j:j+3])
            s=getSum(temp)
            if s>max_sum:
                max_sum=s
    
    return max_sum

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    result = hourglassSum(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
