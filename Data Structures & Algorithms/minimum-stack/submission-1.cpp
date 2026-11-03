class MinStack {
public:
    MinStack() :
        mStart(nullptr),
        mCapacity(0),
        mNumOfElements(0)
    {
        
    }

    ~MinStack()
    {
        delete[] mStart;
    }
    
    void push(int val) 
    {
        if (mNumOfElements == mCapacity)
        {
            grow();
        }
        std::construct_at(end(), val);
        ++mNumOfElements;
        mElements.insert(val);
    }
    
    void pop()
    {
        if (mNumOfElements > 0)
        {
            int value = mStart[mNumOfElements - 1];
            auto it = mElements.find(value);
            mElements.erase(it);  
            --mNumOfElements;
        }
    }
    
    int top() 
    {
        return *(mStart + mNumOfElements - 1);
    }
    
    int getMin() 
    {
        auto tIter = mElements.begin();

        if (tIter != mElements.end())
        {
            return *tIter;
        }

        return -99999;
    }

private:

    int *mStart;
    std::size_t mCapacity;
    std::size_t mNumOfElements;
    std::multiset<int> mElements;
    int* end() const
    {
        return mStart + mNumOfElements;
    }

    void grow() 
    {
        if (mNumOfElements == 0)
        {
            mCapacity = 8;
        }
        else 
        {
            mCapacity = mCapacity * 2;
        }

        int *tNewStart = new int[mCapacity]; 
        
        for (std::size_t i = 0; i < mNumOfElements; ++i)
        {
            tNewStart[i] = *(mStart + i);
        }

        delete[] mStart;
        mStart = tNewStart;
    }
};
