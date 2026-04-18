class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;

        int maxvalue = INT_MIN;
        while (i < j)
        {
            int temp = min(heights[i], heights[j])*(j-i);
            if (temp > maxvalue)
                maxvalue = temp;
            else
                if (heights[i] <= heights[j])
                    i++;
                else
                    j--;
        }
        return maxvalue;
    }
    
};
