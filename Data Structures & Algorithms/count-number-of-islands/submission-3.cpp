class Solution {
public:
    int numIslands(vector<vector<char>>& aGrid) 
    {
        int tRowLength = aGrid.size();
        int tColLength = aGrid[0].size();
        int tNumOfIslands = 0;

        for (int i = 0; i < tRowLength; ++i)
        {
            for (int j = 0; j < tColLength; ++j)
            {
                if (aGrid[i][j] == '1')
                {
                    ++tNumOfIslands;
                    bfs(aGrid, i, j);
                }
            }
        }

        return tNumOfIslands;
    }

    void bfs(vector<vector<char>>& aGrid, int aRow, int aCol)
    {
        // We are going to need a queue
        // we will need to loop until queue is completely empty
        // we must add to the queue until we can't find another 1 and then increment counter

        aGrid[aRow][aCol] = '0';
        std::queue<std::pair<int, int>> tQueue;
        tQueue.push({aRow,aCol});

        while (tQueue.empty() == false)
        {
            std::pair<int, int> tCord = tQueue.front();
            tQueue.pop();

            // Check all four coordinates around our interested point
            std::pair<int,int> tUp = {tCord.first + 1, tCord.second};
            std::pair<int,int> tDown = {tCord.first - 1, tCord.second};
            std::pair<int,int> tLeft = {tCord.first, tCord.second + 1};
            std::pair<int,int> tRight = {tCord.first, tCord.second - 1};
            std::queue<std::pair<int, int>> tSecondQueue;
            tSecondQueue.push(tUp);
            tSecondQueue.push(tDown);
            tSecondQueue.push(tLeft);
            tSecondQueue.push(tRight);

            while (tSecondQueue.empty() == false)
            {
                auto tTry = tSecondQueue.front();
                tSecondQueue.pop();

                if (std::min(tTry.first, tTry.second) >= 0 
                && tTry.first < aGrid.size()
                && tTry.second < aGrid[0].size()
                && aGrid[tTry.first][tTry.second] == '1')
                {
                    aGrid[tTry.first][tTry.second] = '0';
                    tQueue.push(tTry);
                }
            }
        }
    }

    // void dfs(vector<vector<char>>& aGrid, int aRow, int aCol)
    // {
    //     // Safety
    //     int tRowLength = aGrid.size();
    //     int tColLength = aGrid[0].size();

    //     if (std::min(aRow, aCol) < 0)
    //     {
    //         return;
    //     }

    //     if (aRow >= tRowLength || aCol >= tColLength)
    //     {
    //         return;
    //     }

    //     // Do nothing with 0

    //     if (aGrid[aRow][aCol] == '0')
    //     {
    //         return;
    //     }
    //     else 
    //     {
    //         aGrid[aRow][aCol] = '0';
    //     }

    //     dfs(aGrid, aRow + 1, aCol);
    //     dfs(aGrid, aRow - 1, aCol);
    //     dfs(aGrid, aRow, aCol + 1);
    //     dfs(aGrid, aRow , aCol - 1);
    // }
};
