class Solution {
public:
    int calPoints(vector<string>& operations) 
    {
        std::stack<int> tStack;
        
        for (std::string tString : operations)
        {
            if (tString == "+")
            {
                int tTop = tStack.top();
                tStack.pop();
                int tNewTop = tTop + tStack.top();
                tStack.push(tTop);
                tStack.push(tNewTop);
            }
            else if (tString == "D")
            {
                tStack.push(tStack.top() * 2);
            }
            else if (tString == "C")
            {
                tStack.pop();
            }
            else 
            {
                tStack.push(std::stoi(tString));
            }
        }

        int tSum = 0;
        while (tStack.empty() == false)
        {
            tSum += tStack.top();
            tStack.pop();
        }

        return tSum;
    }
};