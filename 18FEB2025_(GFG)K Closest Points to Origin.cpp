class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max-Heap using priority_queue (stores {distance, point})
        priority_queue<pair<double, vector<int>>> maxHeap;
        
        // Iterate over all points
        for (auto& p : points) {
            double dist = sqrt(p[0] * p[0] + p[1] * p[1]); // Euclidean distance
            
            // Push the current point into the max-heap
            maxHeap.push({dist, p});
            
            // If heap size exceeds k, remove the farthest point
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        // Extract k closest points from the max-heap
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};
