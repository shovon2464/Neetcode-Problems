class Solution {
public:
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
    void quickSort(vector<int>& nums, int low, int high) {
        if (low >= high) {
            return;
        }
        int pivotIndex = findPivot(nums, low, high);
        quickSort(nums, low, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};