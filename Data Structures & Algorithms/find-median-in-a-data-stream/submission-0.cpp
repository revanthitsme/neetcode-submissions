class MedianFinder {
    priority_queue<int, vector<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (left.size() == 0)
        {
            left.push(num);
            return;
        }

        if (left.size() == right.size())
        {
            if (!left.empty())
            {
                if (num < right.top())
                    left.push(num);
                else
                {
                    left.push(right.top());
                    right.pop();
                    right.push(num);
                }
            }
        }
        else
        {
            if (left.top() < num)
            {
                right.push(num);
            }
            else
            {
                right.push(left.top());
                left.pop();
                left.push(num);
            }
        }
    }
    
    double findMedian() {
        if (left.size() == right.size())
        {
            return ((double)(left.top()+right.top()))/2;
        }
        else
        {
            return (double)left.top();
        }       

    }
};
