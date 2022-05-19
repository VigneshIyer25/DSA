
## https://www.hackerrank.com/challenges/reverse-a-linked-list/problem
#
# Complete the 'reverse' function below.
#
# The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
# The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
#

#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#

def reverse(llist):
    # Write your code here
    head = llist
    temp = head.next
    head.next = None
    while temp != None:
        curr = temp
        temp = temp.next
        curr.next = head
        head = curr
    return head
        
