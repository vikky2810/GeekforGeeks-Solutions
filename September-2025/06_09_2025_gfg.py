class Solution:
    def lengthOfLoop(self, head):
        """
        :type head: Node
        :rtype: int
        """
        slow = head
        fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                break

        if not fast or not fast.next:
            return 0

        count = 1
        slow = slow.next
        while slow != fast:
            count += 1
            slow = slow.next

        return count