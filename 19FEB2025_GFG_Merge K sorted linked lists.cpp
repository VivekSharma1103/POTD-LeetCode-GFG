struct Compare {
    bool operator()(const Node* a, const Node* b) {
        return a->data > b->data; // Min heap
    }
};

class Solution {
public:
    Node* mergeKLists(vector<Node*>& lists) {
        priority_queue<Node*, vector<Node*>, Compare> minHeap;

      
        for (Node* list : lists) {
            if (list) minHeap.push(list);
        }

      
        Node* dummy = new Node(0);
        Node* tail = dummy;

        while (!minHeap.empty()) {
          
            Node* smallest = minHeap.top();
            minHeap.pop();

         
            tail->next = smallest;
            tail = tail->next;

          
            if (smallest->next) {
                minHeap.push(smallest->next);
            }
        }
st
        return dummy->next; 
    }
};
