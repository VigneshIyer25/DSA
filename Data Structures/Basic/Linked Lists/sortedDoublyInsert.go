// https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem?isFullScreen=true

func sortedInsert(llist *DoublyLinkedListNode, data int32) *DoublyLinkedListNode {
    // Write your code here
    var newnode DoublyLinkedListNode
    newnode.data = data
    
    //first case 
    if llist == nil { 
        llist = &newnode 
    }else if data < llist.data {
        newnode.next = llist
        llist.prev = &newnode
        llist = &newnode
    }else {
        curr := llist
        for curr.next != nil && curr.data < data {
            curr = curr.next
        }
        if curr.next == nil && curr.data < data{
            curr.next = &newnode
            newnode.prev = curr
        }else {
            previous := curr.prev
            previous.next = &newnode
            newnode.next = curr
            newnode.prev = previous
            curr.prev = &newnode
        }
    }
    return llist
}