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
    Node *reverseKGroup(Node *head, int k) {
        Node* current = head;
        Node* next = nullptr;
        Node* prev = nullptr;
        int count = 0;

        // Check if there are at least k nodes
        Node* temp = head;
        int nodeCount = 0;
        while (temp != nullptr && nodeCount < k) {
            temp = temp->next;
            nodeCount++;
        }
        if (nodeCount < k) return head;
        
        current = head;
        count = 0;
        while (current != nullptr && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        if (next != nullptr) {
            head->next = reverseKGroup(next, k);
        }

        return prev;
    }
};