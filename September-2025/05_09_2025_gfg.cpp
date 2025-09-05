#include <bits/stdc++.h>
using namespace std;

/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);
        
        Node* zeroTail = zeroHead;
        Node* oneTail = oneHead;
        Node* twoTail = twoHead;
        
        Node* curr = head;
        
        while(curr != nullptr){
            if(curr->data == 0){
                zeroTail->next = curr;
                zeroTail = curr;
            } else if(curr->data == 1){
                oneTail->next = curr;
                oneTail = curr;
            } else {
                twoTail->next = curr;
                twoTail = curr;
            }
            curr = curr->next;
        }
        
        zeroTail->next = (oneHead->next != nullptr) ? oneHead->next : twoHead->next;
        oneTail->next = twoHead->next;
        twoTail->next = nullptr;
        
        Node* newHead = zeroHead->next;
        
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return newHead;
    }
};