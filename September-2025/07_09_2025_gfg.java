/*
class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}
*/

import java.util.PriorityQueue;

class Solution {
    Node mergeKLists(Node[] arr) {
        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> a.data - b.data);

        for (Node head : arr) {
            if (head != null) {
                pq.add(head);
            }
        }

        if (pq.isEmpty()) {
            return null;
        }

        Node dummy = new Node(-1);
        Node tail = dummy;

        while (!pq.isEmpty()) {
            Node curr = pq.poll();
            tail.next = curr;
            tail = curr;

            if (curr.next != null) {
                pq.add(curr.next);
            }
        }

        return dummy.next;
    }
}