class Node:  # Assuming a Node class exists
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

    def reverseDLL(self, head: 'Node') -> 'Node':
        if head is None or head.next is None:
            return head

        curr = head
        prev = None

        while curr:
            next_node = curr.next

            curr.next = prev
            curr.prev = next_node

            prev = curr
            curr = next_node

        return prev