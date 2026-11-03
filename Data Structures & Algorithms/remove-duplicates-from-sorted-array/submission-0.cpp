class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        vector<int>::iterator tLeft = nums.begin();;
        vector<int>::iterator tRight = nums.begin() + 1;
        int tCounter = 1;

       for (auto tRight = nums.begin() + 1; tRight != nums.end(); ++tRight)
       {
            // Since the array is already sorted all we have to do is check to see if the right element is unique, if so then we can just override left
            if (*tRight != *tLeft)
            {
                ++tLeft;
                *tLeft = *tRight;
                ++tCounter;
            }
       }

        return tCounter;
    }
};