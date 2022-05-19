## https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem?isFullScreen=true

def mergeLists(head1, head2):
    if head1 == None:
        return head2
    res = SinglyLinkedList()
    while head1:
        if head2 == None:
            res.insert_node(head1.data)
            head1 = head1.next
        elif head2 != None and head1.data <= head2.data:
            res.insert_node(head1.data)
            head1 = head1.next
        else:
            res.insert_node(head2.data)
            head2 = head2.next
    
    while head2:
        res.insert_node(head2.data)
        head2 = head2.next
    return res.head