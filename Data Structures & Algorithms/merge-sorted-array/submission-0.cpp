class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        nums1.erase(nums1.begin() + m, nums1.end());
        std::vector<int>::iterator t1Iter = nums1.begin();
        std::vector<int>::iterator t2Iter = nums2.begin();

        while (t1Iter != nums1.end() && t2Iter != nums2.end())
        {
            if (*t1Iter <= *t2Iter)
            {
                ++t1Iter;
            }
            else 
            {
                t1Iter = nums1.insert(t1Iter, *t2Iter);
                ++t2Iter;
            }
        }

        if (t2Iter != nums2.end())
        {
            nums1.insert(t1Iter, t2Iter, nums2.end());
        }
        
    }
};