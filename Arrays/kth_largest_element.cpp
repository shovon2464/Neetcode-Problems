#include<iostream>
#include<vector>

using namespace std;

int findPivot(vector<int>& nums, int low, int high) {
    int random_index = low + rand() % (high - low + 1);
    int pivot = nums[random_index];
    swap(nums[low], nums[random_index]);
    while (low < high) {
        while (low < high && nums[high] >= pivot) {
            high--;
        }
        nums[low] = nums[high];
        while (low < high && nums[low] <= pivot) {
            low++;
        }
        nums[high] = nums[low];

    }
    nums[low] = pivot;
    return low;

}

int main() {
    vector<int> nums{ 3,2,1,5,6,4 };
    int k = 2;
    int start = 0;
    int end = nums.size() - 1;
    int target = nums.size() - k;
    while (start < end) {
        int pivot = findPivot(nums, start, end);
        if (pivot == target) {
            return nums[pivot];
        }
        if (pivot > target) {
            end = pivot - 1;
        }
        else if (pivot < target) {
            start = pivot + 1;
        }
    }
    for (int i = 0;i < nums.size();i++) {
        cout << nums[i] << " ";
    }

    return nums[target];
    return 0;
}