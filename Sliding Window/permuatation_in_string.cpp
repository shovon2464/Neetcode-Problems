class Solution
{
public:
    vector<int> fillUp(string s)
    {
        vector<int> v(26, 0);
        for (char c : s)
        {
            int index = int(c - 'a');
            v[index]++;
        }
        return v;
    }
    int findMatchCount(vector<int> &v1, vector<int> &v2)
    {
        int total = 0;
        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] == v2[i])
                total++;
        }
        return total;
    }
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
            return false;

        vector<int> tracker = fillUp(s1);
        vector<int> window = fillUp(s2.substr(0, s1.size()));

        int matchCount = findMatchCount(tracker, window);

        int left = 0;
        for (int right = s1.size(); right < s2.size(); right++)
        {
            if (matchCount == 26)
                return true;

            int index = int(s2[right] - 'a');
            window[index]++;

            if (window[index] == tracker[index])
            {
                matchCount++;
            }
            else if (window[index] - 1 == tracker[index])
            {
                matchCount--;
            }

            index = int(s2[left] - 'a');
            window[index]--;

            if (window[index] == tracker[index])
            {
                matchCount++;
            }
            else if (window[index] + 1 == tracker[index])
            {
                matchCount--;
            }
            left++;
        }

        return matchCount == 26;
    }
};