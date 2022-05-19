#!/bin/python3

## https://www.hackerrank.com/challenges/compare-two-linked-lists/problem?isFullScreen=true

import os
import sys


def compare_lists(llist1, llist2):
    if llist1 == None and llist2 == None:
        return 1
    elif llist1 == None or llist2 == None:
        return 0
    if llist1.data == llist2.data:
        return compare_lists(llist1.next, llist2.next)
    else:
        return 0
        
if __name__ == '__main__':