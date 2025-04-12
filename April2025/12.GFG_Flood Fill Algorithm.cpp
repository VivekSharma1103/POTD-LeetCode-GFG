class Solution {
  public:
    void flood(vector<vector<int>> &image, vector<vector<int>> &directions, int sr, int sc, int newColor, int original) {
        int rows = image.size();
        int cols = image[0].size();

        for (auto &dir : directions) {
            int newRow = sr + dir[0];
            int newCol = sc + dir[1];

            if (newRow >= 0 && newRow < rows &&
                newCol >= 0 && newCol < cols &&
                image[newRow][newCol] == original) {
                
                image[newRow][newCol] = newColor;
                flood(image, directions, newRow, newCol, newColor, original);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int original = image[sr][sc];
        if (original == newColor) return image; // avoid infinite loop

        vector<vector<int>> directions({{1,0},{0,1},{-1,0},{0,-1}});
        image[sr][sc] = newColor;
        flood(image, directions, sr, sc, newColor, original);
        return image;
    }
};
