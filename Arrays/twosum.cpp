class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> tracker;
        for (int i = 0; i < nums.size(); i++)
        {
            int j = target - nums[i];
            if (tracker.find(j) != tracker.end())
            {
                return vector<int>{tracker[j], i};
            }
            else
            {
                tracker[nums[i]] = i;
            }
        }
        return vector<int>{1, 2};
    }
};