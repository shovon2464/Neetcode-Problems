class Solution {
public:
    struct compare {
        bool operator() (pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> tracker;
        for (int i = 0;i < nums.size();i++) {
            if (tracker.contains(nums[i])) {
                tracker[nums[i]]++;
            }
            else {
                tracker[nums[i]] = 1;
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

        for (auto& x : tracker) {
            pq.push(pair<int, int> {x.first, x.second});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};