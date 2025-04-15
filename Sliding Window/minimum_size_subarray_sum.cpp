class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int minLength = INT_MAX;
        int sum = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            while (sum >= target)
            {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};