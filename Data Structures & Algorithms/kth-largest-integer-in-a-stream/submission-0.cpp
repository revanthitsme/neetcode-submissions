class KthLargest {
    priority_queue<int,vector<int>, greater<int>> pq;
    int maxlength = 0;
public:
    KthLargest(int k, vector<int>& nums) {
        maxlength = k;
        for (int i = 0; i < nums.size(); i++)
        {
            if (pq.size() >= maxlength && pq.top() < nums[i])
                pq.pop();
            if (pq.size() < maxlength)
                pq.push(nums[i]);
        }
    }
    
    int add(int val) {
        if (pq.size() >= maxlength && pq.top() < val)
            pq.pop();
        if (pq.size() < maxlength)
            pq.push(val);
        return pq.top();        
    }
};
