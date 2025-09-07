class Solution:
    def mergeKLists(self, arr):
        """
        :param arr: An array of sorted linked lists.
        :return: The head of the merged sorted linked list.
        """
        import heapq

        heap = []
        for head in arr:
            if head:
                heapq.heappush(heap, (head.data, head))

        dummy = ListNode(0)
        curr = dummy

        while heap:
            val, node = heapq.heappop(heap)
            curr.next = node
            curr = curr.next
            if node.next:
                heapq.heappush(heap, (node.next.data, node.next))

        return dummy.next