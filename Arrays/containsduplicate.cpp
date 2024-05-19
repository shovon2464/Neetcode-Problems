class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
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
                return true;
            }
        }
        return false;
    }
};