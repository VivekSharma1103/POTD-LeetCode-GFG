class Solution {
private:
    vector<int> stack;
    vector<int> minStack; // To keep track of minimum elements
    
public:
    Solution() {}

    // Add an element to the top of Stack
    void push(int x) {
        stack.push_back(x);
        
        // Update minStack
        if (minStack.empty() || x <= minStack.back()) {
            minStack.push_back(x);
        }
    }

    // Remove the top element from the Stack
    void pop() {
        if (!stack.empty()) {
            if (stack.back() == minStack.back()) {
                minStack.pop_back();
            }
            stack.pop_back();
        }
    }

    // Returns top element of the Stack
    int peek() {
        if (!stack.empty()) {
            return stack.back();
        }
        return -1; // Return -1 if stack is empty
    }

    // Finds minimum element of Stack
    int getMin() {
        if (!minStack.empty()) {
            return minStack.back();
        }
        return -1; // Return -1 if stack is empty
    }
};
