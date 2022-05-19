## https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/problem?isFullScreen=true

def reverse(llist):
    head = llist
    temp = llist
    while temp:
        prev = temp.prev
        temp.prev = temp.next
        temp.next = prev
        head = temp
        temp = temp.prev
    return head