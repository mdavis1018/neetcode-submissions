class PrefixTree 
{
    struct TrieNode
    {
        TrieNode() = default;
        std::unordered_map<char, TrieNode*> mChildren;
        bool mIsWordEnd;
    };

public:
    PrefixTree() 
    {
        mRoot = new TrieNode();
    }
    
    void insert(string word) 
    {
        TrieNode *tCurr = mRoot;

        for (auto tChar : word)
        {
            if (tCurr->mChildren.count(tChar) == false)
            {
                tCurr->mChildren[tChar] = new TrieNode();
            }

            tCurr = tCurr->mChildren[tChar];
        }

        tCurr->mIsWordEnd = true;
    }
    
    bool search(string word) 
    {
        auto tCurr = mRoot;

        for (auto tChar : word)
        {
            if (tCurr->mChildren.count(tChar) == false)
            {
                return false;
            }
            
            tCurr = tCurr->mChildren[tChar];
        }
        
        return tCurr->mIsWordEnd;
    }
    
    bool startsWith(string prefix) 
    {
        auto tCurr = mRoot;

        for (auto tChar : prefix)
        {
            if (tCurr->mChildren.count(tChar) == false)
            {
                return false;
            }

            tCurr = tCurr->mChildren[tChar];
        }

        return true;
    }

    TrieNode *mRoot;
};
