class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int> tReturn;
        int tLeft = 0;
        int tRight = numbers.size() - 1;

        while (tLeft < tRight)
        {
            if (numbers[tLeft] + numbers[tRight] == target)
            {
                return {tLeft + 1, tRight + 1};
            }
            if (numbers[tRight] + numbers[tLeft] > target)
            {
                --tRight;
            }
            else if (numbers[tRight] + numbers[tLeft] < target)
            {
                ++tLeft;
            }
        }

        return {};
    }
};
