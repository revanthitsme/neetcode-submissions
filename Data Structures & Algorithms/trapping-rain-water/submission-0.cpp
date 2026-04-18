class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lefts;
        vector<int> rights(height.size(), 0);

        int left = 0;
        for (int i=0; i< height.size(); i++)
        {
            lefts.push_back(left);
            left = max(left, height[i]);
        }

        int right = 0;
        for (int j=height.size() -1 ; j >= 0; j--)
        {
            rights[j] = right;
            right = max(right, height[j]);
        }

        int ans = 0;
        for (int i=0; i<height.size(); i++)
        {

            int temp = max(0, min(lefts[i], rights[i]) - height[i]);
            cout << lefts[i] << ' ' << rights[i] << ' ' << temp <<'\n';
            ans += temp;
        }
        return ans;
    }
};
