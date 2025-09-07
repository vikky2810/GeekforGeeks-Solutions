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
    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<pair<int, Node*>, vector<pair<int, Node*> >, greater<pair<int, Node*> > > pq;
        
        for(Node* head : arr){
            if(head){
                pq.push({head->data, head});
            }
        }
        
        Node* dummy = new Node(-1);
        Node* tail = dummy;
        
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            
            tail->next = curr.second;
            tail = tail->next;
            
            if(curr.second->next){
                pq.push({curr.second->next->data, curr.second->next});
            }
        }
        
        return dummy->next;
    }
};