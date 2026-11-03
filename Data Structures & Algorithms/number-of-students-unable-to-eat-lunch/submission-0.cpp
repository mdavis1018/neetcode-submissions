class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        int tLooper = 0;
        while (students.size() != 0 
              && sandwiches.size() != 0 
              && tLooper != students.size())
        {
            if (students[0] == sandwiches[0])
            {
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                tLooper = 0;
            }
            else
            {
                ++tLooper;
                int tValue = *students.begin();
                students.erase(students.begin());
                students.push_back(tValue);
            }
        }

        return students.size();
    }
};