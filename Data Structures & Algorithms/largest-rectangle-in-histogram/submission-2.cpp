class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> ind;
        int n= heights.size();
        int maxarea = 0;
        for (int i=0; i<n; i++)
        {
            while (!ind.empty() && heights[ind.top()] > heights[i])
            {
                int temp = ind.top();
                ind.pop();
                maxarea = max(maxarea, heights[temp]*(i-(ind.empty() ? 0 : ind.top()+1)));
            }
            ind.push(i);
        }

        // Flush remaining bars using right boundary n
        while (!ind.empty()) {
            int top = ind.top(); ind.pop();
            int width = ind.empty() ? n : (n - ind.top() - 1);
            maxarea = max(maxarea, heights[top] * width);
        }

        return maxarea;
    }
};
