class Solution {
public:
    bool can_assign(int k, const vector<int>& tasks, const vector<int>& workers, int pills, int strength) {
        multiset<int> worker_pool(workers.end() - k, workers.end()); // Strongest k workers

        for (int i = k - 1; i >= 0; --i) { // Hardest k tasks
            int task = tasks[i];
            auto it = worker_pool.lower_bound(task); // Try to find worker who can do task without pill

            if (it != worker_pool.end()) {
                worker_pool.erase(it);
            } else {
                if (pills == 0) return false;
                auto it2 = worker_pool.lower_bound(task - strength); // Use pill to boost weaker worker
                if (it2 == worker_pool.end()) return false;
                worker_pool.erase(it2);
                pills--;
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 0, right = min(tasks.size(), workers.size()), result = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (can_assign(mid, tasks, workers, pills, strength)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};
