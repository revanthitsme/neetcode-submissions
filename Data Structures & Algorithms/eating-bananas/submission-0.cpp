class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin(), piles.end());
        int l = 1;
        while (l<=r)
        
        {
            int mid = l + (r - l) / 2;
            long long hrs =0;
            for (int i=0; i<piles.size();i++)
            {
                hrs += (long long)(piles[i]+mid-1)/mid;
            }

            if (hrs <= h)
            {
                r = mid - 1;
            }
            else
            {
                l = mid+1;
            }
        }
        return l;
    }
};