#include <bits/stdc++.h>
using namespace std;

/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        
        if (fast == NULL || fast->next == NULL) {
            return 0;
        }
        
        int count = 1;
        slow = slow->next;
        while (slow != fast) {
            count++;
            slow = slow->next;
        }
        
        return count;
    }
};