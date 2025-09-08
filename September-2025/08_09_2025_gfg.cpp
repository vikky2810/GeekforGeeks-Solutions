#include <bits/stdc++.h>
using namespace std;

/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* mergeSort(Node* head) {
        // code here
        if (!head || !head->next) {
            return head;
        }

        Node* slow = head;
        Node* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* mid = slow->next;
        slow->next = nullptr;

        Node* left = mergeSort(head);
        Node* right = mergeSort(mid);

        return merge(left, right);
    }

    Node* merge(Node* left, Node* right) {
        Node* dummy = new Node(-1);
        Node* tail = dummy;

        while (left && right) {
            if (left->data <= right->data) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        if (left) {
            tail->next = left;
        } else {
            tail->next = right;
        }

        return dummy->next;
    }
};