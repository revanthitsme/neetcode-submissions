class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int n = nums.size();
        int r = nums.size() - 1;



        while (l < r)
        {

            int mid = (l+r)/2;
            cout << l << ' ' << r << ' ' << mid << '\n';
            if (nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;

        }
        cout << l << ' ' << r << '\n';
        return nums[l];
    }
};

