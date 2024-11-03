class Solution {
  public:
    bool isLengthEven(struct Node **head) {
        int count = 0;
        Node* curr = *head; // Single pointer to iterate through the list
        while (curr != NULL) {
            count++;
            curr = curr->next;
        }
        return count % 2 == 0; // true if even, false if odd
    }
};
