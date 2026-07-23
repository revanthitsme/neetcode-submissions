class Solution {
public:
    int numbits(int n)
    {
        int counter = 0;
        while (n > 0)
        {
            n = n & (n-1);
            counter++;
        }
        return counter;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for (int i = 0; i <= n; i++)
        {
            ans[i] = numbits(i);
        }
        return ans;
    }
};
