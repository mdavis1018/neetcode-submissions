class Solution {
public:
    bool isValid(string s) 
    {
        std::stack<char> tStack;

        std::unordered_map<char, char> tMap = 
        {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char tChar : s)
        {
            if (tMap.count(tChar) && tStack.empty() == false && tMap.at(tChar) == tStack.top())
            {
                tStack.pop();
            }
            else if (tMap.count(tChar) == false)
            {
                tStack.push(tChar);
            }
            else 
            {
                return false;
            }
        }

        return tStack.empty();
    }
};
