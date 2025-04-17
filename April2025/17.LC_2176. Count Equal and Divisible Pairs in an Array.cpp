int countPairs(vector<int>& nums, int k) {
    unordered_map<int, vector<int>> valueToIndices;
    int count = 0;

    // Step 1: Group indices by the value of nums[i]
    for (int i = 0; i < nums.size(); ++i) {
        valueToIndices[nums[i]].push_back(i);
    }

    // Step 2: For each group of equal values, check (i * j) % k == 0
    for (auto& [value, indices] : valueToIndices) {
        int size = indices.size();
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if ((indices[i] * indices[j]) % k == 0) {
                    count++;
                }
            }
        }
    }

    return count;
}
