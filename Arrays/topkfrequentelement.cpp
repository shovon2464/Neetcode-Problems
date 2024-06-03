class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> tracker;
        for (int i = 0; i < nums.size(); i++)
        {
            if (tracker.find(nums[i]) == tracker.end())
            {
                tracker[nums[i]] = 1;
            }
            else
            {
                tracker[nums[i]] += 1;
            }
        }
        vector<vector<int>> bucket(nums.size() + 1, vector<int>(1, 1001));
        for (auto v : tracker)
        {
            if (bucket[v.second][0] == 0)
            {
                bucket[v.second][0] = v.first;
            }
            else
            {
                bucket[v.second].push_back(v.first);
            }
        }
        vector<int> result;
        int count = k;
        for (int i = bucket.size() - 1; i > 0; i--)
        {
            for (int j = 0; j < bucket[i].size(); j++)
            {
                if (bucket[i][j] != 1001)
                {
                    result.push_back(bucket[i][j]);
                    count--;
                    if (count == 0)
                    {
                        return result;
                    }
                }
            }
        }
        return nums;
    }
};