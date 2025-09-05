/*
class Node {
    int data;
    Node next;

    Node(int d)
    {
        data = d;
        next = null;
    }
}*/

class Solution {
    public Node segregate(Node head) {
        // code here
        Node zeroHead = new Node(-1);
        Node oneHead = new Node(-1);
        Node twoHead = new Node(-1);

        Node zeroTail = zeroHead;
        Node oneTail = oneHead;
        Node twoTail = twoHead;

        Node curr = head;

        while (curr != null) {
            if (curr.data == 0) {
                zeroTail.next = curr;
                zeroTail = curr;
            } else if (curr.data == 1) {
                oneTail.next = curr;
                oneTail = curr;
            } else {
                twoTail.next = curr;
                twoTail = curr;
            }
            curr = curr.next;
        }

        zeroTail.next = (oneHead.next != null) ? oneHead.next : twoHead.next;
        oneTail.next = twoHead.next;
        twoTail.next = null;

        return (zeroHead.next != null) ? zeroHead.next : ((oneHead.next != null) ? oneHead.next : twoHead.next);
    }
}