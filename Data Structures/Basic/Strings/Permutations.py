"""
Calculating all permutations of a given string.

for eg. abc
==> abc,acb,bac,bca,cab,cba
RECURSION TREE
            a        b         c
           / \      / \       / \ 
         ab  ac    ba  bc    ca cb    ^
        /     \    /    \    /   \    |    We backtrack from root to top in an inorder traversal fasion.
      abc     acb bac   bca cab  cba  |
"""

def permutations(string, perm):
    if string == "":
        print(perm)
        return
    
    for i in string:
        currChar = i 
        permutations(string.replace(currChar,""), perm+currChar)
        
if __name__ == "__main__":
    permutations("abc","")