class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int three_sum = nums[i] + nums[left] + nums[right];
                if (three_sum < 0)
                {
                    left++;
                }
                else if (three_sum > 0)
                {
                    right--;
                }
                else
                {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    while (nums[left] == nums[left - 1] && left < right)
                    {
                        left++;
                    }
                }
            }
        }
        return result;
    }
};