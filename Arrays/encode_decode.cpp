#include <iostream>
#include <vector>

using namespace std;

// Encodes a list of strings to a single string.
string encode(vector<string>& strs) {
    string s = "";
    for (int i = 0;i < strs.size();i++) {
        s = s + "5" + "#";
        s += strs[i];
    }
    return s;
}

// Decodes a single string to a list of strings.
vector<string> decode(string s) {
    vector<string> strs;
    int i = 0;
    int prev_end = 0;
    while (i < s.size()) {
        cout << i;
        if (s[i] == '#') {
            string num = "";
            for (int j = prev_end;j < i;j++) {
                num += s[j];
            }
            cout << num;
            int len = stoi(num);
            prev_end = i + len;
            i += len + 1;
            if (i == 0) {
                i += 1;
            }
            cout << i;
        }
        else {
            i++;
        }
    }
    return strs;
}

int main() {
    vector<string> strs{ "Hello","World" };
    string s = encode(strs);
    strs = decode(s);
    // for (int i = 0;i < strs.size();i++) {
    //     cout << strs[i];
    // }
    return 0;
}