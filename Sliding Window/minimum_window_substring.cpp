class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> tracker, window;
        for (char c : t)
        {
            tracker[c]++;
        }
        int minWindowSize = INT_MAX;
        int minWindowStart = 0;
        int match = 0;

        int left = 0;
        for (int right = 0; right < s.size(); right++)
        {
            window[s[right]]++;
            if (tracker.count(s[right]) && window[s[right]] == tracker[s[right]])
            {
                match++;
            }
            while (match == tracker.size())
            {
                if (minWindowSize > right - left + 1)
                {
                    minWindowSize = right - left + 1;
                    minWindowStart = left;
                }
                window[s[left]]--;
                if (tracker.count(s[left]) && window[s[left]] < tracker[s[left]])
                {
                    match--;
                }
                left++;
            }
        }
        return minWindowSize == INT_MAX ? "" : s.substr(minWindowStart, minWindowSize);
    }
};