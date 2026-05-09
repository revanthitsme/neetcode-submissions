class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for (char t : tasks)
        {
            freq[t - 'A']++;
        }
        
        sort(begin(freq), end(freq));
        int max_freq = freq[25];

        int idle_time = (max_freq-1)*n;

        for (int i = 24; i>=0 && freq[i] > 0; i --)
        {
            idle_time -= min(max_freq-1, freq[i]);
        }

        idle_time = max(0, idle_time);

        return tasks.size()+idle_time;
    }
};
