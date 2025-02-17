class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> tracker;
        int max = 1;
        for (int i = 0;i < nums.size();i++) {
            if (tracker.contains(nums[i])) {
                tracker[nums[i]]++;
                if (tracker[nums[i]] > max) {
                    max = tracker[nums[i]];
                }
            }
            else {
                tracker[nums[i]] = 1;
            }
        }

        vector<vector<int>> bucket(max + 1, vector<int> {});

        for (auto& x : tracker) {
            bucket[x.second].push_back(x.first);
        }

        vector<int> result;
        int num = k;
        for (int i = max;i >= 0;i--) {
            for (auto& x : bucket[i]) {
                result.push_back(x);
                num--;
                if (num == 0) {
                    break;
                }
            }
            if (num == 0) {
                break;
            }
        }

        return result;


    }
};