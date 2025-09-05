class Node:  # Assuming a Node class exists (or will be created)
    def __init__(self, data):
        self.data = data
        self.next = None

    def sortLinkedList(self, head: Node) -> Node:
        """
        Rearranges a linked list with nodes containing 0s, 1s, and 2s so that all 0s appear at the beginning,
        followed by all 1s, and all 2s are placed at the end.

        Args:
            head: The head of the linked list.

        Returns:
            The head of the rearranged linked list.
        """
        count0 = 0
        count1 = 0
        count2 = 0

        curr = head
        while curr:
            if curr.data == 0:
                count0 += 1
            elif curr.data == 1:
                count1 += 1
            else:
                count2 += 1
            curr = curr.next

        curr = head
        while count0 > 0:
            curr.data = 0
            curr = curr.next
            count0 -= 1

        while count1 > 0:
            curr.data = 1
            curr = curr.next
            count1 -= 1

        while count2 > 0:
            curr.data = 2
            curr = curr.next
            count2 -= 1

        return head