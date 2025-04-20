class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<int, int> tracker;
        int longest = INT_MIN;
        int maxFrequency = INT_MIN;
        int left = 0;
        for (int right = 0; right < s.size(); right++)
        {
            tracker[s[right]]++;
            maxFrequency = max(maxFrequency, tracker[s[right]]);
            while (right - left + 1 - maxFrequency > k)
            {
                tracker[s[left]]--;
                left++;
            }
            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};