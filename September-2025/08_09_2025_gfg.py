class Solution:
    def mergeSort(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head

        # Find the middle of the linked list using the slow and fast pointer approach.
        slow = head
        fast = head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # Split the linked list into two halves.
        mid = slow.next
        slow.next = None

        # Recursively sort the two halves.
        left = self.mergeSort(head)
        right = self.mergeSort(mid)

        # Merge the two sorted halves.
        return self.merge(left, right)

    def merge(self, left, right):
        """
        Merges two sorted linked lists into a single sorted linked list.
        :type left: ListNode
        :type right: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(0)
        tail = dummy

        while left and right:
            if left.data < right.data:
                tail.next = left
                left = left.next
            else:
                tail.next = right
                right = right.next
            tail = tail.next

        if left:
            tail.next = left
        if right:
            tail.next = right

        return dummy.next