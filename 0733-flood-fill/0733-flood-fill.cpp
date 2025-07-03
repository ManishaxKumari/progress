class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int color, int originalColor) {
        int m = image.size();
        int n = image[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || image[i][j] != originalColor){
                  return;
        }
        image[i][j] = color;
        dfs(image, i + 1, j, color, originalColor); // down
        dfs(image, i - 1, j, color, originalColor); // up
        dfs(image, i, j + 1, color, originalColor); // right
        dfs(image, i, j - 1, color, originalColor); // left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        // Edge Case — If color is already same, return image
        if (originalColor == color){
            return image;
        }
        dfs(image, sr, sc, color, originalColor);
        return image;
    }
};