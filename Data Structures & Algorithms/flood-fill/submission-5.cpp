class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }

    void dfs(vector<vector<int>> &aImage, int aRow, int aCol, int aColor, int aOriginalColor)
    {
        int tRowSize = aImage.size();
        int tColSize = aImage[0].size();

        if (aRow >= tRowSize || aCol >= tColSize ||
    std::min(aRow, aCol) < 0 ||
    aImage[aRow][aCol] == aColor ||
    aImage[aRow][aCol] != aOriginalColor)
{
    return;
}

        aImage[aRow][aCol] = aColor;

        dfs(aImage, aRow + 1, aCol, aColor, aOriginalColor);
        dfs(aImage, aRow - 1, aCol, aColor, aOriginalColor);
        dfs(aImage, aRow, aCol + 1, aColor, aOriginalColor);
        dfs(aImage, aRow , aCol - 1, aColor, aOriginalColor);
    }
};