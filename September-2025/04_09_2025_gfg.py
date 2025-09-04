class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def reverseKNodes(head: ListNode, k: int) -> ListNode:
    """
    Reverses every k nodes in a linked list.
    If the number of nodes is not a multiple of k then the left-out nodes at the end,
    should be considered as a group and must be reversed.
    """
    if not head or k == 1:
        return head

    dummy = ListNode(0)
    dummy.next = head
    pre = dummy
    curr = head

    while True:
        count = 0
        temp = curr
        while temp and count < k:
            temp = temp.next
            count += 1

        if count < k:
            break

        prev = None
        next_node = None
        count = 0
        temp_curr = curr
        while curr and count < k:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
            count += 1

        pre.next = prev
        temp_curr.next = curr
        pre = temp_curr

    return dummy.next