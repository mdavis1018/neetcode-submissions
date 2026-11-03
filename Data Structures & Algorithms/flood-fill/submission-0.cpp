class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int startingColor, int color)
    {
        int tRowLength = image.size();
        int tColLength = image[0].size();

        // Can't be out of range
        if (sr > tRowLength - 1 || sc > tColLength - 1)
        {
            return;
        }

        if (std::min(sr,sc) < 0)
        {
            return;
        }

        // If we already visited, i.e already colored the index
        if (image[sr][sc] == color)
        {
            return;
        }

        // Can't be non-starting color
        if (image[sr][sc] != startingColor)
        {
            return;
        }
        else 
        {
            image[sr][sc] = color;
        }

        // Try each direction (4)
        dfs(image, sr + 1, sc, startingColor, color);
        dfs(image, sr - 1, sc, startingColor, color);
        dfs(image, sr, sc + 1, startingColor, color);
        dfs(image, sr, sc - 1, startingColor, color);
    }
};