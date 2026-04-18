class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> results(n,0);
        stack<int> ind;
        for (int i=0;i<n;i++)
        {
            if (ind.empty())
                ind.push(i);
            else
            {

                if (temperatures[i] < temperatures[ind.top()])
                    ind.push(i);
                else
                {
                    while (!ind.empty() && temperatures[i] > temperatures[ind.top()])
                    {
                        results[ind.top()] = i - ind.top();
                        ind.pop();
                    }
                    ind.push(i);
                }
            }
        }
        return results;
    }
};
