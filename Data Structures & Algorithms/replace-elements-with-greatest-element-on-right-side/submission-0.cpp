class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) 
    {
        for (std::vector<int>::iterator tIter = arr.begin(); tIter != arr.end() -1; ++tIter)
        {
            std::vector<int> tCopy(std::next(tIter), arr.end());
            std::sort(tCopy.begin(), tCopy.end());
            *tIter = tCopy.back();
        }

        arr.at(arr.size() - 1) = -1;
        return arr;
    }
};