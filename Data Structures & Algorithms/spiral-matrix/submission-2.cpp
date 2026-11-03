class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        std::vector<int> tReturn;
        int tRow = 0; 
        int tCol = -1;
        while (tReturn.size() != matrix[0].size() * matrix.size())
        {
            // Right 
            singleDirectionDFS(matrix, tRow, tCol, {0, 1}, tReturn);
            // Down 
            singleDirectionDFS(matrix, tRow, tCol, {1, 0}, tReturn);
            // Left 
            singleDirectionDFS(matrix, tRow, tCol, {0, -1}, tReturn);
            // Up 
            singleDirectionDFS(matrix, tRow, tCol, {-1, 0}, tReturn);
        }

        return tReturn;
    }

    void singleDirectionDFS(vector<vector<int>> &aMatrix, int &aRow, int &aCol, std::pair<int,int> aDirection, std::vector<int> &aVisitedPath)
    {
        // Check the next cell
        aRow += aDirection.first;       
        aCol += aDirection.second;

        // Bounds checking
        if (aRow >= aMatrix.size() || aCol >= aMatrix[0].size() || std::min(aRow, aCol) < 0)
        {
            aRow -= aDirection.first;
            aCol -= aDirection.second;
            return;
        }

        if (aMatrix[aRow][aCol] == -101)
        {
            aRow -= aDirection.first;
            aCol -= aDirection.second;
            return;
        }

        aVisitedPath.push_back(aMatrix[aRow][aCol]);
        aMatrix[aRow][aCol] = -101;
        singleDirectionDFS(aMatrix, aRow, aCol, aDirection, aVisitedPath);
    }
};
