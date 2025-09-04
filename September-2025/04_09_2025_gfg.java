/*
class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}
*/

class Solution {
    public Node reverseKGroup(Node head, int k) {
        Node current = head;
        Node next = null;
        Node prev = null;
        int count = 0;

        // Check if there are at least k nodes
        Node temp = head;
        int nodeCount = 0;
        while (temp != null && nodeCount < k) {
            temp = temp.next;
            nodeCount++;
        }
        if (nodeCount < k) {
            return head;
        }

        // Reverse k nodes
        while (current != null && count < k) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
            count++;
        }

        // next is now a pointer to (k+1)th node
        // Recursively call for the list starting from next.
        // And make rest of the list as next of first node
        if (next != null) {
            head.next = reverseKGroup(next, k);
        }

        // prev is now head of the reversed list
        return prev;
    }
}