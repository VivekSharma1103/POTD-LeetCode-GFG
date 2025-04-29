class Solution {
  public:
    Node* segregate(Node* head) {
        int count[3] = {0, 0, 0};
        Node* temp = head;

        // Step 1: Count 0s, 1s, and 2s
        while (temp != NULL) {
            count[temp->data]++;
            temp = temp->next;
        }

        // Step 2: Overwrite the linked list with 0s, 1s, and 2s
        temp = head;
        int i = 0;
        while (temp != NULL) {
            if (count[i] == 0) {
                i++;
            } else {
                temp->data = i;
                count[i]--;
                temp = temp->next;
            }
        }

        return head;
    }
};
