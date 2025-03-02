class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int max = 0;
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] < 0) {
                nums[i] = 0;
            }
            if (nums[i] > max) {
                max = nums[i];
            }
        }



        for (int i = 0;i < nums.size();i++) {
            int index = abs(nums[i]) - 1;
            if (index >= 0 && index < nums.size()) {
                nums[index] = abs(nums[index]) == 0 ? (nums.size() + 1) * -1 : abs(nums[index]) * -1;
            }
        }


        for (int i = 1;i <= nums.size();i++) {
            int index = i - 1;
            if (index >= 0 && index < nums.size()) {
                if (nums[index] >= 0) {
                    return index + 1;
                }
            }
        }
        return max + 1;
    }
};