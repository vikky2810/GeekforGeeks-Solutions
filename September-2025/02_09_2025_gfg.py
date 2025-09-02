class Solution:
    def swapKthNode(self, head, k):
        """
        Swaps the kth node from the beginning and the kth node from the end of a singly linked list.

        Args:
            head: The head of the singly linked list.
            k: The index of the node to swap (1-based index).

        Returns:
            The head of the modified linked list after swapping, or the original list if the swap is not possible.
        """
        if not head or k <= 0:
            return head

        # Find the length of the linked list
        length = 0
        curr = head
        while curr:
            length += 1
            curr = curr.next

        if k > length:
            return head

        if 2 * k - 1 == length:
            return head
        
        # Find kth node from beginning and its predecessor
        prev_k_start = None
        curr_k_start = head
        for _ in range(k - 1):
            prev_k_start = curr_k_start
            curr_k_start = curr_k_start.next

        # Find kth node from end and its predecessor
        prev_k_end = None
        curr_k_end = head
        for _ in range(length - k):
            prev_k_end = curr_k_end
            curr_k_end = curr_k_end.next

        # Swap the nodes
        if prev_k_start:
            prev_k_start.next = curr_k_end
        if prev_k_end:
            prev_k_end.next = curr_k_start

        temp = curr_k_start.next
        curr_k_start.next = curr_k_end.next
        curr_k_end.next = temp

        if k == 1:
            head = curr_k_end
        elif k == length:
            head = curr_k_start

        return head