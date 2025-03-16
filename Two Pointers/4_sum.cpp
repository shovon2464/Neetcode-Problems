class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int len = nums.size();
        for (int i = 0; i < len - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < len - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                int left = j + 1;
                int right = len - 1;
                while (left < right)
                {
                    long long four_sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (four_sum > target)
                    {
                        right--;
                    }
                    else if (four_sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        while (nums[left] == nums[left - 1] && left < right)
                        {
                            left++;
                        }
                    }
                }
            }
        }
        return result;
    }
};