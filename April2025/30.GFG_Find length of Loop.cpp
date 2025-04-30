class Solution {
  public:
    int countNodesinLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect loop using Floyd's algorithm
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Loop detected, count the nodes in the loop
                return countLoopNodes(slow);
            }
        }

        // No loop found
        return 0;
    }

  private:
    int countLoopNodes(Node* loopNode) {
        int count = 1;
        Node* current = loopNode->next;

        while (current != loopNode) {
            count++;
            current = current->next;
        }

        return count;
    }
};
