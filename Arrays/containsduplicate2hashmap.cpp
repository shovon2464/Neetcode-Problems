class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> tracker;
        for (int i = 0; i < nums.size(); i++)
        {
            if (tracker.find(nums[i]) == tracker.end())
            {
                tracker[nums[i]] = i;
            }
            else
            {
                if (abs(i - tracker[nums[i]]) <= k)
                {
                    return true;
                }
                else
                {
                    tracker[nums[i]] = i;
                }
            }
        }
        return false;
    }
};