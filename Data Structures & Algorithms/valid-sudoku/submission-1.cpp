class Solution {
public:
    bool isvalidvector(vector<int>& nums)
    {
        unordered_set<int> numscnt;
        for (int i=0; i<nums.size(); i++)
        {
            if (numscnt.find(nums[i]) != numscnt.end())
                return false;
            else
                numscnt.insert(nums[i]);               
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (int i=0; i<9; i++)
        {
            vector<int> temp;
            for (int j=0; j<9; j++)
            {
                if (board[i][j] != '.')
                {
                    temp.push_back(board[i][j] - '0');
                    // cout<< board[i][j] - '0' << ' ';
                }
            }
            // cout<< '\n';
            if (!isvalidvector(temp))
                return false;
        }

        for (int j=0; j<9;j++)
        {
            vector<int> temp;
            for (int i=0; i<9;i++)
            {
                if (board[i][j] != '.')
                {
                    temp.push_back(board[i][j] - '0');
                    // cout<< board[i][j] - '0' << ' ';
                }
            }
            // cout<< '\n';
            if (!isvalidvector(temp))
                return false;
        }
        int xpos = 0;
        for (int b=0; b<3; b++)
        {
            int ypos = 0;
            for (int a=0; a<3; a++)
            {
                vector<int> temp;
                for (int i=xpos; i<xpos+3; i++)
                {
                    for (int j=ypos;j<ypos+3;j++)
                    {
                        if (board[i][j] != '.')
                        {
                            temp.push_back(board[i][j] - '0');
                            cout<< board[i][j] - '0' << ' ';
                        }
                    }
                }
                cout<<'\n';
                if (!isvalidvector(temp))
                    return false;
                ypos = ypos+3;
            }
            xpos=xpos+3;
        }
        return true;
    }
};
