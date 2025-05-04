class Solution {
public:
    int check(int target, vector<int>& tops, vector<int>& bottoms) {
        int rotate_top = 0, rotate_bottom = 0;
        for (int i = 0; i < tops.size(); ++i) {
            // If target not present at either top or bottom, it's invalid
            if (tops[i] != target && bottoms[i] != target) {
                return -1;
            }
            else if (tops[i] != target) {
                rotate_top++; // must rotate top
            }
            else if (bottoms[i] != target) {
                rotate_bottom++; // must rotate bottom
            }
        }
        return min(rotate_top, rotate_bottom);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int rotations = check(tops[0], tops, bottoms);
        if (rotations != -1) return rotations;

        // If tops[0] and bottoms[0] are the same, no need to check again
        if (tops[0] == bottoms[0]) return -1;

        return check(bottoms[0], tops, bottoms);
    }
};
