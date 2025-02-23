class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int majority1 = INT_MIN;
        int count1 = 0;
        int majority2 = INT_MIN;
        int count2 = 0;
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] == majority1) {
                count1++;
            }
            else if (nums[i] == majority2) {
                count2++;
            }
            else if (count1 == 0) {
                majority1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0) {
                majority2 = nums[i];
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        int count11 = 0;
        int count22 = 0;
        vector<int> result;
        int comparer = int(nums.size() / 3);

        for (int i = 0;i < nums.size();i++) {
            if (nums[i] == majority1) {
                count11++;
            }
            else if (nums[i] == majority2) {
                count22++;
            }
        }
        if (count11 > comparer) {
            result.push_back(majority1);
        }
        if (count22 > comparer) {
            result.push_back(majority2);
        }

        return result;
    }
};