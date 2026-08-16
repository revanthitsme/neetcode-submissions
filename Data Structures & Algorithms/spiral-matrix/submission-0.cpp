class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int bottom = matrix.size()-1;
        int left = 0;
        int right = matrix[0].size()-1;
        vector<int> res;

        int i = 0;
        int j = 0;

        while (top <= bottom && left <= right)
        {
            bool check = top <= bottom && left <= right;
            if (check && i == top && j == left)
            {
                while (j <= right)
                {
                    res.push_back(matrix[i][j]);
                    j++;
                }
                j = right;
                top++;
                i++;
            }
            check = top <= bottom && left <= right;

            if (j == right && i == top && check)
            {
                while (i <= bottom)
                {
                    res.push_back(matrix[i][j]);
                    i++;
                }
                i = bottom;
                right--;
                j--;
            }
            check = top <= bottom && left <= right;

            if (i == bottom && j == right && check)
            {
                while (j >= left)
                {
                    res.push_back(matrix[i][j]);
                    j--;
                }
                j = left;
                bottom--;
                i--;
            }
            check = top <= bottom && left <= right;

            if (i == bottom && j == left && check)
            {
                while (i >= top)
                {
                    res.push_back(matrix[i][j]);
                    i--;
                }
                i = top;
                left++;
                j++;
            }
        }
        return res;


    }
};
