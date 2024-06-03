class Codec
{
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs)
    {
        string result = "";
        for (int i = 0; i < strs.size(); i++)
        {
            result += to_string(strs[i].size()) + "#" + strs[i];
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s)
    {
        vector<string> result;
        string num = "";
        int i = 0;
        while (i < s.size())
        {
            if (s[i] != '#')
            {
                num += s[i];
                i++;
            }
            else
            {
                int len = stoi(num);
                num.clear();
                string temp = "";
                int j = i + 1;
                while (len > 0)
                {
                    temp += s[j];
                    len--;
                    j++;
                }
                result.push_back(temp);
                i = j;
            }
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));