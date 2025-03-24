class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int freeDays = days;
        int lastEnd = 0;
        
        for (auto &meet : meetings) {
            int start = meet[0];
            int end = meet[1];
            
            if (start > lastEnd) {
                freeDays -= (end - start + 1);
                lastEnd = end;
            } else if (end > lastEnd) {
                freeDays -= (end - lastEnd);
                lastEnd = end;
            }
        }
        
        return freeDays;
    }
};
