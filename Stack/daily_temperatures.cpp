class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& nums) {
            vector<int> result(nums.size(),0);
            stack<int> st;
            for(int i=0;i<nums.size();i++) {
                while(!st.empty() && nums[st.top()]<nums[i]) {
                    result[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i); 
            }
            return result;
        }
    };