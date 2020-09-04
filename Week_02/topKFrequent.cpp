//前k个高频数
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> map;
        priority_queue<pair<int, int> > pq;
        
        for(auto i: nums)
            map[i]++;

        for(auto p: map) {
            pq.push(pair<int, int>(-p.second, p.first));
            if(pq.size() > k)
                pq.pop();
        }

        while(k--) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};