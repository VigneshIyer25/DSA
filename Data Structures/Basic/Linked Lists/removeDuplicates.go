// https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/problem?isFullScreen=true

func removeDuplicates(llist *SinglyLinkedListNode) *SinglyLinkedListNode {
    if llist == nil {
        return nil
    }
    curr := llist
    for curr.next != nil {
        fmt.Println(curr.data)
        if curr.data == curr.next.data {
            curr.next = curr.next.next
        }else {
            curr = curr.next
        }
    }
    return llist 
}