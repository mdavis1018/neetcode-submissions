class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        auto tRight = std::prev(numbers.end());    
        auto tLeft = numbers.begin();

        while (tLeft < tRight)
        {
            if (*tLeft + *tRight == target)
            {
                return {static_cast<int>(std::distance(numbers.begin(), tLeft)) + 1, static_cast<int>(std::distance(numbers.begin(), tRight)) + 1};
            }

            if (*tLeft + *tRight > target)
            {
                --tRight;
            }

            if (*tLeft + *tRight < target)
            {
                ++tLeft;
            }

        }
    }
};
