"""
Calculating subsequences of a given string

For eg. a string "abc" has below subsequences
[ abc, ab, bc, ac, a, b, c, "" ]

A string of length n will have 2^n number of subsequences.
In essence, every letter has 2 choices to make. -- Whether to be in the sequence or not. So we multiple all the number of choices to get the total
number of permutations.

I have written two solutions, one using recursion and the other using iteration.


RECURSION + BACKTRACKING
"""

def subsequences(str, idx, newString):
    if idx == len(str):
        if newString in sequences:
            return
        else: 
            print(newString)
            sequences.add(newString)
            return
    
    ## to be
    subsequences(str, idx+1, newString+str[idx])
    ## not to be
    subsequences(str, idx+1, newString)
    
sequences = set()
subsequences("abc",0,"")