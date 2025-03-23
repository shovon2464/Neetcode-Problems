class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> tracker;
        int left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            if (right - left > k)
            {
                tracker.erase(nums[left]);
                left++;
            }
            if (tracker.contains(nums[right]))
            {
                return true;
            }
            else
            {
                tracker[nums[right]] = 1;
            }
        }
        return false;
    }
};
