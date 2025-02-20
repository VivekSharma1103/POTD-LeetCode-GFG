


class Solution {
public:
    vector<double> getMedian(vector<int> &arr) {
        int n = arr.size();
        vector<double> ans;
        multiset<int> num;
        auto mid = num.begin();  // Iterator to track median

        for (int i = 0; i < n; i++) {
            num.insert(arr[i]);

            // Adjust median iterator
            if (num.size() == 1) {
                mid = num.begin();
            } else if (arr[i] < *mid) {
                if (num.size() % 2 == 0) {
                    --mid;
                }
            } else {
                if (num.size() % 2 != 0) {
                    ++mid;
                }
            }

            // Compute median
            if (num.size() % 2 != 0) {
                ans.push_back(*mid);
            } else {
                auto nextMid = next(mid);
                ans.push_back((*mid + *nextMid) / 2.0);
            }
        }

        return ans;
    }
};


