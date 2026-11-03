class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        int tLeftPtr = 0;
        int tRightPtr = heights.size() - 1;
        int tMaxArea = 0;

        // 7 = max
        // 36 = max

        while (tLeftPtr < tRightPtr)
        {
            int tHeight = std::min(heights[tLeftPtr], heights[tRightPtr]);
            int tArea = tHeight * std::abs(tRightPtr - tLeftPtr);
            tMaxArea = std::max(tArea, tMaxArea);
            if (heights[tLeftPtr] > heights[tRightPtr])
            {
                --tRightPtr;
            }
            else 
            {
                ++tLeftPtr;
            }
        }

        return tMaxArea;
    }
};
