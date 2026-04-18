class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() -1;

        while (l <= r)
        {
            int mid = (l+r)/2;
            if (matrix[mid][0] > target)
            {
                if (mid > 0)
                {
                    if (matrix[mid-1][0] < target)
                    {
                        int lrow = 0;
                        int rrow = matrix[mid-1].size() -1;
                        
                        while(lrow<=rrow)
                        {
                            int midrow = (lrow+rrow)/2;
                            if (matrix[mid-1][midrow] == target)
                                return true;
                            else if (matrix[mid-1][midrow] > target)
                                rrow = midrow -1;
                            else
                                lrow = midrow+1;
                        }
                        return false;
                    }
                    else if (matrix[mid-1][0] == target)
                    {
                        return true;
                    }
                }
                else if (mid == 0)
                {
                    int lrow = 0;
                    int rrow = matrix[0].size() -1;
                    
                    while(lrow<=rrow)
                    {
                        int midrow = (lrow+rrow)/2;
                        if (matrix[0][midrow] == target)
                            return true;
                        else if (matrix[0][midrow] > target)
                            rrow = midrow -1;
                        else
                            lrow = midrow+1;
                    }
                    return false;                    
                }
                r = mid -1;
            }
            else if (matrix[mid][0] < target)
            {
                if (mid < matrix.size() -1)
                {
                    if (matrix[mid+1][0] > target)
                    {
                        int lrow = 0;
                        int rrow = matrix[mid].size()-1;
                        while(lrow <= rrow)
                        {
                            int midrow = (lrow+rrow)/2;
                            if (matrix[mid][midrow] == target)
                                return true;
                            else if (matrix[mid][midrow] > target)
                                rrow = midrow -1;
                            else
                                lrow = midrow+1;
                        }
                        return false;                        
                    }
                    else if (matrix[mid+1][0] == target)
                        return true;
                }
                else if (mid == matrix.size() -1)
                {
                    int lrow = 0;
                    int rrow = matrix[matrix.size() -1].size()-1;
                    while(lrow<=rrow)
                    {
                        int midrow = (lrow+rrow)/2;
                        if (matrix[matrix.size() -1][midrow] == target)
                            return true;
                        else if (matrix[matrix.size() -1][midrow] > target)
                            rrow = midrow -1;
                        else
                            lrow = midrow+1;
                    }
                    return false;                       
                }
                l = mid+1;
            }
            else
                return true;
        }
        return false;
    }
};
