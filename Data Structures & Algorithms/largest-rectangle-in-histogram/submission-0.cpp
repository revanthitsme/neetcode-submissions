class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int,int>> hi;
        int maxarea = 0;
        for (int i=0; i<heights.size(); i++)
        {
            int lc = 0;
            int rc = 0;
            int l = i - 1 ;
            int r = i + 1;            

            while (l >=0)
            {
                if (heights[l] >= heights[i])
                {
                    l--;
                    lc++;
                }
                else
                    break;
            }

            while (r < heights.size())
            {
                if (heights[r] >= heights[i])
                {
                    r++;
                    rc++;
                }
                else
                    break;
            }
            maxarea=max(maxarea, heights[i]*(lc+rc+1));

        }

        return maxarea;
    }
};
