class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while ( l < r)
        {
            int mid = (l+r)/2;
            if (nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }

        int low = 0;
        int right = nums.size() - 1;
        while (low <= right)
        {
            int mid = (low+right)/2;
            int corr = (mid+l)%nums.size();
            if (nums[corr] < target)
                low = mid + 1;
            else if (nums[corr] > target)
                right = mid - 1;
            else
                return corr;
        }
        return -1;
    }
};
