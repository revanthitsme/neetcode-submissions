class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        while (low <= high)
        {
            int pX = (low+high)/2;
            int pY = (m+n+1)/2 - pX;

            int maxleftX = (pX == 0) ? INT_MIN : nums1[pX-1];
            int minrightX = (pX == m) ? INT_MAX : nums1[pX];
            int maxleftY = (pY == 0) ? INT_MIN : nums2[pY-1];
            int minrightY = (pY == n) ? INT_MAX : nums2[pY];

            if (maxleftX <=minrightY && maxleftY <= minrightX)
            {
                if ((m+n)%2 == 0)
                {
                    return (max(maxleftX,maxleftY) + min(minrightX,minrightY))/2.0;
                }
                else
                    return max(maxleftX, maxleftY);
            }
            else if (maxleftX > minrightY)
                high = pX - 1;
            else if (maxleftY > minrightX)
                low = pX + 1;
         }
    }
};
