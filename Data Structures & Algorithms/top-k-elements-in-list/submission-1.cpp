class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Use HashMap to count frequency of number.
        unordered_map<int, int> freq;
        for (int num: nums) {
            freq[num]++;
        }
        priority_queue<int> pq;
        for (auto& it: freq) {
            pq.push(it.second);
        }
        vector<int> topK;
        while (k > 0) { 
            int top = pq.top();
            for (auto& it: freq) {
                if (it.second == top) {
                    topK.push_back(it.first);
                    pq.pop();
                    --k;
                } 
            } 
        }
        // int frequency = pq.top();
        // for (auto& it: freq) {
        //     if (it.second == frequency) topK.push_back(it.first);
        // // }
        return topK;
    }
};
